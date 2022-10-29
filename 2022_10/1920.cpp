#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

void find_num(int num,vector<int> origin,int start,int end){
	
	//printf("%d %d %f\n",start,end,ceil((float)(end+start)/2));
	int mid = (int)ceil((float)(end+start)/2);
	if(num == origin[mid]||(end==1 && num == origin[0])){
		printf("1\n");
		return;
	}
	else if(start == end || start > end){
			printf("0\n");
			return;
		}
	else if(num < origin[mid]){
			find_num(num,origin,start,mid);
	}
	else{		
			find_num(num,origin,mid,end);
	}
	return;
	
	
}
int main(){
	int n,m,num;
	bool flag=false;
	vector<int> origin;
	vector<int> req;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		origin.push_back(num);
	}
	sort(origin.begin(),origin.begin()+n);
	// for(int i=0;i<n;i++){
		// printf("%d ",origin[i]);
	// }
	//printf("\n");
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&num);
		//printf("%d\n",num);
		find_num(num,origin,0,n-1);
	}
	//printf("%f",ceil((float)(float)(3+4)/2));
	
}