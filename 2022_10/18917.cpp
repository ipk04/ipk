#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
long long sum=0;
long long Xor=0;
void qury(int q,int x){
	switch(q){
		case 1:
			sum+=x;
			Xor = Xor^x;
			break;
		case 2:
					sum -=x;
					Xor = Xor^x;
					break;
			break;
		case 3:
			printf("%lld\n",sum);
			break;
				
		case 4:		
			printf("%lld\n",Xor);
				break;
		
		
	}
	
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int q,x=0;
		scanf("%d",&q);
		if(q<3)
		 scanf("%d",&x);
		qury(q,x);
	}
	
}