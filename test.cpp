#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define all(x) begin(x),end(x)

void solve() {
    int n;
    cin>>n;
    vector<pii> regular,vip;
    multiset<int> arrivals;
    int curr=INT_MAX;
    for(int i=0;i<n;i++){
        int at,pt,p;
        cin>>at>>pt>>p;
        if(p) vip.pb(make_pair(at,pt));
        else regular.pb(make_pair(at,pt));
        arrivals.insert(at);
        curr=min(curr,at);
    }
    sort(all(vip));     
    sort(all(regular)); 

    int i=0,j=0;
    int ans=0;

    for(int k=0;k<n;k++){
        if(j<vip.size() && i<regular.size()){
            if(vip[j].first<=curr){
                curr=max(curr,vip[j].first);
                curr+=vip[j].second;
                arrivals.erase(arrivals.find(vip[j].first));
                ans=max(ans,(int)distance(begin(arrivals), arrivals.lower_bound(curr)));
                j++;
            }
            else if(regular[i].first<=curr){
                curr=max(curr,regular[i].first);
                curr+=regular[i].second;
                arrivals.erase(arrivals.find(regular[i].first));
                ans=max(ans,(int)distance(begin(arrivals), arrivals.lower_bound(curr)));
                i++;
            }
            else{
                if (vip[j].first <= regular[i].first) {
                    curr=max(curr,vip[j].first);
                    curr+=vip[j].second;
                    arrivals.erase(arrivals.find(vip[j].first));
                    ans=max(ans,(int)distance(begin(arrivals), arrivals.lower_bound(curr)));
                    j++;
                } else {
                    curr=max(curr,regular[i].first);
                    curr+=regular[i].second;
                    arrivals.erase(arrivals.find(regular[i].first));
                    ans=max(ans,(int)distance(begin(arrivals), arrivals.lower_bound(curr)));
                    i++;
                }
            }
        }else{
            if(j<vip.size()){
                curr=max(curr,vip[j].first);
                curr+=vip[j].second;
                arrivals.erase(arrivals.find(vip[j].first));
                ans=max(ans,(int)distance(begin(arrivals), arrivals.lower_bound(curr)));
                j++;
            }
            else{
                curr=max(curr,regular[i].first);
                curr+=regular[i].second;
                arrivals.erase(arrivals.find(regular[i].first));
                ans=max(ans,(int)distance(begin(arrivals), arrivals.lower_bound(curr)));
                i++;
            }
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}