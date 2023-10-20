#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    public:
        int index = 0;
        vector<int> ans;
        void recurse(NestedInteger curr, vector<int> &ans){
            if(curr.isInteger()){
                ans.push_back(curr.getInteger());
            }else{
                for(NestedInteger i : curr.getList()){
                    recurse(i, ans);
                }
            }
        }

        NestedIterator(vector<NestedInteger> &nestedList) {
            for(NestedInteger i : nestedList){
                recurse(i, ans);
            }
        }
        
        int next() {
        return ans[index++];
        }
        
        bool hasNext() {
            return index < ans.size();
        }
};