#include <stdio.h>
#include "prodManager.h"
#include <stdlib.h>
#include <string.h>
//제품을 추가한다



int updateproduct(product *p){
    int decision=0;
    printf("이름 수정: ");
    printf("수정하시려면 1번을 눌러주세요\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("이름 입력: ");
        getchar();
        gets(p->name);
    }
    printf("정보 수정: ");
    printf("수정하시려면 1번을 눌러주세요\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("정보 입력: ");
        getchar();
        gets(p->info);
    }
    printf("가격 수정: ");
    printf("수정하시려면 1번을 눌러주세요\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("가격 입력: ");
        scanf("%d",&p->price);
    }
    printf("수량 수정: ");
    printf("수정하시려면 1번을 눌러주세요\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("수량 입력: ");
        scanf("%d",&p->remain);
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
        printf("5. 제품 이름 검색\n");
        printf("6. 제품 가격 검색\n");
        printf("7. 남은 수량 출력\n");
        printf("8. 최종 가격 출력\n");
        printf("9. 제품 정보 파일 저장\n");
        printf("10. 장바구니 담기\n");
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

void addcart(product*p, int count){
    listproduct(p,count);
    int num;
    do{
        printf("추가할 제품의 번호를 입력하시오: ");
        scanf("%d",&num);
    }while(num>count||num<0);
    if(p[num].remain==0) {
        printf("재고가 없습니다!\n");
        return;
    }
    int buy;
    do{
        printf("몇개를 담으시겠습니까? (%d객 남음): ",p[num].remain);
        scanf("%d",&buy);
        if(buy<0) buy = 0;
    } while((buy>p[num].remain));
    p[num].totalSales += num;
    p[num].remain -= buy;
}

void saveData(product *p,char* data,int count){
    FILE *fp=NULL;
    fp=fopen(data,"wt");
    if(fp==NULL) return;
    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue;
        fprintf(fp,"%s;%s;%d;%d;%d\n",p[i].name,p[i].info,p[i].price,p[i].remain,p[i].totalSales);
    }
    fclose(fp);
    printf("저장됨");
}

int loadData(product *p){
    FILE *fp=NULL;
    char *dummy=NULL;
    char sentence[100];
    int i=0;
    fp=fopen("product.txt","rt");
    if(fp==NULL) return -1;
    while(fgets(sentence,100,fp)){
        dummy=strtok(sentence,";");
        strcpy(p[i].name,dummy);
        dummy=strtok(NULL,";");
        strcpy(p[i].info,dummy);
        dummy=strtok(NULL,";");
        p[i].price=atoi(dummy);
        dummy=strtok(NULL,";");
        p[i].remain=atoi(dummy);
        dummy=strtok(NULL,";");
        p[i].totalSales=atoi(dummy);
        i++;
    }
    fclose(fp);
    return i;
}

int selectDataNo(product *p,int count){
    int no;
    listproduct(p,count);
    printf("번호는? 최소 (0) ? ");
    scanf("%d",&no);
    return no;
}

void searchProductName(product *p,int count){
    char search[100];
    int scount=0;
    getchar();
    printf("제품 이름:");
    scanf("%[^\n]s",search);
    printf("\n***************\n");
    for(int i=0;i<count;i++){
        if(p[i].remain==0||p[i].price==-1||p[i].name[0]=='\0') continue;
        if(strstr(p[i].name,search)){
        printf("\n");
        readproduct(p[i]);
        scount++;
        }
    }
    if(scount==0)
    printf("데이터 없음!\n");
}


int printTotalSell(product *p){

}
void printFinalPrice(product*p,int cart[]);


int main(){
    product p[10];
    product cart[10];
    char outputFileName[100];
    int temp; //selectmenu를 받음
    int result;
    int count=0;
    int choice;
    count=loadData(p);
    if(count==-1){
        printf("파일 없음!\n");
        count=0;
    }
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
            choice=selectDataNo(p,count);
            result=updateproduct(&p[choice-1]);
            if(result==1) printf("저장됨!");
        }
        else if(temp==4){//삭제
            if(count==0){
                printf("데이터 없음");
                continue;;
            }
            choice=selectDataNo(p,count);
            result=deleteProduct(&p[choice-1]);
            if(result==1) printf("삭제됨!");
        }
        else if(temp==5){
            searchProductName(p,count);
            //이름 검색
        }
        else if(temp==6){//가격 검색

        }
        else if(temp==7){//남은 수량
            if(count==0){
                printf("데이터 없음");
                continue;
            }
            result=printRemain(p,count);
        }
        else if(temp==9){
            if(count==0){
                printf("데이터 없음");
                continue;
            }
            printf("저장할 파일 이름은?: ");
            scanf("%s",outputFileName);
            saveData(p,outputFileName,count);
        }
        else if (temp == 10){ //장바구니 담기
            if(count == 0){
                printf("데이터 없음");
                continue;
            }
            addcart(p,count);
            continue;
        }
    }
    return 0;
}

