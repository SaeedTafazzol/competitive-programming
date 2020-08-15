#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int p;
        cin>>p;
        cin.ignore();
        vector<int> idxs(p);
        vector<int> res;
        int minDeg = INT_MAX;
        for(int i = 0;i<p;i++){
            string st;
            getline(cin,st);
            stringstream stream;
            stream<<st;
            int a;
            
            while(stream>>a){
                idxs[i]++;
            }

        }
        for(int i = 0;i<p;i++){
            if(idxs[i]<minDeg){
                minDeg = idxs[i];
                res.clear();
                res.push_back(i);
            }else if(idxs[i]==minDeg){
                res.push_back(i);
            }
        }
        for(int i = 0;i<res.size();i++){
            cout<<res[i]+1;
            (i==res.size()-1?cout<<endl:cout<<" ");
        }
    }
    return 0;
}