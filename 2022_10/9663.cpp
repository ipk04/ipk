#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;
int n,count=0;
vector<int> queen;

bool check(int level){
	for(int i=0;i<level;i++){
		if(queen[i]==queen[level]|| abs(queen[i]-queen[level]) == level-i){
			return true;
		}

	}
			return false;
}

void dfs(int cnt){
	if(cnt ==n){
		count ++;
		return;
	}
	
	for(int i=0;i<n;i++){
		queen[cnt] =i;
		if(check(cnt))continue;
		dfs(cnt+1);
	}
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		queen.push_back(-1);
	}
	dfs(0);	
	printf("%d",count);
}