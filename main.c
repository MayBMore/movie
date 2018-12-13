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
		
	int count = 0; //����� �󸶳� �ִ��� ���� ���� ���� ���� 

	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r"); //movie.dat ���� ���� 
	printf("Reading the data files...\n"); //������ ������ �д� ��...
	 
	if(NULL == fp) {  //���� ���⿡ ������ ���
		printf("Error!!\n");
		return; 
	}
	
	list = list_genList(); //1.2 list generation (use function list_genList() )
	
	//1.3 read each movie data from the file and add it to the linked list
	while (fscanf(fp, "%s %s %i %6f", name, country, &runTime, &score) != EOF) //name, country, runtime and score�� �ҷ��� �б� 
	{
		mvInfo = mv_genMvInfo(name, score, runTime, country); //generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);
	}

	//1.4 FILE close
	fclose(fp); //������ ����
	
	printf("Read done! %i items are read.\n\n", list_len(list) ); //������ �� �а� ��Ͽ� �� �� �ִ��� ��� 
	 
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("--------------------Menu--------------------\n"); //�޴� �� 
		printf("1. print all the movies\n"); //1. ����� ��� ��ȭ ������ ���� ��� 
		printf("2. search for specific country movies\n"); //2. Ư�� �������� ���۵� ��ȭ ������ ��� 
		printf("3. search for specific runtime movies\n"); //3. Ư�� ��Ÿ�Ӻ��� ū ��ȭ ������ ���
		printf("4. search for specific score movies\n"); //4. Ư�� �������� ū ��ȭ ������ ���
		printf("5. exit\n"); //5. ���� 
		printf("--------------------Menu--------------------\n\n"); //��
		
		printf("--select an option : "); //�ɼǼ���
		scanf("%d", &option); //����ڰ� ������ ���ڸ� option�� ���� 
			 
		switch(option)
		{ 
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n"); //����� ��� ��ȭ�� ��� ��.... 
				
				ndPtr = list;
				while ( list_isEndNode(ndPtr) == 0 ) /* repeat until the ndPtr points to the end node */
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //���� ��� ����Ű��
					mvInfo = list_getNdObj(ndPtr); //mvInfo�� ��忡�� ������ get object of ndPtr to mvInfo void pointer
					
					mv_print(mvInfo); //mvInfo�� ����� ��� ����ϱ� print the contents of the mvInfo
					printf("---------------------------------------------------\n"); //���м�	
				}
				
				printf("	- totally %i movies are listed!\n\n\n", list_len(list)); //��Ͽ� �� �� ���� ��ȭ ������ �ִ��� ��� 
				
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				printf("select a country : "); //���� ������ �ޱ� ���� �� �� 
				scanf("%s", country); //���� �Է¹��� 
		
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)/* repeat until the ndPtr points to the end node */
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //���� ��� ����Ű��
					mvInfo = list_getNdObj(ndPtr); //mvInfo�� ��忡�� ������ get object of ndPtr to mvInfo void pointer
					
					if(strcmp(country,mv_getCountry(mvInfo)) == 0) { //strcmp�Լ��� ����� �Է¹��� country�� ��Ͽ� �ִ� ��ȭ ���ϱ� if the input country matches to the country of the movie,
						mv_print(mvInfo); //then print the contents of the mvInfo
						printf("---------------------------------------------------\n");
						count++; //�� �� ���� ��ȭ�� �̿� �ش�Ǵ��� ���� 
					}
				}
				
				printf("	- totally %i movies are listed!\n\n\n", count); //�� �� ���� ��ȭ�� �̿� �ش�Ǵ��� ����ϱ� 
				count = 0; //count�� �ٽ� 0���� �ʱ�ȭ�ϱ� 
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				printf("lowest runtime : "); //��Ÿ���� �ޱ� ���� �� �� 
				scanf("%i", &runTime);  //��Ÿ���� �Է¹���
				
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)/* repeat until the ndPtr points to the end node */
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //���� ��� ����Ű��
					mvInfo = list_getNdObj(ndPtr); //mvInfo�� ��忡�� ������ get object of ndPtr to mvInfo void pointer
					
					if(runTime <= mv_getRunTime(mvInfo)){ //�Է¹��� ����Ÿ�Ӻ��� �� ��ȭ ����� ã�� if the input runtime is lower than the runtime of the movie,
						mv_print(mvInfo); //����ϱ� if the input runtime is lower than the runtime of the movie,
						printf("---------------------------------------------------\n");
						count++; //�� �� ���� ��ȭ�� �̿� �ش�Ǵ��� ���� 
					}
				}
			
				printf("	- totally %i movies are listed!\n\n\n", count); //�� �� ���� ��ȭ�� �̿� �ش�Ǵ��� ����ϱ� 
				count=0; //count�� �ٽ� 0���� �ʱ�ȭ�ϱ� 
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				printf("lowest score : "); //������ �ޱ� ���� �� ��
				scanf("%f", &score); //������ �Է� ����
				 
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0) /* repeat until the ndPtr points to the end node */
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr); //���� ��� ����Ű��
					mvInfo = list_getNdObj(ndPtr); //mvInfo�� ��忡�� ������ get object of ndPtr to mvInfo void pointer
					
					if(score <= mv_getScore(mvInfo)){ //�Է¹��� �������� ū ��ȭ�� ã�� if the input score is lower than the score of the movie,
						mv_print(mvInfo); //��� then print the contents of the mvInfo
						printf("---------------------------------------------------\n");
						count++;//�� �� ���� ��ȭ�� �̿� �ش�Ǵ��� ���� 
					}
			    }
				
				printf("	- totally %i movies are listed!\n\n\n", count);	//�� �� ���� ��ȭ�� �̿� �ش�Ǵ��� ����ϱ�
				count=0; //count�� �ٽ� 0���� �ʱ�ȭ�ϱ� 
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




