#include <Adafruit_NeoPixel.h>
#include <DS1302.h>
#include <DHT.h>


// DS1302 zapojení
#define DS1302_RST 7
#define DS1302_DAT 8
#define DS1302_CLK 9

// LED pásek
#define LED_PIN    6
#define NUM_LEDS   128
//#define BRIGHTNESS 76

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#define BUTTON_PIN 2
bool buttonPressed = false;
unsigned long buttonPressTime = 0;
const unsigned long displayDuration = 5000; 


Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
DS1302 rtc(DS1302_RST, DS1302_DAT, DS1302_CLK);

int leva_1_bile[]    = {18, 26, 34, 42, 50,17,25,33,41,19,20,28,36,44,52,60,51,43,35,27,119,49};
int leva_1_vypnout[] = {95,}; 
int prava_1_bile[]   = {85, 93, 101, 109, 117,86, 94, 102, 110, 118,87,103,111}; 
int prava_1_vypnout[]= {16,24,32,40,48,}; 

int leva_2_bile[]    = {18, 19, 20, 26, 27, 34, 35, 42, 43, 50, 51, 52, 59, 60, 58,17, 25, 33, 41, 49};
int leva_2_vypnout[] = {53 };
int prava_2_bile[]   = {};
int prava_2_vypnout[]= {86, 87, 101, 102, 103, 109, 117, 118, 119};

int leva_3_bile[]    = {25, 26, 41, 42};
int leva_3_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 43, 51, 50, 49};
int prava_3_bile[]   = {85, 86, 87, 93, 95, 101, 102, 103, 109, 117, 118, 119};
int prava_3_vypnout[]= {}; 

int leva_4_bile[]    = {18, 19, 26, 41, 42, 49, 50};
int leva_4_vypnout[] = {17, 25, 33, 31, 35, 27, 43, 51};
int prava_4_bile[]   = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118,119};
int prava_4_vypnout[]= {}; 

int leva_5_bile[] = {26, 27, 41, 42};
int leva_5_vypnout[] = {17, 18, 19, 25, 33, 34, 35, 43, 49, 50, 51};
int prava_5_bile[] = {85, 86, 87, 93, 95, 101, 102, 103, 109, 111, 117, 118, 119};
int prava_5_vypnout[] = {};

int leva_6_bile[] = {18, 19, 26, 27, 42};
int leva_6_vypnout[] = {17, 25, 33, 34, 35, 41, 43, 49, 50, 51};
int prava_6_bile[] = {85, 86, 87, 93, 95, 101, 102, 103, 109, 111, 117, 118, 119};
int prava_6_vypnout[] = {};

int leva_7_bile[] = {85, 86, 87, 95, 101, 102, 103, 109, 117, 118, 119};
int leva_7_vypnout[] = {}; 
int prava_7_bile[] = {25, 26, 33, 34, 41, 42, 49, 50};
int prava_7_vypnout[] = {}; 

int leva_8_bile[] = {85, 86, 87, 93, 94, 95, 101, 102, 103, 109, 110, 111, 117, 118, 119};
int leva_8_vypnout[] = {}; 
int prava_8_bile[] = {26, 42};
int prava_8_vypnout[] = {17, 18, 19, 25, 27, 33, 34, 35, 41, 43, 49, 50, 51};

int leva_9_bile[] = {85, 87, 93, 95, 101, 103, 109, 111, 117, 119,86, 94, 102, 110, 118};
int leva_9_vypnout[] = {};
int prava_9_bile[] = {26, 41, 42, 49, 50};
int prava_9_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 25, 43, 51};

int leva_10_bile[] = {85, 93, 101, 109, 117, 87, 95, 103, 111, 119};
int leva_10_vypnout[] = {86, 94, 102, 110, 118};
int prava_10_bile[] = {26, 34, 42};
int prava_10_vypnout[] = {17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};

