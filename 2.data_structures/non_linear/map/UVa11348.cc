#include <bits/stdc++.h>


using namespace std;

int main(){
    int tt;
    scanf("%d",&tt);
    for(int ttd=1;ttd<=tt;ttd++){
        int n;
        scanf("%d",&n);
        map<int,pair<int,int>> stamps;
        for(int i = 0;i<n;i++){
            int m;
            scanf("%d",&m);
            for(int j = 0;j<m;j++){
                int temp;
                scanf("%d",&temp);
                auto it = stamps.find(temp);
                if(it==stamps.end()){
                    stamps[temp] = make_pair(1,i);
                }else{
                    if(it->second.second!=i)
                        it->second.first++;
                }
            }
        }
        vector<int> friends(n);
        int total = 0;
        for(auto it = stamps.begin();it!=stamps.end();it++){
            if(it->second.first==1){
                friends[it->second.second]++;
                total++;
            }
        }
        printf("Case %d:",ttd);
        for(int i = 0;i<n;i++){
            printf(" %.6f%%",100*double(friends[i])/total);
        }
        printf("\n");

    }
    return 0;
}