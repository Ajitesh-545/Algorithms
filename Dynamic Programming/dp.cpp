#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h> 


using namespace std;

int fibo(int n, vector<int> &dp){
    if(n<=1){
        return dp[n]=n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n]=ans;
}

int fiboDp(int n, vector<int> &dp){
    for(int i=0;i<n;i++){
    if(i<=1){
         dp[i]=i;
        continue;
    }
    int ans=dp[i-1]+dp[i-2];
     dp[i]=ans;
    }
    return dp[n];
}
void display(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}



// Maze path////////////////
int mazepath(int sr,int sc,int er,int ec,vector<vector<int>> &dp){

if(sr==er && sc==ec){
    return dp[sr][sc]=1;
}
if(dp[sr][sc]!=0){
    return dp[sr][sc];
}
int count=0;
if(sr+1<=er){
    count+=mazepath(sr+1,sc,er,ec,dp);
}
if(sc+1<=ec){
    count+=mazepath(sr,sc+1,er,ec,dp);
}
if(sr+1<=er && sc+1<=ec){
    count+=mazepath(sr+1,sc+1,er,ec,dp);
}
return dp[sr][sc]=count;
}

int mazepathDP(int sr,int sc,int er,int ec,vector<vector<int>> &dp)
{
    for(sr=er;sr>=0;sr--){
        for(sc=ec;sc>=0;sc--){
            if(sr==er && sc==ec){
                 dp[sr][sc]=1;
                 continue;
            }
        
            int count=0;
            if(sr+1<=er){
                count+=dp[sr+1][sc];
            }
            if(sc+1<=ec){
                count+=dp[sr][sc+1];
            }
            if(sr+1<=er && sc+1<=ec){
                count+=dp[sr+1][sc+1];
            }
            dp[sr][sc]=count;

        }
    }
    return dp[0][0];
}

int boardpath(int sp,int ep ,vector<int> &dp){
    if(sp==ep){
        return dp[sp]=1;
    }
    if(dp[sp]!=0){
        return dp[sp];
    }
    int count=0;
    for(int dice=1;sp+dice<=ep &&dice<=6;dice++ ){
        count+=boardpath(sp+dice,ep,dp);
    }
    return dp[sp]=count;
}
int boardpathDp(int sp,int ep ,vector<int> &dp){
    for(sp=ep;sp>=0;sp--){
        if(sp==ep){
            dp[sp]=1;
            continue;
        }
        int count=0;
        for(int dice=1;sp+dice<=ep &&dice<=6;dice++ ){
            count+=dp[sp+dice];
            }
        dp[sp]=count;
        }

    return dp[0];
}

int boardpathDicearray(int sp,int ep,vector<int> &dp,vector<int> &arraydice){

if(sp==ep){
    return dp[sp]=1;
}
if(dp[sp]!=0){
    return dp[sp];
}
int count=0;
for(int dice=0;sp+arraydice[dice]<=ep && dice<arraydice.size();dice++){
    count+=boardpathDicearray(sp+arraydice[dice],ep,dp,arraydice);
}
return dp[sp]=count;
}

