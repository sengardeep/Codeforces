#include <bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int start=0,end=n-1;
        bool flag=false;
        while(start < end)
        {
            if(abs((int)s[start]-(int)s[end]) == 1 || abs((int)s[start]-(int)s[end]) > 2){
                flag=false;
                break;
            
            }
            else
            {
            start++;
            end--;
            flag=true; 
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}