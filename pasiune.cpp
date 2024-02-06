#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool Armstrong(int nr)
{
	int temp = nr, count = 0, sumCif = 0;
	while(temp > 0)
	{
		count++;
		temp /= 10;
	}
	temp = nr;
	while(temp > 0)
	{
		sumCif += pow(temp % 10, count);
		temp /= 10;
	}
	return sumCif == nr;
}

int main()
{
	int n; cin >> n;
	vector<int> lista; int count = 0;
	for(int i = 0; i < n; i++)
	{
		int current; cin >> current;
		if(Armstrong(current)) {
			count++;
			lista.push_back(current);
		}
	}
	cout << count << "\n";
	for(int i = 0; i < lista.size(); i++)
		cout << lista[i] << " ";
	return 0;
}