int boardPathWithDiceArrayDP(int sp, int ep, vector<int> &dp, vector<int> &diceArray)
{

    for (sp = ep; sp >= 0; sp--)
    {
        if (sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;
        for (int dice = 0; sp + diceArray[dice] <= ep && dice < diceArray.size(); dice++)
            count += dp[sp + diceArray[dice]]; //boardPath(sp + dice, ep, dp);
        dp[sp] = count;
    }

    return dp[0];
}

//////// leetcode 70

    
    int climbStairsdp(int n,vector<int> &dp) {
        if(n<=1){
            return dp[n]=1;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int count=0;
        count=climbStairsdp(n-1,dp)+climbStairsdp(n-2,dp);
        dp[n]=count;
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return climbStairsdp(n,dp);
     
    }
    int climbStairsdpp(int n,vector<int> &dp){
        int N=n;
        for(int n=0;n<=N;n++)
        {
        if(n<=1){
             dp[n]=1;
             continue;
        }
        int count=0;
        count=dp[n-1]+dp[n-2];
        dp[n]=count;
    }
        return dp[N];
    }

//////////leetcode 746
    int minCostClimbingStairs(int n,vector<int>& cost,vector<int>& dp) {
          if(n<=1){
            return dp[n]=cost[n];
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int ans=0;
        ans=min(minCostClimbingStairs(n-1,cost,dp),minCostClimbingStairs(n-2,cost,dp));
        dp[n]=ans+cost[n];
        return dp[n];
    }
    int minCostClimbingStairsDp(int i,vector<int>& cost,vector<int>& dp){
        for(int n=0;n<=i;n++){
                    if(n<=1){
                 dp[n]=cost[n];
                 continue;
                }
        
        int ans=0;
        ans=min(dp[n-1],dp[n-2]);
        dp[n]=ans+cost[n];
    }
    return dp[i];

        }
    


    
    
    /////// GFG pair program
    int pairprogram(int n, vector<int> &dp){
    if(n<=1){
        return dp[n]=1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int single=pairprogram(n-1,dp);
    int pair=pairprogram(n-2,dp)*(n-1);
    return dp[n]=pair+single;
}
int pairprogramDp(int n,vector<int> &dp){
    int N=n;
    for(int n=0;n<=N;n++){
       if(n<=1){
         dp[n]=1;
         continue;
    }

    int single=dp[n-1];
    int pair=dp[n-2]*(n-1);
     dp[n]=pair+single;
    }
    return dp[N];

}
//////////leetcode 64
 int minPathSum(int sr,int sc, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if(sr==grid.size()-1 && sc == grid[0].size() - 1){
            return dp[sr][sc]=grid[sr][sc];
        }
        if(dp[sr][sc]!=0){
            return dp[sr][sc];
        }
        int mincost=1e8;
        if(sr+1<grid.size()){
            mincost=min(mincost,minPathSum(sr+1,sc,grid,dp));
        }
        if(sc+1<grid[0].size()){
            mincost=min(mincost,minPathSum(sr,sc+1,grid,dp));
        }
        return dp[sr][sc]=mincost+grid[sr][sc];
        
    }
    int minPathSumDp(int sr,int sc, vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        for(sr=grid.size()-1;sr>=0;sr-- ){
            for(sc=grid[0].size()-1;sc>=0;sc--){
                if(sr==grid.size()-1 && sc == grid[0].size() - 1){
                 dp[sr][sc]=grid[sr][sc];
                 continue;
            }
               
                int mincost=1e8;
                if(sr+1<grid.size()){
                    mincost=min(mincost,dp[sr+1][sc]);
                }
                if(sc+1<grid[0].size()){
                    mincost=min(mincost,dp[sr][sc+1]);
                }
                 dp[sr][sc]=mincost+grid[sr][sc];
                    }
        }
        return dp[0][0];
    }

    /////////////////GFG gold mine problem
int goldmine(int sr,int sc, vector<vector<int>>& grid,vector<vector<int>>& dp)
{
    if(sc==grid[0].size()){
        return dp[sr][sc]=grid[sr][sc]; 
    }


    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int dir[3][2]={{-1,1},{0,1},{1,1}};
    int maxcoin=0;
    
    for(int d=0;d<3;d++){
        int x=sr+dir[d][0];
        int y=sc+dir[d][1];
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
            maxcoin=max(maxcoin,goldmine(x,y,grid,dp));
        }
    }
    return dp[sr][sc]=maxcoin+grid[sr][sc];

}
int goldmineDp(int sr,int sc, vector<vector<int>>& grid,vector<vector<int>>& dp)
{
    for(sr=grid.size()-1;sr>=0;sr--){
        for(sc=grid[0].size()-1;sc>=0;sc--){
              if(sc==grid[0].size()){
         dp[sr][sc]=grid[sr][sc]; 
         continue;
    }
    int dir[3][2]={{-1,1},{0,1},{1,1}};
    int maxcoin=0;
    for(int d=0;d<3;d++){
        int x=sr+dir[d][0];
        int y=sc+dir[d][1];
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
            maxcoin=max(maxcoin,goldmine(x,y,grid,dp));
        }
    }
     dp[sr][sc]=maxcoin+grid[sr][sc];

        }
    }
    return dp[0][0];

}
int waystocount(int n, int k,vector<vector<int>> &dp){
    if(n<k){
        return 0;
    }
    if(n==k||k==1){
        return dp[k][n]= 1;
    }
    if(dp[k][n]!=0) 
    {
    return dp[k][n];
    }

    int newgroup=waystocount(n-1,k-1,dp);
    int exisiting=waystocount(n-1,k,dp)*k;

    return dp[k][n]=newgroup+exisiting;
}

////////////Substring and subsequence 

vector<vector<bool>> palindromstring(string str,vector<vector<bool>> &dp){
    int n=str.length();
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap==0){
                dp[i][j]= false;
            }
            else if(gap==1 && str[i]==str[j]){
                dp[i][j]=true;
            }
            else{
                dp[i][j]=str[i]==str[j] && dp[i+1][j-1];
            }

        }
    }
    return dp;

}

