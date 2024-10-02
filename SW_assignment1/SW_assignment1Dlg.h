
// SW_assignment1Dlg.h : 헤더 파일
//

#pragma once


#include "DlgImage.h"


// CSW_assignment1Dlg 대화 상자
class CSW_assignment1Dlg : public CDialogEx
{

private:
	CImage m_image;

// 생성입니다.
public:
	CSW_assignment1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CDlgImage* m_pDlgImage;
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SW_ASSIGNMENT1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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


