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
    int tt;
    cin>>tt;
    cin.ignore();
    string st;
    getline(cin,st);
    while(tt--){
        int n;
        cin>>n;
        cin.ignore();
        disjoint_set ds(n+1);
        int suc=0,unsuc = 0;
        while(getline(cin,st)){
            if(st.size()==0){
                break;
            }
            stringstream ss;
            ss<<st;
            char ins;
            int c1,c2;
            ss>>ins>>c1>>c2;
            if(ins== 'c'){
                ds.setUnion(c1,c2);
            }else{
                if(ds.findSet(c1)==ds.findSet(c2)){
                    suc++;
                }else{
                    unsuc++;
                }
            }
        }
        cout<<suc<<","<<unsuc<<endl;
        if(tt) cout<<endl;
    }
    
    return 0;
}