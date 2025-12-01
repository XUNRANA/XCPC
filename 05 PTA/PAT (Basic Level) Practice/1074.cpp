#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string s,a,b;
    cin>>s>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(s.begin(),s.end());
    while(a.size()<26) a+='0';
    while(b.size()<26) b+='0';
    while(s.size()<26) s+='0';
    int c=0;
    for(int i=0;i<26;i++)
    {
        int x=a[i]-'0'+b[i]-'0'+c;
        int k=s[i]-'0';
        if(!k) k=10;
        c=x/k;
        a[i]=x%k+'0';
    }
    for(int i=25;i>=0;i--) 
    if(a[i]!='0')
    {
        string ans=a.substr(0,i+1);
        reverse(ans.begin(),ans.end());
        cout<<ans<<"\n";
        return ;
    }
    cout<<"0\n";
    // cout<<a<<"\n";


}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
