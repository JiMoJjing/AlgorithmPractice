#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> Sequence(n, 0);
	for (int ix = 0; ix < n; ++ix)
	{
		cin >> Sequence[ix];
	}

	vector<bool> PushPop;
	bool bSuccess = true;
	stack<int> st;

	for (int ix = 1, jx = 0; jx < Sequence.size();)
	{
		if (ix <= n && (st.empty() || st.top() < Sequence[jx]))
		{
			st.push(ix);
			++ix;
			PushPop.emplace_back(true);
			continue;
		}
		
		if (st.top() == Sequence[jx])
		{
			st.pop();
			++jx;
			PushPop.emplace_back(false);
		}
		else
		{
			bSuccess = false;
			break;
		}
	}

	if (bSuccess)
	{
		for (const bool& Result : PushPop)
		{
			char c;
			c = Result ? '+' : '-';
			cout << c << "\n";
		}
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}