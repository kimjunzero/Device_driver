#include "main.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

//DMA
#define GPIOB_ODR 	0x40020414
#define GPIOA_ODR   0x40020404

#define LCD_DATA_PINS_MASK ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))  // D4~D7 마스크

// 명령어 정의 // Data_sheet 6page
#define CLEAR_DISPLAY   0x01
#define RETURN_HOME     0x02
#define ENTRY_MODE_SET  0x06 // 커서 이동 방향과 디스플레이 시프트 여부
#define DISPLAY_OFF     0x08
#define DISPLAY_ON      0x0C
#define FUNCTION_SET    0x28 // 4비트 모드로 설정
#define SET_CURSOR      0x80 // 커서를 특정 위치로 이동. 커서 위치 조정하려면 0x80 + addr하면 된다.

// 핀 정의
#define RS_PIN  GPIO_PIN_0  // RS → PB0
#define EN_PIN  GPIO_PIN_1  // EN → PB1
#define D4_PIN  GPIO_PIN_4  // D4 -> PA4
#define D5_PIN  GPIO_PIN_5  // D5 -> PA5
#define D6_PIN  GPIO_PIN_6  // D6 -> PA6
#define D7_PIN  GPIO_PIN_7  // D7 -> PA7


// D4 : PB4, D5 : PB5, D6 : P6, D7 : P7

// 함수 프로토타입
void lcd_send_nibble(uint8_t nibble);
void lcd1602_command(uint8_t cmd);
void lcd1602_data(uint8_t data);
void lcd_init(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd1602_string(char *str);



