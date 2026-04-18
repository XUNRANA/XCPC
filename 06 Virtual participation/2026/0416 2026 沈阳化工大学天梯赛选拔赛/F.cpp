#include <bits/stdc++.h>
using namespace std;
#define int long long

string fx(string s)
{
    int cnt=1;
    string ans;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        {
            ans+=to_string(cnt);
            ans+=s[i-1];
            cnt=1;
        }
        else cnt++;
    }
    ans+=to_string(cnt);
    ans+=s.back();
    return ans;
}
void solve()
{
    int n;
    string s;
    cin>>n>>s;

    while(n--)
    {
        char ch;
        cin>>ch;
        if(ch=='C') s=fx(s);
        else 
        {
            string s1,s2;
            cin>>s1>>s2;
            int l=-1,r=-1;
            for(int i=0;i+s1.size()<=s.size();i++)
            {
                if(s.substr(i,s1.size())==s1)
                {
                    l=i;
                    break;
                }
            }

            for(int i=s.size()-s2.size();i>=0;i--)
            {
                if(s.substr(i,s2.size())==s2)
                {
                    r=i;
                    break;
                }
            }
            // cout<<l<<" "<<r<<"???\n";
            if(l!=-1&&r!=-1&&l+s1.size()<=r) s=s.substr(l,r+s2.size()-1-l+1);
            // cout<<s<<"?\n";
            // cout<<fx(s)<<"??\n";
        }
    }
    cout<<s<<"\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}