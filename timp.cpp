#include <iostream>

using namespace std;

int main()
{
	int n, m, nodStart; cin >> n >> m >> nodStart;
	int matrice[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) matrice[i][j] = 1000000;
	for(int i = 0; i < n; i++) matrice[i][i] = 0;
	
	for(int i = 0; i < m; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		matrice[x-1][y-1] = z;
	}
	
	int costuri[n]; bool vizitat[n];
	for(int i = 0; i < n; i++)
	{
		costuri[i] = matrice[nodStart-1][i];
		vizitat[i] = false;
	}
	vizitat[0] = true; int nodCurrent = 0, count = 0;
	//Dijkstra
	while(count < n)
	{
		int min = 1000000, imin = 0;
		for(int i = 0; i < n; i++)
			if(costuri[i] < min && !vizitat[i]) {
				min = costuri[i];
				imin = i;
			}
		vizitat[imin] = true;
		nodCurrent = imin;
		for(int i = 0; i < n; i++)
			if(costuri[i] > costuri[nodCurrent] + matrice[nodCurrent][i])
				costuri[i] = costuri[nodCurrent] + matrice[nodCurrent][i];
		count++;
	}
	//Raspuns
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if(costuri[i] == 1000000) {
			cout << "-1";
			return 0;
		}
		else if(costuri[i] > max) max = costuri[i];
	}
	cout << max;
	return 0;
}
