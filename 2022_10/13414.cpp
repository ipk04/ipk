#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	vector<string>suc_id;
	vector<string>id;
	set<string>id_check;
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		string num;
		std::cin>>num;
		id.push_back(num);
	}
	
	reverse(id.begin(),id.end());
	for(int i=0;i<m;i++){
		int size=id_check.size();
		id_check.insert(id[i]);
		if(size!=id_check.size()){
			suc_id.push_back(id[i]);
		}
	}
	reverse(suc_id.begin(),suc_id.end());
	for(int i=0;i<n;i++){
		if(i<suc_id.size()){
			std::cout<<suc_id[i]<<"\n";
		}
	}

}