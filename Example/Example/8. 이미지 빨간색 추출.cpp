#include <opencv2\opencv.hpp>

void reflect(IplImage *image, int value);
void fineRedImage(IplImage *image);


//������ ã��
int main(){

	// IplImage�� �̹��� ������ ������ ���� ����ü
	// Ư�� ������ �д� �Լ�, �⺻ �Ӽ��� ������ ���ڴ�.
	IplImage *img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);

	while (1){
		cvShowImage("test", img);
		char c = cvWaitKey(0);
		if (c == 'u')
			reflect(img, -1);
		else if (c == 'l')
			reflect(img, 1);
		else if (c == 'r')
			fineRedImage(img);
		else if (c == 0x1B)
			break;
	}

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