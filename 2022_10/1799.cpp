#include <iostream>
#include <vector>

using namespace std;
bool visit[10];
int n;
vector<int> vishop;
int board[10][10];
vector<vector<int>> odd_board;
vector<vector<int>> even_board;
int max_odd_cnt = 0;
int max_even_cnt = 0;

int odd_dsf(int cnt) {
	if (cnt == n-1) {
		for(int i=0;i<vishop.size();i++){
			std::cout<<vishop[i]<<" ";
		}
		std::cout<<"\n";
		int odd_cnt = 0;
		for (int i = 0; i < vishop.size(); i++) {
			if (vishop[i] != -1) {
				odd_cnt++;
			}
		}
		if(visit[0]==false && board[n-1][n-1] ==1)
			odd_cnt++;
		if (odd_cnt > ::max_odd_cnt) {
			::max_odd_cnt = odd_cnt;
		}
		return 0;
	}

	for (int i = 0; i < odd_board[cnt].size(); i++) {
		if (visit[i] == true) continue;
		if (odd_board[cnt][i] == 1) {
			visit[i] = true;
			vishop.push_back(i);
		}
		else
			vishop.push_back(-1);
		odd_dsf(cnt + 1);
		visit[i] = false;
		vishop.pop_back();
	}
	return 0;
}


int even_dsf(int cnt) {
	if (cnt == n - 1) {
		
		for(int i=0;i<vishop.size();i++){
			std::cout<<vishop[i]<<" ";
		}
		std::cout<<"\n";
		
		int even_cnt = 0;
		for (int i = 0; i < vishop.size(); i++) {
			if (vishop[i] != -1) {
				even_cnt++;
			}
		}
		if (even_cnt > ::max_even_cnt) {
			::max_even_cnt = even_cnt;
		}
		return 0;
	}

	for (int i = 0; i < even_board[cnt].size(); i++) {
		if (visit[i] == true) continue;
		if (even_board[cnt][i] == 1) {
			visit[i] = true;
			vishop.push_back(i);
		}
		else
			vishop.push_back(-1);

		even_dsf(cnt + 1);
		visit[i] = false;
		vishop.pop_back();
	}
	return 0;
}
int main()
{
	std::cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> num;
			board[i][j] = num;
		}
		visit[i] = false;
	}

	for (int i = 0; i < n; i++) {
		vector<int> odd_board_line;
		for (int j = 0; j < n; j++) {
			if (j == 0)
				odd_board_line.push_back(board[i][i]);
			else
				if (n > i + j && i - j >= 0) {
					odd_board_line.push_back(board[i + j][i - j]);
					odd_board_line.push_back(board[i - j][i + j]);
				}
		}
		odd_board.push_back(odd_board_line);
		odd_board_line.clear();
	}

	for (int i = 0; i < n-1; i++) {
		vector<int> even_board_line;
		for (int j = 0; j < n; j++) {
				if (n > i + j+1 && i - j >= 0) {
					even_board_line.push_back(board[i + j+1][i - j]);
					even_board_line.push_back(board[i - j][i + j+1]);
				}
		}
		even_board.push_back(even_board_line);
		even_board_line.clear();
	}
	odd_dsf(0);
	vishop.clear();
	for (int i = 0; i < n; i++) {
		visit[i] = false;
	}
	even_dsf(0);
	if (n == 1) max_odd_cnt = board[0][0];
	std::cout<<max_even_cnt+max_odd_cnt;
	
	//for (int i = 0; i < 2*n-1; i++) {
	//	if ((i & 1) == 0) {
	//		for (int j = 0; j < odd_board[i/2].size(); j++) {
	//			std::cout << odd_board[i/2][j] << " ";
	//		}
	//	}
	//	else 
	//		for (int j = 0; j < even_board[i/2].size(); j++) {
	//			std::cout << even_board[i/2][j] << " ";
	//		}
	//	std::cout << "\n";
	//}
	
}
