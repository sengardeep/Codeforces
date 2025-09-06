#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //Merge Sort Tree (It is segment tree where each node contains a sorted list)
    //Find the smallest number >= given number in segment (l...r)
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int> tree[4*n];
    auto merge = [](vector<int>&a,vector<int>&b){
        int i=0,j=0;
        vector<int> ans;
        while(i<a.size() && j<b.size())
        {
            if(a[i]<b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while(i<a.size()) ans.push_back(a[i++]);
        while(j<b.size()) ans.push_back(b[j++]);
        return ans;
    };
    function<void(int,int,int)> build = [&](int start,int end,int index)->void{
        if(start==end){
            tree[index]=vector<int>(1,v[start]);
            return;
        }
        int mid = (start+end)/2;
        build(start,mid,2*index);
        build(mid+1,end,2*index+1);
        tree[index]=merge(tree[2*index],tree[2*index+1]);
    };
    function<int(int,int,int,int,int,int)> query = [&](int start,int end,int index,int l,int r,int val)->int{
        if(r<start || l>end) return 1e10;
        if(start>=l && end<=r){
            auto it = lower_bound(tree[index].begin(),tree[index].end(),val);
            if(it != tree[index].end()) return *it;
            return 1e10;
        }
        int mid = (start+end)/2;
        return min(query(start,mid,2*index,l,r,val),query(mid+1,end,2*index+1,l,r,val));
    };
    build(0,n-1,1);

    int q;
    cin>>q;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        cout<<query(0,n-1,1,l,r,x)<<endl;
    }
    return 0;
}
    