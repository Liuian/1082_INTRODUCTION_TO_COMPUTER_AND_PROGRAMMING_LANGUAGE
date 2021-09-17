#pragma once
//#define _CRT_SECURE_NO_WARNINGS

class wave_file
{
public:
	wave_file(void);
	wave_file(char*);
	wave_file(char*, short *, long);
	~wave_file(void);
	char file_name[30];


	FILE *fptr;

	char			chunkID[5];			//RIFF
	unsigned long	fileSize;			//AER¡Ñ?j?p
	char			wave[5];			//WAVE
	char			FormatID[5];		//'fmt '

	int a[10];
	unsigned long	sectionChunkSize;	//
	unsigned short	wavetypeFormat;
	unsigned short	mono;
	unsigned long	dwSamplesPerSec;	//Sample rate
	unsigned long	dwAvgBytesPerSec;	//
	unsigned short	wBlockAlign;		//
	unsigned short	wbitsPerSample;		//
	char			data[5];			//data
	unsigned long	chunkSize;			//
	void read(void);
	//void write(void);
	void initial(void);
	unsigned long length;

	double* signal;//|scn¡MeRA


	void read(FILE *fptr);
	void writeAll(FILE *fp, unsigned long length2, int n, double *data2);
	void writeH(FILE *fp);

};