//
// Created by kehan on 19-7-17.
//

#ifndef FIRA_ESI_PX4INTERFACE_H_
#define FIRA_ESI_PX4INTERFACE_H_



#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/CommandBool.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_datatypes.h>

class PX4Interface
{
public:
    PX4Interface();

    virtual ~PX4Interface();

    int8_t update();

    int8_t switchOffboard();
    int8_t unlockVehicle();

    double_t getCurYaw();
    double_t getCurZ();


private:

    void px4_state_cb(const mavros_msgs::State::ConstPtr& msg);
    void px4_pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg);


    ros::NodeHandle nh;
    ros::Rate loop_rate;

    ros::Subscriber px4_state_sub;
    ros::ServiceClient px4_arming_client;
    ros::ServiceClient px4_set_mode_client;
    ros::Subscriber px4_pose_sub;

    mavros_msgs::State px4_cur_state;
    mavros_msgs::SetMode px4_offb_set_mode;
    mavros_msgs::CommandBool px4_arm_cmd;

    geometry_msgs::PoseStamped px4_cur_pose;

};



#endif //FIRA_ESI_PX4INTERFACE_H_

