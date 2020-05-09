#include<iostream>    
using namespace std;
const int N=2,M=3,K=4;
int  main()
{
	int a[N][M]={1,1,1,1,1,1}, b[M][K]={1,2,3,4,5,6,7,8,9,1,2,3};
	int i, j, k, c[N][N];
	for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
		    c[i][j]=0;
		    for (k = 0; k < M; k++)
		        c[i][j] = c[i][j] + a[i][k] * b[k][j];
	    }
    }
	 
	for (i = 0; i < N; i++) {
		for (j = 0; j < K; j++)
			cout<<c[i][j]<<'\t';
		cout<<endl;
	}
              
    system("pause");
    return 0;	
}