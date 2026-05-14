#include <Arduino.h>
const int potPin = 34;   // Pin Analog untuk Potensiometer
const int ledPin = 2;    // Pin LED internal atau eksternal
const int threshold = 3000; // Ambang batas "tekanan tinggi"

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Serial.println("--- Sistem Monitor Pneumatik Dimulai ---");
}

void loop() {
  // Membaca nilai analog (0 - 4095)
  int potValue = analogRead(potPin);
  
  // Konversi nilai analog ke simulasi satuan tekanan (misal: 0 - 100 PSI)
  float pressure = (potValue / 4095.0) * 100.0;

  // Menampilkan data ke Serial Monitor
  Serial.print("Raw Value: ");
  Serial.print(potValue);
  Serial.print(" | Estimasi Tekanan: ");
  Serial.print(pressure);
  Serial.println(" PSI");

  // Logika Peringatan (Alarm)
  if (potValue > threshold) {
    digitalWrite(ledPin, HIGH); // Nyalakan LED jika tekanan terlalu tinggi
    Serial.println("⚠️ PERINGATAN: Tekanan Berlebih!");
  } else {
    digitalWrite(ledPin, LOW);  // Matikan LED jika normal
  }

  delay(200); // Jeda pembacaan 0.2 detik
}