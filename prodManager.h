#include <stdio.h>
typedef struct
{
  char name[20];
  char info[50];
  int price;
  int remain;
  int totalSales;
}product;


int createproduct(product *p);//제품을 추가한다.
void addcart(product*p, int count); //장바구니에 제품을 추가한다
int readproduct(product p);//한가지의 프로덕트 정보를 출력한다.
void listproduct(product p[],int count);//모든 프로덕트의 정보를 출력한다.
int updateproduct(product *p);//제품 정보를 업데이트한다.
int deleteproduct(product *p);//제품의 정보를 삭제한다.
void searchProductName(product *p, int count);//제품 이름 검색을 이용해 물품 정보를 출력한다.
void searchProductPrice(product p);//제품 가격 검색을 이용해 물품 정보 출력
int loadData(product *p);//파일 형태의 제품 정보를 입력한다.
void saveData(product *p,char* data, int count);//파일 형태로 제품 정보를 추가한다.
int selectMenu();//추가, 출력, 업데이트 등 어떠한 기능을 사용할지 출력한다.
int selectDataNo(product *p, int count);//특정 번호의 제품 정보를 출력한다.
int printRemain(product *p,int count);//남은 개수를 알려준다. 
void printTotalSell(product *p,int count);//지금까지 팔린 개수를 알려준다. 
void printFinalPrice(product*p,int count); //총 매출 출력