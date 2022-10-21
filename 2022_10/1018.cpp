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
	vector<vector<block*>> ches_board_origin;
	vector<vector<block*>> ches_board;
	vector<block*> line;
	vector<block*> line_origin;
	for(int i=0;i<n;i++){
			string str;	
		std::cin>>str;
		for(int j=0;j<m;j++){
			block* oneblock = new block;		
			block* twoblock = new block;
			oneblock->color = str[j];	
			twoblock->color = str[j];
			line.push_back(oneblock);
			line_origin.push_back(twoblock);

		}
		ches_board.push_back(line);
		ches_board_origin.push_back(line_origin);
		line.clear();
		line_origin.clear();
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(i<n-1 &&ches_board[i][j]->color == ches_board[i+1][j]->color){
				if(ches_board[i+1][j]->color=='B'){
					ches_board[i+1][j]->color='W';
				} 
				else
					ches_board[i+1][j]->color='B';
			}
			if(ches_board[i][j]->color == ches_board[i][j+1]->color){
				if(ches_board[i][j+1]->color=='B'){
					ches_board[i][j+1]->color='W';
				} 
				else
					ches_board[i][j+1]->color='B';
				}
		}
	}
	int min=64;
	for(int i=0;i<n-7;i++){
		for(int j=0;j<m-7;j++){
			for(int k1=i;k1<i+8;k1++){
				for(int k2=j;k2<j+8;k2++){
						if(ches_board[k1][k2]->color != ches_board_origin[k1][k2]->color){
							count++;						
						}
				}
			}
			//std::cout<<count<<endl;
			if(count<min){
				min=count;
			}
			count=0;
		}
	}
	std::cout<<min;
}