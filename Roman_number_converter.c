#include <stdio.h>

int digit (int n)
{
    if ( n<10 )
    return 1;
    else 
    return 1 + digit ( n/10 );
}

int main() 
{
	int n;
	int i;
	printf("���޿�ϲ\nExcited Roman\n\n");
	//printf("�¹�ʲô�����������ޣ�������û���ѵ��Ǹ�����Ԫ313�귢���������֮����ͳ��Ҳ����ô������\n\n");
	printf("Please input the Arabic Number you want to convert:\n\n");
	scanf("%d", &n);
	printf("\nThe Arabic number is: %d\n\n", n);
    if ( n<=0 || n>=4000 )
		printf("It make no sense to convert your input, which is out of [1, 4000).");
    else
	{
		printf("The Roman number is: ");
		switch ( digit (n) )
		{
			case 4:
			{
				for (i=1; i<=n/1000; i++)
				printf("M");
				n=n%1000;
			}
		    case 3:
			{
				if ( n>=100 && n<=399 )
				for (i=1; i<=n/100; i++)
				printf("C");
				else if ( n>=400 && n<499)
				printf("CD");
				else if ( n>=500 && n<=899)
				{
					printf("D");
					for (i=6; i<=n/100; i++)
					printf("C");
				}
				else if ( n>=900 && n<=999)
				printf("CM");
				n=n%100;
			}

			case 2:
		    {
		        if ( n>=10 && n<=39 )
		        {
		            for (i=1; i<=n/10; i++)
		            printf("X");
		        }
		        else if ( n>=40 && n<=49 )
		        printf("XL");
		        else if (n>=50 && n<=89)
		        {
		        	printf("L");
		        	for (i=6; i<=n/10; i++)
		        	printf("X");
				}
		        else if ( n>=90 && n<=99 )
		        printf("XC");
		        n=n%10;
		    }
		    //Zaitian��
		    case 1:
		    {
		        if (n==0)
		        {}
		        else if ( n>=1 && n<=3 )
		        {
		            for (i=1; i<=n; i++)
		            printf("I");
		        }
		        else if (n==4)
		        printf("IV");
		        else if ( n>=5 && n<=8)
		        {
		            printf("V");
		            for (i=6; i<=n; i++)
		            {
		                printf("I");
		            }
		        }
		        else if (n==9)
		        printf("IX");
		    }
		}
	}
	printf("\n\nSENATUS POPULUSQUE ROMANUS");
    return 0;
}
/*
����˼·��
�����������ֵ����ԣ����ǿ��԰�ÿһλ���ֱַ�ת��
ÿһλ����Ϊ1~4��5~8��9�����࣬��Ϊ�㣬����ת��ֱ������
Ȼ���ٶ�10^aȡģ������λ����ӳ�� 
*/
/*
�����ջ�
1. ��ϰ�˵ݹ��㷨���Լ���������λ���ĺ���д�˳���
2. ֪����switch��������break�ͻ������һcase
3. �о�����switch(λ��)���е���Ӧ��case����֮���Լ�������λ�����㷨����һ�㴴���� 
*/
