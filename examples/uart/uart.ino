
#include "DFRobot_SpeechSynthesis.h"
  #include <SoftwareSerial.h>
    SoftwareSerial Serial1(2, 3);  //RX, TX
DFRobot_SpeechSynthesis_UART ss;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  ss.begin(&Serial1);
  ss.setVoice(5); //设置音量0-9
  ss.setSpeed(5); // 设置语速0-9
  ss.setTone(5);  //设置音调0-9
  ss.setSoundType(ss.FEMEAL);//设置发音人 MEAL/FEMEAL
  ss.setEnglishPron(ss.WORD);//设置英文阅读方式 WORD/ALPHABET
  String str1="[v1][h2]verifying flash memory 中国against put your setup code here,四川";
  ss.speskChinese(str1);
}

void loop() {
  // put your main code here, to run repeatedly:

}