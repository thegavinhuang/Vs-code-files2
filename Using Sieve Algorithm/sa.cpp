#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size())) {
      freopen((file + ".in").c_str(), "r", stdin);
      freopen((file + ".out").c_str(), "w", stdout);
    }
}
vector<int>s;
int main(){
    //setIO("sa");
    s.assign(1e6,0);
    for(int i=2;i<=100;i++){
        if(s[i]){
            continue;
        }
        for(int j=2*i;j<=100;j+=i){
            s[j]=i;
        }
    }
    for(int i=2;i<=100;i++){
        if(s[i]==0){
            cout<<i<<endl;
        }
    }
}