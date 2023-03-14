#include <iostream>
#include "Header.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	MAIN m;
	int k;
	cout << "\nДобро пожаловать в игру Виселица" << endl;

	cout << "Желаете поиграть? (1/0)" << endl;
	cin >> k;
	if (k == 1) {
		cout << "Тогда начинаем! " << endl << endl;
		m.game();
	}
	else
		cout << "Всего доброго..." << endl;

}
