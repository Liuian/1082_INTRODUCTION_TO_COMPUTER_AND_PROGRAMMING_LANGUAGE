// wavetest.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "wave_file_s.h"
#include <iostream>
#include <math.h>

#define pi 3.14159265
using namespace std;


double fre(int x) {
	switch (x) {
		case 0: //none
			return 0;
			break;

		case 1: //do
			return 261.6;
			break;
	
		case 2: //re
			return 293.7;
			break;
	
		case 3: //mi
			return 329.6;
			break;
	
		case 4: //fa
			return 349.2;
			break;
	
		case 5: //so
			return 392.0;
			break;
	
		case 6: //la
			return 440;
			break;
	
		case 7: //ti
			return 493.9;
			break;
	}
}


int main() {
	long length = 44100;
	short s[44100] = {};
	double V = 10000;
	int x;
	cin >> x;
	for (int i = 0; i < length; i++) {
		
			

		s[i] = V * (        sin(2 * pi *fre(x) *i / 44100)        );
		
	}
	
	wave_file A((char*)"a.wav", s, length);


	return 0;
}