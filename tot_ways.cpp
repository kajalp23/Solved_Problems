/*
Given total distance - tot_dist
At most number of steps we can take - max_step array
we have to find number of ways to reach the tot_dist if at most steps are max_step[i] where i is index

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_recurr(int step,int dist){
     if(dist==0)
        return 1;
    if(dist==1)
        return 1;
    int cnt=0;
    for(int i=1;i<=step && i<=dist;i++){
        cnt+=count_recurr(step,dist-i);
    }
    return cnt;
    
}

int count(int step,int dist,vector<int>&dp){
    if(step==0)
        return 1;
    if(step==1)
        return 1;
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=dist;i++){
        dp[i]=0;
        for(int j=1;j<=step && j<=i;j++){
            dp[i]+=dp[i-j];
        }
    }

    return dp[dist];

}

int main() {
    int tot_dist;
    cin >> tot_dist;
    int m;
    cin >> m;
    int max_step[m];
    for(int i=0;i<m;i++)
        cin >> max_step[i];

    vector<int>dp(tot_dist+1,0);
  
//First Method
    for(int i=0;i<m;i++){
        cout << count(max_step[i],tot_dist,dp) << " ";
    }
    cout << endl;
  
 //Second Method

    for(int i=0;i<m;i++){
        cout << count_recurr(max_step[i],tot_dist) << " ";
    }
    
}