string longestpalindromesubstr(string str){
 
     int n=str.length();
     vector<vector<int>> dp(n,vector<int>(n,0));

     int si,ei=0;
     int maxlen=0;
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap==0){
                dp[i][j]= 1;
            }
            else if(gap==1 && str[i]==str[j]){
                dp[i][j]=2;
            }
            else if(dp[i][j]=str[i]==str[j] && dp[i+1][j-1]){
                dp[i][j]=1+gap;
            }
            if(dp[i][j]>maxlen){
                maxlen=dp[i][j];
                si=i;
                ei=j;
            }

            

        }
    }
  return str.substr(si,(ei-si+1));


}

bool display(vector<vector<bool>> &dp){
for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp.size();j++){
        cout<<dp[i][j] << endl;
    }

}
}
    int longestPalindromeSubseq(string str ,int si, int ei, vector<vector<int>> & dp){
       
        if(si>ei){
            return 0;
        }
        if(si==ei){
            return dp[si][ei]=1;
        }
        if(dp[si][ei]!=0){
            return dp[si][ei];
        }
         int n =str.length();
        int len=0;
        if(str[si]==str[ei]){
            len=longestPalindromeSubseq(str,si+1,ei-1,dp)+2;
        }
        else{
            len=max(longestPalindromeSubseq(str,si+1,ei,dp),longestPalindromeSubseq(str,si,ei-1,dp));
        }
        return dp[si][ei]=len;


            }
 int longestPalindromeSubseqdp(string str,int si,int ei,vector<vector<int>> &dp){
        int n=str.length();
        for(int gap=0;gap<n;gap++){
            for(si=0,si=gap;si<n;si++,ei++){
                 if(si>ei){
                    return 0;
                }
                
                if(dp[si][ei]!=0){
                    return dp[si][ei];
                }
                int len=0;
                if(str[si]==str[ei]){
                    len=dp[si+1][ei-1]+2;
                }
                else{
                    len=max(dp[si+1][ei],dp[si][ei-1]);
                }
                 dp[si][ei]=len;


            }
            }
            return dp[0][n-1];
        }

 int numDistinct(string s,string t,int n, int m, vector<vector<int>> & dp){
       if(m==0){
           return 1;
       }
        if(m>n){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
      
        if(s[n-1]==t[m-1]){
          return dp[n][m]=numDistinct(s,t,n-1,m,dp)+numDistinct(s,t,n-1,m-1,dp);
        }
           return dp[n][m]= numDistinct(s,t,n-1,m,dp);
    }
     int numDistinctdp(string s,string t,int n, int m, vector<vector<int>> & dp){
      for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
              if(j==0){
             dp[i][j]= 1;
             continue;
       }
        if(j>i){
            dp[i][j]= 0;
            continue;
        }
       
      
        if(s[i-1]==t[j-1]){
          return dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
        else{
            dp[n][m]= dp[i-1][j];
        }
            

          }
      }
      return dp[n][m];
       
    }
    ///////leet 1143
 

    int longestCommonSubsequence(string text1, string text2,int i, int j,vector<vector<int>> & dp) {
      
        if(i==text1.length() || j==text2.length()){
            return  0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
        ans=longestCommonSubsequence(text1,text2,i+1,j+1,dp)+1;
        }
        else{
            ans=max(longestCommonSubsequence(text1,text2,i+1,j,dp),longestCommonSubsequence(text1,text2,i,j+1,dp));
        }
       
        return dp[i][j]=ans;
    }
     int longestCommonSubsequencedp(string text1, string text2,int i, int j,vector<vector<int>> & dp){
         for(i=text1.length();i>=0;i--){
             for(j=text2.length();j>=0;j--){
                    
                if(i==text1.length() || j==text2.length()){
                           continue;
                }
                        int ans=0;
                        if(text1[i]==text2[j]){
                        ans=dp[i+1][j+1]+1;
                        }
                        else{
                            ans=max(dp[i+1][j],dp[i][j+1]);
                        }
                    
                         dp[i][j]=ans;
                    }
             }
             return dp[0][0];
         }
     
    ///////////leetcode 1035

    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int m=B.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         for(int i=n;i>=0;i--){
             for(int j=m;j>=0;j--){
                    
                if(i==n || j==m){
                           continue;
                  }
                        int ans=0;
                        if(A[i]==B[j]){
                        ans=dp[i+1][j+1]+1;
                        }
                        else{
                            ans=max(dp[i+1][j],dp[i][j+1]);
                        }
                    
                         dp[i][j]=ans;
                    }
             }
             return dp[0][0];
         }
  //////////leetcode 1458
   int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                int val=nums1[i]*nums2[j];
                int a=dp[i+1][j+1]+val;
                int b=dp[i+1][j];
                int c=dp[i][j+1];
                dp[i][j]=max(max(a,b),max(val,c));
            }
        }
        return dp[0][0];
         
    }

