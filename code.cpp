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

int check_balance(int &main_balance, int &saving_balance)
{

    cout << "Основной счет:\t" << main_balance << endl;
    cout << "Сберегательный:\t" << saving_balance << endl;
    return 0;
}

int add_money()

       int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

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

    // password

    // main menu

    if (check_password(password) == true)
    {
        cout << "===== SMART BANK =====" << endl;
        cout << "1. Проверить баланс" << endl;
        cout << "2. Пополнить счёт" << endl;
        cout << "3. Снять деньги" << endl;
        cout << "4. Перевести деньги" << endl;
        cout << "5. Статистика операций" << endl;
        cout << "6. Изменить PIN" << endl;
        cout << "7. Выйти из аккаунта" << endl;
        cout << "0. Завершить программу" << endl;
        cout << "======================" << endl;
        cout << "Выберите действие:" << endl;
    }

    int user_input;
    cin >> user_input;

    int m, s;
    m = 3000;
    s = 1000;

    switch (user_input)
    {
    case 0:
        cout << "Благодарим за ваш выбор!";
        return 0;

    case 1:
        check_balance(m, s);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;

    default:
        cout << "No options found";
        break;
    }

    return 0;
}
