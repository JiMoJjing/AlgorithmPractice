#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool CanUse(unordered_map<char, int>& Conditions, unordered_map<char, int>& Check)
{
	string Condition = "ACGT";
	for (int ix = 0; ix < 4; ++ix)
	{
		if (Conditions[Condition[ix]] - Check[Condition[ix]] > 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int S, P, Result = 0;
	cin >> S >> P;

	string DNA;
	cin >> DNA;

	unordered_map<char, int> Conditions;
	unordered_map<char, int> Check;
	string Condition = "ACGT";
	string StartStr = DNA.substr(0, P);

	for (int ix = 0; ix < 4; ++ix)
	{
		cin >> Conditions[Condition[ix]];
	}

	for (const char& c : StartStr)
	{
		Check[c]++;
	}

	Result += CanUse(Conditions, Check);


	for (int ix = 1; ix + P <= S; ++ix)
	{
		Check[DNA[ix - 1]]--;
		Check[DNA[ix + P - 1]]++;

		Result += CanUse(Conditions, Check);
	}
	
	cout << Result;

	return 0;
}