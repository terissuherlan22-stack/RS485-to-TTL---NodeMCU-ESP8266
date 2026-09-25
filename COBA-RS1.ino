#include <SoftwareSerial.h>

// Definisikan pin SoftwareSerial untuk ESP8266 (RX, TX)
// RX NodeMCU ke TXD HW-519 (GPIO 4 / D2)
// TX NodeMCU ke RXD HW-519 (GPIO 5 / D1)
SoftwareSerial rs485(4, 5); 

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Inisialisasi komunikasi RS485 (Baudrate 9600)
  rs485.begin(9600);

  Serial.println("\nNodeMCU RS485 (HW-519 Auto-Flow) Siap!");
  Serial.println("Ketik pesan di Serial Monitor untuk dikirim.");
}

void loop() {
  // 1. MENERIMA PESAN DARI KABEL RS485
  if (rs485.available()) {
    String dataMasuk = "";
    while (rs485.available()) {
      dataMasuk += char(rs485.read());
      delay(2);
    }
    if (dataMasuk.length() > 0) {
      Serial.print("[Terima RS485]: ");
      Serial.println(dataMasuk);
    }
  }

  // 2. MENGIRIM PESAN DARI SERIAL MONITOR KE KABEL RS485
  if (Serial.available() > 0) {
    String pesanKirim = Serial.readStringUntil('\n');
    pesanKirim.trim();

    if (pesanKirim.length() > 0) {
      // Karena HW-519 otomatis, langsung print saja ke rs485!
      rs485.print(pesanKirim);
      rs485.flush();
      
      Serial.print("[Kirim Berhasil]: ");
      Serial.println(pesanKirim);
    }
  }
}