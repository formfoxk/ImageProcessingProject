
// ImageProcessingSoftwareDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ImageProcessingSoftware.h"
#include "ImageProcessingSoftwareDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.14159265
// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CImageProcessingSoftwareDlg ��ȭ ����



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


// CImageProcessingSoftwareDlg �޽��� ó����

BOOL CImageProcessingSoftwareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_pDC = GetDlgItem(IDC_VIEW)->GetDC();

    GetDlgItem(IDC_VIEW)->GetWindowRect(&dsprect);
    ScreenToClient(&dsprect);
    GetDlgItem(IDC_VIEW)->GetClientRect(&dlgrect);
    dsprect.right = dlgrect.right;
    dsprect.bottom = dlgrect.bottom;
    InitManager();


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CImageProcessingSoftwareDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CImageProcessingSoftwareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// ����
void CImageProcessingSoftwareDlg::OnOpen()
{
	char szFilter[] = "Image (*.bmp, *.gif, *.jpg) |*.bmp;*.gif;*.jpg||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);

	if (IDOK != dlg.DoModal()) {
		return;
	}

	// FileLoad
	CString fileName = dlg.GetPathName();
	cimg = cvLoadImage(fileName, CV_LOAD_IMAGE_COLOR);


	if(pimg == NULL) 
		initUndo();

	// Display
	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ����
void CImageProcessingSoftwareDlg::OnSave()
{
	printf("Log : Image storage ");
	if(cimg != NULL){
		
		CString fileName("./save.jpg");
		cvSaveImage(fileName, cimg);

		printf("[SUCCESS]\n");
	}else
		printf("[FAILURE]\n");
}

// �ٸ��̸����� ����
void CImageProcessingSoftwareDlg::OnDsave()
{
	char szFilter[] = "JPG (*.jpg) |*.jpg|BMP (*.bmp) |*.bmp|GIF (*.gif) |*.gif||";
	CFileDialog dlg(FALSE, "|*.jpg|", NULL, OFN_HIDEREADONLY, szFilter);

	if (IDOK != dlg.DoModal()) return;

	CString fileName = dlg.GetPathName();

	cvSaveImage(fileName, cimg);
}

// ������
void CImageProcessingSoftwareDlg::OnExit()
{
	PostQuitMessage(WM_QUIT);
}

// ���� ���
void CImageProcessingSoftwareDlg::OnUndo()
{
	printf("Log : Undo ");
	// �̹��� �ε尡 �ȵ� ��� || �̹����� ���� ���
	if(pimg == NULL && cimg == NULL || pimg == cimg){
		printf("[FAILURE]\n");
		return;
	}
	else{
		cvReleaseImage(&cimg);
		cimg = pimg;
		DisplayIplImage(cimg, m_pDC, dsprect);
	
		printf("[SUCCESS]\n");
	}
}

// �¿����
void CImageProcessingSoftwareDlg::OnTransLr()
{
	printf("Log : Image invert left and right ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width/2; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			cvSet2D(cimg, i, j, cvGet2D(cimg, i, cimg->width - j -1));
			cvSet2D(cimg, i,cimg->width- j -1, tmp);
		}
	}
	DisplayIplImage(cimg, m_pDC, dsprect);
	printf("[SUCCESS]\n");
}

// ���Ϲ���
void CImageProcessingSoftwareDlg::OnTransOd()
{
	printf("Log : Image invert up and down ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	for (int i = 0; i < cimg->height /2; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			cvSet2D(cimg, i, j, cvGet2D(cimg,cimg->height -  i - 1, j));
			cvSet2D(cimg, cimg->height - i - 1, j, tmp);
		}
	}
	DisplayIplImage(cimg, m_pDC, dsprect);
	printf("[SUCCESS]\n");
}

