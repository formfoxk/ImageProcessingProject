// HistStrechDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessingSoftware.h"
#include "HistStrechDlg.h"
#include "afxdialogex.h"


// HistStrechDlg ��ȭ �����Դϴ�.

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


// HistStrechDlg �޽��� ó�����Դϴ�.
