#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define inf 0x3fffffff
 
int n;
char a[1000010];
char s[1000010];
struct data
{
    int Min,Max,x,tag;
}tree[4000010];
 
void build(int l,int r,int x)
{
    tree[x].x=0;
    tree[x].tag=0;
    tree[x].Min=0;
    tree[x].Max=0;
    if (l==r) return ;
    int mid=l+r>>1;
    build(l,mid,x<<1);build(mid+1,r,x<<1|1);
}
 
void Pushdown(int x)
{
    if (tree[x].tag)
    {
        tree[x<<1].tag+=tree[x].tag;
        tree[x<<1|1].tag+=tree[x].tag;
        tree[x<<1].Max+=tree[x].tag;
        tree[x<<1].Min+=tree[x].tag;
        tree[x<<1|1].Max+=tree[x].tag;
        tree[x<<1|1].Min+=tree[x].tag;
        tree[x].tag=0;
    }
}
 
void change(int lq,int rq,int q,int l,int r,int x)
{
    if (lq<=l&&rq>=r)
    {
        tree[x].tag+=q;
        tree[x].Max+=q;
        tree[x].Min+=q;
        return ;
    }
    int mid=l+r>>1;
    Pushdown(x);
    if (lq<=mid) change(lq,rq,q,l,mid,x<<1);
    if (rq>mid) change(lq,rq,q,mid+1,r,x<<1|1);
    tree[x].Max=max(tree[x<<1].Max,tree[x<<1|1].Max);
    tree[x].Min=min(tree[x<<1].Min,tree[x<<1|1].Min);
}
 
int querymin(int lq,int rq,int l,int r,int x)
{
    if (lq<=l&&rq>=r) return tree[x].Min;
    int mid=l+r>>1,ans=inf;
    Pushdown(x);
    if (lq<=mid) ans=min(ans,querymin(lq,rq,l,mid,x<<1));
    if (rq>mid) ans=min(ans,querymin(lq,rq,mid+1,r,x<<1|1));
    tree[x].Max=max(tree[x<<1].Max,tree[x<<1|1].Max);
    tree[x].Min=min(tree[x<<1].Min,tree[x<<1|1].Min);
    return ans;
}
 
int querymax(int lq,int rq,int l,int r,int x)
{
    if (lq<=l&&rq>=r) return tree[x].Max;
    int mid=l+r>>1,ans=-inf;
    Pushdown(x);
    if (lq<=mid) ans=max(ans,querymax(lq,rq,l,mid,x<<1));
    if (rq>mid) ans=max(ans,querymax(lq,rq,mid+1,r,x<<1|1));
    tree[x].Max=max(tree[x<<1].Max,tree[x<<1|1].Max);
    tree[x].Min=min(tree[x<<1].Min,tree[x<<1|1].Min);
    return ans;
}
 
int main()  // CF 1263E
{
    scanf("%d%s",&n,s+1);
    build(1,n,1);
    memset(a,0,sizeof(a));
    int l=1;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='(')
        {
            if (a[l]=='(') change(l,n,0,1,n,1);
            else if (a[l]==0) change(l,n,1,1,n,1);
            else if (a[l]==')') change(l,n,2,1,n,1);
            a[l]='(';
        }
        else if (s[i]==')')
        {
            if (a[l]==')') change(l,n,0,1,n,1);
            else if (a[l]==0) change(l,n,-1,1,n,1);
            else if (a[l]=='(') change(l,n,-2,1,n,1);
            a[l]=')';
        }
        else if (s[i]=='L')
        {
            l--;
            if (l==0) l=1;
        }
        else if (s[i]=='R') l++;
        else
        {
            if (a[l]==')') change(l,n,1,1,n,1);
            else if (a[l]=='(') change(l,n,-1,1,n,1);
            a[l]=0;
        }
        if (querymin(1,n,1,n,1)>=0&&querymin(n,n,1,n,1)==0)
            printf("%d ",querymax(1,n,1,n,1));
        else printf("-1 ");
    }
    return 0;
}
