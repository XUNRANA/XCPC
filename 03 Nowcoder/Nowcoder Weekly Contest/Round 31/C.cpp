#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long n,ans=0;
	char ch;
	string s;
    cin>>n>>ch>>s;
    s=" "+s;
    for(long long i=1;i<=n;i++)
    {
        if(s[i]==ch)
        {
            ans+=min(i,n-i+1);
        }
    }
    cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

