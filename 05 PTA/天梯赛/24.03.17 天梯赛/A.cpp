#include <bits/stdc++.h>
using namespace std;
int l,r,ans,p,p1;
int v[10010],res[10010];
int f(int x)
{
    int res=0;
    while(x)
    {
        res+=(x%10)*(x%10);
        x/=10;
    }
    return res;
}
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int main()
{
	cin>>l>>r;
	for(int i=2;i<=10000;i++)
	{
		int j=i;
		set<int>s;
        while(1)
        {
            if(f(j)==1)
            {
            	s.insert(1);
            	ans=s.size();
            	if(is(i)) ans*=2;
            	res[i]=ans;
                break;
            }
            else 
            {
            	p=s.size();
            	s.insert(j);
            	p1=s.size();
            	if(p==p1) break;
            	j=f(j);
			}
        }
	}
	map<int,int>m;
	for(int i=l;i<=r;i++) m[f(i)]=1;
	for(int i=l;i<=r;i++) if(res[i]&&m[i]!=1) cout<<i<<" "<<res[i]<<"\n";
}
