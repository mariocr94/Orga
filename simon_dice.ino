const int MAX_LEVEL = 100;
int sequence[MAX_LEVEL];
int your_sequence[MAX_LEVEL];
int level = 1;
 
int velocity = 1000;
 
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  Serial.begin(9600);
}
 
void loop() 
{
  if (level == 1)
    generate_sequence();
 
  if (digitalRead(A4) == HIGH || level != 1)
  {
    show_sequence();    
    get_sequence();     
  }
}
 
void show_sequence()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
 
  for (int i = 0; i < level; i++)
  {
    digitalWrite(sequence[i], HIGH);
    Serial.write(sequence[i]);
    delay(velocity);
    Serial.write(0);
    digitalWrite(sequence[i], LOW);
    delay(200);
  }
}
 
void get_sequence()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.write(8);
  delay(500);
  int flag = 0;

  for (int i = 0; i < level; i++)
  {
    flag = 0;
    while(flag == 0)
    {
      if (digitalRead(A0) == HIGH)
      {
        digitalWrite(5, HIGH);
        Serial.write(9);
        your_sequence[i] = 5;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i])
        {
          wrong_sequence();
          return;
        }
        digitalWrite(5, LOW);
        Serial.write(0);
      }
 
      if (digitalRead(A1) == HIGH)
      {
        digitalWrite(4, HIGH);
        Serial.write(10);
        your_sequence[i] = 4;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i])
        {
          wrong_sequence();
          return;
        }
        digitalWrite(4, LOW);
        Serial.write(0);
      }
 
      if (digitalRead(A2) == HIGH)
      {
        digitalWrite(3, HIGH);
        Serial.write(11);
        your_sequence[i] = 3;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i])
        {
          wrong_sequence();
          return;
        }
        digitalWrite(3, LOW);
        Serial.write(0);
      }
 
      if (digitalRead(A3) == HIGH)
      {
        digitalWrite(2, HIGH);
        Serial.write(12);
        your_sequence[i] = 2;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i])
        {
          wrong_sequence();
          return;
        }
        digitalWrite(2, LOW);
        Serial.write(0);
      }
 
    }
  }
  right_sequence();
}
 
void generate_sequence()
{
  randomSeed(millis());
 
  for (int i = 0; i < MAX_LEVEL; i++)
  {
    sequence[i] = random(2,6);
  }
}
void wrong_sequence()
{
  Serial.write(6);
  for (int i = 0; i < 3; i++)
  {
    
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(250);
  }
  level = 1;
  velocity = 1000;
  Serial.write(0);
}
 
void right_sequence()
{
  Serial.write(7);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(250);
 
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(500);
 
  if (level < MAX_LEVEL);
  level++;
  Serial.write(0);
  velocity -= 50; 
}
