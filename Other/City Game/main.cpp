#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e3+10;
using namespace std;
char _;
bool arr[MAXN][MAXN];


int main()
{
    int K; scan(K);
    for(int i = 0; i < K; ++i){
        int N, M, res = 0; scan(N); scan(M);
        ms(arr, 0);
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < M; ++c){
                char s; scanf("%s", &s);
                if(s=='F') arr[r][c] = 1;
            }
        }
        int temparr[MAXN]; ms(temparr, 0);
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < M; ++c){
                if(arr[r][c]) ++temparr[c];
                else temparr[c] = 0;
            }
            temparr[M] = -1;
            stack<int>s;
            int i = 0;
            while(i < M){
                if(s.empty()|| temparr[s.top()]<=temparr[i]) s.push(i++);
                else{
                    int temp1 = s.top(); s.pop();
                    if(s.empty()) res = max(res, temparr[temp1] * i);
                    else res = max(res, temparr[temp1] * (i - s.top() -1));
                }
            }
            while(!s.empty()){
                int temp1 = s.top(); s.pop();
                if(s.empty()) res = max(res, temparr[temp1] * i);
                else res = max(res, temparr[temp1] * (i - s.top() -1));
            }
        }
        printf("%i\n", 3*res);
    }
    return 0;
}
