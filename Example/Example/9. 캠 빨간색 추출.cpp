#include <opencv2\opencv.hpp>

void fineRedImage(IplImage *image);

int main()
{
	CvCapture *capture = cvCaptureFromCAM(0);
	IplImage *img;
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		// ���� �����󿡼� ������ ������ ���� ��
		img = cvQueryFrame(capture);
		if (img == NULL) continue;
		fineRedImage(img);
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


void fineRedImage(IplImage *image){

	int wth = image->width;
	int hit = image->height;

	CvScalar value;

	for (int j = 0; j < hit; j++){
		for (int i = 0; i < wth; i++){
			value = cvGet2D(image, j, i);
			if (value.val[0] < 128
				&& value.val[1] < 128
				&& value.val[2] > 128
				)
				cvSet2D(image, j, i, cvScalar(0, 0, 255));
			else
				cvSet2D(image, j, i, cvScalar(0, 0, 0));
		}

	}

}