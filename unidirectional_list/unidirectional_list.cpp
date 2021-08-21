#include "Class_list.h" // "" - мой класс
#include <iostream> // <> - стандартная библиотека

using namespace std;

int main()
{

    List<int> N; // класс подключился, тут выбрал тип int 
    N.add_element(10); // добавили 1 элемент 
    system("pause");
    return 0;
}

