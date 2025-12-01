#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,L,k;
int main()
{
    cin>>n>>L>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ma=0;
    for(int i=0;i<n;i++) ma=max(ma,(a[(i+k+1)%n]-a[i]+L)%L);
    cout<<ma;
}