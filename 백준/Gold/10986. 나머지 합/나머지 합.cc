#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M, Num;
	long long Result = 0;
	cin >> N >> M;

	int Mod = 0;

	vector<int> Modular(1001, 0);
	for (int ix = 0; ix < N; ++ix)
	{
		cin >> Num;
		Mod = (Mod + Num) % M;
		Modular[Mod]++;
	}

	for (int ix = 0; ix < M; ++ix)
	{
		long long Count = Modular[ix];
		Result += Count * (Count - 1) / 2;
	}

	cout << Result + Modular[0];
	
	return 0;
}