
#include "Keyboard.h"
#include "Mouse.h"

int defaultCharDelay = 5;

void typeKey(int key){
  Keyboard.press(key);
  delay(defaultCharDelay);
  Keyboard.release(key);
}

void setup(){
   
    Keyboard.begin();
    Mouse.begin();
      
    delay(1000);

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(defaultDelay);
    Keyboard.print("terminal");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(200);
    Keyboard.print("defaults write com.apple.finder AppleShowAllFiles true");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    killAndRestartFinder();
    clearup();
    
    Keyboard.end();
}

void killAndRestartFinder(){
    delay(200);
    Keyboard.print("killall Finder");
    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(200);
    Keyboard.print("Finder");    
    delay(defaultDelay);
    typeKey(KEY_RETURN);
}

void delay(){
    delay(1000);
}

void clearup(){
    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(defaultDelay);
    Keyboard.print("terminal");
    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("clear");
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("killall Terminal");
    delay(defaultDelay);
    typeKey(KEY_RETURN);
}

void loop(){
}
