#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,i,p,a[200010],res;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>t;
	map<int,int>m;
	m[0]=n;
	res=1;
	while(t--)
	{
		cin>>i>>p;
		m[a[i]]--;
		if(m[a[i]]==0) res--;
		a[i]+=p;
		m[a[i]]++;
		if(m[a[i]]==1) res++;
		cout<<res<<"\n";
	}
}
