include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int n, m;
int count = 0;
vector<int> weight_up;
vector<int> lose_weight;
vector<int> vec;
bool visit[7] = {false,false, false, false, false, false, false};
bool weight_check() {
    int weight = 500;
    for (int i = 0; i < n; i++) {
        weight = weight- m + weight_up[vec[i]];
        if (weight < 500) {
            return false;
        }
    }
    return true;
}
void dsf(int cnt) {
    if (cnt == n) {
        if (weight_check()){
            ::count++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (visit[i] == true) continue;
        visit[i] = true;
        vec.push_back(i);
        dsf(cnt+1);
        vec.pop_back();
        visit[i] = false;
    }
}
int main()
{
    std::cin >> n>>m;
    for (int i = 0; i < n; i++) {
        int weight;
        std::cin >> weight;
        weight_up.push_back(weight);
    }
    dsf(0);
    std::cout << ::count;
}
