
// OfflineDataStorgeTestDlg.h : 头文件
//

#pragma once

#include "OfflineDataStorge.h"

#include "CLog4CPP.h"

#define WM_OFFLINE_DATA_UPLOAD WM_USER+1

using namespace itas109;
using namespace std;

// COfflineDataStorgeTestDlg 对话框
class COfflineDataStorgeTestDlg : public CDialogEx
{

private:
	CLog4CPP log;
// 构造
public:
	COfflineDataStorgeTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OFFLINEDATASTORGETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	bool test(string a, string b, string c);

	bool test2(string a, string b);

	bool test3(string a, string b, string c);

	bool setPersionInfo(string name, string sex, int age, string adddress);


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnBnClickedButtonTest2();
	afx_msg void OnBnClickedButtonTest3();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
