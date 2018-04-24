#include "Keyboard.h"
#include "Mouse.h"

int pause = 400;

void typeKey(int key){
  Keyboard.press(key);
  delay(5);
  Keyboard.release(key);
}

void setup(){
    Keyboard.begin();
    Mouse.begin();
  
    openSpotlight();
    Keyboard.print("terminal");

    delay(pause);
    typeKey(KEY_RETURN);

    delay(pause);
    Keyboard.print("defaults write com.apple.finder AppleShowAllFiles true");

    delay(pause);
    typeKey(KEY_RETURN);

    killAndRestartFinder();
    clearup();
    
    Keyboard.end();
}

void killAndRestartFinder(){
    delay(pause);
    Keyboard.print("killall Finder");
    delay(pause);
    typeKey(KEY_RETURN);

    openSpotlight();
    Keyboard.print("Finder");    
    delay(pause);
    typeKey(KEY_RETURN);
}

void openSpotlight(){
    delay(pause);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();
    delay(pause);
}

void clearup(){
    delay(pause);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(pause);
    Keyboard.print("terminal");
    delay(pause);
    typeKey(KEY_RETURN);

    delay(pause);
    Keyboard.print("clear");
    typeKey(KEY_RETURN);

    delay(pause);
    Keyboard.print("killall Terminal");
    delay(pause);
    typeKey(KEY_RETURN);
}

void loop(){
}
