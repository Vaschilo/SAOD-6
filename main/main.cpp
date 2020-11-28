//Теннисный турнир проходит по олимпийской системе с
//выбыванием. Третий призер определяется в матче игроков,
//проигравших полуфинальные встречи. Известен рейтинг каждого
//игрока.Турнир записан с помощью дерева. Участникам
//соответствуют листья дерева.Известно, что турнир прошел в полном
//соответствии с рейтингом игроков. Требуется выдать результаты по
//турам и определить первых трех призеров

#include "Tree.h"
#include <fstream>
#include <functional>

void from_file(Tree& t)
{
	fstream f;
	Team pr;
	f.open("file.txt");
	if (!f.is_open()) return;
	while (!f.eof())
	{
		f >> pr;
		t.push(pr);
	}
	f.close();
}

void from_hand(Tree& t)
{
	int power = 1;
	string name = "Std_name";

	function<int(string)> f = [](string a)
	{
		int n = 1;
		do
		{
			if (n <= 0) cout << "Введите значение больше 0";
			cout << "\n" << a << "\n";
			cin >> n;
		} while (n <= 0);
		return n;
	};

	int n = f("Введите число команд");

	for (int i = 0; i < n; i++)
	{
		cout << "Введите название команды\n";
		cin >> name;
		power = f("Введите время рейтинг этой детали");
		t.push(Team(name, power));
	}
}

int main()
{
    Tree a;

	from_file(a);

    a.push(Team("a", 1));
    a.push(Team("b", 4));
    a.push(Team("c", 2));
    a.push(Team("d", 3));
    a.push(Team("e", 4));
    a.push(Team("f", 6));
    a.push(Team("g", 5));
    
    for (int i = 0; i < 5; i++)
    {
		system("cls");
        a.print();
        cout << "======================\n\n";
        a.tournament_print(i); system("pause");
    }

    return 0;
}