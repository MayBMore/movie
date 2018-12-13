#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{	 
	movInfo_t* mvPtr; //struct mvPtr

	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	if (mvPtr == NULL) {
		printf("ERROR\n"); 
		return;
	}
		
	strcpy(mvPtr->name, name);
	mvPtr->score = score;
	mvPtr->runTime = runTime;
	strcpy(mvPtr->madeIn, country);
	
	return (void*)mvPtr;
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //struct mvPtr = struct *obj 
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	movInfo_t* mvInfo;
	mvInfo = obj;
	
	return mvInfo->score; 
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{	
	movInfo_t* mvInfo;
	mvInfo = obj;
	
	return mvInfo->runTime;
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvInfo;
	mvInfo = obj;
	
	return mvInfo->name;
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvInfo;
	mvInfo = obj;
	return mvInfo->madeIn;
}


