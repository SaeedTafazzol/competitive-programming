#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        char form[n][3],pron[n][22];
        for(int i = 0;i<n;i++){
            scanf("%s %s\n",form[i],pron[i]);

        }
        int position=0;
        bool turnedOver[n];
        int result[n];
        fill(turnedOver,turnedOver+n,false);
        for(int i = 0;i<n;i++){
            for(char * p = pron[i];*p;){
                if(!turnedOver[position]){
                    p++;
                }
                position = (position+1)%n;

            }
            position = (n+(position-1)%n)%n;
            turnedOver[position] = true;
            result[position] =i;
        }
        printf("%s",form[result[0]]);
        for(int i = 1;i<n;i++){
            printf(" %s",form[result[i]]);
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}