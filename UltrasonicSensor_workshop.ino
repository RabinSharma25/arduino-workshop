int trigPin = 12;
int echoPin = 11;
int pulseTravelTime;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);  
  pulseTravelTime = pulseIn(echoPin,HIGH); // measures the pulse in microseconds 
  delay(25);
  Serial.println(pulseTravelTime);

}
