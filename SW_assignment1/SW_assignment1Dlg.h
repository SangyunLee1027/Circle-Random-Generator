
// SW_assignment1Dlg.h : ��� ����
//

#pragma once


#include "DlgImage.h"


// CSW_assignment1Dlg ��ȭ ����
class CSW_assignment1Dlg : public CDialogEx
{

private:
	CImage m_image;

// �����Դϴ�.
public:
	CSW_assignment1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CDlgImage* m_pDlgImage;
	

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SW_ASSIGNMENT1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnAction();


	LRESULT SaveDisplay(WPARAM wParam, LPARAM lParam);
	LRESULT LoadDisplay(WPARAM wParam, LPARAM lParam);
	LRESULT UpdateDisplay(WPARAM wParam, LPARAM lParam);
	
	void setThreadOff();

//	afx_msg void OnBnClickedBtnDlg();
	afx_msg void OnDestroy();

private:
	int m_nCenterX1;
	int m_nCenterY1;
	int m_nCenterX2;
	int m_nCenterY2;

	bool thread_on = false;

	int m_CurX;
	int m_CurY;
};


void MoveCircle(CSW_assignment1Dlg* pParent, int nCurrent_CenterX, int nCenterX2, int nCurrent_CenterY, int nCenterY2, int nXdir, int nYdir);


