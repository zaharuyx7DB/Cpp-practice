#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    bool has_only_numbers = true;
    string password;
    cin >> password;

    for (char check : password)
    {
        if (!isdigit(check))
        {

            has_only_numbers = false;
        }
    }
    if (has_only_numbers == false)
    {
        cout << "Password can't contains numbers";
    }
    else
    {
        cout << "Welcome";
    }

    return 0;
}
