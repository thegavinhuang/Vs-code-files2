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
int main() {
    ifstream myFile("C:\\Users\\kyler\\.vscode\\USACO\\jeepers\\songs.txt");
    if (!myFile.is_open()) {
        cout<<"issue occured";
        return 0;
    }
    unordered_map<string, unordered_map<string, string>> songs;

    string line;
    // read in every line and store it
    while (getline(myFile, line)) {
        stringstream ss(line);
        string title, plays, album;
        getline(ss, title, ',');
        getline(ss, plays, ',');
        getline(ss, album, ',');
        plays.erase(0,1);
        album.erase(0,1);
        // if unordered_map already has this title
        if (songs.find(title) != songs.end()) {
            songs[title][album] = plays;
        } else {
            unordered_map<string, string> details;
            details[album] = plays;
            songs[title] = details;
        }
    }
    myFile.close();
    cout<<songs["Poker Face"]["The Fame"]<<endl;
    string t, a;
    while (true) {
        cout << "Please enter a song title:" << endl;
        getline(cin, t);

        cout << "Please enter a song album:" << endl;
        getline(cin, a);

        if (songs.find(t) != songs.end() && songs[t].find(a) != songs[t].end()) {
            string plays = songs[t][a];
            cout << plays << endl;
        } else if (songs.find(t) != songs.end() && songs[t].find(a) == songs[t].end()) {
            cout << "The ALBUM you entered is invalid." << endl;
        } else if (songs.find(t) == songs.end()) {
            cout << "The TITLE you entered is invalid." << endl;
        } else {
            cout << "The TITLE AND ALBUM you entered is invalid." << endl;
        }
    }
    // catch (exception& e) {
    //     cout << e.what() << endl;
    // }
}

/*
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
int n,q;
vector<pair<int,int>>adj[10100];
vector<vector<int>>dp;
vector<int>in;
void dfs(int s,int p){
    if(adj[s].size()==1){
        //leaf
    }
    for(auto u:adj[s]){
        dfs(u.first,s);
    }
}
int cnt(int s,int p){
    if(adj[s].size()==1){
        return 1;
    }
    for(auto u:adj[s]){
        in[s]=cnt(u.firsy,s);
    }
    return in[s]+1;
}
int main(){
    setIO("at");
    cin>>n>>q;
    dp.assign(n+1,0);
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    ;
}
*/