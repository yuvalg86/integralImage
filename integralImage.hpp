//
// Created by Yuval Gak on 2019-01-27.
//

#pragma once
#include <opencv2/core/mat.hpp>

class IntegralImg {
public:
    /**
     * Constructor that recieves a 8bit 1Channel Image.
     * @param img 8bit 1 Channel image.
     */
    IntegralImg(cv::Mat const &img); // image is single channel char
    /**
     * returns the summation over the bounding box that defined by the dots.
     * https://en.wikipedia.org/wiki/Summed-area_table
     * note: ASSUMES THAT INPUT IS LEGAL and FORMS a valid rectangle bounding box which is internal.
     * @param topLeft 1d representation of topLeft point
     * @param topRight 1d representation of topRight point
     * @param bottomLeft 1d representation of bottomLeft point
     * @param bottomRight 1d representation of bottomRight point
     * @return double representing the sum
     */
    double SummationOverBoundingBox(int topLeft, int topRight, int bottomLeft, int bottomRight);
    ~IntegralImg();
private:
    // 1d array of sums.
    double *sumsArray;
    // number of cols.
    uint8_t cols;
    // transforms 2d index (x,y) to 1d array.
    inline int matIndexToArray(int x, int y);
    // function that returns sum of previous relevant sums.
    double _returnPrevSumsIfExists(int row, int col);

};