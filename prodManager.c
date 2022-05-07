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
    return 1;
}




int updateproduct(product *p){
    int decision=0;
    printf("이름 수정: ");
    printf("수정하시려면 1번을 눌러주세요");
    scanf("%d",&decision);
    if(decision==1){
        printf("이름 입력: ");
        gets(p->name);
    }
    printf("정보 수정: ");
    printf("수정하시려면 1번을 눌러주세요");
    scanf("%d",&decision);
    if(decision==1){
        printf("정보 입력: ");
        gets(p->info);
    }
    printf("가격 수정: ");
    printf("수정하시려면 1번을 눌러주세요");
    scanf("%d",&decision);
    if(decision==1){
        printf("가격 입력: ");
        scanf("%d",p->price);
    }
    printf("수량 수정: ");
    printf("수정하시려면 1번을 눌러주세요");
    scanf("%d",&decision);
    if(decision==1){
        printf("수량 입력: ");
        scanf("%d",p->remain);
    }
    return 1;

}

int printRemain(product *p,int count){//남은 수량 출력
    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue; // 만약 delete된 제품이라면 뛰어넘고 출력
        printf("%s: %d개 남았습니다.\n",p[i].name,p[i].remain);
    }
    return 1;
}

int deleteProduct(product *p){//제품의 정보를 삭제한다.
        p->price=-1;
        p->name[0]='\0';
        return 1;
}


int selectMenu(){//메뉴 선택 기능
        int menu;
        printf("\n\n메뉴 선택\n");
        printf("================\n");
        printf("1. 제품 추가\n");
        printf("2. 제품 정보 출력\n");
        printf("3. 제품 정보 업데이트\n");
        printf("4. 제품 정보 삭제\n");
        // printf("5. 제품 검색\n");
        // printf("6. 제품 정보 파일 저장\n");
        printf("7. 남은 수량 출력\n");
        printf("8. 최종 가격 출력");
        printf("0. 종료\n");
        printf("========================\n\n");
        scanf("%d",&menu);
        printf("\n");
       return menu;
}




int main(){
    return 0;
}
