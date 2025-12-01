#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[100010],ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=(1<<m)-1;i++)
    {
    	vector<int>c(n+2);
        for(int j=m-1;j>=0;j--)
        {
            if(i>>j&1) 
			{
				c[a[m-j]]++;
				c[b[m-j]+1]--;
			}
        }
        int f=0;
        for(int i=1;i<=n;i++) 
		{
			c[i]+=c[i-1];
			if(c[i]<2)
			{
				f=1;
				break;
			}
		}
		if(f==0) ans++;
    }
    cout<<ans<<"\n";
}