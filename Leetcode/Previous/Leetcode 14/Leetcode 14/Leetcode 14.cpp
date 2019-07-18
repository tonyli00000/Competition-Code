class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix = "";
		for (int j = 0; strs.size()>0; prefix += strs[0][j], j++)
			for (int i = 0; i<strs.size(); i++)
				if (j >= strs[i].size() || (i > 0 && strs[i][j] != strs[i - 1][j]))
					return prefix;
		return prefix;
	}
};