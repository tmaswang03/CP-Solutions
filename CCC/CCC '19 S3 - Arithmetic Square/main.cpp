#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll inf = 1e9;
using namespace std;
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937_64 gen(seed1); uniform_int_distribution<ll> dis(0, 1e7);
ll a[3][3], o[3][3], cnt, ocnt; string in;
bool checkv(int i, int j){
    int cnt = 0;
    for(int i = 0; i < 3; ++i) cnt+=a[i][j]!=inf;
    return cnt==2;
}
bool checkh(int i, int j){
    int cnt = 0;
    for(int j = 0; j < 3; ++j) cnt+=a[i][j]!=inf;
    return cnt==2;
}
bool valid(){
    for(int i = 0; i < 3; ++i){
        if(a[i][1]-a[i][0]!= a[i][2]-a[i][1]) return 0;
        if(a[1][i]-a[0][i]!=a[2][i]-a[1][i]) return 0;
    }
    return 1;
}
void prnt(){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
}
void fil(){
    for(int i = 0;  i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(checkv(i, j) && a[i][j]==inf){
                if(i==1) a[i][j] = (a[0][j]+a[2][j])/2;
                else if(i==0) a[i][j] = (2*a[1][j]-a[2][j]);
                else a[i][j] = (2*a[1][j]-a[0][j]);
                --cnt;
            }
            if(checkh(i, j) &&a[i][j]==inf){
                if(j==1) a[i][j] = (a[i][0]+a[i][2])/2;
                else if(j==0) a[i][j] = (2*a[i][1]-a[i][2]);
                else a[i][j] = (2*a[i][1]-a[i][0]);
                --cnt;
            }
        }
    }
    for(int i = 0;  i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(checkh(i, j) &&a[i][j]==inf){
                if(j==1) a[i][j] = (a[i][0]+a[i][2])/2;
                else if(j==0) a[i][j] = (2*a[i][1]-a[i][2]);
                else a[i][j] = (2*a[i][1]-a[i][0]);
                --cnt;
            }
            if(checkv(i, j) && a[i][j]==inf){
                if(i==1) a[i][j] = (a[0][j]+a[2][j])/2;
                else if(i==0) a[i][j] = (2*a[1][j]-a[2][j]);
                else a[i][j] = (2*a[1][j]-a[0][j]);
                --cnt;
            }
        }
    }
}
void run(){
    while(cnt){
        fil();
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(checkv(i, j)||checkh(i, j)||a[i][j]!=inf) continue;
                a[i][j] = dis(gen);
                --cnt;
                fil();
            }
        }
    }
}
int main()
{
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin>>in;
            if(in!="X") o[i][j] = stoi(in);
            else {o[i][j] = inf; ++ocnt;}
            a[i][j] = o[i][j];
        }
    }
    while(!valid()){
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j )a[i][j] = o[i][j];
         cnt = ocnt;
        run();
    }
    prnt();
    return 0;
}
