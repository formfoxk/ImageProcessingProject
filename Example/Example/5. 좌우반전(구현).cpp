#include <opencv2\opencv.hpp>

void reflect(IplImage *image, int value);

// cvflip ����
int main(){

	// IplImage�� �̹��� ������ ������ ���� ����ü
	// Ư�� ������ �д� �Լ�, �⺻ �Ӽ��� ������ ���ڴ�.
	IplImage *img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	// â�� ����ٴ°�, â �̸���, â�� �Ӽ�

	reflect(img, -1);

	cvShowImage("test", img);

	cvWaitKey(0);
	// Ű�� ���� ������ ���, ������ ������. 

	cvReleaseImage(&img);
	// ����ü �޸� �Ҵ� ����

	return 0;
}

void reflect(IplImage *image, int value){
	int wth = image->width; 
	int hit = image->height;

	CvScalar temp;

	if (value > 0){

		for (int j = 0; j < hit; j++)
			for (int i = 0; i < wth / 2; i++){

				temp = cvGet2D(image, j, i);
				cvSet2D(image, j, i, cvGet2D(image, j, wth - i - 1));
				cvSet2D(image, j, wth - 1 - i, temp);
			}
	}
	else{
		for (int j = 0; j < hit / 2; j++)
			for (int i = 0; i < wth; i++){

				temp = cvGet2D(image, j, i);
				cvSet2D(image, j, i, cvGet2D(image, hit-j-1, i));
				cvSet2D(image, hit - j - 1, i, temp);
			}
	}

}