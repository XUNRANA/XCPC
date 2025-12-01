#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,l,l1,l2,ca,cb;
int pow(int a,int b)
{
	int s=1;
	for(int i=1;i<=b;i++) s*=a;
	return s;
}
void solve()
{
	cin>>a>>b>>l;
	l2=l1=l;
	ca=cb=0;
	while(l1%a==0) ca++,l1/=a;
	while(l2%b==0) cb++,l2/=b;
	set<int>s;
	for(int i=0;i<=ca;i++)
	{
		for(int j=0;j<=cb;j++)
		{
			if(pow(a,i)*pow(b,j)<=l&&l%(pow(a,i)*pow(b,j))==0) s.insert(pow(a,i)*pow(b,j));
		}
	}
	cout<<s.size()<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
