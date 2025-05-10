#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

class CurrencyConverter {
private:
    unordered_map<string, double> exchangeRates;

public:
    CurrencyConverter() {
        // Predefined exchange rates (example values)
        exchangeRates["USD"] = 1.0;       // Base currency
        exchangeRates["EUR"] = 0.91;      // 1 USD = 0.91 EUR
        exchangeRates["GBP"] = 0.78;      // 1 USD = 0.78 GBP
        exchangeRates["INR"] = 83.10;     // 1 USD = 83.10 INR
        exchangeRates["JPY"] = 150.50;    // 1 USD = 150.50 JPY
    }

    void convert(string from, string to, double amount) {
        if (exchangeRates.find(from) == exchangeRates.end() || exchangeRates.find(to) == exchangeRates.end()) {
            cout << "Invalid currency code!\n";
            return;
        }

        double convertedAmount = (amount / exchangeRates[from]) * exchangeRates[to];
        cout << fixed << setprecision(2);
        cout << amount << " " << from << " = " << convertedAmount << " " << to << "\n";
    }

    void displayRates() {
        cout << "Exchange Rates (Base: USD):\n";
        for (const auto& rate : exchangeRates) {
            cout << "1 USD = " << rate.second << " " << rate.first << "\n";
        }
    }
};

int main() {
    CurrencyConverter converter;
    int choice;
    string from, to;
    double amount;

    while (true) {
        cout << "\nCurrency Converter\n";
        cout << "1. Convert Currency\n2. Display Exchange Rates\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source currency (USD, EUR, GBP, INR, JPY): ";
                cin >> from;
                cout << "Enter target currency (USD, EUR, GBP, INR, JPY): ";
                cin >> to;
                cout << "Enter amount: ";
                cin >> amount;
                converter.convert(from, to, amount);
                break;
            case 2:
                converter.displayRates();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}