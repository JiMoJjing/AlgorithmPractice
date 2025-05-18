#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_set<int> CountA;
    unordered_map<int, int> CountB;
    
    for(int ix = 0; ix < topping.size(); ++ix)
    {
        CountB[topping[ix]]++;
    }
    
    for(int ix = 0; ix < topping.size(); ++ix)
    {
        int ToppingNum = topping[ix];
        
        CountA.insert(ToppingNum);
        CountB[ToppingNum]--;
        
        if(CountB[ToppingNum] <= 0)
        {
            CountB.erase(ToppingNum);
        }
        answer += CountA.size() == CountB.size();
    }
    
    return answer;
}