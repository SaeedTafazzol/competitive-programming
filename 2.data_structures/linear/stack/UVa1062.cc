#include <bits/stdc++.h>

using namespace std;

int main(){
    char st[1100];
    scanf("%s",st);
    int ttd = 1;
    while(strcmp(st,"end")){
        vector<stack<char>> stacks;
        for(char * c=st;*c;c++){
            int f = -1;
            for(int i = 0;i<stacks.size();i++){
                if(stacks[i].top()>=(*c)){
                    f = i;
                    break;
                }
            }

            if(f==-1){
                stacks.push_back(stack<char>());
                stacks[stacks.size()-1].push(*c);
            }else{
                stacks[f].push(*c);
            }
        }
        printf("Case %d: %ld\n",ttd,stacks.size());
        ttd++;
        scanf("%s",st);

    }
    return 0;
}