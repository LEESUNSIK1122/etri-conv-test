#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
/*
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




    // if success
    return 0;

    // if fail - in the case of wrong parameters...
    // return -1
}
*/
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
   // your_conv(src,dst,kernel,1,0);
    // ---------------------------

dst = cv::imread( argv[1] );
int i,j,k,s;
int sum[3]={0};

for(i = 0; i<dst.rows-2; i= i+1)
{
	for(j = 0; j<dst.cols-2; j= j+1)
	{
		sum[0]=0;
		sum[1]=0;
		sum[2]=0;
		for(k=0; k<3; k++)
		{
			for(s = 0; s<3; s++)
			{
			sum[0] += src.at<cv::Vec3b>(i+k,j+s)[0] * kernel.at<cv::Vec3b>(k,s)[0];
			sum[1] += src.at<cv::Vec3b>(i+k,j+s)[1] * kernel.at<cv::Vec3b>(k,s)[1];
			sum[2] += src.at<cv::Vec3b>(i+k,j+s)[2] * kernel.at<cv::Vec3b>(k,s)[2];
			}		
		}		
		dst.at<cv::Vec3b>(i,j)[0] =sum[0];
		dst.at<cv::Vec3b>(i,j)[1] =sum[1];
		dst.at<cv::Vec3b>(i,j)[2] =sum[2];
	}
}

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", dst );

    cv::waitKey(0);
    return 0;
}
