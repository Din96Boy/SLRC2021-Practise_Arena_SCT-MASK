

// You may need to add webots include files such as
//<webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <webots/Camera.hpp>






#define MAX_SPEED_WALL 40
#define TURN_POWER 0.001
#define WALL_DISTANCE 200



using namespace webots;

//void delay(int delaytime){
  //std::this_thread::sleep_for(std::chrono::milliseconds(delaytime));
  //}
void showfactors(int n){
  int i;
  std::cout<<"Factors of "<<n<<"are : "<<std::endl;
  for (i =1;i<=n;++i){
    if(n % i == 0)
      std::cout<< i <<std::endl;
  }
}


int main(int argc, char **argv) {
  //create the Robot instance.
  Robot *robot = new Robot();

  // get the time step of the current world.
  int timeStep = 64;
  float max_speed = 6.28; //max speed of robot
  float left_speed =0;//speed of left wheel
  float right_speed =0;//speed of right wheel
  //int walldetect =0;
  
  int left_piller;
  int right_piller;
  int k_right =1;
  int k_left =1;
  int N;
  
  int red_detected =0;
  int green_detected =0;
  int blue_detected =0;
  
  
  

  
  // instances of motors
  Motor *left_motor = robot->getMotor("motor_01");
  Motor *right_motor = robot->getMotor("motor_02");
  
  left_motor->setPosition(float(INFINITY));
  left_motor->setVelocity(0.0);
  
  right_motor->setPosition(float(INFINITY));
  right_motor->setVelocity(0.0);
  
  
  //enabling ir sensors
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
  
  
  DistanceSensor *rightwall_ir = robot->getDistanceSensor("ir_5");
  rightwall_ir->enable(timeStep);
  
  DistanceSensor *leftwalltop_ir = robot->getDistanceSensor("ir_7");
  leftwalltop_ir->enable(timeStep);
  
  DistanceSensor *rightwalltop_ir = robot->getDistanceSensor("ir_8");
  rightwalltop_ir->enable(timeStep);
  
  DistanceSensor *leftcorner_ir = robot->getDistanceSensor("ir_10");
  leftcorner_ir->enable(timeStep);
  
  DistanceSensor *rightcorner_ir = robot->getDistanceSensor("ir_9");
  rightcorner_ir->enable(timeStep);
  
  DistanceSensor *front_ir = robot->getDistanceSensor("ir_11");
  front_ir->enable(timeStep);
  
  //enable camera
  
  Camera *cm;
  cm=robot->getCamera("CAM01");
  cm->enable(timeStep);
  //cm->getImage();
  
  

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    //Read the sensors:
    
    const unsigned char* img001 = cm->getImage();
    
    double left_ir_value = left_ir->getValue();
    double right_ir_value = right_ir->getValue();
    double mid_ir_value = mid_ir->getValue();
    double back_ir_value = back_ir->getValue();
    double front_ir_value = front_ir->getValue();
    
   
    double leftwall_ir_value = leftwall_ir->getValue();
    double rightwall_ir_value = rightwall_ir->getValue();
    
    double leftwalltop_ir_value = leftwalltop_ir->getValue();
    double rightwalltop_ir_value = rightwalltop_ir->getValue();
    
    double leftcorner_ir_value = leftcorner_ir->getValue();
    double rightcorner_ir_value = rightcorner_ir->getValue();
    
    //std::cout<<"mid :"<<mid_ir_value<<std::endl;  //for calibration
    //std::cout<<"image :"<<img001<<std::endl; //for calibration
    //std::cout<<"Rightwall:"<<rightwall_ir_value<<std::endl;  //for calibration
    //std::cout<<"leftwall:"<<leftwall_ir_value<<std::endl;  //for calibration
    
    
    //left_speed = 0.10 * max_speed;    //speed in initial position
    //right_speed = 0.10 * max_speed;   //speed in initial position
    
    //........................................................................
     //........................................................................
      //........................................................................
      
    
    //Detectig pixels of the image generated by camera
    
    for (int x =0;x<256;x++)
      for(int y =0;y<256;y++){
        int r = cm->imageGetRed(img001,256,x,y);
        int g = cm->imageGetGreen(img001,256,x,y);
        int b = cm->imageGetBlue(img001,256,x,y);
        
        //std::cout<<"RED :"<<r<<std::endl;  //for calibration
        //std::cout<<"GREEN :"<<g<<std::endl;  //for calibration
        //std::cout<<"BLUE :"<<b<<std::endl;  //for calibration
        
          
        ///////////////////////////////////////////////////////////
        /////////End Color stop Detection//////////////////////
        
        if (N==4){
          if ((r > 200) && (g < 100) && (b < 100) &&(red_detected==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
          
          if ((r < 100) && (g > 200) && (b < 100) && (green_detected ==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
          
          if ((r <100) && (g < 100) && (b > 200) && (blue_detected ==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
        }
        
        if(N == 8){
          if ((r > 200) && (g < 100) && (b < 100) &&(red_detected==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
          
          if ((r < 100) && (g > 200) && (b < 100) && (green_detected ==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
          
          if ((r <100) && (g < 100) && (b > 200) && (blue_detected ==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
        }
        
        if(N ==12){
          if ((r > 200) && (g < 100) && (b < 100) &&(red_detected==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
          
          if ((r < 100) && (g > 200) && (b < 100) && (green_detected ==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
          
          if ((r <100) && (g < 100) && (b > 200) && (blue_detected ==1)){
            showfactors(N);
            left_speed = 0 * max_speed;
            right_speed = 0 * max_speed;
            break;
          }
        }
        
        //////////////////////////////////////////////////////////////////////////////////
        //////////////////////Color detection at start////////////////////////////////////////
        
        
        
        if ((r > 200) && (g < 100) && (b < 100)){
          red_detected =1;
          std::cout<<"RED "<<std::endl;  //Print RED
          break;
        }
        
        if ((r< 100) && (g >200) && (b < 100)){
          green_detected =1;
          std::cout<<"GREEN "<<std::endl;  //Print GREEN
          break;
        }
        
        if ((r < 100) && (g < 100) && (b >214)){
          blue_detected =1;
          std::cout<<"BLUE "<<std::endl;  //Print BLUE
          break;
        }
      
          
            
            
          
          
        
        
          
        
      }
      
      
      
    
   /////////////////////////////////////////////////////////////////////////
   //////////////////pillar_values/////////////////////////////////////////   
    
    
    
    if((leftwall_ir_value <1000) && (rightwall_ir_value <1000)){
      
      //left piller calculate
      
      if ((leftwall_ir_value < 230)){
        left_piller = 4;
      }
      
      if ((leftwall_ir_value > 445) && (leftwall_ir_value < 450)){
        left_piller = 8;
      }
      
      if ((leftwall_ir_value > 670) && (leftwall_ir_value < 680)){
        left_piller = 12;
        
      }
        
        
      //right piller calculation
      
      
      if ((rightwall_ir_value < 230)){
        right_piller = 4;
      }
      
      if ((rightwall_ir_value > 445) && (rightwall_ir_value < 450)){
        right_piller = 8;
      }
      
      if ((rightwall_ir_value > 670) && (rightwall_ir_value < 680)){
        right_piller = 12;
        
      }
        
        
      if ((leftwalltop_ir_value < 800)){
        k_left = 2;
      }
      
      if (rightwalltop_ir_value < 800){
        k_right = 2;
      }
      
      int left_value = left_piller * k_left;
      int right_value = right_piller * k_right;
      
      N = abs (right_value - left_value);
      
      std::cout<<"left_value : "<<left_value<<std::endl;
      std::cout<<"right_value : "<<right_value<<std::endl;
      //std::cout<<"N_value : "<<N<<std::endl;
      
    }
        
    
    
    //movements for line follow area
    
    if ((left_ir_value <200) && (right_ir_value<200) ){
      
      //std::cout<<"go forward"<<std::endl;
      left_speed = 0.25 * max_speed;
      right_speed = 0.25 * max_speed;
     
    }
    
    if((mid_ir_value>543) && (mid_ir_value <547) && (back_ir_value< 200)){
      //std::cout<<"T turn left"<<std::endl;  //for turning in T junction
      left_speed = -0.05 * max_speed;
      right_speed = 0.05 * max_speed;
      
    }
    
    
    
    else if ((left_ir_value <200) && (right_ir_value <200) && (leftcorner_ir_value < 200) && (rightcorner_ir_value >400)){
      
      //std::cout<<"turn left"<<std::endl;
      //left_speed = -0.5 * max_speed;
      left_speed = 0 * max_speed;
      
      right_speed = 0.5 * max_speed;
      //delay(1000);
      
      
    }
    
    else if ((left_ir_value <200) && (right_ir_value >200) ){
      
      //std::cout<<"turn left"<<std::endl;
      left_speed = -0.25 * max_speed;
      right_speed = 0.25 * max_speed;
      //delay(1000);
      
    }
    
    else if ((left_ir_value <200) && (right_ir_value <200) && (rightcorner_ir_value<200) &&(leftcorner_ir_value >400)){
      
      //std::cout<<"turn right"<<std::endl;
      left_speed = 0.5 * max_speed;
      //right_speed = -0.5 * max_speed;
      right_speed = 0 * max_speed;
      //delay(1000);
      
      
    }
    
    else if ((left_ir_value >200) && (right_ir_value <200) ){
      
      //std::cout<<"turn right"<<std::endl;
      left_speed = 0.25 * max_speed;
      right_speed = -0.25 * max_speed;
      //delay(1000);
      
    }
    
    //////////////////////////////////////////////////////////////////////////////////////
    
    if ((leftwall_ir_value == 1000) && (rightwall_ir_value ==1000) && (leftcorner_ir_value <200) && (rightcorner_ir_value <200) && (front_ir_value < 200)){
      if (N == 4){
        //turn left
        //left_speed = -0.5 * max_speed;
        left_speed = 0 * max_speed;
        right_speed = 1 * max_speed;
        }
        
      if (N == 8){
        //go forward
        left_speed = 0.25 * max_speed;
        right_speed = 0.25 * max_speed;
        }
        
      if (N == 12){
        //turn right
        left_speed = 1 * max_speed;
        //right_speed = -0.5 * max_speed;
        right_speed = 0 * max_speed;
        }
        
    }
        
    
    
    
    
    //movements for wall area
    
    //if ((leftwall_ir_value < 540) && (rightwall_ir_value <500)){
        //std::cout<<"wall forward"<<std::endl;
        //left_speed = 0.20 * max_speed;
        //right_speed = 0.20 * max_speed;
        
      //}
    
    //if (walldetect ==0){
    
      //if ((frontwall_ir_value > 450)  && (frontwall_ir_value <1000)){
        //std::cout<<"wall forward"<<std::endl;
        //left_speed = 0.20 * max_speed;
        //right_speed = 0.20 * max_speed;
        
      //}
      
      //else if(frontwall_ir_value < 450){
        //walldetect =1;
        
        //std::cout<<"wall_turn_right"<<std::endl;
        //left_speed = 0.20 * max_speed;
        //right_speed = - 0.20 * max_speed;
      //}
    //}
    
    
    
    //else if((frontwall_ir_value >450) && (frontwall_ir_value <1000)){
      //std::cout<<"wall_run"<<std::endl;
      //left_speed = 0.4 * (MAX_SPEED_WALL - TURN_POWER * ((leftwall_ir_value - WALL_DISTANCE) + 0.2 * (frontwall_ir_value - WALL_DISTANCE) ));
      //right_speed = 0.4 * (MAX_SPEED_WALL +  TURN_POWER * ((leftwall_ir_value - WALL_DISTANCE) + 0.2 * (frontwall_ir_value - WALL_DISTANCE)));
      
    //}
    
    //else if((frontwall_ir_value < 450)){
      //std::cout<<"wall_newturn_right"<<std::endl;
      //left_speed = 0.20 * max_speed;
      //right_speed = - 0.20 * max_speed;
      
    //}
    //..........................................................    
    
    //if ((leftwall_ir_value < 900) && (rightwall_ir_value > 500) && (rightwall_ir_value < 1000)){
      
      
      //std::cout<<"wall right"<<std::endl;
      //left_speed = 0.50 * max_speed;
      //right_speed = -0.50 * max_speed;
      //_sleep(5000);


    //}
      
      
    //else if ((frontwall_ir_value <600) && (leftwall_ir_value > 900) && (leftwall_ir_value <1000) && (rightwall_ir_value <900)){
      
      //std::cout<<"wall left"<<std::endl;
      //left_speed = - 0.20 * max_speed;
      //right_speed = 0.20 * max_speed;
      
    
      
      
      
    //}
      
        
      
      
   
    
    
    

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    left_motor->setVelocity(left_speed);
    right_motor->setVelocity(right_speed);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}