#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    scanf("%d",&tt);
    int front[8];
    int right[8];
    bool satisfied_right[8];
    while(tt--){
        fill(satisfied_right,satisfied_right+8,false);
        int k;
        scanf("%d",&k);
        for(int i = 0;i<k;i++) scanf("%d",front + i);
        for(int i = 0;i<k;i++) scanf("%d",right + i);
        int mini = 0;
        int maxi = 0;
        for(int i = 0;i<k;i++){
            mini+=front[i];
            for(int j = 0;j<k;j++){
                if(right[j]==front[i] && !satisfied_right[j]){
                    satisfied_right[j]=true;
                    break;
                }
            }
        }

        for(int i  = 0;i<k;i++){
            if(!satisfied_right[i]){
                mini+=right[i];
            }
        }

        for(int i =0;i<k;i++){
            for(int j=0;j<k;j++){
                maxi+=min(front[i],right[j]);
            }
        }
        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n",mini,maxi-mini);
    }    

    return 0;
}