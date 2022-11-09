#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;


int main(){

	int n;
	scanf("%d",&n);
	
	int arr[500]={};
	vector<int> arr2;
	vector<int> arr_num_min;
	int over=0;
	for(int i=0;i<n;i++){
		int m1,m2;
		scanf("%d %d",&m1,&m2);
		arr[m1-1]=m2;
		if(over<m1){
			over=m1;
		}
	}
	int count=0;
	for(int i=0;i<over;i++){
		if(arr[i]!=0){
			if(arr2.empty()==1||arr_num_min.back()<arr[i]){
				count++;
				arr2.push_back(count);
				arr_num_min.push_back(arr[i]);
			}
			else{
				for(int j=0;j<arr_num_min.size();j++){
					if(arr_num_min[j]==arr[i]){
						arr2.push_back(count);
						break;
					}
					if(arr_num_min[j]>arr[i]){
						arr2.push_back(count);
						arr_num_min[j]=arr[i];
						break;
					}
				}
			}
		}
	}
	// for(int i=0;i<arr_num_min.size();i++){
		// printf("%d\n",arr_num_min[i]);
	// }
	printf("%d",n-arr_num_min.size());
}
