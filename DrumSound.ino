int pinAssignments[8] = {'A0','A1','A2','A3','A4','A5','A6','A7'};
int PadNote[8] = {40, 47, 45, 41, 51, 49, 42, 35};
int PadCutOff[8] = {600, 600, 600, 600, 600, 600, 600, 600};
int MaxPlayTime[8] = {30, 30, 30, 30, 30, 30, 30, 30};
boolean VelocityFlag  = true;

boolean activePad[8] = {0,0,0,0,0,0,0,0};
int PinPlayTime[8] = {0,0,0,0,0,0,0,0};     
int hitavg = 0;
const int a = 8;

void setup() {
  pinMode(14, INPUT);
  Serial.begin(115200);
}

void loop() {
  for(int pin = 0; pin < 8; pin++){
    hitavg = analogRead(pin);
    if(hitavg > PadCutOff[pin]){
      if(activePad[pin] == false){
        MIDI_TX(PadNote[pin],127);
        PinPlayTime[pin] = 0;
       // activePad[pin] = true;
      }
      else PinPlayTime[pin]++;
    }
    else if((activePad[pin] == true)) {
      PinPlayTime[pin]++;
      if(PinPlayTime[pin] > MaxPlayTime[pin]){
      activePad[pin] = false;
      MIDI_TX(PadNote[pin],127);
      }
    }
  }
}

void MIDI_TX(int PITCH, int VELOCITY) 
{
  Serial.write(0x90 | 9);
  Serial.write(PITCH);
  Serial.write(VELOCITY);
}
