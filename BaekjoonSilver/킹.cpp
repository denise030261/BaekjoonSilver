#include <iostream>
#include <map>

using namespace std;

int king_col; //왕의 행
int king_row; //왕의 열
int stone_col; //돌의 행
int stone_row; //돌의 열

void moving(int col, int row) // 1 0
{
	int pro_king_col = king_col + col;
	int pro_king_row = king_row + row;
	int pro_stone_col = stone_col + col;
	int pro_stone_row = stone_row + row;

	if (pro_king_col < 1 || pro_king_col > 8 || pro_king_row < 1 || pro_king_row > 8)
	{
		pro_king_col = king_col;
		pro_king_row = king_row;
	}
	
	if (pro_king_col == stone_col && pro_king_row == stone_row)
	{
		if (pro_stone_col < 1 || pro_stone_col > 8 || pro_stone_row < 1 || pro_stone_row > 8)
			return;
		else
		{
			stone_col = pro_stone_col;
			stone_row = pro_stone_row;
			king_col = pro_king_col;
			king_row = pro_king_row;
		}
	}
	else
	{
		king_col = pro_king_col;
		king_row = pro_king_row;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string king_loc; //왕의 위치
	string stone_loc; //돌의 위치
	int num; // 움직이는 횟수
	map<char, int> m = { {'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8} };

	cin >> king_loc >> stone_loc >> num;

	king_col = king_loc[1] - '0';
	king_row = m[king_loc[0]];
	stone_col = stone_loc[1] - '0';
	stone_row = m[stone_loc[0]];
	
	for (int i = 0; i < num; i++)
	{
		string move;
		cin >> move;

		if (move == "R")
			moving(0, 1);
		else if (move == "L")
			moving(0, -1);
		else if (move == "B")
			moving(-1, 0);
		else if (move == "T")
			moving(1, 0);
		else if (move == "RT")
			moving(1, 1);
		else if (move == "LT")
			moving(1, -1);
		else if (move == "RB")
			moving(-1, 1);
		else if (move == "LB")
			moving(-1, -1);
	}

	char king_row_c = king_row + 'A' -1; //출력을 위한 왕의 행
	char stone_row_c = stone_row + 'A' -1; //출력을 위한 돌의 행
	
	cout << king_row_c << king_col << '\n' << stone_row_c << stone_col;
}

