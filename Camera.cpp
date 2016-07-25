#include "Camera.h"
#include <iostream>
#include <opencv2/opencv.hpp>
Camera::Camera()
{

	//std::cout << "camera olusturuldu..." << std::endl;
}


void Camera::loadCameraData() 
{
	cv::VideoCapture vid(1);
	if (!vid.isOpened())
	{
		std::cout << "video yuklenemedi.." << std::endl;
	}
	cv::namedWindow("javakaian", CV_WINDOW_AUTOSIZE);
	int row = vid.get(CV_CAP_PROP_FRAME_HEIGHT);
	int col = vid.get(CV_CAP_PROP_FRAME_WIDTH);

	//std::cout << "Kemara verisi cizdiriliyor..." << std::endl;



	cv::Size boyut(col, row);
	while (true)
	{
		cv::Mat frame;
		bool kontrol = vid.read(frame);
		if (!kontrol)
		{
			std::cout << "goruntu okunamadi" << std::endl;
			break;
		}
        cv::
		imshow("javakaian", frame);
        imwrite("/root/Documents/bitirme/frame.jpg",frame);
		cv::waitKey(50);


	}
        
   /* using namespace cv;
    VideoCapture cap(0); //capture the video from web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         std::cout << "Cannot open the web cam" <<std::endl;
         
    }

        namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

          int iLowH = 0;
         int iHighH = 179;

          int iLowS = 0; 
         int iHighS = 255;

          int iLowV = 0;
         int iHighV = 255;

          //Create trackbars in "Control" window
         cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
         cvCreateTrackbar("HighH", "Control", &iHighH, 179);

          cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
         cvCreateTrackbar("HighS", "Control", &iHighS, 255);

          cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
         cvCreateTrackbar("HighV", "Control", &iHighV, 255);

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             std::cout << "Cannot read a frame from video stream" <<std::endl;
             break;
        }

    Mat imgHSV;

       cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
     
      Mat imgThresholded;

       inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
          
      //morphological opening (remove small objects from the foreground)
      erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
      dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

       //morphological closing (fill small holes in the foreground)
      dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
      erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

       imshow("Thresholded Image", imgThresholded); //show the thresholded image
      imshow("Original", imgOriginal); //show the original image

            if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
           {
                std::cout << "esc key is pressed by user" <<std::endl;
                break; 
           }
    }

    */
    


}



Camera::~Camera()
{
	
	std::cout << "Camera yok edildi..." << std::endl;
}
