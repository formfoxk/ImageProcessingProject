#include <opencv2\opencv.hpp>

int main(){

	// IplImage�� �̹��� ������ ������ ���� ����ü
	// Ư�� ������ �д� �Լ�, �⺻ �Ӽ��� ������ ���ڴ�.
	IplImage *img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	

	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	// â�� ����ٴ°�, â �̸���, â�� �Ӽ�

	cvShowImage("test", img);

	cvWaitKey(0);
	// Ű�� ���� ������ ���, ������ ������. 

	cvReleaseImage(&img);
	// ����ü �޸� �Ҵ� ����

	return 0;
}