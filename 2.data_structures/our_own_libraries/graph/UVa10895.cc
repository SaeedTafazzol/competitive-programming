#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,n;
    while(cin>>m>>n){
        vector<vector<pair<int,int> > > trans(n);
        for(int i = 0;i<m;i++){
            int r;
            cin>>r;
            vector<pair<int,int> > m(r);
            for(int i = 0;i<r;i++){
                cin>>m[i].first;
            }
            for(int i = 0;i<r;i++){
                cin>>m[i].second;
            }

            for(int j = 0;j<r;j++){
                trans[m[j].first-1].push_back(make_pair(i,m[j].second));
            }
        }
        cout<<n<<" "<<m<<endl;
        for(int i = 0;i<n;i++){
            cout<<trans[i].size();
            for(unsigned int j = 0;j<trans[i].size();j++){
                cout<<" "<<trans[i][j].first+1;
            }
            cout<<endl;
            for(unsigned int j = 0;j<trans[i].size();j++){
                cout<<trans[i][j].second;
                if(j!=trans[i].size()-1){
                    cout<<" ";
                }
            }
            cout<<endl;

        }
    }
    return 0;
}