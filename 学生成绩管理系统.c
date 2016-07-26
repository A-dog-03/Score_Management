#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define NAME 0
#define NUMBER 1
#define ALL 2
#define MARK 3
#define COU1 4
#define COU2 5
#define COU3 6
#define COU4 7
#define COU5 8
#define FROMBIG 0                               //�Ӵ�С
#define FROMSMALL 1                             //��С����
typedef struct cou{
	int lesnumber;								//�γ̱��
    char lesname[41];      						//�γ�����
    double score,point;     					//����,ѧ��
}COU;
typedef struct stu{
	int num;									//ѧ��
	char name[11],sex[5],cla[20];				//�������Ա𣬰༶
    struct cou les[5];                       	//5�ſγ�
    double all,average,mark;                    //�ܷ֣�ƽ���֣�����
	struct stu *next;
}STU;
void PrintMenuTea();							 //��ӡ��ʦ�˵�
void PrintMenuStu();							 //��ӡѧ���˵�
void PrintLogin();							     //��ӡ��¼�˵�
void PrintMenuSort();						     //��ӡ����˵�
void PrintMenuSort2();							 //��ӡ����˵�2
int RegisterTea();      						 //��ʦע��
int RegisterStu();      						 //ѧ��ע��
int LoginTea();         						 //��ʦ��¼
int LoginStu();         						 //ѧ����¼
int Count(STU *head);                            //����ѧ������(�ڵ����)
int StuNum(STU *p,double low,double high); 		 //����ѧ����Ŀ��������������
void DisplayAll(STU *head);						 //��ӡ����ѧ����Ϣ
STU *Search_name(STU *head,char *name);		     //ͨ����������ѧ��
STU *Search_num(STU *head,int num);    		     //ͨ��ѧ������ѧ��
void DisplayOne(STU *head,int n,char *name);	 //��ӡһ��ѧ����ϸ��Ϣ
void DisplayCla(STU *head,char *class);			 //���༶��ʾѧ����Ϣ
void DisplayGrade(STU *head,double low,double high); //�������β�ѯ�ɼ�
void DisplayFail(STU *head);					 //�������Ŀ��ѯ
STU *Delete(STU *head,int n,char *name,int *item);   //ɾ��ѧ���ɼ�
int Modify(STU *head,int n,char *name);			 //�޸�ѧ���ɼ�
int Save(STU *head);							 //����ѧ���ɼ�
int Lof(FILE *fp);								 //�����ļ���ѧ������
STU *Initialize();								 //��ʼ����ȡ�ļ��е�ѧ��
STU *Creat(int n);                  			 //��������
int Position(STU *head,STU *p);					 //ȷ���ڵ��������λ��
STU *Sort(STU *head,int m,int n);                //�ɼ�����
STU *SetPosition(STU *head,int n);				 //�������ƶ���ָ���ڵ�
STU *Connect(STU *head,STU *end);   			 //������������
double Mark(STU *p);							 //���㼨��
STU *Input();              			 			 //����ѧ���ɼ�
void HideCursor();								 //���ع��
void PutCursor(); 								 //��ʾ���
void GotoXy(int x,int y);						 //������ƶ���(X,Y)
void GetXy(int *X,int *Y,int x1,int x2,int y1,int y2); //��ȡ���޶���Χ�������������
void Clear(int x,int y,int line);				 //���line�е����ݺ����귵��(x,y)
void PrintMenuTea(){                      		 //��ӡ��ʦ�˵�
	printf("\n");
	printf("         ����������������������ӭʹ��ѧ���ɼ�����ϵͳ������������������         ");
	printf("         ��                                                          ��         ");
	printf("         ��            ��ѡ�������Ŀ��                              ��         ");
	printf("         ��               1.¼��ɼ�          2.�޸ĳɼ�             ��         ");
	printf("         ��               3.ɾ���ɼ�          4.��ѯ�ɼ�             ��         ");
	printf("         ��               5.�ɼ�����          6.��ʾ�ɼ�             ��         ");
	printf("         ��               7.����ɼ�          8.�˳���¼             ��         ");
	printf("         ��               0.�˳�ϵͳ                                 ��         ");
	printf("         ��������������������������������������������������������������         ");
}
void PrintMenuStu(){					         //��ӡѧ���˵�
	printf("\n");
	printf("         ����������������������ӭʹ��ѧ���ɼ�����ϵͳ������������������         ");
	printf("         ��                                                          ��         ");
	printf("         ��            ��ѡ�������Ŀ��                              ��         ");
	printf("         ��               1.��ѯ�ɼ�          2.�˳���¼             ��         ");
	printf("         ��               0.�˳�ϵͳ                                 ��         ");
	printf("         ��������������������������������������������������������������         ");
}
void PrintLogin(){                               //��ӡ��¼����
	printf("\n");
	printf("         ����������������������ӭʹ��ѧ���ɼ�����ϵͳ������������������         ");
	printf("         ��                                                          ��         ");
	printf("         ��            ��ѡ����ݵ�¼��ע�᣺                        ��         ");
	printf("         ��                         1.��ʦע��                       ��         ");
	printf("         ��                         2.��ʦ��¼                       ��         ");
	printf("         ��                         3.ѧ��ע��                       ��         ");
	printf("         ��                         4.ѧ����¼                       ��         ");
	printf("         ��                         0.�˳�ϵͳ                       ��         ");
	printf("         ��������������������������������������������������������������         ");
}
void PrintMenuSort(){                      		 //��ӡ����˵�
	printf("\n");
	printf("         ������������������������ѧ����Ϣ����˵�����������������������         ");
	printf("         ��                                                          ��         ");
	printf("         ��            ��ѡ������ʽ��                              ��         ");
	printf("         ��               1.��ѧ��            2.������               ��         ");
	printf("         ��               3.���ܷ�            4.������               ��         ");
	printf("         ��               5.���γ�1           6.���γ�2              ��         ");
	printf("         ��               7.���γ�3           8.���γ�4              ��         ");
	printf("         ��               9.���γ�5                                  ��         ");
	printf("         ��������������������������������������������������������������         ");
}
void PrintMenuSort2(){					         //��ӡ����˵�2
	printf("\n");
	printf("         ������������������������ѧ����Ϣ����˵�����������������������         ");
	printf("         ��                                                          ��         ");
	printf("         ��            ��ѡ������ʽ��                              ��         ");
	printf("         ��               1.��С����          2.�Ӵ�С             ��         ");
	printf("         ��������������������������������������������������������������         ");
}
int RegisterTea(){      						 //��ʦע��
	char account[16],password[16],reginum[11];  //�˺ţ����룬ע������
	FILE *fp;
	int turn=1;                                 //���ڼ���˺��Ƿ���ע��Ŀ���
	char password_che[16];						//���ڼ����������������Ƿ�һ��
	char str1[16]={0},str2[16]={0};             //�����˺ţ���������
	printf("���������Ĺ��ţ�");
	scanf("%s",account);
	do{
		printf("���������룺");
		scanf("%s",password);
		printf("���ٴ��������룺");
		scanf("%s",password_che);
		if(strcmp(password,password_che))printf("���벻һ�£����������룡\n\n");
	}while(strcmp(password,password_che));
	printf("������ע�����룺");
	scanf("%s",reginum);
	if(strcmp(reginum,"2014052421")){
		printf("ע���������ע��ʧ�ܣ�\n");
		return 0;
	}else{
		if((fp=fopen("admintea.txt","a+"))==NULL){
			printf("ע��ʧ�ܣ�\n");
			return 0;
		}else{
			while(!feof(fp)){
				fscanf(fp,"%s%s",str1,str2);
				if(!strcmp(str1,account)){
					turn=0;
					break;
				}
			}
			if(turn){
				fseek(fp,0,2);
				fprintf(fp,"%s %s\n",account,password);
				fflush(fp);
				printf("ע��ɹ���\n");
				return 1;
			}else{
				printf("�˺���ע�ᣡ\n");
				return 0;
			}
		}
	}
	fclose(fp);
}
int RegisterStu(){								 //ѧ��ע��
	char account[16],password[16],reginum[11];  //�˺ţ����룬ע������
	FILE *fp;
	int turn=1;                                 //���ڼ���˺��Ƿ���ע��Ŀ���
	char password_che[16];						//���ڼ�����������Ƿ�������ȷ
	char str1[16]={0},str2[16]={0};             //�����˺ţ���������
	printf("����������ѧ�ţ�");
	scanf("%s",account);
	do{
		printf("���������룺");
		scanf("%s",password);
		printf("���ٴ��������룺");
		scanf("%s",password_che);
		if(strcmp(password,password_che))printf("���벻һ�£����������룡\n\n");
	}while(strcmp(password,password_che));
	printf("������ע�����룺");
	scanf("%s",reginum);
	if(strcmp(reginum,"2014052421")){
		printf("ע���������ע��ʧ�ܣ�\n");
		return 0;
	}else{
		if((fp=fopen("adminstu.txt","a+"))==NULL){
			printf("ע��ʧ�ܣ�\n");
			return 0;
		}else{
			while(!feof(fp)){
				fscanf(fp,"%s%s",str1,str2);
				if(!strcmp(str1,account)){
					turn=0;
					break;
				}
			}
			if(turn){
				fseek(fp,0,2);
				fprintf(fp,"%s %s\n",account,password);
				fflush(fp);
				printf("ע��ɹ���\n");
				return 1;
			}else{
				printf("�˺���ע�ᣡ\n");
				return 0;
			}
		}
	}
	fclose(fp);
}
int LoginTea(){									 //��ʦ��¼
	char account[16],password[16];       	    //�˺ţ�����
	char che_acc[16]={0},che_pas[16]={0};       //�����˺ţ���������
	FILE *fp;
	int turn=0;                                 //���ڼ����˺������Ƿ�ƥ��
	printf("���������Ĺ��ţ�");
	scanf("%s",account);
	printf("���������룺");
	scanf("%s",password);
	if((fp=fopen("admintea.txt","r"))==NULL){
		printf("��¼ʧ�ܣ�\n");
		return 0;
	}else{
		while(!feof(fp)){
			fscanf(fp,"%s%s",che_acc,che_pas);
			if(!strcmp(che_acc,account)&&!strcmp(che_pas,password)){
				turn=1;
				break;
			}
		}
		if(turn){
			printf("                                    ��¼�ɹ���\n");
			return 1;
		}else{
			printf("�˺Ż�������󣬵�¼ʧ�ܣ�\n");
			return 0;
		}
	}
	fclose(fp);
}
int LoginStu(){                                  //ѧ����¼
	char account[16],password[16];       	    //�˺ţ�����
	char che_acc[16]={0},che_pas[16]={0};       //�����˺ţ���������
	FILE *fp;
	int turn=0;                                 //���ڼ����˺������Ƿ�ƥ��
	printf("����������ѧ�ţ�");
	scanf("%s",account);
	printf("���������룺");
	scanf("%s",password);
	if((fp=fopen("adminstu.txt","r"))==NULL){
		printf("��¼ʧ�ܣ�\n");
		return 0;
	}else{
		while(!feof(fp)){
			fscanf(fp,"%s%s",che_acc,che_pas);
			if(!strcmp(che_acc,account)&&!strcmp(che_pas,password)){
				turn=1;
				break;
			}
		}
		if(turn){
			printf("                                    ��¼�ɹ���\n");
			return 1;
		}else{
			printf("�˺Ż�������󣬵�¼ʧ�ܣ�\n");
			return 0;
		}
	}
	fclose(fp);
}
int Count(STU *head){                            //����ѧ������(�ڵ����)
	int i;
	for(i=0;head!=NULL;i++,head=head->next);
	return i;
}
int StuNum(STU *p,double low,double high){ 		 //����ѧ����Ŀ��������������
	int i,n=0;
	for(i=0;i<5;i++){
		if(p->les[i].score>=low&&p->les[i].score<=high)n++;
	}
	return n;
}
void DisplayAll(STU *head){						 //��ӡ����ѧ����Ϣ
	int rank=1;
	int i,n;
	printf("\n");
	n=Count(head);
	if(n==0){
		printf("��������������������������������������������������������������������������������");
		printf("                                  ��ѧ����¼��                                  ");
		printf("��������������������������������������������������������������������������������");
	}else{
		printf("�����������Щ������� ������ ������ ������ ������ ������ �����Щ������Щ����Щ���");
		printf("   ѧ��   �� ���� ���γ�1���γ�2���γ�3���γ�4���γ�5���� �֩�ƽ���֩����㩦����");
		for(;head!=NULL;head=head->next){
			printf("%10d��%6s",head->num,head->name);
			for(i=0;i<5;i++)printf("��%5.1f",head->les[i].score);
			printf("��%5.1f��%6.1f��%4.1f��%3d ",head->all,head->average,head->mark,rank++);
		}
		printf("�����������ة������� ������ ������ ������ ������ ������ �����ة������ة����ة���");
		printf("����%d��ѧ��\n",n);
	}
}
void DisplayOne(STU *head,int n,char *name){     //��ӡһ��ѧ����ϸ��Ϣ
	STU *p;
	int i;
	if(n==0)p=Search_name(head,name);
	else p=Search_num(head,atoi(name));
	if(p==NULL){
		printf("                               û�и�ѧ������Ϣ��\n");
		return;
	}
	printf("%sͬѧ����ϸ��Ϣ��\n",p->name);
	printf("���������Щ������������Щ������Щ���������\n");
	printf("�� ѧ�� ��%12d�� ���� ��%7s ��\n",p->num,p->name);
	printf("���������੤�����������੤�����੤��������\n");
	printf("�� �༶ ��%12s�� �Ա� ��%7s ��\n",p->cla,p->sex);
	printf("���������੤�����������੤�����੤��������\n");
	for(i=0;i<5;i++){
		printf("�� �γ�%d��%12s�� ���� ��%7.1f ��\n",i+1,p->les[i].lesname,p->les[i].score);
		printf("���������੤�����������੤�����੤��������\n");
	}
	printf("�� �ܷ� ��%11.1f ��ƽ���֩�%7.1f ��\n",p->all,p->average);
	printf("���������੤�����������੤�����ة���������\n");
	printf("�� ���� ��%11.1f ��\n",p->mark);
	printf("���������ة�������������\n");
}
void DisplayCla(STU *head,char *class){			 //���༶��ʾѧ����Ϣ
	int rank=1;
	int i,n=0;
	STU *t=head;
	for(;head!=NULL;head=head->next){
		if(!strcmp(head->cla,class)){
			break;
		}
	}
	if(head!=NULL){
		head=t;
		printf("\n");
		printf("�����������Щ������� ������ ������ ������ ������ ������ �����Щ������Щ����Щ���");
		printf("   ѧ��   �� ���� ���γ�1���γ�2���γ�3���γ�4���γ�5���� �֩�ƽ���֩����㩦����");
		for(;head!=NULL;head=head->next){
			if(!strcmp(head->cla,class)){
				printf("%10d��%6s",head->num,head->name);
				for(i=0;i<5;i++)printf("��%5.1f",head->les[i].score);
				printf("��%5.1f��%6.1f��%4.1f��%3d ",head->all,head->average,head->mark,rank++);
				n++;
			}
		}
		printf("�����������ة������� ������ ������ ������ ������ ������ �����ة������ة����ة���");
		printf("����%d�� %s �༶��ѧ��\n",n,class);
	}else{
		printf("\n");
		printf("��������������������������������������������������������������������������������");
		printf("                           �� %s �༶��ѧ����                            \n",class);
		printf("��������������������������������������������������������������������������������");
	}
}
void DisplayGrade(STU *head,double low,double high){ //�������β�ѯ�ɼ�
	int i;
	int n;
	int t=0;
	for(;head!=NULL;head=head->next){
		n=StuNum(head,low,high);
		if(n!=0){
			t=1;
			printf("���������Щ������������Щ������Щ���������\n");
			printf("�� ѧ�� ��%12d�� ���� ��%7s ��\n",head->num,head->name);
			printf("���������੤�����������੤�����੤��������\n");
			printf("�� �༶ ��%12s�� �Ա� ��%7s ��\n",head->cla,head->sex);
			for(i=0;i<5;i++){
				if(head->les[i].score>=low&&head->les[i].score<=high){
					printf("���������੤�����������੤�����੤��������\n");
					printf("�� �γ�%d��%12s�� ���� ��%7.1f ��\n",i+1,head->les[i].lesname,head->les[i].score);
				}
			}
			printf("���������ة������������ة������ة���������\n");
		}
	}
	if(t==0)printf("                              û��%.0f��%.0f�ֵĳɼ���\n",low,high);
}
void DisplayFail(STU *head){					 //�������Ŀ��ѯ
	int i;
	int n;
	int t=0;
	for(;head!=NULL;head=head->next){
		n=StuNum(head,0,59);
		if(n!=0){
			t=1;
			printf("���������Щ������������Щ������Щ���������\n");
			printf("�� ѧ�� ��%12d�� ���� ��%7s ��\n",head->num,head->name);
			printf("���������੤�����������੤�����੤��������\n");
			printf("�� �༶ ��%12s�� �Ա� ��%7s ��\n",head->cla,head->sex);
			for(i=0;i<5;i++){
				if(head->les[i].score<60){
					printf("���������੤�����������੤�����੤��������\n");
					printf("�� �γ�%d��%12s�� ���� ��%7.1f ��\n",i+1,head->les[i].lesname,head->les[i].score);
				}
			}
			printf("���������ة������������ة������ة���������\n");
		}
	}
	if(t==0)printf("\n                                û�в�����ѧ����\n");
}
STU *Delete(STU *head,int n,char *name,int *item){   //ɾ��ѧ���ɼ�
	STU *p,*t;
	if(n==0)p=Search_name(head,name);
	else p=Search_num(head,atoi(name));
	if(p==NULL){
		*item=0;
		return head;
	}
	else{
		if(p==head)head=head->next;
		else{
			for(t=head;t->next!=p;t=t->next);
			t->next=p->next;
		}
		*item=1;
		free(p);
		p=NULL;
		return head;
	}
}
int Modify(STU *head,int n,char *name){			 //�޸�ѧ���ɼ�
	STU *p;
	int i;
	double Mark(STU *p);
	if(n==0)p=Search_name(head,name);
	else p=Search_num(head,atoi(name));
	if(p==NULL){
		return 0;
	}else{
		printf("������ѧ�ţ�");
	    scanf("%d",&p->num);
		printf("������������");
	    scanf("%s",p->name);
	    printf("������༶��");
	    scanf("%s",p->cla);
	    printf("�������Ա�");
	    scanf("%s",p->sex);
	    p->all=0;
	    for(i=0;i<5;i++){
	    	printf("�������%d�ſγ̵ı�ţ�",i+1);
	    	scanf("%d",&p->les[i].lesnumber);
	    	printf("�������%d�ſγ̵����ƣ�",i+1);
	    	scanf("%s",p->les[i].lesname);
	    	printf("�������%d�ſγ̵�ѧ�֣�",i+1);
	    	scanf("%lf",&p->les[i].point);
	    	printf("�������%d�ſγ̵ĳɼ���",i+1);
	    	scanf("%lf",&p->les[i].score);
	    	p->all+=p->les[i].score;
	    }
	    p->average=p->all/5;
	    p->mark=Mark(p);
	    return 1;
	}
}
STU *Search_name(STU *head,char *name){		     //ͨ����������ѧ��
	for(;head!=NULL;head=head->next){
		if(!strcmp(head->name,name))return head;
	}
	return NULL;
}
STU *Search_num(STU *head,int num){		   		 //ͨ��ѧ������ѧ��
	for(;head!=NULL;head=head->next){
		if(num==head->num)return head;
	}
	return NULL;
}
int Save(STU *head){							 //����ѧ���ɼ�
	FILE *fp;
	int i;
	if((fp=fopen("studata.txt","w"))==NULL){
		return 0;
	}else{
		for(;head!=NULL;head=head->next){
			fprintf(fp,"%d %s %s %s ",head->num,head->name,head->sex,head->cla);
			for(i=0;i<5;i++){
				fprintf(fp,"%d %s %.1f ",head->les[i].lesnumber,head->les[i].lesname,head->les[i].point);
				fprintf(fp,"%.1f ",head->les[i].score);
			}
			fprintf(fp,"%.1f %.1f %.1f\n",head->all,head->average,head->mark);
		}
		fclose(fp);
		return 1;
	}
}
int Lof(FILE *fp){								 //�����ļ���ѧ������
	char str[201];
	int n;
	for(n=0;fgets(str,201,fp)!=NULL;n++);
	rewind(fp);
	return n;
}
STU *Initialize(){								 //��ʼ����ȡ�ļ��е�ѧ��
	FILE *fp;
	STU *head=NULL;
	STU *p=NULL;
	int i,n,line;
	if((fp=fopen("studata.txt","r"))==NULL)return NULL;
	else{
		char str[11]={0};
		fgets(str,11,fp);
		if(!strcmp(str,""))return NULL;
	}
	rewind(fp);
	line=Lof(fp);
	head=p=Creat(line);
	for(n=1;n<=line;n++,p=p->next){
		fscanf(fp,"%d%s%s%s",&p->num,p->name,p->sex,p->cla);
		for(i=0;i<5;i++)fscanf(fp,"%d%s%lf%lf",&p->les[i].lesnumber,p->les[i].lesname,&p->les[i].point,&p->les[i].score);
		fscanf(fp,"%lf%lf%lf",&p->all,&p->average,&p->mark);
	}
	head=Sort(head,ALL,FROMBIG);
	fclose(fp);
	return head;
}
int Position(STU *head,STU *p){					 //ȷ���ڵ��������λ��
	int n;
	for(n=0;head!=p;head=head->next,n++);
	return n;
}
STU *SetPosition(STU *head,int n){				 //�������ƶ���ָ���ڵ�
	int i;
	for(i=0;i<n;i++,head=head->next);
	return head;
}
/*���뷨�����ı�ڵ����ݣ������ڵ�ָ�����������*/
STU *Sort(STU *head,int m,int n){                //�ɼ�����
	STU *p,*p0,*t,*t0;
	int p_pos,p0_pos,t_pos,t0_pos;
	int turn;
	for(p0=head,p=head->next;p!=NULL;p0=p0->next,p=p->next){
		p_pos=Position(head,p);
		p0_pos=Position(head,p0);
		for(t=head,t0=head;t!=p;t=t->next){
			t_pos=Position(head,t);
			t0_pos=Position(head,t0);
			turn=0;
			if(n==0){
				switch(m){
					case 0:if(strcmp(p->name,t->name)>0)turn=1;break;
					case 1:if(p->num>t->num)turn=1;break;
					case 2:if(p->all>t->all)turn=1;break;
					case 3:if(p->mark>t->mark)turn=1;break;
					case 4:if(p->les[0].score>t->les[0].score)turn=1;break;
					case 5:if(p->les[1].score>t->les[1].score)turn=1;break;
					case 6:if(p->les[2].score>t->les[2].score)turn=1;break;
					case 7:if(p->les[3].score>t->les[3].score)turn=1;break;
					case 8:if(p->les[4].score>t->les[4].score)turn=1;break;
				}
				if(turn==1){
					p0->next=p->next;
					p->next=t;
					if(t==head)head=p;
					else t0->next=p;
					p=p0;
				}
			}else{
				switch(m){
					case 0:if(strcmp(p->name,t->name)<0)turn=1;break;
					case 1:if(p->num<t->num)turn=1;break;
					case 2:if(p->all<t->all)turn=1;break;
					case 3:if(p->mark<t->mark)turn=1;break;
					case 4:if(p->les[0].score<t->les[0].score)turn=1;break;
					case 5:if(p->les[1].score<t->les[1].score)turn=1;break;
					case 6:if(p->les[2].score<t->les[2].score)turn=1;break;
					case 7:if(p->les[3].score<t->les[3].score)turn=1;break;
					case 8:if(p->les[4].score<t->les[4].score)turn=1;break;
				}
				if(turn==1){
					p0->next=p->next;
					p->next=t;
					if(t==head)head=p;
					else t0->next=p;
					p=p0;
				}
			}
			p=SetPosition(head,p_pos);
			p0=SetPosition(head,p0_pos);
			t=SetPosition(head,t_pos);
			t0=SetPosition(head,t0_pos);
			if(t!=head)t0=t0->next;
		}
	}
	return head;
}
STU *Creat(int n){                  			 //��������
	STU *pf,*head,*pb;
	int i;
	for(i=0;i<n;i++){
		pb=(STU *)malloc(sizeof(STU));
		if(i==0)pf=head=pb;
		else pf->next=pb;
		pf=pb;
	}
	pb->next=NULL;
	return head;
}
STU *Connect(STU *head,STU *end){                //������������
	STU *p=head;
	for(;head->next!=NULL;head=head->next);
	head->next=end;
	return p;
}
double Mark(STU *p){							 //���㼨��
	double mark_all=0;
	double mark=0;
	double point_all=0;
	int i;
    for(i=0;i<5;i++){
    	mark=(p->les[i].score-50)/10.0*p->les[i].point;
    	point_all+=p->les[i].point;
    	mark_all+=mark;
    }
    mark_all/=point_all;
    return mark_all;
}
STU *Input(){              			 			 //����ѧ���ɼ�
	STU *head;
	int i;
	head=Creat(1);
	printf("������ѧ��(����0����¼��)��");
    scanf("%d",&head->num);
    if(head->num==0){
    	free(head);
    	head=NULL;
    	return NULL;
    }
    printf("������������");
    scanf("%s",head->name);
    printf("������༶��");
    scanf("%s",head->cla);
    printf("�������Ա�");
    scanf("%s",head->sex);
    head->all=0;
    for(i=0;i<5;i++){
	    printf("�������%d�ſγ̵ı�ţ�",i+1);
    	scanf("%d",&head->les[i].lesnumber);
    	printf("�������%d�ſγ̵����ƣ�",i+1);
    	scanf("%s",head->les[i].lesname);
    	printf("�������%d�ſγ̵�ѧ�֣�",i+1);
    	scanf("%lf",&head->les[i].point);
    	printf("�������%d�ſγ̵ĳɼ���",i+1);
    	scanf("%lf",&head->les[i].score);
    	head->all+=head->les[i].score;
    }
    head->average=head->all/5;
    head->mark=Mark(head);
	return head;
}
void HideCursor(){								 //���ع��
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void PutCursor(){								 //��ʾ���
	CONSOLE_CURSOR_INFO cursor_info={1,1};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void GotoXy(int x,int y){						 //������ƶ���(X,Y)
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void GetXy(int *X,int *Y,int x1,int x2,int y1,int y2){ //��ȡ���޶���Χ�������������
	HANDLE hInput;                              //��ȡ��׼�����豸���
    INPUT_RECORD inRec;                         //�������ݼ�¼
    DWORD res;                                  //�����Ѷ�ȡ�ļ�¼��
    int x=-1,y=-1;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	do{
		ReadConsoleInput(hInput, &inRec, 1, &res);
		if(inRec.EventType==MOUSE_EVENT&&inRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
			x=(int)inRec.Event.MouseEvent.dwMousePosition.X;
			y=(int)inRec.Event.MouseEvent.dwMousePosition.Y;
		}
	}while(!(x>=x1&&x<=x2&&y>=y1&&y<=y2));
	*X=x;
	*Y=y;
}
void Clear(int x,int y,int line){				 //���line�е����ݺ����귵��(x,y)
	int i;
	for(i=0;i<line*80-1;printf(" "),i++);
	GotoXy(x,y);
}
int main(){
    int X=0,Y=0;								//����������������(X,Y)
    int turn=0;									//�����Ƿ��¼��ע��ɹ��Ŀ���
    int admin=0;								//�����û����Խ�ʦ��ѧ����ݵ�¼�Ŀ���
    HideCursor();
    PrintLogin();
    while(1){
    	if(admin==0){
			while(1){									//��¼����Ĳ���
				GetXy(&X,&Y,38,45,4,8);
				PutCursor();
				turn=0;
				switch(Y){
					case 4:turn=RegisterTea();break;
					case 5:turn=LoginTea();break;
					case 6:turn=RegisterStu();break;
					case 7:turn=LoginStu();break;
					case 8:GotoXy(28,11);return 0;
				}
				HideCursor();
				if(turn==1&&(Y==5||Y==7)){
						if(Y==5)admin=1;
						if(Y==7)admin=2;
						printf("                             (���������������˵�)");
						getch();
						break;
				}else{
					GotoXy(33,11);
					printf("��������ϣ����");
					GotoXy(15,12);
					printf("        1.���ص�¼�˵�     2.�˳�����ϵͳ");
					do{
						GetXy(&X,&Y,25,55,12,12);
					}while(X>=37&&X<=44);
					if(X>=25&&X<=36){
						GotoXy(0,10);
						Clear(0,10,10);
					}else{
						GotoXy(28,11);
						return 0;
					}
				}
			}
		}else if(admin==1){
			int ismodify=0;
			STU *head=Initialize();
			GotoXy(0,0);
			PrintMenuTea();
			Clear(0,10,8);
			while(1){
				do{
					GetXy(&X,&Y,28,55,4,8);
				}while((X>=36&&X<=47)||(Y==8&&X>=48&&X<=55));
				if(Y==4){
					if(X/10==2||X/10==3){
						STU *p=NULL;
						int t=Count(head);
						int item=t;
						PutCursor();
						do{
							if(p!=NULL){
								GotoXy(0,10);
								Clear(0,10,24);
							}
							p=Input();
							if(t==0){
								head=p;
								t=Count(head);
							}else Connect(head,p);
						}while(p!=NULL);
						HideCursor();
						if(t!=item){
							ismodify=1;
							GotoXy(25,20);
							printf("      ѧ����Ϣ¼��ɹ���");
							GotoXy(25,21);
							printf("    (����������ز����˵�)");

						}else{
							printf("                               ѧ����Ϣ¼��ʧ�ܣ�\n");
							printf("                             (����������ز����˵�)");
						}
						getch();
						GotoXy(0,0);
						PrintMenuTea();
						Clear(0,10,14);
					}else{
						char number[11];
						int t;
						GotoXy(27,11);
						printf("��ѡ��ͨ��ѧ�Ż������޸���Ϣ��");
						GotoXy(27,12);
						printf("    1.ѧ��        2.����\n");
						do{
							GetXy(&X,&Y,33,50,12,12);
						}while(X>=37&&X<=46);
						PutCursor();;
						if(X>=33&&X<=36){
							printf("������ѧ�ţ�");
							scanf("%s",number);
							t=Modify(head,NUMBER,number);
						}else{
							printf("������������");
							scanf("%s",number);
							t=Modify(head,NAME,number);
						}
						HideCursor();
						if(t==0){
							printf("                         �Ҳ�����ѧ������Ϣ���޷��޸ģ�\n");
							printf("                             (����������ز����˵�)");					
						}
						else{
							ismodify=1;
							GotoXy(25,23);
							printf("      ѧ����Ϣ�޸ĳɹ���");
							GotoXy(25,24);
							printf("    (����������ز����˵�)");
						}
						getch();
						GotoXy(0,0);
						PrintMenuTea();
						Clear(0,10,14);	
					}
				}else if(Y==5){
					char number[11];
					int t=0;
					if(X/10==2||X/10==3){
						GotoXy(27,11);
						printf("��ѡ��ͨ��ѧ�Ż�����ɾ��ѧ����");
						GotoXy(27,12);
						printf("    1.ѧ��        2.����\n");
						do{
							GetXy(&X,&Y,33,50,12,12);
						}while(X>=37&&X<=46);
						PutCursor();;
						if(X>=33&&X<=36){
							printf("������ѧ�ţ�");
							scanf("%s",number);
							head=Delete(head,NUMBER,number,&t);
						}else{
							printf("������������");
							scanf("%s",number);
							head=Delete(head,NAME,number,&t);
						}
						HideCursor();
						if(t==0){
							printf("                         �Ҳ�����ѧ������Ϣ���޷�ɾ����\n");
							printf("                             (����������ز����˵�)");					
						}
						else{
							ismodify=1;
							printf("                               ��ѧ����Ϣ��ɾ����\n");
							printf("                             (����������ز����˵�)");
						}
						getch();
						GotoXy(0,0);
						PrintMenuTea();
						Clear(0,10,14);	
					}else{
						GotoXy(32,11);
						printf("��ѡ���ѯ��ʽ��");
						GotoXy(16,12);
						printf("1.��ѯ���˳ɼ�  2.�������β�ѯ  3.��ѯ������ѧ��\n");
						do{
							GetXy(&X,&Y,18,63,12,12);
						}while(X==30||X==31||X==46||X==47);
						if(X/10==1||X/10==2){
							GotoXy(27,14);
							printf("��ѡ��ͨ��ѧ�Ż�������ѯѧ����");
							GotoXy(27,15);
							printf("    1.ѧ��        2.����\n");
							do{
								GetXy(&X,&Y,33,50,15,15);
							}while(X>=37&&X<=46);
							PutCursor();;
							if(X>=33&&X<=36){
								printf("������ѧ�ţ�");
								scanf("%s",number);
								DisplayOne(head,NUMBER,number);
							}else{
								printf("������������");
								scanf("%s",number);
								DisplayOne(head,NAME,number);
							}
							HideCursor();
						}else if(X/10==3||X/10==4){
							double low,high;
							PutCursor();
							printf("������������ޣ�");
							scanf("%lf",&low);
							printf("������������ޣ�");
							scanf("%lf",&high);
							HideCursor();
							DisplayGrade(head,low,high);
						}else{
							DisplayFail(head);
						}
						printf("                             (����������ز����˵�)");
						getch();
						GotoXy(0,0);
						PrintMenuTea();
						Clear(0,10,14);
					}
				}else if(Y==6){
					if(X/10==2||X/10==3){
						int m,n;
						PrintMenuSort();
						do{
							GetXy(&X,&Y,28,54,14,18);
						}while((X>=35&&X<=47)||(Y==18&&X>=48&&X<=54));
						if(X>=28&&X<=34){
							switch(Y){
								case 14:m=NUMBER;break;
								case 15:m=ALL;break;
								case 16:m=COU1;break;
								case 17:m=COU3;break;
								case 18:m=COU5;break;
							}
						}else{
							switch(Y){
								case 14:m=NAME;break;
								case 15:m=MARK;break;
								case 16:m=COU2;break;
								case 17:m=COU4;break;
							}
						}
						PrintMenuSort2();
						do{
							GetXy(&X,&Y,28,55,24,24);
						}while(X>=36&&X<=47);
						switch(X/10){
							case 2:
							case 3:n=FROMSMALL;break;
							case 4:
							case 5:n=FROMBIG;break;
						}
						if(head){
							head=Sort(head,m,n);
							ismodify=1;
							printf("                    ѧ����Ϣ������ϣ��Ƿ��ӡ����ѧ����Ϣ��\n");
							printf("                                  ��(Y)  ��(N)\n");
							do{
								GetXy(&X,&Y,34,45,27,27);
							}while(X==39||X==40);
							if(X>=34&&X<=38){
								DisplayAll(head);
								printf("                             (����������ز����˵�)");
								getch();
							}
						}else{
							printf("��������������������������������������������������������������������������������");
							printf("                                  ��ѧ����¼��                                  ");
							printf("��������������������������������������������������������������������������������");
							printf("                             (����������ز����˵�)");
							getch();
						}
						GotoXy(0,0);
						PrintMenuTea();
						Clear(0,10,14);
					}else{
						GotoXy(32,11);
						printf("��ѡ����ʾ��ʽ��");
						GotoXy(27,12);
						printf("1.��ʾ����      2.������ʾ\n");
						do{
							GetXy(&X,&Y,29,52,12,12);
						}while(X>=37&&X<=44);
						if(X>=29&&X<=36){
							DisplayAll(head);
						}else{
							char cla[11];
							PutCursor();
							printf("������༶����:");
							scanf("%s",cla);
							HideCursor();
							DisplayCla(head,cla);
						}
						printf("                             (����������ز����˵�)");
						getch();
						GotoXy(0,0);
						PrintMenuTea();
						Clear(0,10,14);
					}
				}else if(Y==7){
					if(X/10==2||X/10==3){
						int t;
						t=Save(head);
						if(t==1){
							ismodify=0;
							printf("\n                               ѧ����Ϣ����ɹ���\n");
						}else{
							printf("\n                               ѧ����Ϣ����ʧ�ܣ�\n");
						}
						printf("                             (����������ز����˵�)");
						getch();
						GotoXy(0,0);
						PrintMenuTea();
						Clear(0,10,14);
					}else{
						admin=0;
						if(ismodify==1){
							GotoXy(0,11);
							printf("                  ���Ѷ�ѧ����Ϣ�����޸ģ������Ƿ񱣴���˳���\n");
							printf("                                  ��(Y)  ��(N)\n");
							do{
								GetXy(&X,&Y,34,45,12,12);
							}while(X==39||X==40);
							if(X>=34&&X<=38)Save(head);
						}
						GotoXy(0,11);
						Clear(0,11,2);
						printf("                             (����������ص�¼�˵�)");
						getch();
						GotoXy(0,0);
						Clear(0,0,20);
						PrintLogin();
						break;
					}
				}else{
					if(ismodify==1){
						GotoXy(0,11);
						printf("                  ���Ѷ�ѧ����Ϣ�����޸ģ������Ƿ񱣴���˳���\n");
						printf("                                  ��(Y)  ��(N)\n");
						do{
							GetXy(&X,&Y,34,45,12,12);
						}while(X==39||X==40);
						if(X>=34&&X<=38)Save(head);
					}
					GotoXy(0,11);
					Clear(28,11,2);
					return 0;
				}
			}
		}else if(admin==2){
			STU *head=Initialize();
			GotoXy(0,0);
			PrintMenuStu();
			Clear(0,10,8);
			while(1){
				do{
					GetXy(&X,&Y,28,55,4,5);
				}while((X>=36&&X<=47)||(Y==5&&X>=48&&X<=55));
				if(Y==4){
					if(X/10==2||X/10==3){
						char number[11];
						GotoXy(27,8);
						printf("��ѡ��ͨ��ѧ�Ż�������ѯѧ����");
						GotoXy(27,9);
						printf("    1.ѧ��        2.����\n");
						do{
							GetXy(&X,&Y,33,50,9,9);
						}while(X>=37&&X<=46);
						PutCursor();;
						if(X>=33&&X<=36){
							printf("������ѧ�ţ�");
							scanf("%s",number);
							DisplayOne(head,NUMBER,number);
						}else{
							printf("������������");
							scanf("%s",number);
							DisplayOne(head,NAME,number);
						}
						HideCursor();
						printf("                             (����������ز����˵�)");
						getch();
						GotoXy(0,0);
						PrintMenuStu();
						Clear(0,10,17);
					}else{
						admin=0;
						GotoXy(0,11);
						printf("                             (����������ص�¼�˵�)");
						getch();
						GotoXy(0,0);
						Clear(0,0,20);
						PrintLogin();
						break;
					}
				}
				else{
					GotoXy(0,11);
					Clear(28,11,2);
					return 0;
				}
			}
		}
	}
	return 0;
}