#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_AZUL 11
#define LED_VERMELHO 12
#define LED_VERDE 13
#define BOTAO 5

volatile bool leds_ligados = false; 
alarm_id_t alarm_id;

// Callback para desligar os LEDs em sequência
int64_t desligar_leds_callback(alarm_id_t id, void *user_data) {
    static int estado = 0;

    if (estado == 0) {
        gpio_put(LED_AZUL, 0);
        estado++;
        alarm_id = add_alarm_in_ms(3000, desligar_leds_callback, NULL, false);
    } else if (estado == 1) {
        gpio_put(LED_VERMELHO, 0);
        estado++;
        alarm_id = add_alarm_in_ms(3000, desligar_leds_callback, NULL, false);
    } else if (estado == 2) {
        gpio_put(LED_VERDE, 0);
        estado = 0;
        leds_ligados = false; // Permite nova ativação do botão
    }
    return 0;
}

// Callback do botão
void botao_callback(uint gpio, uint32_t events) {
    if (!leds_ligados) {
        leds_ligados = true;
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
        add_alarm_in_ms(3000, desligar_leds_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Configura LEDs
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    
    // Configura botão
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_RISE, true, &botao_callback);


    while (true) {
        if (!leds_ligados) {
            printf("Aguardando clique no botão...\n");
        }
        sleep_ms(1000);
    }
}
