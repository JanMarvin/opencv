#' convert OpenCV to Magick and vice versa
#'
#' @param input either magick-image or opencv-image for conversion
#'
#' @examples
#' \dontrun{
#'  ocvimg <- convert(mag_img)
#'  magimg <- convert(ocv_img)
#' }
#'
#' @export
convert <- function(input) {

  z <- NULL

  if(inherits(input, "magick-image"))
    z <- magick2opencv(input);

  if(inherits(input, "opencv-image"))
    z <- opencv2magick(input);

  z
}
