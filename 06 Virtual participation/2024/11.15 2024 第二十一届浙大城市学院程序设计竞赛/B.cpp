#include <bits/stdc++.h>  
using namespace std;
int ck(int x)
{
	int res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}
void solve()
{
	int y;
	cin>>y;
	
	for(int i=0;i<=100;i++)
	{
		if(y-i<0) break;
		if(ck(y-i)==i) 
		{
			cout<<y-i<<"\n";
			return ;
		}
	}
	cout<<"-1\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
