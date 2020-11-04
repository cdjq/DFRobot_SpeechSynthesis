/*!
   @file DFRobot_SpeechSynthesis.h
   @brief DFRobot_SpeechSynthesis 类的基础结构
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
#define ENABLE_DBG
 #include <SoftwareSerial.h>
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define I2C_ADDR               0x40
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
typedef enum{
  CHINESE,
  ENGLISH,
  NONE,
} eState_t;

typedef enum{
 MEAL,
 FEMEAL,
} eSoundType_t;

typedef enum{
 ALPHABET,
 WORD,
} eENpron_t;

  /**
     @brief 构造函数
     @param pWire I2C总线指针对象，构造设备，可传参数也可不传参数，默认Wire
     @param address 7位I2C地址,由前三位决定地址的值，默认0x50
  */
  DFRobot_SpeechSynthesis();
  
  /**
     @brief 初始化函数
     @param 语音识别模式
     @return 返回0表示初始化成功，返回其他值表示初始化失败，返回错误码
  */
  virtual bool begin(Stream *s=NULL) = 0;
  void speskChinese(String word);
  void speskElish(String word);
  void sleep();
  void wakeup();
  void getStatus();
  void setVoice(uint8_t voc);
  void setSpeed(uint8_t speed);
  void setSoundType(eSoundType_t type);
  void setTone(uint8_t tone);
  void setEnglishPron(eENpron_t pron);
  void stopSynthesis();
  void pauseSynthesis();
  void recoverSynthesis();
  uint16_t getWordLen();
  void wait();
private:


  uint8_t *_utf8;
  uint8_t *_unicode;
  uint16_t uniLen = 0;
  uint16_t _index=0;
  uint16_t _len=0;
  
  eState_t curState = NONE;
  eState_t lastState = NONE;
  bool lanChange = false;

  virtual uint8_t readACK()= 0;
  void sendPack(uint8_t cmd,uint8_t* data =NULL,uint16_t len = 0);

  virtual uint8_t sendCommand(uint8_t *data,uint8_t length)=0;
  virtual uint8_t sendCommand(uint8_t *head,uint8_t *data,uint8_t length)=0;

};


class DFRobot_SpeechSynthesis_IIC :public DFRobot_SpeechSynthesis{
public:
  DFRobot_SpeechSynthesis_IIC(TwoWire *pWire = &Wire, uint8_t address = I2C_ADDR);
  bool begin(Stream *s=NULL);
private:
  uint8_t _deviceAddr;
  TwoWire *_pWire;
  uint8_t readACK();
  uint8_t sendCommand(uint8_t *data,uint8_t length);
  uint8_t sendCommand(uint8_t *head,uint8_t *data,uint8_t length);
};


class DFRobot_SpeechSynthesis_UART :public DFRobot_SpeechSynthesis{
public:
  DFRobot_SpeechSynthesis_UART();
  bool begin(Stream *s=NULL);

private:
  uint8_t readACK();
  uint8_t sendCommand(uint8_t *data,uint8_t length);
  uint8_t sendCommand(uint8_t *head,uint8_t *data,uint8_t length);

  Stream *_s;
  uint32_t _baudRate;
};







#endif