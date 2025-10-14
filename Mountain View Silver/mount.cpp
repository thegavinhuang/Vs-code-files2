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
int n,big,cnt;
vector<pair<int,int>>arr;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first-a.second==b.first-b.second){
        return a.first+a.second>b.first+b.second;
    }
    return a.first-a.second<b.first-b.second;
}
signed main(){
    setIO("mountains");
    cin>>n;
    arr.assign(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<n;i++){
        if(arr[i].first+arr[i].second>big){
            big=arr[i].first+arr[i].second;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}