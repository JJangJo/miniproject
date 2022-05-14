#include <stdio.h>
#include "prodManager.h"
#include <stdlib.h>
#include <string.h>
//��ǰ�� �߰��Ѵ�



int updateproduct(product *p){
    int decision=0;
    printf("�̸� ����: ");
    printf("�����Ͻ÷��� 1���� �����ּ���\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("�̸� �Է�: ");
        getchar();
        gets(p->name);
    }
    printf("���� ����: ");
    printf("�����Ͻ÷��� 1���� �����ּ���\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("���� �Է�: ");
        getchar();
        gets(p->info);
    }
    printf("���� ����: ");
    printf("�����Ͻ÷��� 1���� �����ּ���\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("���� �Է�: ");
        scanf("%d",&p->price);
    }
    printf("���� ����: ");
    printf("�����Ͻ÷��� 1���� �����ּ���\n");
    scanf("%d",&decision);
    if(decision==1){
        printf("���� �Է�: ");
        scanf("%d",&p->remain);
    }
    return 1;

}

int printRemain(product *p,int count){//���� ���� ���
    for(int i=0;i<count;i++){
        if(p[i].remain==0) continue; // ���� delete�� ��ǰ�̶�� �پ�Ѱ� ���
        printf("%s: %d�� ���ҽ��ϴ�.\n",p[i].name,p[i].remain);
    }
    return 1;
}

int deleteProduct(product *p){//��ǰ�� ������ �����Ѵ�.
        p->price=-1;
        p->name[0]='\0';
        p->remain=0;
        return 1;
}


int selectMenu(){//�޴� ���� ���
        int menu;
        printf("\n\n�޴� ����\n");
        printf("================\n");
        printf("1. ��ǰ �߰�\n");
        printf("2. ��ǰ ���� ���\n");
        printf("3. ��ǰ ���� ������Ʈ\n");
        printf("4. ��ǰ ���� ����\n");
        printf("5. ��ǰ �̸� �˻�\n");
        printf("6. ��ǰ ���� �˻�\n");
        printf("7. ���� ���� ���\n");
        printf("8. ���� ���� ���\n");
        printf("9. ��ǰ ���� ���� ����\n");
        printf("10. ��ٱ��� ���\n");
        printf("0. ����\n");
        printf("========================\n\n");
        scanf("%d",&menu);
        printf("\n");
       return menu;
}
//��ǰ�� �߰��Ѵ� 
int createproduct(product *p){

  printf("\n��ǰ��: ");
  getchar();
  gets(p->name);
  printf("��ǰ ����: ");
  gets(p->info);
  printf("��ǰ ����: ");
  scanf("%d",&p->price);
  printf("��ǰ ����: ");
  scanf("%d",&p->remain);
  p->totalSales = 0;
  printf("\n�߰� �Ϸ�!\n\n");
  return 0;
}

//�Ѱ����� ���δ�Ʈ ������ ����Ѵ� (�ڼ���).
/* ����:

��ǰ��: �̴� ũ�οͻ�
200��
10�� ����

��ǰ ����: ũ�οͻ󺸴� ���� ũ�οͻ�

*/
int readproduct(product p){

    if (p.name[0] == '\0' || p.price < 0 || p.remain < 1) {
  printf("������ üǰ�Դϴ�!");
  return 0;
  } //check for empty
  printf("\n***********************************\n");
  printf("��ǰ��: %s\n%d��\n",p.name,p.price);
  printf("%d�� ���� \n",p.remain);
  printf("\n��ǰ ����: %s",p.info);
  printf("\n***********************************\n\n");
  return 0;
}

//��� ���δ�Ʈ�� ������ ����Ѵ�(�����ϰ�).
void listproduct(product p[],int count){
    printf("\n***********************************\n\n");
    for (int i = 0; i < count; i++)
    {
        if (p[i].name[0] == '\0' || p[i].price < 0 || p[i].remain<1) continue;//check for empty
       
        printf("��ǰ��: %s\n ����:%d\t ���:%d\n",p[i].name,p[i].price,p[i].remain);
    }
    printf("\n***********************************\n\n");
    
}

void addcart(product*p, int count){
    listproduct(p,count);
    int num;
    do{
        printf("�߰��� ��ǰ�� ��ȣ�� �Է��Ͻÿ�: ");
        scanf("%d",&num);
    }while(num>count||num<0);
    if(p[num].remain==0) {
        printf("��� �����ϴ�!\n");
        return;
    }
    int buy;
    do{
        printf("��� �����ðڽ��ϱ�? (%d�� ����): ",p[num].remain);
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
    printf("�����");
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
    printf("��ȣ��? �ּ� (0) ? ");
    scanf("%d",&no);
    return no;
}

void searchProductName(product *p,int count){
    char search[100];
    int scount=0;
    getchar();
    printf("��ǰ �̸�:");
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
    printf("������ ����!\n");
}


int printTotalSell(product *p){

}
void printFinalPrice(product*p,int cart[]);


int main(){
    product p[10];
    product cart[10];
    char outputFileName[100];
    int temp; //selectmenu�� ����
    int result;
    int count=0;
    int choice;
    count=loadData(p);
    if(count==-1){
        printf("���� ����!\n");
        count=0;
    }
    while(1){
        temp=selectMenu();
        if(temp==0) break;
        if(temp==1){//�߰�
            result=createproduct(&p[count]);
                if(result==0){
                    printf("�����");
                    count++;
                }
            }
        else if(temp==2){//���
            if(count==0){
                printf("������ ����");
                continue;;
            }
            listproduct(p,count);
            if(result==0){
                printf("������ ���\n");
            }
        }
        else if(temp==3){//������Ʈ
            if(count==0){
                printf("������ ����");
                continue;;
            }
            choice=selectDataNo(p,count);
            result=updateproduct(&p[choice-1]);
            if(result==1) printf("�����!");
        }
        else if(temp==4){//����
            if(count==0){
                printf("������ ����");
                continue;;
            }
            choice=selectDataNo(p,count);
            result=deleteProduct(&p[choice-1]);
            if(result==1) printf("������!");
        }
        else if(temp==5){
            searchProductName(p,count);
            //�̸� �˻�
        }
        else if(temp==6){//���� �˻�

        }
        else if(temp==7){//���� ����
            if(count==0){
                printf("������ ����");
                continue;
            }
            result=printRemain(p,count);
        }
        else if(temp==9){
            if(count==0){
                printf("������ ����");
                continue;
            }
            printf("������ ���� �̸���?: ");
            scanf("%s",outputFileName);
            saveData(p,outputFileName,count);
        }
        else if (temp == 10){ //��ٱ��� ���
            if(count == 0){
                printf("������ ����");
                continue;
            }
            addcart(p,count);
            continue;
        }
    }
    return 0;
}

