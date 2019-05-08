/*Nyan Cat
  with Bass
  Uses Arduino tone library pitches.h [http://arduino.cc/en/Tutorial/tone ]
       by electricmango
  https://electricmango.github.io
 
  Thanks to Sean for posting the sheet music on
  http://junket.tumblr.com/post/4776023022/heres-the-nyan-cat-sheet-music
 
  Version 1.0.3
  -------------------------------------------------------------------------
  Nyan Cat with Bass is licensed under the
 
  Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
 
  You are free to:
  Share — copy and redistribute the material in any medium or format
  Adapt — remix, transform, and build upon the material
  for any purpose, even commercially.
  The licensor cannot revoke these freedoms as long as you follow the license terms.
  Under the following terms:
  Attribution — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
  ShareAlike — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.
  No additional restrictions — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.
  The full license is available at https://creativecommons.org/licenses/by-sa/4.0/legalcode
 
  Copyright (c) 2012 ~ 2015 electricmango
 
  Edit by Amperka.ru in 2016
 
  -------------------------------------------------------------------------
  Nyan_Cat.ino
  -------------------------------------------------------------------------
*/
 
//Ноты
 /*
#define REST     0
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 */
#define LED_R 10
#define LED_Y 6
#define LED_G 9
#define LED_B 4

#define BUZZER 7
#define BUTTON 8

bool firstNote = true; 
bool pause = false;
int C0 = 440;
int freqToPlay = 440;
int prevFreqToPlay =  440;

  float intervalA4 = 58;
 float prevIntervalA4 = 58;

//float natureInt[13] = {1, 1.0594630943593, 1.12246204830937, 1.18920711500272, 1.25992104989487, 1.33483985417003, 1.4142135623731, 1.49830707687668, 1.5874010519682, 1.68179283050743, 1.78179743628068, 1.88774862536339, 2};// равнотемперированный ряд

//float natureInt[13] = {1, 1.059463, 1.122462, 1.189207, 1.25, 1.333333, 1.40625, 1.5, 1.6, 1.666667, 1.777778, 1.875, 2};//old wrong
//float natureInt[13] = {1,1.0666666666667,1.125,1.2,1.25,1.333333333333,1.40625,1.5,1.6,1.66666666667,1.7777777778,1.875,2};// nature
  float natureInt[13] = {1,1.0416666666667,1.125,1.2,1.25,1.3333333333,1.3888888889,1.5,1.6,1.6666666667,1.8,1.875,2};//New Nature
float minorSecond = 1.0416666666667;  
float risingMinorSecond =  1.066667;
float majorSecond = 1.125;
float decreasingMajorSecond =  1.1111111;
//

 // Можно увеличить высоту мелодии, умножая ноты на 2, 4, 8
    int octaveMul = 2;

//natureInt[2] = 1.123456;

// Массив с нотами мелодии

