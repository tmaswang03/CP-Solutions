#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 100001;
using namespace std;
int main()
{
    int N; cin>>N;
    pair<int, int> arr[N+1]; //time to finish, // time it takes
    int maxt = 0;
    for(int i =0 ; i < N; ++i){
        int a,b; cin>>a>>b;
        maxt = max(maxt,b);
        arr[i]={b,a};
    }
    sort(arr,arr+N);
    int starttime = 0;
    int a = 0, b = maxt, temp = 0;
    while(a<=b){
        int i = (a+b)/2;
        int tottime = 0;
        bool ispos = true;
        for(int k = 0; k < N; ++k){
            tottime+=arr[k].second;
            if(tottime+i>arr[k].first){
                ispos = false;
                break;
            }
        }
        if(ispos == false){
            b = i-1;
        }
        else{
            temp = max(temp,i);
            a = i+1;
        }
    }
    int tottime = 0;
    bool ispos = true;
    for(int k = 0; k < N; ++k){
        tottime+=arr[k].second;
        if(tottime>arr[k].first){
            ispos = false;
            break;
        }
    }
    if(ispos){
        cout<<temp<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
