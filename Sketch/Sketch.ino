
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

  if(touchRead(OffPin) < 15) {
    if(brightness != 0) {
      brightness = 0;
    } else {
      brightness = 30;
    }
  }

  if(touchRead(PresetPin1) < 15) {
    R = 256;
    G = 256;
    B = 256;
  }
  if(touchRead(PresetPin2) < 15) {
    R = 256;
    G = 100;
    B = 40;
  }
  if(touchRead(PresetPin3) < 15) {
    R = 45;
    G = 256;
    B = 220;
  }

  analogWrite(Rpin, R*brightness/100);
  analogWrite(Gpin, G*brightness/100);
  analogWrite(Bpin, B*brightness/100);

  delay(100);
}
