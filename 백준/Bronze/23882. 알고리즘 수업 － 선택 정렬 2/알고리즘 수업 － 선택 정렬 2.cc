#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, K, Count = 0;
	cin >> N >> K;

	vector<int> Nums(N, 0);

	for (int ix = 0; ix < N; ++ix)
	{
		cin >> Nums[ix];
	}

	for (int ix = 0; ix < N; ++ix)
	{
		vector<int>::iterator MaxIter = max_element(Nums.begin(), Nums.end() - ix);
		vector<int>::iterator BackIter = (Nums.end() - ix - 1);
		if (BackIter != MaxIter)
		{
			int MaxVal = *MaxIter;
			*MaxIter = *BackIter;
			*BackIter = MaxVal;
			++Count;
		}
		if (Count == K)
		{
			break;
		}
	}
	if (Count < K)
	{
		cout << -1;
	}
	else
	{
		for (const int Num : Nums)
		{
			cout << Num << " ";
		}
	}

	return 0;
}