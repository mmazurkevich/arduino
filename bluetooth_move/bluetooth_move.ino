#define enA 16
#define in1 14
#define in2 15
#define enB 17
#define in3 19
#define in4 18
unsigned int  x = 0;
unsigned int  y = 0;



void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);    
}
void loop() {
    if(Serial.available()){
        int motorSpeedA = 0;
        int motorSpeedB = 0;
        x = 0;
        y = 0;
        x = Serial.read();
        delay(10);
        y = Serial.read();
        delay(10);
        Serial.println(x);
        Serial.println(y);
        Serial.println("-------------");

        if (y > 0) {
          motorSpeedA = 128;
          motorSpeedB = 128;
        }
        if (y > 60000) {
          motorSpeedA = 0;
          motorSpeedB = 0;
        }
        if (x >=0 && x <= 90) {
          // Set Motor A forward
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          // Set Motor B forward
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
        }
        if (x > 90 && x <= 180) {
           // Set Motor A backward
           digitalWrite(in1, HIGH);
           digitalWrite(in2, LOW);
           // Set Motor B backward
           digitalWrite(in3, HIGH);
           digitalWrite(in4, LOW);
        }

        if (x > 0 && x < 35) {
          motorSpeedA = 128;
          motorSpeedB = 0;
        } else if (x >= 55 && x < 90) {
          motorSpeedA = 0;
          motorSpeedB = 128;
        } else if (x >= 90 && x < 125) {
          motorSpeedA = 0;
          motorSpeedB = 128;
        } else if (x >= 155 && x < 180) {
          motorSpeedA = 128;
          motorSpeedB = 0;        
        }
        analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
        analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    } 
}
