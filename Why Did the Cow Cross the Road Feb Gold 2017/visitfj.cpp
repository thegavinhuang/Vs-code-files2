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
int n,t;
vector<vector<int>>arr;
vector<vector<int>>dist;
int dx[] = {3,2,1,0,-1,-2,-3,-2,-1, 0,1, 2,  1, 0,-1, 0};
int dy[] = {0,1,2,3, 2, 1, 0,-1,-2,-3,-2,-1,  0, 1, 0,-1};
bool inbound(int x,int y){
    return x>=0&&y>=0&&x<n&&y<n;
}
void dk(){
    dist[0][0]=0;
    priority_queue<pair<int,pair<int,int>>>pq;//val,x,y,
    pq.push({arr[0][0],{0,0}});
    while(!pq.empty()){
        pair<int,pair<int,int>>a=pq.top();
        pq.pop();
        int xx=a.second.first;
        int yy=a.second.second;
        int tmp=abs((n-1)-xx)+abs(n-1-yy);
        if(tmp==3){
            dist[n-1][n-1]=min(arr[n-1][n-1]+dist[xx][yy]+3*t,dist[n-1][n-1]);
        }
        else if(tmp<3){
            dist[n-1][n-1]=min(dist[xx][yy]+t*tmp,dist[n-1][n-1]);
        }
        //if thingy for end thingy
        for(int i=0;i<16;i++){
            int xp=a.second.first+dx[i];
            int yp=a.second.second+dy[i];
            if(inbound(xp,yp)){
                if(dist[xx][yy]+3*t+arr[xp][yp]<dist[xp][yp]){
                    dist[xp][yp]=dist[xx][yy]+3*t+arr[xp][yp];
                    pq.push({-dist[xp][yp],{xp,yp}});
                }
            }
        }
    }
}
signed main(){
    setIO("visitfj");
    cin>>n>>t;
    arr.assign(n,vector<int>(n,0));
    dist.assign(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    dk();
    cout<<dist[n-1][n-1]<<endl;
}
/*
https://github.com/cs4fun-classRepos/tue7pm/blob/main/5-6-2025-dijstra-exercises/2017-Feb-P1-Why-did-the-cow-cross-the-road/template.cpp
*/