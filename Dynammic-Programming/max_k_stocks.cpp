#include<bits/stdc++.h>
using namespace std;

class Solve {
  public:
    int solve(int buy  , int count , int k , int index , int n , int *a , vector<vector<vector<int>>> &dp){
        if(count == k) return 0;
        if(index == n) return 0;
        if(dp[index][count][buy] != -1) return dp[index][count][buy];
        int ans1 = 0 , ans2 = 0;
        if(buy){
            ans1 = -a[index] + solve(buy - 1  , count , k , index + 1 , n , a , dp);
            ans2 = solve(buy  , count , k , index + 1 , n , a , dp);
        }
        else{
            ans1 = a[index] + solve(1 - buy  , count + 1 , k , index + 1 , n , a , dp);
            ans2 = solve(buy , count , k , index + 1 , n , a , dp);
        }
        return dp[index][count][buy] = max(ans1 , ans2);
    }

    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>> dp(N + 1 , vector<vector<int>>(K , vector<int>(2 , -1)));
        return solve(1 , 0 , K , 0 , N , A , dp);
    }
};
// this is my new branch code 
