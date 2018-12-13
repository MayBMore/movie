#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{ //구조체선언 
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{	 
	movInfo_t* mvPtr; //struct mvPtr

	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t)); //동적메모리 할당하기 
	
	if (mvPtr == NULL) { //mvPtr에 아무것도 없을 때 에러라고 표시하기 
		printf("ERROR\n"); 
		return;
	}
		
	strcpy(mvPtr->name, name); //영화 이름을 name에 저장하기 
	mvPtr->score = score; //영화 평점을 score에 저장하기 
	mvPtr->runTime = runTime; //영화 런타임을 runTime에 저장하기 
	strcpy(mvPtr->madeIn, country); //영화 국가를 country에 저장하기 
	
	return (void*)mvPtr; //다시 mvPtr로 반환 
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //struct mvPtr = struct *obj 
	
	if (mvPtr == NULL) //mvPtr에 아무것도 없을 시 Error 출력 
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn); //이름과 국가 출력 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score); //런타임과 평점 출력 
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo 선언하고 형변환 
	
	return mvInfo->score; //mvInfo를 score로 반환 
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{	
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo 선언하고 형변환 
	
	return mvInfo->runTime; //mvInfo를 runTime으로 반환 
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo 선언하고 형변환 
	
	return mvInfo->name; //mvInfo를 name으로 반환 
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvInfo = (movInfo_t*)obj; //mvInfo 선언하고 형변환 
	
	return mvInfo->madeIn; //mvInfo를 madeIn으로 반환 
}


