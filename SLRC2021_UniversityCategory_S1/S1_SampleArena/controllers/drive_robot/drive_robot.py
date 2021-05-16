"""drive_robot controller."""

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
from controller import Robot

if __name__ == "__main__":
    
    
    # create the Robot instance.
    robot = Robot()
    
    # get the time step of the current world.
    timestep = 64 #int(robot.getBasicTimeStep())
    max_speed = 6.28
    

    
    #motor instances
    left_motor = robot.getDevice('motor_02')
    right_motor = robot.getDevice('motor_01')
    
    left_motor.setPosition(float('inf'))
    left_motor.setVelocity(0.0)
    
    right_motor.setPosition(float('inf'))
    right_motor.setVelocity(0.0)
    
    # Main loop:
    # - perform simulation steps until Webots is stopping the controller
    while robot.step(timestep) != -1:
        left_speed = 0.5 * max_speed
        right_speed = 0.5 * max_speed
    
        left_motor.setVelocity(left_speed)
        right_motor.setVelocity(right_speed)
    
    # Enter here exit cleanup code.
