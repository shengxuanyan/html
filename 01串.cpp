#include<stdio.h>
int main(){
	int count=1;
	int temp=0;
	int a[100];
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	  scanf("%d",&a[i]);
    }
    for(int i=0;i<t-1;i++){
    	if(a[i]!=a[i+1]){
    		count++;
		}
		else{
			if(count>temp){
				temp=count;
				count=0;
			}
			continue;
		}
		
	}
	if(count>temp){
	temp=count;
	}
	printf("%d",temp);
}
