class Solution {
public:
	bool isValid(string s) {
		stack<char> operatorStack;
		bool ret = true;

		for (char &c : s) {
			if (c == '(') {
				operatorStack.push(c);

			}
			else if (c == '[') {
				operatorStack.push(c);

			}
			else if (c == '{'){
				operatorStack.push(c);
			}
			else if (c == ')') {
				if (operatorStack.empty() || operatorStack.top() != '(') {
					ret = false;
					break;

				}
				operatorStack.pop();

			}
			else if (c == ']') {
				if (operatorStack.empty() || operatorStack.top() != '[') {
					ret = false;
					break;

				}
				operatorStack.pop();

			}
			else if (c == '}'){
				if (operatorStack.empty() || operatorStack.top() != '{') {
					ret = false;
					break;

				}
				operatorStack.pop();
			}

		}

		if (!operatorStack.empty()) ret = false;

		return ret;



	}
};