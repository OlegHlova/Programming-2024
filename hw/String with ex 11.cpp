#include <iostream>
#include <string> 


using namespace std;


string parsing_string(string str)
{
    string line_without_symbol, line_end, result;
    int count_of_symbol = 1, n = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != '*') {
            line_without_symbol += str[i];
        }
        else {
            n += 1;
            i += n;
            string num_str = to_string(count_of_symbol);
            line_without_symbol += num_str;
            for (int e = i; e < str.length(); ++e)
            {
                if (str[e] == '(') {
                    continue;
                }
                else if (str[e] == ')') {
                    line_end += " - " + num_str + ' ';
                    count_of_symbol += 1;
                    i += 1;
                    break;
                }
                else {
                    i += 1;
                    line_end += str[e];
                }
            }
        }
    }
    result = line_without_symbol + line_end;
    return result;
}
int main()
{
    string line, result;
    cout << "Enter anything" << endl;
    getline(cin, line);
    result = parsing_string(line);
    cout << result;
    return 0;
