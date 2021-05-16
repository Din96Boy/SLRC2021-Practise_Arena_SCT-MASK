"""drive_robot controller."""

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
from controller import Robot
import time

def whiteturnright():
    print("whiteturnright2")
    #left_speed = 0.25 * max_speed
    right_speed = -0.25* max_speed

if __name__ == "__main__":
    
    
    # create the Robot instance.
    robot = Robot()
    
    # get the time step of the current world.
    timestep = 32 #int(robot.getBasicTimeStep())
    max_speed = 6.28
    
    

    
    #motor instances
    left_motor = robot.getDevice('motor_01')
    right_motor = robot.getDevice('motor_02')
    
    left_motor.setPosition(float('inf'))
    left_motor.setVelocity(0.0)
    
    right_motor.setPosition(float('inf'))
    right_motor.setVelocity(0.0)
    
    
    #enable ir sensors
    left_ir = robot.getDevice('ir_0')
    left_ir.enable(timestep)
    
    right_ir = robot.getDevice('ir_1')
    right_ir.enable(timestep)
    
    mid_ir = robot.getDevice('ir_2')
    mid_ir.enable(timestep)
    
    back_ir = robot.getDevice('ir_6')
    back_ir.enable(timestep)
    
    leftwall_ir = robot.getDevice('ir_3')
    leftwall_ir.enable(timestep)
    
    frontwall_ir = robot.getDevice('ir_4')
    frontwall_ir.enable(timestep)
    
    rightwall_ir = robot.getDevice('ir_5')
    rightwall_ir.enable(timestep)

    
    
    
    # Main loop:
    # - perform simulation steps until Webots is stopping the controller
    while robot.step(timestep) != -1:
        #read ir sensors
        left_ir_value = left_ir.getValue()
        right_ir_value = right_ir.getValue()
        mid_ir_value = mid_ir.getValue()
        back_ir_value = back_ir.getValue()
        
        frontwall_ir_value = frontwall_ir.getValue()
        leftwall_ir_value = leftwall_ir.getValue()
        rightwall_ir_value = rightwall_ir.getValue()
        
        print("left: {} front: {} right: {}".format(leftwall_ir_value, frontwall_ir_value, rightwall_ir_value))
        
        left_speed = 0.25 * max_speed
        right_speed = 0.25 * max_speed
        
        if (right_ir_value > 200) and (left_ir_value < 200)  :
            print("Go left")
            left_speed = -max_speed * 0.20
            right_speed = max_speed * 0.20
            #sleep(0.5)
        
        elif(left_ir_value > 200) and (right_ir_value < 200)  :
            print("Go right")
            right_speed = -max_speed * 0.20
            left_speed = max_speed * 0.20
            #sleep(0.5)
            
        elif(138<left_ir_value<139) and (138<right_ir_value<139):
            print("RED")
            #left_speed = 0.25 * max_speed
            #right_speed = -0.25 * max_speed
            
        elif(left_ir_value >400) and (right_ir_value >400) and (back_ir_value <200):
            #print("stop")
            #left_speed = 0 * max_speed
            #right_speed = 0 * max_speed
            
            print("go forward")
            left_speed = max_speed * 0.20
            right_speed = max_speed * 0.20
            
            #sleep(1)
            
            
            #print("stop")
            #left_speed = 0 * max_speed
            #right_speed = 0 * max_speed
            
        
            
        if (leftwall_ir_value <=990) and (frontwall_ir_value >980):
            print("drive forward")
            left_speed = 0.25 * max_speed
            right_speed = 0.25 * max_speed
            
            
            
        elif(frontwall_ir_value <980) and (leftwall_ir_value <990):
            
                    
            
            #whiteturnright();
            
            
            print("whiteturnright2")
            #left_speed = 0.25 * max_speed
            right_speed = -1* max_speed
            
            #left_motor.setVelocity(left_speed)
            #right_motor.setVelocity(right_speed)
            
            #timer = threading.Timer(0.5,whiteturnright)
            #timer.start()
            #if (frontwall_ir_value >980) and (leftwall_ir_valur>990):
                #print("still turning right")
            
                #right_speed = -0.25 * max_speed
            
            
            #if(1000>leftwall_ir_value >950):
                #print('turn left wall')
                #left_speed = max_speed / 8
                #right_speed = max_speed
        
        #right_speed = -0.25 * max_speed
        #left_speed = 0.25 * max_speed
        #sleep(1)
           
           
            
    
        left_motor.setVelocity(left_speed)
        right_motor.setVelocity(right_speed)
    
    # Enter here exit cleanup code.
