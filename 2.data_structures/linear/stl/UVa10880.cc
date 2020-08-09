#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;
    int dv[1<<20];
    scanf("%d",&n);
    for(int ttd  = 1;ttd<=n;ttd++){
        int c,r;
        int sz = 0;
        scanf("%d %d",&c,&r);
        int num = c - r;
        for(int i = 1;i<=int(sqrt(num));i++){
            if(num%i==0){
                dv[sz++] = i;
                int divis = num/i;
                if(divis != i)
                    dv[sz++] = divis;
            }
        }
        sort(dv,dv+sz);
        printf("Case #%d:",ttd);
        for(int i = 0;i<sz;i++){
            if(dv[i]>r){
                printf(" %d",dv[i]);
            }
        }
        if(num==0){
            printf(" 0");
        }
        printf("\n");
    }
    return 0;
}