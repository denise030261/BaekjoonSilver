#include <iostream>
#include <stack>

using namespace std;
stack<int> num;
stack<char> bracket;
string str;
int result;
int temp;
bool correct;

void open_bracket(char current_bracket, int mul_num)
{
	temp *= mul_num;
	bracket.push(current_bracket);
}

void close_bracket(char match_bracket, int current_order, int mul_num)
{
	if (bracket.empty() || bracket.top() != match_bracket)
	{
		correct = false;
		return;
	}

	if (str[current_order - 1] == match_bracket)
	{
		result += temp;
		temp /= mul_num;
		bracket.pop();
	}
	else
	{
		temp /= mul_num;
		bracket.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	result = 0;
	temp = 1;
	correct = true;

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			open_bracket('(',2);
		else if (str[i] == '[')
			open_bracket('[',3);
		else if (str[i] == ')')
			close_bracket('(',i,2);
		else if (str[i] == ']')
			close_bracket('[',i,3);
	}

	if (!correct || !bracket.empty())
		cout << 0;
	else
		cout << result;
}