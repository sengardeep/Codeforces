#include<bits/stdc++.h>
using namespace std;

int ask(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    int ans; cin>>ans;
    return ans;
}
void solve() {
   int n;
   cin>>n;
   vector<int> pre(n+1);
   for(int i=2;i<=n;i++){
    pre[i]=ask(1,i);
   }
   int sum_2_to_n = ask(2,n);
   int first = pre[n] - sum_2_to_n;
   pre[1] = first;
   vector<int> v(n+1);
   for(int i=n;i>=2;i--){
    v[i]=pre[i]-pre[i-1];
   }
   v[1]=first;
   cout<<"! ";
   for(int i=1;i<=n;i++) cout<<v[i]<<" ";
   cout.flush();
}

int main(){
   int t=1;
   while(t--){
       solve();
   }
   return 0;
}
