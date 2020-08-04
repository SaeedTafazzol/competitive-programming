#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    int d[55];
    scanf("%d",&n);
    while(n){
        queue<int> q;
        for(int i = 1;i<=n;i++){
            q.push(i);
        }
        int idx=0;

        printf("Discarded cards:");
        while(q.size()>1){
            d[idx++] = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            q.push(b);
        }  

        if(idx>0){
            printf(" ");
            for(int i = 0;i<idx-1;i++){
                printf("%d, ",d[i]);
            }   

            printf("%d\n",d[idx-1]);
        }else{
            printf("\n");
        }
        printf("Remaining card: %d\n",q.front());
        scanf("%d",&n);
    }
    return 0;
}