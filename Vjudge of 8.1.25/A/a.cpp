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
    int n,m;
    vector<string>arr;
    cin>>n>>m;
    arr.assign(n,"");
    pair<int,int>a,b,c,d;
    a={-1,-1};
    b={-1,-1};
    c={-1,-1};
    d={-1,-1};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='B'){
                if(a.first==-1||i+j>a.first+a.second){
                    a={i,j};
                }
                if(b.first==-1||i+j<b.first+b.second){
                    b={i,j};
                }
                if(c.first==-1||i-j>c.first-c.second){
                    c={i,j};
                }
                if(d.first==-1||i-j<d.first-d.second){
                    d={i,j};
                }
            }
        }
    }
    vector<pair<int,int>>tmp;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
    tmp.push_back(d);
    int ans=INT_MAX;
    pair<int,int>best;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int dist=0;
                for(int k=0;k<4;k++){
                    dist=max(dist,abs(tmp[k].first-i)+abs(tmp[k].second-j));
                }
                if(dist<ans){
                    ans=dist;
                    best={i,j};
                }
        }
    }
    cout<<best.first+1<<" "<<best.second+1<<endl;
}
signed main(){
    setIO("C:\\Users\\kyler\\USACO\\Vjudge of 8.1.25\\A\\a");
    cin>>t;
    while(t--){
        solve();
    }
}