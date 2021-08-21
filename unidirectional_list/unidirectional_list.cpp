#include "Class_list.h" // "" - мой класс
#include <iostream> // <> - стандартная библиотека

using namespace std;

int main()
{

    List<int> N; // класс подключился, тут выбрал тип int 
    N.add_start(0); // добавили 1 элемент в начало
    N.add_start(1);
    N.add_element(5); // добавили 1 элемент в конец 
    N.add_element(10);
    N.add_element(15);
    N.add_element(20);
    N.add_element(25);
    system("pause");
    return 0;
}

