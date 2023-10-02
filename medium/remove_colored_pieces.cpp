#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool winnerOfGame(string colors) {
    int a = 0;
    int b = 0;
    for(int i = 1; i < colors.length() - 1; i++){
        char c = colors[i];
        if(colors[i - 1] == c && colors[i + 1] == c){
            if(c == 'A') a++;
            if(c == 'B') b++;
        }
    }
    return a > b;
}

void solve(){
    string colors;
    cin >> colors;
    cout << winnerOfGame(colors);
}

int main(void){
    solve();
    return 1;
}