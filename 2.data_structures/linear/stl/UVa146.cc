#include <bits/stdc++.h>

using namespace std;

int main(){
    char seq[60];
    scanf("%s",seq);
    while(strcmp(seq,"#")){
        int n = strlen(seq);
        bool sw = false;
        int p = 0;
        for(int i = n-2;i>=0;i--){
            if(seq[i] < seq[i+1]){
                p = i+1;
                int min = p;
                for(int j = p;j<n;j++){
                    if(seq[p]>seq[j] && seq[j]>seq[i]){
                        min = j;
                    }
                }
                char tmp = seq[i];
                seq[i] = seq[min];
                seq[min] = tmp;
                sw = true;
                break;
            }
        }
        if(sw){
            sort(seq+p,seq+n);
            printf("%s\n",seq);
        }else{
            printf("No Successor\n");
        }
        scanf("%s",seq);
    }
    return 0;
}