#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
int BIT[100000];
int arr[100000];

int getSum(int index){
    int sum = 0;
    while(index > 0){
        sum+=BIT[index];
        index -= (index & -index);
    }
    return sum;
}

int range(int left, int right){
    int sum = getSum(right)-getSum(left-1);
    return sum;
}

void update(int n, int index, int val){
    while(index <= n){
        BIT[index]+=val;
        index += (index & -index);
    }
}

void convert(int arr[], int N){
    int temp[100000];
    for(int i = 0; i < N; ++i){
        temp[i]=arr[i];
    }
    sort(temp,temp+N);
    for(int i = 0; i < N; ++i){
        arr[i]= lower_bound(temp,temp+N,arr[i]) - temp + 1;
    }


}


ull inversions(int N){
    ull invcount=0;
    for(int i = N-1; i>=0; --i){
        invcount +=getSum(arr[i]-1);
        update(N,arr[i],1);
    }
    return invcount;
}


int main()
{
    ms(BIT,0);
    int N; gc(N);
    for(int i = 0; i < N; ++i){
        int a; gc(a);
        arr[i]=a;
    }
    convert(arr,N);
//    for(int i = 0; i < N; ++i){
//        printf("%i, ",arr[i]);
//    }
    ms(BIT,0);
    ull temp1=inversions(N)+N;
    double temp = (long double)(temp1)/(long double)N;
    printf("%.2lf\n",temp);
//    for(int i = 0; i <= N; ++i){
//        printf("%i, ",BIT[i]);
//    }

    return 0;
}
