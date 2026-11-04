#include <iostream>
#include <windows.h>
#include <cctype>
#include <cstdlib>
using namespace std;

int send_money(string name, int &m, int &s, int sent_money)
{

    cout << "Откуда выводим?:" << endl;
    cout << "1.Основной счет:\t" << m << "грн" << endl;
    cout << "2.Сберегательный:\t" << s << "грн" << endl;
    int user_choose;
    cin >> user_choose;
    switch (user_choose)
    {
    case 1:
    {
        if (m > 0 && sent_money <= m)
        {

            m = m - sent_money;
            cout << sent_money << endl;
            cout << "Деньги отправились успешно к пользователю" << name << "!";
        }
        else
        {
            cout << "Недостаточно средств!" << endl;
        }
        break;
    }
    case 2:
        if (s > 0 && sent_money <= s)
        {

            s = s - sent_money;
            cout << s << "грн у вас залишилося!" << endl;
        }
        else
        {
            cout << "Недостаточно средств!" << endl;
        }
        break;
    }
    return 0;
}
int take_money(int withdraw, int &m, int &s)
{

    int user_input;
    cin >> user_input;

    switch (user_input)
    {
    case 1:
    {
        cout << "Сколько выводим?:" << endl;
        cin >> withdraw;
        if (m > 0 && withdraw <= m)
        {
            m = m - withdraw;
            cout << m << "грн у вас залишилося!" << endl;
        }
        else
        {

            cout << "Недостаточно средств!" << endl;
        }
        break;
    }
    case 2:
    {
        cout << "Сколько выводим?:" << endl;
        cin >> withdraw;
        if (s > 0 && withdraw <= s)
        {

            s = s - withdraw;
            cout << s << "грн у вас залишилося!" << endl;
        }
        else
        {
            cout << "Недостаточно средств!" << endl;
        }
        break;
    }
    default:
    {

        cout << "No option found!" << endl;
        cout << "Try again" << endl;
        break;
    }
    }
    return 0;
}

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

int add_money(int plus, int &main_money, int &saving_money)
{

    cout << "Куда ложим?" << endl;
    int user_option;
    cout << "1.Основной счет" << endl;
    cout << "2.Сберегательный" << endl;
    cout << "Ваш выбор:" << endl;

    bool help = true;
    bool right_option = false;

    while (right_option == false)
    {
        cin >> user_option;
        if (user_option == 1)
        {
            help = true;
            right_option = true;
        }
        else if (user_option == 2)
        {

            help = false;
            right_option = true;
        }
        else
        {

            cout << "No option found!" << endl;
            cout << "Введи правельный счет:" << endl;
            right_option = false;
        }
    }

    if (plus != 0 && help == true)
    {
        main_money = main_money + plus;
        cout << "Деньги полители на ваш счет успешно!" << endl;
        cout << main_money << "грн" << endl;
    }
    else if (plus != 0 && help == false)
    {
        saving_money = saving_money + plus;
        cout << "Деньги полители на ваш счет успешно!" << endl;
        cout << saving_money << "грн" << endl;
    }
    return 0;
}

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

    // money
    int m = 0;
    int s = 0;
    int amount;
    // main menu
    bool main_menu = true;
    while (main_menu == true)
    {
        if (is_ok == true)
        {
            cout << "===== SMART BANK =====" << endl;
            cout << "1. Проверить баланс" << endl;
            cout << "2. Пополнить счёт" << endl;
            cout << "3. Снять деньги" << endl;
            cout << "4. Перевести деньги" << endl;
            cout << "5.???&&&!!!DON\'tOPEENN " << endl;
            cout
                << "0. Завершить программу" << endl;
            cout << "======================" << endl;
            cout << "Выберите действие:" << endl;
        }

        int user_input;
        cin >> user_input;

        switch (user_input)
        {
        case 0:
        {
            cout << "Благодарим за ваш выбор!";
            return 0;
        }
        case 1:
        {

            check_balance(m, s);
            break;
        }
        case 2:
        {
            cout << "Введите сумму:" << endl;
            cin >> amount;
            add_money(amount, m, s);
            break;
        }
        case 3:
            int withdraw;
            cout << "Де выводим?:" << endl;
            cout << "1.Основной счет:\t" << m << "грн" << endl;
            cout << "2.Сберегательный:\t" << s << "грн" << endl;
            take_money(withdraw, m, s);

            break;
        case 4:
        {

            cout << "Кому высылаем деньги?:" << endl;
            cout << "{Подсказка} Деньги можно выслать только Nastia,Zakhar" << endl;
            string name;
            cin >> name;
            if (name == "Zakhar" || name == "Nastia")
            {

                cout << "Пользователь " << name << " найден!" << endl;
            }
            else
            {

                cout << "Деньги только для Насти и Захара!" << endl;
                break;
            }
            cout << "Сколько высылаем " << name << "?" << endl;
            int money_send;
            cin >> money_send;
            send_money(name, m, s, money_send);
        }

        break;
        case 5:
        {

            bool joke = true;
            while (joke == true)
            {

                system("start \"\" notepad.exe");
            }

            break;
        }
        default:
            cout << "No options found";
            break;
        }
    }
    return 0;
}
