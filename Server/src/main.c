#include "pico/stdio.h"
#include "pico/cyw43_arch.h"
#include "lwip/apps/httpd.h"
// #include "lwipopts.h" i dont know if i need this

const char WIFI_SSID[] = "MIWIFI_2G_g9dw";
const char WIFI_PASSWORD[] = "3yzswe3emyh6";

int main()
{
    stdio_init_all();

    cyw43_arch_init();

    cyw43_arch_enable_sta_mode();

    while (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000) != 0)
    {
        printf("Attempring to connect to %s ...\n", WIFI_SSID);
    }

    printf("Connected!\n");

    httpd_init();
    printf("Http server initialised\n");

    while (1)
    {
    }
}