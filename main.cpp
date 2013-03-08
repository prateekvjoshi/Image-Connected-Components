// Finds connected components in the image and colors each region with a different color

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int threshval = 100;
int maxval = 255;
string outputImageFile = "outputImage.jpg";

void findConnectedComponents(Mat inputImage)
{
    Mat grayscale;
    cvtColor(inputImage, grayscale, CV_RGB2GRAY);
    
    Mat bw = Mat::zeros(grayscale.size(), CV_8UC1);
    
    threshold(grayscale, bw, threshval, maxval, THRESH_BINARY);
    
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    
    findContours( bw, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
    
    Mat dst = Mat::zeros(inputImage.size(), CV_8UC3);
    
    if( !contours.empty() && !hierarchy.empty() )
    {
        // iterate through all the top-level contours,
        // draw each connected component with its own random color
        int idx = 0;
        for( ; idx >= 0; idx = hierarchy[idx][0] )
        {
            Scalar color( (rand()&255), (rand()&255), (rand()&255) );
            drawContours( dst, contours, idx, color, CV_FILLED, 8, hierarchy );
        }
    }
    
    imshow( "Connected Components", dst );
    
    imwrite(outputImageFile, dst);
}

int main( int argc, const char** argv )
{
    Mat inputImage = imread(argv[1], 1);
    
    if(inputImage.empty())
    {
        cout << "Could not read input image file\n" << endl;
        return -1;
    }
    
    namedWindow( "Image", 1 );
    imshow( "Image", inputImage );
    
    namedWindow( "Connected Components", 1 );
    findConnectedComponents(inputImage);
    
    waitKey(0);
    return 0;
}



