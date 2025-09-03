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

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    if(k==1) cout<<*min_element(begin(v),end(v));
    else if(k>=3) cout<<*max_element(begin(v),end(v));
    else cout<<max(max(v[0],*min_element(begin(v)+1,end(v))),max(v[n-1],*min_element(begin(v),begin(v)+n-1)));
    return 0;
}
