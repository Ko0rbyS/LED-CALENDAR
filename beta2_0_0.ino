#include <Adafruit_NeoPixel.h>
#include <DS1302.h>

#define LED_PIN     6
#define NUM_LEDS    128
#define DS1302_RST  7
#define DS1302_DAT  8
#define DS1302_CLK  9

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
DS1302 rtc(DS1302_RST, DS1302_DAT, DS1302_CLK);

//TESTDAY
bool manualMode = false;   // true = testování, false = RTC
int testDen = 31;          

// LEDKY: trvale svícící pozadí
int cervene[] = {0, 1, 2, 3, 4, 8, 9, 10, 11, 12, 68, 69, 70, 71, 76, 77, 78, 79};
int bile[] = {16,17,18,19,20,24,25,26,27,28,32,33,34,35,36,40,41,42,43,44,48,49,50,51,52,56,57,58,59,60,
              84,85,86,87,92,93,94,95,100,101,102,103,108,109,110,111,116,117,118,119,124,125,126,127};

// === VYPNUTÍ LEDEK
int den_1_zhasnout[] = {48, 40, 32, 24, 16, 95};
int den_2_zhasnout[] = {87, 16 ,17, 25, 33, 32, 103, 111, 119, 48, 49};
int den_3_zhasnout[] = {87, 16 ,17, 25, 33, 32, 103, 41, 119, 48, 49};
int den_4_zhasnout[] = {87, 95, 25, 33, 32, 103, 41, 49};
int den_5_zhasnout[] = {87, 16 ,17, 95, 33, 32, 103, 41, 119, 48, 49};
int den_6_zhasnout[] = {87, 16 ,17, 95, 33, 32, 103, 41, 119, 48, 49, 111};
int den_7_zhasnout[] = {87, 16 ,17, 25, 33, 41, 49};
int den_8_zhasnout[] = {87, 16 ,17, 25, 33, 41, 49, 95, 103, 32, 111, 119, 48};
int den_9_zhasnout[] = {87, 16 ,17, 25, 33, 41, 49, 95, 103, 32};
int den_10_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
int den_11_zhasnout[] = {87, 94, 95, 103, 111, 119, 18, 25, 26, 34, 42, 50 };
int den_12_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 27, 35, 34, 33, 41, 49, 50, 51};
int den_13_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 27, 35, 34, 33, 43, 51, 50, 49};
int den_14_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 25, 27, 33, 34, 35, 43, 51};
int den_15_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 35, 34, 33, 43, 49, 50, 51};
int den_16_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 35, 34, 33, 41, 43, 49, 50, 51};
int den_17_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 27, 35, 43, 51};
int den_18_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 27, 35, 34, 33, 41, 43, 49, 50, 51};
int den_19_zhasnout[] = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 27, 33, 34, 35, 43, 51};
int den_20_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
int den_21_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 18, 25, 26, 34, 42, 50 };
int den_22_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 27, 35, 34, 33, 41, 49, 50, 51};
int den_23_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 27, 35, 34, 33, 43, 51, 50, 49};
int den_24_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 25, 27, 33, 34, 35, 43, 51};
int den_25_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 35, 34, 33, 43, 49, 50, 51};
int den_26_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 35, 34, 33, 41, 43, 49, 50, 51};
int den_27_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 27, 35, 43, 51};
int den_28_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 27, 35, 34, 33, 41, 43, 49, 50, 51};
int den_29_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 27, 33, 34, 35, 43, 51};
int den_30_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 111, 119, 118, 117, 17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
int den_31_zhasnout[] = {85, 86, 87, 95, 103, 102, 101, 111, 119, 118, 117, 19, 27, 26, 35, 43, 51 };


void vykresliPozadi() {
  for (int i = 0; i < sizeof(cervene)/sizeof(int); i++)
    strip.setPixelColor(cervene[i], strip.Color(255, 0, 0));

  for (int i = 0; i < sizeof(bile)/sizeof(int); i++)
    strip.setPixelColor(bile[i], strip.Color(255, 255, 255));
}

