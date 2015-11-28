#include <opencv2\opencv.hpp>

int main()
{

	CvCapture *capture = cvCaptureFromCAM(0);
	IplImage *img;
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		// 현재 동영상에서 한장을 가지고 오는 것
		img = cvQueryFrame(capture);
		cvShowImage("test", img);
		// 30 m/s마다 키를 대기
		char c = cvWaitKey(30);
		// esx를 누를 경우 종료
		if (c == 0x1B)
			break;
	}

	cvReleaseCapture(&capture);

	return 0;


}