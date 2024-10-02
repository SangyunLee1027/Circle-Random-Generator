#pragma once

#include "CircleInfo.h"
// CDlgImage ��ȭ �����Դϴ�.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgImage();

	CImage m_image; // background (black background)
	CircleInfo m_circleinfo;

private:
	
	CWnd* m_pParent;
	

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	void setCircle(int nCenterX, int nCenterY, int nRadius);
	void drawCircle();

	void load_image(CString file_path);
	void save_image(CString file_path);

private:
	void initImage();
	void find_center();
	void draw_text();
	//void drawCircle(CDC* pDC);
	

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
