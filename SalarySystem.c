#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>
int number;
//int t_salary[100],deduction_count[100],r_salary[100]; //Ӧ�����ʣ��ۿ�ϼƣ�ʵ�����ʡ�
struct staff{
		char uid[3];	//ְ������ 
		int salary;	//��λ���� 
		int csalary;	//н������ 
		int revenue; //�������� 
		int _water_electricity; //ˮ���
		int _deductions; //�����ۿ�
		int t_salary;  	 //Ӧ������
		int deduction_count; //�ۿ�ϼ�
		int r_salary; //ʵ������
}infor[100],temp;
VOID HideConsoleCursor() {
 CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), 
                      &cursor_info);
}
void welcome()
{
printf("\n\n\n\n\n\n");				//��ӭ���棬������������� 
printf("\t\t~****************��ӭ���빤�ʴ���ϵͳ***************~\n");
printf("\n\n\n");
printf("\t\t~*************������:203��16�ų���******************~\n");
printf("\n\n\n");
printf("\t\t~*************��������������˵�********************~\n\n\n\n\t\t\t\t");
system("pause");	//����������� 
}
void title(LPCSTR lpTitle) 			//�޸Ĵ��ڱ��⣬����ʹ����һ���ַ��������� 
{
 SetConsoleTitle(lpTitle);
}
void login()					//��¼���� 
{
	system("cls");	  //�������� 
	char password[12]; //�������
	char acount[8];	  //�˻��� 
	char inputacount[8]; //�û������˻��� 
	char confirm[12];  //ȷ������
	char inputpass[12]; //�û��������� 
	int tryagain=3; 
	int i,c;
	while(1)
	{
		system("cls");
		printf("\t\t    --------------�����˻�---------------\n");
		printf("\n�������˻�����");	
		scanf("%s",acount);			
		printf("\n���������룺");
		for(i=0;i<11&&c!=13;)
	{
		c=getch();
		password[i++]=c;
		if(c!=13)
			putchar('*'); 
	}
	password[i]='\0';
//		scanf("%s",password);
		printf("\n\n���ٴ��������룺");
//		scanf("%s",confirm);
	for(i=0;i<11&&c!=13;)
	{
		c=getch();
		confirm[i++]=c;
		if(c!=13)
			putchar('*'); 
	}
	password[i]='\0';
		if(strcmp(password,confirm)==0)
		{
			printf("\n\n��ϲ�������봴���ɹ���������ת����¼���棡\n\n\t\t\t");
			Sleep(3000);
			break; 
		}
		else
		{
			printf("\n\n�������벻ƥ�䣬��3����������룡����");
			Sleep(3000);
			continue;
		}
	}
	system("cls");
		printf("\t\t    --------------��¼ϵͳ---------------\n");
	while(1)
	{
	if(tryagain==0)
	{
	printf("������֤ʧ�ܣ���������˳�����");
	exit(0); 
	}
	printf("�������˻�����");
	scanf("%s",inputacount);
	if(strcmp(inputacount,acount)==0)
	{
		printf("\n�˻���֤�ɹ���\n");
	}
	else
	{
		printf("\n�˻���������򲻴��ڣ�����������\n");
		continue;
	}	
	printf("\n���������룺");
//	scanf("%s",inputpass);
	for(i=0;i<11&&c!=13;)
	{
		c=getch();
		inputpass[i++]=c;
		if(c!=13)
			putchar('*'); 
	}
	password[i]='\0';
	if(strcmp(password,inputpass)==0)
	{
		printf("\n������֤�ɹ���������½ϵͳ\n");
		break;
	}
	else
	{
		printf("\n������֤ʧ�ܣ�����������\n\n");
		printf("ʣ���������%d��\n",--tryagain);
		continue;
	}
	}

}
void input_data()
{
	int i;
	int count=1;
	system("cls");	  //�������� 
	printf("��������Ҫ¼���Ա��������");
	scanf("%d",&number);
		printf("\nע���밴������˳�����룬���ݼ��Կո�����Ա�����Իس����!\n");
		printf("\n���� ��λ���� н������ �������� ˮ��� �����ۿ� Ӧ������ �ۿ�ϼ� ʵ������\n");
	for(i=0;i<number;i++)
	{
		printf("\n�������%dλԱ����Ϣ��",count++); 
		scanf("%s %d %d %d %d %d",infor[i].uid,&infor[i].salary,&infor[i].csalary,&infor[i].revenue,&infor[i]._water_electricity,&infor[i]._deductions);
	}
	printf("\n����:��λ����:н������:��������:ˮ���:�����ۿ�:\n");
	for(i=0;i<number;i++)
	{
		printf("%s   %d     %d       %d      %d      %d\n",infor[i].uid,infor[i].salary,infor[i].csalary,infor[i].revenue,infor[i]._water_electricity,infor[i]._deductions);
		printf("\n"); 
	}
	printf("\n��ϲ����ȫ����Ϣ¼����ɣ���������������˵���\n\n");
	system("pause");
	menu();		 
}
void calculate()  //ͳ��Ա������
{
	int i;
	system("cls");	  //�������� 
	printf("\n����:��λ����:н������:��������:ˮ���:�����ۿ�:Ӧ������:�ۿ�ϼ�:ʵ������:\n");
	for(i=0;i<number;i++)
	{
		infor[i].t_salary=infor[i].salary+infor[i].csalary+infor[i].revenue;
		infor[i].deduction_count=infor[i]._water_electricity+infor[i]._deductions;
		infor[i].r_salary=infor[i].t_salary-infor[i].deduction_count;
		printf("%s   %d     %d       %d      %d      %d      %d     %d     %d\n",infor[i].uid,infor[i].salary,infor[i].csalary,infor[i].revenue,infor[i]._water_electricity,infor[i]._deductions,infor[i].t_salary,infor[i].deduction_count,infor[i].r_salary);
		printf("\n"); 
	}
	system("pause");
	menu();	 
}
void sort()
{
	int i,j;
	system("cls");	  //�������� 
	for(i=0;i<number-1;i++)
	{
		for(j=i+1;j<number;j++)
		{
			if(infor[i].t_salary>infor[j].t_salary)
			{
				temp=infor[i];
				infor[i]=infor[j];
				infor[j]=temp;
			}
		}
	}
	printf("\n����:��λ����:н������:��������:ˮ���:�����ۿ�:Ӧ������:�ۿ�ϼ�:ʵ������:\n");
	for(i=0;i<number;i++)
	{
		printf("%s   %d     %d       %d      %d      %d      %d     %d     %d\n",infor[i].uid,infor[i].salary,infor[i].csalary,infor[i].revenue,infor[i]._water_electricity,infor[i]._deductions,infor[i].t_salary,infor[i].deduction_count,infor[i].r_salary);
		printf("\n");
	}
	system("pause");
	menu();	 
}
void search()
{
	int i;
	char input[3];
	system("cls");	  //�������� 
	printf("������Ա�����ţ�"); 
	scanf("%s",input);
	printf("\n����:��λ����:н������:��������:ˮ���:�����ۿ�:Ӧ������:�ۿ�ϼ�:ʵ������:\n"); 
	for(i=0;i<number;i++)
	{
		if(strcmp(infor[i].uid,input)==0)
		{
		printf("%s   %d     %d       %d      %d      %d      %d     %d     %d\n",infor[i].uid,infor[i].salary,infor[i].csalary,infor[i].revenue,infor[i]._water_electricity,infor[i]._deductions,infor[i].t_salary,infor[i].deduction_count,infor[i].r_salary);
		}
	}
	system("pause");
	menu();	 
}
void add()
{
	int newnum=0;
	int i,count=1;
	system("cls");	  //�������� 
	printf("����������������");
	scanf("%d",&newnum);
	for(i=number;i<number+newnum;i++)
	{
		printf("\n");
		printf("������������%dλԱ����Ϣ��",count++);
		scanf("%s %d %d %d %d %d",infor[i].uid,&infor[i].salary,&infor[i].csalary,&infor[i].revenue,&infor[i]._water_electricity,&infor[i]._deductions);
	}
	printf("\n������Ա�ɹ�!\n"); 
	number=number+newnum;
	system("pause");
	menu();	
} 
void delete()
{
	int i;
	char dropnum[3];
	system("cls");	  //�������� 
	printf("������Ҫɾ����Ա�����ţ�");
	scanf("%s",dropnum);
	for(i=0;i<number;i++)
	{
		if(strcmp(infor[i].uid,dropnum)==0)
		{
			while(i<number)
			{
				infor[i]=infor[i+1];
				i++;
			}
		}
	}
	number--; 
	printf("\nԱ��ɾ���ɹ�\n");
	system("pause");
	menu(); 
	
} 
void menu()		//���ܲ˵�ѡ���� 
{
	int choice;
	int tryagain=0;
	system("cls");
	printf(
		"\n\t|_________________��ӭ���빤�ʴ���ϵͳ____________________|\t\n"
		"\t|1:¼��Ա����Ϣ                                           |\t\n"
		"\t|2:ͳ��Ա������                                           |\t\n"
		"\t|3:Ա����������                                           |\t\n"
		"\t|4:��ѯԱ������                                           |\t\n"
		"\t|5:����Ա������                                           |\t\n"
		"\t|6:ɾ��Ա������                                           |\t\n"
		"\t|0:�˳�����                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
	printf("����������Ҫ�Ĺ��ܱ�ţ�");
	do
	{
		if(tryagain>=1)
		{
			printf("����������������ȷ���룺");
		}
		scanf("%d",&choice);	
		printf("\n");
		tryagain++; 
	}while(choice<0||choice>6);
	switch(choice)
	{
		case 0: printf("\n�´��ټ���\n");exit(0);
		case 1: input_data(); break;
		case 2: calculate(); break;
		case 3: sort(); break;
		case 4:	search(); break;
		case 5: add(); break;
		case 6: delete(); break;		
	} 
	
}
int main()
{
	system("color F0");			//ϵͳ������������ɫ/������ɫ�� 
	system("mode con cols=80 lines=30");	//����̨���峤����ơ�
	title("���ʴ���ϵͳ");					//�޸Ŀ���̨���⡣
	HideConsoleCursor();					//���ؿ���̨��˸�Ĺ�� 
	welcome();		//��ӭ���档 
	login();		//��¼���档
	menu(); 		//���ܲ˵�ѡ������ 
	return 0; 
}
