
// SW_assignment1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSW_assignment1App:
// �� Ŭ������ ������ ���ؼ��� SW_assignment1.cpp�� �����Ͻʽÿ�.
//

class CSW_assignment1App : public CWinApp
{
public:
	CSW_assignment1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSW_assignment1App theApp;