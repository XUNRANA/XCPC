#include <stdio.h>
const int N=200005;
int n,f1,f2,m,p;
char s[N],t[N]; 
signed main()
{
	int i;
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(i=1;i<=n;i++)
	{
		if(t[i]=='A') f1=1;
		if(t[i]=='B') f2=0;
		if(s[i]=='A'&&t[i]=='B')
		{
			if(!f1)
			{
				puts("-1");
				return 0;
			}
			if(p>0) p--;
			else m++;
		}
		if(s[i]=='B'&&t[i]=='A')
		{
			m++;
			p++;
			f2++;
		}
	}
	
	if(f2) puts("-1");
	else printf("%d\n",m);
	
	return 0;
}
