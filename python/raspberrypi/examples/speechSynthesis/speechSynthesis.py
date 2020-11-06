# coding=gbk

""" 
  @file speechSynthesis.py
  @brief speech synthesis
  @n note: it takes time to stable alcohol concentration, about 1 minutes.
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
  version  V1.0
  date  2020-09-09
  @get from https://www.dfrobot.com
  @url https://github.com/DFRobot/DFRobot_SpeechSynthesis
"""
import sys
sys.path.append("../..")
from DFRobot_SpeechSynthesis import *
from sys import version_info
if version_info.major == 2 and version_info.minor == 7:
   reload(sys)  
   sys.setdefaultencoding('gbk') 
COLLECT_NUMBER   = 1               # collect number, the collection range is 1-100
I2C_MODE         = 0x01            # default use I2C1格式

alcohol = DFRobot_SpeechSynthesis_I2C (I2C_MODE ,I2C_ADDR)
#alcohol = DFRobot_SpeechSynthesis_UART(115200)
alcohol.setVoice(9)#设置音量(0-9)
alcohol.setSpeed(5)#设置播放速度(0-9)
alcohol.setSoundType(FEMEAL)#设置播放声音/FEMEAL/MEAL/DONALDDUCK
alcohol.setTone(5)#设置音调(0-9)
alcohol.setEnglishPron(WORD)#设置设置单词合成方式 /WORD/ALPHABET
while True:
  alcohol.speak("i have a book")
  alcohol.speak("成都极趣科技有限公司")
  alcohol.speak("你好世界 hello world")
  time.sleep(1)