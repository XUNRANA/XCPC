#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll i,j,k,n,m,u,a[100500],b[100500],res;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>u;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) cin>>b[i];
	for(i=1;i<=n;i++)
    {
		ll x=m,y=0;
		for(j=i;j<=n;j++)
        {
			x-=a[j];
            y+=b[j];
			if(x<0||y>u) break;
			res=max(res,j-i+1);
		}
	}
	cout<<res;
}
