#pragma once


// ValueDlg ��ȭ �����Դϴ�.

class ValueDlg : public CDialog
{
	DECLARE_DYNAMIC(ValueDlg)

public:
	ValueDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ValueDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_VALUE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_value;
};
