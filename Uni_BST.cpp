

// Count Unique BST

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int numTrees(int N) 
{
        vector<long long>dp(N+1,0);
        
        dp[0]=dp[1]=1;
        
		
        for(int i=2 ; i<=N ; i++ ){
           
            for(int j=0;j<i;j++){
           
				      dp[i] = ((dp[i]%1000000007) + (dp[j] * dp[i-j-1])%1000000007)%1000000007 ;
           
		        }
        }
		
        return dp[N]%1000000007;
        // Your code here
 }
 
 int main(){
  int n;
  cin >> n;
  
  cout << numTrees(n);
  
 }
