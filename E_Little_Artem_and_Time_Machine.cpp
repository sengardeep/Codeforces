#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

map<int,map<int,int>> bit;
void update(int i,int val,int x){
    for(;i<=1e9+5;i += (i&-i)){
        bit[i][val] += x;
    }
}
int sum(int i,int val){
    int sum=0;
    for(;i>0;i-=(i&-i)) sum+=bit[i][val];
    return sum;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int q;
    cin>>q;
    while(q--){
        int type,time,value;
        cin>>type>>time>>value;

        if(type == 1) update(time,value,1);
        if(type == 2) update(time,value,-1);
        if(type == 3) cout<<sum(time,value)<<endl;
    }

    return 0;
}
