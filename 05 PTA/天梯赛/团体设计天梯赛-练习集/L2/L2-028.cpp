#include <bits/stdc++.h>
using namespace std;
double a[1010][1010];
int g[1010];
int b[510];
//too much details;
void solve()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int k;
		cin>>k;
		for(int i=0;i<k;i++) 
		{
			string s;
			cin>>s;
			if(s[0]=='-') b[i]=stoi(s.substr(1));
			else 
			{
				b[i]=stoi(s);
				g[b[i]]=1;
			} 
		}
		for(int i=0;i<k;i++) for(int j=i+1;j<k;j++)
		{
			if(g[b[i]]==g[b[j]]) continue;
			a[b[i]][b[j]]+=1.0/k;
			a[b[j]][b[i]]+=1.0/k;
		}
	}
	int x,y;
    string sx,sy;
    cin>>sx>>sy;
    if(sx[0]=='-')
    {
        x=stoi(sx.substr(1));
        y=stoi(sy);
        g[y]=1;
    }
    else
    {
        y=stoi(sy.substr(1));
        x=stoi(sx);
        g[x]=1;
    }
    double px=0,py=0;
 	for(int i=0;i<n;i++)
 	{
 		if(g[i]!=g[x]) px=max(px,a[i][x]);
 		if(g[i]!=g[y]) py=max(py,a[i][y]);
	}
	if(px==py&&px==a[x][y]) 
	{
		cout<<(g[x]? "":"-")<<x<<" "<<(g[y]? "":"-")<<y<<"\n";
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(g[i]!=g[x]&&a[i][x]==px) cout<<(g[x]? "":"-")<<x<<" "<<(g[i]? "":"-")<<i<<"\n";
		}
		for(int i=0;i<n;i++)
		{
			if(g[i]!=g[y]&&a[i][y]==py) cout<<(g[y]? "":"-")<<y<<" "<<(g[i]? "":"-")<<i<<"\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

