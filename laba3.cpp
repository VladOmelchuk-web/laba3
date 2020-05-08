#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

struct country
{
	string Name;
	string capital;
	string language;
	string money;
	string president;
	double square;
	string maner;
	enum func
	{
		add_ = 1,
		output_,
		sort_,
		find_,
		delete_,
		exit_,
	};
};


int nextStep();
void getData(country*, int);
void output(country*, int);
void conversion(int n, ...);
void menu();

void(*mass[])(country*, int) = { getData, output };
int main(int argc, char* argv[])
{
	char pass[] = "123";
	/*if (strcmp(pass, argv[1]) || argv[1] == NULL)
	{
		cout << "Wrong password";
		return 0;
	}*/

	{
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int count = 0, command;
		country* gos = new country[count];
		command = nextStep();
		while (command != gos[0].exit_)
		{
			switch (command)
			{
				// add
			case gos[0].add_:
			{
				system("cls");
				int n = count;
				country* temp = new country[n + 1];
				for (int i = 0; i < n; i++)
				{
					temp[i] = gos[i];
				}
				gos = new country[n + 1];
				for (int i = 0; i < n; i++)
				{
					gos[i] = temp[i];
				}
				(mass[0])(gos, n);
				system("cls");
				delete[] temp;
				count++;
				command = nextStep();
				break;
			}
			// output
			case gos[0].output_:
			{
				system("cls");
				for (int i = 0; i < count; i++)
					(mass[1])(gos, i);
				system("pause");
				command = nextStep();
				break;
			}
			// sort
			case gos[0].sort_:
			{
				system("cls");
				int choice = 0;
				cout << "Sort by country name (1)/capital (2)" << endl;
				cin >> choice;
				if (choice < 1 || choice > 2)
				{
					cin >> choice;
				}
				switch (choice)
				{
				case 1:
				{
					for (int i = 0; i < count; i++) {
						for (int k = 0; k < count - 1; k++) {
							if (gos[k].Name > gos[k + 1].Name)
								swap(gos[k], gos[k + 1]);
						}
					}
					break;
				}
				case 2:
				{
					for (int i = 0; i < count; i++) {
						for (int k = 0; k < count - 1; k++) {
							if (gos[k].capital > gos[k + 1].capital)
								swap(gos[k], gos[k + 1]);
						}
					}
					break;
				}
				default:
					break;
				}
				command = nextStep();
				break;
			}
			// find
			case gos[0].find_:
			{
				system("cls");
				int choice;
				cout << "Find:"
					<< endl << "1.Country name"
					<< endl << "2.Capital"
					<< endl << "3.Language";
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					system("cls");
					char name[50];
					bool flagFind = 0;
					cout << "Enter country name: ";
					cin.ignore();
					cin.getline(name, 50);
					for (int i = 0; i < count; i++)
					{
						if (name == gos[i].Name)
						{
							(mass[1])(gos, i);
							cout << endl;
							flagFind = 1;
						}
					}
					if (flagFind)
						system("pause");
					else {
						cout << "No results" << endl;
						system("pause");
					}
					command = nextStep();
					break;
				}
				case 2:
				{
					system("cls");
					char capital[50];
					bool flagFind = 0;
					cout << "Enter capital: ";
					cin.ignore();
					cin.getline(capital, 50);
					for (int i = 0; i < count; i++)
					{
						if (capital == gos[i].capital)
						{
							(mass[1])(gos, i);
							cout << endl;
							flagFind = 1;
						}
					}
					if (flagFind)
						system("pause");
					else {
						cout << "No results" << endl;
						system("pause");
					}
					command = nextStep();
					break;
				}
				case 3:
				{
					system("cls");
					char trd[50];
					bool flagFind = 0;
					cout << "Enter language: ";
					cin.ignore();
					cin.getline(trd, 50);
					for (int i = 0; i < count; i++)
					{
						if (trd == gos[i].language)
						{
							(mass[1])(gos, i);
							cout << endl;
							flagFind = 1;
						}
					}
					if (flagFind)
						system("pause");
					else {
						cout << "No results" << endl;
						system("pause");
					}
					command = nextStep();
					break;
				}
				default:
					break;
				}

				break;
			}
			// delete
			case gos[0].delete_:
			{
				int choice;
				cout << "Total " << count << " elements, what should delete? ";
				if (!count) {
					command = nextStep();
					break;
				}
				cin >> choice;
				while (choice < 0 || choice > count) {
					cin >> choice;
				}
				for (int i = choice - 1; i < count - 1; i++)
					gos[i] = gos[i + 1];
				if (count != 0)
				{
					count--;
				}
				command = nextStep();
				break;
			}
			default:
				break;
			}
		}
		delete[] gos;
		return 0;
	}
}

void getData(country* a, int i)
{
	cout << "Enter title: ";
	cin >> a[i].Name;
	cout << "Enter capital: ";
	cin >> a[i].capital;
	cout << "Enter language: ";
	cin >> a[i].language;
	cout << "Enter money type: ";
	cin >> a[i].money;
	cout << "Enter goverment maner: ";
	cin >> a[i].maner;
	cout << "Enter president: ";
	cin.ignore();
	getline(cin, a[i].president);
	cout << "Enter square: ";
	cin >> a[i].square;
}

void output(country* a, int i)
{
	cout << "Country name: " << a[i].Name << endl;
	cout << "Capital: " << a[i].capital << endl;
	cout << "Language: " << a[i].language << endl;
	cout << "Square: " << a[i].square << endl;
	cout << "Money type: " << a[i].money << endl;
	cout << "President: " << a[i].president << endl;
	cout << "Goverment type: " << a[i].maner << endl;
	cout << endl;
	conversion(3, 0.2, 0.5, 0.7);
	cout << endl << endl;
}

void conversion(int n, ...)
{
	va_list ptr;
	va_start(ptr, n);
	double argument;
	cout << "Your\tAnother" << endl;
	for (int i = 0; i < n; i++)
	{
		argument = va_arg(ptr, double);
		cout << 1 << "\t" << argument << endl;
	}
	va_end(ptr);
}
int nextStep()
{
	int com;
	system("cls");
	menu();
	cin >> com;
	return com;
}
void menu()
{
	cout << "1. Add element" << endl;
	cout << "2. Output" << endl;
	cout << "3. Sort" << endl;
	cout << "4. Find" << endl;
	cout << "5. Delete" << endl;
	cout << "6. Exit" << endl;
}
