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
int t,n,a;
vector<pair<int,int>>needpos,needneg,both;
vector<int>pos,neg;
vector<pair<long long,long long>>slope;
bool cmp(int a,int b){
  return a>b;
}
bool cmp1(pair<int,int>a,pair<int,int>b){
  return a.second>b.second;
}
bool cmp2(pair<long long,long long>a,pair<long long,long long>b){
  return a.first/a.second<b.first/b.second;
}
bool cmp3(pair<long long,long long>a,pair<long long,long long>b){
  return a.first/a.second>b.first/b.second;
}
bool cmp4(pair<int,int>a,pair<int,int>b){
  if(a.second==b.second){
    return a.first<b.first;
  }
  return a.second<b.second;
}
bool cmp5(pair<int,int>a,pair<int,int>b){
  if(a.second==b.second){
    return a.first>b.first;
  }
  return a.second>b.second;
}
bool ok(long long m){
  slope.clear();
  for(int i=0;i<needpos.size();i++){
    slope.push_back({needpos[i].second-m,needpos[i].first});
  }
  //sort(slope.begin(),slope.end(),cmp2);
  for(int i=0;i<pos.size();i++){
    if(slope[i].first/slope[i].second<pos[i]){
      return true;
    }
  }
  return false;
}
bool ok1(long long m){
  slope.clear();
  for(int i=0;i<needneg.size();i++){
    slope.push_back({needneg[i].second-m,needneg[i].first});
  }
  //sort(slope.begin(),slope.end(),cmp3);
  for(int i=0;i<neg.size();i++){
    if(slope[i].first/slope[i].second>neg[i]){
      return false;
    }
  }
  return true;
}
int main(){
  setIO("tp2");
  cin>>t;
  while(t--){
    cin>>n>>a;
    pos.clear();
    neg.clear();
    needpos.resize(n,{0,0});
    needneg.resize(n,{0,0});
    both.resize(2*n,{0,0});
    int eep=0;
    for(int i=0;i<n;i++){
      int b,c,d;
      cin>>b>>d>>c;
      needpos[i]={c,b};
      needneg[i]={c,d};
      both[eep]={a,b};
      both[eep+1]={a,d};
      eep+=2;
    }
    for(int i=0;i<4*n;i++){
      int tmp;
      cin>>tmp;
      if(tmp>0){
        pos.push_back(tmp);
      }
      else{
        neg.push_back(tmp);
      }
    }
    if(pos.size()<n||neg.size()<n){
      cout<<-1<<endl;
      continue;
    }
    sort(pos.begin(),pos.end());
    sort(needpos.begin(),needpos.end(),cmp4);
    sort(needneg.begin(),needneg.end(),cmp5);
    sort(neg.begin(),neg.end(),cmp);
    sort(both.begin(),both.end(),cmp1);
    for(int i=0;i<pos.size()-n;i++){
      needpos.push_back(both[i]);
    }
    for(int i=pos.size()-n;i<2*n;i++){
      needneg.push_back(both[i]);
    }
    long long maxl=-5*1e18,maxr=1e17;
    while(maxl<maxr){
      long long m=maxl+(maxr-maxl+1)/2;
      if(ok(m)){
        maxr=m-1;
      }
      else{
        maxl=m;
      }
    }
    long long minl=0,minr=1e17;
    while(minl<minr){
      long long m=minl+(minr-minl)/2;
      if(ok1(m)){
        minr=m;
      }
      else{
        minl=m+1;
      }
    }
    cout<<minr-maxr<<endl;
  }
}