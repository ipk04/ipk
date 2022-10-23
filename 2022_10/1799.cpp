#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;
int n,count=0;
vector<int> queen;
int board[10][10];
bool check(int level){
	for(int i=0;i<level;i++){
		if(abs(queen[i]-queen[level]) == level-i  ){
			return true;
		}
	}
			return false;
}

void dfs(int cnt){
	if(cnt ==n){
		return;
	}

	for(int i=0;i<n;i++){
		if(board[cnt][i]==0) continue;
		queen[cnt] =i;
		if(check(cnt)){
			board[cnt][i]=0;
			//dfs(cnt-1);
		}
		dfs(cnt+1);
	}
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		queen.push_back(-1);
		for(int j=0;j<n;j++){
			int k;
			scanf("%d",&k);
			board[i][j] = k;
		}
	}
	

	dfs(0);	
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]==1) count++;
	printf("%d",count);
}