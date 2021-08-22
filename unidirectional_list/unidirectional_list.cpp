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

    N.show_list();
    //N.add_by_index(1, 1000); // работает
    // N.swap(2,3); // работает - ок, порядок
    //cout << N[2] << endl; // работает
    //cout << N.index_value(2) << " - data index 2" << endl;
    //N.index_value(2)++; // получаем ссылку на значение - работает
    N.show_list();



    system("pause");
    return 0;
}

