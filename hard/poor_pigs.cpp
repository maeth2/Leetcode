#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    Note: To see which bucket is the culprit we need to assign a unique combination of pigs for each bucket.

    We can then find the minimum number of pigs needed to encode the buckets with a unique combination of pigs.

    First we have to prove that for any T tests and x pigs, it will provide unique encodement for N buckets.

    For example:
        If T = 1, there will be 2^x unique combination of buckets. This is because for each pig,
        there are only two states:
            State #1: Checked the bucket on first test and dies
            State #2: It is still alive

        If T = 2, the number of unique combination of n pigs will be 3^x:
            State #1: Checked the bucket on first test and dies
            State #2: Checked the bucket on second test and dies
            State #3: It is still alive
            
        etc...

        Looking at how we counted max the number of states, we can deduce that it is also equivalent to the (number of tests + 1).
        Therefore we can deduce for any T the maximum number of combinations for x pigs will be (T + 1)^x.

    Let's put this into a different perspective. Assuming we know the number of baskets(N), number of tests(T), number of pigs(x), how can we check if we can find the
    poisoned bucket in T tests. To do this we can imagine assigning a x-bit for each bucket, every bit representing a pig (0 means that the pig is still alive, and the 
    subsequent number representing the other states as mentioned before, e.g 1 means it died at the 1st test, 2 means it died at the 2nd, etc...).

    For example, 9 buckets, 2 tests, and 2 pigs (A, B):
        A	B	C	D 	E 	F 	G 	H	I
        00	01	02	10	11	12	20	21	22

        We can translate this into:
            A is the poisoned bucket if both pigs are still alive.
            B is the poisoned bucket if pig A is still alive and pig B died on the first test.
            C is the poisoned bucket if pig A is still alive and pig B died on the second test.
            D is the poisoned bucket if pig A died on the first test and pig B is still alive.
            E is the poisoned bucket if both pig A and B died on the first test.
            ETC...

        We can also translate this into:
            For the first test:
                Pig A will be assigned Buckets D, E, and F.
                Pig B will be assigned Buckets B, E, and H.

            For the second test:
                Pig A will be assigned Buckets G, H, and I.
                Pig B will be assigned Buckets C, F, and I.

            This combinations of assignments will ensure that each bucket will be encoded with an unique combination of each pigs states, which will allow us to find
            the poisoned bucket after 2 tests.

        Notice that if there were 10 buckets we would no longer be able to represent the 10th bucket with a unique combination of pig states. This is because the maximum number
        of buckets that can be represented by 2 pigs is 3^2.
    
    But what if there were 3 pigs? Well, it will still be a valid solution since each bucket will still be able to receive a unique combination of pig states. One possible new 
    encodement would be this:
        A	B	C	D 	E 	F 	G 	H	I
        000	001	002	010	011	012	020	021	022
    
    We have now proven that for n number of pigs and T number of tests, we will definetly find the poisoned bucket if there less then or equal to (T + 1)^n buckets.
    
    If we were to write this into an equation it would be:
        for every N <= (T+1)^x, a poisoned bucket can be found.

    However the question is asking the Minimum number of pigs. 
    
    In the problem statement, we are given the values of T and N. That means we can simply rearrange the formula above to solve for x instead of N:
        log(T+1)(N) <= x

    We can assume that the answer of log(T+1)(N) is equal to smallest value of x that satisfies the formula.
    We can now just plug in T and N into the formula to find the value of x.
*/
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    /*
        (T+1)^x >= n
        x >= log(n) / log(T + 1)
        
    */
    return ceil(log2(buckets)/log2(minutesToTest / minutesToDie + 1));
}

void solve(){
    int buckets, minutesToDie, minutesToTest;
    cin >> buckets >> minutesToDie >> minutesToTest;
    cout << poorPigs(buckets, minutesToDie, minutesToTest);
}

int main(void){
    solve();
    return 1;
}