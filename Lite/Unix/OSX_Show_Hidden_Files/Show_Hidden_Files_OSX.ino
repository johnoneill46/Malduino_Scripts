#include "Keyboard.h"
#include "Mouse.h"

int pause = 250;

void setup(){
    Keyboard.begin();
    Mouse.begin();
    delay(500);
    openSpotlight();
    input("terminal");
    input("defaults write com.apple.finder AppleShowAllFiles true");
    killAndRestartFinder();
    clearup();
    Keyboard.end();
}

void input(String cmd){
    Keyboard.print(cmd);
    delay(pause);
    typeKey(KEY_RETURN);
    delay(pause);
}

void typeKey(int key){
    Keyboard.press(key);
    delay(5);
    Keyboard.release(key);
}

void killAndRestartFinder(){
    input("killall Finder");
    openSpotlight();
    input("Finder");
}

void openSpotlight(){
    delay(pause);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();
    delay(pause);
}

void clearup(){
    openSpotlight();
    input("terminal");
    input("clear");
    input("killall Terminal");
}

void loop(){
}
