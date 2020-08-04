#include <bits/stdc++.h>

using namespace std;
int kth(int k){
    if(k==0)
        return 0;
    if(k==1)
        return 1;
    int k2=k;
    int i = 0;
    while(k2>>=1){

        i++;
    }
    return kth((1<<(i+1)) - k -1 ) | (1<<i);    
}
int main(){
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int n,k;
        scanf("%d %d",&n,&k);
        printf("%d\n",kth(k));

    }
    return 0;
}