#include <opencv2\opencv.hpp>

void reflect(IplImage *image, int value);

// cvflip 구현
int main(){

	// IplImage는 이미지 정보를 가지고 오는 구조체
	// 특정 파일을 읽는 함수, 기본 속성을 가지고 오겠다.
	IplImage *img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	// 창을 만든다는거, 창 이름과, 창의 속성

	reflect(img, -1);

	cvShowImage("test", img);

	cvWaitKey(0);
	// 키가 들어올 때까지 대기, 없으면 꺼진다. 

	cvReleaseImage(&img);
	// 구조체 메모리 할당 헤제

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