# An-ultrasonic-radar
南工远景实验室第三次作业，push到github一份  

### 材料准备：
ArduinoNUO  
HC-SR04超声波模块  
0.96英寸OLED显示屏  
9g舵机  

### 参考文章：
超声波模块：https://blog.csdn.net/qq_45807930/article/details/120627734  
舵机：https://blog.csdn.net/qq_41877902/article/details/123986178  
SSD1306: https://blog.csdn.net/finedayforu/article/details/108769900  
以及部分问题求助ChatGPT  

### 制作过程：
  周五准备大干一场后电脑无故黑屏，无法开机送去售后检测有问题，无奈之下只好借同学电脑重新搞代码下载arduino，下载库……（暗影精灵9通病 真的很难受）  
  后来在折腾了一天后重新讲分开来的代码打包  
![image](https://github.com/LakiAo/An-ultrasonic-radar/assets/42827331/05d25e99-6306-4ac3-a1b5-43e0b63579c8)  
![image](https://github.com/LakiAo/An-ultrasonic-radar/assets/42827331/dfa22d7c-3899-4570-84f1-9c1972433289)  


  制作期间被朋友吐槽线太乱，不如他的nano用面包板整洁，这个后续一定改正。  
  随后是对代码进行整合，这个项目困难的地方就是如何将点在屏幕上正确的表示出来，让人们能够看得出来你所做的是个雷达。这里用到了两个量，分别是angle和cm，分别通过三角函数计算出应该在屏幕上显示的坐标以达到在屏幕上精确显示位置的效果。  
  此外，由于各个模块之间过于琐碎，本次项目分为多个函数进行调用，显得代码会比较整洁且易读。制作效果如下：  
 
##### 遮挡物体：  
 ![image](https://github.com/LakiAo/An-ultrasonic-radar/assets/42827331/a8273a27-dbb9-4809-a066-a39bfec24266)  

##### 显示效果：（半圆形为检测区域）  
![image](https://github.com/LakiAo/An-ultrasonic-radar/assets/42827331/808f216b-92c7-4b25-9cdb-0d80a4e5505c)  

  舵机支架本想通过3D建模实现，但由于在淘宝冲浪的时候偶然发现这样的舵机支架并且十分便宜便直接购买了。  