//////////////////// coinchange/ target
int  coinChangePermutation(vector<int> &arr,int tar,vector<int> &dp){
    if(tar==0){
        return dp[tar]=1;
    }
    if(dp[tar]!=0){
        return dp[tar];
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(tar-arr[i]>=0){
             count+=coinChangePermutation(arr,tar-arr[i],dp);
        }
       
    }
    return dp[tar]=count;
}

int coinChangePermutationdp(vector<int> &arr,int tar,vector<int> &dp){
   dp[0]=1;
   for(int tar=0;;tar++){
       int count=0;
        for(int i=0;i<arr.size();i++){
        if(tar-arr[i]>=0){
             count+=coinChangePermutation(arr,tar-arr[i],dp);
        }  
    }
    dp[tar]=count;

   }
   return dp[tar];
}

///////////leetcode 322
int coinChange(vector<int>& coins, int amount,vector<int> &dp){
     if(amount==0){
        return dp[amount]=0;
    }
    if(dp[amount]!=0){
        return dp[amount];
    }
    int minheight=1e8;
    for(int i=0;i<coins.size();i++){
        if(amount-coins[i]>=0){
        int height=coinChangePermutation(coins,amount-coins[i],dp);
            if(height!=1e8 && height+1<minheight){
                minheight=height+1;
            }
        } 
     
    }
   return dp[amount]=minheight;
}

//////////Knapsack 0/1
int knapsack(int weight,vector<int> &price,vector<int> &w,int n,vector<vector<int>> &dp){
if(weight==0 || n==0){
    return 0;
}
if(dp[n][weight]!=0){
    return dp[n][weight];
}
int maxprofit=-1e8;
for(int i=0;i<w.size();i++){
    if(weight-w[i]>=0){
        maxprofit=max(maxprofit,knapsack(weight-w[n-1],price,w,n-1,dp)+price[n-1]);

    }
    maxprofit=max(maxprofit,knapsack(weight,price,w,n-1,dp));
}
return dp[n][weight]=maxprofit;
}

int knapsackUnbounded(int weight,vector<int> &price,vector<int> &w){
vector<int> dp(w.size()+1,-1e8);
dp[0]=0;
for(int i=0;i<w.size();i++){
    for(int tar=w[i];tar<=weight;tar++){
        dp[tar]=max(dp[tar],dp[tar-w[i]]+price[i]);
    }
}
return dp[w.size()];

}


/////////leetcode 416
 bool canPartition(vector<int>& nums) {
        
    }
bool canPartition_(vector<int>& nums,int n,int sum,vector<vector<int>> &dp) {
    
 
 
 
 
   }


   ////////// leetcode 72
      int minDistance(string word1, string word2) {
        
    }
       int minDistance(string word1, string word2,int n, int m,vector<vector<int>> &dp) {
        if(n==0||m==0){
            return dp[n][m]=(n==0?m:n);
        }
        if(dp[n][m]!=0){
            return dp[n][m];
        }
        if(word1[n-1]==word2[m-1]){
            return minDistance(word1,word2,n-1,m-1,dp);
        }
        int replace_=minDistance(word1,word2,n-1,m-1,dp);
        int delete_=minDistance(word1,word2,n-1,m,dp);
        int insert_=minDistance(word1,word2,n,m-1,dp);

         return dp[n][m] = min(min(insert_, replace_), delete_);
    }
/////////////LIS TYPE

int LIS_LtoR(vector<int> &arr,vector<int> &dp){
    int n=arr.size();
    int omax=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
               
            }
             omax=max(omax,dp[i]);
        }
        return omax;
}


int LIS_RtoL(vector<int> &arr,vector<int> &dp){
    int n=arr.size();
    int omax=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=1;
            for(int j=0;j<n;j++){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
               
            }
             omax=max(omax,dp[i]);
        }
        return omax;
}



