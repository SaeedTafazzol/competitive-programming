#include <bits/stdc++.h>

using namespace std;

int main(){
    list<char> out;
    auto current = out.begin();
    char c;
    while((c = getchar())!=EOF){
        if(c=='\n'){
            for(auto it = out.begin();it!=out.end();it++){
                printf("%c",(*it));
            }
            printf("\n");
            out.clear();
            current = out.begin();
        }

        else if(c=='['){
            current = out.begin();
        }else if(c==']'){
            current = out.end();
        }else{
            out.insert(current,c);
        }


    }
    for(auto it = out.begin();it!=out.end();it++){
        printf("%c",(*it));
    }
    return 0;
}