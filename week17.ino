/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
const int interruptNumber = 0;
const int ledPin =  13;  
const int buttonPin1 = 2;  
const int buttonPin2 = 3; 
int state = 0;
int buttonState1 = 0;
int buttonState2 = 0;
volatile boolean buttonState = LOW;
// notes in the melody:
int melody[] = {
  NOTE_G5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5
};
int melody1[] = {
  NOTE_E6, NOTE_C6, NOTE_D6, NOTE_G5, NOTE_G5, NOTE_D6, NOTE_E6, NOTE_C6
};
int melody2[] = {
  NOTE_C5, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2
};
int noteDurations1[] = {
  2, 2, 2, 1, 2, 2, 2, 1,
};

int num = 13;
int num1 = 8;

void buttonStateChanged() {
  state =! state; 
  
}

void setup() {
  Serial.begin(9600);
  // iterate over the notes of the melody:
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin1, INPUT); 
    pinMode(buttonPin2, INPUT); 
    attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
}

void loop() {
  buttonState = digitalRead(buttonPin1);
  
  
  if (state == HIGH) {
    int num = 13;
    for (int thisNote = 0; thisNote < num; thisNote++) {
      buttonState = digitalRead(buttonPin1);
      Serial.print(buttonState);Serial.print('\t');Serial.println(state);
      attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
      if (state == LOW){num=0;}
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
   }
  if (state == LOW) {
    noTone(8);
    int num1 = 8;
    for (int thisNote = 0; thisNote < num1; thisNote++) {
      buttonState = digitalRead(buttonPin1);
      Serial.print(buttonState);Serial.print('\t');Serial.println(state);
      attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
      if (state == HIGH){num1=0;}
    int noteDuration1 = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);
    int pauseBetweenNotes = noteDuration1 * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
   }   
/*
      noTone(8);
    int num1 = 8;
    for (int thisNote = 0; thisNote < num1; thisNote++) {
    int noteDuration1 = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);
    int pauseBetweenNotes = noteDuration1 * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
*/
  /*
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH) {
    noTone(8);
    int num = 13;
    for (int thisNote = 0; thisNote < num; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    digitalWrite(ledPin, HIGH);
    int pauseBetweenNotes = noteDuration * 1.10;
    delay(pauseBetweenNotes);
    digitalWrite(ledPin, LOW);
    int ledPindelay = noteDuration * 0.20;
    delay(ledPindelay);
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 == HIGH){num=0;}
    noTone(8);
    }
  }
    if (buttonState2 == HIGH) {
    noTone(8);
    int num1 = 8;
    for (int thisNote = 0; thisNote < num1; thisNote++) {
    int noteDuration1 = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);
    digitalWrite(ledPin, HIGH);
    int pauseBetweenNotes = noteDuration1 * 1.10;
    delay(pauseBetweenNotes);
    digitalWrite(ledPin, LOW);
    int ledPindelay1 = noteDuration1 * 0.20;
    delay(ledPindelay1);
    buttonState1 = digitalRead(buttonPin1);
    if (buttonState1 == HIGH){num1=0;}
    noTone(8);
    }
  }*/
}