//https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
//Longest bitonic subsequence
int LBS(vector<int> &arr){
    int n=arr.size();
    vector<int> LIS(n,0);
    vector<int> LDS(n,0);

    LIS_LtoR(arr,LIS);
    LIS_RtoL(arr,LDS);
    int maxlen=0;
    for(int i=0;i<n;i++)
        {
            int len=LIS[i]+LDS[i]-1;
            maxlen=max(maxlen,len);
        }

    return maxlen;

}

int MaxsumLIS(vector<int> &arr){
    vector<int> dp(arr.size(),0);
     int n=arr.size();
    int omax=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+arr[i]);
                }
               
            }
             omax=max(omax,dp[i]);
        }
        return omax;

}


//////leetcode354
 int maxEnvelopes(vector<vector<int>>& arr) {
     sort(arr.begin(),arr.end(),[](vector<int> &a,vector<int> &b){
         if(a[0]==b[0]){
             return b[1]<a[1];
         }
         return a[0]<b[0];
     });
     int n=arr.size();

     vector<int> dp(n,0);
    int omax=0;
     for(int i=0;i<n;i++){
         dp[i]=1;
         for(int j=i-1;j>=0;j--){
             if(arr[j][1]<arr[i][1])
                dp[i]=max(dp[i],dp[j]+1);
         }
          omax=max(omax,dp[i]);
     }
     return omax;
    
        
    }
////// leetcode 673
int findNumberOfLIS(vector<int>& arr) {
     int n=arr.size();
     if(n<=1)
        return n;
     vector<int> dp(n,0);
     vector<int> count(n,0);
    int maxlen=0;
    int maxcount = 0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            count[i]=1;
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    if(dp[j]+1>dp[i])
                       {
                            dp[i]=dp[j]+1;
                        count[i]=count[j];
                        }
                    else if (dp[j] + 1 == dp[i])
                        count[i] += count[j];
                }
              }
              if(maxlen<dp[i]){
                  maxlen=dp[i];
                  maxcount=count[i];

              }
              else if(dp[i]==maxlen){
                  maxcount+=count[i];
              }
       }
        return maxcount;
  
    }

////// Leetcode 91
int numDecodings(string s,int vidx,vector<int> &dp) {
          if(vidx==s.size()){
              return dp[vidx]=1;
          }
          if(dp[vidx]!=-1){
              return dp[vidx];
          }
        char ch=s[vidx];
        if(ch=='0'){
            return dp[vidx]=0;
        }
        int count=0;
        count+=numDecodings(s,vidx+1,dp);
        if(vidx<s.size()-1){
            int num=(ch-'0')*10+(s[vidx+1]-'0');
            if(num<=26){
                count+=numDecodings(s,vidx+2,dp);
                
            }
        }
        return dp[vidx]=count;
    }
//way 2 is to see and analyse the dp and start by taking 2 pointers and itirating the dp from behind


//https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/
int countSubsequences(string s){
    int acount=0;
    int bcount=0;
    int ccount=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            acount=acount+(1+acount);
        }
        else if(s[i]=='b'){
            bcount=bcount+(acount+bcount);
        }
        else{
            ccount=ccount+(bcount+ccount);
        }
    }
    return ccount;
}

//// leetcode 940 
   int distinctSubseqII(string s) {
      int mod = 1e9 + 7;
    s = '$' + s;
    int n = s.length();
    vector<long> dp(n,0);
    vector<int> last(26,-1);
    for(int i=0;i<n;i++){
        if(i==0){
             dp[i]=1;
             continue;
        }
        char ch=s[i];
        dp[i]=(dp[i-1]%mod*2)%mod;
        if(last[ch-'a']!=-1){
            dp[i]=dp[i]%mod-dp[last[ch-'a']-1]%mod+mod;
        }
        last[ch-'a']=i;


    }
    return dp[n-1]%mod-1;


    }






void knapsack(){
    vector<int> p = {100, 280, 120};
    vector<int> w = {10, 40, 20};
    int weight = 60;
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));

    cout << knapsackUnbounded(weight,p,w) << endl;
    cout << knapsack(weight, p,w,n,dp) << endl;

}


int coinChange()
{
    vector<int> arr{2, 3, 5, 7};
    int tar = 10;
    vector<int> dp(tar + 1, 0);
   return coinChangePermutation(arr, tar, dp);



}

/*int set3(){
    string str ="geeksforgeeks";
    int n=str.length();
    vector<vector<bool>> dp(n,vector<bool>(n,0));
      palindromstring(str,dp);
      display(dp);
      

} */  

int main(){
  
   //cout<< coinChange()<<endl;
    knapsack();
}
