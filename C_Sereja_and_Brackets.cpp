#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

struct Node{
    int l;
    int r;
    int mx;
};

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        string s;
        cin>>s;
        int q;
        cin>>q;
        int n=s.size();
        Node neutral;
        neutral.l=0,neutral.r=0,neutral.mx=0;
        vector<Node> segTree(4*n,neutral);

        auto fix = [&](int start,int index,string &s){
            segTree[index].l=0;
            segTree[index].r=0;
            segTree[index].mx=0;
            if(s[start]=='(') segTree[index].l=1;
            else segTree[index].r=1;
            return;
        };

        auto merge = [&](Node left,Node right){
            Node ans;
            ans.l=left.l+right.l;
            ans.r=left.r+right.r;
            int add=min(left.l-(left.mx)/2,right.r-(right.mx)/2);
            ans.mx=left.mx+right.mx+2*add;
            return ans;
        };

        function<void(int,int,int)> build=[&](int start,int end,int index)->void{
            if(start==end){
                fix(start,index,s);
                return;
            }

            int mid=(start+end)/2;

            build(start,mid,2*index);
            build(mid+1,end,2*index+1);
            
            segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
        };

        function<Node(int,int,int,int,int)> query=[&](int start,int end,int index,int l,int r)->Node{
            if(end<l || start>r) return neutral; //no overlap
            if(start>=l && end<=r) return segTree[index]; //Total overlap
            int mid=(start+end)/2;
            Node left = query(start,mid,2*index,l,r);
            Node right = query(mid+1,end,2*index+1,l,r);
            return merge(left,right);
        };

        build(0,n-1,1);
        while(q--){
            int l,r;
            cin>>l>>r;
            --l,--r;
            cout<<query(0,n-1,1,l,r).mx<<endl;
        }

    }

    return 0;
}
