#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *x,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(x+i);
        if((i+1)%M==0) cout << endl;
        else cout << " ";
    }
}

void randData(double *x,int N,int M){
    for(int i = 0; i < N*M; i++){
        *(x+i) = (rand()%101)/100.00;
    }
}

void findRowSum(const double *x,double *y,int N,int M){
    for(int i=0;i<N;i++) *(y+i)=0;
    
    int count = 0;
	for(int i=0;i<N*M;i++){
	    *(y+count)+=*(x+i);
	    if((i+1)%M==0) count++;
	}
}

/*	double for loop
void findRowSum(const double *x,double *y,int N,int M){
    for(int i=0;i<N;i++) *(y+i)=0;

    int count = 0;
 	for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            *(y+i)+=*(x+count);
            count++;
        }
    }
}*/

void findColSum(const double *x,double *y,int N,int M){
    for(int i=0;i<M;i++) *(y+i)=0;
    
    int count = 0,a=0;
	for(int i=0;i<N*M;i++){
	    count=i%M; 
	    *(y+count)+=*(x+i);
	}
}

/*void findColSum(const double *x,double *y,int N,int M){
    for(int i=0;i<M;i++) *(y+i)=0;
    
    int count = 0,a=0;
	for(int i=0;i<N*M;i++){
	    count=(i+1)%M;
	    if(count>0){
	        count--;
	        a++;
	        }
	    else if(count==0)   count=a;
	    
	    *(y+count)+=*(x+i);
	    
	    if(count==a)    a=0;
	}
}*/


/*void findColSum(const double *x,double *y,int N,int M){
    for(int i=0;i<M;i++) *(y+i)=0;
    
    int count = 0;
	for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            *(y+M)+=*(x+count);
            count++;
        }
    }
}*/