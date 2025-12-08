#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   string s,t;
   cin>>s>>t;
   vector<int> cnt(26, 0);
   for(char c : t) cnt[c-'a']++; 
   for(char c : s) cnt[c-'a']--;
   for(int c : cnt) {
    if(c <0){
        cout<<"Impossible"<<endl;
        return;
        }
   }
   sort(begin(t),end(t));
   map<char,int> map1,map2;
   for(auto c : s) map1[c]++;
   for(auto c : t) map2[c]++;
   string ans="";
   int j=0;
   for(int i=0;i<t.size();i++){
    char curr=t[i];
    if(j>=s.size()) {
        ans+=curr;
        continue;
    }
    if(s[j]==curr){
        ans+=s[j];
        j++;
    }else{
        if(s[j]>curr){
            int jump=map2[curr];
            i+=jump-1;
            int total=map2[curr]-map1[curr];
            while(total--){
                ans+=curr;
            }
        }else{
            while(j<s.size() && s[j]<curr){
                ans+=s[j];
                j++;
            }
            // dbg(curr);
            // dbg(i);
            // dbg(s[j]);
            // if(curr==s[j]) j++;
            ans+=curr;
        }
    }
   }
   while(j<s.size()) ans+=s[j++];
   cout<<ans<<endl;
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