int leva_11_bile[] = {85, 93, 101, 109, 117, 87, 95, 103, 111, 119};
int leva_11_vypnout[] = {86, 94, 102, 110, 118};
int prava_11_bile[] = {17, 19, 25, 27, 33, 35, 41, 43, 49, 51};
int prava_11_vypnout[] = {18, 26, 34, 42, 50};

int leva_12_bile[] = {85, 93, 101, 109, 117, 87, 95, 103, 111, 119};
int leva_12_vypnout[] = {86, 94, 102, 110, 118};
int prava_12_bile[] = {25, 26, 42, 43};
int prava_12_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 41, 49, 50, 51};

int leva_13_bile[] = {85, 93, 101, 109, 117, 87, 95, 103, 111, 119};
int leva_13_vypnout[] = {86, 94, 102, 110, 118};
int prava_13_bile[] = {25, 26, 41, 42};
int prava_13_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 43, 49, 50, 51};

int leva_14_bile[] = {85, 93, 101, 109, 117, 87, 95, 103, 111, 119};
int leva_14_vypnout[] = {86, 94, 102, 110, 118};
int prava_14_bile[] = {18, 19, 26, 41, 42, 49, 50};
int prava_14_vypnout[] = {17, 25, 33, 34, 35, 43, 51};

int leva_15_bile[] = {85, 93, 101, 109, 117, 87, 95, 103, 111, 119};
int leva_15_vypnout[] = {86, 94, 102, 110, 118};
int prava_15_bile[] = {26, 27, 41, 42};
int prava_15_vypnout[] = {17, 18, 19, 25, 33, 34, 35, 43, 49, 50, 51};

int leva_16_bile[] = {85, 93, 101, 109, 117, 87, 95, 103, 111, 119};
int leva_16_vypnout[] = {86, 94, 102, 110, 118};
int prava_16_bile[] = {18, 19, 26, 27, 42};
int prava_16_vypnout[] = {17, 25, 33, 41, 49, 50, 51, 43, 35, 34};

int leva_17_bile[] = {85, 87, 93, 95, 101, 103, 109, 111, 117, 119};
int leva_17_vypnout[] = {86, 94, 102, 110, 118};
int prava_17_bile[] = {25, 26, 33, 34, 41, 42, 49, 50};
int prava_17_vypnout[] = {17, 18, 19, 27, 35, 43, 51};

int leva_18_bile[] = {85, 87, 93, 95, 101, 103, 109, 111, 117, 119};
int leva_18_vypnout[] = {86, 94, 102, 110, 118};
int prava_18_bile[] = {26, 42};
int prava_18_vypnout[] = {17, 18, 19, 25, 27, 33, 34, 35, 41, 43, 49, 50, 51};

int leva_19_bile[] = {85, 87, 93, 95, 101, 103, 109, 111, 117, 119};
int leva_19_vypnout[] = {86, 94, 102, 110, 118};
int prava_19_bile[] = {26, 41, 42, 49, 50};
int prava_19_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 25, 43, 51};

int dvacitka_led_zhasnout[] = {85, 86, 87, 95, 101, 102, 103, 109, 117, 118, 119, 17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
int dvacitka_led_bile[] = {26, 34, 42};

int jednadvacitka_bila[] = {17, 19, 25, 27, 33, 35, 41, 43, 49, 51};
int jednadvacitka_vypnout[] = {85, 86, 87, 95, 101, 102, 103, 109, 117, 118, 119};


int leva_22_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 41, 49, 50, 51};
int leva_22_bile[] = {25, 26, 42, 43};
int prava_22_vypnout[] = {81, 82, 83, 91, 97, 98, 99, 105, 113, 114, 115};

int leva_23_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 43, 51, 50, 49};
int leva_23_bile[] = {25, 26, 41, 42};

int leva_24_vypnout[] = {17, 25, 33, 34, 35, 43, 51};
int leva_24_bile[] = {18, 19, 26, 41, 42, 49, 50};

