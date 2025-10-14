#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int n,m,linec,t;
vector<pair<int,int>>tree,tree1;
vector<pair<pair<int,int>,int>>line;
vector<pair<pair<int,int>,pair<int,int>>>sec;
priority_queue<pair<int,int>>pq;
vector<bool>done;
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
bool cmp2(pair<pair<int,int>,pair<int,int>>a,pair<pair<int,int>,pair<int,int>>b){
  if(a.first.first==b.first.first){
    return a.first.second<b.first.second;//check this
  }
  return a.first.first>b.first.first;
}
int main(){
    setIO("p2");
    cin>>n>>m;
    tree1.assign(n,{0,0});
    tree.assign(n,{0,0});
    done.assign(m,false);
    sec.assign(m,{{0,0},{0,0}});
    line.assign(m*2+n,{{0,0},0});
    for(int i=0;i<n;i++){
      cin>>tree[i].first;
      tree[i].second=i;
      tree1[i].first=tree[i].first*-1;
      tree1[i].second=i;
      line[linec]={{tree[i].first,-1},-1};
      linec++;
    }
    sort(tree.begin(),tree.end());
    sort(tree1.begin(),tree1.end());
    for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      auto l=lower_bound(tree.begin(),tree.end(),make_pair(a,0));
      auto r=lower_bound(tree1.begin(),tree1.end(),make_pair(b*-1,0));
      int tmp=l-tree.begin();
      int tmp2=n-1-(r-tree1.begin());
      sec[i]={{a,b},{c,tmp2-tmp+1}};
      // line[linec]={{a,i},tmp2-tmp+1-c};
      // line[linec+1]={{b,i},-2};
      // linec+=2;
    }
    sort(sec.begin(),sec.end(),cmp2);
    for(int i=0;i<m;i++){
      line[linec]={{sec[i].first.first,i},sec[i].second.second-sec[i].second.first};
      line[linec+1]={{sec[i].first.second,i},-2};
      linec+=2;
    }
    sort(line.begin(),line.end(),cmp);
    int cnt=0;
    for(int i=0;i<line.size();i++){
      if(line[i].first.second==-1){
        while(!pq.empty()&&done[pq.top().second]==true){
          pq.pop();
        }
        if(pq.empty()){
          cnt++;
        }
        else if(pq.top().first+cnt<0){
          cnt++;
        }
      }
      else{
        if(line[i].second!=-2){
          pq.push({(line[i].second+cnt)*-1,line[i].first.second});
        }
        else{
          done[line[i].first.second]=true;
        }
      }
    }
    cout<<cnt<<endl;
}

/*
0
3
3
5
4
4
3
4
3
3
4
3
1
1
2
2
1
4
10
3

20

4 2
0 1 3 5
0 3 2
0 5 4

5 1
0 0 4 4 6
0 4 2

7 3
0 1 2 3 4 5 6
0 3 1
0 3 4
0 3 2

8 4
1 2 3 4 5 6 7 8
1 3 1
2 4 2
4 6 2
3 5 1

7 1
8 4 10 1 2 6 7
2 9 3

7 2
8 4 10 1 2 6 7
2 9 3
1 10 1

7 2
8 4 10 1 2 6 7
2 9 3
1 10 4

9 3
-5 -3 -1 1 2 3 6 7 9
-1 6 3
-4 4 1
-5 8 5

6 3
0 1 2 3 5 2000
0 5 3
0 3 2
0 2 1

6 5
0 2 3 6 9 12
0 1 0
2 3 0
0 13 1
8 9 1
3 11 3


10 7
-5 -4 -2 0 5 6 8 8 10 12
-5 -2 2
6 7 1
6 11 3
1 6 1
-4 3 3
-1 4 0
8 11 2

8 4
3 5 3 2 3 0 -1 1
-4 -2 0
-1 3 2
-3 2 3
3 5 2

8 4
-5 -3 4 -1 3 1 -3 3
3 5 1
-3 1 2
-3 -1 3
-5 3 7

6 4
4 1 2 -4 -2 0
-4 -2 2
0 1 2
-3 1 1
2 5 1

8 8
1 2 3 3 4 7 7 9
1 2 1
1 2 2
3 5 2
6 8 0
6 7 1
6 8 2
7 8 2
6 8 0

9 9
-3 0 0 1 2 3 5 6 6
1 2 2
-4 -3 1
4 6 2
7 8 0
3 4 1
5 7 1
0 1 2
-3 -1 1
-2 -1 0

5 3
1 3 3 6 5
1 3 3
4 5 1
2 6 2

9 5
1 2 4 7 6 7 6 7 9
1 3 2
1 4 1
4 9 3
1 4 3
1 9 4

12 4
-5 20000 6 8 7 -5 -4 -5 -4 3 1 7
-3 1 1
3 5 0
-3 5 2
-3 -1 0

13 13
-4 -4 -2 0 2 3 5 6 6 9 8 12 11
-4 -3 1
-2 0 1
1 2 1
4 5 1
6 8 2
9 10 0
11 12 1
-4 -3 1
-1 0 0
1 3 2
5 6 3
7 8 1
9 10 1
*/