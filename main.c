#include <kipr/botball.h>

int main()
{
    //wait_for_light(4);
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
    msleep(300);
    

     mav(0,-500);
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
        if(get_object_area(0, 0) > 700)
        {
            printf("%d\n", get_object_area(0,0));
            break;
            //if(analog(0) > 1800) 
            //{
            // mav(0,10);
            // mav(2,90);
            // }
            //else
            //{
            //mav(0,90);
            ///  mav(2,10);
            //  }

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
    msleep(1000);
    
    mav(0,500);
    mav(2,-500);
    msleep(1500);
    
    mav(0,1000);
    mav(2,1000);
    msleep(500);
    
    set_servo_position(0, 1304);
    
    mav(0,-1000);
    mav(2,-1000);
    msleep(1000);
    camera_close();
    return 0;
}