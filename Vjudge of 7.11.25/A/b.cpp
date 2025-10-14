#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  // speed up
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
#define int long long
int t;
int sub[]={6,10,14,15,21,35,210};
int add[]={2,3,5,7,30,42,70,105};
void solve(){
    int l,r,sum=0;
    cin>>l>>r;
    for(int i=0;i<7;i++){
        sum-=(r/sub[i])-((l-1)/sub[i]);
    }
    for(int i=0;i<8;i++){
        sum+=(r/add[i])-((l-1)/add[i]);
    }
    cout<<(r-l+1)-sum<<endl;
}
signed main(){
    setIO("C:\\Users\\kyler\\USACO\\Vjudge of 7.11.25\\A\\a");
    cin>>t;
    while(t--){
        solve();
    }
}