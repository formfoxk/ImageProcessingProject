// HistStrechDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessingSoftware.h"
#include "HistStrechDlg.h"
#include "afxdialogex.h"


// HistStrechDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(HistStrechDlg, CDialog)

HistStrechDlg::HistStrechDlg(CWnd* pParent /*=NULL*/)
	: CDialog(HistStrechDlg::IDD, pParent)
	, m_min(0)
	, m_max(0)
{

}

HistStrechDlg::~HistStrechDlg()
{
}

void HistStrechDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_min);
	DDX_Text(pDX, IDC_EDIT2, m_max);
}


BEGIN_MESSAGE_MAP(HistStrechDlg, CDialog)
END_MESSAGE_MAP()


// HistStrechDlg 메시지 처리기입니다.
