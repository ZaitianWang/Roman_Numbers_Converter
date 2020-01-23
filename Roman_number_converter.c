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
	printf("精罗狂喜\nExcited Roman\n\n");
	//printf("甭管什么东罗神罗绿罗，哪怕是没分裂的那个，公元313年发布米兰敕令之后，正统性也就那么回事了\n\n");
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
		    //Zaitianī
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
解题思路：
根据罗马数字的特性，我们可以把每一位数字分别转换
每一位数分为1~4、5~8、9这三类，若为零，则不用转换直接跳过
然后再对10^a取模，求后边位数的映射 
*/
/*
本次收获
1. 复习了递归算法，自己把求数字位数的函数写了出来
2. 知道了switch语句如果不break就会进入下一case
3. 感觉这种switch(位数)，切到对应的case算完之后自己进入后边位数的算法还有一点创新性 
*/
