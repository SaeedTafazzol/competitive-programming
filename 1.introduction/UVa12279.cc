#include <stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    int t = 1;
    while(n!=0){
        int res = 0;
        for(int i = 0;i<n;i++){
            int cur;
            scanf("%d",&cur);
            if(cur==0){
                res--;
            }else if(cur>=1 || cur<=99){ 
                res++;
            }
        }
        printf("Case %d: %d\n",t++,res);
        scanf("%d,",&n);

    }
    return 0;
}