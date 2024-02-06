#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int gb, suma = 0; cin >> gb;
	if(gb > 10) suma += 10 * 5;
	else {
		cout << gb * 5 << " lei";
		return 0;
	}
	gb -= 10;
	if(gb > 10) suma += 10 * 3;
	else {
		suma += gb * 3;
		cout << suma << " lei";
		return 0;
	}
	gb -= 10;
	if(gb > 0) suma += gb * 1;
	cout << suma << " lei";
	return 0;
}
