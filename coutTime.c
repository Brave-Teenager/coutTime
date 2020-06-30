#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//回车键的ascii
#define ESC 27  

//等待函数
void wait(int seconds)
{
	//定义在time.h中的计时函数
	//clock_t是一个长整型数
	clock_t endwait;   

	//clock() c中的计时函数，返回的单位为毫秒。
	//如果想返回用秒为单位可以用：duration = (finish - start) / CLOCKS_PER_SEC;
	endwait = clock() + seconds * CLK_TCK;

	while (clock() < endwait)
	{}
}

//计时函数
void countTime() {
	clock_t start;

	clock_t end;

	char ch;

	printf("\n\t\t *****秒表***** \n\n");

	printf("(1)按't'开始计时  (2)按'p'暂停计时并显示当前计时时长  (3)按'c'使秒表归零  (4)按'Esc'退出程序\n\n");

	// 按't'键开始计时 

	if (getch() == 't')

	{

		printf("已开始计时...");

		// 返回开始计时时间 

		start = clock();

		// for(;;) 等效于 while(1) 

		for (;;)
		{
			ch = getch();

			// 按'p'键暂停计时  

			if (ch == 'p') {

				for (;;) {

					// 返回结束计时时间 


					end = clock();

					printf("\n\n已暂停计时, 再按'p'开始计时. 显示当前计时时长 : %f\n",

						((double)(end - start) / CLOCKS_PER_SEC));  

						// CLOCKS_PER_SEC 等效于 CLK_TCK, 但后者已过时 		
						// 再次按'p'键开始计时 
					if (getch() == 'p') {

						printf("\n\n继续计时...");

						break;
					}
				}
			}
			// 按'c'键秒表归零

			if (ch == 'c') {

				printf("\n\n秒表已归零.\n");

				start = clock();
			}
			// 按'Esc'键退出程序		
			if (ch == ESC)
			{
				break;

				exit(0);

			}
		}

	}

};

//计时函数2
void countTime2() {
	int i = 1;

	printf("计时开始！\n");

	//等待1S
	wait(1);

	//清屏
	system("cls");

	//定义变量 时 分 秒
	int h=0, m=0, s=0;

	char ch;

	printf("按'p'暂停计时并显示当前计时时长\n");

	while (m >= 0)
	{
		while (m <= 59)
		{
			while (s <= 59)
			{

				//等待1S
				wait(1);
				
				//清屏
				system("cls");
				
				//输出计时
				printf("计时开始:\t%d时%d分%d秒\n", h, m, s);  
			
			
				s = s + 1;
			}

				m = m + 1;

				s = 0;
				
				//当按下键为p时停止计时  并退出
			   ch = getch();
			
			   if (ch == 'p')
			   {
				   break;

				   //退出
				   exit(1);
				}
			}
		h = h + 1;

		m = 0;
	}
}

//倒计时函数
void countDown() {
	
	//定义秒数
	int n;

	//时间 秒
	int s;

	//时间 分
	int m;

	printf("请输入要倒计时的秒数：（单位：S）");

	//输入秒数
	scanf("%d", &n);
	
	//数据类型 clock 
	clock_t start, end;
	getchar();
	
	//使数据类型等于 计时函数
	start = end = clock();

	char ch;
	
	while (1)
	{


		wait(1);
		n--;
		if (n == 0)
		{	
			//清屏

			system("cls");

			printf("时间到！！\n");

			system("pause");

			break;
		}

		//计算秒数
		s = n % 60;

		//计算分钟数
		m = n / 60;

		printf("\r\t%02d:%02d", m, s);
	}
	exit(0);

};

int main() {

	system("mode con cols=100 lines=20");                         //显示框大小控制函数

	system("color 0C");                                           //显示颜色控制函数，字体和背景

	int switch_on, hour, minutes, seconds;

	printf("\t======================================================\n");

	printf("\t请选择您要选择的功能：\n");

	printf("\n\t 1  计时");

	printf("\n\t 2  倒计时");

	printf("\n\t 0  Exit\n");

	scanf("\t%d", &switch_on);

	printf("\t======================================================\n");

	switch (switch_on)
	{
		case 1:	countTime();
			break;

		case 2: countDown();
			break;

		case 0:
			exit(0);

		default:

			printf("请输入正确的选项！！\n");

			printf("\t======================================================\n");

		break;
	}
		
}

/*用户进入两个最基本功能：计时器的实现和倒计时器的时间设定及倒计时实现。/
要求： 1、采用菜单选择的方式让用户选择功能；
2、计时器：用户操作(计时开始)计时便开始知道用户操作(计时停止)，显示出这段时间；
3、到计时器：用户输入时间，操作开始倒计时，便计时开始，倒计时完成提示“时间到！”
4、计时器和倒计时器都精确到秒。
**/