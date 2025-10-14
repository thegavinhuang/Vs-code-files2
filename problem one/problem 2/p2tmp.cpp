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
    if(a.first.second!=-2e9&&a.second!=-2){
      if(b.first.second==-2e9){
        return 0<1;
      }
      if(b.first.second!=-2e9&&b.second==-2){
        return 0<1;
      }
      if(b.first.second!=-2e9&&b.second!=-2){
        a.second>b.second;
      }
    }
    if(a.first.second!=-2e9&&a.second==-2){
      if(b.first.second==-2e9){
        return 0>1;
      }
      if(b.first.second!=-2e9&&b.second!=-2){
        return 0>1;
      }
      if(b.first.second!=-2e9&&b.second==-2){
        a.second<b.second;
      }
    }
    if(a.first.second==-2e9){
      if(b.first.second!=-1&&b.second==-2){
        return 0<1;
      }
      if(b.first.second!=-2e9){
        return 0>1;
      }
    }
  }
  return a.first.first<b.first.first;
}
bool cmp2(pair<pair<int,int>,pair<int,int>>a,pair<pair<int,int>,pair<int,int>>b){
  if(a.first.first==b.first.first){
    return a.first.second<b.first.second;
  }
  return a.first.first>b.first.first;
}
int main(){
    setIO();
    cin>>t;
    while(t--){
        cin>>n>>m;
        tree1.assign(n,{0,0});
        tree.assign(n,{0,0});
        done.assign(m,false);
        sec.assign(m,{{0,0},{0,0}});
        line.assign(m*2+n,{{0,0},0});
        linec=0;
        for(int i=0;i<n;i++){
            cin>>tree[i].first;
            tree[i].second=i;
            tree1[i].first=tree[i].first*-1;
            tree1[i].second=i;
            line[linec]={{tree[i].first,-2e9},-2e9};
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
            if(line[i].first.second==-2e9){
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
        while(!pq.empty()){
            pq.pop();
        }
    }
}