#include <bits/stdc++.h>
using namespace std;
#define int long long
int lowbit(int x)
{
    return x&-x;
}
void solve()
{
    int x;
	cin>>x;
	if(x==1)
	{
		cout<<"-1\n";
		return ;
	}
    if(x&1) cout<<x-1<<"\n";
    else 
    {
        if(lowbit(x)==x) cout<<"-1\n";
        else cout<<x-lowbit(x)<<"\n";
    }
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

