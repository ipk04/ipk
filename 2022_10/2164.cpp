#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    queue<int>Deck;
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        Deck.push(i + 1);
    }
    int i = 0;
    while (Deck.size() > 1) {
        if (i & 1) {
           Deck.push(Deck.front());
        }
        Deck.pop();
        i++;
    }
    printf("%d", Deck.front());
}