#include <bits/stdc++.h>
using namespace std;
long long a[1010];
long long f(long long n)
{
	if(a[n]) return a[n];
	for(int i=0;i<=n/2;i++) a[n]+=f(i);
	return a[n];
}
int main()
{
	long long n;
	cin>>n;
    a[0]=1;
	cout<<f(n);
}

/*
#include <bits/stdc++.h>
using namespace std;
int f[2000],n;
int main()
{
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=i/2;j++) f[i]+=f[j];
		f[i]++;
	}
	cin>>n;
	cout<<f[n];
}

f1 1
f2 1+f1
f3 1+f1
f4 1+f1+f2 1+f1+1+f1
f5 1+f1+f2 1+f1+1+f2
*/
