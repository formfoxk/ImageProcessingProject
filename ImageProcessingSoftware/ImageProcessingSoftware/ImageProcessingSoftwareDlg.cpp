
// ImageProcessingSoftwareDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ImageProcessingSoftware.h"
#include "ImageProcessingSoftwareDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CImageProcessingSoftwareDlg 대화 상자



CImageProcessingSoftwareDlg::CImageProcessingSoftwareDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageProcessingSoftwareDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageProcessingSoftwareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImageProcessingSoftwareDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_OPEN, &CImageProcessingSoftwareDlg::OnOpen)
	ON_COMMAND(ID_SAVE, &CImageProcessingSoftwareDlg::OnSave)
	ON_COMMAND(ID_DSAVE, &CImageProcessingSoftwareDlg::OnDsave)
	ON_COMMAND(ID_EXIT, &CImageProcessingSoftwareDlg::OnExit)
	ON_COMMAND(ID_UNDO, &CImageProcessingSoftwareDlg::OnUndo)
	ON_COMMAND(ID_TRANS_LR, &CImageProcessingSoftwareDlg::OnTransLr)
	ON_COMMAND(ID_TRANS_OD, &CImageProcessingSoftwareDlg::OnTransOd)
	ON_COMMAND(ID_ENLARGH_NN, &CImageProcessingSoftwareDlg::OnEnlarghNn)
	ON_COMMAND(ID_ENLARGE_LI, &CImageProcessingSoftwareDlg::OnEnlargeLi)
	ON_COMMAND(ID_REDUCE_NN, &CImageProcessingSoftwareDlg::OnReduceNn)
	ON_COMMAND(ID_REDUCE_LI, &CImageProcessingSoftwareDlg::OnReduceLi)
	ON_COMMAND(ID_ROTATION, &CImageProcessingSoftwareDlg::OnRotation)
	ON_COMMAND(ID_TRANS_RGBTOGRAY, &CImageProcessingSoftwareDlg::OnTransRgbtogray)
	ON_COMMAND(ID_BRIGHT_PLUS, &CImageProcessingSoftwareDlg::OnBrightPlus)
	ON_COMMAND(ID_BRIGHT_MINUS, &CImageProcessingSoftwareDlg::OnBrightMinus)
	ON_COMMAND(ID_BRIGHTP_PLUS, &CImageProcessingSoftwareDlg::OnBrightpPlus)
	ON_COMMAND(ID_BRIGHTP_MINUS, &CImageProcessingSoftwareDlg::OnBrightpMinus)
	ON_COMMAND(ID_BIT_PLANES, &CImageProcessingSoftwareDlg::OnBitPlanes)
	ON_COMMAND(ID_MATRIX_D, &CImageProcessingSoftwareDlg::OnMatrixD)
	ON_COMMAND(ID_MATRIX_D2, &CImageProcessingSoftwareDlg::OnMatrixD2)
	ON_COMMAND(ID_NEGATIVE, &CImageProcessingSoftwareDlg::OnNegative)
	ON_COMMAND(ID_HISTOGRAM_AUTO, &CImageProcessingSoftwareDlg::OnHistogramAuto)
	ON_COMMAND(ID_HISTOGRAM_USER, &CImageProcessingSoftwareDlg::OnHistogramUser)
	ON_COMMAND(ID_HISTOGRAM_EQUL, &CImageProcessingSoftwareDlg::OnHistogramEqul)
	ON_COMMAND(ID_THERESHOLDING, &CImageProcessingSoftwareDlg::OnTheresholding)
	ON_COMMAND(ID_GUASSIAN_33, &CImageProcessingSoftwareDlg::OnGuassian33)
	ON_COMMAND(ID_GUASSIAN_77, &CImageProcessingSoftwareDlg::OnGuassian77)
	ON_COMMAND(ID_SHARPENING_77, &CImageProcessingSoftwareDlg::OnSharpening77)
	ON_COMMAND(ID_AVER_77, &CImageProcessingSoftwareDlg::OnAver77)
	ON_COMMAND(ID_MEDIAN_77, &CImageProcessingSoftwareDlg::OnMedian77)
	ON_COMMAND(ID_BINARY_OPEN, &CImageProcessingSoftwareDlg::OnBinaryOpen)
	ON_COMMAND(ID_BINARY_CLOSE, &CImageProcessingSoftwareDlg::OnBinaryClose)
	ON_COMMAND(ID_GRAY_OPEN, &CImageProcessingSoftwareDlg::OnGrayOpen)
	ON_COMMAND(ID_GRAY_CLOSE, &CImageProcessingSoftwareDlg::OnGrayClose)
	ON_COMMAND(ID_SOBEL_MASK, &CImageProcessingSoftwareDlg::OnSobelMask)
	ON_COMMAND(ID_LAPLACIAN_MASK, &CImageProcessingSoftwareDlg::OnLaplacianMask)
	ON_COMMAND(ID_TOOL, &CImageProcessingSoftwareDlg::OnTool)
	ON_COMMAND(ID_STATUS_BAR, &CImageProcessingSoftwareDlg::OnStatusBar)
	ON_COMMAND(ID_HISTOGRAM_WINDOW, &CImageProcessingSoftwareDlg::OnHistogramWindow)
	ON_COMMAND(ID_HELP, &CImageProcessingSoftwareDlg::OnHelp)
