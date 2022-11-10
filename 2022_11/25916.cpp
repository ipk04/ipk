#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;


int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> hole;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		hole.push_back(a);
	}
	int start=0,end=1;
	int sum=hole.front(),max=0;
	while(end<n){	
		if(sum<=m){
			if(sum>max){
				max=sum;
			}
			sum+=hole[end];
			end++;
		}
		else{
			sum-=hole[start];
			start++;
		}
		//printf("%d\n",sum);
	}
	if(sum<=m&&sum>max){
		max=sum;
	}
	printf("%d",max);
}