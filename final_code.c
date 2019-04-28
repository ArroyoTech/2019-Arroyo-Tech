#include <kipr/botball.h>

int main()
{
    //wait_for_light(0);
    shut_down_in(119);
    //enable_servos();
    int iteration_count = 0;
    int update_errors = 0;
    camera_open_black();
    printf("owo big h test");
    enable_servos();

set_servo_position(0,1600);


    set_servo_position(0,1200);

    mav(0,1000);
    mav(2,1000);
    msleep(6000); 

    mav(0,0);
    mav(2,0);
    msleep(500);
    set_servo_position(0,1802);

    mav(0,0);
    mav(2,0);
    msleep(500);

    mav(0, 1000);
    mav(2, 1000);
    msleep(200);
    
    mav(0,-500);
    mav(2,500);
    msleep(1375);
    

    while (right_button() == 0)
    {
        if(!camera_update())
        {
            update_errors++;
            continue;
        }
        if (iteration_count > 1000)
        {
            iteration_count = 0;
            camera_close();
            camera_open_black();
        }


        //code starts here
        camera_update();
        if(get_object_area(0, 0) > 400)
        {
            printf("%d\n", get_object_area(0,0));
            break;
           

        }
        else
        {
            printf("%d\n", get_object_area(0,0));
            camera_update();
            mav(0,500);
            mav(2,500);

        }
        //turn into box and drop off firetruck
        iteration_count++;


    } 
    
    mav(0,1000);
    mav(2,1000);
    msleep(500);
    
    mav(0,500);
    mav(2,-500);
    msleep(1500);
    
    mav(0,1000);
    mav(2,1000);
    msleep(520);
    
      set_servo_position(0, 1400);
    
    mav(0,0);
    mav(2,0);
    msleep(550);
  
    mav(0,-400);
    mav(2,-400);
    msleep(3000);
    
     mav(0,650);
    mav(0,-650);
    msleep(1000);
    
    
    camera_close();
    
    mav(0,-700);
    mav(2,700);
    msleep(900);
    
    
       while(analog(1) < 2200)	//2200-1200
    {
        mav(0,-1000);
        mav(2,-1000);
    }
    
    mav(0,-700);
    mav(2,700);
    msleep(1250);
    
    //proposed changes
    
    mav(0,-1000);
    mav(2,-1000);
    msleep(1500);           //this piece of code is to make the robot back up and hit the firefighters into the fire station
    
    mav(0,1000);
    mav(2,-1000);
    msleep(700);
    
    mav(0,-1000);
    mav(2,1000);
    msleep(1200);
    
    return 0;
}
