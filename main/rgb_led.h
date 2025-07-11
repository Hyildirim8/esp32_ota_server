#ifndef MAIN_RGB_LED_H
#define MAIN_RGB_LED_H

// RGB LED GPIOs
#define RGB_LED_RED_GPIO 21
#define RGB_LED_GREEN_GPIO 22
#define RGB_LED_BLUE_GPIO 23

// RGB LED color mix channels
#define RGB_LED_CHANNEL_NUM 3

// RGB LED configration
typedef struct rgb_led
{
    int channel;
    int gpio;
    int mode;
    int timer_index;
} ledc_info_t;

// Color to indicate WIFI application has started
void rgb_led_wifi_app_started(void);

// Color to indicate HTTP Server has started
void rgb_led_http_server_started(void);

// Color to indicate that the ESP32 is connected to an access point
void rgb_led_wifi_connected(void);

#endif