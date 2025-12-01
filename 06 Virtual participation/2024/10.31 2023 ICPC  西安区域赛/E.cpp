#include<bits/stdc++.h>
using namespace std;
const int N=5010;
bitset<N> t[N];
char str[N];
int n,ban[N],p[N],a[N];
void work(int x)
{
	for(int i=1;i<=n;i++) if((t[x]&t[i])==t[i]) ban[i]=1;
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		p[i]=i;
		for(int j=1;j<=n;j++) t[i][j]=(str[j-1]-'0'),a[i]+=t[i][j];
	}
	
	sort(p+1,p+n+1,[](int x,int y){return a[x]>a[y];});
	
	vector<int> v;
	for(int i=1;i<=n&&(int)v.size()<3;i++) if(!ban[p[i]]) v.push_back(p[i]),work(p[i]);
	
	if((int)v.size()!=3) puts("NOT FOUND");
	else printf("%d %d %d\n",v[0],v[1],v[2]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
