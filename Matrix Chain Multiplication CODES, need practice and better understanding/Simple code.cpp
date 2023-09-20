// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main()
{
int n=5;
int P[] = {5, 4, 6, 2, 7};
int m[5][5] = {0};
int s[5][5] = {0};
int j, min, q;
for (int d=1; d<n-1;d++)
{
for (int i=1;i<n-d; i++)
{
j=i+d;
min= 32767;
for(int K=i; K <=j-1; K++)
{
q=m[i][K] + m[K+1][j] + P[i-1] *P[K]* P[j];
if(q < min)
{
min=q; 
s[i][j]=K;
}
}
m[i][j]= min;
}
}
cout<<m[1][n-1];
}
