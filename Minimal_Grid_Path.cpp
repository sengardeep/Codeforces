#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

// Created by Deep 
// Date : 05-06-2025 
// Time : 16:44

void solve() {
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    vector<string> ans;

    queue<pair<int,int>> q;
    q.push({0,0});
    queue<string> q1;
    q1.push(string(1, v[0][0]));

    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        string s=q1.front();
        if(r==n-1 && c==n-1) ans.push_back(s);
        q.pop();
        q1.pop();

        //right
        if(c+1 < n)
        {
            q.push({r,c+1});
            q1.push(s + v[r][c+1]);
        }

        //down
        if(r+1 < n)
        {
            q.push({r+1,c});
            q1.push(s + v[r+1][c]);
        }
    }

    sort(all(ans));
    cout<<ans[0]<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // Uncomment this line if multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}