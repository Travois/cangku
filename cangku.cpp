#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define max 32
int ifempty=0;//��־���ж��������޷�Ϊ��
long long int nowcounter=0;
long long int outcounter[3000][12]={0};
long long int incounter[3000][12]={0};
struct outmouth
{
	char name[max];
	int counter[3000][12];
}out_mouth[5000];
int ii=0;
struct outmouth_ki
{
	char kind[max];
	int counter[3000][12];
}out_mouth_ki[5000];
int oo=0;
typedef struct dnode /* ����˫������ṹ�� */ 
{
int year;/*��*/ 
int mouth;/*��*/ 
int day;/*��*/ 
int number; /* ������ */
char name[max]; /* �������� */ 
char  kind[max];/*��������*/
int price;/*����*/
int counter; /* �������� */
struct dnode *prior, *next;
/* ������ָ�룬�ֱ�ָ����ǰ���ͺ�� */
}dlnode; 

dlnode *create(dlnode *L);
dlnode *input(dlnode *L);
dlnode *output(dlnode *L);
dlnode * outnum(dlnode *L);
dlnode * outname(dlnode *L);
dlnode * outkind(dlnode *L);
dlnode *current(dlnode *L);
void search(dlnode *L);
void searchnum(dlnode *L);
void searchname(dlnode *L);
void searchkind(dlnode *L);
void display(dlnode *L) ;

void iocounter()
{
	int y,ye,mo;
	char na[max],ki[max];
	while(1)
{
printf("=====================\n");
printf("1.�ڿ�Ԫ�����ܼ�ֵ\n");
printf("2.ÿ�³���Ԫ�����ܼ�ֵ\n");
printf("3.ÿ�³���Ԫ��������(�����Ʋ�ѯ)\n");
printf("4.ÿ�³���Ԫ��������(�����Ͳ�ѯ)\n");
printf("0.������һ��\n");
printf("====================\n");
printf("ѡ��0--4:");
scanf("%d",&y);
switch(y)
{
case 1:printf("�ڿ�Ԫ�����ܼ�ֵΪ%lld\n",nowcounter);break;
case 2:printf("������������·ݣ�\n");
		scanf("%d%d",&ye,&mo);
		printf("%d��%d�µĳ���Ԫ�����ܼ�ֵΪ%lld\n",ye,mo,outcounter[ye][mo]);
		break;
case 3:printf("������Ԫ�������ƣ�\n") ;
		scanf("%s",&na);
		printf("������������·ݣ�\n") ;
		scanf("%d%d",&ye,&mo);
		for(int i=0;i<=ii;i++)
		if(strcmp(out_mouth[i].name,na)==0)
		printf("%d��%d��%s������%lld��\n",ye,mo,na,out_mouth[i].counter[ye][mo]);
		else printf("δ�ҵ���Ԫ�����������Ƿ��������\n");
		break;
case 4:printf("������Ԫ�������ͣ�\n") ;
		scanf("%s",&ki);
		printf("������������·ݣ�\n") ;
		scanf("%d%d",&ye,&mo);
		for(int i=0;i<=oo;i++)
		if(strcmp(out_mouth_ki[i].kind,ki)==0)
		printf("%d��%d��%s������%lld��\n",ye,mo,ki,out_mouth_ki[i].counter[ye][mo]);
		else printf("δ�ҵ���Ԫ�����������Ƿ��������\n");
		break;
case 0:return;//����
default:printf("enter error!Please input 0--4!\n\n");
getchar();getchar();printf("\n\n");
}
}
}
int main()
{
int x;
dlnode *L;
if(!(L=(dlnode *)malloc(sizeof(dlnode)))) //����ռ�
{
printf("\n");
exit(1);
}
create(L);///���ú���������ͷ�ڵ�
while(1)
{////////////////////////���˵�///////////////////////////
printf(" ============================\n");
printf(" 1. �����������\n");
printf(" 2. ���һ����\n"); 
printf(" 3. ��ʾ�ֿ�����\n");
printf(" 4. ͳ������\n");
printf(" 0. �˳�\n");
printf(" =============================\n");
printf(" ѡ��0--4:");
scanf("%d",&x);
switch(x)
{
case 2:search(L);break;//���ò��Һ���
case 1:current(L);break;//���������⺯��
case 3:display(L);break;//������ʾ�������
case 4:iocounter();break;//����ͳ�ƺ��� 
case 0:printf("\n bye!see you!\n");
getchar();getchar();exit(0);//�˳�����
default:printf("\n Enter erreor!please input 0--4!"); 
getchar();getchar();
}
}
}
dlnode *create(dlnode *L)//��������ͷ�ڵ�
{
printf(" ��ӭʹ�õ���Ԫ�����ֿ����ϵͳ");
getchar(); 
ifempty=0;
///////��ʼ��ͷ�ڵ��ֵ////////
L->next=NULL;L->prior=NULL;
L->number=L->counter=L->day=L->mouth=L->year=L->price=0;
strcpy(L->name," "); 
strcpy(L->kind," "); 
return L;
}

