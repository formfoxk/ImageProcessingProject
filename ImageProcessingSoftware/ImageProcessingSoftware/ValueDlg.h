#pragma once


// ValueDlg 대화 상자입니다.

class ValueDlg : public CDialog
{
	DECLARE_DYNAMIC(ValueDlg)

public:
	ValueDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ValueDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_VALUE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_value;
};
