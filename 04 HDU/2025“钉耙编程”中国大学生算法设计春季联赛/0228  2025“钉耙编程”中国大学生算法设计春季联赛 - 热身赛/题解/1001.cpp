#include<bits/stdc++.h>
using namespace std;
template<class code>inline code read(const code &a){
	code x=0;bool fg=0;
	char c=getchar();
	while(!isdigit(c)){
		fg|=(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return fg?-x:x;
}
int n;
long long k;
int a[100005],dd[100005],pl[100005],pr[100005],st[20][100005],lg[100005];
int gmn(int l,int r){
	if(l==r)return a[l];
	int cd=lg[r-l+1];
	return min(st[cd][l],st[cd][r-(1<<cd)+1]);
}
long long check(int x){
	long long fx=0;
	for(int i=1;i<=n;i++){
		int l=pl[i],r=i,kx1=-1;
		int sy=x-a[i];
		while(l<=r){
			int mid=(l+r)>>1;
			if(gmn(mid,i)>=sy)kx1=mid,r=mid-1;
			else l=mid+1;
		}
		int kx2=-1;
		l=i,r=pr[i];
		while(l<=r){
			int mid=(l+r)>>1;
			if(gmn(i,mid)>=sy)kx2=mid,l=mid+1;
			else r=mid-1;
		}
		if(kx1!=-1&&kx2!=-1)fx+=1ll*(i-kx1+1)*(kx2-i+1);

	}

	return fx;
}
void solve(){
	n=read(n),k=read(k);
	for(int i=1;i<=n;i++)a[i]=read(a[i]),st[0][i]=a[i];
	for(int i=1;i<=19;i++){
		for(int j=1;j+(1<<(i-1))<=n;j++){
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	int top=0;
	dd[top]=0;
	for(int i=1;i<=n;i++){
		while(top&&a[dd[top]]<=a[i])--top;
		pl[i]=dd[top]+1;
		dd[++top]=i;
	}
	top=0;
	dd[top]=n+1;
	for(int i=n;i>=1;i--){
		while(top&&a[dd[top]]<a[i])--top;
		pr[i]=dd[top]-1;
		dd[++top]=i;
	}

	long long l=0,r=2e9,kx=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)>=k)kx=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",kx);
}
int main(){

	for(int i=2;i<=100000;i++)lg[i]=lg[i>>1]+1;
	int t=read(t);
	while(t--)solve();
	return 0;
} 
