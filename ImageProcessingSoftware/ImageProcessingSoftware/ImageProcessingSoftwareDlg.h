
// ImageProcessingSoftwareDlg.h : ��� ����
//

#pragma once


// CImageProcessingSoftwareDlg ��ȭ ����
class CImageProcessingSoftwareDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CImageProcessingSoftwareDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IMAGEPROCESSINGSOFTWARE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
private:
	IplImage *image;
	IplImage *preimage;

protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpen();
	afx_msg void OnSave();
	afx_msg void OnDsave();
	afx_msg void OnExit();
	afx_msg void OnUndo();
	afx_msg void OnTransLr();
	afx_msg void OnTransOd();
	afx_msg void OnEnlarghNn();
	afx_msg void OnEnlargeLi();
	afx_msg void OnReduceNn();
	afx_msg void OnReduceLi();
	afx_msg void OnRotation();
	afx_msg void OnTransRgbtogray();
	afx_msg void OnBrightPlus();
	afx_msg void OnBrightMinus();
	afx_msg void OnBrightpPlus();
	afx_msg void OnBrightpMinus();
	afx_msg void OnBitPlanes();
	afx_msg void OnMatrixD();
	afx_msg void OnMatrixD2();
	afx_msg void OnNegative();
	afx_msg void OnHistogramAuto();
	afx_msg void OnHistogramUser();
	afx_msg void OnHistogramEqul();
	afx_msg void OnTheresholding();
	afx_msg void OnGuassian33();
	afx_msg void OnGuassian77();
	afx_msg void OnSharpening77();
	afx_msg void OnAver77();
	afx_msg void OnMedian77();
	afx_msg void OnBinaryOpen();
	afx_msg void OnBinaryClose();
	afx_msg void OnGrayOpen();
	afx_msg void OnGrayClose();
	afx_msg void OnSobelMask();
	afx_msg void OnLaplacianMask();
	afx_msg void OnTool();
	afx_msg void OnStatusBar();
	afx_msg void OnHistogramWindow();
	afx_msg void OnHelp();
};
