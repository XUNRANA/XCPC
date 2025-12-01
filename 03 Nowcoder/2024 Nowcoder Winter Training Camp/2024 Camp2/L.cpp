#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll comb[12][12],fac[12];
void init(int n)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=n;j++)
		{
			comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
		}
	}
	fac[0]=1;
	for(i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
ll A(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m]*fac[m]%mod;
}
char s[MAX],a[MAX],b[MAX];
char to[12],now[5];
int used[12];
ll pow10[MAX];
int main()
{
	int t,n,i,j,tail,ok,suf,use_cnt,nouse_cnt,has_change,flag[12];
	ll ans;
	init(10);
	pow10[0]=1;
	for(i=1;i<=MAX-10;i++) pow10[i]=pow10[i-1]*10%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",b+1);
		if(n==1)
		{
			if(s[1]>='0' && s[1]<='9')
			{
				if(s[1]>b[1] || (s[1]-'0')%8!=0) puts("0");
				else puts("1");
			}
			else
			{
				if(b[1]>='8') puts("2");
				else puts("1");
			}
			continue;
		}
		if(s[1]=='0')
		{
		    puts("0");
			continue;
		}
		ans=0;
		for(tail=0;tail<(n==2?100:1000);tail+=8)
		{
			sprintf(now+1,"%03d",tail);
			memset(to,'#',sizeof to);
			memset(used,0,sizeof used);
			memset(flag,0,sizeof flag);
			ok=1;
			use_cnt=0;
			for(i=1;i<=n;i++) a[i]=s[i];
			for(i=n-2,j=1;j<=3;i++,j++)
			{
				if(i<1)
				{
					if(now[j]!='0')
					{
						ok=0;
						break;
					}
					continue;
				}
				if(a[i]>='0' && a[i]<='9')
				{
					if(a[i]!=now[j]) ok=0;
				}
				else if(a[i]>='a' && a[i]<='j')
				{
					if(to[a[i]-'a']==now[j])
					{
						a[i]=now[j];
						continue;
					}
					if(to[a[i]-'a']!='#') ok=0;
					if(used[now[j]-'0']) ok=0;
					to[a[i]-'a']=now[j];
					used[now[j]-'0']=1;
					flag[a[i]-'a']=1;
					use_cnt++;
				}
				a[i]=now[j];
			}
			if(!ok) continue;
			suf=0;
			nouse_cnt=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]>='a' && a[i]<='j' && to[s[i]-'a']!='#') a[i]=to[s[i]-'a'];
				suf+=(a[i]=='_');
				if(a[i]>='a' && a[i]<='j')
				{
					if(to[a[i]-'a']!='#') a[i]=to[a[i]-'a'];
					else
					{
						if(!flag[a[i]-'a'])
						{
							nouse_cnt++;
							flag[a[i]-'a']=1;
						}
					}
				}
			}
			if(a[1]=='0') continue;
			for(i=1;i<=n;i++)
			{
				if(a[i]=='_')
				{
					suf--;
					if(i==1) ans=(ans+(b[i]-'0'-1)*pow10[suf]%mod*A(10-use_cnt,nouse_cnt))%mod;
					else ans=(ans+(b[i]-'0')*pow10[suf]%mod*A(10-use_cnt,nouse_cnt))%mod;
				}
				if(a[i]>='a' && a[i]<='j')
				{
					if(to[a[i]-'a']!='#') a[i]=to[a[i]-'a'];
					else
					{
						use_cnt++;
						nouse_cnt--;
						for(j=(i==1?'1':'0');j<b[i];j++)
						{
							if(used[j-'0']) continue;
							ans=(ans+pow10[suf]*A(10-use_cnt,nouse_cnt))%mod;
						}
						if(used[b[i]-'0'])
						{
							ok=0;
							break;
						}
						to[a[i]-'a']=b[i];
						used[b[i]-'0']=1;
						a[i]=b[i];
					}
				}
				if(a[i]>='0' && a[i]<='9')
				{
					if(a[i]>b[i])
					{
						ok=0;
						break;
					}
					else if(a[i]<b[i])
					{
						ans=(ans+pow10[suf]*A(10-use_cnt,nouse_cnt))%mod;
						ok=0;
						break;
					}
				}
			}
			ans=(ans+ok)%mod;
	//		printf("tail:%d ans: %lld\n",tail,ans);
	//		puts(a+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

