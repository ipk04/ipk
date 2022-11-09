#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> arr;
	vector<int> arr2;
	vector<int> arr_num_min;
	int count=0;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		if(arr2.empty()==1){
			arr2.push_back(count);
			arr_num_min.push_back(num);
		}
		else{
			if(arr_num_min.back()<num){
				count++;
				arr2.push_back(count);
				arr_num_min.push_back(num);
			}
			else{
				for(int j=0;j<arr_num_min.size();j++){
					if(arr_num_min[j]==num)
						arr2.push_back(j);
						break;
					else if(arr_num_min[j]>num){
						arr2.push_back(j);
						arr_num_min[j]=num;
						break;
					}
				}
			}
		}
				arr.push_back(num);
		
	 }
	// for(int i=0;i<arr2.size();i++){	
		// printf("  %d",arr2[i]);
	// }
	printf("%d",arr2.back()+1);
	return 0;
}