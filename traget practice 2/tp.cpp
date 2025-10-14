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
int t,n,x1,pos,neg,up;
vector<pair<int,pair<int,int>>>target;//y1,y2,x2
vector<int>front;
vector<int>slopes;
bool cmp(int a,int b){
    return a>b;
}
bool ok(int m){
    vector<double>uh;
    int cop=pos;
    for(int i=0;i<n;i++){
        double a=target[i].second.first-m;
        if(target[i].second.second==0){a=0;}
        else{a/=target[i].second.second;}
        uh.push_back(a);
        cop--;
    }
    int tmp=0;
    for(int i=0;i<n*2;i++){
        if(cop==0){
            break;
        }
        double b=front[tmp]-m;
        if(x1==0){b=0;}
        else{b/=x1;}
        cop--;
        tmp++;
        uh.push_back(b);
        if(cop==0){
            break;
        }
        double c=front[tmp]-m;
        if(x1==0){c=0;}
        else{c/=x1;}
        cop--;
        tmp++;
        uh.push_back(c);
    }
    sort(uh.begin(),uh.end());
    for(int i=0;i<pos;i++){
        if(uh[i]>slopes[i]){
            return false;
        }
    }
    return true;
}
bool ok2(int m){
    vector<double>uh;
    int cop=neg;
    for(int i=0;i<n;i++){
        double a=target[i].first-m;
        if(target[i].second.second==0){a=0;}
        else{a/=target[i].second.second;}
        uh.push_back(a);
        cop--;
    }
    int tmp=0;
    for(int i=0;i<n*2;i++){
        if(cop==0){
            break;
        }
        double b=front[tmp]-m;
        if(x1==0){b=0;}
        else{b/=x1;}
        cop--;
        tmp++;
        uh.push_back(b);
        if(cop==0){
            break;
        }
        double c=front[tmp]-m;
        if(x1==0){c=0;}
        else{c/=x1;}
        cop--;
        tmp++;
        uh.push_back(c);
    }
    sort(uh.begin(),uh.end(),cmp);
    for(int i=0;i<neg;i++){
        if(uh[i]<slopes[i]){
            return false;
        }
    }
    return true;
}
void solve(){
    cin>>n>>x1;
    target.assign(n,{0,{0,0}});
    front.assign(n*2,0);
    slopes.assign(4*n,0);
    pos=0;neg=0;
    int thebigone=0;
    for(int i=0;i<n;i++){
        cin>>target[i].first>>target[i].second.first>>target[i].second.second;
        thebigone=max(thebigone,target[i].second.first);
        front[i]=target[i].first;
        front[n*2-i-1]=target[i].second.first;
    }
    sort(front.begin(),front.end());
    for(int i=0;i<4*n;i++){
        cin>>slopes[i];
        if(slopes[i]>0){pos++;}
        else{neg++;}
    }
    if(pos>3*n||neg>3*n){
        cout<<-1<<endl;
        return;
    }
    sort(slopes.begin(),slopes.end());
    int l=thebigone,r=7*1e18;
    while(l<r){
        int m=l+(r-l)/2;
        if(ok(m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    int up=r;
    sort(front.begin(),front.end(),cmp);
    sort(slopes.begin(),slopes.end(),cmp);
    l=-7*1e18,r=thebigone;
    while(l<r){
        int m=l+(r-l)/2+1;
        if(ok2(m)){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    //.cout<<r<<endl;
    cout<<up-r<<endl;
}
signed main(){
    setIO();
    cin>>t;
    while(t--){
        solve();
    }
}
//918957089641524701