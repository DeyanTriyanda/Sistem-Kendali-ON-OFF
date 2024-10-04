// Deklarasi pin
int sensorPin = A0;  // Pin analog untuk sensor kelembaban tanah
int relayPin = 3;    // Pin digital untuk relay
int adc = 0;  // Variabel untuk menyimpan nilai kelembaban

void setup() {
  pinMode(relayPin, OUTPUT);  // Set relay sebagai output
  Serial.begin(9600);         // Memulai komunikasi serial untuk debugging
}

void loop() {
  // Baca nilai kelembaban tanah dari sensor (0 - 1023)
  adc = analogRead(sensorPin);
  float kelembaban = map(adc, 250, 772, 100, 0);
  Serial.print("adc: ");
  Serial.println(adc);
  Serial.print("kelembaban: ");
  Serial.println(kelembaban);

  
  // Cek apakah kelembaban di bawah threshold (misalnya 600)
  if (kelembaban < 70) {
    digitalWrite(relayPin, LOW);  // Nyalakan pompa air
    Serial.println("Pompa Menyala");
  } else {
    digitalWrite(relayPin, HIGH);  // Matikan pompa air
    Serial.println("Pompa Mati");
  }

  delay(1000);  // Tunggu 2 detik sebelum pembacaan berikutnya
}
