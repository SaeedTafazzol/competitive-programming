#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    int arr[1000010];
    scanf("%d",&tt);
    while(tt--){
        int n;
        scanf("%d",&n);
        map<int,int> s;
        int max_size = 0;
        for(int i = 0;i<n;i++){
            scanf("%d",arr+i);
            auto it = s.find(arr[i]);
            if(it==s.end()){
                s[arr[i]] = i;
            }
            else{
                if(max_size<s.size()){
                    max_size = s.size();
                }
                int idx = it->second;
                s.clear();
                for(int j = it->second+1;j<=i;j++){
                    s[arr[j]] = j;
                }
                
            }
        }
        printf("%d\n",max(max_size,int(s.size())));
    }
    return 0;
}