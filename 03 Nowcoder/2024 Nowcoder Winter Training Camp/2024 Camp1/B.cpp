#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,r,c,fl,fr;
	cin>>n;
	map<int,int>m[2];
	fl=fr=0;
	while(n--)
	{
		cin>>r>>c;
		r--;
		m[r][c]=1;
		if(c>0) fr=max(fr,1);
		if(c<0) fl=max(fl,1);
		if(m[r^1][c]||m[r^1][c-1]||m[r^1][c+1])
		{
			if(c>0) fr=max(fr,2);
			if(c<0) fl=max(fl,2);
		}
	}
	if(m[1][0]) fl=max(fl,1),fr=max(fr,1);
	if(m[1][0]&&m[0][-1]) fl=max(fl,2);
	if(m[1][0]&&m[0][1]) fr=max(fr,2);
	cout<<min(4-fr-fl,3-m[1][0]-m[0][-1]-m[0][1])<<"\n";
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
