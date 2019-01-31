//
// Created by Yuval Gak on 2019-01-27.
//

#include "integralImage.hpp"
#include <stdlib.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>

#define likely(x)       __builtin_expect((x),1)

using namespace cv;
using namespace std;

    IntegralImg::IntegralImg(cv::Mat const &img)  {
        // TODO: implement check that dims are no larger than maxDouble. in order to prevent overflow.
        cols = img.cols;
        this->sumsArray = new double[img.rows*img.cols];
        for (int i=0; i< img.rows; i++){
            for (int j=0; j<img.cols; j++){
                double elem = img.at<uint8_t>(i,j);
                double prevSum = _returnPrevSumsIfExists(i,j);
                this->sumsArray[matIndexToArray(i,j)] = elem + prevSum;
            }
        }

    }
    IntegralImg::~IntegralImg() {
        delete [] this->sumsArray;
    }

    double IntegralImg::SummationOverBoundingBox(int topLeft, int topRight, int bottomLeft, int bottomRight){
        // TODO: implement check that the four point form a rectangle and is whithin borders.
        //as in https://en.wikipedia.org/wiki/Summed-area_table
        return (this->sumsArray[bottomRight] - this->sumsArray[topRight] - this->sumsArray[bottomLeft] + this->sumsArray[topLeft]);
    }

    inline double IntegralImg::_returnPrevSumsIfExists(int i,int j){
        if (likely(i>0 && j>0)) {
            return (this->sumsArray[matIndexToArray(i-1,j)]+this->sumsArray[matIndexToArray(i,j-1)]);
        }
        if (i>0) {
            return this->sumsArray[matIndexToArray(i-1,j)];
        }
        if (j>0) {
            return this->sumsArray[matIndexToArray(i,j-1)];
        }
        // case where i<=0, j<=0
        return 0;
    }

    inline int IntegralImg::matIndexToArray(int x, int y){
        return (x*(this->cols)) + y;
    }

