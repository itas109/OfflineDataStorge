
// OfflineDataStorgeTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OfflineDataStorgeTest.h"
#include "OfflineDataStorgeTestDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COfflineDataStorgeTestDlg �Ի���



COfflineDataStorgeTestDlg::COfflineDataStorgeTestDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(COfflineDataStorgeTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COfflineDataStorgeTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COfflineDataStorgeTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &COfflineDataStorgeTestDlg::OnBnClickedButtonTest)
	ON_BN_CLICKED(IDC_BUTTON_TEST2, &COfflineDataStorgeTestDlg::OnBnClickedButtonTest2)
	ON_BN_CLICKED(IDC_BUTTON_TEST3, &COfflineDataStorgeTestDlg::OnBnClickedButtonTest3)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// COfflineDataStorgeTestDlg ��Ϣ�������

BOOL COfflineDataStorgeTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	log.Init();

	//start offline data timer
	SetTimer(WM_OFFLINE_DATA_UPLOAD, 10000, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COfflineDataStorgeTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COfflineDataStorgeTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COfflineDataStorgeTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COfflineDataStorgeTestDlg::OnBnClickedButtonTest()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OfflineDataStorge ods;

	map<string, vector<string>> offlineDatas;
	string logicFunction1;
	vector<string> parms1;

	logicFunction1 = "test";
	parms1.push_back("a");
	parms1.push_back("b");
	parms1.push_back("c");
	offlineDatas.insert(map<string, vector<string>>::value_type(logicFunction1, parms1));

	ods.saveOfflineData(offlineDatas);
}

void COfflineDataStorgeTestDlg::OnBnClickedButtonTest2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OfflineDataStorge ods;

	map<string, vector<string>> offlineDatas;
	string logicFunction1;
	vector<string> parms1;
	string logicFunction2;
	vector<string> parms2;

	logicFunction1 = "test2";
	parms1.push_back("1");
	parms1.push_back("2");

	logicFunction2 = "test3";
	parms2.push_back("3");
	parms2.push_back("4");
	parms2.push_back("5");
	offlineDatas.insert(map<string, vector<string>>::value_type(logicFunction1, parms1));
	offlineDatas.insert(map<string, vector<string>>::value_type(logicFunction2, parms2));

	ods.saveOfflineData(offlineDatas);
}

void COfflineDataStorgeTestDlg::OnBnClickedButtonTest3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OfflineDataStorge ods;
	vector<string> dataArray;
	dataArray.push_back("petter");
	dataArray.push_back("man");
	dataArray.push_back("26");
	dataArray.push_back("New York");
	ods.saveOfflineData("setPersionInfo", dataArray);
}

void COfflineDataStorgeTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case WM_OFFLINE_DATA_UPLOAD:
	{
								   KillTimer(nIDEvent);

								   OfflineDataStorge ods;
								   map<int, string> tempData;
								   vector<vector<string>> dataLists;
								   bool isSuccess = false;
								   char logData[1024] = { 0 };//��־
								   tempData = ods.getAllOfflineData();

								   if (tempData.size() == 0)
								   {
									   log.LogOut("[OfflineData] -- No Offline Data");
								   }
								   else
								   {
									   for (map<int, string >::const_iterator ptr = tempData.begin();
										   ptr != tempData.end(); ptr++) {
										   dataLists = ods.parseOfflineMapData(ptr->second);

										   isSuccess = true;

										   for (size_t i = 0; i < dataLists.size(); i++)
										   {

											   if (dataLists[i][0] == "setPersionInfo")
											   {
													bool bFlag = setPersionInfo(dataLists[i].at(1), dataLists[i].at(2), atoi(dataLists[i].at(3).c_str()), dataLists[i].at(4));
													isSuccess &= bFlag;
											   }
											   else if (dataLists[i][0] == "test")
											   {
												   bool bFlag = test(dataLists[i].at(1), dataLists[i].at(2), dataLists[i].at(3).c_str());
												   isSuccess &= bFlag;
											   }
											   else if (dataLists[i][0] == "test2")
											   {
												   bool bFlag = test2(dataLists[i].at(1), dataLists[i].at(2));
												   isSuccess &= bFlag;
											   }
											   else if (dataLists[i][0] == "test3")
											   {
												   //just for test faild,so return false
												   bool bFlag = test3(dataLists[i].at(1), dataLists[i].at(2), dataLists[i].at(3).c_str());
												   isSuccess &= bFlag;
											   }
											   else
											   {
												   isSuccess = false;
												   log.LogOut("[OfflineData] -- No Funciton Found");
											   }
										   }

										   //all data success
										   if (isSuccess)
										   {
											   ods.deleteOfflineData(ptr->first);
											   sprintf_s(logData, "[OfflineData] -- Sucess, data:%s", ptr->second.c_str());
											   log.LogOut(logData);
										   }
										   else
										   {
											   sprintf_s(logData, "��OfflineData�� -- failed, data:%s", ptr->second.c_str());
											   log.LogOut(logData);
										   }
										   
									   }
								   }
								   
								   //deal over , start timer
								   SetTimer(WM_OFFLINE_DATA_UPLOAD, 10000, NULL);
								   break;
	}
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);

}

bool COfflineDataStorgeTestDlg::test(string a, string b, string c)
{
	char str[256] = { 0 };
	sprintf_s(str, "function:test\n parms:\n a:%s\n b:%s\n c:%s", a.c_str(), b.c_str(), c.c_str());
	AfxMessageBox(str);

	return true;
}

bool COfflineDataStorgeTestDlg::test2(string a, string b)
{
	char str[256] = { 0 };
	sprintf_s(str, "function:test\n parms:\n a:%s\n b:%s\n", a.c_str(), b.c_str()); 
	AfxMessageBox(str);

	return true;
}

bool COfflineDataStorgeTestDlg::test3(string a, string b, string c)
{
	char str[256] = { 0 };
	sprintf_s(str, "function:test\n parms:\n a:%s\n b:%s\n c:%s", a.c_str(), b.c_str(), c.c_str()); 
	AfxMessageBox(str);
	//just for test faild,so return false
	return false;
}

bool COfflineDataStorgeTestDlg::setPersionInfo(string name, string sex, int age, string adddress)
{
	char str[256] = {0};
	sprintf_s(str,"function:setPersionInfo\n parms:\n name:%s\n sex:%s\n age:%d\n address:%s",name.c_str(),sex.c_str(),age,adddress.c_str());
	AfxMessageBox(str);

	if (age < 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}