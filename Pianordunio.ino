const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600); // Bilgisayar ile iletişim hızı
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Sadece 2cm ile 100cm arasını ciddiye al
  if (distance > 2 && distance <= 100) {
    Serial.println(distance); // Mesafeyi gönder
  }
  
  delay(50); // Hızlı tepki için bekleme süresini azalttık
}
