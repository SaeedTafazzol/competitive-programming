#include <bits/stdc++.h>

using namespace std;

class disjoint_set{
public:
    vector<pair<int,int>> tree;
    vector<int> pop;
    disjoint_set(int n){
        tree.resize(n);
        for(int i = 0;i<n;i++){
            tree[i] = make_pair(i,0);
        }
        pop.assign(n,1);
    }
    int setUnion(int u,int v){
        int p1 = findSet(u);
        int p2 = findSet(v);
        if(p1==p2){
            return p1;
        }
        if(tree[p1].second < tree[p2].second){
            tree[p1].first = p2;
            pop[p2] +=pop[p1];
            return p2;
        }else{
            tree[p2].first = p1;
            if(tree[p2].second == tree[p1].second){
                tree[p1].second++;
            }
            pop[p1]+=pop[p2];
            return p1;
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
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int n,m;
        scanf("%d %d",&n,&m);
        disjoint_set ds(n);
        int maxi = 1;
        for(int i = 0;i<m;i++){
            int f1,f2;
            scanf("%d %d",&f1,&f2);
            int p = ds.setUnion(f1-1,f2-1);
            maxi = max(maxi,ds.pop[p]);
        }


        cout<<maxi<<endl;
    }
    return 0;
}