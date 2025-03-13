/****    Wihtout multithread_FPS : 10.9    ****/
//#include <opencv2\objdetect.hpp>
//#include <opencv2\highgui.hpp>
//#include <opencv2\imgproc.hpp>
//#include <iostream>
//#include <time.h>
//
//using cv::CascadeClassifier;
//using cv::VideoCapture;
//using cv::Scalar;
//using cv::Rect;
//using cv::Mat;
//using cv::waitKey;
//using cv::CAP_PROP_FPS;
//
//int main() {
//	VideoCapture cap(0);
//	if (!cap.isOpened()) {
//		system("cla");
//		std::cerr << "Can't open camera!" << std::endl;
//		return -1;
//	}
//
//	Mat frame;
//	
//	CascadeClassifier faceCascade;
//	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
//	if (faceCascade.empty()) {
//		system("cls");
//		std::cout << "Can't load haarcascade.xml file!" << std::endl;
//		return -1;
//	}
//
//	int numFrames = 120;
//	time_t start, end;
//	time(&start);
//
//	for (int i = 0; i < numFrames; i++) {
//		cap >> frame;
//		if (frame.empty()) {
//			system("cls");
//			std::cout << "Can't read a frame from video stream!" << std::endl;
//			return -1;
//		}
//
//		std::vector<Rect> faces;
//		faceCascade.detectMultiScale(frame, faces, 1.1, 10);
//
//		for (int i = 0; i < faces.size(); i++) {
//			rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
//		}
//
//		imshow("Frame", frame);
//		if (waitKey(1) == 'q') {
//			system("cls");
//			std::cout << "Goodbye" << std::endl;
//			break;
//		}
//	}
//
//	time(&end);
//	double seconds = difftime(end, start);
//	double fps = numFrames / seconds;
//	system("cls");
//	std:: cout << "Estimated frames per second : " << fps << "\n\n";
//
//	cap.release();
//	cv::destroyAllWindows();
//
//	return 0;
//}





/****    Simple multithread_FPS : 10.9    ****/
//#include <opencv2\objdetect.hpp>
//#include <opencv2\highgui.hpp>
//#include <opencv2\imgproc.hpp>
//#include <iostream>
//#include <thread>
//#include <time.h>
//
//using cv::CascadeClassifier;
//using cv::VideoCapture;
//using cv::Scalar;
//using cv::Rect;
//using cv::Mat;
//using cv::waitKey;
//using cv::CAP_PROP_FPS;
//
//void faceDetect(Mat& frame, CascadeClassifier& faceCascade) {
//	std::vector<Rect> faces;
//	faceCascade.detectMultiScale(frame, faces, 1.1, 10);
//
//	for (int i = 0; i < faces.size(); i++) {
//		rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
//	}
//}
//
//int main() {
//	VideoCapture cap(0);
//	if (!cap.isOpened()) {
//		system("cla");
//		std::cerr << "Can't open camera!" << std::endl;
//		return -1;
//	}
//
//	Mat frame;
//	std::thread tds;
//
//	CascadeClassifier faceCascade;
//	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
//	if (faceCascade.empty()) {
//		system("cls");
//		std::cout << "Can't load haarcascade.xml file!" << std::endl;
//		return -1;
//	}
//
//	int numFrames = 120;
//	time_t start, end;
//	time(&start);
//
//	for (int i = 0; i < numFrames; i++) {
//		if (!cap.read(frame)) {
//			system("cls");
//			std::cout << "Can't read a frame from video stream!" << std::endl;
//			return -1;
//		}
//
//		tds = std::thread(&faceDetect, std::ref(frame), std::ref(faceCascade));
//		tds.join();
//
//		imshow("Frame", frame);
//		if (waitKey(1) == 'q') {
//			system("cls");
//			std::cout << "Goodbye" << std::endl;
//			break;
//		}
//	}
//	time(&end);
//	double seconds = difftime(end, start);
//	double fps = numFrames / seconds;
//	system("cls");
//	std::cout << "Estimated frames per second : " << fps << "\n\n";
//
//	cap.release();
//	cv::destroyAllWindows();
//
//	return 0;
//}





#include <opencv2\objdetect.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <time.h>

int main() {
	cv::VideoCapture cap("Resources/avc_Test_video.mp4");
	if (!cap.isOpened()) {
		system("cla");
		std::cerr << "Can't open video!" << std::endl;
		return -1;
	}

	cv::Mat frame;
	
	cv::CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) {
		system("cls");
		std::cout << "Can't load haarcascade.xml file!" << std::endl;
		return -1;
	}

	while (true) {
		cap >> frame;
		if (frame.empty()) {
			system("cls");
			std::cout << "Can't read a frame from video stream!" << std::endl;
			return -1;
		}

		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(frame, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(frame, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 255), 2);
		}

		imshow("Frame", frame);
		if (cv::waitKey(1) == 'q') {
			system("cls");
			std::cout << "Goodbye" << std::endl;
			break;
		}
	}

	cap.release();
	cv::destroyAllWindows();

	return 0;
}