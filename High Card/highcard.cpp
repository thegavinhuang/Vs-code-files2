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
int n,cnt;
vector<bool>b,e;
vector<int>bess,elie;
int main(){
    setIO("highcard");
    cin>>n;
    b.assign(n*2,true);
    e.assign(n*2,false);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        tmp--;
        e[tmp]=true;
        b[tmp]=false;
    }
    for(int i=0;i<n*2;i++){
        if(b[i]==true){
            bess.push_back(i);
        }
        else{
            elie.push_back(i);
        }
    }
    sort(bess.begin(),bess.end());
    sort(elie.begin(),elie.end());
    int l=0,r=0;
    while(l<n&&r<n){
        if(bess[l]>elie[r]){
            cnt++;
            l++;
            r++;
        }
        else{
            l++;
        }
    }
    cout<<cnt<<endl;
}