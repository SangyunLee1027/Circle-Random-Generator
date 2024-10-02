// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SW_assignment1.h"
#include "DlgImage.h"
#include "afxdialogex.h"

#include <iostream>
// CDlgImage 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기입니다.


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	if (m_image != NULL) {
		m_image.Destroy();
	}

	//MoveWindow(0, 0, 640, 480);
	initImage();

	

	//UpdateDisplay();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}




void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	
	if (!m_image.IsNull()) {
		m_image.Draw(dc, 0, 0);
	}

}

void CDlgImage::initImage() {
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; ++i) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0, nWidth * nHeight);
}

void CDlgImage::drawCircle()//CDC* pDC)
{
	int nCenterX = m_circleinfo.get_centerX();
	int nCenterY = m_circleinfo.get_centerY();
	int nRadius = m_circleinfo.get_radius();

	int nTopLeftX = nCenterX - nRadius;
	int nTopLeftY = nCenterY - nRadius;
	int nBottomRightX = nCenterX + nRadius;
	int nBottomRightY = nCenterY + nRadius;
	
	HDC hDC = m_image.GetDC();

	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));

	int width = m_image.GetWidth();
	int height = m_image.GetHeight();

	RECT rect = { 0, 0, width, height };

	FillRect(hDC, &rect, hBrush);

	Ellipse(hDC, nTopLeftX, nTopLeftY, nBottomRightX, nBottomRightY);
	m_image.ReleaseDC();
}

void CDlgImage::setCircle(int nCenterX, int nCenterY, int nRadius)
{
	m_circleinfo.set_params(nCenterX, nCenterY, nRadius);
}


BOOL CDlgImage::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return true;
}

CString test_g_strFileImage = _T("C:\\SW_Assignment1_imgs\\");

void CDlgImage::load_image(CString file_path) {
	if (!m_image.IsNull()) {
		m_image.Destroy();
	}

	m_image.Load(file_path);
	
	find_center();
}

void CDlgImage::save_image(CString nFile_name) {
	
	
	m_image.Save(nFile_name);
}



void CDlgImage::find_center()
{
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();

	int nMaxX = 0;
	int nMinX = INT_MAX;
	int nMaxY = 0;
	int nMinY = INT_MAX;

	for (int i = 0; i< nHeight; ++i) {
		for (int j = 0; j < nWidth; ++j) {
			if (fm[i * nPitch + j] == 255) {
				nMaxX = max(nMaxX, j);
				nMinX = min(nMinX, j);
				nMaxY = max(nMaxY, i);
				nMinY = min(nMinY, i);
			}
		}
	}

	m_circleinfo.set_params((nMaxX + nMinX) / 2, (nMaxY + nMinY) / 2, (nMaxX - nMinX)/2);


	int nCenterX = m_circleinfo.get_centerX();
	int nCenterY = m_circleinfo.get_centerY();
	int nRadius = m_circleinfo.get_radius();

	for (int i = 0; i< nRadius / 4; ++i) {
		fm[(nCenterY + i) * nPitch + (nCenterX + i)] = 123;
		fm[(nCenterY + i) * nPitch + (nCenterX - i)] = 123;
		fm[(nCenterY - i) * nPitch + (nCenterX - i)] = 123;
		fm[(nCenterY - i) * nPitch + (nCenterX + i)] = 123;
	}
	
	
	HDC hDC = m_image.GetDC();

	CString nOutput;
	nOutput.Format(_T("x: %d, y: %d"), nCenterX, nCenterY);

	TextOut(hDC, nCenterX + 15, nCenterY, nOutput, nOutput.GetLength());
	m_image.ReleaseDC();
}

void CDlgImage::draw_text() {

	int nCenterX = m_circleinfo.get_centerX();
	int nCenterY = m_circleinfo.get_centerY();
	int nRadius = m_circleinfo.get_radius();

	HDC hDC = m_image.GetDC();

	CString nOutput;
	nOutput.Format(_T("x: %d, y: %d", nCenterX, nCenterY));

	AfxMessageBox(nOutput);

	TextOut(hDC, nCenterX + 15, nCenterY, nOutput, nOutput.GetLength());
	m_image.ReleaseDC();
}
//
//void CDlgImage::draw_center()
//{
//	unsigned char* fm = (unsigned char*)m_image.GetBits();
//	int nWidth = m_image.GetWidth();
//	int nHeight = m_image.GetHeight();
//	int nPitch = m_image.GetPitch();
//
//	int nCenterX = m_circleinfo.get_centerX();
//	int nCenterY = m_circleinfo.get_centerY();
//	int nRadius = m_circleinfo.get_radius();
//
//	for (int i = 0; i< nRadius/2; ++i) {
//		fm[(nCenterY + i) * nPitch + (nCenterX + i)] = 123;
//		fm[(nCenterY + i) * nPitch + (nCenterX - i)] = 123;
//		fm[(nCenterY - i) * nPitch + (nCenterX - i)] = 123;
//		fm[(nCenterY - i) * nPitch + (nCenterX + i)] = 123;
//	}
//	
//
//
//}
