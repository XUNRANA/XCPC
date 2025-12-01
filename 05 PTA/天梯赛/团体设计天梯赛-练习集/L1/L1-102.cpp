#include <bits/stdc++.h>
using namespace std;
int a[110];
double p[110],ans;
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	while(1)
	{
		int id,c;
		cin>>id>>c;
		if(!id) break;
		a[id]+=c;
		ans+=p[id]*c;
	}
	for(int i=1;i<=n;i++) printf("%d\n",a[i]);
	printf("%.2f",ans);
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

