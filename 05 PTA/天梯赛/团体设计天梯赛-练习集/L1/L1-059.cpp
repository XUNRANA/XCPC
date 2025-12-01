#include <stdio.h>
#include <string.h>
char a[1000];
void solve()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(a);
		int cnt=0;
		for(int i=0;i<strlen(a);i++)
		if(a[i]==',')
		{
			if(i-1>=0&&a[i-1]=='g'&&i-2>=0&&a[i-2]=='n'&&i-3>=0&&a[i-3]=='o')
			{
				cnt++;
			}
		}
		else if(a[i]=='.')
		{
			if(i-1>=0&&a[i-1]=='g'&&i-2>=0&&a[i-2]=='n'&&i-3>=0&&a[i-3]=='o')
			{
				cnt++;
			}
		}
		if(cnt==2)
		{
			for(int i=strlen(a)-1,cnt=0;i>=0;i--)
			{
				if(a[i]==' ') cnt++;
				if(cnt==3)
				{
					for(int j=0;j<i;j++) putchar(a[j]);
					printf(" qiao ben zhong.\n");
					break;
				}
			}
		}
		else printf("Skipped\n");
		
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

