#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string a,b;
	deque<int> dq_a,dq_b,dq_c;
	int sizing;
	std::cin>>a>>b;
	//std::cout<<a<<"  "<<b;
	sizing=max(a.size(),b.size());
	for(int i=0;i<a.size();i++){
		dq_a.push_back(a[i]-'0');
	}
	for(int i=0;i<b.size();i++){
		dq_b.push_back(b[i]-'0');
	}
	if(dq_a.size()>dq_b.size())
		dq_b.insert(dq_b.begin(),(int)(sizing-dq_b.size()),0);
	else{
		dq_a.insert(dq_a.begin(),(int)(sizing-dq_a.size()),0);
	}
	

	for(int i=0;i<dq_a.size();i++){
		dq_c.push_back(dq_a[i]+dq_b[i]);
	}
	reverse(dq_c.begin(),dq_c.end());
	for(int i=0;i<dq_c.size();i++){
		if(dq_c[i]>=10){
			if(i!=dq_c.size()-1){
				dq_c[i]-=10;
				dq_c[i+1]++;
			}
			else{
				dq_c[i]-=10;
				dq_c.push_back(1);
			}
		}
	}
	reverse(dq_c.begin(),dq_c.end());
	for(int i=0;i<dq_c.size();i++){
		std::cout<<dq_c[i];
	}
}