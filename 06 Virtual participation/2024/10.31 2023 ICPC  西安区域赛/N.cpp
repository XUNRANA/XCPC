#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx(int a,int b,int c)
{
	if(a>b)
	{
		if(c>0) return 0;
//		5 1 -2
		int k=a-(b+1);
		k/=(-c);
		return (a+a+k*c)*(k+1)/2;
	}
	else if(a<b)
	{
		if(c<0) return 0;
		
		int k=(b-1)-a;
		k/=c;
		return (a+a+k*c)*(k+1)/2;
	}
	else return 0;
}
void solve()
{
/*
ans=0
    for a in range(1,3):
        for b in range(5,1,-2):
            ans+=b
    print(ans)
*/
	string s;
	cin>>s;
	cin>>s;
	cin>>s;
	cin>>s;
	
	cin>>s;
	vector<int>a;
	int num=0,f=0;
	for(auto i:s)
	{
		if(f)
		{
			num=-(num*10+i-'0');
			f=0;
			continue;
		}
		if(i=='-')
		{
			f=1;
			continue;
		}
		
		if(isdigit(i))
		{
			num=(num*10+i-'0');
		}
		else if(i==',')
		{
			a.push_back(num);
			num=0;
		}
		else if(i==')')
		{
			a.push_back(num);
			if(a.size()==2) a.push_back(1);
		}
	}
//	for(auto i:a) cout<<i<<" ";
//	cout<<"\n";
	
	
/*
ans=0
    for q in range(100,50,-1):
        for i in range(q,77,20):
        ans+=i
    print(ans)
*/
	cin>>s;
	cin>>s;
	cin>>s;
	
	cin>>s;
	vector<int>b;
	num=f=0;
	for(auto i:s)
	{
		if(f)
		{
			num=-(num*10+i-'0');
			f=0;
			continue;
		}
		if(i=='-')
		{
			f=1;
			continue;
		}
		
		if(isdigit(i))
		{
			num=(num*10+i-'0');
		}
		else if(i==',')
		{
			if(num==0) b.push_back(-1e7);
			else b.push_back(num);
			num=0;
		}
		else if(i==')')
		{
			b.push_back(num);
			if(b.size()==2) b.push_back(1);
		}
	}	
//	for(auto i:b) cout<<i<<" ";
//	cout<<"\n";
	
	int ans=0;
	if(a[0]>a[1])
	{
		for(int i=a[0];i>a[1];i+=a[2])
		{
			int d=b[0];
			int e=b[1];
			int f=b[2];
			if(d==-1e7) d=i;
			if(e==-1e7) e=i;
			if(f==-1e7) f=i;
			ans+=fx(d,e,f);
		}
	}
	else if(a[0]<a[1])
	{
		for(int i=a[0];i<a[1];i+=a[2])
		{
			int d=b[0];
			int e=b[1];
			int f=b[2];
			if(d==-1e7) d=i;
			if(e==-1e7) e=i;
			if(f==-1e7) f=i;
			ans+=fx(d,e,f);
		}
	}
	else ans=0;
	cout<<ans<<"\n";
	
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
