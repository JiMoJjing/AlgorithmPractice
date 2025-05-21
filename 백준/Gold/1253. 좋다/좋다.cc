#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> Nums(N, 0);

	for (int ix = 0; ix < N; ++ix)
	{
		cin >> Nums[ix];
	}

	// 크기순으로 정렬.
	sort(Nums.begin(), Nums.end());
	
	// 앞에서 시작할 인덱스, 뒤에서 시작할 인덱스, 목표 값, LeftRight합.
	int Left = 0, Right = 0, Goal = 0, Sum = 0, Result = 0;

	for (int ix = 0; ix < N; ++ix)
	{
		// 양쪽 끝에서 시작.
		Left = 0;
		Right = N - 1;
		Goal = Nums[ix];

		// 둘이 교차되기 전까지.
		while (Left < Right)
		{
			Sum = Nums[Left] + Nums[Right];
			if (Sum == Goal)
			{
				// ix 값은 사용안됨.
				if (Left != ix && Right != ix)
				{
					++Result;
					break;
				}
				else if (Left == ix)
				{
					++Left;
				}
				else if (Right == ix)
				{
					--Right;
				}
			}
			else if (Sum > Goal)
			{
				--Right;
			}
			else if (Sum < Goal)
			{
				++Left;
			}
		}
	}
	cout << Result;

	return 0;
}