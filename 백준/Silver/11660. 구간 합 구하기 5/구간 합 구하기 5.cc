#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> vec(N * N, 0);

	for (int ix = 0; ix < N * N; ++ix)
	{
		cin >> vec[ix];
		if (ix > 0)
		{
			vec[ix] += vec[ix - 1];
		}
	}

	for (int ix = 0; ix < M; ++ix)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		--y1;
		--x2;
		--y2;

		int sum = 0;
		for (int jx = x1; jx <= x2; ++jx)
		{
			int start = jx * N + y1 - 1;
			int end = jx * N + y2;

			sum += start >= 0 ?(vec[end] - vec[start]) : vec[end];
		}
		cout << sum << "\n";
	}

	return 0;
}