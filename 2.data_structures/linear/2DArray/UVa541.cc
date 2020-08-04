#include <bits/stdc++.h>

using namespace std;

int mat[110][110];

bool parity(int n){
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = 0;j<n;j++){
            sum+=mat[i][j];
        }
        if(sum%2!=0){
            return false;
        }
    }
    for(int j = 0;j<n;j++){
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=mat[i][j];
        }
        if(sum%2!=0){
            return false;
        }
    }
    return true;
        
    
}
int main(){
    int n;
    scanf("%d",&n);
    while(n){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                scanf("%d",&mat[i][j]);
            }
        }

        if(parity(n)){
            printf("OK\n");
        }else{
            bool suc = false;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    mat[i][j] = (mat[i][j]?0:1);
                    if(parity(n)){
                        suc = true;
                        printf("Change bit (%d,%d)\n",i+1,j+1);
                        break;
                    }
                    mat[i][j] = (mat[i][j]?0:1);


                }
                if(suc)
                    break;
            }

            if(!suc){
                printf("Corrupt\n");
            }
        }



        scanf("%d",&n);
    }
    return 0;
}