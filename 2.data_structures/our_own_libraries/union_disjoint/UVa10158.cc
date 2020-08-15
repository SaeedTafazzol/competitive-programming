#include <bits/stdc++.h>

using namespace std;


class disjoint_set{
public:
    vector<pair<int,int>> tree;
    vector<int> enemy;
    disjoint_set(int n){
        tree.resize(n);
        for(int i = 0;i<n;i++){
            tree[i] = make_pair(i,0);
        }
        enemy.assign(n,-1);
    }

    bool setEnemy(int u,int v){
        if(findSet(u)!=findSet(v)){
           int p1 = findSet(u);
           int p2 = findSet(v);

           if(enemy[p1] != -1){
               enemy[p1]  = setUnion(p2,enemy[p1]);
               p2 = enemy[p1];
           }else{
               enemy[p1] = p2;
           }

           if(enemy[p2] != -1){
               enemy[p2] = setUnion(p1,enemy[p2]);
           }else{
               enemy[p2] = p1;
           }

           return true;
            
        }

        return false;
    } 

    int setUnion(int u,int v){
        if(enemy[findSet(u)] == findSet(v)){
            return -1;
        }
        int p1 = findSet(u);
        int p2 = findSet(v);
        if(p1==p2){
            return p1;
        }
        if(tree[p1].second < tree[p2].second){
            tree[p1].first = p2;
            if(enemy[p2] == -1){
                enemy[p2] = enemy[p1];
            }else if(enemy[p1]!=-1){
                enemy[enemy[p1]] = p2;
                int res = setUnion(enemy[p1],enemy[p2]);
                enemy[p2] = res;

            }
            return p2;
        }else{
            tree[p2].first = p1;
            if(tree[p2].second == tree[p1].second){
                tree[p1].second++;
            }

            if(enemy[p1] == -1){
                enemy[p1] = enemy[p2];
            }else if(enemy[p2]!=-1){
                enemy[enemy[p2]] = p1;
                int res = setUnion(enemy[p1],enemy[p2]);
                enemy[p1] = res;

            }

            return p1;
        }
    }

    int findSet(int t){
        if(tree[t].first == t)
            return t;
        tree[t].first = findSet(tree[t].first);
        return tree[t].first;
    }

    void operator=(const disjoint_set & rhs){
        tree = rhs.tree;
        enemy = rhs.enemy;
        
    }

};



int main(){
    int n;
    while(cin>>n){
        int c,t1,t2;
        disjoint_set ds(n);
        while(scanf("%d %d %d",&c,&t1,&t2) && (c || t1 || t2)){

            int res;

            
            switch (c){
            case 1:

                res = ds.setUnion(t1,t2);
                if(res==-1){
                    printf("-1\n");
                }
                break;
            case 2:
                if(!ds.setEnemy(t1,t2)){
                    printf("-1\n");
                }
                break;
            case 3:
                if(ds.findSet(t1) == ds.findSet(t2)){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
                break;
            case 4:
                if(ds.enemy[ds.findSet(t1)] == ds.findSet(t2)){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
                break;
            default:
                break;
            }



        }
        
    }
    return 0;
}