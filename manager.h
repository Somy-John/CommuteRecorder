typedef struct {
  char name[20];
  int work;  //(1출근, 2퇴근, 3야근, 4조퇴)
  int tier;  //(0은 사장, 1은 과장, 2는 부장 3,은 말단, 4는 인턴, 5는 알바)
  int bohum;  //(0은 안함, 1은 함)
} People;

void printList(int count, People **p);  //명부 출력 1

int addPeople(People *);  //인부 추가 2

int changePeople(People *p);  //인부 수정 3

int deletePeople(People **p, int count);  //인부 제거 4

int manage_attend(People *p);  //출결 관리 (출근, 퇴근, 야근, 조퇴) 5

int insuranceManage(People *p);  //보험 관리 6

// void selectSearch(); // 검색 선택 7

// void search_name(People **p, int index); //이름 검색 7 - 1

// void search_tier(People **p, int index); //직급 검색 7 - 2

// void search_attand(People **p, int index); //출결기준 검색 7 - 3

// int saveToFile(People **p, int index); // 파일에 저장 8

void readPeople(People p);  // 하나의 제품 출력 함수

// int loadFile(People **p, int *count, int *index); // 파일에서 불러오기

int selectMenu();
