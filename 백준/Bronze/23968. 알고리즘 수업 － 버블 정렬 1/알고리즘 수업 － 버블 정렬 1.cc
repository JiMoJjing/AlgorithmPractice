#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> Nums(N, 0);
	for (int ix = 0; ix < N; ++ix)
	{
		cin >> Nums[ix];
	}
	// 탈출용 Flag.
	bool Flag = false;
	int ChangeCount = 0, CurrentNum1 = 0, CurrentNum2 = 0;
	for (int ix = 0; ix < N - 1; ++ix)
	{
		for (int jx = 0; jx < N - 1; ++jx)
		{
			CurrentNum1 = Nums[jx];
			CurrentNum2 = Nums[jx + 1];

			if (CurrentNum1 > CurrentNum2)
			{
				// 교환이 일어나면 ++Count;
				++ChangeCount;
				Nums[jx] = CurrentNum2;
				Nums[jx + 1] = CurrentNum1;
			}

			if (ChangeCount == K)
			{
				Flag = true;
				break;
			}
		}
		if (Flag)
		{
			break;
		}
	}

	if (Flag)
	{
		cout << min(CurrentNum1, CurrentNum2) << " " << max(CurrentNum1, CurrentNum2);
	}
	else
	{
		cout << -1;
	}

	return 0;
}