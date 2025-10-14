#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "") {
  // speed up
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int n;
string str;
vector<int>dp;
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
void filldp(int s){
  int sum=0;
  
  if(isPowerOfTwo(s)){
    dp[s];
  }
}
signed main(){
    setIO("C:\\Users\\kyler\\USACO\\Interstellar Intervals\\iicaptain");
    cin>>n>>str;
    dp.assign(n+1,-1);
    dp[0]=1;
    dp[1]=0;
    filldp(n);
}