#include <iostream>
#include <string>
using namespace std;

class Pizza {
public:
    // Constructor to initialize pizza attributes

    void inputDescription() {
        cout << "Please enter the type of your pizza."<<endl;
        cin >> type_;
        cout << "Please enter the size of your pizza." << endl;
        cin >> size_;
        cout << "Please enter the amount number of your pizza." << endl;
        cin >> toppings_;
    }

    // Output the description of the pizza
    void outputDescription() {
        std::cout << "This is a " << size_ << " " << type_ << " pizza with "
                  << toppings_ << " toppings." << endl;
    }

    // Compute the price of the pizza
    double computePrice() {
        double basePrice = 0.0;

        // Set base price based on pizza size
        if (size_ == "small") {
            basePrice = 10.0;
        } else if (size_ == "medium") {
            basePrice = 14.0;
        } else if (size_ == "large") {
            basePrice = 17.0;
        }

        // Calculate total price including toppings
        double totalPrice = basePrice + (2.0 * toppings_);
        return totalPrice;
    }

private:
    string type_;   // Type of pizza (Deep Dish, Hand Tossed, Pan)
    string size_;   // Size of pizza (small, medium, large)
    int toppings_;       // Number of toppings
};

int main() {

   char y_n;
   Pizza myPizza;
   
   do {
        myPizza.inputDescription();
        myPizza.outputDescription();
        cout << "The price of the pizza is $" << myPizza.computePrice() << "." << endl;
        cout << endl;

        cout << "Would you like to have another pizza?" << endl;
        cin >> y_n;
    }while (y_n == 'y');


    return 0;
}
