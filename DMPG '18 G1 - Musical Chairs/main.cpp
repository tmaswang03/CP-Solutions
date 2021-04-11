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
int main()
{
    int N, K; scan(N); scan(K);
    bool visited[MAXN]; int student[MAXN]; ms(visited, 1); ms(student, 0);
    stack<int>s;
    int counter = K+1;
    for(int i = 0; i < K; ++i){
        int a; scan(a); --a; visited[a] = 0;
    }
    for(int i = 1; i <= K+1; ++i){
        int a; scan(a); --a; student[a] = i;
    }
    int i = 0;
    while(counter>1){
        if(student[i]){
            s.push(student[i]);
            student[i] = 0;
        }
        if(!visited[i] && !s.empty()){
            s.pop();
            visited[i] = 1;
            --counter;
        }
        ++i; i%=N;
    }
    cout<<s.top()<<endl;
    return 0;
}
