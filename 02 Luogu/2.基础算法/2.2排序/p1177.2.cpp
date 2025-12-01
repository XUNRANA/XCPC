#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],c[100010],d[100010];//普通快排，第一个为基准，有时达n*n 
int randint(int l,int r)
{
    return rand()%(r-l+1)+l;
}
void qsort(int l, int r)
{
    if(l>=r) return;
	int num=randint(l,r),ind1=0,ind2=0,ind3=0;// 随机选择一个数，并定义三个作为下标的变量来记录长度、存放数据
	for(int i=l;i<=r;i++)
	{
	    if(a[i]<a[num]) b[ind1++]=a[i];
		else if(a[i]==a[num]) c[ind2++]=a[i];
		else d[ind3++]=a[i];
	}
	for(int i=0;i<ind1;i++) a[i+l]=b[i];
	for(int i=0;i<ind2;i++) a[i+ind1+l]=c[i];
	for(int i=0;i<ind3;i++) a[i+ind1+ind2+l]=d[i];
	qsort(l,l+ind1-1);
	qsort(l+ind1+ind2,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	qsort(1,n);
    cout<<a[1];
	for(int i=2;i<=n;i++) cout<<" "<<a[i];
    cout<<"\n";
}
