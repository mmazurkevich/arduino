String val;
int IN1 = 14;
int IN3 = 15;
int EN1 = 16;
int IN2 = 19;
int IN4 = 18;
int EN2 = 17;
int carSpeed = 0;
int carDelay = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.readString();
    if (val.length() > 1) 
    {
      String firstValue = getValue(val, '/', 0);
      String secondValue = getValue(val, '/', 1);

      Serial.println("1:" + firstValue);
      Serial.print("2:" + secondValue);
      carSpeed = firstValue.toInt();
      carDelay = secondValue.toInt();
    } 
    else 
    {
      Serial.println("Device speed: " + carSpeed); 
      Serial.println("Move delay : " + carDelay); 
    if (val.equals("W")) // При получении символа "W" движемся вперед
    {
      Serial.println("Got UP signal");
      digitalWrite(IN1, HIGH);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN2, HIGH);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }
    if (val.equals("S")) // При получении символа "S" движемся назад
    {
      Serial.println("Got DOWN signal");
      digitalWrite(IN3, HIGH);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN4, HIGH);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }
    if (val.equals("A")){ // При получении символа "A" движемся влево
      Serial.println("Got LEFT signal");
      digitalWrite(IN1, LOW);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN2, HIGH);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(IN2, LOW);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }
    if (val.equals("D")){ // При получении символа "D" движемся вправо
      Serial.println("Got RIGHT signal");
      digitalWrite(IN1, HIGH);
      analogWrite(EN1, carSpeed);
      digitalWrite(IN2, LOW);
      analogWrite(EN2, carSpeed);
      delay(carDelay);
      digitalWrite(IN1, LOW);
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
    }    
    }
  }
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}