END_MESSAGE_MAP()


// CImageProcessingSoftwareDlg 메시지 처리기

BOOL CImageProcessingSoftwareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_pDC = GetDlgItem(IDC_VIEW)->GetDC();

    GetDlgItem(IDC_VIEW)->GetWindowRect(&dsprect);
    ScreenToClient(&dsprect);
    GetDlgItem(IDC_VIEW)->GetClientRect(&dlgrect);
    dsprect.right = dlgrect.right;
    dsprect.bottom = dlgrect.bottom;
    InitManager();


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CImageProcessingSoftwareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CImageProcessingSoftwareDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CImageProcessingSoftwareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 열기
void CImageProcessingSoftwareDlg::OnOpen()
{
	// 필터 설정
	char szFilter[]= "Image File(*.bmp;*.jpg)| *.bmp;*.jpg|ALL File(*.*)}";
 
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter, NULL);
	CString strPathName;

	if(IDOK == dlg.DoModal()) {

		strPathName = dlg.GetPathName();

	}
	else return;

	printf("열기 : %s", strPathName);
	cimg = cvLoadImage(strPathName, CV_LOAD_IMAGE_UNCHANGED);
	pimg = cimg;

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// 저장
void CImageProcessingSoftwareDlg::OnSave()
{
	if(cimg == nullptr){
		AfxMessageBox(_T("이미지를 열지 않았습니다."));
		return;
	}

	char strPathName[_MAX_PATH];
	GetCurrentDirectory( _MAX_PATH, strPathName); // 현재 폴더 경로
	StrCat(strPathName, "\\save.jpg");
	printf("저장 : %s", strPathName);
	if(!cvSaveImage(strPathName, cimg))
		AfxMessageBox(_T("저장을 실패 했습니다."));
	
}

// 다른이름으로 저장
void CImageProcessingSoftwareDlg::OnDsave()
{
	if(cimg == nullptr){
		AfxMessageBox(_T("이미지를 열지 않았습니다."));
		return;
	}
	// 필터 설정
	char szFilter[]= "Image File(*.bmp;*.jpg)| *.bmp;*.jpg|ALL File(*.*)}";
 
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY, szFilter, NULL);

	if(IDOK == dlg.DoModal()) {

		CString strPathName = dlg.GetPathName();
		printf("다른이름으로 저장 : %s", strPathName);
		if(!cvSaveImage(strPathName, cimg))
		AfxMessageBox(_T("저장을 실패 했습니다."));
	}
}

// 끝내기
void CImageProcessingSoftwareDlg::OnExit()
{
	PostQuitMessage(WM_QUIT);
}

// 실행 취소
void CImageProcessingSoftwareDlg::OnUndo()
{
	if(cimg != pimg){
		cvReleaseImage(&cimg);
		cimg = pimg;
		DisplayIplImage(cimg, m_pDC, dsprect);
	}
}

// 좌우반전
void CImageProcessingSoftwareDlg::OnTransLr()
{
	if(cimg != pimg){
		cvReleaseImage(&pimg);
		pimg = cimg;
	}
	cimg = reflect(cimg, 1);
	DisplayIplImage(cimg, m_pDC, dsprect);
}

// 상하반전
void CImageProcessingSoftwareDlg::OnTransOd()
{
	if(cimg != pimg){
		cvReleaseImage(&pimg);
		pimg = cimg;
	}
	cimg = reflect(cimg, -1);
	DisplayIplImage(cimg, m_pDC, dsprect);
}

// 확대 with NN
void CImageProcessingSoftwareDlg::OnEnlarghNn()
{
	MessageBox("확대 with NN");
}

