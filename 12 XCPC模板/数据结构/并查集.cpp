for(int i=1;i<=n;i++) fa[i]=i;
void merge(int x,int y)
{
	fa[find(x)]=find(y);
	/*
	还可以启发式合并 
	*/
} 
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}