#include <iostream>
#include <string>

using namespace std;

class Ticket {
public:
    int int_number = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

    void do_sex_with_numbers()
    {
        a = int_number / 100000;
        b = (int_number / 10000) % 10;
        c = (int_number / 1000) % 10;
        d = (int_number / 100) % 10;
        e = (int_number / 10) % 10;
        f = int_number % 10;
    }

    bool is_happy()
    {
        if (a + b + c == d + e + f)
            return true;
        else
            return false;
    }

};

    int main()
    {
        bool happy = false;
        Ticket vovas_ticket;

        cin >> vovas_ticket.int_number;

        vovas_ticket.int_number += 1;
        vovas_ticket.do_sex_with_numbers();
        if (vovas_ticket.is_happy())
        {
            cout << "Yes";
            return 0;
        }

        vovas_ticket.int_number -= 2;
        vovas_ticket.do_sex_with_numbers();
        if (vovas_ticket.is_happy())
        {
            cout << "Yes";
            return 0;
        }
        cout << "No";
        return 0;
    }
