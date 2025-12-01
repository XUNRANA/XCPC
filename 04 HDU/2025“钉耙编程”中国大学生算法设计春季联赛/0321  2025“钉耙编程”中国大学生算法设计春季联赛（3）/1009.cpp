#include <bits/stdc++.h>
using namespace std;
#define int long long
int fa[1000010];
int a[1000010];//i人的部落是啥
int b[1000010];//i位置是哪一个部落
int c[1000010];//i部落的位置
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(y)]=find(x);
}

void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		fa[i]=i;
		a[i]=b[i]=c[i]=i;
	}
	while(q--)
	{
		int op,x,y;
		cin>>op;
		if(op==4)
		{
			cin>>x;
			cout<<b[find(a[x])]<<"\n";
		}
		else
		{
			cin>>x>>y;
			if(op==1) merge(c[x],c[y]);//x部落与y部落合并
			else if(op==2) a[x]=c[y];//x人移动到部落y
			else if(op==3) //a部落与b部落的人交换位置    
			{
				swap(c[x],c[y]);
				swap(b[c[x]],b[c[y]]);
			}
		}
	}	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
