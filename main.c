#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
		
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r");
	printf("Reading the data files...\n"); //데이터 파일을 읽는 중... 
	if(NULL != fp) {
		list_len(FILE *fp);
		printf("Read done! %i items are read.\n\n", *fp) ; //파일 열기에 성공한 경우 그런데 몇 개 파일인지 어떻게 알지? 
	} else {
		printf("Error!!\n"); //파일 열기에 실패한 경우
	}
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while (ndPtr != NULL) /* read name, country, runtime and score*/ //이게 맞나? 
	{
		mv_genMvInfo(name, score, runTime, country);
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);
	}

	//1.4 FILE close
	fclose(fp); //파일을 닫음
	 
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("--------------------Menu--------------------\n"); //메뉴 줄 
		printf("1. print all the movies\n"); //1. 저장된 모든 영화 정보에 대해 출력 
		printf("2. search for specific country movies\n"); //2. 특정 국가에서 제작된 영화 정보만 출력 
		printf("3. search for specific runtime movies\n"); //3. 특정 런타임보다 큰 영화 정보만 출력
		printf("4. search for specific score movies\n"); //4. 특정 평점보다 큰 영화 정보만 출력
		printf("5. exit\n"); //종료 
		printf("--------------------Menu--------------------\n\n"); //줄
		
		printf("--select an option : "); //옵션선택
		scanf("%d", &option); //사용자가 선택한 숫자를 option에 저장 
			 
		switch(option)
		{ 
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while ( ndPtr != NULL ) /* repeat until the ndPtr points to the end node */ //ndPtr로 할까 list로 할까 
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					mv_print(list);
					list_getNextNd(list);
					//ndPtr = the next node of the ndPtr;
					
					//get object of ndPtr to mvInfo void pointer
					//print the contents of the mvInfo
				}
				
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				printf("select a country : "); //나라 선택을 받기 위해 쓴 글 
				scanf("%s", country); //나라를 입력받음 
				
				char *ndPtr = strstr(list,country); //country에 입력받은 나라를 찾음
				
				while (ndPtr != NULL) { //검색된 문자열이 없을 때까지 반복 
					printf("%s\n", ndPtr); //검색된 문자열 출력
					ndPtr = strstr(ndPtr+1, country); //country 포인터에 1을 더하여  
				}

				ndPtr = list;
					while (ndPtr != NULL)/* repeat until the ndPtr points to the end node */
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input country matches to the country of the movie,
					//then print the contents of the mvInfo
				}
				
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				
				ndPtr = list;
					while (ndPtr != NULL)/* repeat until the ndPtr points to the end node */
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input runtime is lower than the runtime of the movie,
					//then print the contents of the mvInfo
				}
				
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				
				ndPtr = list;
					while (ndPtr != NULL)/* repeat until the ndPtr points to the end node */
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input score is lower than the score of the movie,
					//then print the contents of the mvInfo
				}
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;
}

/* 할 일
1. 파일을 열었을 때 몇 개의 영화 목록이 있는지 어떻게 출력할까
2. while문 어떻게 하지...ㅎ 
*/ 