void search(dlnode *L) ///���ҵ���Ҫ�˵�
{
int y;
if(ifempty==0)
{
printf("û���������!\n");
getchar();getchar();
return;
}
else
{
while(1)
{
printf("=====================\n");
printf("1.����Ų�ѯ\n");
printf("2.���������Ʋ�ѯ\n");
printf("3.���������Ͳ�ѯ\n");
printf("0.������һ��\n");
printf("====================\n");
printf("ѡ��0--3:");
scanf("%d",&y);
switch(y)
{
case 1:searchnum(L);break;//���ð���Ų��ҵĺ���
case 2:searchname(L);break;//���ð����Ʋ��ҵĺ���
case 3:searchkind(L);break;//���ð����Ʋ��ҵĺ���
case 0:return;//����
default:printf("enter error!Please input 0--3!\n\n");
getchar();getchar();printf("\n\n");
}
}
}
}
void searchnum(dlnode *L)///����Ų��ҵĺ���
{
int num,flag=0;//flagΪ�Ƿ��ҵ��ı�־
dlnode *head=L;
if(ifempty==0)
{
printf("û�л��ﱻ����\n");
getchar();getchar();
return;
}
printf("������Ҫ���ҵĻ�����:\n");
scanf("%d",&num);
while((L=L->next)!=head)
{
if(L->number==num)
{ flag=1;//flagΪ1ʱ��ʾ�ҵ�
printf("�ҵ�ָ����Ż��� \n"); 
printf("\n���:%d\n",L->number);
printf("����:%s\n",L->name) ;
printf("����:%s\n",L->kind) ;
printf("����:%d\n\n",L->counter); 
} 
}
if(flag==0)//flagΪ0ʱ��ʾû���ҵ�
printf("δ�ҵ���Ԫ�����������Ƿ��������\n");
getchar();getchar();
}

void searchname(dlnode *L)//�����Ʋ��ҵĺ���
{
int flag=0;//flagΪ�Ƿ��ҵ��ı�־
char na[32];
dlnode *head=L;
if(ifempty==0)
{
printf("û�л��ﱻ����\n");
getchar();getchar();
return;
}
printf("������Ҫ���ҵĻ�������\n");
scanf("%s",&na);
while((L=L->next)!=head)
{
if(strcmp(L->name,na)==0)
{ flag=1;//flagΪ1ʱ��ʾ�ҵ�
printf("�ҵ�ָ�����ƻ��� \n"); 
printf("\n���:%d\n",L->number);
printf("����:%s\n",L->name) ;
printf("����:%s\n",L->kind) ;
printf("����:%d\n\n",L->counter); 
} 
}

if(flag==0)//flagΪ0ʱ��ʾû���ҵ�
printf("δ�ҵ���Ԫ�����������Ƿ��������\n\n");
getchar();getchar();
}

