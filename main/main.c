#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#include "rgb_led.h"
void app_main(void)
{
   while (true)
   {
    rgb_led_wifi_app_started();
    vTaskDelay(pdMS_TO_TICKS(1000));
    rgb_led_http_server_started();
    vTaskDelay(pdMS_TO_TICKS(1000));
    rgb_led_wifi_connected();
    vTaskDelay(pdMS_TO_TICKS(1000));

   }
   
    
}