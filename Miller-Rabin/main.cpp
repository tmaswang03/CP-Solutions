#include <iostream>
#include<stdlib.h>
using namespace std;
unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long m)//It returns true if number is prime otherwise false {
   unsigned long long x = 0;
   unsigned long long y = a % m;
   while (b > 0) {
      if (b % 2 == 1) {
         x = (x + y) % m;
      }
      y = (y * 2) % m;
      b /= 2;
   }
   return x % m;
}

unsigned long long modulo(unsigned long long base, unsigned long long e, unsigned long long m) {
   unsigned long long x = 1;
   unsigned long long y = base;
   while (e > 0) {
      if (e % 2 == 1)
         x = (x * y) % m;
         y = (y * y) % m;
         e = e / 2;
   }
   return x % m;
}

bool Miller(unsigned long long p, int iteration) {
   if (p < 2) {
      return false;
   }
   if (p != 2 && p % 2==0) {
      return false;
   }
   unsigned long long s = p - 1;
   while (s % 2 == 0) {
      s /= 2;
   }
   for (int i = 0; i < iteration; i++) {
      unsigned long long a = rand() % (p - 1) + 1, temp = s;
      unsigned long long mod = modulo(a, temp, p);
      while (temp != p - 1 && mod != 1 && mod != p - 1) {
         mod = mulmod(mod, mod, p);
         temp *= 2;
      }
      if (mod != p - 1 && temp % 2 == 0) {
         return false;
      }
   }
   return true;
}

int main() {
   int iteration = 20;
   unsigned long long num;
   cin>>num;
   if(num<=2){
    cout<<2<<endl;
    exit(0);
   }
   if(num%2==0){
    ++num;
   }
   while(!Miller(num,10)){
    num+=2;
   }
   cout<<num<<endl;
   return 0;
}
