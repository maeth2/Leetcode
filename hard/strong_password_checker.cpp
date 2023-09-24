#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    For Inserting, the min number of edits is the maximum between the # of insertions, # of edits to break repeats, and # of missing types.

    For Deleting, prioritise the use of deletion to break repeats by picking subsets of 3 or more consecutive characters with size % 3 closest to 0.

    If there is no need to inserting or deleting, the minimum number of edits will be the maximum between # of edits to break repeats and $ of missing types.
*/

int strongPasswordChecker(string password) {
    int length = password.length();
    int count = 0;
    char prev = password[0];
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int repeat = 0;
    vector<int> repeats;
    for(int i = 0; i < password.length(); i++){
        char c = password[i];
        if(c - 'A' < 26 && c - 'A' >= 0) upper++;
        if(c - 'a' < 26 && c - 'a' >= 0) lower++;
        if(c - '0' < 9 && c - '0' >= 0) digit++;
        if(c == prev){ 
            count++;
        }else{
            if(count >= 3){
                repeats.push_back(count);
            }
            prev = c;
            count = 1;
        }
        if(count % 3 == 0){
            repeat++;
        }
    }
    if(count >= 3){
        repeats.push_back(count);
    }

    int ans = 0;
    int changes = 0;
    int ins = 0;
    int del = 0;
    if(length > 20){
        del = length - 20;
    }else if(length < 6){
        ins = 6 - length;
    }
    changes = upper < 0 + lower < 0 + digit < 0;

    if(ins > 0){
        ans = max(ins, max(repeat, changes));
    }else if(del > 0){
        while(del > 0){
            if(repeats.size() == 0) break;
            int mi = 0;
            int md = INT16_MAX;
            for(int i = 0; i < repeats.size(); i++){
                if(repeats[i] % 3 < md){
                    md = repeats[i] % 3;
                    mi = i;
                }
            }
            ans++;
            del--;
            repeats[mi]--;
            if(repeats[mi] < 3){
                repeats.erase(repeats.begin() + mi);
            }
        }
        repeat = 0;
        for(int i = 0; i < repeats.size(); i++){
            repeat += repeats[i] / 3;
        }
        ans += del + max(repeat, changes);
    }else{
        ans = max(repeat, changes);
    }
    return ans;
}

void solve(){
    string n;
    cin >> n;
    cout << strongPasswordChecker(n) << "\n";
}

int main(void){
    solve();
    return 1;
}