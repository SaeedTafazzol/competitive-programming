#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n){
        priority_queue<int> sum;
        int cost = 0;
        for(int i = 0;i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            sum.push(-tmp);
        }
        while(sum.size()>1){
            int a = -sum.top();
            sum.pop();
            int b = -sum.top();
            sum.pop();
            int res = a+b;
            cost+=res;
            sum.push(-res);
        }

        printf("%d\n",cost);

        scanf("%d",&n);
    }
    return 0;
}