
// ImageProcessingSoftware.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CImageProcessingSoftwareApp:
// �� Ŭ������ ������ ���ؼ��� ImageProcessingSoftware.cpp�� �����Ͻʽÿ�.
//

class CImageProcessingSoftwareApp : public CWinApp
{
public:
	CImageProcessingSoftwareApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// Dialog Accelerators
	public:HACCEL m_hAccelTable;

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
};

extern CImageProcessingSoftwareApp theApp;