unsigned int melody[] = {
//31108,
50416,50516,50716,16,51216,50516,50416,50516,50716,51216,60416,60516,60416,51116,51216,16,
50716,16,50416,50516,50716,16,51208,60216,51116,51216,60216,60516,60416,60516,60216,
40708,40908,40316,40416,20716,40216,40316,40216,31208,31208,40208,//40708,40908,40316,40416,20716
40308,40316,40216,31216,40216,40416,40716,40916,40416,40716,40216,40416,31216,40216,31216,
40408,40708,40916,40416,40716,40216,40416,31216,40316,40416,40316,40216,31216,40216,
40308,31216,40216,40416,40716,40216,40316,40216,31216,40208,31208,40208,
40708,40908,40316,40416,20716,40216,40316,40216,31208,31208,40208,//40708,40908,40316,40416,20716,
40308,40316,40216,31216,40216,40416,40716,40916,40416,40716,40216,40416,31216,40216,31216,
40408,40708,40916,40416,40716,40216,40416,31216,40316,40416,40316,40216,31216,40216,
40308,31216,40216,40416,40716,40216,40316,40216,31216,40208,31208,31208,
31208,30716,30916,31208,30716,30916,31216,40216,40416,31216,40516,40416,40516,40716,
31208,31208,30716,30916,31216,30716,40516,40416,40216,31216,30516,30416,30516,30716,
31208,30716,30916,31208,30716,30916,31216,31216,40216,40416,31216,30716,30916,30716,
31208,31216,31116,31216,30716,30916,31216,40516,40416,40516,40716,31208,31108,
31208,30716,30916,31208,30716,30916,31216,40216,40416,31216,40516,40416,40516,40716,
31208,31208,30716,30916,31216,30716,40516,40416,40216,31216,30516,30416,30516,30716,
31208,30716,30916,31208,30716,30916,31216,31216,40216,40416,31216,30716,30916,30716,
31208,31216,31116,31216,30716,30916,31216,40516,40416,40516,40716,31208,40208,
40708,40908,40316,40416,20716,40216,40316,40216,31208,31208,40208,//40708,40908,40316,40416,20716,
40308,40316,40216,31216,40216,40416,40716,40916,40416,40716,40216,40416,31216,40216,31216,
40408,40708,40916,40416,40716,40216,40416,31216,40316,40416,40316,40216,31216,40216,
40308,31216,40216,40416,40716,40216,40316,40216,31216,40208,31208,40208,
40708,40908,40316,40416,20716,40216,40316,40216,31208,31208,40208,//40708,40908,40316,40416,20716,
40308,40316,40216,31216,40216,40416,40716,40916,40416,40716,40216,40416,31216,40216,31216,
40408,40708,40916,40416,40716,40216,40416,31216,40316,40416,40316,40216,31216,40216,
40308,31216,40216,40416,40716,40216,40316,40216,31216,40208,31208,31208,
31208,30716,30916,31208,30716,30916,31216,40216,40416,31216,40516,40416,40516,40716,
31208,31208,30716,30916,31216,30716,40516,40416,40216,31216,30516,30416,30516,30716,
31208,30716,30916,31208,30716,30916,31216,31216,40216,40416,31216,30716,30916,30716,
31208,31216,31116,31216,30716,30916,31216,40516,40416,40516,40716,31208,31108,
};
 /*
int melody[] = {
  NOTE_DS5, NOTE_E5, NOTE_FS5, 0, NOTE_B5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_FS5, NOTE_B5, NOTE_DS6, NOTE_E6, NOTE_DS6, NOTE_AS5, NOTE_B5, 0,
  NOTE_FS5, 0, NOTE_DS5, NOTE_E5, NOTE_FS5, 0, NOTE_B5, NOTE_CS6, NOTE_AS5, NOTE_B5, NOTE_CS6, NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_CS6,
  NOTE_FS4, NOTE_GS4, NOTE_D4, NOTE_DS4, NOTE_FS2, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_CS4, NOTE_B3,
  NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_B3, NOTE_CS4,
  NOTE_FS4, NOTE_GS4, NOTE_D4, NOTE_DS4, NOTE_FS2, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_CS4, NOTE_B3,
  NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_B3, NOTE_B3,
  NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4,
  NOTE_B3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_E4, NOTE_DS4, NOTE_CS4, NOTE_B3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_FS3,
  NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_FS3,
  NOTE_B3, NOTE_B3, NOTE_AS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4, NOTE_B3, NOTE_AS3,
  NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4,
  NOTE_B3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_E4, NOTE_DS4, NOTE_CS4, NOTE_B3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_FS3,
  NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_FS3,
  NOTE_B3, NOTE_B3, NOTE_AS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4, NOTE_B3, NOTE_CS4,
  NOTE_FS4, NOTE_GS4, NOTE_D4, NOTE_DS4, NOTE_FS2, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_CS4, NOTE_B3,
  NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_B3, NOTE_CS4,
  NOTE_FS4, NOTE_GS4, NOTE_D4, NOTE_DS4, NOTE_FS2, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_CS4, NOTE_B3,
  NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4,
  NOTE_D4, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_FS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_B3, NOTE_B3,
  NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4,
  NOTE_B3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_E4, NOTE_DS4, NOTE_CS4, NOTE_B3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_FS3,
  NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_FS3,
  NOTE_B3, NOTE_B3, NOTE_AS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4, NOTE_B3, NOTE_AS3,
  NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4,
  NOTE_B3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_E4, NOTE_DS4, NOTE_CS4, NOTE_B3, NOTE_E3, NOTE_DS3, NOTE_E3, NOTE_FS3,
 // NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_FS3,
 // NOTE_B3, NOTE_B3, NOTE_AS3, NOTE_B3, NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_FS4, NOTE_B3, NOTE_CS4,
};
 */
// Массив длительности нот в мелодии: 4 = четвертная нота,
// 8 = восьмая нота, и так далее...
 /*
int noteDurations[] = {
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8,
  8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8, 8,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8,
};
 */
