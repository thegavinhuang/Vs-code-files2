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
void solve(){
    int n;
    cin>>n;
    pair<int,int>mx;
    vector<int>arr;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mn=0;
    for(int i=0;i<n;i++){
        int sum=1;
        arr[i]++;
        for(int j=0;j<n;j++){
            sum*=arr[j];
        }
        mn=max(mn,sum);
        arr[i]--;
    }
    cout<<mn<<endl;
}
signed main(){
    setIO("C:\\Users\\kyler\\USACO\\Vjudge of 7.11.25\\A\\a");
    cin>>t;
    while(t--){
        solve();
    }
}