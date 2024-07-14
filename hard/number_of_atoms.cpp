#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

map<string, int> elements;

bool isDigit(char i){
    return (i - '0') >= 0 && (i - '0') < 10;
}

bool isCapital(char i){
    return (i - 'A') >= 0 && (i - 'A') < 26;
}

int toInt(string i){
    return (i == "" ? 1 : stoi(i));
}

int recurse(string formula, int index, int multiplier){
    string e = "";
    string count = "";
    for(int i = index; i >= 0; i--){
        char c = formula[i];
        if(c == '('){
            return i;
        }else if(c == ')'){
            i = recurse(formula, i - 1, multiplier * toInt(count));
            count = "";
        }else if(isDigit(c)){
            count = c + count;
        }else{
            e = c + e;
            if(isCapital(c)){
                if(e != ""){
                    elements[e] += toInt(count) * multiplier;
                    count = "";
                }
                e = "";
            }
        }
    }
    return 0;
}

string countOfAtoms(string formula) {
    recurse(formula, formula.size() - 1, 1);
    map<string, int>::iterator it = elements.begin();
    vector<pair<string, int>> li;
    while(it != elements.end()){
        li.emplace_back(it->first, it->second);
        it++;
    }
    sort(li.begin(), li.end(),
        [&] (pair<string, int> a, pair<string, int> b){
            return a.first < b.first;
        }
    );

    string ans = "";
    for(pair<string, int> i : li){
        ans += i.first;
        if(i.second > 1){
            ans += to_string(i.second);
        }
    }
    return ans;
}

void solve(){
    string formula;
    cin >> formula;
    cout << countOfAtoms(formula);
}

int main(void){
    solve();
    return 1;
}