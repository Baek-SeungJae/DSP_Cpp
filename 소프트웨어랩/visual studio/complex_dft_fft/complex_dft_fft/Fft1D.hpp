#include <complex>
using namespace std;

#ifndef __FFT
#define __FFT

#define Real double

class FFT               
{
	int N,NU;               // N = 2**NU
	void InitializeFFT();
	void DITFFT(int);       // 1-D decimation-in-time FFT
	complex<Real> *W;       // W[k] = exp(-2pi*k/N)

	public:
	FFT(int);               // one dimensional constructor
	FFT(Real *,int);        // one dimensional constructor
	~FFT();

	complex<Real> *x, *X;   // x[n]  <-->  X[k]
	void ForwardFFT();  // x[n] ==> X[k]
	void InverseFFT();  // X[k] ==> x[n]
};
#endif


class DFT
{
	int N, NU;               // N = 2**NU
	void InitializeDFT();
	void DITDFT(int);       // 1-D decimation-in-time FFT
	complex<Real> *W;       // W[k] = exp(-2pi*k/N)
	complex<Real> *w;
public:
	DFT(int);               // one dimensional constructor
	DFT(Real *, int);        // one dimensional constructor
	~DFT();

	complex<Real> *x, *X;   // x[n]  <-->  X[k]
	void ForwardDFT();  // x[n] ==> X[k]
	void InverseDFT();  // X[k] ==> x[n]
};