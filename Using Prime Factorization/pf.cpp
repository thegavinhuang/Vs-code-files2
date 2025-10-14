#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size())) {
      freopen((file + ".in").c_str(), "r", stdin);
      freopen((file + ".out").c_str(), "w", stdout);
    }
}
int n;
vector<int>ans;
int main(){
    cin>>n;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            ans.push_back(i);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    if(n!=1){
        cout<<n<<endl;
    }
}