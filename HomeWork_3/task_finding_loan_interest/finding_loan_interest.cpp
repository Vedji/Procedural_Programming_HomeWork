#include <iostream>
#include <cmath>
using namespace std;

double loan_find(double s, double p, double n) {
	double r = p / 100;
	if ((12 * (pow((1 + r), n) - 1)) == 0) { return 0; }
	return ((s * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1)));
}

int main() {
	double s, p, n, m, step = 10;
	s = 100000;
	n = 1;
	m = 9166.66;
	bool flag = true;
	while (flag) {
		// cout << "[DEBUG]: p = " << step << ", m = " << loan_find(s, step, n)  << endl;
		if (loan_find(s, step, n) < m) {
			step = step + step / 2.;
		}
		else if (loan_find(s, step, n) > m) {
			step = step - step / 2.;
		}

		if ((m - 0.005) < loan_find(s, step, n) && loan_find(s, step, n) < (m + 0.006)) {
			flag = false;
			for (double i = (step - 0.005); i < (step + 0.006); i += 0.0000001) {
				if (((m - 0.000001) <= loan_find(s, i, n) && loan_find(s, i, n) <= (m + 0.000001)) || loan_find(s, i, n) == m) {
					step = i;
					break;
				}
			}
		}
		
	}
	if (!flag) {
		cout << "[RELEASE]: p = " << step << ", m = " << loan_find(s, step, n);
	}
	else {
		cout << "[RELEASE]: Error";
	}
	return 0;
}
