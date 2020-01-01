#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


double vm = 0;
double Vp = 48;
double R = 280;
double L = 0.1;
double C = 0.0000004;

double T = 0.01;
/*

int main()
{
	double dt = 0.000001;

	double v[100000];
	//v = new double[];
	v[0] = 0;
	v[1] = 0;
	int n = 0;

	n = 1;
	for (double t = 0; t < T; t += dt)
	{
		v[n + 1] = ((Vp*dt*dt)/(L*C))+ ((2 * v[n] - v[n - 1])) - ((R/L)*dt*(v[n] - v[n - 1])) - (v[n]*dt*dt)/(L*C) ;
		n++;
	}

	
	v[1] = v[0];

	ofstream fp("data.txt");
	n = 0;
	for (double t = 0; t < T; t += dt)
	{
		fp << v[n]<< endl;
		n++;
	}
	

	system("pause");
	return 0;
}
*/

int main()
{
	double dt = 0.0000001;
	int m = 0;
	double temp[10] = {0,0,0,0,0,0,0,0,0,0};
	double v[100000];
	int n = 0;
	double temp2[10];
	for (int k=0; k<8; k++)
	{
		v[0] = 0;
		v[1] = 0;

		n = 1;
		for (double t = 0; t < T; t += dt)
		{
			if (v[n] > temp[m])
			{
				temp[m] = v[n];
				temp2[m] = t;
			}
			v[n + 1] = ((Vp*dt*dt) / (L*C)) + ((2 * v[n] - v[n - 1])) - ((R / L)*dt*(v[n] - v[n - 1])) - (v[n] * dt*dt) / (L*C);
			n++;

		}
		cout << fixed << setprecision(7)<< "dt = " << dt << "    최고값이 위치하는 t = "<< setprecision(9) << temp2[m] << endl;
		m++;
		dt = dt * 5;

	}
	/*
		ofstream fp("data.txt");
		n = 0;
		for (double t = 0; t < T; t += dt)
		{
			fp << v[n] << endl;
			n++;
		}

	*/

	system("pause");
	return 0;
}