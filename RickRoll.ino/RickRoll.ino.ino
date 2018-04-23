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
    delay(500);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("terminal");
    delay(100);
    typeKey(KEY_RETURN);
    delay(100);
    Keyboard.print("osascript -e 'set volume 7'");
    delay(100);
    typeKey(KEY_RETURN);
    delay(100);
    Keyboard.print("open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    delay(100);
    typeKey(KEY_RETURN);
    Keyboard.end();
}

void loop(){
}
