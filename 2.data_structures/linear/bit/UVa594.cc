#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        int res = 0;

        for(int i = 0;i<4;i++){
            for(int j = 0;j<8;j++){
                if((1<<(i*8+j))&n){
                    res|= (1<<((4-i-1)*8+j));
                }
            }
        }
        printf("%d converts to %d\n",n,res);
    }
    return 0;
}