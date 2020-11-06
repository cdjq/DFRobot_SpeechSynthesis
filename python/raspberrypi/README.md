# DFRobot SpeechSynthesis concentration sensor



## DFRobot SpeechSynthesis Library for RaspberryPi

Provide the Raspberry Pi library for the DFRobot_alcohol module.

## Table of Contents

* [Summary](#summary)
* [Feature](#feature)
* [Installation](#installation)
* [Methods](#methods)
* [History](#history)
* [Credits](#credits)

## Summary

   1.合成语音<br>

## Feature

  1. <br>
  2. <br>

## Installation

This Sensor should work with DFRobot_SpeechSynthesis on RaspberryPi. <br>
Run the program:

```
$> python get_alcohol_data.py
```

## Methods

```py

  def speak(self ,string):
    '''
      @brief 合成语音
      @param string: 要合成的内容，可以是中文，英文，数字等
    '''

  def setVoice(self, voc):
    '''
      @brief 设置语音的音量大小
      @param voc: 音量数值(0-9)
    '''
  def setSpeed(self, speed):
    '''
      @brief 设置语音的播放速度
      @param speed: 速度数值(0-9)
    '''
  def setSoundType(self, type):
    '''
      @brief 设置声音种类
      @param type:(MALE:男,FEMALE:女,DONALDDUCK:唐老鸭)
    '''
  def setTone(self, tone):
    '''
      @brief 设置音调
      @param tone:音调数值(0-9)
    '''
  def setEnglishPron(self, pron): 
    '''
      @brief 设置英文发音
      @param pron:(ALPHABET:以字母单个发音,WORD:以单词发音)
    '''
```
## History

- data 2020-11-6
- version V1.0


## Credits

Written by fengli(li.feng@dfrobot.com), 2020.11.6 (Welcome to our [website](https://www.dfrobot.com/))