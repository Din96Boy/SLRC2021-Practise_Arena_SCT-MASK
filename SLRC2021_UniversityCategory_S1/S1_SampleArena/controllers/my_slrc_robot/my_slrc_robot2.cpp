// File:          my_slrc_robot.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
//<webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>


// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  //create the Robot instance.
  Robot *robot = new Robot();

  // get the time step of the current world.
  int timeStep = 32;
  float max_speed = 6.25;

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  Motor *left_motor = robot->getMotor("motor_01");
  Motor *right_motor = robot->getMotor("motor_02");
  
  left_motor->setPosition(float('inf'));
  left_motor->setVelocity(0,0);
  
  right_motor->setPosition(float('inf'));
  right_motor->setVelocity(0,0);
  
  
  DistanceSensor *left_ir = robot->getDistanceSensor("ir_0");
  left_ir->enable(timeStep);
  
  DistanceSensor *right_ir = robot->getDistanceSensor("ir_1");
  right_ir->enable(timeStep);
  
  DistanceSensor *mid_ir = robot->getDistanceSensor("ir_2");
  mid_ir->enable(timeStep);
  
  DistanceSensor *back_ir = robot->getDistanceSensor("ir_6");
  back_ir->enable(timeStep);
  
  DistanceSensor *leftwall_ir = robot->getDistanceSensor("ir_3");
  leftwall_ir->enable(timeStep);
  
  DistanceSensor *frontwall_ir = robot->getDistanceSensor("ir_4");
  frontwall_ir->enable(timeStep);
  
  DistanceSensor *rightwall_ir = robot->getDistanceSensor("ir_5");
  rightwall_ir->enable(timeStep);
  
  

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    //Read the sensors:
    // Enter here functions to read sensor data, like:
    double left_ir_value = left_ir->getValue();
    double right_ir_value = right_ir->getValue();
    double mid_ir_value = mid_ir->getValue();
    double back_ir_value = back_ir->getValue();
    
    double frontwall_ir_value = frontwall_ir->getValue();
    double leftwall_ir_value = leftwall_ir->getValue();
    double rightwall_ir_value = rightwall_ir->getValue();
    
    
    printf("left: {} right: {} mid: {}".format(left_ir_value , right_ir_value , mid_ir_value));
    
    
    float left_speed = 0.25 * max_speed;
    float right_speed = 0.25 * max_speed;
    

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    left_motor->setVelocity(left_speed);
    right_motor->setVelocity(right_speed);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
