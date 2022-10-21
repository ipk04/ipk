#include <iostream>
#include <string>
#include <vector>
using namespace std;
class block{
	private:
	public:
	char color;
	vector<block*> near_blocks; 
};
int main(){
	int n,m,count=0;
	int board_start_i=0;
	int board_start_j=0;
	std::cin>>n>>m;
	vector<string>board;
	for(int i=0;i<n;i++){
			string str;	
		std::cin>>str;
		board.push_back(str);
	}

	string longboard="";
	for(int i=0;i<n-1;i++){
		longboard += board[i];
		for(int j=i*8;j<i*8+8;j++){
			if(longboard.size()-1>j+1){
				if(longboard[j]==longboard[j+1]){
					if(longboard[j+1]=='B')
						longboard[j+1]='W';
					else
						longboard[j+1]='B';
				}
			}				
		}
	}
	std::cout<<endl;
	std::cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		std::cout<<longboard[i*8+j];
		}
		std::cout<<endl;
	}
	 int min=64;
	std::cout<<min;
}