#include <TimedAction.h>
#include <FastLED.h>

#define NUM_STRIPS 1 //no of led strips
#define NUM_LEDS 3
#define CLOCK_PIN 13

CRGB leds[NUM_STRIPS][NUM_LEDS];

int timerCounter1 = 0;
int timerCounter2 = 0;

void incrementNumber1(){
    Serial.println("process 1");
    Serial.println(timerCounter1);
    timerCounter1 = timerCounter1 + 1;
}

void incrementNumber2(){
    Serial.println("process 2");
    Serial.println(timerCounter2);
    timerCounter2 = timerCounter2 + 1;
    //process6();
}


TimedAction numberThread1 = TimedAction(7000,incrementNumber1);
TimedAction numberThread2 = TimedAction(100,incrementNumber2);

void setup()
{
    FastLED.addLeds<WS2812B, 2, RGB>(leds[0], NUM_LEDS);  // precess 6 & process7 *
    Serial.begin(9600);
}

void loop() 
{
    numberThread1.check();
    numberThread2.check();
    
}

int process6()
{
    for(int i = 3;i<=30;i++)
    {
        leds[0][1] = CRGB(i,3,3);  // Green,RED,BLUE
        FastLED.show();
        leds[0][0] = CRGB(30-i,3,3);  // Green,RED,BLUE
        FastLED.show();
        delay(50);
    }

    for(int i = 30;i>3;i--)
    {
        leds[0][1] = CRGB(i,3,3);  // Green,RED,BLUE
        FastLED.show();
        leds[0][0] = CRGB(30-i,3,3);  // Green,RED,BLUE
        FastLED.show();
        delay(50);  
    }
}
