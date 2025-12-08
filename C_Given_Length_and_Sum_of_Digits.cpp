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
    int m,s;
    cin>>m>>s;
    if(!s){
        if(m==1){
            cout<<0<<" "<<0<<endl;
            return;
        }
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    string mn="",mx="";
    int rem=s;
    for(int i=0;i<m;i++){
        if(rem<9) 
        {
            mx+=(rem+'0');
            rem=0;
        }
        else{
            mx+='9';
            rem-=9;
        }
    }
    rem=s;
    mn=mx;
    reverse(all(mn));
    if(mn[0]=='0'){
        mn[0]='1';
        for(int i=1;i<m;i++) {
            if(mn[i]!='0'){
                int d=mn[i]-'0';
                d--;
                mn[i]=(d+'0');
                break;
            }
        }
    }
    int x=0;
    for(int i=0;i<m;i++){
        x+=(mx[i]-'0');
    }
    if(x!=s){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    cout<<mn<<" "<<mx;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}