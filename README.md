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

https://github.com/user-attachments/assets/9c5365a5-10bc-4802-ae84-8b0e3f23330b

- 응답 타임 시간이 지나서 타임 아웃 발생

https://github.com/user-attachments/assets/784c3822-9ddd-4e44-90f1-350b8195c0e1

- 온도, 기압 측정 결과

1. **lcd1602**
- 4bit(4개의 DATA라인을 이용하여 lcd1602제어)
- line1 : Hello world!!!, line2 : 숫자 증가

- 출력 결과

<img width="334" alt="헬로" src="https://github.com/user-attachments/assets/f833f2e7-e4fd-4508-aa74-608baed234e7" />

1. **dht11/ds1302/shift-register-dotmetric 연동**
- 데이터시트보고 coding하기

- dht11

<img width="625" alt="1" src="https://github.com/user-attachments/assets/9145c060-3d49-45df-9e69-e11f6a31cf8a" />

- ds1302

<img width="629" alt="2" src="https://github.com/user-attachments/assets/53ab1cf8-0a5e-40af-8367-08a9bb4bce60" />


- shiftregister - dotmatrix

<img width="621" alt="3" src="https://github.com/user-attachments/assets/2d07971e-0596-484c-93d5-56d9f4de4eb7" />

