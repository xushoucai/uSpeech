/*
uspeech v.0.0.1
2012 Arjo Chakravarty

uspeech is a library that allows sounds to be classified into certain phonemes
on the Arduino. This creates a simple beginning for a full scale voice recognition
program.
*/
#ifndef uspeech_h
#define uspeech_h

#include "Arduino.h"
#include <math.h>
class phoneme
{

public:
	phoneme(int v,int v1, int v2, int v3, int v4, int v10, int v11, int v12, int v13, int v14);
	void debugPrint();
	int loudness();
	unsigned int vector[2][5];
};

class modelPhoneme
{

public:
	modelPhoneme();
	unsigned int mean[2][5];
	unsigned int stdev[2][5];
	int getDistance(phoneme p);
};

class uword
{
public:
	uword();
	void reset();
	void debugPrint();
	void attachPhoneme(phoneme P);
	int confidence();
	unsigned long len;
	unsigned long vector[2][5];
};
class uspeech
{
public:
	uspeech(int ipin);
	phoneme get();
	void calibrate();
private:
	int arr[32];//Main recording
	int filter1[8],filter2[15],filter3[20],filter4[32];
	unsigned int vector[2][5];
	int pin;
	int calib;
	int sumf2();
	int dif2();
	int sumf3();
	int dif3();
	int sumf4();
	int dif4();
	void resetAll();
	void sample();
	void filterx1();
	void filterx2();
	void filterx3();
	void filterx4();
	int fmean(int freq, int start);
	int sumOverall();
	int difOverall();
	void complexity();
};
class knueralnet
{
public:
	char outputs;
	char weights[10][10];
	knueralnet(char output);
	char classify(uword text);
	char classify(phoneme p);
private:
	unsigned long o[10];
};

#endif