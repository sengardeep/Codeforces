#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << (x) << endl

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    stack<int> st;
    vector<pair<int,int>> components;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') st.push(i);
        else{
            if(st.empty()) continue;
            int f = st.top();
            st.pop();

            //Merging  (())
            if(!components.empty() && components.back().first>f && components.back().second<i){
                components.pop_back();
            }
            components.push_back({f,i});
        }
        //Merging ()()
        if(components.size()>1){
            if(components.back().first-components[components.size()-2].second == 1){
                int s = components.back().second;
                components.pop_back();
                components.back().second=s;
            }
        }
    }

    int ans=0,occ=1;
    for(auto it : components){
        int len = it.second - it.first + 1;
        if(len>ans){
            occ=1;
            ans=len;
        }
        else if(len==ans) occ++;
    }

    cout<<ans<<" "<<occ;

    return 0;
}
