#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,q,j;
int b[12][510][510],c[510][510],p[12][510][510];
void solve()
{
	vector<int>a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	do
	{

		b[j][1][1]=a[0];
		b[j][1][2]=a[1];
		b[j][1][3]=a[2];
		
		b[j][2][1]=a[1];
		b[j][2][2]=a[2];
		b[j][2][3]=a[0];
		
		b[j][3][1]=a[2];
		b[j][3][2]=a[0];
		b[j][3][3]=a[1];
        
		b[j+1][1][1]=a[0];
		b[j+1][1][2]=a[1];
		b[j+1][1][3]=a[2];
		
		b[j+1][2][1]=a[2];
		b[j+1][2][2]=a[0];
		b[j+1][2][3]=a[1];
		
		b[j+1][3][1]=a[1];
		b[j+1][3][2]=a[2];
		b[j+1][3][3]=a[0];
		j+=2;
	}while(next_permutation(a.begin(),a.end()));
	cin>>n>>m>>q;
    
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
            for(int k=0;k<12;k++)
            {
                if(i>3||j>3) 
                {
                    if(i>3&&j>3) b[k][i][j]=b[k][i-3][j-3];
                    else if(i>3) b[k][i][j]=b[k][i-3][j];
                    else b[k][i][j]=b[k][i][j-3];
                }
            }
			char ch;
			cin>>ch;
			if(ch=='r') c[i][j]=0;
			else if(ch=='e') c[i][j]=1;
			else c[i][j]=2;
		}
	}
	for(int k=0;k<12;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
            {
                if(b[k][i][j]!=c[i][j]) p[k][i][j]=1;
				p[k][i][j]+=p[k][i-1][j]+p[k][i][j-1]-p[k][i-1][j-1];
			}
		}
	}
	

	while(q--)
	{
		int a,b,c1,d,ans=1e9;
		cin>>a>>b>>c1>>d;
		for(int k=0;k<12;k++) ans=min(ans,p[k][c1][d]-p[k][a-1][d]-p[k][c1][b-1]+p[k][a-1][b-1]);
		if(c1==a+1&&d==b+1) 
        {
            ans=min(ans,(int)(c[a][b]!=c[c1][d])+(int)(c[a][d]!=c[c1][b]));
            if(c[a][b]==c[a+1][b]&&c[a][b]==c[a][b+1]&&c[a][b]==c[a+1][b+1]) cout<<"2\n";
            else cout<<ans<<"\n";
        }
        else cout<<ans<<"\n";
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
