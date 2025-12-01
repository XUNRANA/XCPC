#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string s;
    cin>>s;
    int k;
    for(int i=0;i<s.size();i++)
    if(s[i]=='E')
    {
        k=stoi(s.substr(i+1));
        s=s.substr(0,i);
        break;
    }
    if(k==0) 
    {
        if(s[0]=='-') cout<<"-";
        for(int i=1;i<s.size();i++) cout<<s[i];
    }
    else if(k<0)
    {
        k=-k;
        k--;
        if(s[0]=='-') cout<<"-";
        cout<<"0.";
        while(k--) cout<<"0";
        for(int i=1;i<s.size();i++) if(isdigit(s[i])) cout<<s[i];
    }
    else
    {
        if(s[0]=='-') cout<<"-";
        int cnt=0;
        cout<<s[1];
        int f=0;
        for(int i=3;i<s.size();i++)
        {
            if(cnt==k)
            {
                cout<<".";
                cnt=100000;
                f=1;
                i--;
                continue;
            }
            else 
            {
                cout<<s[i];
                cnt++;
            } 
        }
        if(!f)
        {
            int c=k-cnt;
            while(c--) cout<<"0";
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

