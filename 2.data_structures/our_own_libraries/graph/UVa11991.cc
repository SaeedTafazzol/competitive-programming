#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,m;
    while(cin>>n>>m){
        set<pair<int,int>> arr;
        vector<vector<int>> idx;
        for(int i  = 0;i<n;i++){
            int d;
            cin>>d;
            auto it = arr.upper_bound(make_pair(d,-1));
            if(it!=arr.end() && it->first==d){
                idx[it->second].push_back(i);
            }else{
                idx.push_back(vector<int>(0));
                arr.insert(make_pair(d,idx.size()-1));
                idx[idx.size()-1].push_back(i);

            }

        }

        for(int i = 0;i<m;i++){
            int k,v;
            cin>>k>>v;
            auto it = arr.upper_bound(make_pair(v,-1));
            if(it!=arr.end() && it->first == v && k<=idx[it->second].size()){
                cout<<idx[it->second][k-1]+1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}