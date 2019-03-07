#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	while(a != 1)
	{
		double m = 1.0 * a / 2 * 1.0;
		int t = a / 2;
		if(m == t)
		{
			a /= 2;
		}
		else
		{
			break;
		}
    }
	while(a != 1)
	{
		double m = 1.0 * a / 3 * 1.0;
		int t = a / 3;
		if(m == t)
		{
			a /= 3;
		}
		else
		{
			break;
		}
    }
	while(a != 1)
	{
		double m = 1.0 * a / 5 * 1.0;
		int t = a / 5;
		if(m == t)
		{
			a /= 5;
		}
		else
		{
			printf("bushui\n");
			return 0;
		}
    }
    
    printf("shi");
}
