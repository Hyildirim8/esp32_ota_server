#include <stdbool.h>

#include "driver/ledc.h"
#include "rgb_led.h"

// RGB LED Configuration Array
ledc_info_t led_ch[RGB_LED_CHANNEL_NUM];


// handle for rgb_led_pwm init
bool g_pwm_init_handle = false;

/*
* Initializes the RGB led settings per channel, including
* The GPIO for each color, mode and timer configration.
*/


static void rgb_led_pwm_init(void){
    int rgb_ch;

    // Red
    led_ch[0].channel = LEDC_CHANNEL_0;
    led_ch[0].gpio = RGB_LED_RED_GPIO;
    led_ch[0].mode = LEDC_HIGH_SPEED_MODE;
    led_ch[0].timer_index = LEDC_TIMER_0;

    // Green
    led_ch[1].channel = LEDC_CHANNEL_1;
    led_ch[1].gpio = RGB_LED_GREEN_GPIO;
    led_ch[1].mode = LEDC_HIGH_SPEED_MODE;
    led_ch[1].timer_index = LEDC_TIMER_0;

    // Blue
    led_ch[2].channel = LEDC_CHANNEL_2;
    led_ch[2].gpio = RGB_LED_BLUE_GPIO;
    led_ch[2].mode = LEDC_HIGH_SPEED_MODE;
    led_ch[2].timer_index = LEDC_TIMER_0;

    // Configure timer zero
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_8_BIT,
        .freq_hz = 100,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
    };
    ledc_timer_config(&ledc_timer);

    // Configure channels
    for (rgb_ch = 0; rgb_ch < RGB_LED_CHANNEL_NUM; rgb_ch++)
    {
        ledc_channel_config_t ledc_channel = {
            .channel = led_ch[rgb_ch].channel,
            .duty = 0,
            .hpoint = 0,
            .gpio_num = led_ch[rgb_ch].gpio,
            .intr_type = LEDC_INTR_DISABLE,
            .speed_mode = led_ch[rgb_ch].mode,
            .timer_sel = led_ch[rgb_ch].timer_index,
        };
        ledc_channel_config(&ledc_channel);
    }

    g_pwm_init_handle = true;
    
}


/*
* Set the RGB color
*/

static void rgb_led_set_color(uint8_t red, uint8_t green , uint8_t blue){
    // Value should be 0 - 255  for 8 bit number
    ledc_set_duty(led_ch[0].mode,led_ch[0].channel,red);
    ledc_update_duty(led_ch[0].mode,led_ch[0].channel);

    ledc_set_duty(led_ch[1].mode,led_ch[1].channel,green);
    ledc_update_duty(led_ch[1].mode,led_ch[1].channel);
    
    ledc_set_duty(led_ch[2].mode,led_ch[2].channel,blue);
    ledc_update_duty(led_ch[2].mode,led_ch[2].channel);
}



void rgb_led_wifi_app_started(void){
    if (g_pwm_init_handle == false)
    {
        rgb_led_pwm_init();
    }
    
    rgb_led_set_color(255,102,255);
}


void rgb_led_http_server_started(void){
    if (g_pwm_init_handle == false)
    {
        rgb_led_pwm_init();
    }
    
    rgb_led_set_color(204,255,51);
}


void rgb_led_wifi_connected(void){
    if (g_pwm_init_handle == false)
    {
        rgb_led_pwm_init();
    }
    
    rgb_led_set_color(0,255,153);
}
