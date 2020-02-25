#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define a0 1/pow(8,0.5)
#define an 0.5
#define pi 3.141592
void print(float*A, int a, int b);
void matrixMultiplication(float*A, float*B, float*C, int a, int b);
void swaprow(float*A, float*Ap, int a, int b, int c, int d);
void swapcol(float*A, float*Ap, int a, int b, int c, int d);
int main()
{
	float *A, *B, *C, *Ap, *Bp, *Cp;
	int a = 8;
	int b = 8;

	int m = rand() % 8;
	int n = rand() % 8;

	// 2瞒盔青纺 A, B积己
	A = new float[a*b];
	B = new float[a*b];
	C = new float[a*b];

	Ap = new float[a*b];
	Bp = new float[a*b];
	Cp = new float[a*b];

	// an=0老锭
	for (int j = 0; j < b; j++)
	{
		A[0*b+j] = a0;
	}
	// an=1~7老锭
	for (int i = 1; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			A[i*a+j] = an*cos((pi*i*(2*j+1))/16);
		}
	}

	// bn=0老锭
	for (int i = 0; i < b; i++)
	{
		B[i*b+0] = a0;
	}
	// bn=1~7老锭
	for (int i = 1; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			B[j*a+i] = an*cos((pi*i*(2 * j + 1)) / 16);
		}
	}

	matrixMultiplication(A, B, C, a, b);
	print(A, a, b);
	print(B, a, b);
	print(C, a, b);

	swaprow(A, Ap, a, b, 0, 0);
	swapcol(B, Bp, a, b, m, n);
	matrixMultiplication(A, Bp, Cp, a, b);
	print(Ap, a, b);
	print(Bp, a, b);
	print(Cp, a, b);


	cout << m << n;
	system("pause");
	return 0;
}

void print(float*A,int a,int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << setw(7) << fixed << setprecision(3) << A[i*a+j];
		}
		cout << endl;
	}
	cout << endl;
}

void matrixMultiplication(float*A, float*B, float*C, int a, int b)
{
	float temp=0;
	for (int i = 0; i < a; i++)
	{
		
		for (int j = 0; j < b; j++)
		{
			temp = 0;
			for(int k=0; k<b;k++)
			temp += A[i*a+k]*B[k*a+j];
			C[i*a+j] = temp;
		}
	}
}


void swaprow(float*A, float*Ap, int a, int b, int c, int d)
{

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			Ap[i*a + j] = A[i*a + j];
		}
	}


	for (int j = 0; j < b; j++)
	{
		Ap[c*b + j] = A[d*b + j];
		Ap[d*b + j] = A[c*b + j];

	}
}

void swapcol(float*A, float*Ap, int a, int b, int c, int d)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			Ap[i*a+j] = A[i*a + j];
		}
	}


	for (int j = 0; j < b; j++)
	{
		Ap[j*b + c] = A[j*b + d];
		Ap[j*b + d] = A[j*b + c];

	}
}