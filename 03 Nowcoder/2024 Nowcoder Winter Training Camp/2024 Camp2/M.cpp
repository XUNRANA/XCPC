#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
typedef long long ll;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return qpow(x,mod-2);}
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
char s[MAX],b[MAX];
char to[12],now[5];
int dig_used[12],dig_used_cnt;
int underline_bit[MAX],underline_suf[MAX];
int underline_no_used_cnt,underline_tot_cnt;
int letter_no_used_kind,letter_tot_kind;
vector<int> pos[12],no_eq_pos[12][12],dig_no_eq_pos,underline_pos;
int get_now_pos(int x)
{
	int i,res;
	res=*upper_bound(all(dig_no_eq_pos),x);
	res=min(res,*upper_bound(all(underline_pos),x));
	for(i=0;i<10;i++)
	{
		if(to[i]=='#') res=min(res,*upper_bound(all(pos[i]),x));
		else res=min(res,*upper_bound(all(no_eq_pos[i][to[i]-'0']),x));
	}
	return res;
}
ll pow10[MAX],invpow10[MAX],bit[MAX];
ll cal()
{
	return pow10[underline_no_used_cnt]
			*A(10-dig_used_cnt,letter_no_used_kind)%mod;
}
ll work(int l,int r)
{
	int i,j,tail,ok,now_pos,pre_pos,d;
	ll ans,tmp,delta;
	char now_ch;
	if(l==r)
	{
		if(s[l]>='0' && s[l]<='9')
		{
			if(s[l]>b[l] || (s[l]-'0')%8!=0) return 0;
			else return 1;
		}
		else
		{
			if(b[l]>='8') return 2;
			else return 1;
		}
	}
	if(s[l]=='0') return 0;
	delta=invpow10[underline_suf[max(0,r-3)]];
	underline_tot_cnt=underline_bit[r]-underline_bit[l-1];
	letter_tot_kind=0;
	for(i=0;i<10;i++) letter_tot_kind+=(*lower_bound(all(pos[i]),l)<=r);
	ans=0;
	for(tail=0;tail<(r-l+1==2?100:1000);tail+=8)
	{
		sprintf(now+1,"%03d",tail);
		memset(to,'#',sizeof to);
		memset(dig_used,0,sizeof dig_used);
		ok=1;
		dig_used_cnt=0;
		letter_no_used_kind=letter_tot_kind;
		underline_no_used_cnt=underline_tot_cnt;
		underline_pos.clear();
		for(i=r-2,j=1;j<=3;i++,j++)
		{
			if(i<l)
			{
				if(now[j]!='0')
				{
					ok=0;
					break;
				}
				continue;
			}
			if(i==l && now[j]=='0') ok=0;
			if(s[i]>='0' && s[i]<='9')
			{
				if(s[i]!=now[j]) ok=0;
			}
			else if(s[i]>='a' && s[i]<='j')
			{
				if(to[s[i]-'a']!=now[j])
				{
					if(to[s[i]-'a']!='#') ok=0;
					if(dig_used[now[j]-'0']) ok=0;
					to[s[i]-'a']=now[j];
					letter_no_used_kind--;
					dig_used[now[j]-'0']=1;
					dig_used_cnt++;
				}
			}
			else
			{
				underline_no_used_cnt--;
				underline_pos.push_back(i);
			}
			if(i>=l) swap(s[i],now[j]);
		}
		if(s[l]>='a' && s[l]<='j' && to[s[l]-'a']=='0') ok=0;
		if(!ok)
		{
			for(i=r-2,j=1;j<=3&&i<=r;i++,j++)
			{
				if(i>=l) swap(s[i],now[j]);
			}
			continue;
		}
		underline_pos.push_back(r+1);
		now_pos=l;
		pre_pos=0;
		while(now_pos<=r)
		{
			now_ch=s[now_pos];
			if(now_ch=='_')
			{
				underline_no_used_cnt--;
				ans=(ans+max(0,b[now_pos]-'0'-(now_pos==l))*cal())%mod;
				now_ch=b[now_pos];
			}
			if(now_ch>='a' && now_ch<='j')
			{
				if(to[now_ch-'a']=='#')
				{
					dig_used_cnt++;
					letter_no_used_kind--;
					for(j=(now_pos==l?'1':'0');j<b[now_pos];j++)
					{
						if(!dig_used[j-'0']) ans=(ans+cal())%mod;
					}
					if(dig_used[b[now_pos]-'0'])
					{
						ok=0;
						break;
					}
					to[now_ch-'a']=b[now_pos];
					dig_used[b[now_pos]-'0']=1;
					now_ch=b[now_pos];
				}
				else now_ch=to[now_ch-'a'];
			}
			if(now_ch>='0' && now_ch<='9')
			{
				if(now_ch>b[now_pos])
				{
					ok=0;
					break;
				}
				else if(now_ch<b[now_pos])
				{
					ans=(ans+cal())%mod;
					ok=0;
					break;
				}
			}
			pre_pos=now_pos;
			now_pos=get_now_pos(now_pos);
			if(pre_pos<r-2)
			{
				d=underline_bit[min(now_pos,r-3)]-underline_bit[pre_pos];
				underline_no_used_cnt-=d;
				tmp=(bit[min(now_pos-1,r-3)]-bit[pre_pos])%mod;
				if(tmp<0) tmp+=mod;
				ans=(ans+tmp*delta%mod*A(10-dig_used_cnt,letter_no_used_kind))%mod;
			}
		}
		ans=(ans+ok)%mod;
		for(i=r-2,j=1;j<=3&&i<=r;i++,j++)
		{
			if(i>=l) swap(s[i],now[j]);
		}
	}
	return ans;
}
int main()
{
	int t,n,q,l,r,i,j;
	init(10);
	pow10[0]=1;
	for(i=1;i<=MAX-10;i++) pow10[i]=pow10[i-1]*10%mod;
	invpow10[MAX-10]=inv(pow10[MAX-10]);
	for(i=MAX-11;~i;i--) invpow10[i]=invpow10[i+1]*10%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		scanf("%s",b+1);
		for(i=0;i<10;i++)
		{
			pos[i].clear();
			for(j=0;j<10;j++)
			{
				no_eq_pos[i][j].clear();
			}
		}
		dig_no_eq_pos.clear();
		underline_bit[0]=0;
		for(i=1;i<=n;i++)
		{
			underline_bit[i]=0;
			if(s[i]>='a' && s[i]<='j')
			{
				pos[s[i]-'a'].push_back(i);
				for(j=0;j<10;j++)
				{
					if(b[i]-'0'==j) continue;
					no_eq_pos[s[i]-'a'][j].push_back(i);
				}
			}
			else if(s[i]=='_') underline_bit[i]=1;
			else if(s[i]!=b[i]) dig_no_eq_pos.push_back(i);
			underline_bit[i]+=underline_bit[i-1];
		}
		for(i=0;i<10;i++)
		{
			pos[i].push_back(n+1);
			for(j=0;j<10;j++)
			{
				no_eq_pos[i][j].push_back(n+1);
			}
		}
		dig_no_eq_pos.push_back(n+1);
		bit[0]=0;
		underline_suf[0]=underline_bit[n];
		for(i=1;i<=n;i++)
		{
			underline_suf[i]=underline_bit[n]-underline_bit[i];
			if(s[i]=='_') bit[i]=pow10[underline_suf[i]]*(b[i]-'0')%mod;
			else bit[i]=0;
			bit[i]=(bit[i]+bit[i-1])%mod;
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",work(l,r));
		}
	}
	return 0;
}

