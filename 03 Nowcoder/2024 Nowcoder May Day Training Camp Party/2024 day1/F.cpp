#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,r,x,y,a[N],c[N],mx,ans,res;
vector<int>h[N];
//hi表示击中i，i-r，i+r三行的所有气球的y值（可重复）
//ai表示击中i，i-r，i+r三列的所有气球数
//ci表示值为i的ai有ci个 
//mx表示除了某三行上的气球外，选一个列i，i-r，i+r射击可以得到的最多的气球数 
void add(int y)
{
	if(y<0||y>=N) return ;
	c[a[y]++]--;
	mx=max(mx,a[y]);
	c[a[y]]++;	
}
void del(int y)
{
	if(y<0||y>=N) return ;
	c[a[y]]--;//a[y]的个数减少一个 
	if(c[a[y]]==0&&a[y]==mx) mx--;
	if(a[y]) c[--a[y]]++;
}
int main()
{
	cin>>n>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		h[x].push_back(y);
		if(x>=r) h[x-r].push_back(y);
		if(x+r<N) h[x+r].push_back(y);
		add(y);
		add(y-r);
		add(y+r);
	}
	for(int x=0;x<N;x++)
	{
		res=h[x].size();
		for(auto y:h[x]) del(y),del(y-r),del(y+r);
		ans=max(ans,res+mx);
		for(auto y:h[x]) add(y),add(y-r),add(y+r);
	}
	cout<<ans<<"\n";
}
