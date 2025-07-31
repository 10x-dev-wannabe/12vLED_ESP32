
int Rpin = 18;
int Gpin = 17;
int Bpin = 16;

int UpPin = 13;
int DnPin = 12;
int OffPin =14;

int PresetPin1 = 27;
int PresetPin2 = 33;
int PresetPin3 = 32;

int brightness = 0;
int R = 0;
int G = 0;
int B = 0;

int message = 0;

int buttonPressDetect(int pin) {
  int cnt = 15;
  for(int i = 0; i < 150; i++) {
    delay(1);
    if (touchRead(pin) > 15)
      return 0;
  }
  return 1;
}

void setup() {
  Serial.begin(115200);
  Serial.println("init finished");
}


void loop() {
  if(touchRead(UpPin) < 15 && brightness < 100) {
    brightness += 1;
  }
  
  if(touchRead(DnPin) < 15 && brightness > 0) {
    brightness -= 1;
  }

  if(buttonPressDetect(OffPin))
    if(brightness != 0) {
      brightness = 0;
    } else {
      brightness = 30;
    }

  if(buttonPressDetect(PresetPin1)) {
    R = 256;
    G = 256;
    B = 256;
  }
  if(buttonPressDetect(PresetPin2)) {
    R = 256;
    G = 100;
    B = 40;
  }
  if(buttonPressDetect(PresetPin3)) {
    R = 45;
    G = 256;
    B = 220;
  }

  analogWrite(Rpin, R*brightness/100);
  analogWrite(Gpin, G*brightness/100);
  analogWrite(Bpin, B*brightness/100);

  Serial.println(touchRead(DnPin));

  delay(10);
}
