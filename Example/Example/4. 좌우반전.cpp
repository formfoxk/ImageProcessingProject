#include <opencv2\opencv.hpp>

int main()
{

	// IplImage�� �̹��� ������ ������ ���� ����ü
	// Ư�� ������ �д� �Լ�, �⺻ �Ӽ��� ������ ���ڴ�.
	IplImage *img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);


	cvShowImage("test", img);

	char c = cvWaitKey(0);
	// Ű�� ���� ������ ���, ������ ������. 
	if (c == 0x1B)
		// parameter > 0 �¿� ����
		// parameter <= 0 ���� ����
		// esc Ű�� ������ �� �߻�
		cvFlip(img, img, 1);

	cvShowImage("test", img);

	cvWaitKey(0);
	cvReleaseImage(&img);
	// ����ü �޸� �Ҵ� ����

	return 0;
}