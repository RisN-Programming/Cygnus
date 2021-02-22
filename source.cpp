#include "header.cpp"
#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>

using namespace std;

class Product
{
	public:
	int id, stock, sold, weight;
	string name;
	float price, cost;
};

int keyID, menu;
string keyName;
bool running = true;
list <Product> Products;
fstream file;

int main()
{
	while (running)
	{
		cout << "Main Menu" << endl;
		cout << "1) Display All " << endl;
		cout << "2) Add A New Product " << endl;
		cout << "3) Edit Existing Product " << endl;
		cout << "4) Delete Existing Product " << endl;
		cout << "5) Search Products " << endl;
		cout << "6) Exit Without Saving" << endl;
		cout << "7) Exit And Save" << endl;

		cin >> menu;
	   	cout << endl;
	    
		switch (menu)
		{
			case 1: 
			{
				DisplayAll(); 
				break; 
			}

			case 2: 
			{
				AddProduct(); 
				break;
			}

			case 3: 	
			{
				cout << "Please Enter The ID of The Product You Would Like to Edit: " << endl;
				cin >> keyID;
				cout << endl;
				EditProduct(keyID); 
				break;
			}

			case 4: 
			{
				cout << "Please Enter The ID of The Product You Would Like to Delete: " << endl;
				cin >> keyID;
				cout << endl;
				RemoveProduct(keyID); 
				break;
			}

			case 5: 
			{
				ProductSearch(); 
				break;
			}

			case 6: 
			{
				running = false; 
				break;
			}

			case 7: 
			{
				Save(); 
				running = false; 
				break;
			}
		}
		cout << endl;
	}
	return 0;
}

void DisplayAll()
{
	if (Products.empty()) 
	{ 
		cout << "There Are No Products To Be Displayed " << endl; 
		return; 
	}

	for (list<Product> ::iterator itAll = Products.begin(); itAll != Products.end(); itAll++)
	{
		cout << "Product ID: " << (itAll)->id << endl;
		cout << "Product Name: " << (itAll)->name << endl;
		cout << "Product Stock Level: " << (itAll)->stock << endl;
		cout << "Product Selling Price: " << (itAll)->price << endl;
		cout << "Product Wholesale Price: " << (itAll)->cost << endl;
		cout << "Product Unit Weight: " << (itAll)->weight << endl;
		cout << "Product Sold: " << (itAll)->sold << endl;
	}
}

void AddProduct()
{
	Product newProduct;

	cout << "Enter Product ID" << endl;
	cin >> newProduct.id;
	cout << endl;
	
	cout << "Enter Product Name" << endl;
	cin >> newProduct.name;
	cout << endl;
		
	cout << "Enter Product Stock Level" << endl;
	cin >> newProduct.stock;
	cout << endl;
		
	cout << "Enter Product Selling Price" << endl;
	cin >> newProduct.price;
	cout << endl;
		
	cout << "Enter Product Wholesale Price" << endl;
	cin >> newProduct.cost;
	cout << endl;
		
	cout << "Enter Product Unit Weight" << endl;
	cin >> newProduct.weight;
	cout << endl;
		
	cout << "Enter Number of Items Sold " << endl;
	cin >> newProduct.sold;
	cout << endl;
		
	Products.push_back(newProduct);
}

void EditProduct(int ID)
{
	int aspect = 0;
	for (list<Product>::iterator itBegin = Products.begin(); itBegin != Products.end(); itBegin++)
	{
		if ((itBegin->id) == ID)
		{
			cout << "What would you like to edit?"<< endl;
			cout << "1) Product Name"<< endl;
			cout << "2) Selling Price"<< endl;
			cout << "3) Stock Level" << endl;
			cout << "4) Product ID"<< endl;
			cout << "5) Number Sold"<< endl;
			cin >> aspect;
            		cout << endl;
            
			switch (aspect)
			{
				case 1:
				{ 
					cout << "Please Enter Updated Product Name: " << endl;
					cin >> (itBegin)->name; 
					return;
				}
	
				case 2:
				{ 
					cout << "Please Enter Updated Selling Price: " << endl;
					cin >> (itBegin)->price; 
					return;
				}
	
				case 3:
				{
					cout << "Please Enter Updated Stock Level: " << endl;
					cin >> (itBegin)->stock; 
					return;
				}		

				case 4:
				{ 
					cout << "Please Enter Updated Product ID: " << endl;
					cin >> (itBegin)->id; 
					return;
				}

				case 5:
				{ 
					cout << "Please Enter Updated Number Of Product Sold: " << endl;
					cin >> (itBegin)->sold; 
					return;
				}
			}
		}
	}
	cout << "Product ID Could Not Be Found" << endl;
	return;
}

void RemoveProduct(int ID)
{
	for (list<Product>::iterator itBegin = Products.begin(); itBegin != Products.end(); itBegin++)
	{
		if ((itBegin->id) == ID)
		{
			Products.erase(itBegin);
			return;
		}
	}
	cout << "Product ID Could Not Be Found" << endl;
}

void ProductSearch()
{
	int choice;

	cout << "Search by: " << endl;
	cout << "1) Product ID" << endl;
	cout << "2) Product Name" << endl;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
		case 1: 
		{
			cout << "Please Enter The Product ID: " << endl;
			cin >> keyID;
			cout << endl;
			
			for (list<Product>::iterator itSearch = Products.begin(); itSearch != Products.end(); itSearch++)
			{
				if ((itSearch->id) == keyID)
				{
					cout << "Product ID: " << (itSearch)->id << endl;
					cout << "Product Name: " << (itSearch)->name << endl;
					cout << "Product Stock Level: " << (itSearch)->stock << endl;
					cout << "Product Selling Price: " << (itSearch)->price << endl;
					cout << "Product Wholesale Price: " << (itSearch)->cost << endl;
					cout << "Product Unit Weight: " << (itSearch)->weight << endl;
					cout << "Product Sold: " << (itSearch)->sold << endl;
					cout << endl;
					return;
				}
			}
			cout << "Product ID Could Not Be Found" << endl; 
			return; 
		}

		case 2: 
		{	
			cout << "Please Enter The Product Name: " << endl;
			cin >> keyName;
			cout << endl;
			for (list<Product>::iterator itSearch = Products.begin(); itSearch != Products.end(); itSearch++)
			{
				if ((itSearch->name) == keyName)
				{
					cout << "Product ID: " << (itSearch)->id << endl;
					cout << "Product Name: " << (itSearch)->name << endl;
					cout << "Product Stock Level: " << (itSearch)->stock << endl;
					cout << "Product Selling Price: " << (itSearch)->price << endl;
					cout << "Product Wholesale Price: " << (itSearch)->cost << endl;
					cout << "Product Unit Weight: " << (itSearch)->weight << endl;
					cout << "Product Sold: " << (itSearch)->sold << endl;
					cout << endl;
					return;
				}
			}  
		cout << "Product Name Could Not Be Found" << endl;
		return; 
		}
	}
}

void Save()
{
	file.open("list.txt", ios::out | ios::app);

	if (file.good() == true)
	{
		for (list<Product> ::iterator itAll = Products.begin(); itAll != Products.end(); itAll++)
		{
			file << (itAll)->id << endl;
			file << (itAll)->name << endl;
			file << (itAll)->stock << endl;
			file << (itAll)->price << endl;
			file << (itAll)->cost << endl;
			file << (itAll)->weight << endl;
			file << (itAll)->sold << endl;
			cout << endl;
			file << endl;
		}
		file.close();
	}
}