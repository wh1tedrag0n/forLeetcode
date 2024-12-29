#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	Solution721 sol;
	vector<vector<string>> temp{ {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
		{"John", "johnsmith@mail.com", "john00@mail.com"},{"Mary", "mary@mail.com"},
		{"John", "johnnybravo@mail.com"} };
}

class Solution721 {
private:
	vector<vector<string>> Union;

	int Find(vector<string> input) {
		int index = 0;
		for (const auto& item : Union)
		{
			for (int i = 1; i < item.size(); i++)
			{
				for (int j = 1; j < input.size(); j++)
				{
					if (item[i] == input[j])
					{
						return index;
					}
				}
			}
			index++;
		}
		return -1;
	}

	void Merge(int index, vector<string> account) {
		for (int i = 1; i < account.size(); i++) {
			for (int j = 1; j < Union[index].size(); j++) {
				if (account[i] == Union[index][j]) {
					break;
				}
			}

			Union[index].push_back(account[i]);
			sort(Union[index].begin() + 1, Union[index].end());
		}
	}

public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		for (const auto& account : accounts)
		{
			int index = Find(account);
			if (index != -1)
			{
				Merge(index, account);
			}
			else
			{
				Union.push_back(account);
			}
		}
		return Union;
	}
};

class Solution {
public:
	std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
	}
};