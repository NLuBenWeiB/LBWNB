void Deal_first(int u,int father)  
{
    Dep[u]=Dep[father]+1;    
    for(int i=0;i<=19;i++)    
    f[u][i+1]=f[f[u][i]][i];  
    for(int e=first[u];e;e=next[e])    
    {
        int v=go[e];    
        if(v==father) continue;    
        f[v][0]=u;                       //v向上跳2^0=1就是u    
        Deal_first(v,u);    
    }    
} 
