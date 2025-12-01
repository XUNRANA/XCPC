#include <bits/stdc++.h>
using namespace std;
long long a1,a2,n;
int main()
{
	cin>>a1>>a2>>n;
	cout<<(a1+a1+(n-1)*(a2-a1))*n/2;	
} 
