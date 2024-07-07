#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED 2

void initialization(void)
{
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);
}

void app_main(void)
{
    initialization();
    uint32_t isOn = 0;

    while (true)
    {
        isOn = !isOn;
        gpio_set_level(LED, isOn);
        
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
