#include <bits/stdc++.h>
using namespace std;

struct node
{
	int idx;
	int val;
	int cnt;
}a[10010];
bool cmp(node a1,node a2)
{
	if(a1.val==a2.val) return a1.cnt>a2.cnt;
	return a1.val>a2.val;
}
void solve()
{
	int n,x,y,id;
	cin>>n;
	for(int i=1;i<=n;i++) a[i].idx=i;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		while(x--)
		{
			cin>>id>>y;
			a[id].val+=y;
			a[id].cnt++;
			a[i].val-=y;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) printf("%d %.2f\n",a[i].idx,0.01*a[i].val);

	
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

