/*!
 * @file  LeastSquareFittingExponential.cpp
 * @brief Calculate exponential equation from data, y = Ae^(Bx)
 * refer http://mathworld.wolfram.com/LeastSquaresFittingExponential.html
 * @date 2015/06/16
 * @author YoonSeong Yong 
 * 
 */

#include <iostream>  
#include <cmath> 

using namespace std;  

double ln(double x){
	double a = log(x)/log(exp(1));
	return a;
}

void BestFit(double x[], double y[], int n, double &a, double &b){
	double Elnyi = 0.0; /// summation of ln yi, where i is from 1~n
	double Exi2 = 0.0; /// summation of pow 2 of xi, where i is from 1~n
	double Exi = 0.0; /// summation of xi, where i is from 1~n
	double Exilnyi = 0.0; /// summmation of xi * lnyi, where i is from 1~n
		
	for(int i=0; i < n; i++){
		Elnyi += ln(y[i]);
		Exi2 += (x[i]*x[i]);
		Exi += x[i];
		Exilnyi += (x[i]*ln(y[i]));
	}
	a = ((Elnyi*Exi2)-(Exi*Exilnyi))/((n*Exi2)-(Exi*Exi));
	b = ((n*Exilnyi)-(Exi*Elnyi))/((n*Exi2)-(Exi*Exi));
}

void LeastSquaresFitting(double x[], double y[], int n, double &a, double &b){
	double Exi2yi = 0.0; /// summation of xi^2 * yi, where i is from 1~n
	double Eyilnyi = 0.0; /// summation of yi * ln(yi), where i is from 1~n
	double Exiyi = 0.0; /// summation of xi*yi, where i is from 1~n
	double Exiyilnyi = 0.0; /// summation of xi*yi*ln(yi), where i is from 1~n
	double Eyi = 0.0; /// summation of yi, where i is from 1~n
	
	for(int i=0; i<n; i++){
		Exi2yi += (x[i]*x[i]*y[i]);
		Eyilnyi += (y[i]*ln(y[i]));
		Exiyi += (x[i]*y[i]);
		Exiyilnyi += (x[i]*y[i]*ln(y[i]));
		Eyi += y[i];
	}
	a = ((Exi2yi*Eyilnyi) - (Exiyi*Exiyilnyi)) / ((Eyi*Exi2yi) - (Exiyi*Exiyi));
	b = ((Eyi*Exiyilnyi) - (Exiyi*Eyilnyi)) / ((Eyi*Exi2yi) - (Exiyi*Exiyi));
}		
	

int main(){
	double x[] = {52.330381, 117.995151, 144.848765, 158.07532, 167.472161, 173.454366};
	double y[] = {7.902201, 32.90917, 57.91613, 82.9231, 107.9301, 132.937};
	double a, b;
	int n = sizeof(x)/sizeof(*x);
	cout << "n = " << n << endl;	
	BestFit(x, y, n, a, b);

	cout << "Best Fit:" << endl;
	cout << "y = " << exp(a) << "e^(" << b << "x)" << endl;	
	
	LeastSquaresFitting(x, y, n, a, b);
	cout << "Least Squares Fitting:" << endl;
	cout << "y = " << exp(a) << "e^(" << b << "x)" << endl;		
}