void setup() {
  //iterate over the notes of the melody:
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
 //  natureInt[2] = 1.0123456;
  Serial.begin(9600);
   Serial.println(" .......................");
 Serial.println("Launch....................");
 Serial.print("natureInt[2] = ");
 Serial.println(natureInt[2],6);

 
}
 
void loop() {
  // Если была нажата кнопка, играем мелодию
  if (checkClick())
    nya();
 
  // Гасим светодиоды
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_B, LOW);
}
 
void nya()
{
  // Вычисляем количество нот
  int noteCount = sizeof(melody) / sizeof(int);
 
  // Переменная для хранения состояния светодиодов
 // bool toggleLeds = true;
 
  // Играем мелодию
  for (int thisNote = 0; thisNote < noteCount; thisNote++) {
 
  // Если была нажата клавиша - останавливаем мелодию
    if (checkClick())
      return;
 
    // Каждую новую ноту меняем состояние светодиодов
  /*  
    digitalWrite(LED_R, toggleLeds);
    digitalWrite(LED_Y, toggleLeds);
    digitalWrite(LED_G, !toggleLeds);
    digitalWrite(LED_B, !toggleLeds);
    toggleLeds = !toggleLeds;
 */
  //  noTone(BUZZER); //останавливаем воспроизведение предыдущей ноты
 
    /*
     Вычислим длительность ноты. Разделим секунду на длительность ноты из массива
     Четвертная нота = 1000/4, восьмая нота 1000/8
     Скорость можно увеличить, увеличив числитель. Больше подошло 1200
    */
 
   // int noteDuration = 1200 / 16;
    //noteDurations[thisNote];
 
   
  float melodyFloat = float(melody[thisNote]);
  // Serial.print("melodyFloat = ");
   //  Serial.println(melodyFloat);
//Serial.print("int(melodyFloat/10000) = ");
 //Serial.println(int(melodyFloat/10000));
 //  Serial.print("(melodyFloat/10000 - int(melodyFloat/10000)) = ");
// Serial.println(melodyFloat/10000 - int(melodyFloat/10000));  

if(melodyFloat > 100){
     
 intervalA4 = int(melodyFloat/10000) * 12 + (melodyFloat/10000 - int(melodyFloat/10000)) * 100;
 Serial.print("intervalA4 = ");
 Serial.println(intervalA4);
 pause = false;
 Serial.print("pause = ");
  Serial.println(pause);
} else {
  intervalA4 = prevIntervalA4;
   pause = true;  
   Serial.print("pause = ");
  Serial.print(pause);
  Serial.println("pause now");
  
}


 // Serial.print("prevIntervalA4 = ");
 //Serial.println(prevIntervalA4);
 // Serial.print("dlit = ");
 //Serial.println(((intervalA4 - int(intervalA4))*100));
 // Serial.print("int(intervalA4) = ");
// Serial.println(int(intervalA4));
//  Serial.print("int(prevIntervalA4) = ");
// Serial.println(int(prevIntervalA4));
 
 int relIntervalA4 = int(intervalA4) - int(prevIntervalA4);
   //  Serial.print("relIntervalA4 = ");
   //  Serial.println(relIntervalA4);

switch ( relIntervalA4 ) {

    case -12 : 
    // Process for octava
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, true);
    break;

    case -11 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
    break;

    case -10 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
    break;

    case -9 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, true);
    break;

    case -8 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, true);
    break;

    case -7 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, true);
    break;

    case -6 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
    break;


    case -5 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, true);
    break;

    case -4 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, false);
    break;


    case -3 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, true);
    break;

    case -2 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, false);
    break;

   
        case -1 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, true);
    break;

    case 0 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, true);
    break;

      case 1 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, true);
    break;

    case 2 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, false);
    break;

     case 3 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
    break; 

     case 4 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, true);
    break;

        case 5 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, false);
    break;

        case 6 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
    break;

        case 7 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, true);
    break;

        case 8 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, false);
    break;

        case 9 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, false);
    break;

        case 10 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
    break;

        case 11 : 
    // Process for test = 1
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
    break;

    case 12 : 
    // Process for test = 1
    digitalWrite(LED_R, true);
      digitalWrite(LED_G, true);
      digitalWrite(LED_Y, true);
    digitalWrite(LED_B, true);
    break;

  default : 
    // Process for all other cases.
    digitalWrite(LED_R, false);
      digitalWrite(LED_G, false);
      digitalWrite(LED_Y, false);
    digitalWrite(LED_B, false);
}
 
 
int noteDuration = 1200 /((intervalA4 - int(intervalA4))*100);
 //Serial.print("noteDuration = ");
 //Serial.println(noteDuration);
 float intervalC0 = 58 - int(intervalA4);
 // Serial.print("intervalC0 = ");
 //Serial.println(intervalC0);
