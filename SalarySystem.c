#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>
int number;
//int t_salary[100],deduction_count[100],r_salary[100]; //应发工资，扣款合计，实发工资。
struct staff{
		char uid[3];	//职工代号 
		int salary;	//岗位工资 
		int csalary;	//薪级工资 
		int revenue; //其他补贴 
		int _water_electricity; //水电费
		int _deductions; //其他扣款
		int t_salary;  	 //应发工资
		int deduction_count; //扣款合计
		int r_salary; //实发工资
}infor[100],temp;
VOID HideConsoleCursor() {
 CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), 
                      &cursor_info);
}
void welcome()
{
printf("\n\n\n\n\n\n");				//欢迎界面，按任意键继续。 
printf("\t\t~****************欢迎进入工资处理系统***************~\n");
printf("\n\n\n");
printf("\t\t~*************制作者:203班16号迟鑫******************~\n");
printf("\n\n\n");
printf("\t\t~*************按任意键进入主菜单********************~\n\n\n\n\t\t\t\t");
system("pause");	//按任意键继续 
}
void title(LPCSTR lpTitle) 			//修改窗口标题，调用使传入一个字符串常量。 
{
 SetConsoleTitle(lpTitle);
}
void login()					//登录函数 
{
	system("cls");	  //清屏函数 
	char password[12]; //存放密码
	char acount[8];	  //账户名 
	char inputacount[8]; //用户输入账户名 
	char confirm[12];  //确认密码
	char inputpass[12]; //用户输入密码 
	int tryagain=3; 
	int i,c;
	while(1)
	{
		system("cls");
		printf("\t\t    --------------创建账户---------------\n");
		printf("\n请输入账户名：");	
		scanf("%s",acount);			
		printf("\n请输入密码：");
		for(i=0;i<11&&c!=13;)
	{
		c=getch();
		password[i++]=c;
		if(c!=13)
			putchar('*'); 
	}
	password[i]='\0';
//		scanf("%s",password);
		printf("\n\n请再次输入密码：");
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
			printf("\n\n恭喜您！密码创建成功，即将跳转至登录界面！\n\n\t\t\t");
			Sleep(3000);
			break; 
		}
		else
		{
			printf("\n\n两次密码不匹配，请3秒后重新输入！！！");
			Sleep(3000);
			continue;
		}
	}
	system("cls");
		printf("\t\t    --------------登录系统---------------\n");
	while(1)
	{
	if(tryagain==0)
	{
	printf("密码验证失败，按任意键退出程序");
	exit(0); 
	}
	printf("请输入账户名：");
	scanf("%s",inputacount);
	if(strcmp(inputacount,acount)==0)
	{
		printf("\n账户验证成功！\n");
	}
	else
	{
		printf("\n账户名称有误或不存在，请重新输入\n");
		continue;
	}	
	printf("\n请输入密码：");
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
		printf("\n密码验证成功，即将登陆系统\n");
		break;
	}
	else
	{
		printf("\n密码验证失败，请重新输入\n\n");
		printf("剩余输入次数%d次\n",--tryagain);
		continue;
	}
	}

}
void input_data()
{
	int i;
	int count=1;
	system("cls");	  //清屏函数 
	printf("请输入需要录入的员工人数：");
	scanf("%d",&number);
		printf("\n注：请按照如下顺序输入，数据间以空格间隔，员工间以回车间隔!\n");
		printf("\n代号 岗位工资 薪级工资 其他补贴 水电费 其他扣款 应发工资 扣款合计 实发工资\n");
	for(i=0;i<number;i++)
	{
		printf("\n请输入第%d位员工信息：",count++); 
		scanf("%s %d %d %d %d %d",infor[i].uid,&infor[i].salary,&infor[i].csalary,&infor[i].revenue,&infor[i]._water_electricity,&infor[i]._deductions);
	}
	printf("\n代号:岗位工资:薪级工资:其他补贴:水电费:其他扣款:\n");
	for(i=0;i<number;i++)
	{
		printf("%s   %d     %d       %d      %d      %d\n",infor[i].uid,infor[i].salary,infor[i].csalary,infor[i].revenue,infor[i]._water_electricity,infor[i]._deductions);
		printf("\n"); 
	}
	printf("\n恭喜您！全部信息录入完成，按任意键返回主菜单！\n\n");
	system("pause");
	menu();		 
}
void calculate()  //统计员工工资
{
	int i;
	system("cls");	  //清屏函数 
	printf("\n代号:岗位工资:薪级工资:其他补贴:水电费:其他扣款:应发工资:扣款合计:实发工资:\n");
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
	system("cls");	  //清屏函数 
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
	printf("\n代号:岗位工资:薪级工资:其他补贴:水电费:其他扣款:应发工资:扣款合计:实发工资:\n");
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
	system("cls");	  //清屏函数 
	printf("请输入员工代号："); 
	scanf("%s",input);
	printf("\n代号:岗位工资:薪级工资:其他补贴:水电费:其他扣款:应发工资:扣款合计:实发工资:\n"); 
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
	system("cls");	  //清屏函数 
	printf("请输入新增人数：");
	scanf("%d",&newnum);
	for(i=number;i<number+newnum;i++)
	{
		printf("\n");
		printf("请输入新增第%d位员工信息：",count++);
		scanf("%s %d %d %d %d %d",infor[i].uid,&infor[i].salary,&infor[i].csalary,&infor[i].revenue,&infor[i]._water_electricity,&infor[i]._deductions);
	}
	printf("\n新增人员成功!\n"); 
	number=number+newnum;
	system("pause");
	menu();	
} 
void delete()
{
	int i;
	char dropnum[3];
	system("cls");	  //清屏函数 
	printf("请输入要删除的员工代号：");
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
	printf("\n员工删除成功\n");
	system("pause");
	menu(); 
	
} 
void menu()		//功能菜单选择函数 
{
	int choice;
	int tryagain=0;
	system("cls");
	printf(
		"\n\t|_________________欢迎进入工资处理系统____________________|\t\n"
		"\t|1:录入员工信息                                           |\t\n"
		"\t|2:统计员工工资                                           |\t\n"
		"\t|3:员工工资排序                                           |\t\n"
		"\t|4:查询员工工资                                           |\t\n"
		"\t|5:新增员工工资                                           |\t\n"
		"\t|6:删除员工工资                                           |\t\n"
		"\t|0:退出程序                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
	printf("请输入您需要的功能编号：");
	do
	{
		if(tryagain>=1)
		{
			printf("您的输入有误，请正确输入：");
		}
		scanf("%d",&choice);	
		printf("\n");
		tryagain++; 
	}while(choice<0||choice>6);
	switch(choice)
	{
		case 0: printf("\n下次再见！\n");exit(0);
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
	system("color F0");			//系统函数，背景颜色/文字颜色。 
	system("mode con cols=80 lines=30");	//控制台窗体长宽控制。
	title("工资处理系统");					//修改控制台标题。
	HideConsoleCursor();					//隐藏控制台闪烁的光标 
	welcome();		//欢迎界面。 
	login();		//登录界面。
	menu(); 		//功能菜单选择函数。 
	return 0; 
}
