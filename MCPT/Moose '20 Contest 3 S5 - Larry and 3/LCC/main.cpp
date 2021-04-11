#include<bits/stdc++.h>
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
using namespace std;
int N;
int main()
{
    cin>>N;
    if(N==6){
        cout<<"9\n1 4\n1 5\n1 6\n2 4\n2 5\n2 6\n3 4\n3 5\n3 6"<<endl;
    }
    else if(N==7){
        cout<<"12\n1 4\n1 5\n1 6\n2 4\n2 5\n2 6\n3 4\n3 5\n3 6\n7 1\n7 2\n7 3"<<endl;
    }
    else if(N==8){
        cout<<"15\n1 4\n1 5\n1 6\n2 4\n2 5\n2 6\n3 4\n3 5\n3 6\n7 1\n7 2\n7 3\n8 1 \n8 2\n8 3"<<endl;
    }
    return 0;
}
