#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
ll i,j,a,b,c,res;
ll g(ll w)
{
    w%=M; 
    return (w*w+w)%M*((M+1)/2)%M;
}
ll f(ll w)
{
    w=g(w); 
    return w*w%M;
}

int main()
{
	cin>>a>>b>>c;
	for(i=1;i<=min({a,b,c});i=j+1)
    {
		j=min({a/(a/i),b/(b/i),c/(c/i)});
		res+=(f(j)-f(i-1)+M)%M*g(a/i)%M*g(b/i)%M*g(c/i)%M;
	}
	cout<<res%M;
}