// Ȯ�� with NN
void CImageProcessingSoftwareDlg::OnEnlarghNn()
{
	printf("Log : Ȯ�� with NN ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg;
	if (dlg.DoModal() != IDOK){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	int value = dlg.m_value;
	if (value <= 0) return;

	IplImage* grayImage = cvCloneImage(cimg);
	// resize
	IplImage* resizeImage = cvCreateImage(cvSize(cimg->width * value, cimg->height * value), cimg->depth, cimg->nChannels);

	for (int i = 0; i < cimg->height - 1; i++)
		for (int j = 0; j < cimg->width - 1; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			for (int y = 0; y < value; y++)
				for (int x = 0; x < value; x++)
					cvSet2D(resizeImage, i*value + y, j*value + x, v);
		}

	if (cimg != NULL) {
		cvReleaseImage(&cimg);
		cimg = NULL;
	}
	cimg = resizeImage;

	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// Ȯ�� with ��������
void CImageProcessingSoftwareDlg::OnEnlargeLi()
{
	printf("Log : Ȯ�� with ��������");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg;
	if (dlg.DoModal() != IDOK){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	int value = dlg.m_value;
	if (value <= 0) return;

	IplImage* grayImage = cvCloneImage(cimg);
	// resize
	IplImage* resizeImage = cvCreateImage(cvSize(cimg->width * value, cimg->height * value), cimg->depth, cimg->nChannels);

	for (int i = 0; i < cimg->height-1; i++)
		for (int j = 0; j < cimg->width-1; j++)
		{
			CvScalar a = cvGet2D(grayImage, i, j);
			CvScalar b = cvGet2D(grayImage, i, j+1);
			CvScalar c = cvGet2D(grayImage, i+1, j);
			CvScalar d = cvGet2D(grayImage, i+1, j+1);
			double aY = 0.299*a.val[2] + 0.587*a.val[1] + 0.114*a.val[0];
			double bY = 0.299*b.val[2] + 0.587*b.val[1] + 0.114*b.val[0];
			double cY = 0.299*c.val[2] + 0.587*c.val[1] + 0.114*c.val[0];
			double dY = 0.299*d.val[2] + 0.587*d.val[1] + 0.114*d.val[0];

			for (int y = 0; y < value; y++){
				for (int x = 0; x < value; x++){
					double alpha = (x+1) / (double)value;
					double beta = (y+1) / (double)value;
					double eY = aY + alpha * (bY - aY);
					double fY = cY + alpha * (dY - cY);
					double xY = eY + beta * (fY - eY);

					CvScalar v;
					v.val[2] = xY;
					v.val[1] = xY;
					v.val[0] = xY;

					cvSet2D(resizeImage, i*value + y, j*value + x, v);
				}
			}
		}

	if (cimg != NULL) {
		cvReleaseImage(&cimg);
		cimg = NULL;
	}
	cimg = resizeImage;

	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��� with NN
void CImageProcessingSoftwareDlg::OnReduceNn()
{
	printf("Log : ��� with NN");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg;
	if (dlg.DoModal() != IDOK){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	int i, j, value = dlg.m_value;
	if (value <= 0) return;

	IplImage* grayImage = cvCloneImage(cimg);
	// resize
	IplImage* resizeImage = cvCreateImage(cvSize(cimg->width / value, cimg->height / value), cimg->depth, cimg->nChannels);

	for (i = 0; i < cimg->height - 1; i+=value)
		for (j = 0; j < cimg->width - 1; j+=value)
		{
			if (i / value < resizeImage->height && j / value < resizeImage->width)
            {
				CvScalar v = cvGet2D(grayImage, i, j);
				cvSet2D(resizeImage, i/value, j/value, v);
			}
		}

	if (cimg != NULL) {
		cvReleaseImage(&cimg);
		cimg = NULL;
	}
	cimg = resizeImage;

	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��� with ��������
void CImageProcessingSoftwareDlg::OnReduceLi()
{
	printf("Log : ��� with ��������");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg;
	if (dlg.DoModal() != IDOK){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	int i, j, value = dlg.m_value;
	if (value <= 0) return;

	IplImage* grayImage = cvCloneImage(cimg);
	// resize
	IplImage* resizeImage = cvCreateImage(cvSize(cimg->width / value, cimg->height / value), cimg->depth, cimg->nChannels);

	for (i = 0; i < cimg->height - 1; i+=value)
		for (j = 0; j < cimg->width - 1; j+=value)
		{
			if (i / value < resizeImage->height && j / value < resizeImage->width)
            {
				int ni = i + value > cimg->height - 1 ? cimg->height - 1 : i + value;
				int nj = j + value > cimg->width - 1 ? cimg->width - 1 : j + value;
				CvScalar a = cvGet2D(grayImage, i, j);
				CvScalar b = cvGet2D(grayImage, i, nj);
				CvScalar c = cvGet2D(grayImage, ni, j);
				CvScalar d = cvGet2D(grayImage, ni, nj);
				double aY = 0.299*a.val[2] + 0.587*a.val[1] + 0.114*a.val[0];
				double bY = 0.299*b.val[2] + 0.587*b.val[1] + 0.114*b.val[0];
				double cY = 0.299*c.val[2] + 0.587*c.val[1] + 0.114*c.val[0];
				double dY = 0.299*d.val[2] + 0.587*d.val[1] + 0.114*d.val[0];

				double alpha = 1 / (double)value;
				double beta = 1 / (double)value;
				double eY = aY + alpha * (bY - aY);
				double fY = cY + alpha * (dY - cY);
				double xY = eY + beta * (fY - eY);

				CvScalar v;
				v.val[2] = xY;
				v.val[1] = xY;
				v.val[0] = xY;

				cvSet2D(resizeImage, i / value, j / value, v);
			}
		}

	if (cimg != NULL) {
		cvReleaseImage(&cimg);
		cimg = NULL;
	}
	cimg = resizeImage;

	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ȸ��
void CImageProcessingSoftwareDlg::OnRotation()
{
	printf("Log : Rotation");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg;
	if (dlg.DoModal() != IDOK){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	int i, j, value = dlg.m_value;
	if (value <= 0) return;
	if (value > 90)
	{
		AfxMessageBox("ȸ�� ������ 0 ~ 90�� ���̸� �Է��� �ֽñ� �ٶ��ϴ�.");
		return;
	}

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);

	double maxX = cos(value * PI / 180.0) * grayImage->width;
	double maxY = cos((90-value) * PI / 180.0) * grayImage->width + cos(value * PI / 180.0) * grayImage->height;
	double minX = -cos((90-value) * PI / 180.0) * grayImage->height;
	double minY = 0.0;
	double maxW = abs(maxX - minX);
	double maxH = abs(maxY - minY);
	// rotation (�̹��� ũ�� ���� �� �����ؾ���)
	IplImage* rotationImage = cvCreateImage(cvSize(maxW, maxH), grayImage->depth, grayImage->nChannels);

	// clear
	for (int i = 0; i < rotationImage->height; i++)
	{
		for (int j = 0; j < rotationImage->width; j++)
		{
			CvScalar v;
			v.val[0] = 0;
			v.val[1] = 0;
			v.val[2] = 0;
			cvSet2D(rotationImage, i, j, v);
		}
	}

	// rotation
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			double mx = (abs(minX) + cos(value * PI / 180.0)*j - sin(value * PI / 180.0)*i);
			double my = sin(value * PI / 180.0)*j + cos(value * PI / 180.0)*i;
			if (mx < 0 || mx >= rotationImage->width) continue;
			if (my < 0 || my >= rotationImage->height) continue;

			CvScalar v = cvGet2D(grayImage, i, j);
			cvSet2D(rotationImage, my, mx, v);
		}
	}

	if (cimg != NULL) {
		cvReleaseImage(&cimg);
		cvReleaseImage(&grayImage);
		cimg = NULL;
	}
	cimg = rotationImage;
	printf("[SUCCESS]\n");
	DisplayIplImage(cimg, m_pDC, dsprect);
}

// RGB to Gray ��ȯ
void CImageProcessingSoftwareDlg::OnTransRgbtogray()
{
	printf("Log : Image RGB to Gray ");
	if(tranRgbToGray()) printf("[SUCCESS]\n");
	else printf("[FAILURE]\n");
		
	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��Ⱚ ����(+)
void CImageProcessingSoftwareDlg::OnBrightPlus()
{
	printf("Log : Image increase brightness ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg = new ValueDlg();
	if (IDOK != dlg.DoModal()) return;

	initUndo();
	tranRgbToGray();

	int i, j, value;
	value = dlg.m_value;

	IplImage* grayImage = cvCloneImage(cimg);
	for (i = 0; i < grayImage->height; i++)
	{
		for (j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double R = v.val[2];
			double G = v.val[1];
			double B = v.val[0];

			int Y = (int)(0.299*R + 0.587*G + 0.114*B) + value;
			Y = Y > 255 ? 255 : Y;
			int Cb = 0, Cr = 0;

			v.val[2] = Y + 1.402*Cr;
			v.val[1] = Y - 0.344*Cb - 0.714*Cr;
			v.val[0] = Y + 1.772*Cb;

			cvSet2D(cimg, i, j, v);
		}
	}
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��Ⱚ ����(-)
void CImageProcessingSoftwareDlg::OnBrightMinus()
{
	printf("Log : Image decrease brightness ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg = new ValueDlg();
	if (IDOK != dlg.DoModal()) return;

	initUndo();
	tranRgbToGray();

	int i, j, value;
	value = dlg.m_value;

	IplImage* grayImage = cvCloneImage(cimg);
		for (i = 0; i < grayImage->height; i++)
		{
			for (j = 0; j < grayImage->width; j++)
			{
				CvScalar v = cvGet2D(grayImage, i, j);
				double R = v.val[2];
				double G = v.val[1];
				double B = v.val[0];

				int Y = (int)(0.299*R + 0.587*G + 0.114*B) - value;
				Y = Y < 0? 0: Y;
				int Cb = 0, Cr = 0;

				v.val[2] = Y + 1.402*Cr;
				v.val[1] = Y - 0.344*Cb - 0.714*Cr;
				v.val[0] = Y + 1.772*Cb;

				cvSet2D(cimg, i, j, v);
			}
		}
		cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��Ⱚ ��� ����(*)
void CImageProcessingSoftwareDlg::OnBrightpPlus()
{
	printf("Log : Image increase contrast brightness ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg = new ValueDlg();
	if (IDOK != dlg.DoModal()) return;

	initUndo();
	tranRgbToGray();

	int i, j;
	int value = dlg.m_value;

	IplImage* grayImage = cvCloneImage(cimg);
	for (i = 0; i < grayImage->height; i++)
	{
		for (j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double R = v.val[2];
			double G = v.val[1];
			double B = v.val[0];

			int Y = (int)(0.299*R + 0.587*G + 0.114*B) * value;
			Y = Y > 255 ? 255 : Y;
			int Cb = 0, Cr = 0;

			v.val[2] = Y + 1.402*Cr;
			v.val[1] = Y - 0.344*Cb - 0.714*Cr;
			v.val[0] = Y + 1.772*Cb;

			cvSet2D(cimg, i, j, v);
		}
	}
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��Ⱚ ��� ����(/)
void CImageProcessingSoftwareDlg::OnBrightpMinus()
{
	printf("Log : Image decrease contrast brightness ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg = new ValueDlg();
	if (IDOK != dlg.DoModal()) return;

	initUndo();
	tranRgbToGray();

	int i, j;
	int value = dlg.m_value;

	IplImage* grayImage = cvCloneImage(cimg);
	for (i = 0; i < grayImage->height; i++)
		for (j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double R = v.val[2];
			double G = v.val[1];
			double B = v.val[0];

			int Y = (int)(0.299*R + 0.587*G + 0.114*B) / value;
			Y = Y > 255 ? 255 : Y;
			int Cb = 0, Cr = 0;

			v.val[2] = Y + 1.402*Cr;
			v.val[1] = Y - 0.344*Cb - 0.714*Cr;
			v.val[0] = Y + 1.772*Cb;

			cvSet2D(cimg, i, j, v);
		}
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��Ʈ�÷���
void CImageProcessingSoftwareDlg::OnBitPlanes()
{
	printf("Log : bitplane ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	ValueDlg dlg = new ValueDlg();
	if (IDOK != dlg.DoModal()) return;

	initUndo();
	
	CvSize img_size;
	img_size.height = cimg->height;
	img_size.width = cimg->width;
	IplImage* gray = cvCreateImage(img_size, IPL_DEPTH_8U, 1);

	double r, g, b;
	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			r = tmp.val[2];
			g = tmp.val[1];
			b = tmp.val[0];
			cvSet2D(gray, i, j,cvScalar( b * 0.11 + g * 0.59 + r * 0.3 ,0,0,0));
		}

	}
	cvReleaseImage(&cimg);
	cimg = gray;

	int value = dlg.m_value;
	
	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			tmp.val[0] = (int)(tmp.val[0] / pow(2.0, value)) % 2;
			if (tmp.val[0] == 0)
				tmp.val[0] = 0;
			else
				tmp.val[0] = 255;
			cvSet2D(cimg, i, j, tmp);
		}
	}
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// D ���
void CImageProcessingSoftwareDlg::OnMatrixD()
{
	printf("Log : D Matrix");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	int D[2][2] = {
		{ 0, 128 },
		{ 192, 64 }
	};

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i+=2)
	{
		for (int j = 0; j < grayImage->width; j+=2)
		{
			for (int y = 0; y < 2 && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < 2 && x + j < grayImage->width; x++)
				{
					CvScalar v = cvGet2D(grayImage, i + y, j + x);
					double R = v.val[2];
					double G = v.val[1];
					double B = v.val[0];

					int Y = (int)(0.299*R + 0.587*G + 0.114*B);
					Y = 0xFF * (Y > D[y][x]);
					int Cb = 0, Cr = 0;

					v.val[2] = Y;
					v.val[1] = Y;
					v.val[0] = Y;
					cvSet2D(cimg, i + y, j + x, v);
				}
			}
		}
	}
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// D2 ���
void CImageProcessingSoftwareDlg::OnMatrixD2()
{
	printf("Log : Image D2 Matrix");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	int D[4][4] = {
		{ 0, 128, 32, 160 },
		{ 192, 64,224, 96 },
		{ 48, 176,16, 144 },
		{ 240, 112,208,80 }
	};

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i+=4)
	{
		for (int j = 0; j < grayImage->width; j+=4)
		{
			for (int y = 0; y < 4 && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < 4 && x + j < grayImage->width; x++)
				{
					CvScalar v = cvGet2D(grayImage, i + y, j + x);
					double R = v.val[2];
					double G = v.val[1];
					double B = v.val[0];

					int Y = (int)(0.299f*R + 0.587f*G + 0.114f*B);
					Y = 0xFF * (Y > D[y][x]);
					int Cb = 0, Cr = 0;

					v.val[2] = Y;
					v.val[1] = Y;
					v.val[0] = Y;
					cvSet2D(cimg, i + y, j + x, v);
				}
			}
		}
	}

	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// Negative ����
void CImageProcessingSoftwareDlg::OnNegative()
{
	printf("Log : Image  ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double R = v.val[2];
			double G = v.val[1];
			double B = v.val[0];

			int Y = 255 - (int)(0.299*R + 0.587*G + 0.114*B);
			int Cb = 0, Cr = 0;

			v.val[2] = Y + 1.402*Cr;
			v.val[1] = Y - 0.344*Cb - 0.714*Cr;
			v.val[0] = Y + 1.772*Cb;

			cvSet2D(cimg, i, j, v);
		}
	}
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ������׷� ��Ʈ��Ī (�ڵ�)
void CImageProcessingSoftwareDlg::OnHistogramAuto()
{
	printf("Log : Histogram Stretching Auto ");

	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	int min = -1, max = -1;
	for (int i = 0; i < 256; i++) {
		if (min == -1 && hist[i] != 0)
			min = i;
		if (hist[i] != 0)
			max = i;
	}

	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			double R = tmp.val[2];
			double G = tmp.val[1];
			double B = tmp.val[0];

			double Y = (255 * ((0.299*R + 0.587*G + 0.114*B) - min) / (double)(max - min));

			tmp.val[2] = Y;
			tmp.val[1] = Y;
			tmp.val[0] = Y;

			cvSet2D(cimg, i, j, tmp);
		}
	}
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ������׷� ��Ʈ��Ī (����� �Է�)
void CImageProcessingSoftwareDlg::OnHistogramUser()
{
	printf("Log : Histogram Stretching User");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}
	
	HistStrechDlg dlg = new HistStrechDlg();
	if (IDOK != dlg.DoModal()){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	int min = dlg.m_min;
	int max = dlg.m_max;
	if (min > max){
		int tmp = min;
		min = max;
		max = tmp;
	}

	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			double R = tmp.val[2];
			double G = tmp.val[1];
			double B = tmp.val[0];

			double Y = (255 * ((0.299*R + 0.587*G + 0.114*B) - min) / (double)(max - min));

			tmp.val[2] = Y;
			tmp.val[1] = Y;
			tmp.val[0] = Y;
			cvSet2D(cimg, i, j, tmp);
		}
	}

	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ������׷� ����ȭ (Equalization)
void CImageProcessingSoftwareDlg::OnHistogramEqul()
{
	printf("Log : Histogram Equalization ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	double sum[256];
	double totalSum = 0;
	for (int i = 0; i < 256; i++) {
		totalSum += hist[i];
		sum[i] = totalSum;
	}

	for (int i = 0; i < 256; i++) {
		sum[i] = sum[i]*256 / totalSum;
	}

	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			double R = tmp.val[2];
			double G = tmp.val[1];
			double B = tmp.val[0];

			double Y = round(sum[round((0.299*R + 0.587*G + 0.114*B))]);

			tmp.val[2] = Y;
			tmp.val[1] = Y;
			tmp.val[0] = Y;

			cvSet2D(cimg, i, j, tmp);
		}
	}
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// �Ӱ�ġ ���͸� (Thresholding)
void CImageProcessingSoftwareDlg::OnTheresholding()
{
	printf("Log : Thresholding ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	IplImage* grayImage = cvCloneImage(cimg);
	cimg = GetThresholding(grayImage);
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ����ð� ����(3*3)
void CImageProcessingSoftwareDlg::OnGuassian33()
{
	printf("Log : Guassian (3*3) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	const int sizeW = 3;
	const int sizeH = 3;
	double Mask[sizeH][sizeW] = {
		{ 1, 2, 1 },
		{ 2, 4, 2 },
		{ 1, 2, 1 }
	};

	double TotalSumOfMask = 0;
	for (int i = 0; i < sizeH; i++)
		for (int j = 0; j < sizeW; j++)
			TotalSumOfMask += (double)Mask[i][j];

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			double result = 0;
			CvScalar pixel;
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					int ni = i + y - sizeH / 2 < 0 ? 0 : i + y - sizeH / 2;
					int nj = j + x - sizeW / 2 < 0 ? 0 : j + x - sizeW / 2;

					CvScalar v = cvGet2D(grayImage, ni, nj);
					double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
					// setting filter
					result += Y * Mask[y][x];
				}
			}

			pixel.val[2] = result / TotalSumOfMask;
			pixel.val[1] = result / TotalSumOfMask;
			pixel.val[0] = result / TotalSumOfMask;
			cvSet2D(cimg, i, j, pixel);
		}
	}

	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ����ð� ����(7*7)
void CImageProcessingSoftwareDlg::OnGuassian77()
{
	printf("Log : Guassian (7*7) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	const int sizeW = 7;
	const int sizeH = 7;
// 	double Mask[sizeH][sizeW] = {
// 		{ 0, 0, 1, 2, 1, 0, 0 },
// 		{ 0, 3, 13, 22, 13, 3, 0 },
// 		{ 1, 13, 59, 97, 59, 13, 1 },
// 		{ 2, 22, 97, 159, 97, 22, 2 },
// 		{ 1, 13, 59, 97, 59, 13, 1 },
// 		{ 0, 3, 13, 22, 13, 3, 0 },
// 		{ 0, 0, 1, 2, 1, 0, 0 }
// 	};
	double Mask[sizeH][sizeW] = {
		{ 1, 1, 2, 2, 2, 1, 1 },
		{ 1, 3, 4, 5, 4, 3, 1 },
		{ 2, 4, 7, 8, 7, 4, 2 },
		{ 2, 5, 8,10, 8, 5, 2 },
		{ 2, 4, 7, 8, 7, 4, 2 },
		{ 1, 3, 4, 5, 4, 3, 1 },
		{ 1, 1, 2, 2, 2, 1, 1 },
	};
	double TotalSumOfMask = 0;
	for (int i = 0; i < sizeH; i++)
		for (int j = 0; j < sizeW; j++)
			TotalSumOfMask += (double)Mask[i][j];

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			double result = 0;
			CvScalar pixel;
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					int ni = i + y - sizeH / 2 < 0 ? 0 : i + y - sizeH / 2;
					int nj = j + x - sizeW / 2 < 0 ? 0 : j + x - sizeW / 2;

					CvScalar v = cvGet2D(grayImage, ni, nj);
					double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
					// setting filter
					result += Y * Mask[y][x];
				}
			}

			pixel.val[2] = result / TotalSumOfMask;
			pixel.val[1] = result / TotalSumOfMask;
			pixel.val[0] = result / TotalSumOfMask;
			cvSet2D(cimg, i, j, pixel);
		}
	}

	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ������ (7*7)
void CImageProcessingSoftwareDlg::OnSharpening77()
{
	printf("Log : ������ 7*7 ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	const int sizeW = 7;
	const int sizeH = 7;
// 	double Mask[sizeH][sizeW] = {
// 		{ -1, -1, -1, -1, -1, -1, -1 },
// 		{ -1, -1, -1, -1, -1, -1, -1 },
// 		{ -1, -1, -1, -1, -1, -1, -1 },
// 		{ -1, -1, -1, 49, -1, -1, -1 },
// 		{ -1, -1, -1, -1, -1, -1, -1 },
// 		{ -1, -1, -1, -1, -1, -1, -1 },
// 		{ -1, -1, -1, -1, -1, -1, -1 }
// 	};
	double Mask[sizeH][sizeW] = {
		{ -2, -3, -4, -6, -4, -3, -2 },
		{ -3, -5, -4, -3, -4, -5, -3 },
		{ -4, -4,  9, 20,  9, -4, -4 },
		{ -6, -3, 20, 72, 20, -3, -6 },
		{ -4, -4,  9, 20,  9, -4, -4 },
		{ -3, -5, -4, -3, -4, -5, -3 },
		{ -2, -3, -4, -6, -4, -3, -2 }
	};

	double TotalSumOfMask = 0;
	for (int i = 0; i < sizeH; i++)
		for (int j = 0; j < sizeW; j++)
			TotalSumOfMask += (double)Mask[i][j];

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			double result = 0;
			CvScalar pixel;
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					int ni = i + y - sizeH / 2 < 0 ? 0 : i + y - sizeH / 2;
					int nj = j + x - sizeW / 2 < 0 ? 0 : j + x - sizeW / 2;

					CvScalar v = cvGet2D(grayImage, ni, nj);
					double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
					// setting filter
					result += Y * Mask[y][x];
				}
			}

			pixel.val[2] = result / TotalSumOfMask;
			pixel.val[1] = result / TotalSumOfMask;
			pixel.val[0] = result / TotalSumOfMask;
			cvSet2D(cimg, i, j, pixel);
		}
	}

	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ��հ� ���͸� (7*7)
void CImageProcessingSoftwareDlg::OnAver77()
{
	printf("Log : ��հ� ���͸� (7*7) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	const int sizeW = 7;
	const int sizeH = 7;
	double Mask[sizeH][sizeW] = {
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 }
	};

	double TotalSumOfMask = 0;
	for (int i = 0; i < sizeH; i++)
		for (int j = 0; j < sizeW; j++)
			TotalSumOfMask += (double)Mask[i][j];

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			double result = 0;
			CvScalar pixel;
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					int ni = i + y - sizeH / 2 < 0 ? 0 : i + y - sizeH / 2;
					int nj = j + x - sizeW / 2 < 0 ? 0 : j + x - sizeW / 2;

					CvScalar v = cvGet2D(grayImage, ni, nj);
					double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
					// setting filter
					result += Y * Mask[y][x];
				}
			}

			pixel.val[2] = result / TotalSumOfMask;
			pixel.val[1] = result / TotalSumOfMask;
			pixel.val[0] = result / TotalSumOfMask;
			cvSet2D(cimg, i, j, pixel);
		}
	}

	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// �߰��� ���͸� (7*7)
void CImageProcessingSoftwareDlg::OnMedian77()
{
	printf("Log : �߰��� ���͸� (7*7) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	const int sizeW = 7;
	const int sizeH = 7;

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			double result = 0;
			double resArr[sizeH*sizeW] = { 0.0, };
			CvScalar pixel;
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					int ni = i + y - sizeH / 2 < 0 ? 0 : i + y - sizeH / 2;
					int nj = j + x - sizeW / 2 < 0 ? 0 : j + x - sizeW / 2;
					if (ni >= 0 && nj >= 0)
					{
						CvScalar v = cvGet2D(grayImage, ni, nj);
						double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
						resArr[y*sizeH+x] = Y;
					}
				}
			}

			for (int y = 0; y < sizeH; y++)
			{
				int idx = y;
				double median = resArr[y];
				for (int x = y+1; x < sizeW*sizeH; x++)
				{
					if (median > resArr[x])
					{
						median = resArr[x];
						idx = x;
					}
				}
				double temp = resArr[y];
				resArr[y] = resArr[idx];
				resArr[idx] = temp;
			}

			pixel.val[2] = resArr[sizeH - 1];
			pixel.val[1] = resArr[sizeH - 1];
			pixel.val[0] = resArr[sizeH - 1];
			cvSet2D(cimg, i, j, pixel);
		}
	}

	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ���� ���� (Binary)
void CImageProcessingSoftwareDlg::OnBinaryOpen()
{
	printf("Log : ���� ���� (Binary) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	IplImage* grayImage = cvCloneImage(cimg);
	// ���� ����ȭ
	IplImage* binImage = GetThresholding(grayImage);
	// ħ��
	binImage = GetGrayErosion(binImage);
	// ��â
	cimg = GetGrayDilation(binImage);
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ���� ���� (Binary)
void CImageProcessingSoftwareDlg::OnBinaryClose()
{
	printf("Log : ���� ���� (Binary) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	IplImage* grayImage = cvCloneImage(cimg);
	// ���� ����ȭ
	IplImage* binImage = GetThresholding(grayImage);
	// ��â
	binImage = GetGrayDilation(binImage);
	// ħ��
	cimg = GetGrayErosion(binImage);
	cvReleaseImage(&grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ���� ���� (Gray)
void CImageProcessingSoftwareDlg::OnGrayOpen()
{
	printf("Log : ���� ���� (Gray) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	IplImage* grayImage = cvCloneImage(cimg);
	// ħ��
	grayImage = GetGrayErosion(grayImage);
	// ��â
	cimg = GetGrayDilation(grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}
 
// ���� ���� (Gray)
void CImageProcessingSoftwareDlg::OnGrayClose()
{
	printf("Log : ���� ���� (Gray) ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	IplImage* grayImage = cvCloneImage(cimg);
	// ��â
	grayImage = GetGrayDilation(grayImage);
	// ħ��
	cimg = GetGrayErosion(grayImage);
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}


// �Һ� ����ũ
void CImageProcessingSoftwareDlg::OnSobelMask()
{
	printf("Log : Sobel Mask ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();

	const int sizeW = 3;
	const int sizeH = 3;
	double MaskX[sizeH][sizeW] = {
		{ -1,-2,-1 },
		{  0, 0, 0 },
		{  1, 2, 1 }
	};

	double MaskY[sizeH][sizeW] = {
		{ -1, 0, 1 },
		{ -2, 0, 2 },
		{ -1, 0, 1 }
	};

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		// x edge detect
		for (int j = 0; j < grayImage->width; j++)
		{
			double result = 0, resultX = 0, resultY = 0;
			CvScalar pixel;
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					int ni = i + y - sizeH / 2 < 0 ? 0 : i + y - sizeH / 2;
					int nj = j + x - sizeW / 2 < 0 ? 0 : j + x - sizeW / 2;

					CvScalar v = cvGet2D(grayImage, ni, nj);
					double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
					// setting filter
					resultX += Y * MaskX[y][x];
					resultY += Y * MaskY[y][x];
				}
			}
			result = sqrt(resultX * resultX + resultY * resultY);

			// set x * y
			pixel.val[2] = result;
			pixel.val[1] = result;
			pixel.val[0] = result;
			cvSet2D(cimg, i, j, pixel);
		}
	}

	cvReleaseImage(&grayImage);

	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ���ö�þ� ����ũ
void CImageProcessingSoftwareDlg::OnLaplacianMask()
{
	printf("Log : Laplacian Mask ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	tranRgbToGray();
	
	const int sizeW = 3;
	const int sizeH = 3;
	double Mask[sizeH][sizeW] = {
		{ 0,-1, 0 },
		{-1, 4,-1 },
		{ 0,-1, 0 }
	};

	double TotalSumOfMask = 0;
	for (int i = 0; i < sizeH; i++)
		for (int j = 0; j < sizeW; j++)
			TotalSumOfMask += (double)Mask[i][j];

	if (TotalSumOfMask == 0.0) TotalSumOfMask = 1.0;

	// Gray Scale ���� ���
	IplImage* grayImage = cvCloneImage(cimg);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			double result = 0;
			CvScalar pixel;
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					int ni = i + y - sizeH / 2 < 0 ? 0 : i + y - sizeH / 2;
					int nj = j + x - sizeW / 2 < 0 ? 0 : j + x - sizeW / 2;

					CvScalar v = cvGet2D(grayImage, ni, nj);
					double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
					// setting filter
					result += Y * Mask[y][x];
				}
			}

			pixel.val[2] = result / TotalSumOfMask;
			pixel.val[1] = result / TotalSumOfMask;
			pixel.val[0] = result / TotalSumOfMask;
			cvSet2D(cimg, i, j, pixel);
		}
	}

	cvReleaseImage(&grayImage);

	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ���� ����
void CImageProcessingSoftwareDlg::OnTool()
{
	MessageBox("���� ����");
}

// ���� ǥ����
void CImageProcessingSoftwareDlg::OnStatusBar()
{
	MessageBox("���� ǥ����");
}

// ������׷� ������
void CImageProcessingSoftwareDlg::OnHistogramWindow()
{
	printf("Log : Histogram Window ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	double    scale = 1;
	int       i, max = 0;
	
	// histogram�� ǥ���� �̹��� canvas ����
	IplImage* canvas;
	canvas = cvCreateImage(cvSize(256, 256), IPL_DEPTH_8U, 1);
	cvSet(canvas, CV_RGB(255, 255, 255), 0);

	// hist �ʱ�ȭ �� �� ����� �󵵼� ���
	initHist();

	// max : ���� ���� ���� ����� ����
	// ������ scale�� ���� �̹����� histogram�� ������� ���
	// max ���� ���Ƿ� ������Ű�� �ȴ�
	// ���⼭�� �ִ�� ���� ������ 256*60����� ���Ƿ� ����

	max = 256 * 50;		

	// ȭ���� �� ä���� ��������� �Ʒ��� for���� �̿��� hist �� �ִ� ���� ã�´�
	/*
	for (i = 0; i < 256; i++)
		max = hist[i] > max ? hist[i] : max;
	*/

	// canvas â�� �µ��� scale �� ����

	scale = max > canvas->height ? (double)canvas->height/max : 1.;

	// canvas�� ���� ���� �׸�
	// ���� canvas�� �ؿ������� �׷����ϱ� ������ �� ���� ����Ʈ(pt2)���� �׸�

	for (i = 0; i < 256; i++)
	{
		CvPoint pt1 = cvPoint(i, canvas->height - (int)(hist[i] * scale));
		CvPoint pt2 = cvPoint(i, canvas->height);
		cvLine(canvas, pt1, pt2, CV_RGB(0,0,0), 1, 8, 0);
	}

	// w_name�̶�� â�� canvas �̹����� ���
	
	cvShowImage("Histogram Window", canvas);

	cvReleaseImage(&canvas);

	printf("[SUCCESS]\n");
}

// ����
void CImageProcessingSoftwareDlg::OnHelp()
{
	MessageBox("����");
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

void CImageProcessingSoftwareDlg::initUndo(){

	if (pimg != NULL && pimg != cimg) {
		cvReleaseImage(&pimg);
		pimg = NULL;
	}
	pimg = cvCloneImage(cimg);
}

bool CImageProcessingSoftwareDlg::tranRgbToGray(){
	if (cimg == NULL) 
		return false;

	initUndo();

	for (int i = 0; i < cimg->height; i++)
	{
		for (int j = 0; j < cimg->width; j++)
		{
			CvScalar v = cvGet2D(cimg, i, j);
			double R = v.val[2];
			double G = v.val[1];
			double B = v.val[0];

			double Y = 0.299*R + 0.587*G + 0.114*B;

			v.val[2] = Y;
			v.val[1] = Y;
			v.val[0] = Y;
			cvSet2D(cimg, i, j, v);
		}
	}

	return true;
}

void CImageProcessingSoftwareDlg::initHist()
{
	for (int i = 0; i < 256; i++)
		hist[i] = 0;
	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			hist[(int)tmp.val[0]] ++;
		}
	}
}

IplImage* CImageProcessingSoftwareDlg::GetThresholding(IplImage* grayImage){

	int yArr[256] = { 0, };
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double R = v.val[2];
			double G = v.val[1];
			double B = v.val[0];

			int Y = round(0.299*R + 0.587*G + 0.114*B);
			yArr[Y]++;
		}
	}

	const int sizeW = grayImage->width;
	const int sizeH = grayImage->height;

	int i = grayImage->height / 2;
	int j = grayImage->width / 2;

	// ��հ� ���ϱ�
	double maxT = 0;
	double maxInter = 0;
	for (double T = 0; T < 256.0; T++)
	{
		double alpha = 0, alphaU = 0, alphaSum = 0;
		int alphaCount = 0;
		double beta = 0, betaU = 0, betaSum = 0;
		int betaCount = 0;
		for (int i = 0; i < T; i++)
		{
			alphaCount += yArr[i];
			alphaSum += yArr[i] * i;
		}
		for (int i = T; i < 256; i++)
		{
			betaCount += yArr[i];
			betaSum += yArr[i] * i;
		}

		// ���� ���ϱ�
		alpha = alphaCount / (double)(alphaCount + betaCount);
		beta = betaCount / (double)(alphaCount + betaCount);
		// ��� ���ϱ� = E(X)
		alphaU = alphaSum / alphaCount;
		betaU = betaSum / betaCount;

		double inter = alpha * beta * ((alphaU - betaU) * (alphaU - betaU));
		if (maxInter < inter)
		{
			maxT = T;
			maxInter = inter;
		}
	}

	IplImage* currImage = cvCloneImage(grayImage);
	for (int i = 0; i < grayImage->height; i += sizeH)
	{
		for (int j = 0; j < grayImage->width; j += sizeW)
		{
			for (int y = 0; y < sizeH && y + i < grayImage->height; y++)
			{
				for (int x = 0; x < sizeW && x + j < grayImage->width; x++)
				{
					CvScalar v = cvGet2D(grayImage, i + y, j + x);
					double Y = 0.299f*v.val[2] + 0.587f*v.val[1] + 0.114f*v.val[0];
					Y = 0xFF * (Y > maxT);

					v.val[2] = v.val[1] = v.val[0] = Y;
					cvSet2D(currImage, i + y, j + x, v);
				}
			}
		}
	}

	return currImage;
}

IplImage* CImageProcessingSoftwareDlg::GetBinErosion(IplImage* grayImage){

	int Mask[3][3] = {
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	IplImage* erosionImage = cvCloneImage(grayImage);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double Y = v.val[2];

			for (int y = -1; y <= 1; y++)
			{
				for (int x = -1; x <= 1; x++)
				{
					int nx = j + x;
					int ny = i + y;
					if (nx < 0 || nx >= grayImage->width) continue;
					if (ny < 0 || ny >= grayImage->height) continue;
					if (Mask[1 + y][1 + x] == 0) continue;

					CvScalar vv = cvGet2D(grayImage, ny, nx);
					if (vv.val[2] == 0)
					{
						Y = 0; break;
					}
				}
				if (Y == 0) break;
			}

			v.val[2] = v.val[1] = v.val[0] = Y;
			cvSet2D(erosionImage, i, j, v);
		}
	}
	return erosionImage;
}

IplImage* CImageProcessingSoftwareDlg::GetBinDilation(IplImage* grayImage){

	int Mask[3][3] = {
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	IplImage* dilationImage = cvCloneImage(grayImage);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double Y = v.val[2];

			for (int y = -1; y <= 1; y++)
			{
				for (int x = -1; x <= 1; x++)
				{
					int nx = j + x;
					int ny = i + y;
					if (nx < 0 || nx >= grayImage->width) continue;
					if (ny < 0 || ny >= grayImage->height) continue;
					if (Mask[1 + y][1 + x] == 0) continue;

					CvScalar vv = cvGet2D(grayImage, ny, nx);
					if (vv.val[2] == 0xFF)
					{
						Y = 0xFF; break;
					}
				}
				if (Y == 0xFF) break;
			}

			v.val[2] = v.val[1] = v.val[0] = Y;
			cvSet2D(dilationImage, i, j, v);
		}
	}
	return dilationImage;
}

IplImage* CImageProcessingSoftwareDlg::GetGrayErosion(IplImage* grayImage){

	int Mask[3][3] = {
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	IplImage* erosionImage = cvCloneImage(grayImage);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double Y = v.val[2];
			double minY = Y;

			for (int y = -1; y <= 1; y++)
			{
				for (int x = -1; x <= 1; x++)
				{
					int nx = j + x;
					int ny = i + y;
					if (nx < 0 || nx >= grayImage->width) continue;
					if (ny < 0 || ny >= grayImage->height) continue;
					if (Mask[1 + y][1 + x] == 0) continue;

					CvScalar vv = cvGet2D(grayImage, ny, nx);
					if (vv.val[2] < minY)
					{
						minY = vv.val[2];
					}
				}
			}

			v.val[2] = v.val[1] = v.val[0] = minY;
			cvSet2D(erosionImage, i, j, v);
		}
	}
	return erosionImage;
}

IplImage* CImageProcessingSoftwareDlg::GetGrayDilation(IplImage* grayImage){

	int Mask[3][3] = {
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	IplImage* dilationImage = cvCloneImage(grayImage);
	for (int i = 0; i < grayImage->height; i++)
	{
		for (int j = 0; j < grayImage->width; j++)
		{
			CvScalar v = cvGet2D(grayImage, i, j);
			double Y = v.val[2];
			double maxY = Y;

			for (int y = -1; y <= 1; y++)
			{
				for (int x = -1; x <= 1; x++)
				{
					int nx = j + x;
					int ny = i + y;
					if (nx < 0 || nx >= grayImage->width) continue;
					if (ny < 0 || ny >= grayImage->height) continue;
					if (Mask[1 + y][1 + x] == 0) continue;

					CvScalar vv = cvGet2D(grayImage, ny, nx);
					if (vv.val[2] > maxY)
					{
						maxY = vv.val[2];
					}
				}
			}

			v.val[2] = v.val[1] = v.val[0] = maxY;
			cvSet2D(dilationImage, i, j, v);
		}
	}
	return dilationImage;
}