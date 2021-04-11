#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e6+10;
const ll INF = 0x3f3f3f;
using namespace std;
char _;


int arr[MAXN];

int main()
{
    int N,M,J, pos = 0, time = 0; scan(N); scan(M); scan(J);ms(arr,-1);
    for(int i = 0; i < M; ++i){
        int p,t; scan(p); scan(t);
        arr[p] = t;
    }
    arr[N+1] = 0;
    while(pos<N+1){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq; //stores shortest time and position;
        for(int i = pos+1; i <= pos+J; ++i){
            if(arr[i]!=-1)
                pq.push({arr[i], i});
        }
        if(pq.empty())break;
        pos = pq.top().s;
        time = max(time, pq.top().f);
    }
    printf(pos<N? "-1\n" : "%d\n", time);

    return 0;
}
