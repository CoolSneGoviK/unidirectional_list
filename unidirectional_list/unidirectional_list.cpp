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
    //N.delete_all(); // удаляет все элементы - работает, добавить его в деструктор 
    //N.delete_by_index(3); // удаляет элемент по индексу - работает
    //N.delete_last(); // удаление последнего - работает 
    //N.delete_first(); // удаление первого элемента - работает
    //N.add_by_index(1, 1000); // добавление элемента по индексу - работает
    //N.swap(0,5); // замена значений элементов - работает
    //cout << N[2] << endl; // перегруженный оператор получение элемента по индеку работает
    
    //cout << N.index_value(-10) << " - data index" << endl; // получение элемента по индексу - работает
    
    //N.index_value(2)++; // получаем ссылку на значение - работает
    
    N.show_list();

    system("pause");
    return 0;
}

