#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x,k,j;
	cin>>x>>k;
	for(int i=x;i;i++)
	{
		j=i;
		int s=0;
		while(j)
		{
			s+=j%10;
			j/=10;
		}
		if(s%k==0)
		{
			cout<<i<<"\n";
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
