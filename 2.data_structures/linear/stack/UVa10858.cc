#include <bits/stdc++.h>

using namespace std;
void factorize(int n,vector<vector<int>> & res,bool include,int minF){
    if(n==1){
        return;
    }
    bool isPrime = true;
    for(int i = minF;i<=int(sqrt(n));i++){
        if(n%i==0){
            isPrime = false;
            vector<vector<int> >temp;
            factorize(n/i,temp,true,i);
            for(int j = 0;j<temp.size();j++){
                res.push_back(vector<int>());
                int cur_idx = res.size()-1;
                res[cur_idx].push_back(i);
                for(int k = 0;k<temp[j].size();k++){
                    res[cur_idx].push_back(temp[j][k]);
                }
            }
        }
    }
    if(include){
        res.push_back(vector<int>());
        res[res.size()-1].push_back(n);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    while(n){

        vector<vector<int>> res;
        
        factorize(n,res,false,2);
        printf("%ld\n",res.size());
        for(int i = 0;i<res.size();i++){
            for(int j = 0;j<res[i].size()-1;j++){
                printf("%d ",res[i][j]);
            }
            printf("%d\n",res[i][res[i].size()-1]);
        }
        scanf("%d",&n);

    }
    return 0;
}