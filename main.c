#include <kipr/botball.h>

int main()
{
    //wait_for_light(4);
    shut_down_in(119);
    int iteration_count = 0;
    int update_errors = 0;
    camera_open_black();
    enable_servos();

set_servo_position(0,1600);             //open claw


    set_servo_position(0,1200);         //open claw

    mav(0,1000);
    mav(2,1000);                        //move forward for 6 seconds
    msleep(6000); 

    mav(0,0);
    mav(2,0);                           //wait half a second
    msleep(500);
    set_servo_position(0,1802);         //close claw

    mav(0,0);                           
    mav(2,0);                           //wait another half second
    msleep(500);

    mav(0, 1000);                       //move forward for 1/3 of a second
    mav(2, 1000);
    msleep(300);
    

     mav(0,-500);                      //turn right 90 degrees
    mav(2,500);
    msleep(1500);


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
        if(get_object_area(0, 0) > 700)         //move forward until camera sees burning
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
    msleep(1000);               // move forward for 1 second
    
    mav(0,500);
    mav(2,-500);                //turn 90 degrees into the box
    msleep(1500);
    
    mav(0,1000);
    mav(2,1000);
    msleep(500);            //move forward half a second
    
    set_servo_position(0, 1304);        //open claw
    
    mav(0,-1000);
    mav(2,-1000);
    msleep(1000);                   //back up
    camera_close();
    return 0;
}
