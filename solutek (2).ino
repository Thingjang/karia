//************
//Sound Level to light show sketch for the
//autogain microphone Amplifier from Adafruit on pin AO
//plus neopixel led functions (pin 6) mapped on to different sound levels to give music to light effects
//
//*************

//lines below set variables for neopixels

#include <Adafruit_NeoPixel.h>
#define arduino.h
#define NUMBER_PIXEL 60
#define LEDPIN    6


Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_PIXEL, LEDPIN, NEO_GRB + NEO_KHZ800);

int lng = 100;//long delay
int sht = 50;//short delay

//lines below are for the microphone sampling from Adafruit autogain mic

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup()
{
  strip.begin();//initialises neopixels
  strip.setBrightness(255);// set brightness from 0 to max is 255
  strip.show();//clears any previous data in the strip
  Serial.begin(9600);//set up for checking mic is working
}


void loop()
{
  //open void loop
  //first run the sound sampling
  unsigned long startMillis = millis(); // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    //open while loop
    sample = analogRead(0);
    if (sample < 1024)  // toss out spurious readings
    {
      //open 1st if + in while
      if (sample > signalMax)
      {
        //open 2nd if
        signalMax = sample;  // save just the max levels
      }//close 2nd if
      else if (sample < signalMin)
      {
        //open 3rd if
        signalMin = sample;  // save just the min levels
      }//close 3rd if
    }//close 1st if
  }//close while loop
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 3.3) / 1024;  // convert to volts

//section below maps the signal from the microphone on to 12 options for LED effects

  int sound = (volts * 10);

  int soundLevel = map(sound, 1, 10, 0, 11);
  Serial.print("The volt level is  ");
  Serial.println(volts);//for debugging

