#include <stdio.h>
#include "prodManager.h"

//제품을 추가한다
int createproduct(product *p){

	printf("\n제품명: ");
    getchar();
	fgets(p->name,sizeof(p->name),stdin);
	printf("제품 정보: ");
	getchar();
	fgets(p->info,sizeof(p->info),stdin);
	printf("제품 가격: ");
	scanf("%d",p->price);
	printf("제품 수량: ");
	scanf("%d",&p->remain);
    p->totalSales = 0;
	printf("\n추가 완료!\n\n");
}


int main(){
    return 0;
}
