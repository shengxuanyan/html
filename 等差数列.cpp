#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	int a[100];
	for(i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	int k;
	int temp;
	for(k=0;k<t-1;k++){
		for(i=k+1;i<t;i++){
			if(a[k]>a[i]){
			    temp=a[k];
			    a[k]=a[i];
			    a[i]=temp;
			}
		}
		
	}
	//for(i=0;i<t;i++){
	//	printf("%d\n",a[i]);
	//}
	
	for(i=0;i<t-2;i++){
		if((a[i+2]-a[i+1])==(a[i+1]-a[i])){
			continue;
		}
		else{
			printf("impossible\n");
			return 0;
		}
		
	}
	printf("Possible\n");
	
	
	return 0;
} 
