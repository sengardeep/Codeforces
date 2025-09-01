#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

int f(int n){
    int ans=0;
    while(1<<(ans+1) <= n) ans++;
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    int LOG = f(m);
    vector<vector<int>> st(m,vector<int>(LOG+1));
    vector<int> v(m);
    for(int i=0;i<m;i++) 
    {
        cin>>v[i];
        st[i][0]=v[i];
    }
    int q;
    cin>>q;

    //PreProcessing
    for(int j=1;j<=LOG;j++) for(int i=0;i+(1<<j)-1<m;i++) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    
    function<int(int,int)> query = [&](int l,int r)->int{
        int len=r-l+1;
        int k=f(len);
        return max(st[l][k],st[r-(1<<k)+1][k]);
    };

    while(q--){
        int x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;

        if((abs(x1-x2))%k || (abs(y1-y2))%k) {
            cout<<"NO"<<endl;
            continue;
        }

        int mx = ((n-x1)/k)*k;
        x1 += mx;
        if(y1>y2) swap(y1,y2);
        if(x1 > query(y1-1,y2-1) || (x1 == x2 && y1 == y2)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
