#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "imshowGrid.h"
using namespace cv;
using namespace std;
char namefile[100];
int main(int argc,char** argv)
{
	int iNum = 0;
	cout << "please input a num (img number:)" << endl;
	cin >> iNum;
	vector<Mat> vecImg(iNum);
	for (int i = 0; i < iNum; i++)
	{
		sprintf(namefile, "%d.jpg", i + 1);
		vecImg[i] = imread(namefile);
	}

	//int iNumImg = vecImg.size();
	//cout << iNumImg << endl;

	imshowGrid(vecImg, 3, 3, cvSize(500,500), "subplot");
	system("pause");
	return 0;
}

