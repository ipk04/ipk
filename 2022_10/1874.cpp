#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int n,m,j=1;
		scanf("%d",&n);
	vector<int>num;
	vector<int>com;
	bool flag=false;
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		for(;j<=m;j++){
				num.push_back(j);
				com.push_back(1);
		}
		if(num.back()==m){
			//printf("  %d\n",num.back());
			num.pop_back();	
			com.push_back(0);		
		}
		else{

			com.clear();
			flag=true;
		}
	}
	if(flag ==true){
		printf("NO");
		com.clear();
	}
	
	for(int i=0;i<com.size();i++){
		switch(com[i]){
			case 0:
				printf("-\n");
				break;
			case 1:
				printf("+\n");
				break;
		}
	}
}