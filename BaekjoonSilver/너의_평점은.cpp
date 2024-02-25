#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string sub;
    float credit;
    string score;
    float sum = 0;
    float credit_num = 0;

    for (int i = 0; i < 20; i++)
    {
        cin >> sub >> credit >> score;
        if (score == "A+")
            sum += credit * 4.5;
        else if (score == "A0")
            sum += credit * 4.0;
        else if (score == "B+")
            sum += credit * 3.5;
        else if (score == "B0")
            sum += credit * 3.0;
        else if (score == "C+")
            sum += credit * 2.5;
        else if (score == "C0")
            sum += credit * 2.0;
        else if (score == "D+")
            sum += credit * 1.5;
        else if (score == "D0")
            sum += credit * 1.0;
        else if (score == "F")
            sum += credit * 0;
        else if (score == "P")
            credit_num -= credit;
        credit_num += credit;
    }

    cout << sum/credit_num;
}