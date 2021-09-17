#include "StdAfx.h"
#include "wave_file_s.h"
#include < string.h >


wave_file::wave_file(void)//建構子
{
	strncpy_s(chunkID, "RIFF", 4);
	strncpy_s(wave, "WAVE", 4);
	strncpy_s(FormatID, "fmt ", 4);
	strncpy_s(data, "data", 4);
	sectionChunkSize = 16;    //fixed 
	wavetypeFormat = 1;         // uncompressed 
	mono = 1;
	wbitsPerSample = 16;		//16
	dwSamplesPerSec = 44100;	//
	wBlockAlign = 2 * mono;			//{wbitsPerSample/8}*mono
	dwAvgBytesPerSec = dwSamplesPerSec*wBlockAlign;
}

wave_file::wave_file(char* file_name)//建構子
{
	int i;
	short y;
	fopen_s(&fptr, file_name, "rb");
	read(fptr);
	signal = new double[length];
	//讀資料
	for (i = 0; i<length; i++)
	{
		fread(&y, sizeof(short), 1, fptr);
		signal[i] = (double)y;
		//fprintf(fptr2,"%f %f\n",i*h,data[i]);
	}
	fclose(fptr);
}

wave_file::wave_file(char* file_name, short *NewS, long l)//建構子
{
	strncpy_s(chunkID, "RIFF", 4);
	strncpy_s(wave, "WAVE", 4);
	strncpy_s(FormatID, "fmt ", 4);
	strncpy_s(data, "data", 4);
	sectionChunkSize = 16;    //fixed 
	wavetypeFormat = 1;         // uncompressed 
	mono = 1;
	wbitsPerSample = 16;		//16
	dwSamplesPerSec = 44100;	//
	wBlockAlign = 2 * mono;			//{wbitsPerSample/8}*mono
	dwAvgBytesPerSec = dwSamplesPerSec*wBlockAlign;
	//	chunkSize = length*2;						//
	//	fileSize =chunkSize + 36;					//

	int i;
	length = l;
	short y;
	FILE *fp;
	fopen_s(&fp, file_name, "wb");
	writeH(fp);


	for (i = 0; i<l; i++)
	{
		y = short(NewS[i]);
		fwrite(&y, sizeof(short), 1, fp);

	}
	fclose(fp);

}








wave_file::~wave_file(void)//解構子
{
	//	delete [] signal;
}

void wave_file::read(FILE *fptr)
{
	int i;
	short y;

	/*讀檔頭*/
	fread(chunkID, sizeof(char), 4, fptr);						//RIFF 4bytes
	fread(&fileSize, sizeof(unsigned long), 1, fptr);			//檔案大小減8 4bytes
	fread(wave, sizeof(char), 4, fptr);							//WAVE 4bytes
	fread(FormatID, sizeof(char), 4, fptr);						//fmt 4bytes
	fread(&sectionChunkSize, sizeof(unsigned long), 1, fptr);	//16 4bytes
	fread(&wavetypeFormat, sizeof(unsigned short), 1, fptr);	//1 2bytes
	fread(&mono, sizeof(unsigned short), 1, fptr);				//1 2bytes
	fread(&dwSamplesPerSec, sizeof(unsigned long), 1, fptr);	//每秒取樣數 4bytes
	fread(&dwAvgBytesPerSec, sizeof(unsigned long), 1, fptr);	//每秒資料大小 4bytes
	fread(&wBlockAlign, sizeof(unsigned short), 1, fptr);		//每個採樣資料的大小 4bytes
	fread(&wbitsPerSample, sizeof(unsigned short), 1, fptr);	//4bytes
	fread(data, sizeof(char), 4, fptr);							//data 4bytes
	fread(&chunkSize, sizeof(unsigned long), 1, fptr);			//4bytes
																//
	length = chunkSize / wBlockAlign;

}
void wave_file::writeAll(FILE *fp, unsigned long length2, int n, double *data2)
{
	int i, j;
	short y;

	//printf("te-ts%d\n",length2);
	long chunkSize = 2 * length2*n;
	fileSize = chunkSize + 36;

	/////////寫標頭檔//////////
	fwrite(chunkID, sizeof(char), 4, fp);
	fwrite(&fileSize, sizeof(unsigned long), 1, fp);//檔案大小減8 4bytes
	fwrite(wave, sizeof(char), 4, fp);
	fwrite(FormatID, sizeof(char), 4, fp);
	fwrite(&sectionChunkSize, sizeof(unsigned long), 1, fp);//16 4bytes
	fwrite(&wavetypeFormat, sizeof(unsigned short), 1, fp);//1 2bytes
	fwrite(&mono, sizeof(unsigned short), 1, fp);//1 2bytes

	fwrite(&dwSamplesPerSec, sizeof(unsigned long), 1, fp);//每秒取樣數 4bytes
	fwrite(&dwAvgBytesPerSec, sizeof(unsigned long), 1, fp);//每秒資料大小 4bytes
	fwrite(&wBlockAlign, sizeof(unsigned short), 1, fp);//每個採樣資料的大小 4bytes
	fwrite(&wbitsPerSample, sizeof(unsigned short), 1, fp);//4bytes
	fwrite(data, sizeof(char), 4, fp);

	//	fprintf(fp,"data");
	fwrite(&chunkSize, sizeof(unsigned long), 1, fp);
	///////////////////////////////////////
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<length2; j++)
		{
			y = (short)data2[j];
			fwrite(&y, sizeof(short), 1, fp);

		}
	}

}
void wave_file::writeH(FILE *fp)
{
	int i, j;
	short y;

	//printf("te-ts%d\n",length2);
	chunkSize = 2 * length;
	fileSize = chunkSize + 36;

	/////////寫標頭檔//////////
	fwrite(chunkID, sizeof(char), 4, fp);
	fwrite(&fileSize, sizeof(unsigned long), 1, fp);//檔案大小減8 4bytes
	fwrite(wave, sizeof(char), 4, fp);
	fwrite(FormatID, sizeof(char), 4, fp);
	fwrite(&sectionChunkSize, sizeof(unsigned long), 1, fp);//16 4bytes
	fwrite(&wavetypeFormat, sizeof(unsigned short), 1, fp);//1 2bytes
	fwrite(&mono, sizeof(unsigned short), 1, fp);//1 2bytes

	fwrite(&dwSamplesPerSec, sizeof(unsigned long), 1, fp);//每秒取樣數 4bytes
	fwrite(&dwAvgBytesPerSec, sizeof(unsigned long), 1, fp);//每秒資料大小 4bytes
	fwrite(&wBlockAlign, sizeof(unsigned short), 1, fp);//每個採樣資料的大小 4bytes
	fwrite(&wbitsPerSample, sizeof(unsigned short), 1, fp);//4bytes
	fwrite(data, sizeof(char), 4, fp);

	//	fprintf(fp,"data");
	fwrite(&chunkSize, sizeof(unsigned long), 1, fp);
	///////////////////////////////////////

}