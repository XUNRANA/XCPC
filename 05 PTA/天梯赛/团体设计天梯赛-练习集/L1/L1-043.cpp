#include <stdio.h>
int mp[1010];
void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=1000;i++) mp[i]=-1;
	while(n--)
	{
		int cnt=0,sum=0;
		while(1)
		{
			int id,h,m;
			char ch;
			scanf("%d %c %d:%d",&id,&ch,&h,&m);
			if(id==0) break; 
			if(ch=='S') mp[id]=h*60+m;
			else
			{
				if(mp[id]!=-1)
				{
					cnt++;
					sum+=h*60+m-mp[id];
					mp[id]=-1;
				}
			}
		}
		int ans1=0,ans2=0;
		if(cnt!=0) printf("%d %.0f\n",cnt,1.0*sum/cnt);
        else printf("0 0\n");
	}
} 
 
int main() 
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

