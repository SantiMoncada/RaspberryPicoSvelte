#include "pico/stdio.h"
#include "pico/cyw43_arch.h"
#include "lwip/apps/httpd.h"

const char WIFI_SSID[] = "<WIFI_SSID>";
const char WIFI_PASSWORD[] = "<WIFI_PASSWORD>";

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

    extern cyw43_t cyw43_state;
    int ip_addr = cyw43_state.netif[CYW43_ITF_STA].ip_addr.addr;
    printf("IP Address: %lu.%lu.%lu.%lu\n", ip_addr & 0xFF, (ip_addr >> 8) & 0xFF, (ip_addr >> 16) & 0xFF, (ip_addr >> 24) & 0xFF);

    httpd_init();
    printf("Http server initialised\n");

    while (1)
    {
    }
}