// Serial.print("intervalC0/12 = ");
// Serial.println(intervalC0/12);
 
// Serial.print("pow(2,(intervalC0/12)) = ");
// Serial.println(pow(2.0,(intervalC0/12)));



int monoFreqToPlay = C0 /pow(2.0,(intervalC0/12));
// Serial.print("monoFreqToPlay = ");
// Serial.println(monoFreqToPlay);

 if (firstNote){
  freqToPlay = monoFreqToPlay;
   }

 
if (!firstNote){
 // Serial.print("int(relIntervalA4/12)  = ");
 // Serial.println(int(abs(relIntervalA4/12)) );
 //   Serial.print("natureInt[abs(relIntervalA4-int(relIntervalA4/12)*12)]  = ");
 // Serial.println(natureInt[abs(relIntervalA4-int(relIntervalA4/12)*12)] );
// Serial.print("freqNatInt  = ");
//  Serial.println((int(abs(relIntervalA4/12)) + natureInt[abs(relIntervalA4-int(relIntervalA4/12)*12)]),6 );
// Serial.print("prevFreqToPlay  = ");
 // Serial.println(prevFreqToPlay );

if (relIntervalA4 == 0){freqToPlay = prevFreqToPlay;}
  if (relIntervalA4 > 0){
 freqToPlay = prevFreqToPlay * (int(abs(relIntervalA4/12)) + natureInt[abs(relIntervalA4-int(relIntervalA4/12)*12)]);
  Serial.print("      >freqToPlay = ");
 Serial.println(freqToPlay);
} 
  if (relIntervalA4 < 0){
 freqToPlay = prevFreqToPlay / (int(abs(relIntervalA4/12)) + natureInt[abs(relIntervalA4-int(relIntervalA4/12)*12)]);
  Serial.print("     <freqToPlay = ");
 Serial.println(freqToPlay);
} 

if(freqToPlay < monoFreqToPlay) {
  natureInt[1] = risingMinorSecond;
  natureInt[2] = majorSecond;
} else{
  natureInt[2] = decreasingMajorSecond;
  natureInt[1] = minorSecond;
}

 
}

if (pause == true) {
  Serial.println("change to pause = false;");
  freqToPlay = 0;
  pause = false;
  Serial.print("pause = ");
  Serial.println(pause);
}


   noTone(BUZZER); //останавливаем воспроизведение предыдущей ноты
 firstNote = false;
 //if((thisNote == noteCount - 1) ||(thisNote == 0)){
 
   Serial.print("melodyFloat = ");
     Serial.println(melodyFloat);
 
   Serial.print("monoFreqToPlay = ");
     Serial.println(monoFreqToPlay);
     
 Serial.print("freqToPlay = ");
 Serial.println(freqToPlay);
 //}
if(freqToPlay < 31) freqToPlay =  0;
if(freqToPlay < 95) freqToPlay = 2* freqToPlay;
    // воспроизведём ноту
     tone(BUZZER, octaveMul * freqToPlay, noteDuration);
     if(freqToPlay){  
     prevFreqToPlay = freqToPlay;// if it was not 0
     }
   // tone(BUZZER, octaveMul * melody[thisNote], noteDuration);
  //  Serial.println(freqToPlay);
   // Serial.print(melody[thisNote]);
   // Serial.print("\t");
 prevIntervalA4 = intervalA4;
    /*
      Чтобы отделить ноты друг от друга, добавим небольшую паузу между ними
      30% от длины ноты звучат неплохо
    */
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
 
  }
}


// Функция для проверки клика кнопки
bool checkClick()
{
  // Переменная для хранения предыдущего состояния кнопки
  static bool buttonWasUp = true;
  bool result = false;
 
  // Читаем текущее состояние кнопки
  bool buttonIsUp = digitalRead(BUTTON);
 
  // Если кнопка была не нажата, а теперь нажата
  // значит был клик
  if (buttonWasUp && !buttonIsUp) {
    delay(50);
    result = true;
  }
  buttonWasUp = buttonIsUp;
  return result;
}
