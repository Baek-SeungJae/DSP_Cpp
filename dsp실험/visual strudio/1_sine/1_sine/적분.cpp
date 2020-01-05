#include<iostream>
#include<conio.h>
#include<iomanip>
#define pi 3.141592
using namespace std;

void calculate_x(float);

int main()
{
	float dt = 0.1;
	for (int i = 0; i < 5; i++)
	{
		calculate_x(dt);
		dt *= 0.1;
	}
	getchar();
	return 0;

}

void calculate_x(float ddt)
{
	double t, T = 10, v, xbar, errorinpercent;
	xbar = 0.0;
	for (t = 0; t < T; t += ddt)
	{
		xbar += pi * t * ddt;
	}
	errorinpercent = (fabs(100*pi - xbar) / (100 * pi)) * 100;
	cout << fixed << "dt " <<setprecision(5) << ddt << " x=314.1592 "  << setprecision(2)<< xbar << " error " <<setprecision(10) << errorinpercent << "%\n";

}