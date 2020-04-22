#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, const char * argv[]) {

Mat img = imread("ballon.jpg", IMREAD_GRAYSCALE);
if (img.empty())
    return -1;

int row = img.rows;
int col = img.cols;


double *data_gray = new double[row * col];

uchar *ptr;
int idx = 0;
for (int i = 0; i < row; i++)
{
    ptr = img.ptr<uchar>(i);
    for (int j = 0; j < col; j++){
        data_gray[idx] = ptr[j] / 255.;
        printf("%lf %d \n", data_gray[idx], idx);
        idx++;
    }
}

printf("%d, %d\n", row, col);
Mat output(row, col, CV_64F, data_gray);

namedWindow( "Example1", WINDOW_AUTOSIZE );
imshow( "Example1", output );
waitKey( 0 );
destroyWindow( "Example1" );

delete[] data_gray;

return 0;
}