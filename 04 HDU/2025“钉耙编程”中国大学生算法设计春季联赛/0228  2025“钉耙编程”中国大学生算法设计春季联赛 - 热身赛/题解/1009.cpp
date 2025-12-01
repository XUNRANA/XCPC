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
bool dp[2005][40005];
int yu[2005][2005],hu[2005][2005],yh[2005][2005],n,a;
int pyu(int x,int y){
	if(x<=1023&&y<=1023)return yu[x][y];
	return pyu(x/a,y/a)*a+min(x%a,y%a);
}
int phu(int x,int y){
	if(x<=1023&&y<=1023)return hu[x][y];
	return phu(x/a,y/a)*a+max(x%a,y%a);
}
int pyh(int x,int y){
	if(x<=1023&&y<=1023)return yh[x][y];
	return pyh(x/a,y/a)*a+(x+y)%a;
}
void solve(){
	memset(yu,0,sizeof(yu));
	memset(hu,0,sizeof(hu));
	memset(yh,0,sizeof(yh));
	memset(dp,0,sizeof(dp));
	n=read(n),a=read(a);
	int x=read(x);
	for(int i=0;i<=1023;i++){
		for(int j=0;j<=1023;j++){
			yu[i][j]=yu[i/a][j/a]*a+min(i%a,j%a);
			hu[i][j]=hu[i/a][j/a]*a+max(i%a,j%a);
			yh[i][j]=yh[i/a][j/a]*a+((i+j)%a);
		}
	}
	dp[0][x]=1;
	for(int i=1;i<=n;i++){
		int z;
		scanf("%d",&z);
		for(int j=0;j<=40000;j++){
			if(!dp[i-1][j])continue;
			dp[i][pyu(j,z)]=1;
			dp[i][phu(j,z)]=1;
			dp[i][pyh(j,z)]=1;
		}
	}
	int ans=0;
	for(int i=0;i<=40000;i++){
		if(dp[n][i])ans+=i;
	} 
	printf("%d\n",ans);
}
int main(){
//	freopen("text.out","w",stdout);
	int t=read(t);
	while(t--)solve();
	return 0;
} 
