#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
1. 문제 정의
-다양한 영화 정보를 가지고 있고, 조건 검색이 가능한 프로그램 구현
-영화 정보는 movie.dat이라는 파일로부터 읽어와서 저장하며, movie.dat은 아래와 같은 형식으로 영화 정보를 저장하고 있음.
(영화이름) (제작국가) (run time) (평점)
-영화 이름 및 제작국가는 문자열이며, 모두 중간에 공백이 없이 한 단어로 이루어짐
-run time은 정수임
-평점은 소수점을 가지는 숫자임
-아래와 같은 기능을 제공해야 함
1. 저장된 모든 영화 정보에 대해 출력
2. 특정 국가에서 제작된 영화 정보만 출력
3. 특정 run time보다 큰 영화 정보만 출력
4. 특정 평점보다 큰 영화 정보만 출력
-아래와 같이 UI를 제공해서 사용자로 하여금 반복적으로 입력을 받아 위의 기능을 쓸 수 있게 해야 함
-영화 정보는 아래와 같은 형식으로 출력해야 함
---------------------------------
Name : 영화 이름 (제작 국가)
running time : run time 값, score :  평점 값
---------------------------------
2. 코딩 방향
-linked list 코드를 활용해서 영화 정보 저장 (linkedList.h 설명 참조)
1. linked list는 여러 자료들을 저장하기 위한 방법 중 하나로, 배열과 유사한 존재임
2. list를 생성하여 영화 정보를 list에 저장
3. main.c에 linkedList.h를 include하면 list 생성 및 데이터 추가 등의 linked list 관련 함수 사용 가능
-주어진 main.c 및 movie.c 내의 함수들을 채우면 됨
-주석에 언급된 guide 대로 코드 구현
-두가지 구현 방향이 있으며, 각 구현 방향에 맞는 파일을 기반으로 구현
-함수 포인터를 활용해서 구현하는 방법 (movie_functionPointer.zip 활용)
-linked list 관련 함수들을 이용해서 구현 (movie_linkedListFunction.zip 활용)
-코드를 보기 쉽게 들여쓰기를 적절히 삽입
-함수나 변수 정의, 코드 흐름에 대해 다른 사람들이 알아볼 수 있도록 주석을 삽입
-기능 혹은 일정 코드 부분을 구현하거나 디버깅을 통해 코드를 수정할 때마다 형상고나리에 올려서 변화를 추적할 수 있도록 함.
*/

int main(int argc, char *argv[]) {
	return 0;
}
