#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//�س�����ascii
#define ESC 27  

//�ȴ�����
void wait(int seconds)
{
	//������time.h�еļ�ʱ����
	//clock_t��һ����������
	clock_t endwait;   

	//clock() c�еļ�ʱ���������صĵ�λΪ���롣
	//����뷵������Ϊ��λ�����ã�duration = (finish - start) / CLOCKS_PER_SEC;
	endwait = clock() + seconds * CLK_TCK;

	while (clock() < endwait)
	{}
}

//��ʱ����
void countTime() {
	clock_t start;

	clock_t end;

	char ch;

	printf("\n\t\t *****���***** \n\n");

	printf("(1)��'t'��ʼ��ʱ  (2)��'p'��ͣ��ʱ����ʾ��ǰ��ʱʱ��  (3)��'c'ʹ������  (4)��'Esc'�˳�����\n\n");

	// ��'t'����ʼ��ʱ 

	if (getch() == 't')

	{

		printf("�ѿ�ʼ��ʱ...");

		// ���ؿ�ʼ��ʱʱ�� 

		start = clock();

		// for(;;) ��Ч�� while(1) 

		for (;;)
		{
			ch = getch();

			// ��'p'����ͣ��ʱ  

			if (ch == 'p') {

				for (;;) {

					// ���ؽ�����ʱʱ�� 


					end = clock();

					printf("\n\n����ͣ��ʱ, �ٰ�'p'��ʼ��ʱ. ��ʾ��ǰ��ʱʱ�� : %f\n",

						((double)(end - start) / CLOCKS_PER_SEC));  

						// CLOCKS_PER_SEC ��Ч�� CLK_TCK, �������ѹ�ʱ 		
						// �ٴΰ�'p'����ʼ��ʱ 
					if (getch() == 'p') {

						printf("\n\n������ʱ...");

						break;
					}
				}
			}
			// ��'c'��������

			if (ch == 'c') {

				printf("\n\n����ѹ���.\n");

				start = clock();
			}
			// ��'Esc'���˳�����		
			if (ch == ESC)
			{
				break;

				exit(0);

			}
		}

	}

};

//��ʱ����2
void countTime2() {
	int i = 1;

	printf("��ʱ��ʼ��\n");

	//�ȴ�1S
	wait(1);

	//����
	system("cls");

	//������� ʱ �� ��
	int h=0, m=0, s=0;

	char ch;

	printf("��'p'��ͣ��ʱ����ʾ��ǰ��ʱʱ��\n");

	while (m >= 0)
	{
		while (m <= 59)
		{
			while (s <= 59)
			{

				//�ȴ�1S
				wait(1);
				
				//����
				system("cls");
				
				//�����ʱ
				printf("��ʱ��ʼ:\t%dʱ%d��%d��\n", h, m, s);  
			
			
				s = s + 1;
			}

				m = m + 1;

				s = 0;
				
				//�����¼�Ϊpʱֹͣ��ʱ  ���˳�
			   ch = getch();
			
			   if (ch == 'p')
			   {
				   break;

				   //�˳�
				   exit(1);
				}
			}
		h = h + 1;

		m = 0;
	}
}

//����ʱ����
void countDown() {
	
	//��������
	int n;

	//ʱ�� ��
	int s;

	//ʱ�� ��
	int m;

	printf("������Ҫ����ʱ������������λ��S��");

	//��������
	scanf("%d", &n);
	
	//�������� clock 
	clock_t start, end;
	getchar();
	
	//ʹ�������͵��� ��ʱ����
	start = end = clock();

	char ch;
	
	while (1)
	{


		wait(1);
		n--;
		if (n == 0)
		{	
			//����

			system("cls");

			printf("ʱ�䵽����\n");

			system("pause");

			break;
		}

		//��������
		s = n % 60;

		//���������
		m = n / 60;

		printf("\r\t%02d:%02d", m, s);
	}
	exit(0);

};

int main() {

	system("mode con cols=100 lines=20");                         //��ʾ���С���ƺ���

	system("color 0C");                                           //��ʾ��ɫ���ƺ���������ͱ���

	int switch_on, hour, minutes, seconds;

	printf("\t======================================================\n");

	printf("\t��ѡ����Ҫѡ��Ĺ��ܣ�\n");

	printf("\n\t 1  ��ʱ");

	printf("\n\t 2  ����ʱ");

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

			printf("��������ȷ��ѡ���\n");

			printf("\t======================================================\n");

		break;
	}
		
}

/*�û�����������������ܣ���ʱ����ʵ�ֺ͵���ʱ����ʱ���趨������ʱʵ�֡�/
Ҫ�� 1�����ò˵�ѡ��ķ�ʽ���û�ѡ���ܣ�
2����ʱ�����û�����(��ʱ��ʼ)��ʱ�㿪ʼ֪���û�����(��ʱֹͣ)����ʾ�����ʱ�䣻
3������ʱ�����û�����ʱ�䣬������ʼ����ʱ�����ʱ��ʼ������ʱ�����ʾ��ʱ�䵽����
4����ʱ���͵���ʱ������ȷ���롣
**/