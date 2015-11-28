#include <opencv2\opencv.hpp>

int main()
{

	CvCapture *capture = cvCaptureFromCAM(0);
	IplImage *img;
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		// ���� �����󿡼� ������ ������ ���� ��
		img = cvQueryFrame(capture);
		cvShowImage("test", img);
		// 30 m/s���� Ű�� ���
		char c = cvWaitKey(30);
		// esx�� ���� ��� ����
		if (c == 0x1B)
			break;
	}

	cvReleaseCapture(&capture);

	return 0;


}