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
int n;
vector<int>arr,c,dps,dpl,dpe,val;
vector<int>compressed;
vector<int>queries;
void compress(){
    vector<int>b;
    b=queries;
    for(int i=0;i<arr.size();i++){
        b.push_back(arr[i]);
    }
    sort(queries.begin(),queries.end());
    b.resize(unique(b.begin(),b.end())-b.begin());
    for(int i=0;i<b.size();i++){
        compressed[i]=lower_bound(b.begin(),b.end(),compressed[i])-b.begin();
    }
}
void update(int s,int m){
    int l=s*2,r=s*2+1;
    if(s==0){
        return;
    }
    if(l>n){
        dps[s]=(arr[s]>=m)*c[s];
        dpl[s]=(arr[s]<=m)*c[s];
        dpe[s]=(arr[s]!=m)*c[s];
        return;
    }
    dps[s]=min(dps[l]+dps[r],  min(dps[l]+(arr[s]>=m)*c[s],  dps[r]+(arr[s]>=m)*c[s]));//wait .. ?
    dpl[s]=min(dpl[l]+dpl[r],  min(dpl[l]+(arr[s]<=m)*c[s],  dpl[r]+(arr[s]<=m)*c[s]));

    dpe[s]=min({dpe[l]+dpe[r], dps[l]+dpl[r]+(arr[s]!=m)*c[s], dpl[l]+dps[r]+(arr[s]!=m)*c[s],
                dpe[l]+min(dpl[r]+(arr[s]>m)*c[s], dps[r]+(arr[s]<m)*c[s]), 
                dpe[r]+min(dpl[l]+(arr[s]>m)*c[s], dps[l]+(arr[s]<m)*c[s])});
    update(s/2,m);
}
void getdpall(int s,int m){
    int l=s*2,r=s*2+1;
    if(l>n){
        dps[s]=(arr[s]>=m)*c[s];
        dpl[s]=(arr[s]<=m)*c[s];
        dpe[s]=(arr[s]!=m)*c[s];
        return;
    }

    getdpall(l,m);
    getdpall(r,m);
    dps[s]=min(dps[l]+dps[r],  min(dps[l]+(arr[s]>=m)*c[s],  dps[r]+(arr[s]>=m)*c[s]));//wait .. ?
    dpl[s]=min(dpl[l]+dpl[r],  min(dpl[l]+(arr[s]<=m)*c[s],  dpl[r]+(arr[s]<=m)*c[s]));

    dpe[s]=min({dpe[l]+dpe[r], dps[l]+dpl[r]+(arr[s]!=m)*c[s], dpl[l]+dps[r]+(arr[s]!=m)*c[s],
                dpe[l]+min(dpl[r]+(arr[s]>m)*c[s], dps[r]+(arr[s]<m)*c[s]), 
                dpe[r]+min(dpl[l]+(arr[s]>m)*c[s], dps[l]+(arr[s]<m)*c[s])});
}
signed main(){
    setIO();
    cin>>n;
    c.assign(n+1,0);
    arr.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i]>>c[i];
    }
    int q;
    cin>>q;
    queries.assign(q,0);
    compressed.assign(n+q,0);
    for(int i=0;i<q;i++){
        cin>>queries[i];
        compressed[i]=queries[i];
    }
    for(int i=q;i<q+n;i++){
        compressed[i]=arr[i];
    }
    dps.assign(n+1,-1);
    dpl.assign(n+1,-1);
    dpe.assign(n+1,-1);
    compress();
    getdpall(1,0);
    sort(queries.begin(),queries.end());
    for(int i=0;i<q;i++){
        update(,queries[i]);
    }
}