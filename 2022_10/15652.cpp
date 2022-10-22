#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
int n,m;
vector<int> arr;
vector<bool> visit;
vector<int> vec;
void print(){
	for(int i=0;i<vec.size();i++)
		printf("%d ",vec[i]);
	printf("\n");
	return;
}
void dfs(int cnt,int start){
	if(cnt==m){
		print();
		visit[vec.back()-1] =true;
		return;
	}
	
	for(int i=0;i<n;i++){
		if(visit[i]==true|| arr[i]<start) continue;
		vec.push_back(arr[i]);
		dfs(cnt+1,arr[i]);
		vec.pop_back();
		visit[i]=false;
	}
	
}


int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		arr.push_back(i+1);
		visit.push_back(false);
	}
	dfs(0,0);
}