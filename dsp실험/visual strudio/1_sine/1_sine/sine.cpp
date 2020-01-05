#include<iostream>
#include<fstream>
#include<iomanip>
#define pi 3.141592

using namespace std;




int main()
{
	ofstream FILE; // sine값을 저장할 FILE 스트림을 연결
	FILE.open("사인그래프.txt");

	float f0, fc, t, dt;
	float fs =150.0;
	float sine, mod;
	t = 0;
	f0 = 220;
	fc = 1200; // for modulation
	dt = 1.0 / fs;
	


	// Normalized freq : w / fs
	// f(t)=sin(2*pi*f*t)
	// f[n] = sin(w/fs * n)
	
	for (int i = 0; i < 10*fs/f0; i++ , t += dt)
	{
		sine = cos(2*pi*f0*t);										
		FILE <<fixed <<setprecision(6) << t	<< setw(10)  << "\t" << sine << "\n";
	}
	

	 //monulation
	for (int i = 0; i < 5 * fs / f0; i++, t += dt)
	{
		mod = sin(fc * 2 * pi*t);// *cos(f0 * 2 * pi*t);
		FILE << fixed << setprecision(6) << t << setw(10) << "\t" << mod << "\n";
	}
	


	FILE.close();

	return 0;
}