// 확대 with 선형보간
void CImageProcessingSoftwareDlg::OnEnlargeLi()
{
	MessageBox("확대 with 선형보간");
}

// 축소 with NN
void CImageProcessingSoftwareDlg::OnReduceNn()
{
	MessageBox("축소 with NN");
}

// 축소 with 선형보간
void CImageProcessingSoftwareDlg::OnReduceLi()
{
	MessageBox("축소 with 선형보간");
}

// 회전
void CImageProcessingSoftwareDlg::OnRotation()
{
	MessageBox("회전");
}

// RGB to Gray 변환
void CImageProcessingSoftwareDlg::OnTransRgbtogray()
{
	MessageBox("RGB to Gray 변환");
}

// 밝기값 증가(+)
void CImageProcessingSoftwareDlg::OnBrightPlus()
{
	MessageBox("밝기값 증가(+)");
}

// 밝기값 감소(-)
void CImageProcessingSoftwareDlg::OnBrightMinus()
{
	MessageBox("밝기값 감소(-)");
}

// 밝기값 대비 증가(*)
void CImageProcessingSoftwareDlg::OnBrightpPlus()
{
	MessageBox("밝기값 대비 증가(*)");
}

// 밝기값 대비 감소(/)
void CImageProcessingSoftwareDlg::OnBrightpMinus()
{
	MessageBox("밝기값 대비 감소(/)");
}

// 비트플레인
void CImageProcessingSoftwareDlg::OnBitPlanes()
{
	MessageBox("비트플레인");
}

// D 행렬
void CImageProcessingSoftwareDlg::OnMatrixD()
{
	MessageBox("D 행렬");
}

// D2 행렬
void CImageProcessingSoftwareDlg::OnMatrixD2()
{
	MessageBox("D2 행렬");
}

// Negative 영상
void CImageProcessingSoftwareDlg::OnNegative()
{
	MessageBox("Negative 영상");
}

// 히스토그램 스트레칭 (자동)
void CImageProcessingSoftwareDlg::OnHistogramAuto()
{
	MessageBox("히스토그램 스트레칭 (자동)");
}

// 히스토그램 스트레칭 (사용자 입력)
void CImageProcessingSoftwareDlg::OnHistogramUser()
{
	MessageBox("히스토그램 스트레칭 (사용자 입력)");
}

// 히스토그램 평준화 (Equalization)
void CImageProcessingSoftwareDlg::OnHistogramEqul()
{
	MessageBox("히스토그램 평준화 (Equalization)");
}

// 임계치 필터링 (Thresholding)
void CImageProcessingSoftwareDlg::OnTheresholding()
{
	MessageBox("임계치 필터링 (Thresholding)");
}

// 가우시간 블러링(3*3)
void CImageProcessingSoftwareDlg::OnGuassian33()
{
	MessageBox("가우시간 블러링(3*3)");
}

// 가우시간 블러링(7*7)
void CImageProcessingSoftwareDlg::OnGuassian77()
{
	MessageBox("가우시간 블러링(7*7)");
}

// 샤프닝 (7*7)
void CImageProcessingSoftwareDlg::OnSharpening77()
{
	MessageBox("샤프닝 (7*7)");
}

// 평균값 필터링 (7*7)
void CImageProcessingSoftwareDlg::OnAver77()
{
	MessageBox("평균값 필터링 (7*7)");
}

// 중간값 필터링 (7*7)
void CImageProcessingSoftwareDlg::OnMedian77()
{
	MessageBox("중간값 필터링 (7*7)");
}

// 열림 연산 (Binary)
void CImageProcessingSoftwareDlg::OnBinaryOpen()
{
	MessageBox("열림 연산 (Binary)");
}

// 닫힘 연산 (Binary)
void CImageProcessingSoftwareDlg::OnBinaryClose()
{
	MessageBox("닫힘 연산 (Binary)");
}

// 열림 연산 (Gray)
void CImageProcessingSoftwareDlg::OnGrayOpen()
{
	MessageBox("열림 연산 (Gray)");
}
 
// 닫힘 연산 (Gray)
void CImageProcessingSoftwareDlg::OnGrayClose()
{
	MessageBox("닫힘 연산 (Gray)");
}


// 소벨 마스크
void CImageProcessingSoftwareDlg::OnSobelMask()
{
	MessageBox("소벨 마스크");
}

