
#include "Keyboard.h"
#include "Mouse.h"

int pause = 500;

void typeKey(int key){
  Keyboard.press(key);
  delay(5);
  Keyboard.release(key);
}

void setup(){
    Keyboard.begin();
    Mouse.begin();
    delay(pause);
    openSpotlight();
    input("terminal");
    input("osascript -e 'set volume 7'");
    input("open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    Keyboard.end();
}

void input(String cmd){
    Keyboard.print(cmd);
    delay(pause);
    typeKey(KEY_RETURN);
    delay(pause);
}

void openSpotlight(){
    delay(pause);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();
    delay(pause);
}

void loop(){
}
