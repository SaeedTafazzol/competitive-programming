#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int out[1010];
    scanf("%d",&n);
    while(n!=0){
        while(1){
            scanf("%d",out);
            if(!out[0]){
                break;
            }
            for(int i = 1;i<n;i++)
                scanf("%d",out+i);

            int j = 0;
            stack<int> s;
            for(int i = 0;i<n;i++){
                s.push(i+1);
                while(!s.empty() && s.top()==out[j]){
                    s.pop();
                    j++;
                }
            }


            if(j==n && s.empty()){
                printf("Yes\n");
            }else{
                printf("No\n");
            }


        } 
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}