#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 商品类
class Product {
public:
	Product(string name, int price) : name(name), price(price) {}
	
	string getName() const {
		return name;
	}
	
	int getPrice() const {
		return price;
	}
	
private:
	string name;
	int price;
};

// 商城管理系统类
class Shop {
public:
	void addProduct(const Product& product) {
		products.push_back(product);
	}
	
	void displayProducts() const {
		cout << "商城商品列表：" << endl;
		for (const auto& product : products) {
			cout << "名称：" << product.getName() << ", 价格：" << product.getPrice() << "元" << endl;
		}
	}
	
private:
	vector<Product> products;
};

int main() {
	Shop shop;
	
	// 添加商品
	Product product1("商品1", 100);
	Product product2("商品2", 200);
	shop.addProduct(product1);
	shop.addProduct(product2);
	
	// 显示商品列表
	shop.displayProducts();
	
	return 0;
}

