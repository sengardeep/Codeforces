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
        string s;
        cin>>s;
        int c1=0;
        for(auto it : s) c1 += (it=='(');
        if(c1 != (n-c1)){
            cout<<-1<<endl;
            continue;
        }
        stack<char> st;
        bool flag=false;
        char prev=' ';
        int count=0;
        vector<int> ans;
        for(char c : s){
            if(st.empty() || st.top()==c){
                if(st.empty() && (prev==' ' || prev != c))
                {
                    if(prev != ' ' && prev != c) {
                        flag=true;
                        count ^= 1;
                    }
                }
                st.push(c);
                prev=c;
            }
            else{
                ans.push_back(count+1);
                ans.push_back(count+1);
                st.pop();
            }
        }

        if(flag)
        cout<<2<<endl;
        else 
        cout<<1<<endl;
        for(auto it : ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}
