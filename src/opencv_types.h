#define R_NO_REMAP
#define STRICT_R_HEADERS

#include <Rcpp.h>
#include <opencv2/opencv.hpp>

void finalize_mat(cv::Mat * frame);
typedef Rcpp::XPtr<cv::Mat, Rcpp::PreserveStorage, finalize_mat, true> XPtrMat;

// for conversion from magick
#include <Magick++.h>
#include <list>

typedef Magick::Image Frame;
typedef std::vector<Frame> Image;

void finalize_image(Image *image);
typedef Rcpp::XPtr<Image, Rcpp::PreserveStorage, finalize_image, false> XPtrImage;
typedef Image::iterator Iter;
