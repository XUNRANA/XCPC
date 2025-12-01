#include <bits/stdc++.h>
using namespace std;
int n,m,k;
#define N 100010
int a[510][510],x1[N],y11[N],x2[N],y2[N];
bool ck(int x)
{
	for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) a[i][j]=0;
	
	for(int i=1;i<=x;i++) 
	{
		a[x1[i]][y11[i]]++;
        
		a[x1[i]][y2[i]+1]--;
		
        a[x2[i]+1][y11[i]]--;
        
        a[x2[i]+1][y2[i]+1]++;//???
	}
    
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		{
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if(!a[i][j]) return 0;
		}
	}
	return 1;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>x1[i]>>y11[i]>>x2[i]>>y2[i];
    
    if(!ck(k))
	{
        cout<<"-1\n";
		return ;
	}
    int l=1,r=k;
    while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
