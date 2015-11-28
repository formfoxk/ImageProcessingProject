#include <opencv2\opencv.hpp>

int main()
{
	const char *path = "D:/Hobby/Music/okdoky.avi";
	CvCapture *capture = cvCaptureFromAVI(path);

	IplImage *img;
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		img = cvQueryFrame(capture);
		cvShowImage("test", img);
		char c = cvWaitKey(30);
		if (c == 0x1B)
			break;
	}

	cvReleaseCapture(&capture);

	return 0;
}