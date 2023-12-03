//int inputValue = 0;

// connect 4 leds to pins 8,9,10,11
int val = 0;
String toString = "";

const int ledPin0 = 8;
const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  val = takeInput();
  if (val) {
    Serial.print("Received Integer: ");
    Serial.println(val);
    toString = convertToBinary(val);
    ledCounter(toString);
  }
}

int takeInput() {
  //  int inputValue;
  // Wait until a valid integer is received
  while (!Serial.available()) { // the Serial.available() returns 0 when no data is available
    delay(10);
  }

  // Read the integer from the Serial input
  int inputValue = Serial.parseInt();
  // Print the received integ
  if (inputValue < 0 || inputValue > 15) {
    Serial.println("Invalid input");
    return 0 ;
  }

  //  delay(1000);
  return inputValue;

}

String convertToBinary(int value) {
  String binaryString = "";

  // Convert the integer to a 4-digit binary string
  for (int i = 3; i >= 0; i--) {
    int bit = (value >> i) & 1;
    binaryString += String(bit);
  }

  // Print the result
  Serial.print("Binary representation of ");
  Serial.print(value);
  Serial.print(" is ");
  Serial.println(binaryString);
  return binaryString;
}


void ledCounter(String bin) {
  digitalWrite(ledPin0, LOW);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  if (bin[0] == '1') {
    digitalWrite(ledPin0, HIGH);
//    Serial.print("high ");
  }

  if (bin[1] == '1') {
    digitalWrite(ledPin1, HIGH);
//    Serial.print("high ");
  }

  if (bin[2] == '1') {
    digitalWrite(ledPin2, HIGH);
//    Serial.print("high ");
  }

  if (bin[3] == '1') {
    digitalWrite(ledPin3, HIGH);
//    Serial.println("high");
  }

}