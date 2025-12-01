#include <bits/stdc++.h>
using namespace std;
int a,b,xk,yk,xq,yq,cnt;
int dx[]={1,1,-1,-1};
int dy[]={1,-1,1,-1};
void solve()
{
	cnt=0;
	cin>>a>>b>>xk>>yk>>xq>>yq;
	
	for(int i=0;i<4;i++)
	{
		
		for(int j=0;j<4;j++)
		{
			
			if(a==b) 
			{
				if(xk+dx[i]*a==xq+dx[j]*a&&yk+dy[i]*a==yq+dy[j]*a) cnt++;
			}
			else
			{
				if(xk+dx[i]*a==xq+dx[j]*a&&yk+dy[i]*b==yq+dy[j]*b) cnt++;
				
				//cout<<xk+dx[i]*a<<" "<<xq+dx[j]*a<<" "<<yk+dy[i]*b<<" "<<yq+dy[j]*b<<"\n";
				if(xk+dx[i]*a==xq+dx[j]*b&&yk+dy[i]*b==yq+dy[j]*a) cnt++;
				
				if(xk+dx[i]*b==xq+dx[j]*a&&yk+dy[i]*a==yq+dy[j]*b) cnt++;
				
				if(xk+dx[i]*b==xq+dx[j]*b&&yk+dy[i]*a==yq+dy[j]*a) cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
