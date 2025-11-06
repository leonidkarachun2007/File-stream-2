#include <iostream>
#include<fstream>
#include<string>

using namespace std;


class Car
{
	string model;
	int year;
	double price;

public:
	Car(){}
	Car(string mod, int y, double pr)
	{
		model = mod;
		year = y;
		price = pr;

	}
	void Print()
	{
		cout << model << "\t" << year << "\t" << price << endl;
	}
	void SaveFile(string filename)
	{
		ofstream write;
		write.open(filename, ios::out);
		write << "Model: " << model << "\tYear: " << year << "\tPrice: " << price << "$\n";
		write.close();
	}
	void LoadFile()
	{
		ifstream write("Car.txt");
		while (!write.eof())
		{
			string temp;

			write >> temp;
			cout << temp << " ";
		}
		write.close();
	}
};


int main() {
	Car obj1("Audi A5", 2023, 30000);
	obj1.Print();
	obj1.SaveFile("Car.txt");
	obj1.LoadFile();
}