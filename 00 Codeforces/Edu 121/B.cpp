#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=n-2;i>=0;i--)
    {
        int now=s[i]-'0';
        int nxt=s[i+1]-'0';
        if(now+nxt>=10)//不用减少一位
        {
            cout<<s.substr(0,i)<<now+nxt<<s.substr(i+2)<<"\n";
            return ;
        }
    }
    int now=s[0]-'0';
    int nxt=s[1]-'0';
    if(n==2) cout<<now+nxt<<"\n";
    else cout<<now+nxt<<s.substr(2)<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

