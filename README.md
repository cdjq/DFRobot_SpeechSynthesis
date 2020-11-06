# DFRobot_SpeechSynthesis
  
![正反面svg效果图](https://github.com/ouki-wang/DFRobot_Sensor/raw/master/resources/images/SEN0245svg1.png)

## 产品链接（链接到英文商城）
    SKU：<br>
   
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

   1.合成语音<br>


## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
    
  /**
     @brief 构造函数
     @param pWire I2C总线指针对象，构造设备，可传参数也可不传参数，默认Wire
     @param address 7位I2C地址,由前三位决定地址的值，默认0x50
  */
  DFRobot_SpeechSynthesis();
  
  /**
     @brief 语音合成函数
     @param word 要合成的内容，可以是中文，英文，数字等
  */
  void speak(String word);
  
  /**
     @brief 让传感器进入休眠状态
  */
  void sleep();
  
  /**
     @brief 让传感器进入结束休眠状态
  */
  void wakeup();
  
  /**
     @brief 设置语音的音量大小
     @param voc,音量数值(0-9)
  */
  void setVoice(uint8_t voc);
  
  /**
     @brief 设置语音的播放速度
     @param speed,速度数值(0-9)
  */
  void setSpeed(uint8_t speed);

  /**
     @brief 设置声音种类
     @param type(MALE:男,FEMALE:女,DONALDDUCK:唐老鸭)
  */
  void setSoundType(eSoundType_t type);

  /**
     @brief 设置音调
     @param tone,音调数值(0-9)
  */
  void setTone(uint8_t tone);

  /**
     @brief 设置英文发音
     @param pron(ALPHABET:以字母单个发音,WORD:以单词发音)
  */
  void setEnglishPron(eENpron_t pron);
  
  /**
     @brief 恢复默认设置
  */
  void reset();
  
  /**
     @brief 使能韵律的内容的处理
     @param enable(true:处理,false:不处理)
  */
  void enableRhythm(bool enable);
  
  /**
     @brief 设置号码中"1"的读音
     @param pron(YAO:读作"yao",CHONE:读作"yi")
  */
  void setOnePron(eOnePron_t pron);
  
  /**
     @brief 设置是否强制使用姓氏读音规则
     @param pron(NAME：强制,AUTOJUDGEDN:自动判断)
  */
  void setNamePron(eNamePron_t pron);
  
  /**
     @brief 设置号码中"0"的读音
     @param pron(ZREO:读作"zero",OU:读作"ou")
  */
  void setZeroPron(eZeroPron_t pron);
  
  /**
     @brief 设置阿拉伯数字、度量单位、特殊符号等合成为中文或英文
     @param style(CHINESEL:中文,ENGLISHL:英文,AUTOJUDGEL:自动判断)
  */
  void setLanguage(eLanguage_t style);
  
  /**
     @brief 使能拼音的合成
     @param enable(true:使能,false:不使能)
  */
  void enablePINYIN(bool enable);
  
  /**
     @brief 设置合成风格
     @param enable(CATON:一字一顿,SMOOTH:流畅)
  */
  void setSpeechStyle(eSpeechStyle_t style);
  
  /**
     @brief 设置一串数字的读法
     @param pron(NUMBER:电话号码型,NUMERIC:数值型,AUTOJUDGED:自动判断)
  */
  void setDigitalPron(eDigitalPron_t pron);
  
  /**
     @brief 停止合成
  */
  void stopSynthesis();
  /**
     @brief 暂停合成
  */
  void pauseSynthesis();

  /**
     @brief 恢复合成
  */
  void recoverSynthesis();
  
  /**
     @brief 等待语音合成完成
  */
  void wait();
  
  /**
     @brief 合成英文字符串
  */
  void speakElish(String word);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 
micro:bit        |      √       |              |             | 


## History

- data 2020-11-6
- version V1.0


## Credits

Written by fengli(li.feng@dfrobot.com), 2020.11.6 (Welcome to our [website](https://www.dfrobot.com/))





