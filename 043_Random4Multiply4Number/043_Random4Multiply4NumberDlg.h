
// 043_Random4Multiply4NumberDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy043_Random4Multiply4NumberDlg �Ի���
class CMy043_Random4Multiply4NumberDlg : public CDialog
{
// ����
public:
	int A[16];
	HICON hicon;
	CMy043_Random4Multiply4NumberDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY043_RANDOM4MULTIPLY4NUMBER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
	afx_msg void OnBnClickedButton1();
	CStatic tu[16];
};