void searchkind(dlnode *L)//�����Ʋ��ҵĺ���
{
int flag=0;//flagΪ�Ƿ��ҵ��ı�־
char ki[32];
dlnode *head=L;
if(ifempty==0)
{
printf("û�л��ﱻ����\n");
getchar();getchar();
return;
}
printf("������Ҫ���ҵĻ�������\n");
scanf("%s",&ki);
while((L=L->next)!=head)
{
if(strcmp(L->kind,ki)==0)
{ flag=1;//flagΪ1ʱ��ʾ�ҵ�
printf("�ҵ�ָ�����ͻ��� \n"); 
printf("\n���:%d\n",L->number);
printf("����:%s\n",L->name) ;
printf("����:%s\n",L->kind) ; 
printf("����:%d\n\n",L->counter); 
} 
}

if(flag==0)//flagΪ0ʱ��ʾû���ҵ�
printf("δ�ҵ���Ԫ�����������Ƿ��������\n\n");
getchar();getchar();
}
dlnode *current(dlnode *L)//���������⺯��
{
int y;
while(1)
{
printf("========================\n");
printf(" 1.�������\n");
printf(" 2.�������\n");
printf(" 0.������һ��\n");
printf("========================\n");
printf(" ѡ��0--2:");
scanf("%d",&y);
switch(y)
{
case 1:input(L);break;//������⺯��
case 2:output(L);break;//���ó��⺯��
case 0:return(L);//������һ��
default:printf("enter error!Please input 0--2!");
getchar();getchar();
printf("\n\n");
}
}
}

dlnode *input(dlnode *L)//������⺯��
{
dlnode *in,*head;
head=in=(dlnode *)malloc(sizeof(dlnode));//����ռ�
head=L;

printf("\n����������(�� �� ��)��\n");
scanf("%d%d%d",&in->year,&in->mouth,&in->day);
printf("\n�������������:\n");
printf("���:");scanf("%d",&in->number);
printf("����:");scanf("%s",&in->name);
printf("����:");scanf("%s",&in->kind);
printf("����:");scanf("%d",&in->price);
printf("����:");scanf("%d",&in->counter);
incounter[in->year][in->mouth]+=in->price*in->counter;
nowcounter+=in->price*in->counter;
if(L->next==NULL) //���ֻ��ͷ�ڵ㣬
{ //�Ѹ������in�ڵ�
L->next=in; //����ͷ�ڵ����
L->prior=in; //
in->next=L; //
in->prior=L; //
ifempty++; //ifempty��1
}
else
{//�����ǰL����һ���ڵ㲻��ͷ�ڵ�
while((L=L->next)!=head)
{//��������������L->number����嵽L��ǰ��
if(L->number<in->number)
{
in->next=L;
in->prior=L->prior; 
L->prior->next=in;
L->prior=in;
ifempty++; //ifempty��1
return(head);
} 
}
//����ı�ű�������Ŷ�С����嵽�����ڵ㣬����β����
head->prior->next=in;
in->prior=head->prior;
head->prior=in;
in->next=head;
ifempty++; //ifempty��1
} 
return head;
}

dlnode *output(dlnode *L)//����ĺ���
{
int y;
dlnode *head=L;
if(ifempty==0)//����Ƿ��л�������
{
printf("û�л�������ϵͳ\n");
getchar();getchar();
return(head);
} 
while(1)
{
printf("=============\n");
printf("1.����ų���\n");
printf("2.�����Ƴ���\n");
printf("3.�����ͳ���\n");
printf("0.������һ��\n");
printf("==============\n");
printf("ѡ��0--3:");scanf("%d",&y);
switch(y)
{
case 1:outnum(L);break;//���ð���ų��⺯��
case 2:outname(L);break;//���ð����Ƴ��⺯��
case 3:outkind(L);break;//���ð����ͳ��⺯��
case 0:return(L);
default:printf("enter error!Please input 0--3!");
getchar();getchar();printf("\n\n");
}
}
} 
dlnode *outnum(dlnode *L)//����ų��⺯��
{ 
int num;
dlnode *head=L;

printf("������������ı��:");
scanf("%d",&num);
while((L=L->next)!=head)
{//����ҵ���ɾ���ڵ�
if(L->number==num)
{
outcounter[L->year][L->mouth]+=L->price*L->counter;
nowcounter-=L->price*L->counter;
for(int i=0;i<oo;i++)
if(strcmp(out_mouth_ki[i].kind,L->kind)==0)
out_mouth_ki[i].counter[L->year][L->mouth]+=L->counter;
else
{
	strcpy(out_mouth_ki[oo++].kind,L->kind);
	out_mouth_ki[oo-1].counter[L->year][L->mouth]=L->counter;
}
for(int i=0;i<ii;i++)
if(strcmp(out_mouth[i].name,L->name)==0)
out_mouth[i].counter[L->year][L->mouth]+=L->counter;
else
{
	strcpy(out_mouth[ii++].name,L->name);
	out_mouth[ii-1].counter[L->year][L->mouth]=L->counter;
}
L->prior->next=L->next;
L->next->prior=L->prior;
ifempty--; //ifempty��1 
printf("���Ϊ%d�Ļ���ɹ�����",num); 
getchar();getchar();
return head; 
} 
}
printf("δ�ҵ���Ԫ�����������Ƿ��������\n\n");
getchar();getchar();
return (head);
}

