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
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
int n,m;
signed main(){
    setIO("C:\\Users\\kyler\\USACO\\Milk Pumping\\mp");
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
    }
}