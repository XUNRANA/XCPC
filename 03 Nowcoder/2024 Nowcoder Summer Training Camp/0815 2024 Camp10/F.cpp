#include <bits/stdc++.h>
using namespace std;
int f[1010][1010];
	int n,x,y;
	string ans;
set<pair<int,int> >st;
bool ck(int x,int y)
{
	if(!f[x][y])
	{
		for(auto i:st)
		{
			int nx=i.first;
			int ny=i.second;
			if(nx==x) 
			{
				for(int j=1;j<=n;j++) f[x][j]=1;
				continue;
			}
			if(ny==y) 
			{
				for(int i=1;i<=n;i++) f[i][y]=1;
				continue;
			}
			int xx=nx-x;
			int yy=ny-y;
			int t=__gcd(xx,yy);
			xx/=t;
			yy/=t;
			f[x][y]=1;
			int k=1;
			while(1)
			{
				int nxx=x+xx*k;
				int nyy=y+yy*k;
				if(nxx>n||nxx<1||nyy>n||nyy<1) break;
				f[nxx][nyy]=1;
				k++;
			}
			k=-1;
			while(1)
			{
				int nxx=x+xx*k;
				int nyy=y+yy*k;
				if(nxx>n||nxx<1||nyy>n||nyy<1) break;
				f[nxx][nyy]=1;
				k--;
			}
		}
		st.insert({x,y});
		return 1;
	}
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n*n;i++)
	{
        cin>>x>>y;
		if(ck(x,y)) ans+="1"; 
		else ans+="0";
    }
    
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
