#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,s1,s2,sum1,sum2;
struct node
{
	int a,b;
}c[100010];
bool cmp(node c1,node c2)
{
	if(c1.a==c2.a) return c1.b>c2.b;
	return c1.a<c2.a;
}
void solve()
{
	cin>>n;
	s=s1=s2=sum1=sum2=0;
	for(int i=1;i<=n;i++) cin>>c[i].a>>c[i].b,s+=c[i].b;
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(2*(s1+c[i].b)>=s)
		{
			sum1+=((s+1)/2-s1)*c[i].a;
			s1+=(s+1)/2-s1;
			break;
		}
		s1+=c[i].b;
		sum1+=c[i].a*c[i].b;
	}
	for(int i=n;i>=1;i--)
	{
		if(s2+c[i].b>=s1)
		{
			sum2+=(s1-s2)*c[i].a;
			break;
		}
		s2+=c[i].b;
		sum2+=c[i].a*c[i].b;
	}
	//cout<<sum2<<" "<<sum1<<'\n';
	cout<<sum2-sum1<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();  
}
