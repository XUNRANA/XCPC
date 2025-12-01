#include <bits/stdc++.h>
using namespace std;
int n,a[100010];//普通快排，第一个为基准，有时达n*n 
int partition(int *a,int l,int r)
{
	int p=a[l],t;
	while(l<r)
	{
		while(l<r&&a[r]>=p) r--;
		t=a[r];
		a[r]=a[l];
		a[l]=t;
		while(l<r&&a[l]<=p) l++;
		t=a[r];
		a[r]=a[l];
		a[l]=t;
	}
	return l;
}
void quicksort(int *a,int l,int r)
{
	if(l<r)
	{
		int p=partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	quicksort(a,1,n);
    cout<<a[1];
	for(int i=2;i<=n;i++) cout<<" "<<a[i];
    cout<<"\n";
}
/*
4' 2 4 5 1

1 2 4 5 4'

1 2 4 4' 5 return 4 
1 2 4    5

1 2 4 return 1
2 4 return 1
*/
