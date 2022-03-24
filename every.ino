#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

const byte neopixelPin = 7;

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(110, neopixelPin, NEO_GRB + NEO_KHZ800);


const int cr = 1;
const int hi = 2;
const int sn = 3;
const int ki = 4;
const int t3 = 5;
const int ri = 6;
const int t2 = 7;
const int t1 = 8;
const int tset  = 9;
const int khi = 10;
const int snt3 = 11;
const int br = 12;
const int crki = 13;
const int snri = 14;
const int kiri = 15;
const int start = 16;
const int three = 17;
const int two = 18;
const int one = 19;


const int scaleval[19] = {cr, hi, sn, ki, t3, ri, t2, t1, tset, khi, snt3, crki, snri, kiri, start, three, two, one};
//멜로디
const int melody[] = {
   start, br, br, br, br, three, two, one,
   ki, hi, ki, sn,
   ki, hi, ki, sn,
   ki, hi, ki, sn,
   ki, hi, ki, sn,
   ki, hi, ki, sn,
   ki, hi, ki, sn,
   ki, hi, ki, sn,
   ki, hi, ki, sn,
   khi, hi, khi, tset,
   khi, hi, khi, tset,
   khi, hi, khi, tset,
   br, snt3, snt3, snt3, snt3, sn, sn, t1,
   crki, hi, hi, hi, khi, hi, tset, hi,
   khi, hi, hi, hi, khi, hi, tset, hi,
   khi, hi, hi, hi, khi, hi, tset, hi,
   khi, hi, hi, hi, khi, hi, tset, hi, hi,
   crki, hi, hi, hi, khi, hi, tset, hi,
   khi, hi, hi, hi, khi, hi, tset, hi,
   khi, hi, hi, hi, khi, hi, tset, hi,
   khi, hi, hi, hi, tset, crki, br
};
//음길이
const int noteDurations[] ={
  1, 1, 1, 4, 4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  8, 8, 8, 8, 4, 16, 16, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 16, 16, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 4
};

void setup()
{
  pinMode(4, INPUT);
  neopixel.begin();
}

void loop()
{
  //if(digitalRead(4) == true){
    for (int i = 0; i < 300; i++)
    {
        int Durations = 60.0 / 67 * (4000 / noteDurations[i]);    // 음계의 음길이 계산
        nepixelbar(melody[i]);
        int pauseBetweenNotes = Durations;
        delay(pauseBetweenNotes - 50);
        neopixel.clear();
    }
  //}
}

void bk(){
  for(int i = 0; i <= 110; i++)
       neopixel.setPixelColor(i, 0, 0, 0);
     neopixel.show();
     delay(50);
}

void nepixelbar(int soundval)
{
  if (soundval == start){
       bk();
       for(int i = 0; i <= 110; i++){
         neopixel.setPixelColor(i, 255, 0, 0);
       }
        neopixel.show();

    }
    else if (soundval == three){
       bk();
       for(int i = 27; i <= 43; i++){
         neopixel.setPixelColor(i, 255, 0, 0);
       }
       for(int i = 80; i <= 110; i++){
         neopixel.setPixelColor(i, 255, 0, 0);
       }
        neopixel.show();

    }
    else if (soundval == two){
       bk();
       for(int i = 27; i <= 43; i++){
         neopixel.setPixelColor(i, 0, 255, 0);
       }
       for(int i = 95; i <= 110; i++){
         neopixel.setPixelColor(i, 0, 255, 0);
       }
        neopixel.show();

    }
    else if (soundval == one){
       bk();
       for(int i = 27; i <= 43 ; i++){
         neopixel.setPixelColor(i, 0, 0, 255);
       }
        neopixel.show();

    }
    
    else if (soundval == cr)
     {  
        bk();
        for(int i = 0; i <= 12; i++){
        neopixel.setPixelColor(i, 146, 83, 235);
      }        
        neopixel.show();
           
    } else if(soundval == br){

      bk();

      for(int i = 0; i <= 110; i++)
        neopixel.setPixelColor(i, 0, 0, 0);
      neopixel.show();
    }
    
    else if (soundval == hi)
    {
      bk();
      for(int i = 13; i <= 26; i++){
        neopixel.setPixelColor(i, 255, 0, 0);
      }

        neopixel.show();
    }
    else if (soundval == sn)
    {
      
      bk();
      for(int i = 27; i <= 43; i++){
        neopixel.setPixelColor(i, 255, 80, 0);
      }
      
        neopixel.show();
    }
    else if(soundval == ki){
        bk();
        neopixel.setPixelColor(44, 255, 255, 255);
        neopixel.setPixelColor(45, 255, 100, 0);
        neopixel.setPixelColor(46, 255, 195, 70);
        neopixel.setPixelColor(47, 100, 100, 200);
        neopixel.setPixelColor(48, 0, 150, 255);

        neopixel.show();

    }
    else if (soundval == t3)
    {
      bk();
      for(int i = 49; i <= 65; i++){
        neopixel.setPixelColor(i, 255, 246, 18);
      }

        neopixel.show();
    }

    else if (soundval == ri)
    {
      bk();
      for(int i = 66; i <= 79; i++){
        neopixel.setPixelColor(i, 29, 219, 22);
      }
  
        neopixel.show();
    }

    else if (soundval == t2)
    {
        bk();
        for(int i = 80; i <= 94; i++){
        neopixel.setPixelColor(i, 0, 216, 255);
      }

        neopixel.show();
    }
    else if (soundval == t1)
    {
        bk();
        for(int i = 95; i <= 110; i++){
        neopixel.setPixelColor(i, 1, 0, 255);
      }

        neopixel.show();
    }
    else if (soundval == tset){
       bk();
       for(int i = 13; i <= 43; i++){
         neopixel.setPixelColor(i, 0, 129, 0);
       }
        
        neopixel.show();

    }else if (soundval == khi){
       bk();
       for(int i = 13; i <= 26; i++){
         neopixel.setPixelColor(i, 0, 0, 183);
       }
       for(int i = 44; i <= 48; i++){
         neopixel.setPixelColor(i, 0, 0, 183);
       }
        
        neopixel.show();

    }
    else if (soundval == snt3){
       bk();
       for(int i = 27; i <= 43; i++){
         neopixel.setPixelColor(i, 153, 0, 76);
       }
       for(int i = 49; i <= 65; i++){
         neopixel.setPixelColor(i, 153, 0, 76);
       }
        
        neopixel.show();

    }
    else if (soundval == crki){
       bk();
       for(int i = 0; i <= 12; i++){
         neopixel.setPixelColor(i, 255, 255, 126);
       }
       for(int i = 44; i <= 48; i++){
         neopixel.setPixelColor(i, 255, 255, 126);
       }
        
        neopixel.show();

    }
    else if (soundval == snri){
       bk();
       for(int i = 27; i <= 43; i++){
         neopixel.setPixelColor(i, 0, 255, 255);
       }
       for(int i = 66; i <= 79; i++){
         neopixel.setPixelColor(i, 0, 255, 126);
       }
        
        neopixel.show();

    }

    else if (soundval == kiri){
       bk();
       for(int i = 44; i <= 48; i++){
         neopixel.setPixelColor(i, 255, 0, 0);
       }
       for(int i = 66; i <= 79; i++){
         neopixel.setPixelColor(i, 255, 0, 0);
       }
        
        neopixel.show();

    }
}
