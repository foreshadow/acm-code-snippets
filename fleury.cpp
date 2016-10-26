Fleury£¨¸¥ÂÞÀ³£©Ëã·¨
int a[5*MAXN];
int b[5*MAXN];
int d[MAXN];
bool vis[MAXN];
int n,m;
int ans,num,cnt;
int mm[MAXN][MAXN];
void dfs(int u){
    a[num++] = u;
    for(int i = 1 ; i <= n ; i++){
        if(mm[u][i]){
            mm[u][i]--;
            mm[i][u]--;
            dfs(i);
            break;
        }
    }
}
void fleury(int ss){
    int brige;
    num = 0;
    a[num++] = ss;
    while(num>0){
        brige = 1;
        for(int i = 1 ; i <= n ; i++){
            if(mm[a[num-1]][i]){
                brige = 0;
                break;
            }
        }
        if(brige)
            b[cnt++] = a[--num];
            //printf("%d ",a[--num]);
        else dfs(a[--num]);
    }
}
int main()
{
    int tt,ca = 1;
    int p,q;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < m ;i++){
        scanf("%d %d",&p,&q);
        mm[p][q]++;
        mm[q][p]++;
        d[p]++;
        d[q]++;
    }
    int s = 1;
    for(int i = 1 ; i <= n ; i++)
        if(d[i]%2)
        s = i;
    num = 0;
    cnt = 0;
    fleury(s);
    for(int i = 0 ; i < cnt ; i++){
        printf("%d",b[i]);
        printf("%c",i==num-1?'\n':' ');
    }
    return 0;
}
