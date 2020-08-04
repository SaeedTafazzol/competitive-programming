#include <bits/stdc++.h>

using namespace std;


int main(){
    int tt;
    scanf("%d",&tt);
    int sp[100010];
    int sf[100010];
    for(int ttd = 1;ttd<=tt;ttd++){
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++)
            scanf("%d",sf+i);

        for(int i = 0;i<n;i++)
            scanf("%d",sp+i);

        bool suc = false;
        int j = 0;
        int i = 0;
        int fuel = sf[0];        
        for(int ctr = 0;ctr<2*n;ctr++){
            fuel-=sp[i];
            i = (i+1)%n;
            if(fuel<0){
                j = i;
                fuel = sf[i];
                
            }else{
                if(j==i){
                    suc = true;
                    break;
                }
                fuel+=sf[i];

            }
        }
        printf("Case %d: ",ttd);
        suc?printf("Possible from station %d\n",j+1):printf("Not possible\n");        

    }
    return 0;
}