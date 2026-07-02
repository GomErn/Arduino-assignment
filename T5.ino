const int buzzer = 8;

// 7-segment pins (a-g)
int segPins[] = {2, 3, 4, 5, 6, 7, 9};

// Lookup table for digits 0-9
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

void showDigit(int n)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], digits[n][i]);
  }
}

void setup()
{
  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < 7; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("=== Beeping Countdown Starting ===");

  int count = 9;

  while (count >= 1)
  {
    showDigit(count);

    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);

    delay(800);

    count--;
  }

  // Show 0 and play completion tone
  showDigit(0);

  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
}

void loop()
{
  // Nothing here
}