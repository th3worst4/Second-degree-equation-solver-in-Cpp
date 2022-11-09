#include <iostream> //cout/cin
#include <cmath> //modulo matematico
#include <tuple> //tuplas
#include <cwchar> //wprintf
#include <clocale> //wprintf
#include <ctype.h> // isdigit()
#include <sstream> //string para numero
#include <string> //str.size()

using std::cout;
using std::cin;
using std::endl;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::string;
using std::stringstream;

double delta(double a, double b, double c) {
	double d;
	d = pow(b, 2) -4 * a * c;
	return d;
}

tuple<double, double> findx(double a, double b, double d) {
	double x1, x2;
	x1 = (-b + sqrt(d)) / 2.0*a;
	x2 = (-b - sqrt(d)) / 2.0*a;
	return make_tuple(x1, x2);
}

bool isNum(const string& str)
{
	for (char const& c : str) {
		if (c == '-' || c == '.')
			continue;
		else;
			if (std::isdigit(c) == 0) return false;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "en_US.UTF-8");
	
	bool rodar = true;
	string ans, r;
	char ra;
	
	do {
		wprintf(L"Calculadora de Equação do 2º Grau \nvr: 1.3.2\nPor: Caio Couto \nFeito em C++\n\n\n");
		double a, b, c, d, x1, x2;
		
		cout << "Insira a" << endl;
		cin >> ans;
		while (ans == "0" || !isNum(ans)) {
			wprintf(L"a não pode ser 0 ou um caractere inválido,\nInsira a novamente\n");
			cin >> ans;
		}
		stringstream temp1(ans);
		temp1 >> a;

		cout << "Insira b" << endl;
		cin >> ans;
		while (!isNum(ans)) {
			wprintf(L"b não pode ser um caractere inválido,\nInsira b novamente\n");
			cin >> ans;
		}
		stringstream temp2(ans);
		temp2 >> b;

		cout << "Insira c" << endl;
		cin >> ans;
		while (!isNum(ans)) {
			wprintf(L"c não pode ser um caractere inválido,\nInsira c novamente\n");
			cin >> ans;
		}
		stringstream temp3(ans);
		temp3 >> c;
		
		d = delta(a, b, c);

		wprintf(L"O delta é %f \n", d);

		if (d >= 0) {
			tie(x1, x2) = findx(a, b, d);
			wprintf(L"x_1 é: %f e x_2 é: %f \n", x1, x2);
		}
		else {
			double sq, b_;
			sq = sqrt(d * -1) / 2.0 * a;
			sq = abs(sq);
			b_ = -b / 2.0 * a;
			wprintf(L"x_1 é: %f+%fi  e ", b_, sq);
			wprintf(L"x_2 é: %f-%fi \n", b_, sq);
		}
		ask:
		wprintf(L"Deseja rodar o programa novamente? \n1-Sim \n2-Não \n");
		cin >> r;
		
		if(r.size() > 1) {
			wprintf(L"Resposta inválida!\n");
			goto ask;
		}
		else {
			ra = r[0];
		}

		switch (ra)
		{
		case '1': rodar = true;
			system("cls");
			break;
		case '2': rodar = false; 
			return 0;
			break;
		default: wprintf(L"Resposta inválida!\n");
			wprintf(L"Deseja rodar o programa novamente? \n1-Sim \n2-Não \n");
			cin >> r;
			goto ask;
			break;
		}
	
	} while (rodar);
	return 0;
}