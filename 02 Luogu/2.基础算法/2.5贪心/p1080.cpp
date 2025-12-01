#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
	char cnta[10000],all[10000];//所有a的乘积逆序、正序 
	char ca[100];//a转为成字符数组 
	char ans[10000];//所获金币数 
	int lans;
}da[1010];
bool cmp(node a1,node a2)
{
	return a1.a*a1.b<a2.a*a2.b;
}
bool cmp2(node a,node b)
{
	if(a.lans!=b.lans) return a.lans>b.lans;
	else
	{
		for(int i=0;i<a.lans;i++) 
		if(a.ans[i]!=b.ans[i]) return a.ans[i]>b.ans[i];
	}
	return 1==1;
}
void doit(int a,char b[])
{
	int lb=0;
	while(a)
	{
		b[lb++]=a%10+'0';
		a/=10;
	}
	b[lb]='\0';
}
void add(char c[],char d[],int i)
{
	int lc=strlen(c),j;
	int jw=0,tmp;
	for(int j=0;j<lc;j++,i++)
	{
		tmp=(d[i]>0?d[i]-'0':0)+c[j]-'0'+jw;
		d[i]=tmp%10+'0';
		jw=tmp/10;
	}
	if(jw) d[i++]=jw+'0';
	d[i]='\0';
}
void gc(char a[],char b[],char d[])
{
	int la=strlen(a);
	int lb=strlen(b);
	char c[10000];
	for(int i=0;i<la;i++)
	{
		int tmp,jw=0,lc=0;
		for(int j=0;j<lb;j++)
		{
			tmp=(a[i]-'0')*(b[j]-'0')+jw;
			c[lc++]=tmp%10+'0';
			jw=tmp/10;
		}
		if(jw) c[lc++]=jw+'0';
		c[lc]='\0';
		add(c,d,i);
	}
}
void mult(char a[],int b,char c[])
{
	int i=0,tag=0,la=strlen(a),lc=0,d=0;
	while(i<=la)
	{
		if(b>d) 
		{
			d=d*10+a[i++]-'0';
			if(tag) c[lc++]='0';
		}
		else
		{
			c[lc++]=d/b+'0';
			d%=b;
			d=d*10+a[i++]-'0';
			tag=1;
		}
	}
	if(!tag) c[lc++]='0';
	c[lc]='\0';
}
int main()
{
	int n;
	memset(da,0,sizeof(da));
	cin>>n;
	cin>>da[0].a>>da[0].b;
	for(int i=1;i<=n;i++) cin>>da[i].a>>da[i].b;
	sort(da+1,da+n+1,cmp);
	doit(da[0].a,da[0].ca);
	da[0].cnta[0]='1';
	da[0].cnta[1]='\0';
	for(int i=1;i<=n;i++)
	{
		doit(da[i].a,da[i].ca);
		gc(da[i-1].cnta,da[i-1].ca,da[i].cnta);
	}
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=strlen(da[i].cnta)-1;j>=0;j--) da[i].all[k++]=da[i].cnta[j];
		da[i].all[k]='\0';
	}
	for(int i=1;i<=n;i++)
	{
		mult(da[i].all,da[i].b,da[i].ans);
		da[i].lans=strlen(da[i].ans);
	}
	int ans=1;
	for(int i=2;i<=n;i++) if(!cmp2(da[ans],da[i])) ans=i;
	cout<<da[ans].ans;
}
