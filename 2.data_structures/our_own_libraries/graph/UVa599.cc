#include <bits/stdc++.h>

using namespace std;

struct node{
  int idx;
  node * parent;
  int rank;
  node(int idx_):idx(idx_),rank(0){
    parent = nullptr;
  }
};


node * makeSet(int idx){
  node * ptrNode = new node(idx);
  ptrNode->parent = ptrNode;
  return ptrNode;
  
}
void link(node * a,node * b){
  if(a->rank>b->rank){
    b->parent = a;
  }else{
    a->parent = b;
    if(a->rank==b->rank)
      b->rank++;
  }
}


node * findSet(node * a){
  if(a->parent != a){
    a->parent = findSet(a->parent);
  }
  return a->parent;
}



void setUnion(node * a,node * b){
  link(findSet(a),findSet(b));
}

int main(){
    int tt;
    cin>>tt;
    cin.ignore();

    while(tt--){
        vector<vector<int>> graph(26);
        vector<node *> ds;
        ds.assign(26,nullptr);
        string st;
        while(1){
            getline(cin,st);
            if(st[0]=='*'){
                break;
            }
            graph[st[1]-'A'].push_back(st[3]-'A');
            

        }
        getline(cin,st);
        for(int i = 0;i<st.size();i+=2){
            ds[st[i] - 'A'] = makeSet(st[i]-'A');
        }

        for(int i = 0;i<graph.size();i++){
            for(int j = 0;j<graph[i].size();j++){
                setUnion(ds[i],ds[graph[i][j]]);
            }
        }

        vector<int> num;
        num.assign(26,0);
        for(int i = 0;i<ds.size();i++){
            if(ds[i]){
                num[findSet(ds[i])->idx]++;
            }
        }
        int trees = 0,aco = 0;
        for(int i=0;i<num.size();i++){
            if(num[i]==1){
                aco++;
            }
            if(num[i]>1){
                trees++;
            }
        }
        

    

        printf("There are %d tree(s) and %d acorn(s).\n",trees,aco);


    }
    return 0;
}