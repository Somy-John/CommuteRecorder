#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int selectMenu()
{
   int menu;
   printf("\n*** product.c ***\n");
   printf("1. 명부 출력\n");
   printf("2. 출결 관리\n");
   printf("3. 보험 관리\n");
   printf("4. 인부 추가\n");
   printf("5. 인부 수정\n");
   printf("6. 인부 제거\n");
   printf("7. 파일 저장\n");
   printf("8. 검색\n");
   printf("0. 종료\n\n");
   printf("=> 원하는 버튼은? ");
   scanf("%d", &menu);
   return menu;
}

int addPeople(People *p)
{ // 제품을 추가하는 함수 2
   printf("새 인부의 이름은? ");
   scanf(" %[^\n]", p->name);
   printf("새 인부의 직급은? ");
   scanf(" %d", &p->tier);
   printf("새 인부의 출퇴근 현황은? ");
   scanf(" %d", &p->work);
   return 1;
}

void readProduct(People p)
{ // 하나의 제품 출력 함수
   printf("%6s%6d  %6d%6.1f %6d\n", p.name, p.tier, p.work);
}

int printlist(People **p, int count)
{ // 전체 등록된 제품 리스트 출력 1
   int i = 0;
   printf("  이름 직급 출결 \n");
   for (i = 0; i < count; i++)
   {
      if (p[i] == NULL)
         continue;
      printf("%2d ", i + 1);
      readProduct(*p[i]);
   }
   return 1;
}

int updateProduct(People *p)
{ //제품 수정 3
   printf("새 인부 이름은? ");
   scanf(" %[^\n]", p->name);
   printf("새 인부의 출퇴근 현황은? ");
   scanf(" %d", &p->work);
   printf("새 인부의  직급은(0은 사장, 1은 과장, 2는 부장 3,은 말단, 4는 인턴, 5는 알바)? ");
   scanf(" %d", &p->tier);
   return 1;
}
int manage_attend(People *p){
    int input1;
      printf("출 퇴근 처리할 인부의 번호는? ");
      scanf("%d",input1);
      printf("출결 관리(1출근, 2퇴근, 3야근, 4조퇴)");
      scanf("%d", &p[input1]->work);

}
int insuranceManage(People p){
    int input1;
    printf("보험 처리할 인부의 번호는? ");
      scanf("%d",input1);
      printf("보험 신청(1보험 처리,0종료)");
      scanf("%d", &p[input1]->work);
}



int deleteProduct(People **p, int count)
{ // 제품 삭제 4
   int deleteok, no;
   printlint(p,count);
   printf("삭제할 인부의 번호를 선택하시오.\n>> ");
   scanf(" %d",&no);
   printf("정말로 삭제하시겠습니까?(삭제:1)\n>> ");
   scanf("%d", &deleteok);
   if (deleteok == 1)
      free(p[no - 1]);
   p[no - 1] = NULL;
   count--;
   return count;
}



