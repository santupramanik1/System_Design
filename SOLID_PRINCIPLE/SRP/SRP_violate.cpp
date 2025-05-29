#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
public:
    double price;
    string name;

    // Constructor
    Product(string name, double price)
    {
        this->price = price;
        this->name = name;
    }
};

// Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProducts(Product *p)
    {
        products.push_back(p);
    }

    // This is used to access0 the product outside the class since the product list is private
    const vector<Product *> &getProducts()
    {
        return products;
    }

    // 1. Calculates total price in cart.
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }

    // Print Invoice
    void printInvoice()
    {
        cout << "Shopping Cart Invoice :" << endl;

        for (auto p : products)
        {
            cout << p->name << " " << p->price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    // Save to the Database
    void saveToDatabase()
    {
        cout << "Saving shopping cart to database..." << endl;
    }
};
int main()
{
    ShoppingCart *cart=new ShoppingCart();

    cart->addProducts(new Product("Laptop",80000));
    cart->addProducts(new Product("Mouse",2000));

    cart->printInvoice();
    cart->saveToDatabase();
    return 0;
}