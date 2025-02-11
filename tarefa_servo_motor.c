#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// CONFIGURAÇÕES PARA O PWM
#define PERIODO_LIMITE 10000 // Valor máximo do contador do PWM
#define DIVISOR_PWM 250.0f // Divisor do clock do PWM
// Definição do pino do servo motor
uint8_t PINO_SERVO=22;

// Função para inicializar o PWM no pino do servo
void configurar_pwm()
{
    gpio_set_function(PINO_SERVO, GPIO_FUNC_PWM); // Configura o pino como saída PWM

    uint canal_pwm = pwm_gpio_to_slice_num(PINO_SERVO); // Obtém o canal PWM correspondente
    pwm_set_wrap(canal_pwm, PERIODO_LIMITE); // Define o valor máximo do contador PWM
    pwm_set_clkdiv(canal_pwm, DIVISOR_PWM); // Define a divisão do clock para PWM
    pwm_set_enabled(canal_pwm, true); // Ativa o PWM
}

void definir_nivel_pwm(uint16_t nivel_duty){
  uint canal_pwm = pwm_gpio_to_slice_num(PINO_SERVO);
  pwm_set_gpio_level(PINO_SERVO, nivel_duty);
}

void mover_servo_0_180(){
  // Gira o servo motor de 0° a 180°
  for(uint16_t passo=500; passo<=2400; passo+=5){
    definir_nivel_pwm(passo);
    sleep_ms(10);
  }
}

void mover_servo_180_0(){
  // Retorna o servo motor de 180° a 0°
  for(uint16_t passo=2400; passo>=500; passo-=5){
    definir_nivel_pwm(passo);
    sleep_ms(5);
  }
}

int main()
{
    stdio_init_all();
    configurar_pwm();

    sleep_ms(200);
    definir_nivel_pwm(2400);
    sleep_ms(2000);
    definir_nivel_pwm(1470);
    sleep_ms(2000);
    definir_nivel_pwm(500);
    sleep_ms(2000);
    
    while (true) {
      printf("Iniciando nova movimentação do servo\n");
      mover_servo_0_180();
      mover_servo_180_0();
      sleep_ms(2000);
    }
}
