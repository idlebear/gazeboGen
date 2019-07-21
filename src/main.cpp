//
// Created by bjgilhul on 7/18/19.
//

#include <iostream>
#include <ros/ros.h>
#include <string>
#include <vector>

#include "gazebo_generator.h"

using namespace std;
namespace gg = gazebo_generator;

int
main( int argc, char** argv ) {

    // Init ROS
    ros::init( argc, argv, "GazeboGen" );
    ros::NodeHandle n;



    string gazeboFileName;
    n.getParam( "gazebo_world_file", gazeboFileName );
    string contourFileName;
    n.getParam( "contour_file", contourFileName );

    gg::GazeboGenerator generator( "test.world", contourFileName, 2000, 2000, 25, 5 );

    vector<gg::Polygon> obs;
    gg::Polygon p { {{ 100, 100 }, { 200, 100 }},
                    {{ 200, 100 }, { 200, 200 }},
                    {{ 200, 200 }, { 100, 200 }},
                    {{ 100, 200 }, { 100, 100 }} };
    generator.addPolygon( p );
    generator.write();
}

