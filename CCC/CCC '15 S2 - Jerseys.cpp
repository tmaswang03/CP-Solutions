#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;

using namespace std;

int main()
{
    int J,A; cin>>J>>A;
    char arr[J+1];
    bool used[J+1];
    for(int j = 1; j <= J; ++j){
        char s; cin>>s;
        arr[j]=s;
    }
    ms(used,0);
    int counter = 0;
    for(int i = 0; i < A; ++i){
        char s; cin>>s;
        int N; cin>>N;
        if(s=='S' && !used[N]){
            ++counter;
            used[N]=1;
        }
        else if(s=='M' && (arr[N]=='M'||arr[N]=='L') && !used[N]){
            ++counter;
            used[N]=1;
        }
        else if(s=='L' && arr[N]=='L' && !used[N]){
            ++counter;
            used[N]=1;
        }
    }
    cout<<counter<<endl;
    return 0;
}
