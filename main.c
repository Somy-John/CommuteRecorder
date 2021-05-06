#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int main(void)
{
   People *p[100];
   int count = 0, index = 0, menu;

   // if (loadFile(p, &count, &index) == 1)  printf("=> 로딩 성공!\n");
   // else  printf("=> 파일 없음\n");

   while (1)
   {
      menu = selectMenu();
      if (menu == 0)
         break;
      if (menu == 1 || menu == 3 || menu == 4 || menu == 5 || menu == 6 || menu == 7)
         if (count == 0)
            continue;
      if (menu == 2)
      {
         p[index] = (People *)malloc(sizeof(People));
         count += addPeople(p[index++]);
      }
      else if (menu == 1)
         printList(count, p);
      else if (menu == 3)
      {
         int no;
         printList(count, p);
         printf("수정할 인부의 번호를 선택하시오. (취소:0)\n>> ");
         scanf(" %d", &no);
         if (no > 0)
            changePeople(p[no - 1]);
      }
      else if (menu == 4)
         count = deletePeople(p, count);
      else if (menu == 5)
      {
         int no;
         printList(count, p);
         printf("출결 관리할 인부의 번호를 선택하시오. (취소:0)\n>> ");
         scanf(" %d", &no);
         if (no > 0)
            if (manage_attend(p[no - 1]))
               printf("출결관리 성공\n");
      }
      else if (menu == 6)
      {
         int no;
         printList(count, p);
         printf("보험 처리할 인부의 번호를 선택하시오. (취소:0)\n>> ");
         scanf(" %d", &no);
         if (no > 0)
         {
            if (insuranceManage(p[no - 1]))
               printf("보험처리 성공\n");
         }
      }
      // else if (menu == 7)
      //    selectSearch();
      // else if (menu == 8)
      // {
      //    if (saveToFile(p, index))
      //       printf("저장됨!\n");
      // }
   }
   printf("종료됨 ... \n");
   return 0;
}