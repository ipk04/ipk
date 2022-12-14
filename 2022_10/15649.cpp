#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int arr[8];
bool visit[8];
vector<int> vec;
int n,m;


void print(){
	for(int i=0;i<vec.size();i++)
		printf("%d ",vec[i]);
	printf("\n");
	return;
}
void dfs(int cnt){

	if(cnt==m){
		print();
		return;
	}
	
	for(int i=0;i<n;i++){
		if(visit[i]==true) continue;
		visit[i]=true;
		vec.emplace_back(i+1);
		dfs(cnt+1);
		vec.pop_back();
		visit[i]=false;
	}	
}

int main(){
	scanf("%d%d",&n,&m);
	//vector<int> arr(n,0);
	//vector<bool> visit(n,false);
	for(int i=0;i<n;i++){
		arr[i]=i+1;
		visit[i]=false;
	}
	dfs(0);
}