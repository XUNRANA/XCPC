#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,x1=0,x2,y1,y2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='#'&&!x1)
			{
				x1=i;
				y1=j;
			}
			if(ch=='#')
			{
				x2=i;
				y2=j;
			}
		}
	}
	cout<<(x1+x2)/2<<" "<<(y1+y2)/2<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
