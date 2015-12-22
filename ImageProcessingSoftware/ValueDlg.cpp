// ValueDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessingSoftware.h"
#include "ValueDlg.h"
#include "afxdialogex.h"


// ValueDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(ValueDlg, CDialog)

ValueDlg::ValueDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ValueDlg::IDD, pParent)
	, m_value(0)
{

}

ValueDlg::~ValueDlg()
{
}

void ValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_value);
}


BEGIN_MESSAGE_MAP(ValueDlg, CDialog)
END_MESSAGE_MAP()


// ValueDlg 메시지 처리기입니다.
