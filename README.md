대한상공회의소 AI 시스템 반도체 SW 개발자 과정

STM32를 활용하여 Data Sheet보고 Device Driver 구현하기

재작기간 : 2025-3-4 ~ 2025-3-7

--------------------------------------------

1. bmp180 driver
2. lcd1602 driver
3. dht11/ds1302/shift-register-dotmetric 연동

--------------------------------------------

1. **bmp180 driver**
- I2C 프로토콜 방식으로 동작하는 센서(기압, 온도)
- 무응답시 Timeout 처리 기능
- 오실로스코프 동작 파형 분석

<img width="633" alt="회로도" src="https://github.com/user-attachments/assets/a65c8cc8-ad21-4f3e-a1ec-ab5c6eba48d1" />

[컴포트1.mp4](attachment:2df1bd59-0956-465c-b0ed-93046db5a5e1:컴포트1.mp4)

- 응답 타임 시간이 지나서 타임 아웃 발생

[컴포트2.mp4](attachment:4ac79902-a187-4aa4-8ace-ad100195a682:컴포트2.mp4)

- 온도, 기압 측정 결과

1. **lcd1602**
- 4bit(4개의 DATA라인을 이용하여 lcd1602제어)
- line1 : Hello world!!!, line2 : 숫자 증가

- 출력 결과

![image.png](attachment:9486aead-fec4-451d-9666-5a84e62bdcdf:image.png)

1. **dht11/ds1302/shift-register-dotmetric 연동**
- 데이터시트보고 coding하기

- dht11

![image.png](attachment:a4134d7e-d614-4c6a-90e2-de05ba17eed5:image.png)

- ds1302

![image.png](attachment:f717078f-50da-4825-a710-4af7d06ffaf5:image.png)

- shiftregister - dotmatrix

![image.png](attachment:9186a69e-81e6-4947-b47c-f52c3ee38adb:image.png)
