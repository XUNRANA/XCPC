#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int op;
    string a,b;
    while(n--)
    {
        cin>>op;
        if(op==1) 
        {
            cin>>a;
            int f=0;
            for(int i=0;i<s.size();i++) 
            if(s.substr(i,a.size())==a)
            {
                f=1;
                cout<<i<<"\n";
                break;
            }
            if(!f) cout<<"-1\n";
        }
        else if(op==2) 
        {
            cin>>a>>b;
            for(int i=0;i<s.size();i++) 
            if(s.substr(i,a.size())==a)
            {
                s=s.substr(0,i)+b+s.substr(i+a.size());
                break;
            }
            cout<<s<<"\n";
        }
        else 
        {
            char c1,c2;
            cin>>c1>>c2>>a;
            string ns="";
            for(int i=0;i<s.size();i++)
            {
                if(s[i]==c1&&i+1<s.size()&&s[i+1]==c2)
                {
                    ns+=s[i];
                    ns+=a;
                }
                else ns+=s[i];
            }
            s=ns;
            cout<<s<<"\n";
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}