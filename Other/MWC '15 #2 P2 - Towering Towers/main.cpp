#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e6+1;
using namespace std;
char _;
int arr[MAXN];
int main()
{
    int N; scan(N);
    stack<int> s;
    for(int i = 1; i <= N; ++i){
        cin>>arr[i];
    }
    arr[1] = 0x3f3f3f;
    s.push(1);
    cout<<"0"<<" ";
    for(int i = 2; i <= N; ++i){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }
        cout<<i-s.top()<<" ";
        s.push(i);
    }
    return 0;
}
