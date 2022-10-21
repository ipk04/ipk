#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> arr){
	for(int i=0;i<arr.size();i++)
		std::cout<<arr[i]<<" ";
	std::cout<<endl;
	return;
}
vector<int> vec;


void dfs(int cnt,int n,int m,vector<int> arr,vector<bool>visit){

	if(cnt==m){
		print(vec);
		return;
	}
	
	for(int i=0;i<n;i++){
		if(visit[i]==true) continue;
		visit[i]=true;
		vec.push_back(arr[i]);
		dfs(cnt+1,n,m,arr,visit);
		vec.pop_back();
		visit[i]=false;
	}	
}

int main(){
	int n,m;
	std::cin>>n>>m;
	vector<int> arr;
	vector<bool> visit;
	for(int i=0;i<n;i++){
		arr.push_back(i+1);
		visit.push_back(false);
	}
	dfs(0,n,m,arr,visit);
}