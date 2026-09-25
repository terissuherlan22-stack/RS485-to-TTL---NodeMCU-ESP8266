# RS485-to-TTL with NodeMCU-ESP8266

This is a source code to communicate using NodeMCU (ESP8266) and RS485 HW-519 module with automatic flow control.

## Pin Configuration NodeMCU to RS485 HW-519:

| Pin HW-519 | Pin NodeMCU (ESP8266) | Keterangan |
| :--- | :--- | :--- |
| VCC | 5V | Sumber Daya Modul |
| GND | GND | Ground Bersama |
| TXD | GPIO 4 (D2) | SoftwareSerial RX |
| RXD | GPIO 5 (D1) | SoftwareSerial TX |
| DE / RE | - | Tidak Ada (Menggunakan HW-519 Automatic Flow Control) |
| A+ / B- | Jalur Bus | Kabel Komunikasi Diferensial RS485 |
