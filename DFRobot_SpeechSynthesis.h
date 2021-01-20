/*!
   @file DFRobot_SpeechSynthesis.h
   @brief Basic structure of DFRobot_SpeechSynthesis class
   @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [fengli](li.feng@dfrobot.com)
   @version  V1.0
   @date  2020-08-17
   @get from https://www.dfrobot.com
   @https://github.com/DFRobot/DFRobot_SpeechSynthesis
*/

#ifndef DFROBOT_SPEECHSYNTHESIS_H
#define DFROBOT_SPEECHSYNTHESIS_H
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>
//#define ENABLE_DBG
// #include <SoftwareSerial.h>
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define I2C_ADDR               0x40  //i2c address
#define INQUIRYSTATUS          0x21
#define ENTERSAVEELETRI        0x88
#define WAKEUP                 0xFF

#define START_SYNTHESIS        0x01
#define START_SYNTHESIS1       0x02
#define STOP_SYNTHESIS         0x02
#define PAUSE_SYNTHESIS        0x03
#define RECOVER_SYNTHESIS      0x04

class DFRobot_SpeechSynthesis {
public:
  #define ERR_OK             0      //No error
  #define ERR_DATA_BUS      -1      //Data bus error
  #define ERR_IC_VERSION    -2      //Chip version does not match



  /**！
    Speech Synthesis style 
  */
  typedef enum{
    CATON,/**<Word by word>*/
    SMOOTH,/**<Fluently>*/
  } eSpeechStyle_t;
  
  /**
    Whether synthesize PinYin
  */
  typedef enum{
    PINYIN_ENABLE,/**<合成>*/
    PINYIN_DISABLE,/**<不合成>*/
  } ePinyin_t;
  
  /**
    设置阿拉伯数字、度量单位、特殊符号等合成为中文或英文
  */
  typedef enum{
    CHINESEL,/**<成为中文>*/
    ENGLISHL,/**<成为英文>*/
    AUTOJUDGEL,/**<自动判断>*/
  } eLanguage_t;
  
  /**
    一串数字的读法
  */
  typedef enum{
    NUMBER,/**<电话号码>*/
    NUMERIC,/**<数值>*/
    AUTOJUDGED,/**<自动判断>*/
  } eDigitalPron_t;
  
  /**
    语音合成时"零"的读法
  */
  typedef enum{
    ZREO,/**<读作'zero'>*/
    OU,/**<读作'ou'>*/
  } eZeroPron_t;

  /**
    语音合成时"一"的读法
  */
  typedef enum{
    YAO,/**<读作'yao'>*/
    CHONE,/**<读作'yi'>*/
  } eOnePron_t;
  
  /**
    姓的读法
  */
  typedef enum{
    NAME,/**<强制把所有的姓的汉字读作姓的读法>*/
    AUTOJUDGEDN,/**<自动判断>*/
  } eNamePron_t;
  
  /**
    语音合成的声音的选择
  */
  typedef enum{
    FEMALE1,/**<女声1，推荐发音人>*/
    MALE1,/**<男声1，推荐发音人>*/
    FEMALE2,/**<女声2>*/
    MALE2,/**<男声2>*/
    DONALDDUCK,/**<唐老鸭的声音>*/
    FEMALE3,/**<女声3>*/
  } eSoundType_t;

  /**
    英文的阅读方式
  */
  typedef enum{
   ALPHABET,/**<拼写>*/
   WORD,/**<单词>*/
  } eENpron_t;
  
  typedef enum{
    CHINESE,
    ENGLISH,
    NONE,
  } eState_t;
  
public:
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
private:


  uint8_t *_utf8;
  uint8_t *_unicode;
  uint16_t uniLen = 0;
  uint16_t _index=0;
  uint16_t _len=0;

  eState_t curState = NONE;
  eState_t lastState = NONE;
  bool lanChange = false;
  uint16_t getWordLen();
  virtual uint8_t readACK()= 0;
  void sendPack(uint8_t cmd,uint8_t* data =NULL,uint16_t len = 0);

  virtual uint8_t sendCommand(uint8_t *data,uint8_t length)=0;
  virtual uint8_t sendCommand(uint8_t *head,uint8_t *data,uint8_t length)=0;

};


class DFRobot_SpeechSynthesis_I2C :public DFRobot_SpeechSynthesis{
public:
  DFRobot_SpeechSynthesis_I2C(TwoWire *pWire = &Wire, uint8_t address = I2C_ADDR);
  ~DFRobot_SpeechSynthesis_I2C();
  bool begin();
private:
  uint8_t _deviceAddr;
  TwoWire *_pWire;
  //Stream none;
  uint8_t readACK();
  uint8_t sendCommand(uint8_t *data,uint8_t length);
  uint8_t sendCommand(uint8_t *head,uint8_t *data,uint8_t length);
};


class DFRobot_SpeechSynthesis_UART :public DFRobot_SpeechSynthesis{
public:
  DFRobot_SpeechSynthesis_UART();
  
  bool begin(Stream &s);

private:
  uint8_t readACK();
  uint8_t sendCommand(uint8_t *data,uint8_t length);
  uint8_t sendCommand(uint8_t *head,uint8_t *data,uint8_t length);
  
  Stream *_s;
  uint32_t _baudRate;
};







#endif
