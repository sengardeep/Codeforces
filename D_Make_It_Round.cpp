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
    vector<int> p2(19,1);
    vector<int> p5(19,1);
    for(int i=1;i<19;i++){
        p2[i]=p2[i-1]*2;
        p5[i]=p5[i-1]*5;
    }
    while(t--){
        int n,m;
        cin>>n>>m;
        int temp = n;
        int cnt2=0,cnt5=0;
        while(temp%2==0) {
            temp/=2;
            cnt2++;
        }
        temp=n;
        while(temp%5==0){
            temp/=5;
            cnt5++;
        }
        bool flag=false;
        for(int i=18;i>=0;i--){
            int idx1=max(0LL,i-cnt2);
            int idx2=max(0LL,i-cnt5);
            int num = p2[idx1]*p5[idx2];

            if(m>=num){
                flag=true;
                int x = m-(m%num);
                cout<<x*n<<endl;
                break;
            }
        }
        if(flag) continue;
        cout<<n*m<<endl;
    }

    return 0;
}
