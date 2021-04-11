
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr1[5]={};
    for(int i = 0 ; i < 5; i++){
        int b; cin>>b;
        arr1[i]=b;
    }
	int primes[100000]={};
	int counter=0;
	for(int i = 0; i < 100000; ++i){
        primes[i]=i;
	}
	primes[1]=0;

	int i = 2;
	int totalcounter=0;
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
    for(int i = 0; i < 5; i++){
        totalcounter = 0;
        for(int j = 0; j < arr1[i]; j++){
            if(primes[j]!=0){
                totalcounter+=primes[j];
            }
        }
        cout<<totalcounter<<endl;
    }



	return 0;
}


