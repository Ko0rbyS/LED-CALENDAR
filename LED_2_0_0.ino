#include <Adafruit_NeoPixel.h>
#include <DS1302.h>
#include <DHT.h>
#include <avr/pgmspace.h>

#define LED_PIN     6
#define NUM_LEDS    128
#define DS1302_RST  7
#define DS1302_DAT  8
#define DS1302_CLK  9
#define DHTPIN 4
#define DHTTYPE DHT11
#define BUTTON_PIN 2
DHT dht(DHTPIN, DHTTYPE);

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
DS1302 rtc(DS1302_RST, DS1302_DAT, DS1302_CLK);

bool manualMode = false;
int testDen = 31;

int cervene[] = {0, 1, 2, 3, 4, 8, 9, 10, 11, 12, 68, 69, 70, 71, 76, 77, 78, 79};
int bile[] = {16,17,18,19,20,24,25,26,27,28,32,33,34,35,36,40,41,42,43,44,48,49,50,51,52,56,57,58,59,60,
              84,85,86,87,92,93,94,95,100,101,102,103,108,109,110,111,116,117,118,119,124,125,126,127};

const uint8_t den_1[] PROGMEM = {48, 40, 32, 24, 16, 95};
const uint8_t den_2[] PROGMEM = {87, 16, 17, 25, 33, 32, 103, 111, 119, 48, 49};
const uint8_t den_3[] PROGMEM = {87, 16, 17, 25, 33, 32, 103, 41, 119, 48, 49};
const uint8_t den_4[] PROGMEM = {87, 95, 25, 33, 32, 103, 41, 49};
const uint8_t den_5[] PROGMEM = {87, 16, 17, 95, 33, 32, 103, 41, 119, 48, 49};
const uint8_t den_6[] PROGMEM = {87, 16, 17, 95, 33, 32, 103, 41, 119, 48, 49, 111};
const uint8_t den_7[] PROGMEM = {87, 16, 17, 25, 33, 41, 49};
const uint8_t den_8[] PROGMEM = {87, 16, 17, 25, 33, 41, 49, 95, 103, 32, 111, 119, 48};
const uint8_t den_9[] PROGMEM = {87, 16, 17, 25, 33, 41, 49, 95, 103, 32};
const uint8_t den_10[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
const uint8_t den_11[] PROGMEM = {87, 94, 95, 103, 111, 119, 18, 25, 26, 34, 42, 50};
const uint8_t den_12[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 27, 35, 34, 33, 41, 49, 50, 51};
const uint8_t den_13[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 27, 35, 34, 33, 43, 51, 50, 49};
const uint8_t den_14[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 25, 27, 33, 34, 35, 43, 51};
const uint8_t den_15[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 35, 34, 33, 43, 49, 50, 51};
const uint8_t den_16[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 35, 34, 33, 41, 43, 49, 50, 51};
const uint8_t den_17[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 27, 35, 43, 51};
const uint8_t den_18[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 27, 35, 34, 33, 41, 43, 49, 50, 51};
const uint8_t den_19[] PROGMEM = {86, 93, 94, 102, 110, 118, 17, 18, 19, 25, 27, 33, 34, 35, 43, 51};
const uint8_t den_20[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
const uint8_t den_21[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 18, 25, 26, 34, 42, 50};
const uint8_t den_22[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 27, 35, 34, 33, 41, 49, 50, 51};
const uint8_t den_23[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 27, 35, 34, 33, 43, 51, 50, 49};
const uint8_t den_24[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 25, 27, 33, 34, 35, 43, 51};
const uint8_t den_25[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 35, 34, 33, 43, 49, 50, 51};
const uint8_t den_26[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 35, 34, 33, 41, 43, 49, 50, 51};
const uint8_t den_27[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 27, 35, 43, 51};
const uint8_t den_28[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 27, 35, 34, 33, 41, 43, 49, 50, 51};
const uint8_t den_29[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 109, 117, 118, 119, 17, 18, 19, 25, 27, 33, 34, 35, 43, 51};
const uint8_t den_30[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 111, 119, 118, 117, 17, 18, 19, 25, 27, 33, 35, 41, 43, 49, 50, 51};
const uint8_t den_31[] PROGMEM = {85, 86, 87, 95, 103, 102, 101, 111, 119, 118, 117, 19, 27, 26, 35, 43, 51};

const uint8_t* const dny_zhasnout[] PROGMEM = {
  den_1, den_2, den_3, den_4, den_5, den_6, den_7, den_8,
  den_9, den_10, den_11, den_12, den_13, den_14, den_15, den_16,
  den_17, den_18, den_19, den_20, den_21, den_22, den_23, den_24,
  den_25, den_26, den_27, den_28, den_29, den_30, den_31
};

const uint8_t dny_delky[] PROGMEM = {
  sizeof(den_1), sizeof(den_2), sizeof(den_3), sizeof(den_4), sizeof(den_5), sizeof(den_6), sizeof(den_7), sizeof(den_8),
  sizeof(den_9), sizeof(den_10), sizeof(den_11), sizeof(den_12), sizeof(den_13), sizeof(den_14), sizeof(den_15), sizeof(den_16),
  sizeof(den_17), sizeof(den_18), sizeof(den_19), sizeof(den_20), sizeof(den_21), sizeof(den_22), sizeof(den_23), sizeof(den_24),
  sizeof(den_25), sizeof(den_26), sizeof(den_27), sizeof(den_28), sizeof(den_29), sizeof(den_30), sizeof(den_31)
};

//PRO VLHKOST
const uint8_t den_32[] = {};
const uint8_t den_33[] = {};
const uint8_t den_34[] = {};

int zjistiJas(int hodina) {
  if (hodina >= 6 && hodina < 12) return 3;
  if (hodina >= 12 && hodina < 18) return 2;
  if (hodina >= 18 && hodina < 22) return 1;
  return 0;
}

void vykresliPozadi(bool teplota = false) {
  uint32_t barva = teplota ? strip.Color(255, 150, 0) : strip.Color(255, 0 , 0);
  for (int i = 0; i < sizeof(cervene)/sizeof(int); i++)
    strip.setPixelColor(cervene[i], barva);
  for (int i = 0; i < sizeof(bile)/sizeof(int); i++)
    strip.setPixelColor(bile[i], strip.Color(255, 255, 255));
}

void zobrazDen(uint8_t den, bool teplota = false) {
  strip.clear();
  vykresliPozadi(teplota);

  const uint8_t* ptr = nullptr;
  uint8_t delka = 0;

  if (den >= 1 && den <= 31) {
    ptr = (const uint8_t*)pgm_read_word(&(dny_zhasnout[den - 1]));
    delka = pgm_read_byte(&(dny_delky[den - 1]));

    for (uint8_t i = 0; i < delka; i++) {
      uint8_t index = pgm_read_byte(&(ptr[i]));
      strip.setPixelColor(index, 0);
    }
  } else if (den == 32) {
    for (uint8_t i = 0; i < sizeof(den_32); i++)
      strip.setPixelColor(den_32[i], 0);
  } else if (den == 33) {
    for (uint8_t i = 0; i < sizeof(den_33); i++)
      strip.setPixelColor(den_33[i], 0);
  } else if (den == 34) {
    for (uint8_t i = 0; i < sizeof(den_34); i++)
      strip.setPixelColor(den_34[i], 0);
  }

  strip.show();
}

void setup() {
  strip.begin();
  rtc.halt(false);
  rtc.writeProtect(false);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  dht.begin();
  Time t = rtc.time();
  strip.setBrightness(zjistiJas(t.hr)); 
  zobrazDen(t.date);
}


void loop() {
  static bool zobrazenaTeplota = false;
  static unsigned long casZobrazeniTeploty = 0;
  
  Time t = rtc.time();  
  int jas = zjistiJas(t.hr);
  strip.setBrightness(jas);

  if (jas == 0) {
    strip.clear();
    strip.show();
    delay(1000);
    return;
  }

  if (manualMode) {
    zobrazDen(testDen);
    delay(2000);
    return;
  }

  if (digitalRead(BUTTON_PIN) == LOW && !zobrazenaTeplota) {
    delay(50);
    if (digitalRead(BUTTON_PIN) == LOW) {
      float temp = dht.readTemperature();
      if (!isnan(temp)) {
        int tRounded = constrain(round(temp), 1, 34);
        zobrazDen(tRounded, true);
        zobrazenaTeplota = true;
        casZobrazeniTeploty = millis();
        while (digitalRead(BUTTON_PIN) == LOW);
      }
    }
  }

  if (zobrazenaTeplota && millis() - casZobrazeniTeploty >= 5000) {
    zobrazenaTeplota = false;
    zobrazDen(t.date);
  }

  if (!zobrazenaTeplota) {
    zobrazDen(t.date);
  }

  delay(1000);
}

