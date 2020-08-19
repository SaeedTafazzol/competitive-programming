#include <bits/stdc++.h>

using namespace std;

struct node{
    int max,min,label;

};
long long int overlap;
node tree[1<<18+1];

void update(int p,int l,int r,int q1,int q2,int h){
    if(q1>r || q2<l){
        return;
    }
    if(l!=r){
        if(tree[p].label){
            tree[p<<1|1].max = tree[p<<1|1].min = tree[p<<1|1].label = tree[p].label;
            tree[p<<1].max = tree[p<<1].min = tree[p<<1].label = tree[p].label;
            tree[p].label = 0;
        }
    }

    if(tree[p].min> h){
        return;
    }

    if(q1<=l && q2>=r && h>=tree[p].max){
        overlap += r-l+1;
        tree[p].max = tree[p].min = tree[p].label = h;
        return;
    }


    int m = (l+r)>>1;
    update(p<<1,l,m,q1,q2,h);
    update(p<<1|1,m+1,r,q1,q2,h);


    tree[p].max = max(tree[p<<1].max,tree[p<<1|1].max);
    tree[p].min = min(tree[p<<1].min,tree[p<<1|1].min);


}
int main(){
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int n;
        scanf("%d",&n);
        memset(tree,0,sizeof(tree));
        overlap = 0;
        for(int i = 0;i<n;i++){
            int l,r,h;
            scanf("%d %d %d",&l,&r,&h);
            update(1,1,100000,l,r-1,h);
        }
        printf("%lld\n",overlap);
    }
    return 0;
}