void zobrazDen(int den) {
  strip.clear();
  vykresliPozadi();

  int* ledky = nullptr;
  int pocet = 0;

  switch (den) {
    case 1: ledky = den_1_zhasnout; pocet = sizeof(den_1_zhasnout)/sizeof(int); break;
    case 2: ledky = den_2_zhasnout; pocet = sizeof(den_2_zhasnout)/sizeof(int); break;
    case 3: ledky = den_3_zhasnout; pocet = sizeof(den_3_zhasnout)/sizeof(int); break;
    case 4: ledky = den_4_zhasnout; pocet = sizeof(den_4_zhasnout)/sizeof(int); break;
    case 5: ledky = den_5_zhasnout; pocet = sizeof(den_5_zhasnout)/sizeof(int); break;
    case 6: ledky = den_6_zhasnout; pocet = sizeof(den_6_zhasnout)/sizeof(int); break;
    case 7: ledky = den_7_zhasnout; pocet = sizeof(den_7_zhasnout)/sizeof(int); break;
    case 8: ledky = den_8_zhasnout; pocet = sizeof(den_8_zhasnout)/sizeof(int); break;
    case 9: ledky = den_9_zhasnout; pocet = sizeof(den_9_zhasnout)/sizeof(int); break;
    case 10: ledky = den_10_zhasnout; pocet = sizeof(den_10_zhasnout)/sizeof(int); break;
    case 11: ledky = den_11_zhasnout; pocet = sizeof(den_11_zhasnout)/sizeof(int); break;
    case 12: ledky = den_12_zhasnout; pocet = sizeof(den_12_zhasnout)/sizeof(int); break;
    case 13: ledky = den_13_zhasnout; pocet = sizeof(den_13_zhasnout)/sizeof(int); break;
    case 14: ledky = den_14_zhasnout; pocet = sizeof(den_14_zhasnout)/sizeof(int); break;
    case 15: ledky = den_15_zhasnout; pocet = sizeof(den_15_zhasnout)/sizeof(int); break;
    case 16: ledky = den_16_zhasnout; pocet = sizeof(den_16_zhasnout)/sizeof(int); break;
    case 17: ledky = den_17_zhasnout; pocet = sizeof(den_17_zhasnout)/sizeof(int); break;
    case 18: ledky = den_18_zhasnout; pocet = sizeof(den_18_zhasnout)/sizeof(int); break;
    case 19: ledky = den_19_zhasnout; pocet = sizeof(den_19_zhasnout)/sizeof(int); break;
    case 20: ledky = den_20_zhasnout; pocet = sizeof(den_20_zhasnout)/sizeof(int); break;
    case 21: ledky = den_21_zhasnout; pocet = sizeof(den_21_zhasnout)/sizeof(int); break;
    case 22: ledky = den_22_zhasnout; pocet = sizeof(den_22_zhasnout)/sizeof(int); break;
    case 23: ledky = den_23_zhasnout; pocet = sizeof(den_23_zhasnout)/sizeof(int); break;
    case 24: ledky = den_24_zhasnout; pocet = sizeof(den_24_zhasnout)/sizeof(int); break;
    case 25: ledky = den_25_zhasnout; pocet = sizeof(den_25_zhasnout)/sizeof(int); break;
    case 26: ledky = den_26_zhasnout; pocet = sizeof(den_26_zhasnout)/sizeof(int); break;
    case 27: ledky = den_27_zhasnout; pocet = sizeof(den_27_zhasnout)/sizeof(int); break;
    case 28: ledky = den_28_zhasnout; pocet = sizeof(den_28_zhasnout)/sizeof(int); break;
    case 29: ledky = den_29_zhasnout; pocet = sizeof(den_29_zhasnout)/sizeof(int); break;
    case 30: ledky = den_30_zhasnout; pocet = sizeof(den_30_zhasnout)/sizeof(int); break;
    case 31: ledky = den_31_zhasnout; pocet = sizeof(den_31_zhasnout)/sizeof(int); break;
  }
  
  

  if (ledky != nullptr) {
    for (int i = 0; i < pocet; i++)
      strip.setPixelColor(ledky[i], 0);
  }

  strip.show();
}

void setup() {
  strip.begin();
  rtc.halt(false);
  rtc.writeProtect(false);

  Time t = rtc.time();
  strip.setBrightness(1); // pevne nastavený jas
  zobrazDen(t.date);      // zobrazení dne podle RTC
}

void loop() {
  if (manualMode) {
    zobrazDen(testDen);  // ruční test
  } else {
    Time t = rtc.time();
    zobrazDen(t.date);   // RTC
  }

  delay(5000);
}

