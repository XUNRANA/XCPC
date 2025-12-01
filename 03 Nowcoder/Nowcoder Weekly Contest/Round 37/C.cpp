#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
    n%=495;
	if(n%495==0)
	{
        cout<<-1;
        return ;
    }
	for(int i=0;i<9;i++)
	{
		if((n*10+i)%495==0)
		{
			cout<<i<<endl;
			return ;
		}
	}
	for(int i=0;i<99;i++)
	{
		if((n*100+i)%495==0)
		{
			printf("%02d",i);
			return ;
		}
	}
	for(int i=0;i<999;i++)
	{
		if((n*1000+i)%495==0)
		{
			printf("%03d",i);
			return ;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
