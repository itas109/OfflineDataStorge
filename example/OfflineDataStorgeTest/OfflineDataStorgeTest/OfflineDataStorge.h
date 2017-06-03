/*
 * OfflineDataStorge
 * Developed by itas109 <itas109@vip.qq.com>
 * http://blog.csdn.net/itas109
 * https://github.com/itas109
 * See LICENSE file for copyright and license info
 */

#ifndef _OFFLINEDATASTORGE_H
#define _OFFLINEDATASTORGE_H

#include <string>
#include <vector>
#include <map> 

//sqlite
#include "CppSQLite3.h"

//rapidjson
#include "document.h"
#include "writer.h"
#include "prettywriter.h"
#include "stringbuffer.h"

//log
#include "CLog4CPP.h"

namespace itas109
{
	class OfflineDataStorge
	{
	public:
		OfflineDataStorge();
		~OfflineDataStorge();

		std::string getVersion();

		//save offline data to SQLite
		//offlineDatas->first -- std::string logicFunction
		//offlineDatas->second -- std::vector<std::string> parms
		void saveOfflineData(std::map<std::string, std::vector<std::string>> offlineDatas);
		//save single logicFunction offline data to SQLite
		//std::string logicFunction
		//std::vector<std::string> parms
		void saveOfflineData(std::string logicFunction, std::vector<std::string> parms);

		//get all offline data
		std::map<int, std::string> getAllOfflineData();

		//delete offline data by id
		void deleteOfflineData(int id);

		//parse offline json data
		std::vector<std::string> parseOfflineData(std::string jsondata);
		//parse offline json map data
		std::vector<std::vector<std::string>> parseOfflineMapData(std::string jsondata);

	private:
		CppSQLite3DB db;

		CLog4CPP logUtil;

		//class version
		const std::string version = "1.0.0.170603";

		//offline data convert to json
		//offlineDatas->first -- std::string logicFunction
		//offlineDatas->second -- std::vector<std::string> parms
		std::string offlineData2Json(std::map<std::string, std::vector<std::string>> offlineDatas);
		//offline single logicFunction data convert to json
		//td::string logicFunction
		//std::vector<std::string> parms
		std::string offlineData2Json(std::string logicFunction, std::vector<std::string> parms);

	};
}

#endif _OFFLINEDATASTORGE_H