#include <bits/stdc++.h>
#define int long long
using namespace std;
void setIO(string file = "") {
  // speed up
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
struct dsu{
    vector<int>val;
    int islands;
    dsu(int n){val=vector<int>(n,-1),islands=n;}
    int get (int x){
        if(val[x]<0){
            return val[x];
        }
        return val[x]=get(val[x]);
    }
    void merge(int a,int b){
        int x=get(a),y=get(b);
        if(val[x]<val[y]){
            swap(x,y);
        }
        val[x]+=val[y];
        val[y]=x;
        islands--;
    }
};
int n,m,k;
vector<int>exploded,ans;
set<int>forexploded;
vector<pair<int,int>>arr,rem;
set<pair<int,int>>adj;
void clearit(){
    for(int i=0;i<rem.size();i++){
        adj.erase({rem[i].first,rem[i].second});
    }
    rem.clear();
}
signed main(){
    setIO("C:\\Users\\kyler\\USACO\\Star Wars\\sw");
    cin>>n>>m;
    arr.assign(m,{0,0});
    exploded.assign(n,0);
    for(int i=0;i<n;i++){
        forexploded.insert(i);
    }
    for(int i=0;i<m;i++){
        cin>>arr[i].first>>arr[i].second;
        adj.insert({arr[i].first,arr[i].second});
    }
    cin>>k;//i think so
    for(int i=0;i<k;i++){
        cin>>exploded[i];
        forexploded.erase(exploded[i]);
    }
    dsu planet(n);
    for(auto u:adj){
        if(forexploded.find(u.first)!=forexploded.end()&&forexploded.find(u.second)!=forexploded.end()){
            planet.merge(u.first,u.second);
            rem.push_back({u.first,u.second});
        }
    }
    clearit();
    int tmp=0;
    for(int i=0;i<n;i++){
        if(planet.val[i]<0&&forexploded.find(i)!=forexploded.end()){
            tmp++;
        }
    }
    ans.push_back(tmp);
    for(int i=k-1;i>=0;i--){
        forexploded.insert(exploded[i]);
        if(!adj.empty()){
            for(auto u:adj){
                if(forexploded.find(u.first)!=forexploded.end()&&forexploded.find(u.second)!=forexploded.end()){
                    planet.merge(u.first,u.second);
                    rem.push_back({u.first,u.second});
                }
            }
            clearit();
        }
        tmp=0;
        for(int j=0;j<n;j++){
            if(planet.val[j]<0&&forexploded.find(j)!=forexploded.end()){
                tmp++;
            }
        }
        ans.push_back(tmp);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }
    return 0;
}