#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod=1e9+7;

void solve() {
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    priority_queue<int> pq;
    for(int i=0;i<n;i++) pq.push(abs(a[i]-b[i]));
    int k=k1+k2;
    while(k>0){
        int top=pq.top();
        pq.pop();
        if(top==0){
            if(k%2){
                cout<<1<<endl;
                return;
            }else{
                cout<<0<<endl;
                return;
            }
        }
        top--;
        k--;
        pq.push(top);
    }
    int ans=0;
    while(!pq.empty()){
        int top=pq.top();
        pq.pop();
        ans=ans+top*top;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}