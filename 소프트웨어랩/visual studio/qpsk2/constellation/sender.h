#ifndef __SENDER
#define __SENDER
#include <cmath>
#include <random>
#include <iostream>
#include "variables.h"
using namespace std;
class Csender {
public:
	Csender(); 
	char data[Nbits]; // 비스트트림 : 1000개
	float s[Nbits/Nbitspersymbol*Nsamplespersymbol]; // trasmitted signal 1000개 비트스트림을 2비트당 1심볼, 1심볼당 20샘플
	void transmitData(); // 
	void generateSymbol(float, float, float*); // 
	float *c0t, *c1t;
};
#endif
