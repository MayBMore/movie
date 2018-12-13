#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{ //����ü���� 
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{	 
	movInfo_t* mvPtr; //struct mvPtr

	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t)); //�����޸� �Ҵ��ϱ� 
	
	if (mvPtr == NULL) { //mvPtr�� �ƹ��͵� ���� �� ������� ǥ���ϱ� 
		printf("ERROR\n"); 
		return;
	}
		
	strcpy(mvPtr->name, name); //��ȭ �̸��� name�� �����ϱ� 
	mvPtr->score = score; //��ȭ ������ score�� �����ϱ� 
	mvPtr->runTime = runTime; //��ȭ ��Ÿ���� runTime�� �����ϱ� 
	strcpy(mvPtr->madeIn, country); //��ȭ ������ country�� �����ϱ� 
	
	return (void*)mvPtr; //�ٽ� mvPtr�� ��ȯ 
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //struct mvPtr = struct *obj 
	
	if (mvPtr == NULL) //mvPtr�� �ƹ��͵� ���� �� Error ��� 
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn); //�̸��� ���� ��� 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score); //��Ÿ�Ӱ� ���� ��� 
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo �����ϰ� ����ȯ 
	
	return mvInfo->score; //mvInfo�� score�� ��ȯ 
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{	
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo �����ϰ� ����ȯ 
	
	return mvInfo->runTime; //mvInfo�� runTime���� ��ȯ 
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo �����ϰ� ����ȯ 
	
	return mvInfo->name; //mvInfo�� name���� ��ȯ 
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo �����ϰ� ����ȯ 
	
	return mvInfo->madeIn; //mvInfo�� madeIn���� ��ȯ 
}


