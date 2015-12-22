
// ImageProcessingSoftwareDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ImageProcessingSoftware.h"
#include "ImageProcessingSoftwareDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
	MessageBox("������");
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
	MessageBox("Ȯ�� with NN");
}

// Ȯ�� with ��������
void CImageProcessingSoftwareDlg::OnEnlargeLi()
{
	MessageBox("Ȯ�� with ��������");
}

// ��� with NN
void CImageProcessingSoftwareDlg::OnReduceNn()
{
	MessageBox("��� with NN");
}

// ��� with ��������
void CImageProcessingSoftwareDlg::OnReduceLi()
{
	MessageBox("��� with ��������");
}

// ȸ��
void CImageProcessingSoftwareDlg::OnRotation()
{
	MessageBox("ȸ��");
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
	if(!isGray(cimg)) tranRgbToGray();

	int i, j, t, value;
	value = dlg.m_value;

	for (i = 0; i < cimg->height; i++) {
		for (j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			
			t = (int)tmp.val[0];
			t += value;
			if (t > 255) t = 255;
			else if (t < 0) t = 0;
			tmp.val[0] = t;
			
			cvSet2D(cimg, i, j, tmp);
		}
	}
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
	if(!isGray(cimg)) tranRgbToGray();

	int i, j, t, value;
	value = dlg.m_value;

	for (i = 0; i < cimg->height; i++) {
		for (j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			
			t = (int)tmp.val[0];
			t -= value;
			if (t > 255) t = 255;
			else if (t < 0) t = 0;
			tmp.val[0] = t;
			
			cvSet2D(cimg, i, j, tmp);
		}
	}
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
	if(!isGray(cimg)) tranRgbToGray();

	int i, j, t;
	double rate = (double)dlg.m_value/100;

	for (i = 0; i < cimg->height; i++) {
		for (j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			
			t = (int)tmp.val[0];
			t = t + (int)(t * rate);
			if (t > 255) t = 255;
			else if (t < 0) t = 0;
			tmp.val[0] = t;
			
			cvSet2D(cimg, i, j, tmp);
		}
	}
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
	if(!isGray(cimg)) tranRgbToGray();

	int i, j, t;
	double rate = (double)dlg.m_value/100;

	for (i = 0; i < cimg->height; i++) {
		for (j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			
			t = (int)tmp.val[0];
			t = t - (int)(t * rate);
			if (t > 255) t = 255;
			else if (t < 0) t = 0;
			tmp.val[0] = t;
			
			cvSet2D(cimg, i, j, tmp);
		}
	}
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
	if(!isGray(cimg)) tranRgbToGray();

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
	if(!isGray(cimg)) tranRgbToGray();
	
	const int ms = 2;
	int dithMx[ms][ms] = { {0,128},{192,64} };

	for (int i = 0; i < cimg->height; i+=ms) {
		for (int j = 0; j < cimg->width; j+=ms) {
			for (int a = 0; a < ms && a+i < cimg->height; a++) {
				for (int b = 0; b < ms && b+j < cimg->width; b++) {
					CvScalar tmp = cvGet2D(cimg, i+a, j+b);
					if ((int)tmp.val[0] > dithMx[a][b])
						tmp.val[0] = 255;
					else
						tmp.val[0] = 0;
					cvSet2D(cimg, i+a, j+b, tmp);
				}
			}
		}
	}
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
	if(!isGray(cimg)) tranRgbToGray();
	
	const int ms = 4;
	int dithMx[ms][ms] = { { 0,128,32,160 },{ 192,64,224,96 }
	,{48,176,16,144},{240,112,208,80 }};

	for (int i = 0; i < cimg->height; i += ms) {
		for (int j = 0; j < cimg->width; j += ms) {
			for (int a = 0; a < ms && i+a < cimg->height; a++) {
				for (int b = 0; b < ms && j+b < cimg->width; b++) {
					CvScalar tmp = cvGet2D(cimg, i + a, j + b);
					if ((int)tmp.val[0] > dithMx[a][b])
						tmp.val[0] = 255;
					else
						tmp.val[0] = 0;
					cvSet2D(cimg, i + a, j + b, tmp);
				}
			}
		}
	}
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
	if(!isGray(cimg)) tranRgbToGray();
	
	for (int i = 0; i < cimg->height; i++) {
		for (int j = 0; j < cimg->width; j++) {
			CvScalar tmp = cvGet2D(cimg, i, j);
			tmp.val[0] = 255 - tmp.val[0];
			cvSet2D(cimg, i, j, tmp);
		}
	}
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ������׷� ��Ʈ��Ī (�ڵ�)
void CImageProcessingSoftwareDlg::OnHistogramAuto()
{
	printf("Log : Image  ");
	if (cimg == NULL){
		printf("[FAILURE]\n");
		return;
	}

	initUndo();
	if(!isGray(cimg)) tranRgbToGray();
	
	printf("[SUCCESS]\n");

	DisplayIplImage(cimg, m_pDC, dsprect);
}

// ������׷� ��Ʈ��Ī (����� �Է�)
void CImageProcessingSoftwareDlg::OnHistogramUser()
{
	MessageBox("������׷� ��Ʈ��Ī (����� �Է�)");
}

// ������׷� ����ȭ (Equalization)
void CImageProcessingSoftwareDlg::OnHistogramEqul()
{
	MessageBox("������׷� ����ȭ (Equalization)");
}

// �Ӱ�ġ ���͸� (Thresholding)
void CImageProcessingSoftwareDlg::OnTheresholding()
{
	MessageBox("�Ӱ�ġ ���͸� (Thresholding)");
}

// ����ð� ����(3*3)
void CImageProcessingSoftwareDlg::OnGuassian33()
{
	MessageBox("����ð� ����(3*3)");
}

// ����ð� ����(7*7)
void CImageProcessingSoftwareDlg::OnGuassian77()
{
	MessageBox("����ð� ����(7*7)");
}

// ������ (7*7)
void CImageProcessingSoftwareDlg::OnSharpening77()
{
	MessageBox("������ (7*7)");
}

// ��հ� ���͸� (7*7)
void CImageProcessingSoftwareDlg::OnAver77()
{
	MessageBox("��հ� ���͸� (7*7)");
}

// �߰��� ���͸� (7*7)
void CImageProcessingSoftwareDlg::OnMedian77()
{
	MessageBox("�߰��� ���͸� (7*7)");
}

// ���� ���� (Binary)
void CImageProcessingSoftwareDlg::OnBinaryOpen()
{
	MessageBox("���� ���� (Binary)");
}

// ���� ���� (Binary)
void CImageProcessingSoftwareDlg::OnBinaryClose()
{
	MessageBox("���� ���� (Binary)");
}

// ���� ���� (Gray)
void CImageProcessingSoftwareDlg::OnGrayOpen()
{
	MessageBox("���� ���� (Gray)");
}
 
// ���� ���� (Gray)
void CImageProcessingSoftwareDlg::OnGrayClose()
{
	MessageBox("���� ���� (Gray)");
}


// �Һ� ����ũ
void CImageProcessingSoftwareDlg::OnSobelMask()
{
	MessageBox("�Һ� ����ũ");
}

// ���ö�þ� ����ũ
void CImageProcessingSoftwareDlg::OnLaplacianMask()
{
	MessageBox("���ö�þ� ����ũ");
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
	MessageBox("������׷� ������");
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

bool CImageProcessingSoftwareDlg::isGray(IplImage *image){
	if(image->nChannels == 1) return true;
	return false;
}

bool CImageProcessingSoftwareDlg::tranRgbToGray(){
	if (cimg == NULL || isGray(cimg)) 
		return false;

	initUndo();
	IplImage* gray  = cvCreateImage(cvGetSize(cimg), IPL_DEPTH_8U, 1);
    cvCvtColor(cimg, gray, CV_BGR2GRAY);
	cvReleaseImage(&cimg);
	cimg = gray;
	return true;

}