#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "")
{
    // speed up
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size()))
    {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int n,m;
vector<int>arr;
int main(){
    setIO("mo");
    cin>>n>>m;
    arr.assign(n,0);
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++){
            int b;
            cin>>b;
            arr[a].push_back(b);
        }
    }
    cout<<"e";
}