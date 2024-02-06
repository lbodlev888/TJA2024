#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cumparatura {
	string nume;
	unsigned pret;
};

bool compara(Cumparatura c1, Cumparatura c2)
{
	int len = (c1.nume.length() > c2.nume.length()) ? c2.nume.length() : c1.nume.length();
	for(int i = 0; i < len; i++)
	{
		if(c1.nume[i] > c2.nume[i]) return false;
		else if(c1.nume[i] < c2.nume[i]) return true;
	}
	return (c1.pret > c2.pret);
}

int main()
{
	int n; cin >> n;
	vector<Cumparatura> lista;
	for(int i = 0; i < n; i++)
	{
		Cumparatura local; cin >> local.nume >> local.pret;
		lista.push_back(local);
	}
	sort(lista.begin(), lista.end(), compara);
	
	for(unsigned i = 0; i < lista.size(); i++)
	{
		cout << lista[i].nume << " " << lista[i].pret << " ";
		while(i < lista.size() - 1 && lista[i].nume == lista[i+1].nume)
		{
			cout << lista[i+1].pret << " ";
			i++;
		}
		cout << "\n";
	}
	return 0;
}
