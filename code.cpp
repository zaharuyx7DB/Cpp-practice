#include <iostream>
#include <windows.h>
#include <cctype>
using namespace std;

/*

ask for a pin


1. Проверить баланс check_balance
2. Пополнить счёт  add_money
3. Снять деньги take_money
4. Перевести деньги send_money
5. Статистика операций statistics
6. Изменить PIN change_pin
7. Выйти из аккаунта leave_acc
0. Завершить программу stop_running

*/

bool check_password(string password)
{

    for (char check : password)
    {
        if (!isdigit(check))
        {
            cout << "Password can't contains letters" << endl;
            return false;
        }
    }
    if (password.size() != 4)
    {
        cout << "Password must have 4 digits only!" << endl;
        return false;
    }

    if (password == "2011")
    {
        cout << "Welcome!" << endl;
        return true;
    }
    else
    {
        cout << "Wrong password!" << endl;
    }
    return false;
}

int main()
{

    cout << "Enter your password:" << endl;
    bool is_ok = false;
    int limits = 4;
    string password;
    while (is_ok == false)
    {
        limits--;
        cout << "You have tries\t" << limits << endl;
        if (limits == 0)
        {
            return 0;
        }
        else
        {
            cin >> password;
            is_ok = check_password(password);
        }
    }

    return 0;
}
