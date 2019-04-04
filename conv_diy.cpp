#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int your_conv( cv::Mat src,
               cv::Mat dst,
               cv::Mat kernel,
               int stride,
               int padding
               )
{
    int src_height = src.rows;
    int src_width = src.cols;

    int kernel_height = kernel.rows;
    int kernel_width = kernel.cols;

    int dst_height;
    int dst_width;

    // src.ptr<unsigned char>(i)[ calculate INDEX ]

    // MAKE YOUR OWN CONVOLUTION PROCESS
int i,j;
int sum =0;
dst_height = src_height;
dst_width = src_width;


dst = cv::Mat_<float>(1000, 1000, 3);

for(i = 0; i<1000; i= i+1)
{
	for(j = 0; j<1000; j= j+1)
	{
     //   std::cout << src.at<cv::Vec3b>(0,0)[0] << std::endl;
     //   std::cout << dst.at<cv::vec3b>(i,j)[0] << std::endl;
	//	dst.at<cv::Vec3b>(i,j)[0] = 100;
	//	dst.at<cv::Vec3b>(i,j)[1] = 100;
	//	dst.at<cv::Vec3b>(i,j)[2] = 100;
	}
}


    // if success
    return 0;

    // if fail - in the case of wrong parameters...
    // return -1
}

int main ( int argc, char** argv )
{
    if (argc < 2) {
        std::cout << "no filename given." << std::endl;
        std::cout << "usage: " << argv[0] << " image" << std::endl;
        return -1;
    }

    cv::Mat src, kernel, dst;

    // Load an image
    src = cv::imread( argv[1] );
    if( !src.data )  { return -1; }

    // Make filter
    kernel = (cv::Mat_<float>(3, 3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1,
					   0,  0,  0,  0, 0,  0,  0,  0,  0,
					   0,  0,  0,  0, 0,  0,  0,  0,  0);


    // Run 2D filter
    //cv::filter2D(src, dst, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    // ---------------------------
    your_conv(src,dst,kernel,1,0);
    // ---------------------------

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", kernel );

    cv::waitKey(0);
    return 0;
}
