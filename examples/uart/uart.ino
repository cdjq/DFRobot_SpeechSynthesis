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
  Serial1.begin(115200);
  //设置语音的音量大小为5
  //ss.setVoice(5);
  //设置语音的播放速度为5
  //ss.setSpeed(5);
  //设置发音人为女性
  //ss.setSoundType(ss.FEMALE);
  //设置音调为5
  //ss.setTone(5);
  //设置英文以单词发音
  //ss.setEnglishPron(ss.WORD);

  //初始化语音合成传感器
  ss.begin(Serial1);
}

void loop() {
  ss.speak(F("黑灰化肥发灰黑会挥发"));
  ss.speak(F("Hello, I'm Speech Synthesis module"));
  ss.speak(F("duck不必"));
  ss.speak(F("a b c d e f g"));

  /*使用文本控制标识控制*/
  //音量标识
  //ss.speak(F("[v3]Hello [v8]world"));
  //单词发音方式标识
  //ss.speak(F("[h1]Hello [h2]world"));
}
