#include <bits/stdc++.h>

using namespace std;


int main(){
    bool check[3010];
    string in;
    stringstream ss;
    getline(cin,in);
    ss<<in;

    while(1){
        fill(check,check+3010,false);
        int ctr;
        ss>>ctr;
        int preNum;
        int num;
        if(!(ss>>preNum)){
            break;
        }
        while(ss>>num){
            check[abs(num-preNum)]=true;
            preNum = num;
        }
        bool isJo=true;
        for(int i = 1;i<ctr;i++){
            if(!check[i]){
                isJo = false;
                printf("Not jolly\n");
                break;
            }
        }
        if(isJo){
            printf("Jolly\n");
        }
        ss.clear();
        getline(cin,in);
        ss<<in;

    }
    return 0;
}