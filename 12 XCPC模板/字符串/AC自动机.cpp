struct Tree
{
    int fail;//失配指针
    int vis[26];//子节点位置
    int end;//标记几个单词以这个节点结尾
}AC[1000010];//Trie树
int cnt=0;//Trie的指针
int insert(string s)
{
    int u=0;//字典树根节点
    for(auto i:s)
    {
        int v=i-'a';
        if(!AC[u].vis[v]) AC[u].vis[v]=++cnt;
        u=AC[u].vis[v];
    }
    AC[u].end++;//结尾个数增加
    return u;
}
void get_fail()
{
    queue<int>q;
    for(int i=0;i<26;i++)//第二层处理
    {
        if(AC[0].vis[i])
        {
            AC[AC[0].vis[i]].fail=0;//指向根节点
            q.push(AC[0].vis[i]);//压入队列
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            if(AC[u].vis[i])
            {
                AC[AC[u].vis[i]].fail=AC[AC[u].fail].vis[i];
                q.push(AC[u].vis[i]);
            }
            else AC[u].vis[i]=AC[AC[u].fail].vis[i];
        }
    }
}
int ac_query(string s)
{
    int u=0,ans=0;
    for(auto i:s)
    {
        int v=i-'a';
        u=AC[u].vis[v];
        for(int t=u;t&&AC[t].end!=-1;t=AC[t].fail)
        {
            ans+=AC[t].end;//加上个数
            AC[t].end=-1;//清空
        }
    }
    return ans;//返回总个数
}