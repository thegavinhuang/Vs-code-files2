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
bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
  if(a.first.first==b.first.first){
    if(a.first.second!=-1&&a.second!=-2){
      if(b.first.second==-1){
        return 0<1;
      }
      if(b.first.second!=-1&&b.second==-2){
        return 0<1;
      }
      if(b.first.second!=-1&&b.second!=-2){
        a.second>b.second;
      }
    }
    if(a.first.second!=-1&&a.second==-2){
      if(b.first.second==-1){
        return 0>1;
      }
      if(b.first.second!=-1&&b.second!=-2){
        return 0>1;
      }
      if(b.first.second!=-1&&b.second==-2){
        a.second<b.second;
      }
    }
    if(a.first.second==-1){
      if(b.first.second!=-1&&b.second==-2){
        return 0<1;
      }
      if(b.first.second!=-1){
        return 0>1;
      }
    }
  }
  return a.first.first<b.first.first;
}
int main(){
    setIO("p2");
    vector<pair<pair<int,int>,int>>line;
    line.assign(16,{{0,0},0});
    line[2]={{3,-1},-1};
    line[12]={{3,2},2};
    line[11]={{4,-1},-2};
    line[9]={{3,0},-2};
    line[3]={{4,-1},-1};
    line[7]={{8,-1},-1};
    line[6]={{7,-1},-1};
    line[15]={{6,3},-2};
    line[5]={{6,-1},-1};
    line[13]={{5,2},-2};
    line[4]={{5,-1},-1};
    line[14]={{4,3},1};
    line[10]={{2,1},1};
    line[0]={{1,-1},-1};
    line[8]={{1,0},2};
    line[1]={{2,-1},-1};

    // line[0]={{3,-1},-1};
    // line[1]={{3,2},2};
    // line[2]={{4,-1},-2};
    // line[3]={{3,0},-2};
    // line[4]={{4,-1},-1};
    // line[5]={{8,-1},-1};
    // line[6]={{7,-1},-1};
    // line[7]={{6,3},-2};
    // line[8]={{6,-1},-1};
    // line[9]={{5,2},-2};
    // line[10]={{5,-1},-1};
    // line[11]={{4,3},1};
    // line[12]={{2,1},1};
    // line[13]={{1,-1},-1};
    // line[14]={{1,0},2};
    // line[15]={{2,-1},-1};
    sort(line.begin(),line.end(),cmp);
    for(int i=0;i<line.size();i++){
        cout<<line[i].first.first<<" "<<line[i].first.second<<" "<<line[i].second<<endl;
    }
}
/*
9 3
-5 -3 -1 1 2 3 6 7 9
-1 6 3
-4 4 1
-5 8 5

    line[2]={{3,-1},-1};
    line[12]={{3,2},2};
    line[11]={{4,-1},-2};
    line[9]={{3,0},-2};
    line[3]={{4,-1},-1};
    line[7]={{8,-1},-1};
    line[6]={{7,-1},-1};
    line[15]={{6,3},-2};
    line[5]={{6,-1},-1};
    line[13]={{5,2},-2};
    line[4]={{5,-1},-1};
    line[14]={{4,3},1};
    line[10]={{2,1},1};
    line[0]={{1,-1},-1};
    line[8]={{1,0},2};
    line[1]={{2,-1},-1};
*/