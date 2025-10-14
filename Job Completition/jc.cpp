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
int testc;
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>arr;
    arr.assign(n,{0,0});
    priority_queue<int>doop;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        arr[i].first+=arr[i].second;
    }
    sort(arr.begin(),arr.end());
    int t=0,ans=0;
    for(int i=0;i<n;i++){
        if(t+arr[i].second<=arr[i].first){
            doop.push(arr[i].second);
            t+=arr[i].second;
            ans++;
        }
        else{
            if(!doop.empty()&&arr[i].second<doop.top()){// >??
                int loog=doop.top();
                doop.pop();
                doop.push(arr[i].second);
                t-=(loog-arr[i].second);
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    setIO();
    cin>>testc;
    while(testc--){
        solve();
    }
}