#include <bits/stdc++.h>
using namespace std;
int a[6][6],ans;
void dfs(int x,int y)
{
	if(x==5&&y==5)
	{
		int c1=0;
		for(int i=1;i<=5;i++)
		{
			int c=0;
			for(int j=1;j<=5;j++) if(a[i][j]) c1++,c++;
			if(c==0||c==5)
			{
				return ;
			}
		}
		
		if(c1!=13) return ;
		
		for(int j=1;j<=5;j++)
		{
			int c=0;
			for(int i=1;i<=5;i++) if(a[i][j]) c++;
			if(c==0||c==5)
			{
				return ;
			}
		}
		if(c1!=13) return ;
		
		int c2=0,c3=0;
		for(int i=1;i<=5;i++) 
		{
			if(a[i][i]) c2++;
			if(a[i][6-i]) c3++;
 		}
 		
 		if(c2!=0&&c2!=5&&c3!=0&&c3!=5) 
		{
			
			if(ans<15)
			{
				for(int i=1;i<=5;i++,cout<<"\n") for(int j=1;j<=5;j++) cout<<a[i][j]<<" ";
				cout<<"\n";
			}
		 	ans++;
		}
		return ;
	}
	
	a[x][y]=1;
	if(y+1<=5) dfs(x,y+1);
	else dfs(x+1,1);
	
	a[x][y]=0;
	if(y+1<=5) dfs(x,y+1);
	else dfs(x+1,1);

}
int main()
{
	dfs(1,1); 
	cout<<ans;
}