//next section is a series of 12 (0-11) 'if' statements which trigger different patterns.
//it is a combination of a traditional VU style meter fill of the strip
// combined with randomised animated patterns to keep it interesting
  if (soundLevel == 0)
  {
    //open if 0. When there is silence a rainbow pattern runs

    rainbowCycle(3);//from the neopixel library

  }//close if 0 statement


  if (soundLevel == 1)
  {
    //open level 1 if statement which contains 4 randomised options

    int level1Color = random(1, 4);//choose random number 1 - 4

    if (level1Color == 1) //if random no 1 chosen light up pixels 1 and 2 red:
    {

      strip.setPixelColor(0, 255, 0, 0); // this turns on pixel 1 100% red (range runs 0 - 255) and leaves green and blue off
      strip.setPixelColor(1, 255, 0, 0); //  - you get the idea
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 0, 0);  
      strip.setPixelColor(5, 255, 0, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 255, 0, 0);  
      strip.setPixelColor(8, 255, 0, 0);  
      strip.setPixelColor(9, 255, 0, 0);  
      strip.setPixelColor(10, 255, 0, 0);  
      strip.setPixelColor(11, 255, 0, 0); 
       strip.setPixelColor(12, 255, 0, 0); // this turns on pixel 1 100% red (range runs 0 - 255) and leaves green and blue off
      strip.setPixelColor(13, 255, 0, 0); //  - you get the idea
      strip.setPixelColor(14, 255, 0, 0);  
      strip.setPixelColor(15, 255, 0, 0);  
      strip.setPixelColor(16, 255, 0, 0);  
      strip.setPixelColor(17, 255, 0, 0);  
      strip.setPixelColor(18, 255, 0, 0);  
      strip.setPixelColor(19, 255, 0, 0);  
      strip.setPixelColor(20, 255, 0, 0);  
      strip.setPixelColor(21, 255, 0, 0);  
      strip.setPixelColor(22, 255, 0, 0);  
      strip.setPixelColor(23, 255, 0, 0);  
       strip.setPixelColor(24, 255, 0, 0); // this turns on pixel 1 100% red (range runs 0 - 255) and leaves green and blue off
      strip.setPixelColor(25, 255, 0, 0); //  - you get the idea
      strip.setPixelColor(26, 255, 0, 0);  
      strip.setPixelColor(27, 255, 0, 0);  
      strip.setPixelColor(28, 255, 0, 0);  
      strip.setPixelColor(29, 255, 0, 0);  
      strip.setPixelColor(30, 255, 0, 0);  
      strip.setPixelColor(31, 255, 0, 0);  
      strip.setPixelColor(32, 255, 0, 0);  
      strip.setPixelColor(33, 255, 0, 0);  
      strip.setPixelColor(34, 255, 0, 0);  
      strip.setPixelColor(35, 255, 0, 0); 
       strip.setPixelColor(36, 255, 0, 0); // this turns on pixel 1 100% red (range runs 0 - 255) and leaves green and blue off
      strip.setPixelColor(37, 255, 0, 0); //  - you get the idea
      strip.setPixelColor(38, 255, 0, 0);  
      strip.setPixelColor(39, 255, 0, 0);  
      strip.setPixelColor(40, 255, 0, 0);  
      strip.setPixelColor(41, 255, 0, 0);  
      strip.setPixelColor(42, 255, 0, 0);  
      strip.setPixelColor(44, 255, 0, 0);  
      strip.setPixelColor(43, 255, 0, 0);  
      strip.setPixelColor(45, 255, 0, 0);  
      strip.setPixelColor(46, 255, 0, 0);  
      strip.setPixelColor(47, 255, 0, 0);  strip.setPixelColor(0, 255, 0, 0); // this turns on pixel 1 100% red (range runs 0 - 255) and leaves green and blue off
      strip.setPixelColor(48, 255, 0, 0); //  - you get the idea
      strip.setPixelColor(49, 255, 0, 0);  
      strip.setPixelColor(50, 255, 0, 0);  
      strip.setPixelColor(51, 255, 0, 0);  
      strip.setPixelColor(52, 255, 0, 0);  
      strip.setPixelColor(53, 255, 0, 0);  
      strip.setPixelColor(54, 255, 0, 0);  
      strip.setPixelColor(55, 255, 0, 0);  
      strip.setPixelColor(56, 255, 0, 0);  
      strip.setPixelColor(57, 255, 0, 0);  
      strip.setPixelColor(58, 255, 0, 0); 
      strip.show();
      delay(lng);
    }//close red random no. 1

    else if (level1Color == 2) //if random no 2 choses show green
    {
      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 255, 0);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 255, 0);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 255, 0);  
      strip.setPixelColor(8, 0, 255, 0);  
      strip.setPixelColor(9, 0, 255, 0);  
      strip.setPixelColor(10, 0, 255, 0);  
      strip.setPixelColor(11, 0, 255, 0); 
      strip.setPixelColor(12, 0, 255, 0);  
      strip.setPixelColor(13, 0, 255, 0);  
      strip.setPixelColor(14, 0, 255, 0);  
      strip.setPixelColor(15, 0, 255, 0);  
      strip.setPixelColor(16, 0, 255, 0);  
      strip.setPixelColor(17, 0, 255, 0);  
      strip.setPixelColor(18, 0, 255, 0);  
      strip.setPixelColor(19, 0, 255, 0);  
      strip.setPixelColor(20, 0, 255, 0);  
      strip.setPixelColor(21, 0, 255, 0);  
      strip.setPixelColor(22, 0, 255, 0);  
      strip.setPixelColor(23, 0, 255, 0); 
      strip.setPixelColor(24, 0, 255, 0);  
      strip.setPixelColor(25, 0, 255, 0);  
      strip.setPixelColor(26, 0, 255, 0);  
      strip.setPixelColor(27, 0, 255, 0);  
      strip.setPixelColor(28, 0, 255, 0);  
      strip.setPixelColor(29, 0, 255, 0);  
      strip.setPixelColor(30, 0, 255, 0);  
      strip.setPixelColor(31, 0, 255, 0);  
      strip.setPixelColor(32, 0, 255, 0);  
      strip.setPixelColor(33, 0, 255, 0);  
      strip.setPixelColor(34, 0, 255, 0);  
      strip.setPixelColor(35, 0, 255, 0); 
      strip.setPixelColor(36, 0, 255, 0);  
      strip.setPixelColor(37, 0, 255, 0);  
      strip.setPixelColor(38, 0, 255, 0);  
      strip.setPixelColor(39, 0, 255, 0);  
      strip.setPixelColor(40, 0, 255, 0);  
      strip.setPixelColor(41, 0, 255, 0);  
      strip.setPixelColor(42, 0, 255, 0);  
      strip.setPixelColor(43, 0, 255, 0);  
      strip.setPixelColor(44, 0, 255, 0);  
      strip.setPixelColor(45, 0, 255, 0);  
      strip.setPixelColor(46, 0, 255, 0);  
      strip.setPixelColor(47, 0, 255, 0); 
      strip.setPixelColor(48, 0, 255, 0);  
      strip.setPixelColor(49, 0, 255, 0);  
      strip.setPixelColor(50, 0, 255, 0);  
      strip.setPixelColor(51, 0, 255, 0);  
      strip.setPixelColor(52, 0, 255, 0);  
      strip.setPixelColor(53, 0, 255, 0);  
      strip.setPixelColor(54, 0, 255, 0);  
      strip.setPixelColor(55, 0, 255, 0);  
      strip.setPixelColor(56, 0, 255, 0);  
      strip.setPixelColor(57, 0, 255, 0);  
      strip.setPixelColor(58, 0, 255, 0);  
      strip.setPixelColor(59, 0, 255, 0); 

      strip.show();
      delay(lng);
    }//close random no. 2 green

    else if (level1Color == 3) //run blue
    {

      strip.setPixelColor(0, 0, 0, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 0, 0);  
      strip.setPixelColor(3, 0, 0, 0);  
      strip.setPixelColor(4, 0, 0, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close blue

    else if (level1Color == 4) //run yellow
    {

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 0, 0, 0);  
      strip.setPixelColor(3, 0, 0, 0);  
      strip.setPixelColor(4, 0, 0, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close yellow



  }//end of if sound level 1 options


  if (soundLevel == 2)
  {
    //open level 2

    int level2Color = random(1, 5);//choose one of 5 options if sound level 2

    if (level2Color == 1) //run red mix
    {

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 0, 0, 0);  
      strip.setPixelColor(4, 0, 0, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level2Color == 2) //run green mix
    {
      //open option 2

      strip.setPixelColor(0, 0, 206, 209);  
      strip.setPixelColor(1, 0, 206, 209);  
      strip.setPixelColor(2, 0, 206, 209);  
      strip.setPixelColor(3, 0, 0, 0);  
      strip.setPixelColor(4, 0, 0, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close green

    else if (level2Color == 3) //run blue mix
    {
      //open option 3

      strip.setPixelColor(0, 0, 0, 255);  
      strip.setPixelColor(1, 255, 0, 0);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 0, 0, 0);  
      strip.setPixelColor(4, 0, 0, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level2Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 0, 0, 0);  
      strip.setPixelColor(4, 0, 0, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close yellow

    else if (level2Color == 5)//for a bit of variation 1 in 5 of level 2 will show a pattern across whole strip:
    {
      //open if 5
      strip.setPixelColor(0, 200, 75, 109);  
      strip.setPixelColor(1, 252, 203, 198);  
      strip.setPixelColor(2, 255, 216, 209);  
      strip.setPixelColor(3, 253, 215, 130);  
      strip.setPixelColor(4, 181, 198, 130);  
      strip.setPixelColor(5, 141, 189, 193);  
      strip.setPixelColor(6, 177, 217, 242);  
      strip.setPixelColor(7, 100, 165, 187);  
      strip.setPixelColor(8, 133, 105, 128);  
      strip.setPixelColor(9, 140, 166, 95);  
      strip.setPixelColor(10, 198, 44, 58);  
      strip.setPixelColor(11, 149, 69, 103); 
       strip.setPixelColor(12, 200, 75, 109);  
      strip.setPixelColor(13, 252, 203, 198);  
      strip.setPixelColor(14, 255, 216, 209);  
      strip.setPixelColor(15, 253, 215, 130);  
      strip.setPixelColor(16, 181, 198, 130);  
      strip.setPixelColor(17, 141, 189, 193);  
      strip.setPixelColor(18, 177, 217, 242);  
      strip.setPixelColor(19, 100, 165, 187);  
      strip.setPixelColor(20, 133, 105, 128);  
      strip.setPixelColor(21, 140, 166, 95);  
      strip.setPixelColor(22, 198, 44, 58);  
      strip.setPixelColor(23, 149, 69, 103);
       strip.setPixelColor(24, 200, 75, 109);  
      strip.setPixelColor(25, 252, 203, 198);  
      strip.setPixelColor(26, 255, 216, 209);  
      strip.setPixelColor(27, 253, 215, 130);  
      strip.setPixelColor(28, 181, 198, 130);  
      strip.setPixelColor(29, 141, 189, 193);  
      strip.setPixelColor(30, 177, 217, 242);  
      strip.setPixelColor(31, 100, 165, 187);  
      strip.setPixelColor(32, 133, 105, 128);  
      strip.setPixelColor(33, 140, 166, 95);  
      strip.setPixelColor(34, 198, 44, 58);  
      strip.setPixelColor(35, 149, 69, 103);
       strip.setPixelColor(36, 200, 75, 109);  
      strip.setPixelColor(37, 252, 203, 198);  
      strip.setPixelColor(38, 255, 216, 209);  
      strip.setPixelColor(39, 253, 215, 130);  
      strip.setPixelColor(40, 181, 198, 130);  
      strip.setPixelColor(41, 141, 189, 193);  
      strip.setPixelColor(42, 177, 217, 242);  
      strip.setPixelColor(43, 100, 165, 187);  
      strip.setPixelColor(44, 133, 105, 128);  
      strip.setPixelColor(45, 140, 166, 95);  
      strip.setPixelColor(46, 198, 44, 58);  
      strip.setPixelColor(47, 149, 69, 103);
       strip.setPixelColor(48, 200, 75, 109);  
      strip.setPixelColor(49, 252, 203, 198);  
      strip.setPixelColor(50, 255, 216, 209);  
      strip.setPixelColor(51, 253, 215, 130);  
      strip.setPixelColor(52, 181, 198, 130);  
      strip.setPixelColor(53, 141, 189, 193);  
      strip.setPixelColor(54, 177, 217, 242);  
      strip.setPixelColor(55, 100, 165, 187);  
      strip.setPixelColor(56, 133, 105, 128);  
      strip.setPixelColor(57, 140, 166, 95);  
      strip.setPixelColor(58, 198, 44, 58);  
      strip.setPixelColor(59, 149, 69, 103); 


      strip.show();
      delay(lng);

      strip.setPixelColor(1, 200, 75, 109);  
      strip.setPixelColor(2, 252, 203, 198);  
      strip.setPixelColor(3, 255, 216, 209);  
      strip.setPixelColor(4, 253, 215, 130);  
      strip.setPixelColor(5, 181, 198, 130);  
      strip.setPixelColor(6, 141, 189, 193);  
      strip.setPixelColor(7, 177, 217, 242);  
      strip.setPixelColor(8, 100, 165, 187);  
      strip.setPixelColor(9, 133, 105, 128);  
      strip.setPixelColor(10, 140, 166, 95);  
      strip.setPixelColor(11, 198, 44, 58);  
      strip.setPixelColor(12, 149, 69, 103);  
      strip.setPixelColor(13, 200, 75, 109);  
      strip.setPixelColor(14, 252, 203, 198);  
      strip.setPixelColor(15, 255, 216, 209);  
      strip.setPixelColor(16, 253, 215, 130);  
      strip.setPixelColor(17, 181, 198, 130);  
      strip.setPixelColor(18, 141, 189, 193);  
      strip.setPixelColor(19, 177, 217, 242);  
      strip.setPixelColor(20, 100, 165, 187);  
      strip.setPixelColor(21, 133, 105, 128);  
      strip.setPixelColor(22, 140, 166, 95);  
      strip.setPixelColor(23, 198, 44, 58);  
      strip.setPixelColor(24, 149, 69, 103);  
strip.setPixelColor(25, 200, 75, 109);  
      strip.setPixelColor(26, 252, 203, 198);  
      strip.setPixelColor(27, 255, 216, 209);  
      strip.setPixelColor(28, 253, 215, 130);  
      strip.setPixelColor(29, 181, 198, 130);  
      strip.setPixelColor(30, 141, 189, 193);  
      strip.setPixelColor(31, 177, 217, 242);  
      strip.setPixelColor(32, 100, 165, 187);  
      strip.setPixelColor(33, 133, 105, 128);  
      strip.setPixelColor(34, 140, 166, 95);  
      strip.setPixelColor(35, 198, 44, 58);  
      strip.setPixelColor(36, 149, 69, 103);  
strip.setPixelColor(37, 200, 75, 109);  
      strip.setPixelColor(38, 252, 203, 198);  
      strip.setPixelColor(39, 255, 216, 209);  
      strip.setPixelColor(40, 253, 215, 130);  
      strip.setPixelColor(41, 181, 198, 130);  
      strip.setPixelColor(42, 141, 189, 193);  
      strip.setPixelColor(43, 177, 217, 242);  
      strip.setPixelColor(44, 100, 165, 187);  
      strip.setPixelColor(45, 133, 105, 128);  
      strip.setPixelColor(46, 140, 166, 95);  
      strip.setPixelColor(47, 198, 44, 58);  
      strip.setPixelColor(48, 149, 69, 103);  
strip.setPixelColor(49, 200, 75, 109);  
      strip.setPixelColor(50, 252, 203, 198);  
      strip.setPixelColor(51, 255, 216, 209);  
      strip.setPixelColor(52, 253, 215, 130);  
      strip.setPixelColor(53, 181, 198, 130);  
      strip.setPixelColor(54, 141, 189, 193);  
      strip.setPixelColor(55, 177, 217, 242);  
      strip.setPixelColor(56, 100, 165, 187);  
      strip.setPixelColor(57, 133, 105, 128);  
      strip.setPixelColor(58, 140, 166, 95);  
      strip.setPixelColor(59, 198, 44, 58);  
    
      


      strip.show();
      delay(lng);

    }//close of option 5
  }//close level 2

  if (soundLevel == 3)
  {
    //open if sound level 3
    int level3Color = random(1, 5);

    if (level3Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 0, 255, 0);  
      strip.setPixelColor(4, 255, 0, 0);  
      strip.setPixelColor(5, 0, 255, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 0, 255, 0);  
      strip.setPixelColor(8, 255, 0, 0);  
      strip.setPixelColor(9, 0, 255, 0);  
      strip.setPixelColor(10, 255, 0, 0);  
      strip.setPixelColor(11, 0, 255, 0);  
      
      strip.setPixelColor(12, 255, 0, 0);  
      strip.setPixelColor(13, 0, 255, 0);  
      strip.setPixelColor(14, 255, 0, 0);  
      strip.setPixelColor(15, 0, 255, 0);  
      strip.setPixelColor(16, 255, 0, 0);  
      strip.setPixelColor(17, 0, 255, 0);  
      strip.setPixelColor(28, 255, 0, 0);  
      strip.setPixelColor(19, 0, 255, 0);  
      strip.setPixelColor(20, 255, 0, 0);  
      strip.setPixelColor(21, 0, 255, 0);  
      strip.setPixelColor(22, 255, 0, 0);  
      strip.setPixelColor(23, 0, 255, 0);  
      
      strip.setPixelColor(24, 255, 0, 0);  
      strip.setPixelColor(25, 0, 255, 0);  
      strip.setPixelColor(26, 255, 0, 0);  
      strip.setPixelColor(27, 0, 255, 0);  
      strip.setPixelColor(28, 255, 0, 0);  
      strip.setPixelColor(29, 0, 255, 0);  
      strip.setPixelColor(30, 255, 0, 0);  
      strip.setPixelColor(31, 0, 255, 0);  
      strip.setPixelColor(32, 255, 0, 0);  
      strip.setPixelColor(33, 0, 255, 0);  
      strip.setPixelColor(34, 255, 0, 0);  
      strip.setPixelColor(35, 0, 255, 0);  
      
      strip.setPixelColor(36, 255, 0, 0);  
      strip.setPixelColor(37, 0, 255, 0);  
      strip.setPixelColor(38, 255, 0, 0);  
      strip.setPixelColor(39, 0, 255, 0);  
      strip.setPixelColor(40, 255, 0, 0);  
      strip.setPixelColor(41, 0, 255, 0);  
      strip.setPixelColor(42, 255, 0, 0);  
      strip.setPixelColor(43, 0, 255, 0);  
      strip.setPixelColor(44, 255, 0, 0);  
      strip.setPixelColor(45, 0, 255, 0);  
      strip.setPixelColor(46, 255, 0, 0);  
      strip.setPixelColor(47, 0, 255, 0);  
      
      strip.setPixelColor(48, 255, 0, 0);  
      strip.setPixelColor(49, 0, 255, 0);  
      strip.setPixelColor(50, 255, 0, 0);  
      strip.setPixelColor(51, 0, 255, 0);  
      strip.setPixelColor(52, 255, 0, 0);  
      strip.setPixelColor(53, 0, 255, 0);  
      strip.setPixelColor(54, 255, 0, 0);  
      strip.setPixelColor(55, 0, 255, 0);  
      strip.setPixelColor(56, 255, 0, 0);  
      strip.setPixelColor(57, 0, 255, 0);  
      strip.setPixelColor(58, 255, 0, 0);  
      strip.setPixelColor(59, 0, 255, 0);  
      
      
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level3Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 245, 116, 97);  
      strip.setPixelColor(1, 169, 221, 20);  
      strip.setPixelColor(2, 245, 116, 97);  
      strip.setPixelColor(3, 169, 221, 20);  
        strip.setPixelColor(0, 245, 116, 97);  
      strip.setPixelColor(4, 169, 221, 20);  
      strip.setPixelColor(5, 245, 116, 97);  
      strip.setPixelColor(6, 169, 221, 20);  
     
       strip.setPixelColor(7, 245, 116, 97);  
      strip.setPixelColor(8, 169, 221, 20);  
      strip.setPixelColor(9, 245, 116, 97);  
      strip.setPixelColor(10, 169, 221, 20);  
     
       strip.setPixelColor(11, 245, 116, 97);  
      strip.setPixelColor(12, 169, 221, 20);  
      strip.setPixelColor(13, 245, 116, 97);  
      strip.setPixelColor(14, 169, 221, 20);  
     
       strip.setPixelColor(15, 245, 116, 97);  
      strip.setPixelColor(16, 169, 221, 20);  
      strip.setPixelColor(17, 245, 116, 97);  
      strip.setPixelColor(18, 169, 221, 20);  
     
       strip.setPixelColor(19, 245, 116, 97);  
      strip.setPixelColor(20, 169, 221, 20);  
      strip.setPixelColor(21, 245, 116, 97);  
      strip.setPixelColor(22, 169, 221, 20);  
     
       strip.setPixelColor(23, 245, 116, 97);  
      strip.setPixelColor(24, 169, 221, 20);  
      strip.setPixelColor(25, 245, 116, 97);  
      strip.setPixelColor(26, 169, 221, 20);  
     
       strip.setPixelColor(27, 245, 116, 97);  
      strip.setPixelColor(28, 169, 221, 20);  
      strip.setPixelColor(29, 245, 116, 97);  
      strip.setPixelColor(30, 169, 221, 20);  
     
       strip.setPixelColor(31, 245, 116, 97);  
      strip.setPixelColor(32, 169, 221, 20);  
      strip.setPixelColor(33, 245, 116, 97);  
      strip.setPixelColor(34, 169, 221, 20);  
       strip.setPixelColor(35, 245, 116, 97);  
      strip.setPixelColor(36, 169, 221, 20);  
      strip.setPixelColor(37, 245, 116, 97);  
      strip.setPixelColor(38, 169, 221, 20);  
       strip.setPixelColor(39, 245, 116, 97);  
      strip.setPixelColor(40, 169, 221, 20);  
      strip.setPixelColor(41, 245, 116, 97);  
      strip.setPixelColor(42, 169, 221, 20);  
       strip.setPixelColor(43, 245, 116, 97);  
      strip.setPixelColor(44, 169, 221, 20);  
      strip.setPixelColor(45, 245, 116, 97);  
      strip.setPixelColor(46, 169, 221, 20);  
       strip.setPixelColor(47, 245, 116, 97);  
      strip.setPixelColor(48, 169, 221, 20);  
      strip.setPixelColor(49, 245, 116, 97);  
      strip.setPixelColor(50, 169, 221, 20);  
       strip.setPixelColor(51, 245, 116, 97);  
      strip.setPixelColor(52, 169, 221, 20);  
      strip.setPixelColor(53, 245, 116, 97);  
      strip.setPixelColor(54, 169, 221, 20);  
       strip.setPixelColor(55, 245, 116, 97);  
      strip.setPixelColor(56, 169, 221, 20);  
      strip.setPixelColor(57, 245, 116, 97);  
      strip.setPixelColor(58, 169, 221, 20);  
       strip.setPixelColor(59, 245, 116, 97);  
     
     
     
      strip.show();
      delay(lng);
    }//close option 2green

    else if (level3Color == 3) //run blue
    {
      //open option 3

      strip.setPixelColor(0, 169, 221, 199);  
      strip.setPixelColor(1, 245, 116, 97);  
      strip.setPixelColor(2, 169, 221, 199);  
      strip.setPixelColor(3,  245, 116, 97);  
       strip.setPixelColor(4, 169, 221, 199);  
      strip.setPixelColor(5, 245, 116, 97);  
      strip.setPixelColor(6, 169, 221, 199);  
      strip.setPixelColor(7,  245, 116, 97);  
       strip.setPixelColor(8, 169, 221, 199);  
      strip.setPixelColor(9, 245, 116, 97);  
      strip.setPixelColor(10, 169, 221, 199);  
      strip.setPixelColor(11,  245, 116, 97);  
       strip.setPixelColor(12, 169, 221, 199);  
      strip.setPixelColor(13, 245, 116, 97);  
      strip.setPixelColor(14, 169, 221, 199);  
      strip.setPixelColor(15,  245, 116, 97);  
       strip.setPixelColor(16, 169, 221, 199);  
      strip.setPixelColor(17, 245, 116, 97);  
      strip.setPixelColor(18, 169, 221, 199);  
      strip.setPixelColor(19,  245, 116, 97);  
       strip.setPixelColor(20, 169, 221, 199);  
      strip.setPixelColor(21, 245, 116, 97);  
      strip.setPixelColor(22, 169, 221, 199);  
      strip.setPixelColor(23,  245, 116, 97);  
       strip.setPixelColor(24, 169, 221, 199);  
      strip.setPixelColor(25, 245, 116, 97);  
      strip.setPixelColor(26, 169, 221, 199);  
      strip.setPixelColor(27,  245, 116, 97);  
       strip.setPixelColor(28, 169, 221, 199);  
      strip.setPixelColor(29, 245, 116, 97);  
      strip.setPixelColor(30, 169, 221, 199);  
      strip.setPixelColor(31,  245, 116, 97);  
       strip.setPixelColor(32, 169, 221, 199);  
      strip.setPixelColor(33, 245, 116, 97);  
      strip.setPixelColor(34, 169, 221, 199);  
      strip.setPixelColor(35,  245, 116, 97);  
       strip.setPixelColor(36, 169, 221, 199);  
      strip.setPixelColor(37, 245, 116, 97);  
      strip.setPixelColor(38, 169, 221, 199);  
      strip.setPixelColor(39,  245, 116, 97);  
       strip.setPixelColor(40, 169, 221, 199);  
      strip.setPixelColor(41, 245, 116, 97);  
      strip.setPixelColor(42, 169, 221, 199);  
      strip.setPixelColor(43,  245, 116, 97);  
       strip.setPixelColor(44, 169, 221, 199);  
      strip.setPixelColor(45, 245, 116, 97);  
      strip.setPixelColor(46, 169, 221, 199);  
      strip.setPixelColor(47,  245, 116, 97);  
       strip.setPixelColor(48, 169, 221, 199);  
      strip.setPixelColor(49, 245, 116, 97);  
      strip.setPixelColor(50, 169, 221, 199);  
      strip.setPixelColor(51,  245, 116, 97);  
       strip.setPixelColor(52, 169, 221, 199);  
      strip.setPixelColor(53, 245, 116, 97);  
      strip.setPixelColor(54, 169, 221, 199);  
      strip.setPixelColor(55,  245, 116, 97);  

       
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level3Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
       strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 255, 255, 0);  
      strip.setPixelColor(7, 255, 255, 0);  
      
       strip.setPixelColor(8, 255, 255, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 255, 255, 0);  
      
       strip.setPixelColor(12, 255, 255, 0);  
      strip.setPixelColor(13, 255, 255, 0);  
      strip.setPixelColor(14, 255, 255, 0);  
      strip.setPixelColor(15, 255, 255, 0);  
      
       strip.setPixelColor(16, 255, 255, 0);  
      strip.setPixelColor(17, 255, 255, 0);  
      strip.setPixelColor(18, 255, 255, 0);  
      strip.setPixelColor(19, 255, 255, 0);  
      
       strip.setPixelColor(20, 255, 255, 0);  
      strip.setPixelColor(21, 255, 255, 0);  
      strip.setPixelColor(22, 255, 255, 0);  
      strip.setPixelColor(23, 255, 255, 0);  
      
       strip.setPixelColor(24, 255, 255, 0);  
      strip.setPixelColor(25, 255, 255, 0);  
      strip.setPixelColor(26, 255, 255, 0);  
      strip.setPixelColor(27, 255, 255, 0);  
      
       strip.setPixelColor(28, 255, 255, 0);  
      strip.setPixelColor(29, 255, 255, 0);  
      strip.setPixelColor(30, 255, 255, 0);  
      strip.setPixelColor(31, 255, 255, 0);  
      
       strip.setPixelColor(32, 255, 255, 0);  
      strip.setPixelColor(33, 255, 255, 0);  
      strip.setPixelColor(34, 255, 255, 0);  
      strip.setPixelColor(35, 255, 255, 0);  
      
       strip.setPixelColor(36, 255, 255, 0);  
      strip.setPixelColor(37, 255, 255, 0);  
      strip.setPixelColor(38, 255, 255, 0);  
      strip.setPixelColor(39, 255, 255, 0);  
      
       strip.setPixelColor(40, 255, 255, 0);  
      strip.setPixelColor(41, 255, 255, 0);  
      strip.setPixelColor(42, 255, 255, 0);  
      strip.setPixelColor(43, 255, 255, 0);  
      
       strip.setPixelColor(44, 255, 255, 0);  
      strip.setPixelColor(45, 255, 255, 0);  
      strip.setPixelColor(46, 255, 255, 0);  
      strip.setPixelColor(47, 255, 255, 0);  
      
       strip.setPixelColor(48, 255, 255, 0);  
      strip.setPixelColor(49, 255, 255, 0);  
      strip.setPixelColor(50, 255, 255, 0);  
      strip.setPixelColor(51, 255, 255, 0);  
      
       strip.setPixelColor(52, 255, 255, 0);  
      strip.setPixelColor(53, 255, 255, 0);  
      strip.setPixelColor(54, 255, 255, 0);  
      strip.setPixelColor(55, 255, 255, 0);  
      
       strip.setPixelColor(56, 255, 255, 0);  
      strip.setPixelColor(57, 255, 255, 0);  
      strip.setPixelColor(58, 255, 255, 0);  
      strip.setPixelColor(59, 255, 255, 0);  
      
     

      
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level3Color == 5)
    {
      //open option 5
      strip.setPixelColor(0, 255, 255, 255);  
      strip.setPixelColor(1, 255, 105, 180);  
      strip.setPixelColor(2, 255, 255, 255);  
      strip.setPixelColor(3, 255, 105, 180);  
      strip.setPixelColor(4, 255, 255, 255);  
      strip.setPixelColor(5, 255, 105, 180);  
      strip.setPixelColor(6, 255, 255, 255);  
      strip.setPixelColor(7, 255, 105, 180);  
      strip.setPixelColor(8, 255, 255, 255);  
      strip.setPixelColor(9, 255, 105, 180);  
      strip.setPixelColor(10, 255, 255, 255);  
      strip.setPixelColor(11, 255, 105, 180); 
         strip.setPixelColor(12, 255, 255, 255);  
      strip.setPixelColor(13, 255, 105, 180);  
      strip.setPixelColor(14, 255, 255, 255);  
      strip.setPixelColor(15, 255, 105, 180);  
      strip.setPixelColor(16, 255, 255, 255);  
      strip.setPixelColor(17, 255, 105, 180);  
      strip.setPixelColor(18, 255, 255, 255);  
      strip.setPixelColor(19, 255, 105, 180);  
      strip.setPixelColor(20, 255, 255, 255);  
      strip.setPixelColor(21, 255, 105, 180);  
      strip.setPixelColor(22, 255, 255, 255);  
      strip.setPixelColor(23, 255, 105, 180);  
         strip.setPixelColor(24, 255, 255, 255);  
      strip.setPixelColor(25, 255, 105, 180);  
      strip.setPixelColor(26, 255, 255, 255);  
      strip.setPixelColor(27, 255, 105, 180);  
      strip.setPixelColor(28, 255, 255, 255);  
      strip.setPixelColor(29, 255, 105, 180);  
      strip.setPixelColor(30, 255, 255, 255);  
      strip.setPixelColor(31, 255, 105, 180);  
      strip.setPixelColor(32, 255, 255, 255);  
      strip.setPixelColor(33, 255, 105, 180);  
      strip.setPixelColor(34, 255, 255, 255);  
      strip.setPixelColor(35, 255, 105, 180);  
         strip.setPixelColor(36, 255, 255, 255);  
      strip.setPixelColor(37, 255, 105, 180);  
      strip.setPixelColor(38, 255, 255, 255);  
      strip.setPixelColor(39, 255, 105, 180);  
      strip.setPixelColor(40, 255, 255, 255);  
      strip.setPixelColor(41, 255, 105, 180);  
      strip.setPixelColor(42, 255, 255, 255);  
      strip.setPixelColor(43, 255, 105, 180);  
      strip.setPixelColor(44, 255, 255, 255);  
      strip.setPixelColor(45, 255, 105, 180);  
      strip.setPixelColor(46, 255, 255, 255);  
      strip.setPixelColor(47, 255, 105, 180);  
         strip.setPixelColor(48, 255, 255, 255);  
      strip.setPixelColor(49, 255, 105, 180);  
      strip.setPixelColor(50, 255, 255, 255);  
      strip.setPixelColor(51, 255, 105, 180);  
      strip.setPixelColor(52, 255, 255, 255);  
      strip.setPixelColor(53, 255, 105, 180);  
      strip.setPixelColor(54, 255, 255, 255);  
      strip.setPixelColor(55, 255, 105, 180);  
      strip.setPixelColor(56, 255, 255, 255);  
      strip.setPixelColor(57, 255, 105, 180);  
      strip.setPixelColor(58, 255, 255, 255);  
      strip.setPixelColor(59, 255, 105, 180);  
           
      strip.show();
      delay(sht);
    }//close of option 5
  }//close level 3


  if (soundLevel == 4)
  {
    //open if sound level 4
    int level4Color = random(1, 5);

    if (level4Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 255, 0, 0);  
       strip.setPixelColor(5, 255, 0, 0);  
      strip.setPixelColor(6, 0, 0, 255);  
      strip.setPixelColor(7, 255, 0, 0);  
      strip.setPixelColor(8, 0, 0, 255);  
      strip.setPixelColor(9, 255, 0, 0);  
       strip.setPixelColor(10, 255, 0, 0);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.setPixelColor(12, 255, 0, 0);  
      strip.setPixelColor(13, 0, 0, 255);  
      strip.setPixelColor(14, 255, 0, 0);  
       strip.setPixelColor(15, 255, 0, 0);  
      strip.setPixelColor(16, 0, 0, 255);  
      strip.setPixelColor(17, 255, 0, 0);  
      strip.setPixelColor(18, 0, 0, 255);  
      strip.setPixelColor(19, 255, 0, 0);  
       strip.setPixelColor(20, 255, 0, 0);  
      strip.setPixelColor(21, 0, 0, 255);  
      strip.setPixelColor(22, 255, 0, 0);  
      strip.setPixelColor(23, 0, 0, 255);  
      strip.setPixelColor(24, 255, 0, 0);  
       strip.setPixelColor(25, 255, 0, 0);  
      strip.setPixelColor(26, 0, 0, 255);  
      strip.setPixelColor(27, 255, 0, 0);  
      strip.setPixelColor(28, 0, 0, 255);  
      strip.setPixelColor(29, 255, 0, 0);  
       strip.setPixelColor(30, 255, 0, 0);  
      strip.setPixelColor(31, 0, 0, 255);  
      strip.setPixelColor(32, 255, 0, 0);  
      strip.setPixelColor(33, 0, 0, 255);  
      strip.setPixelColor(34, 255, 0, 0);  
       strip.setPixelColor(35, 255, 0, 0);  
      strip.setPixelColor(36, 0, 0, 255);  
      strip.setPixelColor(37, 255, 0, 0);  
      strip.setPixelColor(38, 0, 0, 255);  
      strip.setPixelColor(39, 255, 0, 0);  
       strip.setPixelColor(40, 255, 0, 0);  
      strip.setPixelColor(41, 0, 0, 255);  
      strip.setPixelColor(42, 255, 0, 0);  
      strip.setPixelColor(43, 0, 0, 255);  
      strip.setPixelColor(44, 255, 0, 0);  
       strip.setPixelColor(45, 255, 0, 0);  
      strip.setPixelColor(46, 0, 0, 255);  
      strip.setPixelColor(47, 255, 0, 0);  
      strip.setPixelColor(48, 0, 0, 255);  
      strip.setPixelColor(49, 255, 0, 0);  
       strip.setPixelColor(50, 255, 0, 0);  
      strip.setPixelColor(51, 0, 0, 255);  
      strip.setPixelColor(52, 255, 0, 0);  
      strip.setPixelColor(53, 0, 0, 255);  
      strip.setPixelColor(54, 255, 0, 0);  
       strip.setPixelColor(55, 255, 0, 0);  
      strip.setPixelColor(56, 0, 0, 255);  
      strip.setPixelColor(57, 255, 0, 0);  
      strip.setPixelColor(58, 0, 0, 255);  
      strip.setPixelColor(59, 255, 0, 0);  
       
      strip.show();
      delay(lng);
    }//close red

    else if (level4Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 255, 0);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close green

    else if (level4Color == 3) //run blue
    {
      //open option 3

      strip.setPixelColor(0, 0, 0, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 0, 255); 
      
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 0, 255);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 0, 255);  
      strip.setPixelColor(9, 0, 0, 255);  
      
      strip.setPixelColor(10, 0, 0, 255);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.setPixelColor(12, 0, 0, 255);  
      strip.setPixelColor(13, 0, 0, 255);  
      strip.setPixelColor(14, 0, 0, 255);  
      
      strip.setPixelColor(15, 0, 0, 255);  
      strip.setPixelColor(16, 0, 0, 255);  
      strip.setPixelColor(17, 0, 0, 255);  
      strip.setPixelColor(18, 0, 0, 255);  
      strip.setPixelColor(19, 0, 0, 255);   
      
      strip.setPixelColor(20, 0, 0, 255);  
      strip.setPixelColor(21, 0, 0, 255);  
      strip.setPixelColor(22, 0, 0, 255);  
      strip.setPixelColor(23, 0, 0, 255);  
      strip.setPixelColor(24, 0, 0, 255);  
      
      strip.setPixelColor(25, 0, 0, 255);  
      strip.setPixelColor(26, 0, 0, 255);  
      strip.setPixelColor(27, 0, 0, 255);  
      strip.setPixelColor(28, 0, 0, 255);  
      strip.setPixelColor(29, 0, 0, 255);  
      
      strip.setPixelColor(30, 0, 0, 255);  
      strip.setPixelColor(31, 0, 0, 255);  
      strip.setPixelColor(32, 0, 0, 255);  
      strip.setPixelColor(33, 0, 0, 255);  
      strip.setPixelColor(34, 0, 0, 255);  
      
      strip.setPixelColor(35, 0, 0, 255);  
      strip.setPixelColor(36, 0, 0, 255);  
      strip.setPixelColor(37, 0, 0, 255);  
      strip.setPixelColor(38, 0, 0, 255);  
      strip.setPixelColor(39, 0, 0, 255);  
      
      strip.setPixelColor(40, 0, 0, 255);  
      strip.setPixelColor(41, 0, 0, 255);  
      strip.setPixelColor(42, 0, 0, 255);  
      strip.setPixelColor(43, 0, 0, 255);  
      strip.setPixelColor(44, 0, 0, 255);  
      
      strip.setPixelColor(45, 0, 0, 255);  
      strip.setPixelColor(46, 0, 0, 255);  
      strip.setPixelColor(47, 0, 0, 255);  
      strip.setPixelColor(48, 0, 0, 255);  
      strip.setPixelColor(49, 0, 0, 255);  
      
      strip.setPixelColor(50, 0, 0, 255);  
      strip.setPixelColor(51, 0, 0, 255);  
      strip.setPixelColor(52, 0, 0, 255);  
      strip.setPixelColor(53, 0, 0, 255);  
      strip.setPixelColor(54, 0, 0, 255);  
      
      strip.setPixelColor(55, 0, 0, 255);  
      strip.setPixelColor(56, 0, 0, 255);  
      strip.setPixelColor(57, 0, 0, 255);  
      strip.setPixelColor(58, 0, 0, 255);  
      strip.setPixelColor(59, 0, 0, 255);  
      strip.show();
      delay(lng);
    }//close blue

    else if (level4Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 255, 255, 0);  
      strip.setPixelColor(7, 255, 255, 0);  
      strip.setPixelColor(8, 255, 255, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 255, 255, 0);  
      strip.setPixelColor(12, 255, 255, 0);  
      strip.setPixelColor(13, 255, 255, 0);  
      strip.setPixelColor(14, 255, 255, 0);  
      strip.setPixelColor(15, 255, 255, 0);  
      strip.setPixelColor(16, 255, 255, 0);  
      strip.setPixelColor(17, 255, 255, 0);  
      strip.setPixelColor(18, 255, 255, 0);  
      strip.setPixelColor(19, 255, 255, 0);  
      strip.setPixelColor(20, 255, 255, 0);  
      strip.setPixelColor(21, 255, 255, 0);  
      strip.setPixelColor(22, 255, 255, 0);  
      strip.setPixelColor(23, 255, 255, 0);  
      strip.setPixelColor(24, 255, 255, 0);  
      strip.setPixelColor(25, 255, 255, 0);  
      strip.setPixelColor(26, 255, 255, 0);  
      strip.setPixelColor(27, 255, 255, 0);  
      strip.setPixelColor(28, 255, 255, 0);  
      strip.setPixelColor(29, 255, 255, 0);  
      strip.setPixelColor(30, 255, 255, 0);  
      strip.setPixelColor(31, 255, 255, 0);  
      strip.setPixelColor(32, 255, 255, 0);  
      strip.setPixelColor(33, 255, 255, 0);  
      strip.setPixelColor(34, 255, 255, 0);  
      strip.setPixelColor(35, 255, 255, 0);  
      strip.setPixelColor(36, 255, 255, 0);  
      strip.setPixelColor(37, 255, 255, 0);  
      strip.setPixelColor(38, 255, 255, 0);  
      strip.setPixelColor(39, 255, 255, 0);  
      strip.setPixelColor(40, 255, 255, 0);  
      strip.setPixelColor(41, 255, 255, 0);  
      strip.setPixelColor(42, 255, 255, 0);  
      strip.setPixelColor(43, 255, 255, 0);  
      strip.setPixelColor(44, 255, 255, 0);  
      strip.setPixelColor(45, 255, 255, 0);  
      strip.setPixelColor(46, 255, 255, 0);  
      strip.setPixelColor(47, 255, 255, 0);  
      strip.setPixelColor(48, 255, 255, 0);  
      strip.setPixelColor(49, 255, 255, 0);  
      strip.setPixelColor(50, 255, 255, 0);  
      strip.setPixelColor(51, 255, 255, 0);  
      strip.setPixelColor(52, 255, 255, 0);  
      strip.setPixelColor(53, 255, 255, 0);  
      strip.setPixelColor(54, 255, 255, 0);  
      strip.setPixelColor(55, 255, 255, 0);  
      strip.setPixelColor(56, 255, 255, 0);  
      strip.setPixelColor(57, 255, 255, 0);  
      strip.setPixelColor(58, 255, 255, 0);  
      strip.setPixelColor(59, 255, 255, 0);  
      
      
      strip.show();
      delay(lng);
    }//close yellow

    else if (level4Color == 5)
    {
      ////open option 5
      strip.setPixelColor(0, 255, 01, 165);  
      strip.setPixelColor(1, 255, 187, 218);  
      strip.setPixelColor(2, 228, 194, 191);  
      strip.setPixelColor(3, 153, 87, 205);  
      strip.setPixelColor(4, 176, 284, 218);  
      strip.setPixelColor(5, 67, 142, 200);  
      strip.setPixelColor(6, 107, 167, 214);  
      strip.setPixelColor(7, 168, 204, 232);  
      strip.setPixelColor(8, 59, 198, 182);  
      strip.setPixelColor(9, 100, 212, 199);  
      strip.setPixelColor(10, 164, 231, 223);  
      strip.setPixelColor(11, 255, 01, 165);  
      strip.setPixelColor(12, 255, 187, 218);  
      strip.setPixelColor(13, 228, 194, 191);  
      strip.setPixelColor(14, 153, 87, 205);  
      strip.setPixelColor(15, 176, 284, 218);  
      strip.setPixelColor(16, 67, 142, 200);  
      strip.setPixelColor(17, 107, 167, 214);  
      strip.setPixelColor(18, 168, 204, 232);  
      strip.setPixelColor(19, 59, 198, 182);  
      strip.setPixelColor(20, 100, 212, 199);  
      strip.setPixelColor(22, 164, 231, 223);  
      strip.setPixelColor(23, 176, 124, 218);  
       strip.setPixelColor(24, 255, 01, 165);  
      strip.setPixelColor(25, 255, 187, 218);  
      strip.setPixelColor(26, 228, 194, 191);  
      strip.setPixelColor(27, 153, 87, 205);  
      strip.setPixelColor(28, 176, 284, 218);  
      strip.setPixelColor(29, 67, 142, 200);  
      strip.setPixelColor(30, 107, 167, 214);  
      strip.setPixelColor(31, 168, 204, 232);  
      strip.setPixelColor(32, 59, 198, 182);  
      strip.setPixelColor(33, 100, 212, 199);  
      strip.setPixelColor(34, 164, 231, 223);  
      strip.setPixelColor(35, 176, 124, 218);  
       strip.setPixelColor(36, 255, 01, 165);  
      strip.setPixelColor(37, 255, 187, 218);  
      strip.setPixelColor(38, 228, 194, 191);  
      strip.setPixelColor(39, 153, 87, 205);  
      strip.setPixelColor(40, 176, 284, 218);  
      strip.setPixelColor(41, 67, 142, 200);  
      strip.setPixelColor(42, 107, 167, 214);  
      strip.setPixelColor(43, 168, 204, 232);  
      strip.setPixelColor(44, 59, 198, 182);  
      strip.setPixelColor(45, 100, 212, 199);  
      strip.setPixelColor(46, 164, 231, 223);  
      strip.setPixelColor(47, 176, 124, 218);  
       strip.setPixelColor(48, 255, 01, 165);  
      strip.setPixelColor(49, 255, 187, 218);  
      strip.setPixelColor(50, 228, 194, 191);  
      strip.setPixelColor(51, 153, 87, 205);  
      strip.setPixelColor(52, 176, 284, 218);  
      strip.setPixelColor(53, 67, 142, 200);  
      strip.setPixelColor(54, 107, 167, 214);  
      strip.setPixelColor(55, 168, 204, 232);  
      strip.setPixelColor(56, 59, 198, 182);  
      strip.setPixelColor(57, 100, 212, 199);  
      strip.setPixelColor(58, 164, 231, 223);  
      strip.setPixelColor(59, 176, 124, 218);  
         

      strip.show();
      delay(lng);
    }//close option 5

  }//close if sound level 4

  else if (soundLevel == 5)
  {
    //open if sound level 5


    int level5Color = random(1, 6);

    if (level5Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 255, 255, 255);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 255, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
       strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 255, 255, 255);  
      strip.setPixelColor(8, 0, 0, 255);  
      strip.setPixelColor(9, 255, 0, 0);  
      strip.setPixelColor(10, 255, 255, 255);  
      strip.setPixelColor(11, 0, 0, 255);  
       strip.setPixelColor(12, 255, 0, 0);  
      strip.setPixelColor(13, 255, 255, 255);  
      strip.setPixelColor(14, 0, 0, 255);  
      strip.setPixelColor(15, 255, 0, 0);  
      strip.setPixelColor(16, 255, 255, 255);  
      strip.setPixelColor(17, 0, 0, 255);  
       strip.setPixelColor(18, 255, 0, 0);  
      strip.setPixelColor(19, 255, 255, 255);  
      strip.setPixelColor(20, 0, 0, 255);  
      strip.setPixelColor(21, 255, 0, 0);  
      strip.setPixelColor(22, 255, 255, 255);  
      strip.setPixelColor(23, 0, 0, 255);  
       strip.setPixelColor(24, 255, 0, 0);  
      strip.setPixelColor(25, 255, 255, 255);  
      strip.setPixelColor(26, 0, 0, 255);  
      strip.setPixelColor(27, 255, 0, 0);  
      strip.setPixelColor(28, 255, 255, 255);  
      strip.setPixelColor(29, 0, 0, 255);  
       strip.setPixelColor(30, 255, 0, 0);  
      strip.setPixelColor(31, 255, 255, 255);  
      strip.setPixelColor(32, 0, 0, 255);  
      strip.setPixelColor(33, 255, 0, 0);  
      strip.setPixelColor(34, 255, 255, 255);  
      strip.setPixelColor(35, 0, 0, 255);  
       strip.setPixelColor(36, 255, 0, 0);  
      strip.setPixelColor(37, 255, 255, 255);  
      strip.setPixelColor(38, 0, 0, 255);  
      strip.setPixelColor(39, 255, 0, 0);  
      strip.setPixelColor(40, 255, 255, 255);  
      strip.setPixelColor(41, 0, 0, 255);  
       strip.setPixelColor(42, 255, 0, 0);  
      strip.setPixelColor(43, 255, 255, 255);  
      strip.setPixelColor(44, 0, 0, 255);  
      strip.setPixelColor(45, 255, 0, 0);  
      strip.setPixelColor(46, 255, 255, 255);  
      strip.setPixelColor(47, 0, 0, 255);  
       strip.setPixelColor(48, 255, 0, 0);  
      strip.setPixelColor(49, 255, 255, 255);  
      strip.setPixelColor(50, 0, 0, 255);  
      strip.setPixelColor(51, 255, 0, 0);  
      strip.setPixelColor(52, 255, 255, 255);  
      strip.setPixelColor(53, 0, 0, 255);  
       strip.setPixelColor(54, 255, 0, 0);  
      strip.setPixelColor(55, 255, 255, 255);  
      strip.setPixelColor(56, 0, 0, 255);  
      strip.setPixelColor(57, 255, 0, 0);  
      strip.setPixelColor(58, 255, 255, 255);  
      strip.setPixelColor(59, 0, 0, 255);  
      

      
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level5Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 255, 0);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 255, 0);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 255, 0);  
      strip.setPixelColor(8, 0, 255, 0);  
      strip.setPixelColor(9, 0, 255, 0);  
      strip.setPixelColor(10, 0, 255, 0);  
      strip.setPixelColor(11, 0, 255, 0);  
      strip.setPixelColor(12, 0, 255, 0);  
      strip.setPixelColor(13, 0, 255, 0);  
      strip.setPixelColor(14, 0, 255, 0);  
      strip.setPixelColor(15, 0, 255, 0);  
      strip.setPixelColor(16, 0, 255, 0);  
      strip.setPixelColor(17, 0, 255, 0);  
      strip.setPixelColor(18, 0, 255, 0);  
      strip.setPixelColor(19, 0, 255, 0);  
      strip.setPixelColor(20, 0, 255, 0);  
      strip.setPixelColor(21, 0, 255, 0);  
      strip.setPixelColor(22, 0, 255, 0);  
      strip.setPixelColor(23, 0, 255, 0);  
      strip.setPixelColor(24, 0, 255, 0);  
      strip.setPixelColor(25, 0, 255, 0);  
      strip.setPixelColor(26, 0, 255, 0);  
      strip.setPixelColor(27, 0, 255, 0);  
      strip.setPixelColor(28, 0, 255, 0);  
      strip.setPixelColor(29, 0, 255, 0);  
      strip.setPixelColor(30, 0, 255, 0);  
      strip.setPixelColor(31, 0, 255, 0);  
      strip.setPixelColor(32, 0, 255, 0);  
      strip.setPixelColor(33, 0, 255, 0);  
      strip.setPixelColor(34, 0, 255, 0);  
      strip.setPixelColor(35, 0, 255, 0);  
      strip.setPixelColor(36, 0, 255, 0);  
      strip.setPixelColor(37, 0, 255, 0);  
      strip.setPixelColor(38, 0, 255, 0);  
      strip.setPixelColor(39, 0, 255, 0);  
      strip.setPixelColor(40, 0, 255, 0);  
      strip.setPixelColor(41, 0, 255, 0);  
      strip.setPixelColor(42, 0, 255, 0);  
      strip.setPixelColor(43, 0, 255, 0);  
      strip.setPixelColor(44, 0, 255, 0);  
      strip.setPixelColor(45, 0, 255, 0);  
      strip.setPixelColor(46, 0, 255, 0);  
      strip.setPixelColor(47, 0, 255, 0);  
      strip.setPixelColor(48, 0, 255, 0);  
      strip.setPixelColor(49, 0, 255, 0);  
      strip.setPixelColor(50, 0, 255, 0);  
      strip.setPixelColor(51, 0, 255, 0);  
      strip.setPixelColor(52, 0, 255, 0);  
      strip.setPixelColor(53, 0, 255, 0);  
      strip.setPixelColor(54, 0, 255, 0);  
      strip.setPixelColor(55, 0, 255, 0);  
      strip.setPixelColor(56, 0, 255, 0);  
      strip.setPixelColor(57, 0, 255, 0);  
      strip.setPixelColor(58, 0, 255, 0);  
      strip.setPixelColor(59, 0, 255, 0);  
    
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level5Color == 3) //run blue
    {
      //open option 3

      strip.setPixelColor(0, 0, 0, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 0, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level5Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close yellow

    else if (level5Color == 5)
    {
      //open option 5

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 0, 255);      
strip.setPixelColor(6, 0, 0, 255);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 0, 255, 0);  
      strip.setPixelColor(8, 0, 0, 255);  
      strip.setPixelColor(9, 255, 0, 0);  
      strip.setPixelColor(10, 0, 255, 0);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.show();
      delay(lng);
    }//close option 5

    else if (level5Color == 6)
    {
      //open option 6

      colorWipe(strip.Color(255, 0, 255), 50); // magenta
      colorWipe(strip.Color(0, 255, 0), 50); // green
      strip.show();
    }//close option 6
  }//close if sound level 5


  else if (soundLevel == 6)
  {
    //open if soundlevel 6

    int level6Color = random(1, 6);

    if (level6Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 255, 255, 255);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 255, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 1red

    else if (level6Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 255, 0);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 255, 0);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level6Color == 3) //run blue
    {
      //open option 3

      strip.setPixelColor(0, 0, 0, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 0, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 0, 255);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level6Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 148, 0, 211);  
      strip.setPixelColor(1, 75, 0, 130);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 0, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 127, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 148, 0, 211);  
      strip.setPixelColor(8, 75, 0, 130);  
      strip.setPixelColor(9, 0, 0, 255);  
      strip.setPixelColor(10, 0, 255, 0);  
      strip.setPixelColor(11, 255, 255, 0);  
      strip.setPixelColor(12, 255, 127, 0);  
      strip.setPixelColor(13, 255, 0, 0);  
      strip.setPixelColor(14, 148, 0, 211);  
      strip.setPixelColor(15, 75, 0, 130);  
      strip.setPixelColor(16, 0, 0, 255);  
      strip.setPixelColor(17, 0, 255, 0);  
      strip.setPixelColor(18, 255, 255, 0);  
      strip.setPixelColor(19, 255, 127, 0);  
      strip.setPixelColor(20, 148, 0, 211);  
      strip.setPixelColor(21, 75, 0, 130);  
      strip.setPixelColor(22, 0, 0, 255);  
      strip.setPixelColor(23, 0, 255, 0);  
      strip.setPixelColor(24, 255, 255, 0);  
      strip.setPixelColor(25, 255, 127, 0);  
      strip.setPixelColor(26, 255, 0, 0);  
      strip.setPixelColor(27, 148, 0, 211);  
      strip.setPixelColor(28, 75, 0, 130);  
      strip.setPixelColor(29, 0, 0, 255);  
      strip.setPixelColor(30, 0, 255, 0);  
      strip.setPixelColor(31, 255, 255, 0);  
      strip.setPixelColor(32, 255, 127, 0);  
      strip.setPixelColor(33, 255, 0, 0);  
      strip.setPixelColor(34, 148, 0, 211);  
      strip.setPixelColor(35, 75, 0, 130);  
      strip.setPixelColor(36, 0, 0, 255);  
      strip.setPixelColor(37, 0, 255, 0);  
      strip.setPixelColor(38, 255, 255, 0);  
      strip.setPixelColor(39, 255, 127, 0);  
    
    strip.setPixelColor(40, 148, 0, 211);  
      strip.setPixelColor(41, 75, 0, 130);  
      strip.setPixelColor(42, 0, 0, 255);  
      strip.setPixelColor(43, 0, 255, 0);  
      strip.setPixelColor(44, 255, 255, 0);  
      strip.setPixelColor(45, 255, 127, 0);  
      strip.setPixelColor(46, 255, 0, 0);  
      strip.setPixelColor(47, 148, 0, 211);  
      strip.setPixelColor(48, 75, 0, 130);  
      strip.setPixelColor(49, 0, 0, 255);  
      strip.setPixelColor(50, 0, 255, 0);  
      strip.setPixelColor(51, 255, 255, 0);  
      strip.setPixelColor(52, 255, 127, 0);  
      strip.setPixelColor(53, 255, 0, 0);  
      strip.setPixelColor(54, 148, 0, 211);  
      strip.setPixelColor(56, 75, 0, 130);  
      strip.setPixelColor(57, 0, 0, 255);  
      strip.setPixelColor(58, 0, 255, 0);  
      strip.setPixelColor(59, 255, 255, 0);  
      
    

    

      
      strip.show();
      delay(sht);
    }//close yellow

    else if (level6Color == 5)
    {
      //open option 5
      colorWipe(strip.Color(0, 0, 255), 50); // Blue
      colorWipe(strip.Color(255, 255, 0), 50); // yellow
      strip.show();
    }//close option 5

    else if (level6Color == 6)
    {
      //open option6

      theaterChase(strip.Color(200, 0, 0), 50); // Red
      strip.show();
      delay(lng);
    }//close option 6
  }//close if sound level 6

  else if (soundLevel == 7)
  {
    //open if sound level 7
    int level7Color = random(1, 7);

    if (level7Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 255, 0, 0);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 0, 0);  
      strip.setPixelColor(5, 255, 0, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 255, 0, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level7Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 255, 0);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 255, 0);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 255, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level7Color == 3) //run blue
    {
      //open option 3

      strip.setPixelColor(0, 0, 0, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 0, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 0, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 0, 255);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level7Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 255, 255, 0);  
      strip.setPixelColor(7, 255, 255, 0);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level7Color == 5)
    {
      //open option 5
      colorWipe(strip.Color(255, 20, 147), 50); // pink
      colorWipe(strip.Color(0, 206, 209), 50); // turquoise
      strip.show();
      delay(lng);
    }//close option 5

    else if (level7Color == 6)
    {
      //open option 6

      theaterChase(strip.Color(255, 20, 100), 50); // Red
      strip.show();
      delay(sht);
    }//close option 6

    else if (level7Color == 7)
    {
      //open option 7
      strip.setPixelColor(0, 0, 70, 70);  
      strip.setPixelColor(1, 0, 100, 0);  
      strip.setPixelColor(2, 255, 0, 70);  
      strip.setPixelColor(3, 50, 0, 150);  
      strip.setPixelColor(4, 0, 70, 70);  
      strip.setPixelColor(5, 0, 100, 0);  
      strip.setPixelColor(6, 255, 0, 70);  
      strip.setPixelColor(7, 50, 0, 150);  
strip.setPixelColor(8, 0, 70, 70);  
      strip.setPixelColor(9, 255, 0, 70);  
      strip.setPixelColor(10, 0, 100, 0);  
      strip.setPixelColor(11, 255, 0, 70);  
      strip.setPixelColor(12, 50, 0, 150);  
      strip.setPixelColor(13, 0, 70, 70);  
      strip.setPixelColor(14, 0, 100, 0);  
      strip.setPixelColor(15, 255, 0, 70);  
      strip.setPixelColor(16, 50, 0, 150);  
      strip.setPixelColor(17, 0, 70, 70);  
      strip.setPixelColor(18, 0, 100, 0);  
      strip.setPixelColor(19, 255, 0, 70);  
      strip.setPixelColor(20, 50, 0, 150);  
strip.setPixelColor(21, 0, 70, 70);  
      strip.setPixelColor(22, 255, 0, 70);  
      strip.setPixelColor(23, 0, 100, 0);  
      strip.setPixelColor(24, 255, 0, 70);  
      strip.setPixelColor(25, 50, 0, 150);  

strip.setPixelColor(26, 0, 70, 70);  
      strip.setPixelColor(27, 0, 100, 0);  
      strip.setPixelColor(28, 255, 0, 70);  
      strip.setPixelColor(29, 50, 0, 150);  
      strip.setPixelColor(30, 0, 70, 70);  
      strip.setPixelColor(31, 0, 100, 0);  
      strip.setPixelColor(32, 255, 0, 70);  
      strip.setPixelColor(33, 50, 0, 150);  
strip.setPixelColor(34, 0, 70, 70);  
      strip.setPixelColor(35, 255, 0, 70);  
      strip.setPixelColor(36, 0, 100, 0);  
      strip.setPixelColor(37, 255, 0, 70);  
      strip.setPixelColor(38, 50, 0, 150);  

strip.setPixelColor(38, 0, 70, 70);  
      strip.setPixelColor(39, 0, 100, 0);  
      strip.setPixelColor(40, 255, 0, 70);  
      strip.setPixelColor(41, 50, 0, 150);  
      strip.setPixelColor(42, 0, 70, 70);  
      strip.setPixelColor(43, 0, 100, 0);  
      strip.setPixelColor(44, 255, 0, 70);  
      strip.setPixelColor(45, 50, 0, 150);  
strip.setPixelColor(46, 0, 70, 70);  
      strip.setPixelColor(47, 255, 0, 70);  
      strip.setPixelColor(48, 0, 100, 0);  
      strip.setPixelColor(49, 255, 0, 70);  
      strip.setPixelColor(50, 50, 0, 150);  

strip.setPixelColor(51, 0, 70, 70);  
      strip.setPixelColor(52, 0, 100, 0);  
      strip.setPixelColor(53, 255, 0, 70);  
      strip.setPixelColor(54, 50, 0, 150);  
      strip.setPixelColor(55, 0, 70, 70);  
      strip.setPixelColor(56, 0, 100, 0);  
      strip.setPixelColor(57, 255, 0, 70);  
      strip.setPixelColor(58, 50, 0, 150);  
strip.setPixelColor(59, 0, 70, 70);  
     

      strip.show();
      delay(sht);
    }//close option 7
  }//close if sound level 7

  else if (soundLevel == 8)
  {
    //open if sound level 8

    int level8Color = random(1, 8);

    if (level8Color == 1) //run red
    {
      //open option 1
      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 255, 0, 0);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 0, 0);  
      strip.setPixelColor(5, 255, 0, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 255, 0, 0);  
      strip.setPixelColor(8, 255, 0, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level8Color == 2) //run green/blue
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 255, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 2 green/blue

    else if (level8Color == 3) //run turquoise / blue
    {
      //open option 3

      strip.setPixelColor(0, 0, 206, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 206, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 206, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 206, 255);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 206, 255);  
      
      strip.setPixelColor(9, 0, 206, 255);  
      strip.setPixelColor(10, 0, 0, 255);  
      strip.setPixelColor(11, 0, 206, 255);  
      strip.setPixelColor(12, 0, 0, 255);  
      strip.setPixelColor(13, 0, 206, 255);  
      strip.setPixelColor(14, 0, 0, 255);  
      strip.setPixelColor(15, 0, 206, 255);  
      strip.setPixelColor(16, 0, 0, 255);  
      strip.setPixelColor(17, 0, 206, 255);  
      
      strip.setPixelColor(18, 0, 206, 255);  
      strip.setPixelColor(19, 0, 0, 255);  
      strip.setPixelColor(20, 0, 206, 255);  
      strip.setPixelColor(21, 0, 0, 255);  
      strip.setPixelColor(22, 0, 206, 255);  
      strip.setPixelColor(23, 0, 0, 255);  
      strip.setPixelColor(24, 0, 206, 255);  
      strip.setPixelColor(25, 0, 0, 255);  
      strip.setPixelColor(26, 0, 206, 255);  
      
      strip.setPixelColor(27, 0, 206, 255);  
      strip.setPixelColor(28, 0, 0, 255);  
      strip.setPixelColor(29, 0, 206, 255);  
      strip.setPixelColor(30, 0, 0, 255);  
      strip.setPixelColor(31, 0, 206, 255);  
      strip.setPixelColor(32, 0, 0, 255);  
      strip.setPixelColor(33, 0, 206, 255);  
      strip.setPixelColor(34, 0, 0, 255);  
      strip.setPixelColor(35, 0, 206, 255);  
      
      strip.setPixelColor(36, 0, 206, 255);  
      strip.setPixelColor(37, 0, 0, 255);  
      strip.setPixelColor(38, 0, 206, 255);  
      strip.setPixelColor(39, 0, 0, 255);  
      strip.setPixelColor(40, 0, 206, 255);  
      strip.setPixelColor(41, 0, 0, 255);  
      strip.setPixelColor(42, 0, 206, 255);  
      strip.setPixelColor(43, 0, 0, 255);  
      strip.setPixelColor(44, 0, 206, 255);  
      
      strip.setPixelColor(45, 0, 206, 255);  
      strip.setPixelColor(46, 0, 0, 255);  
      strip.setPixelColor(47, 0, 206, 255);  
      strip.setPixelColor(48, 0, 0, 255);  
      strip.setPixelColor(49, 0, 206, 255);  
      strip.setPixelColor(50, 0, 0, 255);  
      strip.setPixelColor(51, 0, 206, 255);  
      strip.setPixelColor(52, 0, 0, 255);  
      strip.setPixelColor(53, 0, 206, 255);  
      
      strip.setPixelColor(54, 0, 206, 255);  
      strip.setPixelColor(55, 0, 0, 255);  
      strip.setPixelColor(56, 0, 206, 255);  
      strip.setPixelColor(57, 0, 0, 255);  
      strip.setPixelColor(58, 0, 206, 255);  
      strip.setPixelColor(59, 0, 0, 255);  
     
     
      delay(lng);
    }//close option 3 blue

    else if (level8Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 255, 255, 0);  
      strip.setPixelColor(7, 255, 255, 0);  
      strip.setPixelColor(8, 255, 255, 0);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level8Color == 5)
    {
      //open option 5
      colorWipe(strip.Color(255, 20, 147), 20); // pink
      colorWipe(strip.Color(0, 206, 209), 20); // turquoise
      strip.show();
    }//close option 5

    else if (level8Color == 6)
    {
      //open option 6

      theaterChase(strip.Color(0, 206, 209), 50); // Red
      strip.show();
      delay(sht);
    }//close option 6

    else if (level8Color == 7)
    {
      //open option 7
      strip.setPixelColor(0, 0, 70, 70);  
      strip.setPixelColor(1, 0, 100, 0);  
      strip.setPixelColor(2, 255, 0, 70);  
      strip.setPixelColor(3, 50, 0, 150);  
      strip.setPixelColor(4, 0, 70, 70);  
      strip.setPixelColor(5, 0, 100, 0);  
      strip.setPixelColor(6, 255, 0, 70);  
      strip.setPixelColor(7, 50, 0, 150);  
strip.setPixelColor(8, 0, 70, 70);  
      strip.setPixelColor(9, 255, 0, 70);  
      strip.setPixelColor(10, 0, 100, 0);  
      strip.setPixelColor(11, 255, 0, 70);  
      strip.setPixelColor(12, 50, 0, 150);
        strip.setPixelColor(13, 0, 70, 70);  
      strip.setPixelColor(14, 0, 100, 0);  
      strip.setPixelColor(15, 255, 0, 70);  
      strip.setPixelColor(16, 50, 0, 150);  
      strip.setPixelColor(17, 0, 70, 70);  
      strip.setPixelColor(18, 0, 100, 0);  
      strip.setPixelColor(19, 255, 0, 70);  
      strip.setPixelColor(20, 50, 0, 150);  
strip.setPixelColor(21, 0, 70, 70);  
      strip.setPixelColor(22, 255, 0, 70);  
      strip.setPixelColor(23, 0, 100, 0);  
      strip.setPixelColor(24, 255, 0, 70);  
      strip.setPixelColor(25, 50, 0, 150);  

  strip.setPixelColor(26, 0, 70, 70);  
      strip.setPixelColor(27, 0, 100, 0);  
      strip.setPixelColor(28, 255, 0, 70);  
      strip.setPixelColor(29, 50, 0, 150);  
      strip.setPixelColor(30, 0, 70, 70);  
      strip.setPixelColor(31, 0, 100, 0);  
      strip.setPixelColor(32, 255, 0, 70);  
      strip.setPixelColor(33, 50, 0, 150);  
strip.setPixelColor(34, 0, 70, 70);  
      strip.setPixelColor(35, 255, 0, 70);  
      strip.setPixelColor(36, 0, 100, 0);  
      strip.setPixelColor(37, 255, 0, 70);  
      strip.setPixelColor(38, 50, 0, 150);  

  strip.setPixelColor(39, 0, 70, 70);  
      strip.setPixelColor(40, 0, 100, 0);  
      strip.setPixelColor(41, 255, 0, 70);  
      strip.setPixelColor(42, 50, 0, 150);  
      strip.setPixelColor(43, 0, 70, 70);  
      strip.setPixelColor(44, 0, 100, 0);  
      strip.setPixelColor(45, 255, 0, 70);  
      strip.setPixelColor(46, 50, 0, 150);  
strip.setPixelColor(47, 0, 70, 70);  
      strip.setPixelColor(48, 255, 0, 70);  
      strip.setPixelColor(49, 0, 100, 0);  
      strip.setPixelColor(50, 255, 0, 70);  
      strip.setPixelColor(51, 50, 0, 150);  

  strip.setPixelColor(52, 0, 70, 70);  
      strip.setPixelColor(53, 0, 100, 0);  
      strip.setPixelColor(54, 255, 0, 70);  
      strip.setPixelColor(55, 50, 0, 150);  
      strip.setPixelColor(56, 0, 70, 70);  
      strip.setPixelColor(57, 0, 100, 0);  
      strip.setPixelColor(58, 255, 0, 70);  
      strip.setPixelColor(59, 50, 0, 150);  

      strip.show();
      delay(lng);


    }//close option 7

  }//close if sound level 8

  else if (soundLevel == 9)
  {
    //open if sound level 9

    int level9Color = random(1, 8);

    if (level9Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 255, 0, 0);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 0, 0);  
      strip.setPixelColor(5, 255, 0, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 255, 0, 0);  
      strip.setPixelColor(8, 255, 0, 0);  
      strip.setPixelColor(9, 255, 0, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level9Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 255, 0);  
      strip.setPixelColor(9, 0, 0, 255);  
       strip.setPixelColor(10, 0, 255, 0);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.setPixelColor(12, 0, 255, 0);  
      strip.setPixelColor(13, 0, 0, 255);  
      strip.setPixelColor(14, 0, 255, 0);  
      strip.setPixelColor(15, 0, 0, 255);  
      strip.setPixelColor(16, 0, 255, 0);  
      strip.setPixelColor(17, 0, 0, 255);  
      strip.setPixelColor(18, 0, 255, 0);  
      strip.setPixelColor(19, 0, 0, 255);  
       strip.setPixelColor(20, 0, 255, 0);  
      strip.setPixelColor(21, 0, 0, 255);  
      strip.setPixelColor(22, 0, 255, 0);  
      strip.setPixelColor(23, 0, 0, 255);  
      strip.setPixelColor(24, 0, 255, 0);  
      strip.setPixelColor(25, 0, 0, 255);  
      strip.setPixelColor(26, 0, 255, 0);  
      strip.setPixelColor(27, 0, 0, 255);  
      strip.setPixelColor(28, 0, 255, 0);  
      strip.setPixelColor(29, 0, 0, 255);  
       strip.setPixelColor(30, 0, 255, 0);  
      strip.setPixelColor(31, 0, 0, 255);  
      strip.setPixelColor(32, 0, 255, 0);  
      strip.setPixelColor(33, 0, 0, 255);  
      strip.setPixelColor(34, 0, 255, 0);  
      strip.setPixelColor(35, 0, 0, 255);  
      strip.setPixelColor(36, 0, 255, 0);  
      strip.setPixelColor(37, 0, 0, 255);  
      strip.setPixelColor(38, 0, 255, 0);  
      strip.setPixelColor(39, 0, 0, 255);  
       strip.setPixelColor(40, 0, 255, 0);  
      strip.setPixelColor(41, 0, 0, 255);  
      strip.setPixelColor(42, 0, 255, 0);  
      strip.setPixelColor(43, 0, 0, 255);  
      strip.setPixelColor(44, 0, 255, 0);  
      strip.setPixelColor(45, 0, 0, 255);  
      strip.setPixelColor(46, 0, 255, 0);  
      strip.setPixelColor(47, 0, 0, 255);  
      strip.setPixelColor(48, 0, 255, 0);  
      strip.setPixelColor(49, 0, 0, 255);  
       strip.setPixelColor(50, 0, 255, 0);  
      strip.setPixelColor(51, 0, 0, 255);  
      strip.setPixelColor(52, 0, 255, 0);  
      strip.setPixelColor(53, 0, 0, 255);  
      strip.setPixelColor(54, 0, 255, 0);  
      strip.setPixelColor(55, 0, 0, 255);  
      strip.setPixelColor(56, 0, 255, 0);  
      strip.setPixelColor(57, 0, 0, 255);  
      strip.setPixelColor(58, 0, 255, 0);  
      strip.setPixelColor(59, 0, 0, 255);  
      
       
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level9Color == 3) //run blue
    {
      //open option 3
      strip.setPixelColor(0, 255, 0, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 255, 0, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 255, 0, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 255, 0, 255);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 255, 0, 255);  
      strip.setPixelColor(9, 0, 0, 255);  
      strip.setPixelColor(10, 255, 0, 255);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.setPixelColor(12, 255, 0, 255);  
      strip.setPixelColor(13, 0, 0, 255);  
      strip.setPixelColor(14, 255, 0, 255);  
      strip.setPixelColor(15, 0, 0, 255);  
      strip.setPixelColor(16, 255, 0, 255);  
      strip.setPixelColor(17, 0, 0, 255);  
      strip.setPixelColor(18, 255, 0, 255);  
      strip.setPixelColor(19, 0, 0, 255);  
     
     strip.setPixelColor(10, 255, 0, 255);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.setPixelColor(12, 255, 0, 255);  
      strip.setPixelColor(13, 0, 0, 255);  
      strip.setPixelColor(14, 255, 0, 255);  
      strip.setPixelColor(15, 0, 0, 255);  
      strip.setPixelColor(16, 255, 0, 255);  
      strip.setPixelColor(17, 0, 0, 255);  
      strip.setPixelColor(18, 255, 0, 255);  
      strip.setPixelColor(19, 0, 0, 255);  
     
     strip.setPixelColor(20, 255, 0, 255);  
      strip.setPixelColor(21, 0, 0, 255);  
      strip.setPixelColor(22, 255, 0, 255);  
      strip.setPixelColor(23, 0, 0, 255);  
      strip.setPixelColor(24, 255, 0, 255);  
      strip.setPixelColor(25, 0, 0, 255);  
      strip.setPixelColor(26, 255, 0, 255);  
      strip.setPixelColor(27, 0, 0, 255);  
      strip.setPixelColor(28, 255, 0, 255);  
      strip.setPixelColor(29, 0, 0, 255);  
     
     strip.setPixelColor(30, 255, 0, 255);  
      strip.setPixelColor(31, 0, 0, 255);  
      strip.setPixelColor(32, 255, 0, 255);  
      strip.setPixelColor(33, 0, 0, 255);  
      strip.setPixelColor(34, 255, 0, 255);  
      strip.setPixelColor(35, 0, 0, 255);  
      strip.setPixelColor(36, 255, 0, 255);  
      strip.setPixelColor(37, 0, 0, 255);  
      strip.setPixelColor(38, 255, 0, 255);  
      strip.setPixelColor(39, 0, 0, 255);  
     
     strip.setPixelColor(40, 255, 0, 255);  
      strip.setPixelColor(41, 0, 0, 255);  
      strip.setPixelColor(42, 255, 0, 255);  
      strip.setPixelColor(43, 0, 0, 255);  
      strip.setPixelColor(44, 255, 0, 255);  
      strip.setPixelColor(45, 0, 0, 255);  
      strip.setPixelColor(46, 255, 0, 255);  
      strip.setPixelColor(47, 0, 0, 255);  
      strip.setPixelColor(48, 255, 0, 255);  
      strip.setPixelColor(49, 0, 0, 255);  
     
     strip.setPixelColor(50, 255, 0, 255);  
      strip.setPixelColor(51, 0, 0, 255);  
      strip.setPixelColor(52, 255, 0, 255);  
      strip.setPixelColor(53, 0, 0, 255);  
      strip.setPixelColor(54, 255, 0, 255);  
      strip.setPixelColor(55, 0, 0, 255);  
      strip.setPixelColor(56, 255, 0, 255);  
      strip.setPixelColor(57, 0, 0, 255);  
      strip.setPixelColor(58, 255, 0, 255);  
      strip.setPixelColor(59, 0, 0, 255);  
     
     

     
      strip.show();
      delay(lng);
    }//close option 3blue

    else if (level9Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 255, 255, 0);  
      strip.setPixelColor(7, 255, 255, 0);  
      strip.setPixelColor(8, 255, 255, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level9Color == 5)
    {
      //open option 5
      colorWipe(strip.Color(255, 255, 255), 60); // white
      colorWipe(strip.Color(0, 206, 209), 20); // turquoise
      strip.show();
    }//close option 5

    else if (level9Color == 6)
    {
      //open option 6

      theaterChase(strip.Color(50, 190, 209), 50); // turquise
      strip.show();
      delay(lng);
    }//close option 6

    else if (level9Color == 7)
    {
      //open option 7
      strip.setPixelColor(0, 0, 70, 70);  
      strip.setPixelColor(1, 0, 100, 0);  
      strip.setPixelColor(2, 255, 0, 70);  
      strip.setPixelColor(3, 50, 0, 150);  
      strip.setPixelColor(4, 0, 70, 70);  
      strip.setPixelColor(5, 0, 100, 0);  
      strip.setPixelColor(6, 255, 0, 70);  
      strip.setPixelColor(7, 50, 0, 150);  
      strip.setPixelColor(8, 255, 0, 70);  
      strip.setPixelColor(9, 0, 100, 0);  
      strip.setPixelColor(10, 255, 0, 70);  
      strip.setPixelColor(11, 50, 0, 150);  
        strip.setPixelColor(12, 0, 70, 70);  
      strip.setPixelColor(13, 0, 100, 0);  
      strip.setPixelColor(14, 255, 0, 70);  
      strip.setPixelColor(15, 50, 0, 150);  
      strip.setPixelColor(16, 0, 70, 70);  
      strip.setPixelColor(17, 0, 100, 0);  
      strip.setPixelColor(18, 255, 0, 70);  
      strip.setPixelColor(19, 50, 0, 150);  
      strip.setPixelColor(20, 255, 0, 70);  
      strip.setPixelColor(21, 0, 100, 0);  
      strip.setPixelColor(22, 255, 0, 70);  
      strip.setPixelColor(23, 50, 0, 150);    strip.setPixelColor(24, 0, 70, 70);  
      strip.setPixelColor(25, 0, 100, 0);  
      strip.setPixelColor(26, 255, 0, 70);  
      strip.setPixelColor(27, 50, 0, 150);  
      strip.setPixelColor(28, 0, 70, 70);  
      strip.setPixelColor(29, 0, 100, 0);  
      strip.setPixelColor(30, 255, 0, 70);  
      strip.setPixelColor(31, 50, 0, 150);  
      strip.setPixelColor(32, 255, 0, 70);  
      strip.setPixelColor(33, 0, 100, 0);  
      strip.setPixelColor(34, 255, 0, 70);  
      strip.setPixelColor(35, 50, 0, 150);    strip.setPixelColor(39, 0, 70, 70);  
      strip.setPixelColor(36, 0, 100, 0);  
      strip.setPixelColor(37, 255, 0, 70);  
      strip.setPixelColor(38, 50, 0, 150);  
      strip.setPixelColor(40, 0, 70, 70);  
      strip.setPixelColor(41, 0, 100, 0);  
      strip.setPixelColor(42, 255, 0, 70);  
      strip.setPixelColor(43, 50, 0, 150);  
      strip.setPixelColor(44, 255, 0, 70);  
      strip.setPixelColor(45, 0, 100, 0);  
      strip.setPixelColor(46, 255, 0, 70);  
      strip.setPixelColor(47, 50, 0, 150);    strip.setPixelColor(48, 0, 70, 70);  
      strip.setPixelColor(49, 0, 100, 0);  
      strip.setPixelColor(50, 255, 0, 70);  
      strip.setPixelColor(51, 50, 0, 150);  
      strip.setPixelColor(52, 0, 70, 70);  
      strip.setPixelColor(53, 0, 100, 0);  
      strip.setPixelColor(54, 255, 0, 70);  
      strip.setPixelColor(55, 50, 0, 150);  
      strip.setPixelColor(56, 255, 0, 70);  
      strip.setPixelColor(57, 0, 100, 0);  
      strip.setPixelColor(58, 255, 0, 70);  
      strip.setPixelColor(59, 50, 0, 150);   
     

      strip.show();
      delay(lng);

      strip.setPixelColor(0, 0, 255, 255);  
      strip.setPixelColor(1, 0, 255, 255);  
      strip.setPixelColor(2, 0, 0, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 255, 255);  
      strip.setPixelColor(7, 0, 255, 255);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);

      strip.setPixelColor(0, 255, 50, 50);  
      strip.setPixelColor(1, 0, 255, 0);  
      strip.setPixelColor(2, 255, 50, 50);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 50, 50);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 255, 50, 50);  
      strip.setPixelColor(7, 0, 255, 0);  
      strip.setPixelColor(8, 255, 50, 50);  
      strip.setPixelColor(9, 255, 0, 0);  
      strip.setPixelColor(10, 255, 50, 50);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.show();

      delay(lng);


    }//close option 7

    else if (level9Color == 8)
    {
      //open option 8
      strip.setPixelColor(0, 255, 255, 255);  
      strip.setPixelColor(1, 0, 0, 0);  
      strip.setPixelColor(2, 255, 255, 255);  
      strip.setPixelColor(3, 0, 0, 0);  
      strip.setPixelColor(4, 255, 255, 255);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 255, 255, 255);  
      strip.setPixelColor(7, 0, 0, 0);  
      strip.setPixelColor(8, 255, 255, 255);  
      strip.setPixelColor(9, 0, 0, 0);  
      strip.setPixelColor(10, 255, 255, 255);  
      strip.setPixelColor(11, 0, 0, 0);  

      strip.show();
      delay (lng);

      strip.setPixelColor(0, 0, 0, 0);  
      strip.setPixelColor(1, 255, 255, 255);  
      strip.setPixelColor(2, 0, 0, 0);  
      strip.setPixelColor(3, 255, 255, 255);  
      strip.setPixelColor(4, 0, 0, 0);  
      strip.setPixelColor(5, 255, 255, 255);  
      strip.setPixelColor(6, 0, 0, 0);  
      strip.setPixelColor(7, 255, 255, 255);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 255, 255, 255);  
      strip.setPixelColor(10, 0, 0, 0);  
      strip.setPixelColor (11, 255, 255, 255);  

      strip.show();
      delay(lng);


    }//close option 9

  }//close if sound level 9

  else if (soundLevel == 10)

  {
    //open if sound Level 10

    int level10Color = random(1, 8);

    if (level10Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 255, 0, 0);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 0, 0);  
      strip.setPixelColor(5, 255, 0, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 255, 0, 0);  
      strip.setPixelColor(8, 255, 0, 0);  
      strip.setPixelColor(9, 255, 0, 0);  
      strip.setPixelColor(10, 255, 0, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level10Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 255, 0);  
      strip.setPixelColor(9, 0, 0, 255);  
      strip.setPixelColor(10, 0, 255, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 2 green

    else if (level10Color == 3) //run blue
    {
      //open option 3

      strip.setPixelColor(0, 0, 206, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 206, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 206, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 206, 255);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 206, 255);  
      strip.setPixelColor(9, 0, 0, 255);  
      strip.setPixelColor(10, 0, 206, 255);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level10Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 255, 255, 0);  
      strip.setPixelColor(7, 255, 255, 0);  
      strip.setPixelColor(8, 255, 255, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level10Color == 5)
    {
      //open option 5

      colorWipe(strip.Color(200, 40, 147), 50); // pink
      colorWipe(strip.Color(0, 206, 209), 20); // turquoise
      strip.show();
      delay(sht);
    }//close option 5

    else if (level10Color == 6)
    {
      //open option 6
      theaterChase(strip.Color(0, 206, 209), 50);
      strip.show();
      delay(sht);
    }//close option 6

    else if (level10Color == 7)
    {
      //open option 7
      strip.setPixelColor(0, 0, 70, 70);  
      strip.setPixelColor(1, 0, 100, 0);  
      strip.setPixelColor(2, 255, 0, 70);  
      strip.setPixelColor(3, 50, 0, 150);  
      strip.setPixelColor(4, 0, 70, 70);  
      strip.setPixelColor(5, 0, 100, 0);  
      strip.setPixelColor(6, 255, 0, 70);  
      strip.setPixelColor(7, 50, 0, 150);  
      strip.setPixelColor(8, 255, 0, 70);  
      strip.setPixelColor(9, 0, 100, 0);  
      strip.setPixelColor(10, 255, 0, 70);  
      strip.setPixelColor(11, 50, 0, 150);  

      strip.show();
      delay(lng);

      strip.setPixelColor(0, 0, 255, 255);  
      strip.setPixelColor(1, 0, 255, 255);  
      strip.setPixelColor(2, 0, 0, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 255, 255);  
      strip.setPixelColor(7, 0, 255, 255);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);

      strip.setPixelColor(0, 255, 255, 255);  
      strip.setPixelColor(1, 255, 255, 255);  
      strip.setPixelColor(2, 255, 255, 255);  
      strip.setPixelColor(3, 255, 255, 255);  
      strip.setPixelColor(4, 255, 255, 255);  
      strip.setPixelColor(5, 255, 255, 255);  
      strip.setPixelColor(6, 255, 255, 255);  
      strip.setPixelColor(7, 255, 255, 255);  
      strip.setPixelColor(8, 255, 255, 255);  
      strip.setPixelColor(9, 255, 255, 255);  
      strip.setPixelColor(10, 255, 255, 255);  
      strip.setPixelColor(11, 255, 255, 255);  
      strip.show();
      delay(sht);

    }//close option 7

  }//close if sound level 10


  else if (soundLevel == 11)

  {
    //open if sound Level 11

    int level11Color = random(1, 8);

    if (level11Color == 1) //run red
    {
      //open option 1

      strip.setPixelColor(0, 255, 0, 0);  
      strip.setPixelColor(1, 255, 0, 0);  
      strip.setPixelColor(2, 255, 0, 0);  
      strip.setPixelColor(3, 255, 0, 0);  
      strip.setPixelColor(4, 255, 0, 0);  
      strip.setPixelColor(5, 255, 0, 0);  
      strip.setPixelColor(6, 255, 0, 0);  
      strip.setPixelColor(7, 255, 0, 0);  
      strip.setPixelColor(8, 255, 0, 0);  
      strip.setPixelColor(9, 255, 0, 0);  
      strip.setPixelColor(10, 255, 0, 0);  
      strip.setPixelColor(11, 255, 0, 0);  
      strip.show();
      delay(lng);
    }//close option 1 red

    else if (level11Color == 2) //run green
    {
      //open option 2

      strip.setPixelColor(0, 0, 255, 0);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 255, 0);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 255, 0);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 255, 0);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 255, 0);  
      strip.setPixelColor(9, 0, 0, 255);  
      strip.setPixelColor(10, 0, 255, 0);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.show();
      delay(lng);
    }//close option 2  green

    else if (level11Color == 3) //run blue
    {
      //open option 3

      strip.setPixelColor(0, 0, 206, 255);  
      strip.setPixelColor(1, 0, 0, 255);  
      strip.setPixelColor(2, 0, 206, 255);  
      strip.setPixelColor(3, 0, 0, 255);  
      strip.setPixelColor(4, 0, 206, 255);  
      strip.setPixelColor(5, 0, 0, 255);  
      strip.setPixelColor(6, 0, 206, 255);  
      strip.setPixelColor(7, 0, 0, 255);  
      strip.setPixelColor(8, 0, 206, 255);  
      strip.setPixelColor(9, 0, 0, 255);  
      strip.setPixelColor(10, 0, 206, 255);  
      strip.setPixelColor(11, 0, 0, 255);  
      strip.show();
      delay(lng);
    }//close option 3 blue

    else if (level11Color == 4) //run yellow
    {
      //open option 4

      strip.setPixelColor(0, 255, 255, 0);  
      strip.setPixelColor(1, 255, 255, 0);  
      strip.setPixelColor(2, 255, 255, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 255, 255, 0);  
      strip.setPixelColor(6, 255, 255, 0);  
      strip.setPixelColor(7, 255, 255, 0);  
      strip.setPixelColor(8, 255, 255, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 255, 255, 0);  
      strip.show();
      delay(lng);
    }//close option 4 yellow

    else if (level11Color == 5)
    {
      //open option 5

      colorWipe(strip.Color(0, 40, 255), 50); // pink
      colorWipe(strip.Color(0, 209, 206), 20); // turquoise
      strip.show();
      delay(sht);
    }//close option 5

    else if (level11Color == 6) //open option 6
    {
      //open option 6
      theaterChase(strip.Color(0, 206, 109), 50);
      strip.show();
      delay(sht);
    }//close option 6

    else if (level11Color == 7)//open option 7
    {
      //open option 7
      strip.setPixelColor(0, 0, 70, 70);  
      strip.setPixelColor(1, 0, 100, 0);  
      strip.setPixelColor(2, 255, 0, 70);  
      strip.setPixelColor(3, 50, 0, 150);  
      strip.setPixelColor(4, 0, 70, 70);  
      strip.setPixelColor(5, 0, 100, 0);  
      strip.setPixelColor(6, 255, 0, 70);  
      strip.setPixelColor(7, 50, 0, 150);  
      strip.setPixelColor(8, 255, 0, 70);  
      strip.setPixelColor(9, 0, 100, 0);  
      strip.setPixelColor(10, 255, 0, 70);  
      strip.setPixelColor(11, 50, 0, 150);  

      strip.show();
      delay(lng);

      strip.setPixelColor(0, 0, 255, 255);  
      strip.setPixelColor(1, 0, 255, 255);  
      strip.setPixelColor(2, 0, 0, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 255, 255);  
      strip.setPixelColor(7, 0, 255, 255);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 0, 0, 0);  
      strip.show();
      delay(lng);

      strip.setPixelColor(0, 255, 255, 255);  
      strip.setPixelColor(1, 255, 255, 255);  
      strip.setPixelColor(2, 255, 255, 255);  
      strip.setPixelColor(3, 255, 255, 255);  
      strip.setPixelColor(4, 255, 255, 255);  
      strip.setPixelColor(5, 255, 255, 255);  
      strip.setPixelColor(6, 255, 255, 255);  
      strip.setPixelColor(7, 255, 255, 255);  
      strip.setPixelColor(8, 255, 255, 255);  
      strip.setPixelColor(9, 255, 255, 255);  
      strip.setPixelColor(10, 255, 255, 255);  
      strip.setPixelColor(11, 255, 255, 255); 
      strip.setPixelColor(12, 255, 255, 255);  
      strip.setPixelColor(13, 255, 255, 255);  
      strip.setPixelColor(14, 255, 255, 255);  
      strip.setPixelColor(15, 255, 255, 255);  
      strip.setPixelColor(16, 255, 255, 255);  
      strip.setPixelColor(17, 255, 255, 255);  
      strip.setPixelColor(18, 255, 255, 255);  
      strip.setPixelColor(19, 255, 255, 255);  
      strip.setPixelColor(20, 255, 255, 255);  
      strip.setPixelColor(21, 255, 255, 255);  
      strip.setPixelColor(22, 255, 255, 255);  
      strip.setPixelColor(23, 255, 255, 255); 
       strip.setPixelColor(24, 255, 255, 255);  
      strip.setPixelColor(25, 255, 255, 255);  
      strip.setPixelColor(26, 255, 255, 255);  
      strip.setPixelColor(27, 255, 255, 255);  
      strip.setPixelColor(28, 255, 255, 255);  
      strip.setPixelColor(29, 255, 255, 255);  
      strip.setPixelColor(30, 255, 255, 255);  
      strip.setPixelColor(31, 255, 255, 255);  
      strip.setPixelColor(32, 255, 255, 255);  
      strip.setPixelColor(33, 255, 255, 255);  
      strip.setPixelColor(34, 255, 255, 255);  
      strip.setPixelColor(35, 255, 255, 255); 
      strip.setPixelColor(36, 255, 255, 255);  
      strip.setPixelColor(37, 255, 255, 255);  
      strip.setPixelColor(38, 255, 255, 255);  
      strip.setPixelColor(39, 255, 255, 255);  
      strip.setPixelColor(40, 255, 255, 255);  
      strip.setPixelColor(41, 255, 255, 255);  
      strip.setPixelColor(42, 255, 255, 255);  
      strip.setPixelColor(43, 255, 255, 255);  
      strip.setPixelColor(44, 255, 255, 255);  
      strip.setPixelColor(45, 255, 255, 255);  
      strip.setPixelColor(46, 255, 255, 255);  
      strip.setPixelColor(47, 255, 255, 255);  
      strip.setPixelColor(48, 255, 255, 255);  
      strip.setPixelColor(49, 255, 255, 255);  
      strip.setPixelColor(50, 255, 255, 255);  
      strip.setPixelColor(51, 255, 255, 255);  
      strip.setPixelColor(52, 255, 255, 255);  
      strip.setPixelColor(53, 255, 255, 255);  
      strip.setPixelColor(54, 255, 255, 255);  
      strip.setPixelColor(55, 255, 255, 255);  
      strip.setPixelColor(56, 255, 255, 255);  
      strip.setPixelColor(57, 255, 255, 255);  
      strip.setPixelColor(58, 255, 255, 255);  
      strip.setPixelColor(59, 255, 255, 255);  
     
        
      strip.show();
      delay(lng);

      strip.setPixelColor(0, 0, 255, 255);  
      strip.setPixelColor(1, 0, 255, 255);  
      strip.setPixelColor(2, 0, 0, 0);  
      strip.setPixelColor(3, 255, 255, 0);  
      strip.setPixelColor(4, 255, 255, 0);  
      strip.setPixelColor(5, 0, 0, 0);  
      strip.setPixelColor(6, 0, 255, 255);  
      strip.setPixelColor(7, 0, 255, 255);  
      strip.setPixelColor(8, 0, 0, 0);  
      strip.setPixelColor(9, 255, 255, 0);  
      strip.setPixelColor(10, 255, 255, 0);  
      strip.setPixelColor(11, 0, 0, 0); 
      strip.setPixelColor(12, 0, 255, 255);  
      strip.setPixelColor(13, 0, 255, 255);  
      strip.setPixelColor(14, 0, 0, 0);  
      strip.setPixelColor(15, 255, 255, 0);  
      strip.setPixelColor(16, 255, 255, 0);  
      strip.setPixelColor(17, 0, 0, 0);  
      strip.setPixelColor(18, 0, 255, 255);  
      strip.setPixelColor(19, 0, 255, 255);  
      strip.setPixelColor(20, 0, 0, 0);  
      strip.setPixelColor(21, 255, 255, 0);  
      strip.setPixelColor(22, 255, 255, 0);  
      strip.setPixelColor(23, 0, 0, 0);  
      strip.setPixelColor(24, 0, 255, 255);  
      strip.setPixelColor(25, 0, 0, 0);  
      strip.setPixelColor(26, 255, 255, 0);  
      strip.setPixelColor(27, 255, 255, 0);  
      strip.setPixelColor(28, 0, 0, 0);  
      strip.setPixelColor(29, 0, 255, 255);  
      strip.setPixelColor(30, 0, 255, 255);  
      strip.setPixelColor(31, 0, 0, 0);  
      strip.setPixelColor(32, 255, 255, 0);  
      strip.setPixelColor(33, 255, 255, 0);  
      strip.setPixelColor(34, 0, 0, 0);  
      strip.setPixelColor(35, 0, 255, 255);  
      strip.setPixelColor(36, 0, 0, 0);  
      strip.setPixelColor(37, 255, 255, 0);  
      strip.setPixelColor(38, 255, 255, 0);  
      strip.setPixelColor(39, 0, 0, 0);  
      strip.setPixelColor(40, 0, 255, 255);  
      strip.setPixelColor(41, 0, 255, 255);  
      strip.setPixelColor(42, 0, 0, 0);  
      strip.setPixelColor(43, 255, 255, 0);  
      strip.setPixelColor(44, 255, 255, 0);  
      strip.setPixelColor(45, 0, 0, 0);  strip.setPixelColor(46, 0, 255, 255);  
      strip.setPixelColor(47, 0, 255, 255);  
      strip.setPixelColor(48, 0, 0, 0);  
      strip.setPixelColor(49, 255, 255, 0);  
      strip.setPixelColor(50, 255, 255, 0);  
      strip.setPixelColor(51, 0, 0, 0);  
      strip.setPixelColor(52, 0, 255, 255);  
      strip.setPixelColor(53, 0, 255, 255);  
      strip.setPixelColor(54, 0, 0, 0);  
      strip.setPixelColor(55, 255, 255, 0);  
      strip.setPixelColor(56, 255, 255, 0);  
      strip.setPixelColor(57, 0, 0, 0);   
      strip.show();
      delay(lng);

    }//close option 7

  }//close if sound level 11

}//close void loop()

//neopixel functions below



void colorWipe(uint32_t c, uint8_t wait)
{
  //open colowipe
  for(uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}//close colorWipe function

void theaterChase(uint32_t c, uint8_t wait)
{
  //open theaterchase function
  for (int j = 0; j < 3; j++) //do 3 cycles of chasing
  {
    for (int q = 0; q < 3; q++)
    {
      for (int i = 0; i < strip.numPixels(); i = i + 3)
      {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i = 0; i < strip.numPixels(); i = i + 3)
      {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}//close theater chase function

void rainbowCycle(uint8_t wait)  //open rainbow function
{
  uint16_t i, j;

  for(j = 0; j < 256; j++) // 1 cycles of all colors on wheel
  {
    for(i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}//close rainbow function
//you need to included the code below for the neopixel functions that use the 'wheel' code:
uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85)
  {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170)
  {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

//end
