#include <bits/stdc++.h>
using namespace std;
int f[110][110][2];
int c[2];
//0 ср 
//1 об 
void solve()
{
	int n,m,s;
	cin>>n>>m>>s;
	int p=1;
	vector<int>ans;
	for(int i=1;i<=s;i++)
	{
		int op,sx,sy,ex,ey;
		cin>>op;
		cin>>sx>>sy>>ex>>ey;
		
		if(op!=(p^1)||abs(sx-ex)+abs(sy-ey)!=1)
		{
			ans.push_back(i);
			continue;	
		}
		
		if(sx>ex)
		{
			swap(sx,ex);
			swap(sy,ey);
		}
		if(sy>ey)
		{
			swap(sx,ex);
			swap(sy,ey);	
		}
		
		
//		cout<<op<<" "<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<"?\n";
		if(sx==ex)//
		{
			if(f[sx][sy][0]||sy==m)
			{
				ans.push_back(i);
				continue;	
			}
			f[sx][sy][0]=1;
			
			
			int fx=0;
			//об 
			if(f[sx][sy][1]&&f[sx+1][sy][0]&&f[sx][sy+1][1])
			{
				c[op]++;
				fx=1;
			}
			//ио 
			if(f[sx-1][sy][0]&&f[sx-1][sy][1]&&f[sx-1][sy+1][1])
			{
				c[op]++;
				fx=1;
			}
			if(fx) p^=1;
		}
		else
		{
//			cout<<i<<" "<<sx<<" "<<sy<<" "<<"?\n";
			if(f[sx][sy][1]||sx==n)
			{
				ans.push_back(i);
				continue;	
			}
			f[sx][sy][1]=1;
			int fx=0;
			//вС 
			if(f[sx][sy-1][0]&&f[sx][sy-1][1]&&f[sx+1][sy-1][0])
			{
				c[op]++;
				fx=1;
			}
			//ср
			if(f[sx][sy][0]&&f[sx+1][sy][0]&&f[sx][sy+1][1])
			{
				c[op]++;
				fx=1;
			} 
			if(fx) p^=1;
		}	
		p^=1;
	}
	
	
	if(!ans.size()) ans.push_back(-1); 
	
	
	int f=0;
	for(auto i:ans)
	{
		if(f) cout<<" ";
		cout<<i;
		f=1;
	}
	cout<<"\n";
	
	if(c[0]>c[1]) cout<<"0 "<<c[0]<<"\n";
	else cout<<"1 "<<c[1]<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