dlnode *outname(dlnode *L)//�����Ƴ��⺯��
{
char na[32];
dlnode *head=L;

printf("�����������������:");
scanf("%s",&na);
while((L=L->next)!=head)
{//����ҵ���ɾ���ڵ�
if(strcmp(L->name,na)==0)
{
outcounter[L->year][L->mouth]+=L->price*L->counter;
nowcounter-=L->price*L->counter;
for(int i=0;i<ii;i++)
if(strcmp(out_mouth[i].name,L->name)==0)
out_mouth[i].counter[L->year][L->mouth]+=L->counter;
else
{
	strcpy(out_mouth[ii++].name,L->name);
	out_mouth[ii-1].counter[L->year][L->mouth]=L->counter;
}
for(int i=0;i<oo;i++)
if(strcmp(out_mouth_ki[i].kind,L->kind)==0)
out_mouth_ki[i].counter[L->year][L->mouth]+=L->counter;
else
{
	strcpy(out_mouth_ki[oo++].kind,L->kind);
	out_mouth_ki[oo-1].counter[L->year][L->mouth]=L->counter;
}
L->prior->next=L->next;
L->next->prior=L->prior;
ifempty--; //ifempty��1 
printf("����Ϊ%s�Ļ���ɹ�����",na);
getchar();getchar();
return (head);
}
}
printf("δ�ҵ���Ԫ�����������Ƿ��������\n\n");
getchar();getchar();
return(head);
} 

dlnode *outkind(dlnode *L)//�����Ƴ��⺯��
{
char ki[32];
dlnode *head=L;

printf("�����������������:");
scanf("%s",&ki);
while((L=L->next)!=head)
{//����ҵ���ɾ���ڵ�
if(strcmp(L->kind,ki)==0)
{
outcounter[L->year][L->mouth]+=L->price*L->counter;
nowcounter-=L->price*L->counter;
for(int i=0;i<ii;i++)
if(strcmp(out_mouth[i].name,L->name)==0)
out_mouth[i].counter[L->year][L->mouth]+=L->counter;
else
{
	strcpy(out_mouth[ii++].name,L->name);
	out_mouth[ii-1].counter[L->year][L->mouth]=L->counter;
}
for(int i=0;i<oo;i++)
if(strcmp(out_mouth_ki[i].kind,L->kind)==0)
out_mouth_ki[i].counter[L->year][L->mouth]+=L->counter;
else
{
	strcpy(out_mouth_ki[oo++].kind,L->kind);
	out_mouth_ki[oo-1].counter[L->year][L->mouth]=L->counter;
}
L->prior->next=L->next;
L->next->prior=L->prior;
ifempty--; //ifempty��1 
printf("����Ϊ%s�Ļ���ɹ�����",ki);
getchar();getchar();
return (head);
}
}
printf("δ�ҵ���Ԫ�����������Ƿ��������\n\n");
getchar();getchar();
return(head);
} 

void display(dlnode *L)//��ʾ�����嵥
{
dlnode *head=L;
if(ifempty==0)
{
printf("û�л������ʾ\n");
getchar();getchar();
return;
}
L=L->next;
do
{ 
printf("\n���:%d\n",L->number);
printf("����:%s\n",L->name) ;
printf("����:%s\n",L->kind) ;
printf("����:%d\n\n",L->counter);
}while((L=L->next)!=head);
getchar();getchar(); 
}
