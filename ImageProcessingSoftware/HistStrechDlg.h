#pragma once


// HistStrechDlg ��ȭ �����Դϴ�.

class HistStrechDlg : public CDialog
{
	DECLARE_DYNAMIC(HistStrechDlg)

public:
	HistStrechDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~HistStrechDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HISTSTRETCH_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_min;
	int m_max;
};
