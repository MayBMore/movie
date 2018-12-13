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
		
	int count = 0; //목록이 얼마나 있는지 세기 위한 변수 선언 

	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r"); //movie.dat 파일 열기 
	printf("Reading the data files...\n"); //데이터 파일을 읽는 중...
	 
	if(NULL == fp) {  //파일 열기에 실패한 경우
		printf("Error!!\n");
		return; 
	}
	
	list = list_genList(); //1.2 list generation (use function list_genList() )
	
	//1.3 read each movie data from the file and add it to the linked list
	while (fscanf(fp, "%s %s %i %6f", name, country, &runTime, &score) != EOF) //name, country, runtime and score를 불러와 읽기 
	{
		mvInfo = mv_genMvInfo(name, score, runTime, country); //generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);
	}

	//1.4 FILE close
	fclose(fp); //파일을 닫음
	
	printf("Read done! %i items are read.\n\n", list_len(list) ); //파일을 다 읽고 목록에 몇 개 있는지 출력 
	 
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("--------------------Menu--------------------\n"); //메뉴 줄 
		printf("1. print all the movies\n"); //1. 저장된 모든 영화 정보에 대해 출력 
		printf("2. search for specific country movies\n"); //2. 특정 국가에서 제작된 영화 정보만 출력 
		printf("3. search for specific runtime movies\n"); //3. 특정 런타임보다 큰 영화 정보만 출력
		printf("4. search for specific score movies\n"); //4. 특정 평점보다 큰 영화 정보만 출력
		printf("5. exit\n"); //5. 종료 
		printf("--------------------Menu--------------------\n\n"); //줄
		
		printf("--select an option : "); //옵션선택
		scanf("%d", &option); //사용자가 선택한 숫자를 option에 저장 
			 
		switch(option)
		{ 
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n"); //목록의 모든 영화를 출력 중.... 
				
				ndPtr = list;
				while ( list_isEndNode(ndPtr) == 0 ) /* repeat until the ndPtr points to the end node */
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //다음 노드 가르키기
					mvInfo = list_getNdObj(ndPtr); //mvInfo를 노드에서 꺼내기 get object of ndPtr to mvInfo void pointer
					
					mv_print(mvInfo); //mvInfo에 저장된 목록 출력하기 print the contents of the mvInfo
					printf("---------------------------------------------------\n"); //구분선	
				}
				
				printf("	- totally %i movies are listed!\n\n\n", list_len(list)); //목록에 총 몇 개의 영화 정보가 있는지 출력 
				
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				printf("select a country : "); //나라 선택을 받기 위해 쓴 글 
				scanf("%s", country); //나라를 입력받음 
		
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)/* repeat until the ndPtr points to the end node */
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //다음 노드 가르키기
					mvInfo = list_getNdObj(ndPtr); //mvInfo를 노드에서 꺼내기 get object of ndPtr to mvInfo void pointer
					
					if(strcmp(country,mv_getCountry(mvInfo)) == 0) { //strcmp함수를 사용해 입력받은 country와 목록에 있는 영화 비교하기 if the input country matches to the country of the movie,
						mv_print(mvInfo); //then print the contents of the mvInfo
						printf("---------------------------------------------------\n");
						count++; //총 몇 개의 영화가 이에 해당되는지 세기 
					}
				}
				
				printf("	- totally %i movies are listed!\n\n\n", count); //총 몇 개의 영화가 이에 해당되는지 출력하기 
				count = 0; //count를 다시 0으로 초기화하기 
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				printf("lowest runtime : "); //런타임을 받기 위해 쓴 글 
				scanf("%i", &runTime);  //런타임을 입력받음
				
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)/* repeat until the ndPtr points to the end node */
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //다음 노드 가르키기
					mvInfo = list_getNdObj(ndPtr); //mvInfo를 노드에서 꺼내기 get object of ndPtr to mvInfo void pointer
					
					if(runTime <= mv_getRunTime(mvInfo)){ //입력받은 러닝타임보다 긴 영화 목록을 찾음 if the input runtime is lower than the runtime of the movie,
						mv_print(mvInfo); //출력하기 if the input runtime is lower than the runtime of the movie,
						printf("---------------------------------------------------\n");
						count++; //총 몇 개의 영화가 이에 해당되는지 세기 
					}
				}
			
				printf("	- totally %i movies are listed!\n\n\n", count); //총 몇 개의 영화가 이에 해당되는지 출력하기 
				count=0; //count를 다시 0으로 초기화하기 
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				printf("lowest score : "); //평점을 받기 위해 쓴 글
				scanf("%f", &score); //평점을 입력 받음
				 
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0) /* repeat until the ndPtr points to the end node */
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //다음 노드 가르키기
					mvInfo = list_getNdObj(ndPtr); //mvInfo를 노드에서 꺼내기 get object of ndPtr to mvInfo void pointer
					
					if(score <= mv_getScore(mvInfo)){ //입력받은 평점보다 큰 영화를 찾음 if the input score is lower than the score of the movie,
						mv_print(mvInfo); //출력 then print the contents of the mvInfo
						printf("---------------------------------------------------\n");
						count++;//총 몇 개의 영화가 이에 해당되는지 세기 
					}
			    }
				
				printf("	- totally %i movies are listed!\n\n\n", count);	//총 몇 개의 영화가 이에 해당되는지 출력하기
				count=0; //count를 다시 0으로 초기화하기 
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




