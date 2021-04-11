
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr1;
    vector<int> arr2;
	int n; cin >> n;
	arr1.resize(n);
	arr2.resize(n);
	int primes[1000000]={};
	int counter=0;
	for(int i = 0 ; i < 1000000; ++i){
        primes[i]=i;
	}
	for(int i = 0 ; i < n; i++){
        int a,b;    cin>>a>>b;
        arr1[i]=a;
        arr2[i] = b;
	}
	int i = 2;
    while ((i*i) <= 100000)
    {
        if (primes[i] != 0)
        {
            for(int j=2; j<100000; j++)
            {
                if (primes[i]*j > 100000)
                    break;
                else
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }
    primes[1]=0;
    for(int i = 0; i < n; i++){
        for(int j = arr1[i]; j<arr2[i]; j++){
            if(primes[j]!=0){
                ++counter;
            }
        }
        cout<<counter<<endl;
        counter=0;
    }



	return 0;
}


