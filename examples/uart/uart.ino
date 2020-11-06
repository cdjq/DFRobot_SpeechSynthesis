/*!
 * @file uart.ino
 * @brief 通过uart的方式控制语音合成传感器，并合成语音
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2020-11-6
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_SpeechSynthesis
 */
#include "DFRobot_SpeechSynthesis.h"
#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3);  //RX, TX
DFRobot_SpeechSynthesis_UART ss;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  //初始化语音合成传感器
  //传入通信串口
  ss.begin(Serial);
    // 待合成的字符串
  String str1="verifying flash memory 中国against put your setup code here,四川";
  //合成语音
  ss.speak(str1);
}

void loop() {
  // put your main code here, to run repeatedly:

}