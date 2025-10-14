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
int n,tmp=2;
string needle,hay;
vector<int>abc;
int hashf(string str){
    int val=1;
    for(int i=0;i<str.size();i++){
        val*=10007+2*(str[i]-'a')%tmp;
    }
    val/=2;
    return val;
}
void solve(){
    abc.assign(26,0);
    int ans=0;
    set<string>key;
    n=hashf(needle);
    int t=hashf(hay.substr(0,needle.size()));
    for(int i=0;i<hay.size()-needle.size()+1;i++){
        if(t==n){
            int r=key.size();
            key.insert(hay.substr(i,needle.size()));
            if(r!=key.size()){
                ans++;
            }
        }
        t*=10007+(2*(hay[i+needle.size()]-'a')%tmp);
        t/=10007+(2*(hay[i]-'a')%tmp);
    }
    cout<<ans<<endl;
    return;
}
signed main(){
    setIO("C:\\Users\\kyler\\USACO\\Vjudge of 6.13.25\\A\\a");
    tmp=(tmp<<61)-1;
    cin>>needle>>hay;
    solve();
}