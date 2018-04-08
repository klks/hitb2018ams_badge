#pragma once
extern Adafruit_SSD1306 display;

#include <HackRadio.h>
HackRadio Hackradio = HackRadio();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long u32;
typedef unsigned long long u64;
uint64_t key = 0; /*REDACTED*/
#define KeeLoq_NLF    0 /*REDACTED*/
#define bit(x,n)    (((x)>>(n))&1)
#define g5(x,a,b,c,d,e) (bit(x,a)+bit(x,b)*2+bit(x,c)*4+bit(x,d)*8+bit(x,e)*16)
uint32_t  KeeLoq_Encrypt (const uint32_t data, const uint64_t key)
{
  uint32_t  x = data, r;
  for (r = 0; r < 528; r++) {
    x = (x >> 1) ^ ((bit(x, 0)^bit(x, 16) ^ (uint32_t)bit(key, r & 63)^bit(KeeLoq_NLF, g5(x, 1, 9, 20, 26, 31))) << 31);
  }
  return x;
}
uint32_t  KeeLoq_Decrypt (const uint32_t data, const uint64_t key)
{
  uint32_t   x = data, r;
  for (r = 0; r < 528; r++) {
    x = (x << 1)^bit(x, 31)^bit(x, 15) ^ (uint32_t)bit(key, (15 - r) & 63)^bit(KeeLoq_NLF, g5(x, 0, 8, 19, 25, 30));
  }
  return x;
}

void RF_check() {
  if (Hackradio.available()) {
    detachInterrupt(PB8);

    unsigned long rfdata = strtoul(Hackradio.getkey().c_str(), NULL, 16);
    uint32_t datadc = KeeLoq_Decrypt(rfdata, key);

    unsigned int  Func = datadc >> 28;
    //Serial.print(Func, HEX);
    //Serial.print(" Distinguish Code:");
    uint32_t   Distinguish = datadc << 6;
    Distinguish = Distinguish >> 22;
    //Serial.print(Distinguish, HEX);
    //Serial.print(" Sync Counter Value:");
    uint32_t   SyncCounterValue = datadc << 16;
    SyncCounterValue = SyncCounterValue >> 16;
    //Serial.println(SyncCounterValue, HEX);

    if (Distinguish == 0x3da) {
      if (Func == 0xb) {
        //Serial.println("blinkl");
        led_rf();
      }
    }

    Hackradio.resetAvailable();

    Hackradio.enableReceive(PB8);
  }
}

void setup_rf() {
  //Serial.begin(9600);
  delay(1000);
  //Serial.println("test");
  pinMode(PB8, INPUT);
  Hackradio.enableReceive(PB8);
}

void process_rf() {
  RF_check();
}