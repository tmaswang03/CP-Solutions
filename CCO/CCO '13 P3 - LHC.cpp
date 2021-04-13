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
const ll MAXN = 4e5+1;
using namespace std;
vector<int>v[MAXN];
vector<pair< int, int > >sols;
int arr1[MAXN], arr2[MAXN], arrD[MAXN], ind, diameter;

void bfsmax(int node1, int arr1[]){
    queue<pair<int, int> >q;
    q.push({node1,-1});
    arr1[node1] = 0;
    while(!q.empty()){
        int temp1 = q.front().first, temp2 = q.front().second;  // node, parent
        q.pop();
        for(auto && i : v[temp1]){
            if(i != temp2){
                arr1[i] = arr1[temp1] + 1;
                if(arr1[i] > diameter){ ind = i; diameter = arr1[i];}
                q.push({i, temp1});
            }
        }
    }
}

void bfsdepth(int node1, int parent){
    queue<pair<int, int> >q; // node + parent;
    q.push({node1, parent});
    int arr1[MAXN];
    ms(arr1, 0);
    arr1[node1] = 1;
    int depth = 1;
    while(!q.empty()){
        int temp1 = q.front().first, temp2 = q.front().second;
        q.pop();
        for(auto && i : v[temp1]){
            if(i != temp2){
                arr1[i] = arr1[temp1] + 1;
                depth = max(depth, arr1[i]);
                q.push({i, temp1});
            }
        }
    }
    int counter = 0;
    for(int i = 1; i <= MAXN; ++i){
        if(arr1[i]==depth) ++counter;
    }
//    cout<<depth<<endl;
    sols.pb({depth, counter});

}

int main()
{
    int N; scan(N);
    for(int i = 0; i < N-1; ++i){
        int a,b; scan(a); scan(b);
        v[a].pb(b);
        v[b].pb(a);
    }
    // find centre and construct tree, ans = maxdepth of tree + max2depth of tree
    bfsmax(1, arr1);
    ms(arr1,0);
    diameter = 0;
    bfsmax(ind, arr1);
    bfsmax(ind, arr2);
    int radius = 0x3f3f3f, center = 0;
    for(int i = 1; i <= N; ++i){
        if(max(arr1[i],arr2[i])<radius){
            radius = max(arr1[i], arr2[i]);
            center = i;
        }
    }
//    cout<<center<<endl;
    for(auto && i : v[center]){
//        cout<<i<<" ";
        bfsdepth(i, center);
    }
    sort(sols.begin(), sols.end(), greater<pair<int, int> >());
    int counter1 = 0, sums = 0;
    if(sols[0].first==sols[1].first){
        for(int i = 0; i < sols.size(); ++i){
            if(sols[i].first == sols[0].first){ counter1++; sums += sols[i].second;}
            else break;
        }

        cout<<sols[0].first*2+1<<" ";
        __int128 res = 0;
        for(int i = 0; i < counter1; ++i){
            res+=(sums-sols[i].second)*sols[i].second;
        }
        cout<<(ll)(res/2)<<endl;
    }
    else{
//        for(int i = 0; i < sols.size(); ++i){
//            cout<< sols[i].first<<" "<<sols[i].second<<endl;
//        }
        for(int i = 1; i < sols.size(); ++i){
            if(sols[i].first == sols[1].first) counter1+=sols[i].second;
            else break;
        }
        cout<<sols[0].first + sols[1].first + 1<<" "<<sols[0].second*counter1<<endl;
    }





    return 0;
}
