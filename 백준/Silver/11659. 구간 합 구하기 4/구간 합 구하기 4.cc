#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int M = 0, N = 0, num = 0, i = 0, j = 0;

	cin >> N >> M;

	vector<int> Sums(N + 1, 0);
	Sums[0] = 0;

	for (int ix = 0; ix < N; ++ix)
	{
		cin >> num;
		Sums[ix + 1] = Sums[ix] + num;
	}

	for (int ix = 0; ix < M; ++ix)
	{
		cin >> i >> j;
		cout << Sums[j] - Sums[i - 1] << "\n";
	}

	return 0;
}