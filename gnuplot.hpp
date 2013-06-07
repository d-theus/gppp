#include<string>
#include<fstream>
#include<functional>

using std::string;
using std::ofstream;
using std::function;

void gp_plot(const string f, double left, double right, size_t samples, ofstream &of);

void gp_setVline(double x, double bottom, double top, ofstream &of, int color = 0x000000);

void my_f_gnuplot(const function<double(double)> f, double left, double right, size_t samples, ofstream &dof, ofstream &of);
