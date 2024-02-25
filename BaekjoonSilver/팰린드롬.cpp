#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		bool check = true;
		if(i==0)
			cin.ignore();
		getline(cin, str);

		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] >= 'A' && str[j] <= 'Z')
				str[j] = tolower(str[j]);
		}

		for (int j = 0; j < str.length()/2; j++)
		{
			if (str[j] != str[str.length() - j - 1])
				check = false;
		}

		if (check)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
}