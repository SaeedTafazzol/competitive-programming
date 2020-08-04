#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    scanf("%d",&tt);
    bitset<1024> s;
    while(tt--){
        int n;
        int m;
        scanf("%d %d",&n,&m);
        s.set();

        for(int i = 0;i<m;i++){
            int idx;
            scanf("%d",&idx);
            s[idx-1] = false;

        }
        int ctr = 0;
        while(n){
            for(int i =0;i<(1<<n);i+=2){
                if(s[i]^s[i+1])
                    ctr++;
                s[i/2] = s[i]|s[i+1];
            }
            n--;
        }
        cout<<ctr<<endl;
    }
    return 0;
}