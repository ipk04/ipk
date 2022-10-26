
#include <iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    std::cin >> str;
    bool same_falg = false;
    if (str.size() == 1) {
        std::cout << -1;
        return 0;
    }
    if (str.size() == 2) {
        if (str[0] == str[1]) {
            std::cout << -1;
            return 0;
        }
        else
            std::cout << 2;
            return 0;
    }

        for (int i = 0; i < str.size() / 2 + 1; i++) {
            if (str[i] != str[str.size() - 1 - i]) {
                std::cout << str.size();
                break;
            }
            if (str[i] == str[str.size() - 1 - i] && str[i] == str[i + 1]) {
                same_falg = true;
            }
            else
                same_falg = false;
            if (i == str.size() / 2) {
                if (same_falg == true) {
                    std::cout << -1;
                }
                else {
                    std::cout << str.size() - 1;
                    break;
                }


            }
        }
    
}