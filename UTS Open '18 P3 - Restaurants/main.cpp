#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    int N,T,K,V, tempcounter = 0; scan(N); scan(T); scan(K); scan(V);
    bool arr[N+1]; ms(arr,0);
    for(int i = 0; i < V; ++i){
        int it; scan(it); --it; arr[it] = 1;
        if(it<T) ++tempcounter;
    }
    int p2 = T-1, counter = 0;
    vector<int>v;
    for(int i = 0; i < T; ++i){
        if(!arr[i]) v.pb(i);
    }
    sort(v.begin(),v.end());
    while(tempcounter<K){
        arr[v[v.size()-1]]=1;
        v.pop_back();
        ++counter; ++tempcounter;
    }
    while(p2<N-1){
        ++p2;
        if(arr[p2-T]){
            --tempcounter;
        }
        if(arr[p2]){
            ++tempcounter;
        }
        if(tempcounter<K){
            arr[p2] = 1;
            ++tempcounter;
            ++counter;
        }
    }
    cout<<counter<<endl;
    return 0;
}
