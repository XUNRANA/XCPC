#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	double ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			int j=i+1;
			int cnt=1;
			while(j<n&&s[j]=='1') cnt++,j++;
			if(cnt&1) ans+=(cnt+1)/2;
			else ans+=cnt/2+sqrt(2)-1;
			i=j;
		}
	}
	printf("%.20f\n",ans);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
