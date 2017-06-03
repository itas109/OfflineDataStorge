#include "OfflineDataStorge.h"

itas109::OfflineDataStorge::OfflineDataStorge()
{
	logUtil.Init();
}

itas109::OfflineDataStorge::~OfflineDataStorge()
{
	
}

//offline data convert to json
std::string itas109::OfflineDataStorge::offlineData2Json(std::map<std::string, std::vector<std::string>> offlineDatas)
{
	std::vector<std::string> jsonData;
	rapidjson::Document doc;
	doc.SetObject();
	rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

	rapidjson::Value businessesArray(rapidjson::kArrayType);
	for (std::map<std::string, std::vector<std::string>>::const_iterator itr = offlineDatas.begin();itr != offlineDatas.end(); itr++)
	{
		rapidjson::Value businessesObject(rapidjson::kObjectType);
		businessesObject.SetObject();

		rapidjson::Value parmsArray(rapidjson::kArrayType);
		for (size_t j = 0; j < itr->second.size(); j++)
		{
			rapidjson::Value parmObject(rapidjson::kObjectType);
			parmObject.SetObject();
			parmObject.AddMember("parm", rapidjson::StringRef(itr->second.at(j).c_str()), allocator);
			parmsArray.PushBack(parmObject, allocator);
		}

		businessesObject.AddMember("logicFunction", rapidjson::StringRef(itr->first.c_str()), allocator);
		businessesObject.AddMember("parms", parmsArray, allocator);

		businessesArray.PushBack(businessesObject, allocator);
	}
	doc.AddMember("businesses", businessesArray, allocator);

	rapidjson::StringBuffer buffer;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);
	
	return buffer.GetString();
}

//offline single logicFunction data convert to json
std::string itas109::OfflineDataStorge::offlineData2Json(std::string logicFunction, std::vector<std::string> parms)
{
	std::map<std::string, std::vector<std::string>> offlineDatas;

	//single logicFunction data
	offlineDatas.insert(std::map<std::string, std::vector<std::string>>::value_type(logicFunction, parms));

	return offlineData2Json(offlineDatas);
}

// save offline date to SQLite
void itas109::OfflineDataStorge::saveOfflineData(std::map<std::string, std::vector<std::string>> offlineDatas)
{
	std::string jsondata = offlineData2Json(offlineDatas);

	try
	{
		db.open("offlineData.db3");

		if (!db.tableExists("offlineDataStorge"))
		{
			std::string sql = "CREATE TABLE offlineDataStorge (id INTEGER PRIMARY KEY AUTOINCREMENT,'data'  varchar(256),'UpdateTime' TimeStamp NOT NULL DEFAULT (datetime('now','localtime')));";
			db.execDML(sql.c_str());
		}

		char strDst[2048] = { 0 };
		sprintf_s(strDst,2048, "INSERT INTO offlineDataStorge (data,UpdateTime) VALUES('%s',datetime('now', 'localtime'));", jsondata.c_str());
		db.execDML(strDst);

		db.close();
	}
	catch (CppSQLite3Exception ex)
	{
		char logData[512] = {0};
		sprintf_s(logData, 512, "[OfflineDataStorge] -- Insert error! message:%s",ex.errorMessage());
		logUtil.LogOut(logData);
	}
}

// save single logicFunction offline date to SQLite
void itas109::OfflineDataStorge::saveOfflineData(std::string logicFunction, std::vector<std::string> parms)
{
	std::string jsondata = offlineData2Json(logicFunction, parms);

	try
	{
		db.open("offlineData.db3");

		if (!db.tableExists("offlineDataStorge"))
		{
			std::string sql = "CREATE TABLE offlineDataStorge (id INTEGER PRIMARY KEY AUTOINCREMENT,'data'  varchar(256),'UpdateTime' TimeStamp NOT NULL DEFAULT (datetime('now','localtime')));";
			db.execDML(sql.c_str());
		}

		char strDst[2048] = { 0 };
		sprintf_s(strDst, 2048, "INSERT INTO offlineDataStorge (data,UpdateTime) VALUES('%s',datetime('now', 'localtime'));", jsondata.c_str());
		db.execDML(strDst);

		db.close();
	}
	catch (CppSQLite3Exception ex)
	{
		char logData[512] = { 0 };
		sprintf_s(logData, 512, "[OfflineDataStorge] -- Insert error! message:%s", ex.errorMessage());
		logUtil.LogOut(logData);
	}
}