// 라플라시안 마스크
void CImageProcessingSoftwareDlg::OnLaplacianMask()
{
	MessageBox("라플라시안 마스크");
}

// 도구 상자
void CImageProcessingSoftwareDlg::OnTool()
{
	MessageBox("도구 상자");
}

// 상태 표시줄
void CImageProcessingSoftwareDlg::OnStatusBar()
{
	MessageBox("상태 표시줄");
}

// 히스토그램 윈도우
void CImageProcessingSoftwareDlg::OnHistogramWindow()
{
	MessageBox("히스토그램 윈도우");
}

// 도움말
void CImageProcessingSoftwareDlg::OnHelp()
{
	MessageBox("도움말");
}

void CImageProcessingSoftwareDlg::InitManager()
{
    CStatic *staticSize = (CStatic *)GetDlgItem(IDC_VIEW);

    staticSize->GetClientRect(dsprect);

    m_pBmiColor = (BITMAPINFOHEADER*)malloc(sizeof(BITMAPINFOHEADER));
    m_pBmiColor->biSize = sizeof(BITMAPINFOHEADER);
    m_pBmiColor->biBitCount = 24;
    m_pBmiColor->biWidth = 0;
    m_pBmiColor->biHeight = 0;
    m_pBmiColor->biPlanes = 1;

    m_pBmiColor->biCompression = BI_RGB;
    m_pBmiColor->biSizeImage = 0;

    m_pBmiColor->biXPelsPerMeter = 0;
    m_pBmiColor->biYPelsPerMeter = 0;

    m_pBmiColor->biClrUsed = 0;
    m_pBmiColor->biClrImportant = 0;
    m_pBmiColor->biClrUsed = 0;
}

void CImageProcessingSoftwareDlg::DisplayIplImage(IplImage* pImgIpl, CDC* pDC, CRect rect)
{
    BITMAPINFO bitmapInfo;

    bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfo.bmiHeader.biPlanes = 1;
    bitmapInfo.bmiHeader.biCompression = BI_RGB;
    bitmapInfo.bmiHeader.biXPelsPerMeter = 100;
    bitmapInfo.bmiHeader.biYPelsPerMeter = 100;
    bitmapInfo.bmiHeader.biClrUsed = 0;
    bitmapInfo.bmiHeader.biClrImportant = 0;
    bitmapInfo.bmiHeader.biSizeImage = 0;
    bitmapInfo.bmiHeader.biWidth = pImgIpl->width;
    bitmapInfo.bmiHeader.biHeight = -pImgIpl->height;

    IplImage* tempImage = NULL;

    if (pImgIpl->nChannels == 3)
    {
        tempImage = (IplImage*)cvClone(pImgIpl);
        bitmapInfo.bmiHeader.biBitCount = tempImage->depth * tempImage->nChannels;
    }
    else if (pImgIpl->nChannels == 1)
    {
        tempImage = cvCreateImage(cvGetSize(pImgIpl), IPL_DEPTH_8U, 3);
        cvCvtColor(pImgIpl, tempImage, CV_GRAY2BGR);
        bitmapInfo.bmiHeader.biBitCount = tempImage->depth * tempImage->nChannels;
    }

    if (tempImage != NULL)
    {
        pDC->SetStretchBltMode(COLORONCOLOR);
        ::StretchDIBits(pDC->GetSafeHdc(), rect.left, rect.top, rect.right, rect.bottom,
            0, 0, tempImage->width, tempImage->height, tempImage->imageData, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);
        cvReleaseImage(&tempImage);
    }
}

IplImage *CImageProcessingSoftwareDlg::reflect(IplImage *image, int value){
	IplImage *tmpImage = cvCloneImage(image);
	
	int wth = tmpImage->width; 
	int hit = tmpImage->height;

	CvScalar temp;

	if (value > 0){

		for (int j = 0; j < hit; j++)
			for (int i = 0; i < wth / 2; i++){

				temp = cvGet2D(tmpImage, j, i);
				cvSet2D(tmpImage, j, i, cvGet2D(tmpImage, j, wth - i - 1));
				cvSet2D(tmpImage, j, wth - 1 - i, temp);
			}
	}
	else{
		for (int j = 0; j < hit / 2; j++)
			for (int i = 0; i < wth; i++){

				temp = cvGet2D(tmpImage, j, i);
				cvSet2D(tmpImage, j, i, cvGet2D(tmpImage, hit-j-1, i));
				cvSet2D(tmpImage, hit - j - 1, i, temp);
			}
	}

	return tmpImage;
}