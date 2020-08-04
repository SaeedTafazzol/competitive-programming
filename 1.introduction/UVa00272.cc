#include <iostream>
#include <string>
using namespace std;
int main(){
    bool enc = false;
    char c;
    while((c=getchar())!=EOF){
        if(c=='\"'){
            if(enc){
                printf("%s","\'\'");
            }else{
                printf("%s","``");
            }
            enc = !enc;
        }else{
            printf("%c",c);
        }

    
    }
    return 0;
}