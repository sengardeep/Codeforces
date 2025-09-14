#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n;
   cin>>n;
   vector<int> a(n),b(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i];
   int score1=0,score2=0;
   int pos=0,neg=0;
   for(int i=0;i<n;i++){
    if(a[i]==0 && b[i]==0) continue;
    if(a[i]>b[i]) score1+=a[i];
    else if(b[i]>a[i]) score2+=b[i];
    else {
        if(a[i]>0) pos++;
        else neg++;
    }
   }
   //cover negatives
   if(neg>0){
    int diff=abs(score1-score2);
    if(neg>=diff) {
        neg-=diff;
        score1=score2=min(score1,score2);
    }
    else{
        if(score1>score2) score1-=neg;
        else score2-=neg;
        neg=0;
    }
    while(neg>0){
        score1-=1;
        neg--;
        if(neg==0) break;
        score2-=1;
        neg--;
    }
   }
   //cover positives
   if(pos>0){
    int diff=abs(score1-score2);
    if(pos>=diff) {
        pos-=diff;
        score1=score2=max(score1,score2);
    }
    else{
        if(score1<score2) score1+=pos;
        else score2+=pos;
        pos=0;
    }
    while(pos>0){
        score1+=1;
        pos--;
        if(pos==0) break;
        score2+=1;
        pos--;
    }
   }
   cout<<min(score1,score2)<<endl;
}

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
       solve();
   }

   return 0;
}
