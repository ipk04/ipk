#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class bluck{
private:
public:
    int pay;
    int x, y;
    //bluck* up;
    //bluck* down;
    //bluck* left;  
    //bluck* right;
    bluck* before[2] = {0,0};
    bluck* after[2] = {0,0};
    vector<bluck*> r;

};


int main()
{
    int n=-1;
    int cycle = 0;
     
    while (true) {
        cycle++;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        vector< vector <bluck>> map;
        vector <bluck>blucks;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int n;
                bluck bluck_o;
                std::cin >> n;
                bluck_o.pay = n;
                bluck_o.x = i;
                bluck_o.y = j;
                blucks.emplace_back(bluck_o);
            }
            map.emplace_back(blucks);
            blucks.clear();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    map[i][j].r.emplace_back(&(map[i - 1][j]));
                }
                if (i < n - 1) {
                    map[i][j].r.emplace_back(&(map[i + 1][j]));
                }
                if (j < n - 1) {
                    map[i][j].r.emplace_back(&(map[i][j + 1]));
                }
                if (j > 0) {
                    map[i][j].r.emplace_back(&(map[i][j - 1]));
                }

            }
        }

        vector<vector<int>> map_length;
        vector<int> road;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                road.emplace_back(-1);
            }
            map_length.emplace_back(road);
            road.clear();
        }
        queue<bluck> node;
        int x = 0, y = 0;
        map_length[x][y] = 0;
        for (int i = 0; i < map[0][0].r.size(); i++) {
            map_length[map[x][y].r[i]->x][map[x][y].r[i]->y] = map[x][y].pay + map[map[x][y].r[i]->x][map[x][y].r[i]->y].pay;
            node.emplace(map[map[x][y].r[i]->x][map[x][y].r[i]->y]);

        }
        while (node.empty() != 1) {

            x = node.front().x;
            y = node.front().y;

            for (int i = 0; i < node.front().r.size(); i++) {
                if (x != 0 || y != 0) {
                    if (map_length[node.front().r[i]->x][node.front().r[i]->y] == -1) {
                        map_length[node.front().r[i]->x][node.front().r[i]->y] = map_length[x][y] + map[node.front().r[i]->x][node.front().r[i]->y].pay;
                        node.emplace(map[map[x][y].r[i]->x][map[x][y].r[i]->y]);
                    }
                    else if (map_length[node.front().r[i]->x][node.front().r[i]->y] > map_length[x][y] + map[node.front().r[i]->x][node.front().r[i]->y].pay) {
                        map_length[node.front().r[i]->x][node.front().r[i]->y] = map_length[x][y] + map[node.front().r[i]->x][node.front().r[i]->y].pay;
                        node.emplace(map[map[x][y].r[i]->x][map[x][y].r[i]->y]);
                    }
                }
            }

            node.pop();

        }

                std::cout <<"Problem "<<cycle <<": " << map_length[n-1][n-1]<<endl;
    }
}

