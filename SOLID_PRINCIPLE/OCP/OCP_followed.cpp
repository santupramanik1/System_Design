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
};

// The Responsibilities of this class is used to print the invoice
class CartInvoicePrinter
{
private:
    ShoppingCart *cart; // here we get the reference of the ShoppinCart class

public:
    // Constructor
    CartInvoicePrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    // Print Invoice
    void printInvoice()
    {
        cout << "Shopping Cart Invoice :" << endl;

        for (auto p : cart->getProducts())
        {
            cout << p->name << " " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

// Abstract class
class Persistence
{
private:
    ShoppingCart *car;

public:
    virtual void save(ShoppingCart *car) = 0; // Pure virtual function
};

// Save the data into Sql Database
class SqlPersistence : public Persistence
{
public:
    void save(ShoppingCart *car) override
    {
        cout << "Saving Shopping Cart into SQl DB.." << endl;
    }
};

// Save the data into mongoDB
class MongoPersistence : public Persistence
{
public:
    void save(ShoppingCart *car) override
    {
        cout << "Saving Shopping Cart into MongoDB.." << endl;
    }
};

// Save the data into File
class FilePersistence : public Persistence
{
public:
    void save(ShoppingCart *car) override
    {
        cout << "Saving Shopping Cart into File.." << endl;
    }
};

// main function
int main()
{
    ShoppingCart *cart = new ShoppingCart();

    cart->addProducts(new Product("Laptop", 80000));
    cart->addProducts(new Product("Mouse", 2000));

    CartInvoicePrinter *printer = new CartInvoicePrinter(cart);
    printer->printInvoice();

    SqlPersistence *sql = new SqlPersistence();
    sql->save(cart);

    MongoPersistence *db=new MongoPersistence();
    db->save(cart);

    FilePersistence *file=new FilePersistence();
    file->save(cart);
    return 0;
}