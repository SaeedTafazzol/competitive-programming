#include <bits/stdc++.h>

using namespace std;


int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int m,n;
        cin>>n>>m;
        vector<vector<int>> mat(n);
        bool con[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)
                con[i][j] = false;
            mat[i].resize(m);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        bool correct = true;
        for(int i =0;i<m;i++){
            int sum = 0;
            int v1,v2;
            for(int j = 0;j<n;j++){
                if(mat[j][i]){
                    if(sum){
                        v2 = j;
                    }else{
                        v1 = j;
                    }
                }
                sum+=mat[j][i];
            }
            if(sum!=2 || con[v1][v2]){
                correct = false;
                break;
            }
            con[v1][v2] = true;
            con[v2][v1] = true;
        }
        (correct?cout<<"Yes":cout<<"No");
        cout<<endl;
    }
}