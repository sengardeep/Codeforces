#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    long long ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='W') ans+=2;
        else if(s[i]=='V') ans+=5;
        else if(s[i]=='X') i++;
        else if(s[i]=='Y') 
        {
            if(i+1<s.size()) s.push_back(s[i+1]);
            i++;
        }
        else 
        {
            if(i+1<s.size() && s[i+1]=='v') 
            {
                ans/=5;
                i++;
            }
            else if(i+1<s.size() && s[i+1]=='W')
            {
                ans/=2;
                i++;
            }
        }
    }
    cout<<ans<<endl;
}