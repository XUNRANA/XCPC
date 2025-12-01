#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[7][7];
int c[7];
int r[7];
int cnt=0;
void dfs(int x,int y)
{
	if(x==6&&y==7) 
	{
		cnt++;
		for(int i=1;i<=6;i++) if(c[i]!=3||r[i]!=3) return ;
		
		set<string>st;
		for(int i=1;i<=6;i++)
		{
			string s;
			for(int j=1;j<=6;j++) s+='0'+a[i][j];
			st.insert(s);
		}
		
		set<string>st1;
		for(int j=1;j<=6;j++)
		{
			string s;
			for(int i=1;i<=6;i++) s+='0'+a[i][j];
			st1.insert(s);
		}
		
		if(st.size()==6&&st1.size()==6)
		{
			for(int i=1;i<=6;i++,cout<<"\n") for(int j=1;j<=6;j++) cout<<a[i][j]<<" ";
		}
		
		return ;		
	}
	if(y==7) y-=6,x++;
	if(a[x][y]==-1)
	{
		if(r[x]<3&&c[y]<3&&(y<3||(y>=3&&(!a[x][y-1]||!a[x][y-2])))&&(x<3||(x>=3&&(!a[x-1][y]||!a[x-2][y])))) 
		{
			a[x][y]=1;
			r[x]++;
			c[y]++;
			dfs(x,y+1);
			r[x]--;
			c[y]--;
			a[x][y]=-1;
		}
		if((y<3||(y>=3&&(a[x][y-1]||a[x][y-2])))&&(x<3||(x>=3&&(a[x-1][y]||a[x-2][y]))))
		{
			a[x][y]=0;
			dfs(x,y+1);
			a[x][y]=-1;
		}
	}
	else dfs(x,y+1);
}
void solve()
{

	for(int i=1;i<=6;i++) for(int j=1;j<=6;j++) a[i][j]=-1;
	a[1][1]=a[5][3]=a[5][6]=a[6][5]=1;
	r[1]++;
	r[5]++;
	r[5]++;
	r[6]++;
	c[1]++;
	c[3]++;
	c[6]++;
	c[5]++;
	a[1][2]=a[1][4]=a[2][4]=a[3][5]=a[3][6]=a[6][2]=0;
	dfs(1,1);
	cout<<cnt<<"\n";
	for(int i=1;i<=6;i++,cout<<"\n") for(int j=1;j<=6;j++) cout<<a[i][j]<<" ";
//1 0 1 0 0 1
//32+8+1
//0 1 0 0 1 1
//16+3
//1 0 1 1 0 0
//32+8+4
//0 1 0 1 1 0
//16+6
//0 1 1 0 0 1
//16+8+1
//1 0 0 1 1 0
//32+6


//41
//19
//44
//22
//25
//38
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
