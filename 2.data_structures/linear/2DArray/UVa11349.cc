#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main(){
    int tt;
    scanf("%d",&tt);
    for(int ttd = 1;ttd<=tt;ttd++){
        int n;
        scanf("\nN = %d",&n);
        ll mat[n][n];
        for(int i = 0;i<n;i++){
            scanf("\n");
            for(int j = 0;j<n;j++){
                scanf("%lld",&mat[i][j]);
            }
            
        }
        bool suc = true;
        for(int i = 0;i<ceil(n/2.0);i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != mat[n-i-1][n-j-1] || mat[i][j]<0){
                    suc= false;
                    break;
                }
            }
            if(!suc){
                break;
            }
        }
        printf("Test #%d: ",ttd);
        suc?printf("Symmetric.\n"):printf("Non-symmetric.\n");
    }
    return 0;
}