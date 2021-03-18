# 简介
这个工程用于将sensor_msgs::CompressedImageConstPtr数据转换成cv：：mat Image，使用两种方法实现：
1. 使用cv_bridge；
2. 使用cv::imdecode，解码的彩色图像是BGR格式；
```
enum ImreadModes {
       IMREAD_UNCHANGED            = -1, //!< If set, return the loaded image as is (with alpha channel, otherwise it gets cropped).
       IMREAD_GRAYSCALE            = 0,  //!< If set, always convert image to the single channel grayscale image.
       IMREAD_COLOR                = 1,  //!< If set, always convert image to the 3 channel BGR color image.
       IMREAD_ANYDEPTH             = 2,  //!< If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
       IMREAD_ANYCOLOR             = 4,  //!< If set, the image is read in any possible color format.
       IMREAD_LOAD_GDAL            = 8,  //!< If set, use the gdal driver for loading the image.
       IMREAD_REDUCED_GRAYSCALE_2  = 16, //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/2.
       IMREAD_REDUCED_COLOR_2      = 17, //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2.
       IMREAD_REDUCED_GRAYSCALE_4  = 32, //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/4.
       IMREAD_REDUCED_COLOR_4      = 33, //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/4.
       IMREAD_REDUCED_GRAYSCALE_8  = 64, //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/8.
       IMREAD_REDUCED_COLOR_8      = 65, //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/8.
       IMREAD_IGNORE_ORIENTATION   = 128 //!< If set, do not rotate the image according to EXIF's orientation flag.
     };

```

/** @brief Reads an image from a buffer in memory.

The function imdecode reads an image from the specified buffer in the memory. If the buffer is too short or
contains invalid data, the function returns an empty matrix ( Mat::data==NULL ).

See cv::imread for the list of supported formats and flags description.

@note In the case of color images, the decoded images will have the channels stored in **B G R** order.
@param buf Input array or vector of bytes.
@param flags The same flags as in cv::imread, see cv::ImreadModes.
*/
CV_EXPORTS_W Mat imdecode( InputArray buf, int flags );

# others
这个工程可以直接用cmake .. , make 编译，代替catkin_make 流程，
但是，无法使用rosrun启动对应的节点，roslaunch运行正常。