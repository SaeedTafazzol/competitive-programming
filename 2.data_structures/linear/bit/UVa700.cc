#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int ttd = 1;
    int y[22],m[22],r[22],b[22];
    while(n!=0){
        int ctr = 0;
        for(int i = 0;i<n;i++){
            int e;
            scanf("%d %d %d",y+i,b+i,&e);
            m[i] = e-b[i];
            r[i] = y[i] - b[i];
            if(ctr<b[i]){
                ctr = b[i];
            }
        }
        int date;
        for(;ctr<10000;ctr++){
            bool match = true;
            for(int i = 0;i<n;i++){
                if((ctr-r[i]-b[i])%m[i]!=0){
                    match = false;
                    break;
                }
            }
            if(match){
                date = ctr;
                break;
            }
        }
        printf("Case #%d:\n",ttd);
        if(ctr!=10000){
            printf("The actual year is %d.\n\n",date);
        }else{
            printf("Unknown bugs detected.\n\n");
        }
        ttd++;
        scanf("%d",&n);

    }
    return 0;
}