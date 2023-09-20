#include <stdio.h>

int main(void) {
  int n=5;
  int P[]={5,4,6,2,7};
  int M[5][5]={0};
  int S[5][5]={0};
  int j,min,q;


//EMPTY MATRIX FOR TABLE M
printf("Empty table for Matrix M\n\n");
  for(int d=1;d<n;d++){
    for(int i=1;i<n;i++){
      printf("\t%d",M[d][i]);
    }
    printf("\n");
  }
  printf("\n");

  for(int d=1;d<n-1;d++){
    for(int i=1;i<n-d;i++){
      j=i+d;
      min=32767;
      for(int k=1;k<=j-1;k++){
        if(i<=k && k<j){
          q = M[i][k] + M[k+1][j] + P[i-1] * P[k] * P[j];
          if(q<min){
            min=q;
            S[i][j]=k;
          }
      }
      }
      M[i][j]=min;
    }
  }

//MATRIX FOR TABLE M
printf("Table for Matrix M\n\n");
  for(int d=1;d<n;d++){
    for(int i=1;i<n;i++){
      printf("\t%d",M[d][i]);
    }
    printf("\n");
  }
  printf("\n");



//MATRIX FOR TABLE S
printf("Table for Matrix S\n\n");
  for(int d=1;d<n;d++){
    for(int i=1;i<n;i++){
      printf("\t%d",S[d][i]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Minimum number of Calculation = %d\n",M[1][n-1]);
  printf("Paranthesis position %d and %d",S[1][n-2],S[1][n-1]);

  return 0;
}
