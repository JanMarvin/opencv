#include "util.hpp"
#include "opencv_types.h"

// ************************************************************************** //
// for conversion from magick

//External R pointer finalizer
void finalize_image( Image *image ){
  delete image;
  image = NULL;
}

// [[Rcpp::export]]
XPtrImage create (int len){
  Image *image = new Image();
  if(len > 0){
    image->reserve(len);
  }
  XPtrImage ptr(image);
  ptr.attr("class") = Rcpp::CharacterVector::create("magick-image");
  return ptr;
}

// ************************************************************************** //

// [[Rcpp::export]]
XPtrMat magick2opencv (XPtrImage image) {

  // Dimensions of Magick++ Image
  int col = image->at(0).columns();
  int row = image->at(0).rows();

  // OpenCV Mat of same size
  cv::Mat opencvImage(row, col, CV_8UC3);

  // Magick++ to OpenCV
  image->at(0).write(0, 0, col, row, "BGR",
            Magick::CharPixel, opencvImage.data);

  return cvmat_xptr(opencvImage);
}

// [[Rcpp::export]]
XPtrImage opencv2magick(XPtrMat image)
{
  cv::Mat img = get_mat(image);

  // Dimensions of OpenCV Mat
  int col = img.cols;
  int row = img.rows;

  // OpenCV to Magick++
  Magick::Image magickImage(col, row, "BGR",
                            Magick::CharPixel, img.data);

  // prepare output
  XPtrImage outptr = create(1);
  outptr->push_back(magickImage);
  return outptr;
}
