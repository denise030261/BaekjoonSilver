#include<iostream>
#include<string>
#include<sstream>
#include <vector>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    string str;
    vector<string> word;
    int length = 0;
    int alpha[27] = { 0, };
    bool check = false;
    cin >> N;

    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        getline(cin, str);
        char separator = ' ';
        word.clear();
        istringstream iss(str);
        string str_buf;
        while (getline(iss, str_buf, separator))
            word.push_back(str_buf);
        
        for (int j = 0; j < word.size(); j++)
        {
            if (alpha[toupper(word[j][0]) - 'A']==0)
            {
                alpha[toupper(word[j][0]) - 'A'] = 1;
                word[j].insert(1, "]");
                word[j].insert(0, "[");
                string new_str = "";
                for (int k = 0; k < word.size(); k++)
                    new_str += word[k] + ' ';
                str = new_str;
                check = true;
                break;
            }
        }

        for (int j = 0; j < str.length(); j++)
        {
            if (!check)
            {
                if (alpha[toupper(str[j]) - 'A'] == 0 && str[j] != ' ')
                {
                    alpha[toupper(str[j]) - 'A'] = 1;
                    str.insert(j+1, "]");
                    str.insert(j, "[");
                    check = true;
                    break;
                }
            }
        }

        check = false;
        cout << str << '\n';
    }
}