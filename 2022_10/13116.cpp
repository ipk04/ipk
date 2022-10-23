//n>>1 = 이전 노드의 수

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int n,a,b,count=1,num=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		num=0;
		if(a>b){
			while(b>=1<<num){
				num++;
			}
			while(a>=1<<num){
				a=a>>1;
			}
		}
		else{
			while(a>=1<<num){
				num++;
			}
			while(b>=1<<num){
				b=b>>1;
			}
		}
		
		while(a>0){
			if(a==b) {
				count=a;
				break;
			}
			a=a>>1;
			b=b>>1;
		}
		printf("%d\n",count*10);
		count =0;

	}
	
}