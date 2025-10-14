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
bool ok(vector<int>a,vector<int>b){
    for(int i=0;i<a.size();i++){
        if(a[i]>b[i]){
            return false;
        }
    }
    return true;
}
void solve(){
    set<string>key;
    vector<int>ned,hej;
    string needle,hay;
    int ans=0;
    cin>>needle>>hay;
    ned.assign(26,0);
    hej.assign(26,0);
    for(int i=0;i<needle.size();i++){
        ned[needle[i]-'a']++;
    }
    for(int i=0;i<needle.size();i++){
        hej[hay[i]-'a']++;
    }
    for(int i=needle.size();i<hay.size();i++){
        if(ok(ned,hej)){
            int tmp=key.size();
            key.insert(hay.substr(i-needle.size(),needle.size()));
            if(tmp!=key.size()){
                ans++;
            }
        }
        hej[hay[i-needle.size()]-'a']--;
        hej[hay[i]-'a']++;
    }
    if(ok(ned,hej)){
        int tmp=key.size();
        key.insert(hay.substr(hay.size()-needle.size(),needle.size()));
        if(tmp!=key.size()){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    setIO("C:\\Users\\kyler\\USACO\\Vjudge of 6.13.25\\A\\a");
    solve();
}