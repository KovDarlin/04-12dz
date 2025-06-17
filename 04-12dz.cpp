#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Product {
public:
	string name;
	string category;
	double price;
	int stock;
	Product(const string& n, const string& c, double p, int s): name(n), category(c), price(p), stock(s){}
};

int main() {
    vector<Product> products = {
        Product("apples", "fruits", 15.60, 300),
        Product("lemon", "fruits", 12.90, 200),
        Product("carrots", "vegetables", 30.50, 9),
        Product("potatos", "vegetables", 29.98, 500),
        Product("pepsi", "drinks", 35.30, 120),
        Product("sprite", "drinks", 45.70, 120)
    };

    sort(products.begin(), products.end(),
        [](const Product& a, const Product& b) {
            return a.price < b.price;
        });
    cout << "\nProducts by price:\n";
    for (const auto& p : products) {
        cout << p.name << " - " << p.price << " UAH\n";
    }

    vector<Product> lowStock;
    copy_if(products.begin(), products.end(), back_inserter(lowStock),
        [](const Product& p) {
            return p.stock < 10;
        });
    cout << "\nLow stock products (<10):\n";
    for (const auto& p : lowStock) {
        cout << p.name << " (" << p.stock << " piece)\n";
    }

    string targetCategory = "fruits";
    vector<Product> categoryProducts;
    copy_if(products.begin(), products.end(), back_inserter(categoryProducts),
        [targetCategory](const Product& p) {
            return p.category == targetCategory;
        });
    double avgPrice = 0.0;
    if (!categoryProducts.empty()) {
        double sum = accumulate(categoryProducts.begin(), categoryProducts.end(), 0.0,
            [](double acc, const Product& p) {
                return acc + p.price;
            });
        avgPrice = sum / categoryProducts.size();
    }

    cout << "\nAverage price in the category " << targetCategory << ": " << avgPrice << " UAH\n";

    double totalValue = accumulate(products.begin(), products.end(), 0.0,
        [](double acc, const Product& p) {
            return acc + (p.price * p.stock);
        });

    cout << "\nTotal cost of all products in stock: " << totalValue << " UAH\n";

}
