#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
using namespace std;

int main()
{
    int M; scan(M);
    int arr[101];
    bool replied[101], visited[101];
    ms(arr,0);
    ms(visited,0);
    ms(replied,0);
    char prev;
    for(int i = 0; i < M; ++i){
        char s; cin>>s;
        int x; scan(x);
        if(s=='R'){
            visited[x]=1;
            if(prev != 'W'){
                for(int j = 1; j <= 100; ++j){
                    if(replied[j]){
                        ++arr[j];
                    }
                }
            }
            replied[x]=1;
        }
        else if (s== 'S'){
            if(prev != 'W'){
                for(int j = 1; j <= 100; ++j){
                    if(replied[j]){
                        ++arr[j];
                    }
                }
            }
            replied[x]=0;
        }
        else{
            for(int j = 1; j <= 100; ++j){
                if(replied[j]){
                    arr[j]+=x;
                }
            }
        }
        prev=s;
    }
    for(int i = 1; i <= 100; ++i){
        if(visited[i]){
            if(!replied[i]){
                cout<<i<<" "<<arr[i]<<endl;
            }
            else{
                cout<<i<<" "<<-1<<endl;
            }
        }
    }
    return 0;
}
