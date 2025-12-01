#include <bits/stdc++.h>
using namespace std;
int f[32][32],a[32][32],n,fx,x,y;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
			{
				for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) f[i][j]=0;
				deque<pair<int,int> >d;
				vector<pair<int,int> >ans;
				d.push_back(make_pair(i,j));
				ans.push_back(make_pair(i,j));
				fx=0;
				while(!d.empty())
				{
					pair<int,int>t;
					t=d.front();
					x=t.first;
					y=t.second;
					f[x][y]=1;
					d.pop_front();
					if(x+1>=n&&a[x+1][y]==0) fx=1;
					else if(x-1<=1&&a[x-1][y]==0) fx=1;
					else if(y+1>=n&&a[x][y+1]==0) fx=1;
					else if(y-1<=1&&a[x][y-1]==0) fx=1;
					else 
					{
						if(!f[x+1][y]&&!a[x+1][y]) d.push_back(make_pair(x+1,y)),ans.push_back(make_pair(x+1,y));
						if(!f[x-1][y]&&!a[x-1][y]) d.push_back(make_pair(x-1,y)),ans.push_back(make_pair(x-1,y));
						if(!f[x][y+1]&&!a[x][y+1]) d.push_back(make_pair(x,y+1)),ans.push_back(make_pair(x,y+1));
						if(!f[x][y-1]&&!a[x][y-1]) d.push_back(make_pair(x,y-1)),ans.push_back(make_pair(x,y-1));
					}
				}
				if(fx==0)
				{
					for(int i=0;i<ans.size();i++) a[ans[i].first][ans[i].second]=2;
					for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
					return 0;
				}
		    }
		}
	}
}
