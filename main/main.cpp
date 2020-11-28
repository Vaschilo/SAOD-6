//Теннисный турнир проходит по олимпийской системе с
//выбыванием. Третий призер определяется в матче игроков,
//проигравших полуфинальные встречи. Известен рейтинг каждого
//игрока.Турнир записан с помощью дерева. Участникам
//соответствуют листья дерева.Известно, что турнир прошел в полном
//соответствии с рейтингом игроков. Требуется выдать результаты по
//турам и определить первых трех призеров

#include "Tree.h"

int main()
{
    Tree a;

    a.push(Team("a", 1));
    a.print();
    a.push(Team("b", 4));
    a.print();
    a.push(Team("c", 2));
    a.print();
    a.push(Team("d", 3));
    a.print();system("pause");system("cls");
    a.push(Team("e", 4));
    a.print();system("pause");system("cls");
    a.push(Team("f", 6));
    a.print();system("pause");system("cls");
    a.push(Team("g", 5));
    a.print();system("pause"); system("cls");
    a.tournament_print(1);system("pause"); system("cls");


    return 0;
}