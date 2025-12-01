#include <bits/stdc++.h>
using namespace std;
#define int long long
struct P
{
	int x,y;
}p[310];
int d[310][310];
int cross(P a,P b,P c)//>0 c在ab左侧；<0 c在ab右侧；=0 c在ab上 
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
} 
int dot(P a,P b,P c)//ab垂直bc返回0
{
	return (b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y);
}
int dis(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int fx(int l,int r,int m)
{
	if(2*p[m].x==p[l].x+p[r].x&&2*p[m].y==p[l].y+p[r].y) return 0;
	return 1;
}
signed main()
{
	int n,ans=0;
	cin>>n;
	map<pair<int,int>,int>mp;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y,mp[{p[i].x,p[i].y}]=1;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) d[i][j]=d[j][i]=dis(p[i],p[j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int l=0,l1=0,r=0,r1=0;
			vector< pair<int,int> >v;
			for(int k=1;k<=n;k++)
			{
				if(k==i||k==j||cross(p[i],p[j],p[k])==0) continue;
				if(d[k][i]==d[k][j])
				{
					if(cross(p[i],p[j],p[k])>0) l++;
					else r++;
				}
				if(dot(p[i],p[j],p[k])==0) v.push_back({p[k].x,p[k].y});
			}
			for(auto t:v)
			{
				P temp={t.first,t.second};
				if(mp.count({t.first-p[j].x+p[i].x,t.second-p[j].y+p[i].y}))
				{		
					if(cross(p[i],p[j],temp)>0) l1++;
					else r1++;
				}
			}
			ans+=l1*r+r1*l;
		}
	}
	cout<<ans<<'\n';
}
