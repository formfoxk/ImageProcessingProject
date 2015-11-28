#include <opencv2\opencv.hpp>

int main()
{
	IplImage *image = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);

	unsigned char *data = (unsigned char *)image->imageData;
	printf("# of channels \t= %d \n", image->nChannels);
	printf("origin \t\t= %d \n", image->origin);
	printf("width \t\t= %d \n", image->width);
	printf("height \t\t= %d \n", image->height);
	printf("widthStep \t= %d\t bytes (width x channels) \n", image->widthStep);
	printf("depth \t\t= %d\t bits \n", image->depth);
	printf("imageSize \t= %d bytes (width x height x channels) \n", image->imageSize);

	for (int i = 0; i<10; i++)
		printf("imageData \t= %d \n", data[i]);

	cvReleaseImage(&image);


	return 0;
}