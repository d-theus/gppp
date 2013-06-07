#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<functional>
#include<string>
#include<unistd.h>
#include<cmath>

using std::ofstream;
using std::string;
using std::endl;
using std::function;

void gp_plot(const string f, double left, double right, size_t samples, ofstream &of){
	of << "set key left box" << endl;
	of << "set samples " << samples << endl;
	of << "plot [" <<left <<":" << right << "] " << f << endl;
}

void gp_setVline(double x, double bottom, double top, ofstream &of, int color = 0x000000){
	char arrow[256];
	sprintf(arrow, "set arrow from %lf, %lf to %lf,%lf nohead lc rgb '#%x'", x, bottom, x, top, color);
	of << arrow << endl;
}

void my_f_gnuplot(const function<double(double)> f, double left, double right, size_t samples, ofstream &dof, ofstream &of){
	double step = (right - left)/samples;
	for(double x = left; x <= right; x+=step){
		dof << x << "\t" << f(x) <<endl;
	}
	of << "plot 'data.dat' with lines";
}
