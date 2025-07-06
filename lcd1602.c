#include "lcd1602.h"
#include "extern.h"

extern TIM_HandleTypeDef htim2;  // Timer2 사용

void i2c1602_lcd_main(void)
{
    char temp_str[16];
    char press_str[16];
    uint8_t value = 0;

    lcd_init();
    calib_data();

    while (1)
    {
        lcd_set_cursor(0, 0);
        lcd1602_string("Hello World!!!");

        lcd_set_cursor(1, 0);
        lcd1602_data(value + '0');
        value++;

        if (value > 9) value = 0;

        delay_us(500000);  // 500ms = 500,000us
    }

//    while (1)
//    {
//        uint16_t UT_raw = read_uncom_temp();
//        uint32_t UP_raw = read_uncom_press(0);  // oss = 0
//
//        if (UT_raw != 0 && UP_raw != 0)
//        {
//            float temperature = cal_temp();        // 예: 23.56
//            float pressure_atm = cal_preass(0);    // 예: 1.013
//
//            //  float → 정수 변환 후 문자열 조립
//            int temp_i = (int)(temperature * 100);    // 2356
//            int press_i = (int)(pressure_atm * 1000); // 1013
//
//            //  직접 소수점 나누기
//            int temp_whole = temp_i / 100;
//            int temp_frac = temp_i % 100;
//
//            int press_whole = press_i / 1000;
//            int press_frac = press_i % 1000;
//
//            //  float 포맷 없이 출력
//            snprintf(temp_str, sizeof(temp_str), "Temp:%2d.%02dC", temp_whole, temp_frac);
//            snprintf(press_str, sizeof(press_str), "Pres:%1d.%03datm", press_whole, press_frac);
//
//            lcd_set_cursor(0, 0);
//            lcd1602_string(temp_str);
//
//            lcd_set_cursor(1, 0);
//            lcd1602_string(press_str);
//        }
//        else
//        {
//            lcd_set_cursor(0, 0);
//            lcd1602_string(" I2C Timeout   ");
//        }
//
//        HAL_Delay(1000);
//    }
}


// 내부 함수: 4비트 전송
void lcd_send_nibble(uint8_t nibble)
{
    // 1. 데이터 설정
	GPIOA->ODR &= ~LCD_DATA_PINS_MASK;             // D4~D7 클리어
	GPIOA->ODR |= (nibble & 0x0F) << 4;             // nibble의 하위 4비트를 PA4~PA7에 세팅

    // 2. 데이터 셋업 타임 (T_DSW ≥ 40ns)
    delay_us(1);  // 1us = 1000ns → 40ns보다 훨씬 충분함

    // 3~4. Enable 펄스
    //HAL_GPIO_WritePin(GPIOB, EN_PIN, 1);
    GPIOB->ODR |= EN_PIN;
    delay_us(1);  // TPW ≥ 140ns → 1us로 충분

    // 5. Enable 하강
    //HAL_GPIO_WritePin(GPIOB, EN_PIN, 0);
    GPIOB->ODR &= ~EN_PIN;

    // 6. 데이터 홀드 타임 (T_H ≥ 10ns)
    delay_us(1);  // 1us = 1000ns → 10ns보다 충분
}

// 명령어 전송
void lcd1602_command(uint8_t cmd)
{
    //HAL_GPIO_WritePin(GPIOB, RS_PIN, 0);   // RS = 0 → 명령 모드
    GPIOB->ODR &= ~RS_PIN;
    lcd_send_nibble(cmd >> 4);             // 상위 4비트 먼저 전송
    lcd_send_nibble(cmd & 0x0F);           // 하위 4비트 전송
    delay_us(2000);                        // 명령 처리 시간 보장 (2ms)
}


// 데이터 전송
void lcd1602_data(uint8_t data)
{
    // HAL_GPIO_WritePin(GPIOB, RS_PIN, 1);   // RS = 1 → 데이터 모드
    GPIOB->ODR |= RS_PIN;
    lcd_send_nibble(data >> 4);            // 상위 4비트 전송
    lcd_send_nibble(data & 0x0F);          // 하위 4비트 전송
    delay_us(2000);                        // 데이터 처리 시간 보장
}

// 초기화
void lcd_init(void)
{
    delay_us(50000);  // 전원 안정화 대기 (50ms)

    lcd_send_nibble(0x03); delay_us(5000);
    lcd_send_nibble(0x03); delay_us(5000);
    lcd_send_nibble(0x03); delay_us(5000);
    lcd_send_nibble(0x02); delay_us(5000);  // 4비트 모드 진입

    lcd1602_command(FUNCTION_SET);       // 0x28
    lcd1602_command(DISPLAY_ON);         // 0x0C
    lcd1602_command(CLEAR_DISPLAY);      // 0x01
    delay_us(2000);
    lcd1602_command(ENTRY_MODE_SET);     // 0x06
}

// 커서 이동
void lcd_set_cursor(uint8_t row, uint8_t col)
{
    uint8_t addr = (row == 0) ? col : (0x40 + col);
    lcd1602_command(SET_CURSOR | addr);
}

// 문자열 출력
void lcd1602_string(char *str)
{
    while (*str)
    {
        lcd1602_data((uint8_t)(*str++));
    }
}


