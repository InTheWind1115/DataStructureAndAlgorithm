#include<iostream> 
#include<cmath>
#include<ctime>
using namespace std;
int main()
{ 
	int a[4][4],i,j,b[4][4];
    srand(time(0));

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            a[i][j]= rand()%100;

	for (i = 0; i < 4; i++)
	     for (j = 0; j < 4; j++)
	       	b[j][i]=a[i][j];

	for (i = 0; i < 4; i++) {
	    for (j = 0; j < 4; j++)
		    cout<<b[i][j]<<'\t';
	    cout<<endl;
	}

    system("pause");
    return 0;
}