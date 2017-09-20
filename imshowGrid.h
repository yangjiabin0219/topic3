#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
//参数说明：
//imgList - 包含需要显示的多幅图像的vector
//row - 分几行显示
//col - 分几列显示
//windowSize - 用于显示所有多幅图像的window的尺寸
//windowName - 用于显示所有多幅图像的window的name
using namespace cv;
using namespace std;

void imshowGrid(std::vector<cv::Mat> imgList, int row, int col, cv::Size windowSize, std::string windowName)
{
	int iNum = imgList.size();//get vector images size
	Mat mDstimg(windowSize, CV_8UC3, Scalar(0,0,0));//define a new image mat
	
	if (iNum > (row*col))
	{
		cout << "input a bigger col or row" << endl;
		return;
	}
	if (iNum == 0)
	{
		cout << "please input images" << endl;
		return;
	}

	int iCol, iRow,iResizeCol,iResizeRow;// ori img size,resize img size
	double dBlock_row = mDstimg.rows / row;//subplot image size
	double dBlock_col = mDstimg.cols / col;
	int iPos_col;
	int iPos_row;
	double dOri_Ratio = 0;//ori img ratio
	double dBlk_Ratio = dBlock_col / dBlock_row;//subplot ratio fixed
	Mat mImgROI;
	for (int i = 0; i < iNum; i++)
	{
		iCol = imgList[i].cols;
		iRow = imgList[i].rows;
		dOri_Ratio = double(iCol) / double(iRow);
		//ori too long
		if (dOri_Ratio >= dBlk_Ratio)
		{
			iResizeCol = dBlock_col;
			iResizeRow = iResizeCol / dOri_Ratio;
		}
		else// ori too high
		{
			iResizeRow = dBlock_row;
			iResizeCol = iResizeRow * dOri_Ratio;
		}
		//subplot position
		iPos_row = i / col * dBlock_row;
		iPos_col = i % col * dBlock_col;
		mImgROI = mDstimg(Rect(iPos_col, iPos_row, int(iResizeCol), int(iResizeRow)));
		resize(imgList[i], mImgROI, Size(int(iResizeRow), int(iResizeCol)));
	}
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, mDstimg);
	waitKey();


}
