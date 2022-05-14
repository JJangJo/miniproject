#include <stdio.h>
typedef struct
{
  char name[20];
  char info[50];
  int price;
  int remain;
  int totalSales;
}product;


int createproduct(product *p);//��ǰ�� �߰��Ѵ�.
void addcart(product*p, int count); //��ٱ��Ͽ� ��ǰ�� �߰��Ѵ�
int readproduct(product p);//�Ѱ����� ���δ�Ʈ ������ ����Ѵ�.
void listproduct(product p[],int count);//��� ���δ�Ʈ�� ������ ����Ѵ�.
int updateproduct(product *p);//��ǰ ������ ������Ʈ�Ѵ�.
int deleteproduct(product *p);//��ǰ�� ������ �����Ѵ�.
void searchProductName(product *p, int count);//��ǰ �̸� �˻��� �̿��� ��ǰ ������ ����Ѵ�.
void searchProductPrice(product p);//��ǰ ���� �˻��� �̿��� ��ǰ ���� ���
int loadData(product *p);//���� ������ ��ǰ ������ �Է��Ѵ�.
void saveData(product *p,char* data, int count);//���� ���·� ��ǰ ������ �߰��Ѵ�.
int selectMenu();//�߰�, ���, ������Ʈ �� ��� ����� ������� ����Ѵ�.
int selectDataNo(product *p, int count);//Ư�� ��ȣ�� ��ǰ ������ ����Ѵ�.
int printRemain(product *p,int count);//���� ������ �˷��ش�. 
int printTotalSell(product *p);//���ݱ��� �ȸ� ������ �˷��ش�. 
void printFinalPrice(product*p,int cart[]);