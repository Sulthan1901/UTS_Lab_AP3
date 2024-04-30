#include <iostream>
using namespace std;
int main() {
    cout << "Enter your account number: ";
    int validation, valid, validation2, valid2;
    long long account_number, mods, divide;
    cin >> account_number;
    mods = 100;
    divide = 10;
    validation = 0;
    do {
        valid = (((account_number % mods) / divide) * 2);
        if (valid >= 10 || valid < 0) {
            int digit_1, digit_2;
            digit_1 = valid % 10;
            digit_2 = valid / 10;
            valid = digit_1 + digit_2;
        } else {
            valid = valid;
        }
        validation = validation + valid;
        mods *= 100;
        divide *= 100;
    } while ((mods <= 10000000000000000) || (divide <= 1000000000000000));

    mods = 10;
    divide = 1;
    validation2 = 0;
    do {
        valid2 = ((account_number % mods) / divide);
        validation2 = validation2 + valid2;
        mods *= 100;
        divide *= 100;
    } while ((mods <= 1000000000000000) || (divide <= 100000000000000));

    int total_validation = validation + validation2;

    string card_type;
    if ((((account_number % 10000000000000000) / 1000000000000000) == 5) && (total_validation % 10 == 0)) {
        card_type = "MASTERCARD";
    } else if ((((account_number % 10000000000000000) / 1000000000000000) == 4) && (total_validation % 10 == 0)) {
        card_type = "VISA";
    } else {
        card_type = "invalid";
    }
    cout << "Your card number: " << account_number << endl;
    cout << "Your card type: " << card_type << endl;
    cout << "Checksum: " << total_validation << endl;
    return 0;
}
