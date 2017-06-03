
// OfflineDataStorgeTestDlg.h : ͷ�ļ�
//

#pragma once

#include "OfflineDataStorge.h"

#include "CLog4CPP.h"

#define WM_OFFLINE_DATA_UPLOAD WM_USER+1

using namespace itas109;
using namespace std;

// COfflineDataStorgeTestDlg �Ի���
class COfflineDataStorgeTestDlg : public CDialogEx
{

private:
	CLog4CPP log;
// ����
public:
	COfflineDataStorgeTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OFFLINEDATASTORGETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	bool test(string a, string b, string c);

	bool test2(string a, string b);

	bool test3(string a, string b, string c);

	bool setPersionInfo(string name, string sex, int age, string adddress);


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
