#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int target=0;
        for(int i=0;i<n;i++) 
        {
            cin>>v[i];
            while(v[i]%10 != 2 && v[i]%10 != 0){
                v[i] += v[i]%10;
            }
            target=max(target,v[i]);
        }

        bool flag=true;
        for(int i=0;i<n;i++){
            if((v[i]%10) == 0){
                if(v[i] != target) 
                {
                    flag=false;
                    break;
                }
            }
            else {
                if((target-v[i])%20 != 0){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
