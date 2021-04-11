#include <iostream>
using namespace std;

int main()
{
	int primes[7000]={};
	int counter=0;
	for(int i = 0; i < 7000; ++i){
        primes[i]=i;
	}
  primes[1]=0;
	int i = 2;
    while ((i*i) <= 7000)
    {
        if (primes[i] != 0)
        {
            for(int j=2; j<7000; j++)
            {
                if (primes[i]*j > 7000)
                    break;
                else
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }
    int n,k;
    for(int i = 2 ; i <=n; i++){
        int counter =0;
        for(int i = 0 ; i < n; i++){

        }
    }

    return 0;
}
