#include <stdio.h>
char a[110][110];
char b[110][110];
void solve()
{
	char ch;
	int n;
	scanf("%c %d",&ch,&n);
	for(int i=1;i<=n;i++) 
	{
		getchar();//³Ôµô»»ÐÐ·û 
		for(int j=1;j<=n;j++) 
		{
			char ch1;
			scanf("%c",&ch1);
			if(ch1=='@') a[i][j]=ch;
			else a[i][j]=' ';
		}
	}	
	
	int f=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
	{
		b[i][j]=a[n+1-i][n+1-j];
		if(b[i][j]!=a[i][j]) f=1;
	}
	
	if(f==0) puts("bu yong dao le");
	
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=n;j++) putchar(b[i][j]);
	
} 
 
int main() 
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

