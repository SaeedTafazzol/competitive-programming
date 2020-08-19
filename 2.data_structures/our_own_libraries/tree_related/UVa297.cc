#include <bits/stdc++.h>

using namespace std;

struct node{
    char type;
    node * children[4];
    node(){
        for(int i = 0;i<4;i++){
            children[i] = nullptr;
        }
    }
};

void deleteNode(node * n){
    if(n->type!='p'){
        delete n;
        return;
    }
    for(int i = 0;i<4;i++){
        deleteNode(n->children[i]);
    }
    delete n;
}

int getTree(node * n,string st,int i){
    n->type = st[i++];
    if(n->type=='p'){
        for(int j = 0;j<4;j++){
            n->children[j] = new node();
            i = getTree(n->children[j],st,i);
        }
    }
    return i;
}
int treeWorth(node * t,int s){
    if(t->type=='f'){
        return s;
    }else if(t->type=='p'){
        int sum = 0;
        for(int i = 0;i<4;i++){
            sum+=treeWorth(t->children[i],s/4);
        }
        return sum;
    }else{
        return 0;
    }
}
int sumTree(node * t1,node * t2,int s){
    if(t1->type=='f' || t2->type=='f'){
        return s;
    }else if(t1->type=='p' && t2->type=='p'){
        int sum=0;
        for(int i = 0;i<4;i++){
            sum+=sumTree(t1->children[i],t2->children[i],s/4);
        }
        return sum;
    }else if(t1->type=='p'){
        return treeWorth(t1,s);
    }else if(t2->type=='p'){
        return treeWorth(t2,s);
    }else{
        return 0;
    }

    
}

void printInOrder(node * t){
    cout<<t->type;
    if(t->type=='p'){
        for(int i =0;i<4;i++){
            printInOrder(t->children[i]);
        }
    }
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string s1,s2;
        cin>>s1>>s2;
        node * t1 = new node();
        node * t2 = new node();
        getTree(t1,s1,0);
        getTree(t2,s2,0);
        printf("There are %d black pixels.\n",sumTree(t1,t2,1024));
        deleteNode(t1);
        deleteNode(t2);
    }
    return 0;
}