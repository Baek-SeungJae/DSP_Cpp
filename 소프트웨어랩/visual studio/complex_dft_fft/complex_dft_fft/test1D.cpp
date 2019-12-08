
#include <iostream>
#include <fstream>
#include <complex>
#include "fft1D.hpp"
#include <ctime>

void FFFT(complex<Real>*func, int n, double*t);
void IFFT(complex<Real>*func, int n, double*t);
void FDFT(complex<Real>*func, int n, double*t);
void IDFT(complex<Real>*func, int n, double*t);
void initialize(int n, complex<Real>*square, complex<Real>*sine, complex<Real>*cosine);

clock_t start, endd, diff;

void main()
{
	int N = 128;
	double t1, t2, t3, t4;
	complex<Real>*square, *sine, *cosine;
	square = new complex<Real>[N];
	sine = new complex<Real>[N];
	cosine = new complex<Real>[N];
	initialize(N, square, sine, cosine);


	// test 1: FFT of square x[n]
	FFFT(cosine, N, &t1);
	// test 2: FFT of ideal low pass filter X[k]
	IFFT(square, N, &t2);
	// test 3: DFT of square x[n]
	FDFT(sine, N, &t3);
	// test 4: FFT of ideal low pass filter X[k]
	IDFT(square, N, &t4);



	cout << t1 << endl << t2 << endl << t3 << endl << t4 << endl;
	system("pause");
	return;
}

void initialize(int l, complex<Real>*square, complex<Real>*sine, complex<Real>*cosine)
{
	int N = l;
		for (int n = 0; n<N; n++)    square[n] = complex<Real>(0.0, 0.0);
		for (int n = 0; n<16; n++)   square[n] = complex<Real>(1.0, 0.0);
		for (int n = N - 15; n<N; n++) square[n] = complex<Real>(1.0, 0.0);

		int f1 = 32; // ÁÖÆÄ¼ö
		int f2 = 10;
		for (int n = 0; n < N; n++)
		{
			cosine[n] = complex<Real>(0.0,cos(3.141592 * 2 * n *f1 / N));
			sine[n] = complex<Real>(sin(3.141592 * 2 * n *f2 / N),0.0);
		}

}

void FFFT(complex<Real>*func, int l, double*t)
{
	ofstream fff("FFTofSquare.txt");
	int N = l;
	FFT *sequence;
	sequence = new FFT(N);
	start = clock();
	for (int n = 0; n<N; n++)    sequence->x[n] = func[n];

	sequence->ForwardFFT();
	endd = clock();
	if (!fff) {
		cout << "cant open FFTofSquare.txt.\n";
		exit(333);
	}

	for (int k = 0; k<N / 2 + 1; k++) fff << real(sequence->X[k]) << endl;
	for (int k = N / 2; k<N - 1; k++) fff << real(sequence->X[k]) << endl;
	fff.close();

	
	*t = (double)(endd - start) / CLOCKS_PER_SEC;
}

void IFFT(complex<Real>*func, int l, double*t)
{
	ofstream ggg("IFFTofLPF.txt");
	int N = l;
	FFT *sequence;
	sequence = new FFT(N);
	start = clock();
	for (int n = 0; n<N; n++)    sequence->X[n] = func[n];
	sequence->InverseFFT();
	endd = clock();
	if (!ggg) {
		cout << "cant open IFFTofLPF.txt.\n";
		exit(334);
	}
	for (int n = N / 2; n<N - 1; n++) ggg << real(sequence->x[n]) << endl;
	for (int n = 0; n<N / 2 + 1; n++) ggg << real(sequence->x[n]) << endl;
	ggg.close();

	
	*t = (double)(endd - start) / CLOCKS_PER_SEC;
}

void FDFT(complex<Real>*func, int l, double*t)
{
	ofstream kkk("DFTofSquare.txt");
	int N = l;
	DFT *dft;
	dft = new DFT(N);
	start = clock();

	for (int n = 0; n<N; n++)    
		dft->x[n] = func[n];

	dft->ForwardDFT();
	endd = clock();
	if (!kkk) {
		cout << "cant open DFTofSquare.txt.\n";
		exit(333);
	}

	for (int k = N / 2; k<N - 1; k++) 
		kkk << real(dft->X[k]) << endl;
	for (int k = 0; k<N / 2 + 1; k++) 
		kkk << real(dft->X[k]) << endl;


	kkk.close();

	
	*t = (double)(endd - start) / CLOCKS_PER_SEC;
}

void IDFT(complex<Real>*func, int l, double*t)
{
	ofstream lll("IDFTofLPF.txt");
	int N = l;
	DFT *dft;
	dft = new DFT(N);

	start = clock();
	for (int n = 0; n<N; n++)    
		dft->X[n] = func[n];
	dft->InverseDFT();
	lll.close();
	if (!lll) {
		cout << "cant open IDFTofLPF.txt.\n";
		exit(334);
	}

	for (int n = N / 2; n<N - 1; n++) 
		lll << real(dft->x[n]) << endl;
	for (int n = 0; n<N / 2 + 1; n++) 
		lll << real(dft->x[n]) << endl;

	

	endd = clock();
	*t = (double)(endd - start) / CLOCKS_PER_SEC;
}

