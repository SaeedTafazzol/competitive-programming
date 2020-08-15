#include <bits/stdc++.h>

using namespace std;

class disjoint_set{
private:
    vector<pair<int,int>> tree;
public:
    disjoint_set(int n){
        tree.resize(n);
        for(int i = 0;i<n;i++){
            tree[i] = make_pair(i,0);
        }
    }
    void setUnion(int u,int v){
        int p1 = findSet(u);
        int p2 = findSet(v);
        if(p1==p2){
            return;
        }
        if(tree[p1].second < tree[p2].second){
            tree[p1].first = p2;
        }else{
            tree[p2].first = p1;
            if(tree[p2].second == tree[p1].second){
                tree[p1].second++;
            }
        }
    }

    int findSet(int t){
        if(tree[t].first == t)
            return t;
        tree[t].first = findSet(tree[t].first);
        return tree[t].first;
    }

};

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m) && (n || m)){
        disjoint_set ds(n);
        for(int i = 0;i<m;i++){
            int r;
            cin>>r;
            int pv;
            int cur;
            if(r) cin>>pv;
            for(int j = 1;j<r;j++){
                cin>>cur;
                ds.setUnion(pv,cur);
            }
        }
        int ctr = 0;
        for(int i = 0;i<n;i++){
            if(ds.findSet(0) == ds.findSet(i)){
                ctr++;
            }
        }
        printf("%d\n",ctr);
    }
    return 0;
}