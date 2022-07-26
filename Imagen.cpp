#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/*
comentarios en el programa
*/

//comentarios en el programa

int main()
{

    Mat img;

    img = imread("lena.jpg", 1);

    Mat gris(img.rows, img.cols, CV_8UC1);
    Mat gris50Positivo(img.rows, img.cols, CV_8UC1);
    Mat gris50Negativo(img.rows, img.cols, CV_8UC1);

    //255 es negro y 0 es blanco

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            cv::Vec3b pixel = img.at<Vec3b>(i, j);

            uchar Azul = pixel[0];
            uchar Verde = pixel[1];
            uchar Rojo = pixel[2];

            gris.at<uchar>(i, j) = (Azul + Verde + Rojo) / 3;

            gris50Positivo.at<uchar>(i, j) = ( (Azul + Verde + Rojo) / 3 ) + 50;
            gris50Negativo.at<uchar>(i, j) = ( (Azul + Verde + Rojo) / 3 ) - 50;

            if (gris.at<uchar>(i, j) > gris50Positivo.at<uchar>(i, j) )
            {
                gris50Positivo.at<uchar>(i, j) = 255;
            }
            else if (gris.at<uchar>(i, j) < gris50Negativo.at<uchar>(i, j))
            {
                gris50Negativo.at<uchar>(i, j) = 0;
            }
        }
    }


    imshow("Display Image", img);
    imshow("Display gris", gris);
    imshow("Display contraste positivo", gris50Positivo);
    imshow("Display contraste negativo", gris50Negativo);


    waitKey();
    //getchar();
    return 0;
}