#include<iostream>
#include<math.h>
using namespace std;
//finding the compliment using bitmusk
//like 5 = 101
//so it's compliment will be 2 = 010

int func(int n)
{
   int m = n;
   int mask = 0;
   if(n == 0)return 1;// this is corner case

   while(m!= 0)
   {
       mask = (mask << 1) | 1;
       m  = m>>1;
   }
   int ans = mask & (~n);
   return ans;
}
int main()
{
    int n ;
    cin>>n;
    cout<<func(n)<<endl;

    return 0;
}
