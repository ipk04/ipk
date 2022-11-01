#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int n,X;
	scanf("%d %d",&n,&X);
	vector<int> voice_limit;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		voice_limit.push_back(num);
		//printf("%d\n",voice_limit[i]);
	}
	int i=0;
	while(voice_limit[i]>=X){
		//printf("%d %d \n",i,X);
		X++;
		i++;
		if(i>=n){
			i=0;
		}
	}
	printf("%d",i+1);
}