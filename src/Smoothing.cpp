/**
 * file Smoothing.cpp
 * brief Sample code for simple filters
 * author OpenCV team
 */
#include <iostream>
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"

using namespace std;
using namespace cv;

/// Global Variables
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

Mat src; Mat dst;
char window_name[] = "Smoothing Demo";

/// Function headers
int display_caption( const char* caption );
int display_dst( int delay );

int main( void )  {

  namedWindow( window_name, WINDOW_AUTOSIZE );

  /// Load the source image
  src = imread( "../images/fig08-06.jpg", 1 );

  if( display_caption( "Original Image" ) != 0 ) { return 0; }

  dst = src.clone();
  if( display_dst( DELAY_CAPTION ) != 0 ) { return 0; }

  /// Applying Median blur
  if( display_caption( "Median Blur with 3" ) != 0 ) { return 0; }

  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
      { medianBlur ( src, dst, 3 );
        if( display_dst( DELAY_BLUR ) != 0 ) { return 0; } }

  if( display_caption( "Median Blur with 5" ) != 0 ) { return 0; }

  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
      { medianBlur ( src, dst, 5 );
        if( display_dst( DELAY_BLUR ) != 0 ) { return 0; } }

  return 0;
}

/**
 * @function display_caption
 */
int display_caption( const char* caption )
{
  dst = Mat::zeros( src.size(), src.type() );
  putText( dst, caption,
           Point( src.cols/4, src.rows/2),
           FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

  imshow( window_name, dst );
  int c = waitKey( DELAY_CAPTION );
  if( c >= 0 ) { return -1; }
  return 0;
}

/**
 * @function display_dst
 */
int display_dst( int delay )
{
  imshow( window_name, dst );
  int c = waitKey ( delay );
  if( c >= 0 ) { return -1; }
  return 0;
}
