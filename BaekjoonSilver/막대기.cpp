#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> sticks; // ������
	int sum = 0; // �������� ���� ��
	int stick1 = 0; // �ɰ��� �����1
	int stick2 = 0; // �ɰ��� �����2
	int X;

	sticks.push_back(64);
	cin >> X;

	while (sum!=X)
	{
		if (X == 64)
			break;

		stick1 = sticks[sticks.size() - 1] / 2;
		stick2 = sticks[sticks.size() - 1] / 2; // ���� ª�� ���� ���� �ڸ���
		sticks.pop_back();
		sticks.push_back(stick2);
		sum = 0;
		for (int i = 0; i < sticks.size(); i++)
			sum += sticks[i]; // ������ ���� �͵鳢�� ���ϱ�
	
		if (sum<X)
		{
			sum += stick1;
			sticks.push_back(stick1);
		} //�۴ٸ� �ٽ� ���ϱ�
	}

	int result = sticks.size();
	cout << result;
}