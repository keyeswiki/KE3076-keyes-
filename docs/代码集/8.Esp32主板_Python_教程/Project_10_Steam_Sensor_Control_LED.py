# 导入 Pin，ADC 和 time 库.
from machine import ADC, Pin
import time

# 定义水滴传感器和led的引脚. 
sensor_steam = ADC(Pin(36))
sensor_steam.atten(ADC.ATTN_11DB)
sensor_steam.width(ADC.WIDTH_12BIT)
led = Pin(2, Pin.OUT)
 
while True: 
      adcvalue = sensor_steam.read()
      if adcvalue > 3000:
          print(adcvalue, "LED Blinking!") 
          led.value(1)
          time.sleep(0.5)
          led.value(0)
          time.sleep(0.5)         
      else:
          led.value(0)
          print(adcvalue, "LED OFF!")
          time.sleep(0.2)