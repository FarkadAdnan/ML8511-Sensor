# ML8511-Sensor
Arduino library for  ML8511 Analog Output Ultra-Violet Light Sensor Module

 # Description
ML8511 module is an easy to use ultraviolet light sensor. The ML8511 Sensor works by outputing an analog signal in relation to the amount of detected UV light . This breakout can be very handy in creating devices that warn the user of sunburn or detect the UV index as it relates to weather conditions.

This sensor detects 280-390nm light most effectively. This is categorized as part of the UVB (burning rays) spectrum and most of the UVA (tanning rays) spectrum. It outputs a analog voltage that is linearly related to the measured UV intensity (mW/cm2). Simply connect the output of the module to an ADC channel of microcontroller to read UV Light intensity.

![GY-ML8511_UV_Light_Sensor_Module_AO-1-300x300](https://github.com/FarkadAdnan/ML8511-Sensor/assets/35774039/f945f2f4-40eb-4545-9c5b-6edafea352b1)



 # Pinouts
- VIN : Power Connection (3V – 5V)
- 3.3V : Output of the on board regulator
- GND: 0V
- OUT: Analog Output
- EN: Enable Input

- ![2132](https://github.com/FarkadAdnan/ML8511-Sensor/assets/35774039/879894fc-bdf6-497d-bd1d-0cd4f4e4b576)

# sensitivity 
 ![graph024](https://github.com/FarkadAdnan/ML8511-Sensor/assets/35774039/1bde5cc6-7754-4667-a942-2344c8653da9)
  
Relative sensitivity of the eye and the skin to UV radiation of different wavelengths.
- الحساسية النسبية للعين والجلد للأشعة فوق البنفسجية ذات الأطوال الموجية المختلفة.
- تمثل الأشعة فوق البنفسجية طويلة الموجة (UV-A) ما يصل إلى 95% من الأشعة فوق البنفسجية التي تصل إلى سطح الأرض. على الرغم من أن الأشعة فوق البنفسجية (أ) أقل كثافة من الأشعة فوق البنفسجية (ب)، إلا أنها أكثر انتشارًا ويمكن أن تخترق طبقات الجلد بشكل أعمق، مما يؤثر على النسيج الضام والأوعية الدموية، مما يؤدي إلى الشيخوخة المبكرة.

تعمل بعض المواد الكيميائية والأدوية كعوامل حساسية للضوء وتعزز تأثير الأشعة فوق البنفسجية الصادرة عن ضوء الشمس أو من مصادر أخرى. وتشمل هذه العوامل مدرات البول الثيازيدية (الأدوية التي تسبب زيادة إنتاج البول)، والأدوية المستخدمة في علاج ارتفاع ضغط الدم، وبعض المضادات الحيوية (التتراسيكلين، والسلفوناميدات)، ومستحضرات التجميل، والمهدئات الثيازينية.
# Source
1. https://www.ccohs.ca/oshanswers/phys_agents/ultravioletradiation.html
2. https://learn.sparkfun.com/tutorials/ml8511-uv-sensor-hookup-guide?_ga=2.145686967.206897689.1498227319-1848794875.1497668269
