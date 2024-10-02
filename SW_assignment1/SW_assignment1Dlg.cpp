
// SW_assignment1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SW_assignment1.h"
#include "SW_assignment1Dlg.h"
#include "afxdialogex.h"
#include "CircleInfo.h"

#include <thread>
#include <afxdlgs.h> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UPDATE_CIRCLE_MSG (WM_USER + 1)
#define SAVE_CIRCLE (WM_USER + 2)

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.


struct Updated_CircleInfo{
	int nCurrentX;
	int nCurrentY;
	int nRadius;
};


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSW_assignment1Dlg 대화 상자



CSW_assignment1Dlg::CSW_assignment1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SW_ASSIGNMENT1_DIALOG, pParent)
	, m_nCenterX1(0)
	, m_nCenterY1(0)
	, m_nCenterX2(0)
	, m_nCenterY2(0)
	, m_CurX(0)
	, m_CurY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSW_assignment1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_nCenterX1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_nCenterY1);
	DDX_Text(pDX, IDC_EDIT_X2, m_nCenterX2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_nCenterY2);
	DDV_MinMaxInt(pDX, m_nCenterX1, 0, 640);
	DDV_MinMaxInt(pDX, m_nCenterY1, 0, 480);
	DDV_MinMaxInt(pDX, m_nCenterX2, 0, 640);
	DDV_MinMaxInt(pDX, m_nCenterY2, 0, 480);
	DDX_Text(pDX, IDC_EDIT2, m_CurX);
	DDX_Text(pDX, IDC_EDIT3, m_CurY);
}

BEGIN_MESSAGE_MAP(CSW_assignment1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CSW_assignment1Dlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CSW_assignment1Dlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CSW_assignment1Dlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CSW_assignment1Dlg::OnBnClickedBtnAction)
	ON_MESSAGE(UPDATE_CIRCLE_MSG, &CSW_assignment1Dlg::UpdateDisplay)
	ON_MESSAGE(SAVE_CIRCLE, &CSW_assignment1Dlg::SaveDisplay)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CSW_assignment1Dlg 메시지 처리기

BOOL CSW_assignment1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 1080, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(50, 100, 640, 480);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSW_assignment1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSW_assignment1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSW_assignment1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSW_assignment1Dlg::OnBnClickedBtnImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	UpdateData(true);
	
	m_pDlgImage->setCircle(m_nCenterX1, m_nCenterY1, rand() % 239 + 1);

	m_CurX = m_nCenterX1;
	m_CurY = m_nCenterY1;

	UpdateData(false);

	m_pDlgImage->drawCircle();

	m_pDlgImage->Invalidate();
	
}


void CSW_assignment1Dlg::OnBnClickedBtnSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SaveDisplay(0 ,0);
	
}



void CSW_assignment1Dlg::OnBnClickedBtnLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CFileDialog nFileDlg(TRUE, _T("bmp"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, _T("Image Files (*.bmp, *.jpg, *.png) | *.bmp;*.jpg;*.png | All Files (*.*)|(*/*||"));

	if (nFileDlg.DoModal() == IDOK) {
		CString nFilePath = nFileDlg.GetPathName();
		m_pDlgImage->load_image(nFilePath);
		m_pDlgImage->Invalidate();

		UpdateData(true);

		m_CurX = m_pDlgImage->m_circleinfo.get_centerX();
		m_CurY = m_pDlgImage->m_circleinfo.get_centerY();

		UpdateData(false);
	}

	
	
}


LRESULT  CSW_assignment1Dlg::SaveDisplay(WPARAM wParam, LPARAM lParam) {
	CreateDirectory(_T("../SW_Assignment1_imgs\\"), NULL);

	SYSTEMTIME cur_time;
	GetLocalTime(&cur_time);

	CString nFilename;
	nFilename.Format(_T("../SW_Assignment1_imgs\\Circle_%04d_%02d_%02d_%02d_%02d_%02d_%03d.bmp"), cur_time.wYear, cur_time.wMonth, cur_time.wDay, cur_time.wHour, cur_time.wMinute, cur_time.wSecond, cur_time.wMilliseconds);
	m_pDlgImage->save_image(nFilename);

	return 0;
}


LRESULT  CSW_assignment1Dlg::UpdateDisplay(WPARAM wParam, LPARAM lParam)
{
	/*CClientDC dc(this);
	m_image.Draw(dc, 0, 0);*/

	Updated_CircleInfo* pUpdateCircle = (Updated_CircleInfo*)wParam;

	int nCurrent_CenterX = pUpdateCircle->nCurrentX;
	int nCurrent_CenterY = pUpdateCircle->nCurrentY;
	int nCurrent_Radius = pUpdateCircle->nRadius;

	m_pDlgImage->setCircle(nCurrent_CenterX, nCurrent_CenterY, nCurrent_Radius);

	m_CurX = nCurrent_CenterX;
	m_CurY = nCurrent_CenterY;

	UpdateData(false);

	m_pDlgImage->drawCircle();

	m_pDlgImage->Invalidate();

	return 0;
}

void MoveCircle(CSW_assignment1Dlg* pParent, int nCurrent_CenterX, int nCenterX2, int nCurrent_CenterY, int nCenterY2, int nXdir, int nYdir)
{
	int nCurrent_Radius = pParent->m_pDlgImage->m_circleinfo.get_radius();

	while (nCurrent_CenterX != nCenterX2 || nCurrent_CenterY != nCenterY2) {
		if (nCurrent_CenterX != nCenterX2) {
			nCurrent_CenterX += nXdir;
		}
		if (nCurrent_CenterY != nCenterY2) {
			nCurrent_CenterY += nYdir;
		}

		Updated_CircleInfo* pUpdateCircle = new Updated_CircleInfo{ nCurrent_CenterX, nCurrent_CenterY, nCurrent_Radius };
		pParent->PostMessage(UPDATE_CIRCLE_MSG, (WPARAM)pUpdateCircle);

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	pParent->PostMessage(SAVE_CIRCLE, 0, 0);

	pParent->setThreadOff();

}


void CSW_assignment1Dlg::OnBnClickedBtnAction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pDlgImage->m_circleinfo.get_radius() == 0) {
		return;
	}

	if (thread_on) {
		return;
	}

	thread_on = true;

	UpdateData(true);

	int nCurrent_CenterX = m_pDlgImage->m_circleinfo.get_centerX();
	int nCurrent_CenterY = m_pDlgImage->m_circleinfo.get_centerY();
	

	int nNum_MoveX = m_nCenterX2 - nCurrent_CenterX;
	int nNum_MoveY = m_nCenterY2 - nCurrent_CenterY;

	if (!nNum_MoveX) {
		nNum_MoveX = 1;
	}

	if (!nNum_MoveY) {
		nNum_MoveY = 1;
	}
	
	int nXdir = nNum_MoveX / abs(nNum_MoveX);
	int nYdir = nNum_MoveY / abs(nNum_MoveY);


	
	std::thread t(MoveCircle, this, nCurrent_CenterX, m_nCenterX2, nCurrent_CenterY, m_nCenterY2, nXdir, nYdir);
	t.detach();
}


void CSW_assignment1Dlg::setThreadOff() {
	thread_on = false;
}

void CSW_assignment1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_pDlgImage) {
		delete m_pDlgImage;
	}
}