int leva_25_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 41, 49, 50, 51};
int leva_25_bile[] = {26, 27, 41, 42};

int leva_26_vypnout[] = {17, 18, 19, 25, 33, 34, 35, 41, 43, 49, 50, 51};
int leva_26_bile[] = {26, 27, 42};

int leva_27_vypnout[] = {17, 18, 19, 27, 35, 43, 51};
int leva_27_bile[] = {25, 26, 33, 34, 41, 42, 49, 50};

int leva_28_vypnout[] = {17, 18, 19, 25, 27, 33, 34, 35, 41, 43, 49, 50, 51};
int leva_28_bile[] = {26, 42};

int leva_29_vypnout[] = {17, 18, 19, 27, 35, 34, 33, 25, 43, 51};
int leva_29_bile[] = {26, 41, 42, 49, 50};

int leva_30_vypnout[] = {85, 86, 87, 95, 103, 102, 101, 111, 119, 118, 117};
int leva_30_bile[] = {93, 94, 109, 110};
int prava_30_vypnout[] = {17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
int prava_30_bile[] = {26, 34, 42};

int leva_31_vypnout[] = {85, 86, 87, 95, 103, 102, 101, 111, 119, 118, 117};
int leva_31_bile[] = {93, 94, 109, 110};
int prava_31_vypnout[] = {18,26, 34, 42,50,25};
int prava_31_bile[] = {17,19, 27, 33, 35, 41, 43, 49,51};

// STYL POZADÍ
int cervene[] = {
  0,1,2,3,4,5,6,7,
  8,9,10,11,12,13,14,15,
  64,65,66,67,68,69,70,71,
  72,73,74,75,76,77,78,79
};

int bile[] = {
  84, 92, 100, 108, 116, 124,
  20, 28, 36, 44, 52, 60,
  16, 24, 32, 40, 48, 56,
  57, 58, 59,
  93, 94, 110, 111,
  125, 126, 127
};

int zhasnout_navic[] = {
  5, 6, 7, 13, 14, 15,
  64, 65, 66, 67,
  72, 73, 74, 75,
  31
};

void vykresliPozadi(bool teplota = false) {
  strip.clear();
  uint32_t barvaPozadi = teplota ? strip.Color(255, 160, 0) : strip.Color(255, 0, 0);

  for (int i = 0; i < sizeof(cervene) / sizeof(int); i++)
    strip.setPixelColor(cervene[i], barvaPozadi);

  for (int i = 0; i < sizeof(bile) / sizeof(int); i++)
    strip.setPixelColor(bile[i], strip.Color(255, 255, 255));

  for (int i = 0; i < sizeof(zhasnout_navic) / sizeof(int); i++)
    strip.setPixelColor(zhasnout_navic[i], 0);
}

int zjistiJas(int hodina) {
  if (hodina >= 6 && hodina < 12) return 3; // ráno: 
  if (hodina >= 12 && hodina < 18) return 4; // odpoledne
  if (hodina >= 18 && hodina < 22) return 1; // večer
  return 0; // noc (22–6)
}
void zobraz1() {
 
  for (int i = 0; i < sizeof(leva_1_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_1_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_1_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_1_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_1_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_1_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_1_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_1_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz2() {
  
  for (int i = 0; i < sizeof(leva_2_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_2_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_2_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_2_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_2_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_2_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_2_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_2_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz3() {
  
  for (int i = 0; i < sizeof(leva_3_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_3_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_3_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_3_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_3_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_3_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_3_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_3_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz4() {
  
  for (int i = 0; i < sizeof(leva_4_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_4_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_4_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_4_bile[i], strip.Color(255, 255, 255));
    for (int i = 0; i < sizeof(prava_4_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_4_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_4_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_4_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz5() {
  
  for (int i = 0; i < sizeof(leva_5_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_5_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_5_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_5_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_5_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_5_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz6() {
  
  for (int i = 0; i < sizeof(leva_6_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_6_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_6_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_6_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_6_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_6_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_6_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_6_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz7() {
  
  for (int i = 0; i < sizeof(leva_7_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_7_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_7_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_7_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz8() {
  
  for (int i = 0; i < sizeof(leva_8_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_8_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_8_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_8_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_8_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_8_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_8_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_8_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz9() {
  
  for (int i = 0; i < sizeof(leva_9_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_9_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_9_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_9_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_9_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_9_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_9_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_9_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz10() {
  
  for (int i = 0; i < sizeof(leva_10_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_10_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_10_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_10_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_10_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_10_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_10_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_10_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz11() {
 
  for (int i = 0; i < sizeof(leva_11_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_11_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_11_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_11_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_11_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_11_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_11_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_11_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz12() {
 
  for (int i = 0; i < sizeof(leva_12_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_12_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_12_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_12_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_12_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_12_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_12_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_12_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz13() {
  
  for (int i = 0; i < sizeof(leva_13_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_13_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_13_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_13_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_13_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_13_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_13_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_13_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz14() {
  
  for (int i = 0; i < sizeof(leva_14_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_14_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_14_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_14_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_14_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_14_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_14_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_14_bile[i], strip.Color(255, 255, 255));
  strip.show();
}

void zobraz15() {
  
  for (int i = 0; i < sizeof(leva_15_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_15_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_15_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_15_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_15_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_15_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_15_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_15_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz16() {
  
  for (int i = 0; i < sizeof(leva_16_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_16_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_16_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_16_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_16_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_16_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_16_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_16_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz17() {
  
  for (int i = 0; i < sizeof(leva_17_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_17_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_17_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_17_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_17_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_17_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_17_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_17_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz18() {
  
  for (int i = 0; i < sizeof(leva_18_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_18_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_18_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_18_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_18_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_18_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_18_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_18_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz19() {
  
  for (int i = 0; i < sizeof(leva_19_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_19_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_19_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_19_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_19_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_19_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_19_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_19_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz20() {
  
  for (int i = 0; i < sizeof(dvacitka_led_zhasnout)/sizeof(int); i++)
    strip.setPixelColor(dvacitka_led_zhasnout[i], 0);
  for (int i = 0; i < sizeof(dvacitka_led_bile)/sizeof(int); i++)
    strip.setPixelColor(dvacitka_led_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz21() {
  
  for (int i = 0; i < sizeof(jednadvacitka_vypnout)/sizeof(int); i++)
    strip.setPixelColor(jednadvacitka_vypnout[i], 0);
  for (int i = 0; i < sizeof(jednadvacitka_bila)/sizeof(int); i++)
    strip.setPixelColor(jednadvacitka_bila[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz22() {
  
  for (int i = 0; i < sizeof(leva_22_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_22_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_22_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_22_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_22_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_22_vypnout[i], 0);
  strip.show();
}

void zobraz23() {
  
  for (int i = 0; i < sizeof(leva_23_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_23_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_23_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_23_bile[i], strip.Color(255, 255, 255));
  strip.show();
}

void zobraz24() {
  
  for (int i = 0; i < sizeof(leva_24_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_24_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_24_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_24_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz25() {
  
  for (int i = 0; i < sizeof(leva_25_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_25_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_25_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_25_bile[i], strip.Color(255, 255, 255));
  strip.show();
}

void zobraz26() {
  
  for (int i = 0; i < sizeof(leva_26_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_26_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_26_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_26_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz27() {
  
  for (int i = 0; i < sizeof(leva_27_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_27_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_27_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_27_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz28() {
  
  for (int i = 0; i < sizeof(leva_28_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_28_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_28_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_28_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz29() {
  
  for (int i = 0; i < sizeof(leva_29_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_29_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_29_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_29_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz30() {
  
  for (int i = 0; i < sizeof(leva_30_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_30_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_30_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_30_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_30_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_30_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_30_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_30_bile[i], strip.Color(255, 255, 255));
  strip.show();
}
void zobraz31() {
  
  for (int i = 0; i < sizeof(leva_31_vypnout)/sizeof(int); i++)
    strip.setPixelColor(leva_31_vypnout[i], 0);
  for (int i = 0; i < sizeof(leva_31_bile)/sizeof(int); i++)
    strip.setPixelColor(leva_31_bile[i], strip.Color(255, 255, 255));
  for (int i = 0; i < sizeof(prava_31_vypnout)/sizeof(int); i++)
    strip.setPixelColor(prava_31_vypnout[i], 0);
  for (int i = 0; i < sizeof(prava_31_bile)/sizeof(int); i++)
    strip.setPixelColor(prava_31_bile[i], strip.Color(255, 255, 255));
  strip.show();
}

void zobrazDen(int den, bool teplota = false);



void setup() {
  Serial.begin(9600);
  strip.begin();
  rtc.halt(false);
  rtc.writeProtect(false);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  dht.begin();


  Time t = rtc.time();
  int hodina = t.hr;

  strip.setBrightness(zjistiJas(hodina));
  strip.show();
  Serial.print("Nacteny cas: ");
  Serial.print(t.yr); Serial.print("-");
  Serial.print(t.mon); Serial.print("-");
  Serial.print(t.date); Serial.print(" ");
  Serial.print(t.hr); Serial.print(":");
  Serial.print(t.min); Serial.print(":");
  Serial.println(t.sec);
}



void loop() {
  static bool buttonPressed = false;
  static unsigned long buttonPressTime = 0;
  const unsigned long displayDuration = 5000;

  Time t = rtc.time();
  int hodina = t.hr;
  int jas = zjistiJas(hodina);
  strip.setBrightness(jas);

  if (!buttonPressed && digitalRead(BUTTON_PIN) == LOW) {
    buttonPressed = true;
    buttonPressTime = millis();

    float temp = dht.readTemperature();
    if (isnan(temp)) {
      Serial.println("Chyba čtení z DHT11");
      return;
    }

    int tRounded = constrain(round(temp), 1, 31);
    Serial.print("Zobrazuji teplotu: ");
    Serial.print(temp);
    Serial.println(" °C");

    zobrazDen(tRounded, true);  // ← Změna tady
  } 


  else if (buttonPressed && millis() - buttonPressTime > displayDuration) {
    buttonPressed = false;
    Serial.print("Zobrazuji datum: ");
    Serial.println(t.date);
    zobrazDen(t.date);
  }

  if (!buttonPressed) {
    zobrazDen(t.date);
  }


  delay(2000);
}


void zobrazDen(int den, bool teplota) {
  
  vykresliPozadi(teplota);

 switch (den) {
    case 1:  zobraz1();  break;
    case 2:  zobraz2();  break;
    case 3:  zobraz3();  break;
    case 4:  zobraz4();  break;
    case 5:  zobraz5();  break;
    case 6:  zobraz6();  break;
    case 7:  zobraz7();  break;
    case 8:  zobraz8();  break;
    case 9:  zobraz9();  break;
    case 10: zobraz10(); break;
    case 11: zobraz11(); break;
    case 12: zobraz12(); break;
    case 13: zobraz13(); break;
    case 14: zobraz14(); break;
    case 15: zobraz15(); break;
    case 16: zobraz16(); break;
    case 17: zobraz17(); break;
    case 18: zobraz18(); break;
    case 19: zobraz19(); break;
    case 20: zobraz20(); break;
    case 21: zobraz21(); break;
    case 22: zobraz22(); break;
    case 23: zobraz23(); break;
    case 24: zobraz24(); break;
    case 25: zobraz25(); break;
    case 26: zobraz26(); break;
    case 27: zobraz27(); break;
    case 28: zobraz28(); break;
    case 29: zobraz29(); break;
    case 30: zobraz30(); break;
    case 31: zobraz31(); break;
    default:
     
      strip.clear(); strip.show(); break;
  
  }
}
