#include "ros/ros.h"
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <string> 

void image_callback ( const sensor_msgs::CompressedImageConstPtr& msg ) {

    ROS_INFO ( "... image message received!" );

    try {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::BGR8);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        cv::Mat image = cv_ptr -> image;
        printf("image width:%d\n",image.cols);
        printf("image width:%d\n",image.rows);
        cv::imshow ( "view", image );
        cv::waitKey ( 3 );

    } catch (cv_bridge::Exception& e ) {
        ROS_ERROR ( "... exception occurred when catching image!" );
    };

    return;
}

void image_callback2 ( const sensor_msgs::CompressedImageConstPtr& msg ) {

    ROS_INFO ( "... image message received!" );

    try {
        cv::Mat image = cv::imdecode(msg->data,1);
        printf("image width:%d\n",image.cols);
        printf("image width:%d\n",image.rows);
        cv::imshow ( "view", image );
        cv::waitKey ( 3 );

    } catch (cv_bridge::Exception& e ) {
        ROS_ERROR ( "... exception occurred when catching image!" );
    };

    return;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "decode_compressed_image");
    ros::NodeHandle nh("~");
    
    cv::namedWindow("view");
    cv::startWindowThread();
    ros::Subscriber sub = nh.subscribe("/sensor/camera_front_fisheye/image_raw/compressed", 1, image_callback);
    ros::spin();
    cv::destroyWindow("view");

    return 0;
}