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
int t;
void solve(){
    int n;
    cin>>n;
    vector<int>arr;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<int>in,tmp;
    in.insert(arr[0]);
    tmp.insert(arr[0]);
    int i=1,ans=0;
    while(!(i>=n)){
        while(!in.empty()){
            if(i>=n){
                cout<<ans+1<<endl;
                return;
            }
            if(in.find(arr[i])!=in.end()){
                in.erase(arr[i]);
            }
            tmp.insert(arr[i]);
            i++;
        }
        ans++;
        in=tmp;
    }
    cout<<ans+1<<endl;
}
int main(){
    setIO("C:\\Users\\kyler\\USACO\\Vjudge of 6.13.25\\A\\b");
    cin>>t;
    while(t--){
        solve();
    }
}