
// ImageProcessingSoftwareDlg.h : 헤더 파일
//

#pragma once


// CImageProcessingSoftwareDlg 대화 상자
class CImageProcessingSoftwareDlg : public CDialogEx
{
// 생성입니다.
public:
	CImageProcessingSoftwareDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IMAGEPROCESSINGSOFTWARE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
private:
	IplImage *image;
	IplImage *preimage;

protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
