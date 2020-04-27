# We need https
if(getRversion() < "3.3.0") setInternet2()
VERSION <- commandArgs(TRUE)

# Downloads libssh2 + dependencies
if(!file.exists(sprintf("../windows/opencv-%s/include/opencv4/opencv2/opencv.hpp", VERSION))){
  download.file(sprintf("https://github.com/rwinlib/opencv/archive/v%s.zip", VERSION), "lib.zip", quiet = TRUE)
  dir.create("../windows", showWarnings = FALSE)
  unzip("lib.zip", exdir = "../windows")
  unlink("lib.zip")
}

# Build against imagemagick static website.
MAG_IM <- 6
MAG_VERSION <- "6.9.9"
if(!file.exists(sprintf("../windows/imagemagick%s-%s/include/ImageMagick-%s/Magick++.h", MAG_IM, MAG_VERSION, MAG_IM))){
  curl::curl_download(sprintf("https://github.com/rwinlib/imagemagick%s/archive/v%s.zip", MAG_IM, MAG_VERSION), "lib.zip")
  dir.create("../windows", showWarnings = FALSE)
  unzip("lib.zip", exdir = "../windows")
  unlink("lib.zip")
}
