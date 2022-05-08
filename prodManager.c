#include <stdio.h>
#include "prodManager.h"


//제품을 추가한다



int updateproduct(product *p){
    int decision=0;
    printf("이름 수정: ");
    printf("수정하시려면 1번을 눌러주세요");
    getchar();
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
        if(p[i].remain==0) continue; // 만약 delete된 제품이라면 뛰어넘고 출력
        printf("%s: %d개 남았습니다.\n",p[i].name,p[i].remain);
    }
    return 1;
}

int deleteProduct(product *p){//제품의 정보를 삭제한다.
        p->price=-1;
        p->name[0]='\0';
        p->remain=0;
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
        printf("8. 최종 가격 출력\n");
        printf("0. 종료\n");
        printf("========================\n\n");
        scanf("%d",&menu);
        printf("\n");
       return menu;
}
//제품을 추가한다 
int createproduct(product *p){

  printf("\n제품명: ");
  getchar();
  gets(p->name);
  printf("제품 정보: ");
  gets(p->info);
  printf("제품 가격: ");
  scanf("%d",&p->price);
  printf("제품 수량: ");
  scanf("%d",&p->remain);
  p->totalSales = 0;
  printf("\n추가 완료!\n\n");
  return 0;
}

//한가지의 프로덕트 정보를 출력한다 (자세히).
/* 예시:

제품명: 미니 크로와상
200원
10개 남음

제품 정보: 크로와상보다 작은 크로와상

*/
int readproduct(product p){

    if (p.name[0] == '\0' || p.price < 0 || p.remain < 1) {
  printf("삭제된 체품입니다!");
  return 0;
  } //check for empty
  printf("\n***********************************\n");
  printf("제품명: %s\n%d원\n",p.name,p.price);
  printf("%d개 남음 \n",p.remain);
  printf("\n제품 정보: %s",p.info);
  printf("\n***********************************\n\n");
  return 0;
}

//모든 프로덕트의 정보를 출력한다(간략하게).
void listproduct(product p[],int count){
    printf("\n***********************************\n\n");
    for (int i = 0; i < count; i++)
    {
        if (p[i].name[0] == '\0' || p[i].price < 0 || p[i].remain<1) continue;//check for empty
       
        printf("제품명: %s\n 가격:%d\t 재고:%d\n",p[i].name,p[i].price,p[i].remain);
    }
    printf("\n***********************************\n\n");
    
}

void addcart(product*p, int *cart[], int count){
  listproduct(p,count);
  int num;
  do{
  printf("추가할 제품의 번호를 입력하시오: ");
  scanf("%d",&num);
  }while(num>count||num<0);
  cart[0] = num;
  do{
  printf("몇개를 담으시겠습니까?: ");
  scanf("%d",&num);
  } while((num<p[num].remain));

 }


int main(){
    product p[10];
    int temp; //selectmenu를 받음
    int result;
    int count=0;
    int choice;
    while(1){
        temp=selectMenu();
        if(temp==0) break;
        if(temp==1){//추가
            result=createproduct(&p[count]);
                if(result==0){
                    printf("저장됨");
                    count++;
                }
            }
        else if(temp==2){//출력
            if(count==0){
                printf("데이터 없음");
                continue;;
            }
            listproduct(p,count);
            if(result==0){
                printf("데이터 출력\n");
            }
        }
        else if(temp==3){//업데이트
            if(count==0){
                printf("데이터 없음");
                continue;;
            }
            printf("몇 번 데이터");
            scanf("%d",&choice);
            result=updateproduct(&p[choice]);
            if(result==1) printf("저장됨!");
        }
        else if(temp==4){//삭제
            if(count==0){
                printf("데이터 없음");
                continue;;
            }
            printf("몇 번 데이터");
            scanf("%d",&choice);
            result=deleteProduct(&p[choice]);
            if(result==1) printf("삭제됨!");
        }
        else if(temp==7){//남은 수량
            if(count==0){
                printf("데이터 없음");
                continue;
            }
            result=printRemain(p,count);
        }
    }
    return 0;
}

