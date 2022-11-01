#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	double chance;
	long long k=1000000000000000;
	vector<int> chances;
	for(int i=0;i<10;i++){
		scanf("%lf",&chance);
		chances.push_back(round(chance*100));
	}

	// for(int i=0;i<chances.size();i++){
		// printf("%d\n",chances[i]);
	// }
	sort(chances.begin(),chances.end());
	chances.erase(chances.begin());
	for(int i=0;i<chances.size();i++){
		k=round((k*chances[i]/100)/(i+1));	
		//printf("%lld\n",k);		
	}
	//k=20123400;
	if(k%1000000 == 0){
		printf("%lld",k/1000000);
	}
	else{
		printf("%lld.", k / 1000000);
		int ne = 1000000;
		k = k % ne;
		while (k > 0) {
			ne /= 10;
			//printf("%lld\n", k);
			printf("%lld", k/ ne);
			k = k % ne;
		}
	}
		//printf("%lld.%06lld",k/1000000,k%1000000);
	return 0;
}