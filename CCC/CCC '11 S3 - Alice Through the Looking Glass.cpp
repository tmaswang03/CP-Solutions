#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;

using namespace std;

bool crystal(int m, int x, int y){
    if(m==1){
        if((x==1&&y==0)||(x==2&&y==0)||(x==3&&y==0)||(x==2&&y==1)) return true;
        else return false;
    }
    if((x>=pow(5,m-1)&&x<4*pow(5,m-1))&&y>=0&&y<pow(5,m-1)) return true;
    else if(x>=2*pow(5,m-1)&&x<3*pow(5,m-1)&&y>=pow(5,m-1)&&y<2*pow(5,m-1)) return true;
    else if(x>=pow(5,m-1)&&x<2*pow(5,m-1)&&y>=pow(5,m-1)&&y<2*pow(5,m-1)) return crystal(m-1,x-pow(5,m-1),y-pow(5,m-1));
    else if(x>=2*pow(5,m-1)&&x<3*pow(5,m-1)&&y>=2*pow(5,m-1)&&y<3*pow(5,m-1)) return crystal(m-1,x-2*pow(5,m-1),y-2*pow(5,m-1));
    else if(x>=3*pow(5,m-1)&&x<4*pow(5,m-1)&&y>=pow(5,m-1)&&y<2*pow(5,m-1)) return crystal(m-1,x-3*pow(5,m-1),y-pow(5,m-1));
    else return false;
}

int main()
{
    int T; gc(T);
    for(int i = 0; i < T; ++i){
        int x,y,m; gc(m);gc(x); gc(y);
        string s;
        if(crystal(m,x,y)==1) s="crystal";
        else s="empty";
        cout<<s<<"\n";
    }

    return 0;
}
