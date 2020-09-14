#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h> 
#include <algorithm>

using namespace std;
 
 void display(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

void display2D(vector<vector<int>> &arr)
{
    for (vector<int> ar : arr)
        display(ar);
    cout << endl;
}

int MCM_rec(vector<int> &arr,int si,int ei,vector<vector<int>> &dp){
    if(si+1==ei){
        return dp[si][ei]=0;
    }
    if(dp[si][ei]!=-1){
        return dp[si][ei];
    }
    int ans= 1e8;
    for(int cut=si+1;cut<ei;cut++){
        int left=MCM_rec(arr,si,cut,dp);
        int right=MCM_rec(arr,cut,ei,dp);

        int cost=left+ arr[si]*arr[cut]*arr[ei] + right;
        if(cost<ans){
            ans=cost;
        }
    }
    return ans;
}
int MCM_DP(vector<int> &arr,int si,int ei,vector<vector<int>> &dp){
   for(int gap=1;gap<arr.size();gap++){
       for(int si=0,ei=gap;ei<arr.size();si++,ei++){
               if(si+1==ei){
                dp[si][ei]=0;
                continue;
                    }
    
    int ans= 1e8;
    for(int cut=si+1;cut<ei;cut++){
        int left=dp[si][cut];
        int right=dp[cut][ei];

        int cost=left+ arr[si]*arr[cut]*arr[ei] + right;
        if(cost<ans){
            ans=cost;
            
        }
    }
     dp[si][ei]=ans;

       }
   }
   return dp[0][arr.size()-1];

}
int costofsearching(vector<int> &freq,int si,int ei){
    int sum=0;
    for(int i=si;i<freq.size();i++){
        sum+=freq[i];
    }
    return sum;
}
int OBST_rec(vector<int> &freq, int si, int ei, vector<vector<int>> &dp)
{
    if(dp[si][ei]!=0){
        return dp[si][ei];
    }
    int ans=1e8;
     for(int cut=si+1;cut<ei;cut++){
        int left=(cut==si)?0:OBST_rec(freq,si,cut, dp);
        int right=(cut==ei)?0:OBST_rec(freq,cut,ei, dp);


        int cost=left+ costofsearching(freq,si,ei) + right;
        if(cost<ans){
            ans=cost;
        }
    }
    return ans;

}


 
void MCM()
{
    vector<int> arr{1,2,3,4,5};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << MCM_rec(arr, 0, n-1, dp) << endl;
     //cout << MCM_DP(arr, 0, n - 1, dp) << endl;
    // MCM_DP_Ans(arr);

    display2D(dp);
}
void solve(){
  MCM();
}
int main(){
      solve();
      return 0;
    
}