//get all offline data
std::map<int, std::string> itas109::OfflineDataStorge::getAllOfflineData()
{
	std::map<int, std::string> datamap;
	try
	{
		db.open("offlineData.db3");
		if (!db.tableExists("offlineDataStorge"))
		{
			db.execDML("CREATE TABLE offlineDataStorge (id INTEGER PRIMARY KEY AUTOINCREMENT,'data'  varchar(256),'UpdateTime'  TimeStamp NOT NULL DEFAULT (datetime('now','localtime')));");
		}

		CppSQLite3Query query = db.execQuery("select id,data from offlineDataStorge");
		
		while (!query.eof())
		{
			std::string tempUploadStr = "";
			tempUploadStr = std::string(query.getStringField("data"));

			datamap[query.getIntField("id")] = tempUploadStr;
			//next data
			query.nextRow();
		}
		query.finalize();

		//close database
		db.close();
	}
	catch (CppSQLite3Exception ex)
	{
		char logData[512] = { 0 };
		sprintf_s(logData, 512, "[OfflineDataStorge] -- Select error! message:%s", ex.errorMessage());
		logUtil.LogOut(logData);
	}
	return datamap;
}

//delete offline data by id
void itas109::OfflineDataStorge::deleteOfflineData(int id)
{
	try
	{
		db.open("offlineData.db3");

		//CREATE TABLE offlineDataStorge (id INTEGER PRIMARY KEY AUTOINCREMENT,'data'  varchar(256),'UpdateTime' TimeStamp NOT NULL DEFAULT (datetime('now','localtime')))
		if (!db.tableExists("offlineDataStorge"))
		{
			db.execDML("CREATE TABLE offlineDataStorge (id INTEGER PRIMARY KEY AUTOINCREMENT,'data'  varchar(256),'UpdateTime'  TimeStamp NOT NULL DEFAULT (datetime('now','localtime')));");
		}
		else
		{
			char strDst[256] = { 0 };
			//DELETE FROM offlineDataStorge WHERE id=1;
			sprintf_s(strDst, 256, "DELETE FROM offlineDataStorge where id = %d;", id);
			db.execDML(strDst);
		}
		db.close();
	}
	catch (CppSQLite3Exception ex)
	{
		char logData[512] = { 0 };
		sprintf_s(logData, 512, "[OfflineDataStorge] -- Delete error! message:%s", ex.errorMessage());
		logUtil.LogOut(logData);
	}
}

//parse offline json data
std::vector<std::string> itas109::OfflineDataStorge::parseOfflineData(std::string jsondata)
{
	rapidjson::Document document;
	std::vector<std::string> dataList;

	document.Parse(jsondata.c_str());
	rapidjson::Value & businessesArray = document["businesses"];

	int count = businessesArray.Size();

	//if businesses's size not equal 1
	if (count != 1)
	{
		return dataList;
	}

	if (businessesArray.IsArray())
	{
		for (int i = 0; i < count; i++)
		{
			rapidjson::Value & business = businessesArray[i];
			//parse logic function
			if (business.HasMember("logicFunction") && business["logicFunction"].IsString())
			{
				dataList.push_back(business["logicFunction"].GetString());
			}

			if (business.HasMember("parms") && business.IsObject())
			{
				rapidjson::Value & parms = business["parms"];
				if (parms.IsArray())
				{
					for (size_t j = 0; j < parms.Size(); j++)
					{
						rapidjson::Value & parm = parms[j];
						//parse parms
						if (parm.HasMember("parm") && parm["parm"].IsString())
						{
							dataList.push_back(parm["parm"].GetString());
						}
					}
				}
			}
		}
	}

	return dataList;
}

//parse offline json map data
std::vector<std::vector<std::string>> itas109::OfflineDataStorge::parseOfflineMapData(std::string jsondata)
{
	rapidjson::Document document;
	std::vector<std::vector<std::string>> dataLists;
	std::vector<std::string> dataList;

	document.Parse(jsondata.c_str());
	rapidjson::Value & businessesArray = document["businesses"];

	int count = businessesArray.Size();

	if (businessesArray.IsArray())
	{
		for (int i = 0; i < count; i++)
		{
			rapidjson::Value & business = businessesArray[i];
			//parse logic function
			if (business.HasMember("logicFunction") && business["logicFunction"].IsString())
			{
				dataList.push_back(business["logicFunction"].GetString());
			}

			if (business.HasMember("parms") && business.IsObject())
			{
				rapidjson::Value & parms = business["parms"];
				if (parms.IsArray())
				{
					for (size_t j = 0; j < parms.Size(); j++)
					{
						rapidjson::Value & parm = parms[j];
						//parse parms
						if (parm.HasMember("parm") && parm["parm"].IsString())
						{
							dataList.push_back(parm["parm"].GetString());
						}
					}
				}
			}

			dataLists.push_back(dataList);
			dataList.clear();
		}
	}

	return dataLists;
}

std::string itas109::OfflineDataStorge::getVersion()
{
	return version;
}