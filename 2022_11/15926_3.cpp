#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;


	vector<int>str_sub;
	vector<int>cnt;
	
int count_off(int count){
					 if(count>0){
					 int k1=count;
					 int k2=cnt.size()-1;
					 while(k1>0){
						 if(cnt[k2]==0){
							cnt.erase(cnt.begin()+k2);
							k1--;
						 }
						 k2--;

					 }
					 cnt.push_back(count);
				 }
				 return 0;
}


int main(){
	int n,count=0,max=0;
	string str;
	scanf("%d",&n);
	std::cin>>str;

	
	for(int i=0;i<n;i++){
		switch(str[i]){	
			case '(':

				 count=count_off(count);	
				 cnt.push_back(0);
				str_sub.push_back(0);
				break;
			case ')':
				if(str_sub.empty()==0&&str_sub.back()==0){
					str_sub.pop_back();
					count++;	
					//cnt.push_back(count);				
				}
				else{
				str_sub.push_back(1);
					count=count_off(count);	
				 cnt.push_back(0);
				}
			break;
		}	
	      // printf("\n");
		  // for(int i=0;i<cnt.size();i++){
			  // printf("  %d",cnt[i]);
		  // }
	}
   count=count_off(count);	
	 // printf("\n");
	 // for(int i=0;i<str_sub.size();i++){
		  // printf("  %d",str_sub[i]);
	  // }
	 // printf("\n");
	 for(int i=1;i<cnt.size();i++){
		 if(cnt[i]>0)
			cnt[i]+=cnt[i-1];
	 }
	  // printf("\n");
	 // for(int i=0;i<cnt.size();i++){
		 // printf("  %d",cnt[i]);
	 // }
	sort(cnt.begin(),cnt.end());
	max=cnt.back();

	

	//printf("\n");
	printf("%d",max*2);
}