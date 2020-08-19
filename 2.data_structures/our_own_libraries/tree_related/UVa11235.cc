#include <bits/stdc++.h>

using namespace std;

struct node{
    int mx_freq,mx_num;
    int left_freq,left_num;
    int right_freq,right_num;
};

vector<int> arr;
vector<node> tree;
void build(int p,int l,int r){
    if(l==r){
        tree[p].mx_freq = tree[p].left_freq = tree[p].right_freq = 1;
        tree[p].mx_num = tree[p].left_num = tree[p].right_num = arr[l];
        return;
    }
    int m = (l+r)>>1;
    build(p<<1,l,m);
    build(p<<1|1,m+1,r);


    int mid_freq = 0;
    int mid_num  = -200001;
    if(tree[p<<1].right_num == tree[p<<1|1].left_num){
        mid_freq=tree[p<<1].right_freq + tree[p<<1|1].left_freq;
        mid_num = tree[p<<1].right_num;
    }
    int cur_mx,cur_mx_num;
    if(tree[p<<1].mx_freq > tree[p<<1|1].mx_freq){
        cur_mx = tree[p<<1].mx_freq;
        cur_mx_num = tree[p<<1].mx_num;
    }else{
        cur_mx = tree[p<<1|1].mx_freq;
        cur_mx_num = tree[p<<1|1].mx_num;
    }

    if(cur_mx>mid_freq){
        tree[p].mx_freq = cur_mx;
        tree[p].mx_num = cur_mx_num;
    }else{
        tree[p].mx_freq = mid_freq;
        tree[p].mx_num = mid_num;
    }

    if(mid_num == tree[p<<1].left_num && mid_num == tree[p<<1|1].right_num){
        tree[p].right_freq = tree[p].left_freq = mid_freq;
        tree[p].right_num = tree[p].left_num = mid_num;
    }else if(mid_num == tree[p<<1].left_num){
        tree[p].left_freq = mid_freq;
        tree[p].left_num = mid_num;
        tree[p].right_freq = tree[p<<1|1].right_freq;
        tree[p].right_num = tree[p<<1|1].right_num;
    }else if(mid_num == tree[p<<1|1].right_num){
        tree[p].right_freq = mid_freq;
        tree[p].right_num = mid_num;
        tree[p].left_freq = tree[p<<1].left_freq;
        tree[p].left_num = tree[p<<1].left_num;
    }else{
        tree[p].left_freq = tree[p<<1].left_freq;
        tree[p].left_num = tree[p<<1].left_num;
        tree[p].right_freq = tree[p<<1|1].right_freq;
        tree[p].right_num = tree[p<<1|1].right_num;
    }
}

int query(int p,int l,int r,int q1,int q2){
    if(q1>r || q2<l){
        return 0;
    }

    if(q1<=l && q2>=r){
        return tree[p].mx_freq;
    }
    int m = (l+r)>>1;
    int r1 = query(p<<1,l,m,q1,q2);
    int r2 = query(p<<1|1,m+1,r,q1,q2);
    int mid_freq = 0;
    if(tree[p<<1].right_num == tree[p<<1|1].left_num){
        int m1 = min(tree[p<<1].right_freq,m-q1+1);
        int m2 = min(tree[p<<1|1].left_freq,q2-m);
        mid_freq = m1+m2;
    }
    
    return max(max(r1,r2),mid_freq);
}

void printTree(int p,int l,int r){
    // cout<<p<<" : "<<l<<"-"<<r<<" -> max ::: "<<tree[p].mx_freq<<","<<tree[p].mx_num<<" --- left ::: "<<tree[p].left_freq<<","<<tree[p].left_num<<"--- right ::: "<<tree[p].right_freq<<","<<tree[p].right_num<<endl;
    if(l==r){
        return;
    }
    int m = (l+r)>>1;
    printTree(p<<1,l,m);
    printTree(p<<1|1,m+1,r);
}
int main(){
    int n,q;
    while(cin>>n && n){
        cin>>q;
        arr.resize(n+1);
        tree.resize(4*n);
        for(int i = 1;i<=n;i++){
            cin>>arr[i];
        }
        build(1,1,n);   
        printTree(1,1,n);
        for(int i = 0;i<q;i++){
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}