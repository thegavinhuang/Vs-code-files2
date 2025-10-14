#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
#define int long long
int n,best,t,sum;
vector<int>arr,pre;
signed main(){
    setIO();
    cin>>t;
    while(t--){
      cin>>n;
      pre.assign(n+1,0);
      arr.assign(n+1,0);
      for(int i=1;i<=n;i++){
        cin>>arr[i];
        pre[i]=pre[i-1]+arr[i];
        sum+=arr[i];
      }
      int l=0,r=n/2-1;
      while(l!=n/2){
        int tmp=0;
        tmp+=pre[n]-pre[n-r];
        tmp+=pre[l];
        best=max(best,tmp);
        l++;
        r--;
      }
      cout<<sum-best<<" "<<best<<endl;
      best=0;
      sum=0;
    }
}