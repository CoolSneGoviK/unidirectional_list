#pragma once // дл€ подключени€ заголовочного файла один раз

#include <iostream> 
using namespace std;

template <class T> // template - шаблон
class List
{
public:
	List(); // объ€вление, конструктор по умолчанию ничего не делает
	//~List();

	void add_element(T data); // добавление элемента в конец списка
	void add_start(T data); // добавление в начало

	// метод - добавление элемента по индексу
	T& index_value(int index = 0); // получение значени€ элемента по индексу
	void show_list(); // вывод элементов всех

	void swap(int index1 = 0, int index2 = 1); // помен€ть местами элементы (их значени€ по сути)

	// метод - удаление элемента (первого, последнего, по индексу)
	// метод - удаление всех элементов (вызвать в деструкторе списка)

private:

	template <class T> // класс - узел
	class Node 
	{ // узел - из узлов состоит список
	public:
		Node(T data = T(), Node<T>* next = nullptr) // принимает данные и указатель на следующий узел в списке
		{
			this->data = data;
			this->Next = next;
		}

		Node* Next = nullptr;
		T data;
	};

	Node<T>* head = nullptr;
	int Size = 0;
};

template<class T> // добавление в начало
void List<T>::add_start(T data)
{
	head = new Node<T>(data, head); // это добавление в начало списка элемента
	Size++;
};

template <class T>
List<T>::List()
{}; // определение - пустое, по умолчанию ничего не происходит

template<class T> // добавление элемента в конец
void List<T>::add_element(T data)
{
	if (this->head == nullptr)
	{
		this->head = new Node<T>(data);
		this->Size++;
	}
	else
	{
		Node<T>* first_element = head; // сохран€ем указатель на первый элемент
		while (head->Next)
		{
			head = head->Next;
		}

		head->Next = new Node<T>(data);
		head = first_element;
		Size++;
	}
}

template <class T> // вывод всех элементов на экран
void List<T>::show_list() 
{
	Node<T>* first_element = head; // сохран€ем указатель на первый элемент
	while (head->Next)
	{
		cout << head->data << " ";
		head = head->Next;
	}
	head = first_element;
	cout << endl;
}

template <class T> // возвращает данные элемента по индексу
T& List<T>::index_value(int index) 
{ 
	int counter = 0;
	Node<T>* first_element = head; // сохран€ем указатель на первый элемент
	while (head->Next) 
	{
		if (counter == index) 
		{
			Node<T>* current = head;
			head = first_element;
			return current->data; // возвращаетс€ значение или ссылка на него решаетс€ в объ€влении функции
		}
		head = head->Next;
		counter++;
	}
}

template <class T> // мен€ем местами значени€ двух элементов
void List<T>::swap(int index1, int index2) 
{
	int t = index_value(index1); // получили значение первого
	index_value(index1) = index_value(index2); // присвоили первому значение второго
	index_value(index2) = t; // второму значение первого
}