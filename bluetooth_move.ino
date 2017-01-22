int val;
int IN1 = 14;
int EN1 = 16;
int IN2 = 19;
int EN2 = 17;
int carSpeed = 0;
int carDelay = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    if (val == 'A')
    {
       carSpeed = 100;
       carDelay = 100;
    }
    if (val == 'B')
    {
       carSpeed = 150;
       carDelay = 100;
    }
    if (val == 'C')
    {
       carSpeed = 200;
       carDelay = 300;
    }
    if (val == 'D')
    {
       carSpeed = 250;
       carDelay = 400;
    }
    if (val == '0') // При получении символа "W" движемся вперед
    {
      digitalWrite(IN1, HIGH);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN2, HIGH);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }
    if (val == '1') // При получении символа "S" движемся назад
    {
      digitalWrite(IN1, LOW);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN2, LOW);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }
    if (val == '2'){ // При получении символа "A" движемся влево
      digitalWrite(IN1, HIGH);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN2, LOW);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }
    if (val == '3'){ // При получении символа "D" движемся вправо
      digitalWrite(IN1, LOW);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN2, HIGH);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }    
  }
}
