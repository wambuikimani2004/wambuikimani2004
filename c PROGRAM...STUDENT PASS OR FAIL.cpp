//students pass or fail
#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,c,d,sum;
	float avg;
	printf("enter the marks of the 4 students=\n");
	scanf("%d\n%d\n%d\n%d",&a,&b,&c,&d);
	sum=a+b+c+d;
	printf("sum marks=%d\n",sum);
	avg=(a+b+c+d)/4;
	printf("the avarage is=%f\n",avg);
	if(sum<300)
	{
		printf("The student fail!!\n");
		printf("the student should undergo repeat!!\n");
	}
		else
{
	printf("the student reach the pass mark!!\n");
	printf("the student qualify for secondary school");
}
	return 0;
}