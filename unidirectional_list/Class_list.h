#pragma once // для подключения заголовочного файла один раз

#include <iostream> 
using namespace std;

template <class T> // template - шаблон
class List
{
public:
	List(); // объявление, конструктор по умолчанию ничего не делает
	~List() 
	{ // очищает память от элементов списка при удалении объекта
		delete_all();
	};

	void add_element(T data); // добавление элемента в конец списка 
	void add_start(T data); // добавление в начало 
	void add_by_index(int index = 1, T data = T()); // метод - добавление элемента по индексу 
	
	T& index_value(int index = 0); // получение значения элемента по индексу 
	T& operator [] (int index); // получение по индексу с перегрузкой [] 
	
	void show_list(); // вывод элементов всех 

	void swap(int index1 = 0, int index2 = 1); // поменять местами элементы (их значения по сути) 

	void delete_first(); // удаление первого элемента 
	void delete_last(); // удаление последнего 
	void delete_by_index(int index = 0); // удаление по индексу МИНУС
	void delete_all(); // удаление всех элементов списка

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

template <class T>
List<T>::List()
{}; // определение - пустое, по умолчанию ничего не происходит

template<class T> // добавление в начало
void List<T>::add_start(T data)
{
	head = new Node<T>(data, head); // это добавление в начало списка элемента
	Size++;
};

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
		Node<T>* first_element = head; // сохраняем указатель на первый элемент
		while (head->Next)
		{
			head = head->Next;
		}

		head->Next = new Node<T>(data);
		head = first_element;
		Size++;
	}
}

template <class T> // добавление элемента по индексу, элементы считаются с 0
void List<T>::add_by_index(int index, T data)
{
	if (index < 0)
	{ 
		cout << "error" << endl;
		return;
	}

	if (index == Size)
	{ // добавим в конец списка элемент 
		add_element();
		return;
	}

	if (index > Size - 1)
	{
		cout << "error" << endl;
		return;
	}

	if (index == 0) // если индекс 0, вызывваем метод вставки в начало
	{
		add_start(data);
		return;
	}

	int counter = 0;
	Node<T>* first_element = head; // сохраняем указатель на первый элемент
	while (head->Next)
	{
		if (counter == index - 1)
		{ // за этим элементов нужно вставить новый
			head->Next = new Node<T>(data, head->Next->Next);
			head = first_element;
			break;
		}
		head = head->Next;
		counter++;
	}
}

template <class T> // вывод всех элементов на экран
void List<T>::show_list() 
{
	if (Size == 0) 
	{
		cout << "the list is empty " << endl;
		return;
	}

	Node<T>* first_element = head; // сохраняем указатель на первый элемент
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
	if (index < 0)
	{
		cout << "error" << endl; // выводит ошибку в консоль и возвращает ссылку на данные первого элемента
		return head->data;
	}

	if (index > Size -1) 
	{
		cout << "error" << endl; // выводит ошибку в консоль и возвращает ссылку на данные первого элемента
		return head->data; 
	} 

	int counter = 0;
	Node<T>* first_element = head; // сохраняем указатель на первый элемент
	while (head->Next) 
	{
		if (counter == index) 
		{
			Node<T>* current = head;
			head = first_element;
			return current->data; // возвращается значение или ссылка на него решается в объявлении функции
		}
		head = head->Next;
		counter++;
	}
}

template<class T> // возвращает данные элемента по индексу
T& List<T>::operator[](int index)
{
	if (index < 0)
	{
		cout << "error" << endl; // выводит ошибку в консоль и возвращает ссылку на данные первого элемента
		return head->data;
	}

	if (index > Size - 1)
	{
		cout << "error" << endl; // выводит ошибку в консоль и возвращает ссылку на данные первого элемента
		return head->data;
	}

	int counter = 0;
	Node<T>* first_element = head; // сохраняем указатель на первый элемент
	while (head->Next)
	{
		if (counter == index)
		{
			Node<T>* current = head;
			head = first_element;
			return current->data; // возвращается значение или ссылка на него решается в объявлении функции
		}
		head = head->Next;
		counter++;
	}
}

template <class T> // меняем местами значения двух элементов
void List<T>::swap(int index1, int index2)
{
	if (index1 < 0 || index2 < 0)
	{
		cout << "error" << endl;
		return;
	}

	if (index1 >= Size - 1 || index2 >= Size - 1)
	{
		cout << "error" << endl;
		return;
	}

	int t = index_value(index1); // получили значение первого
	index_value(index1) = index_value(index2); // присвоили первому значение второго
	index_value(index2) = t; // второму значение первого
}

template <class T> // удаление первого элемента
void List<T>::delete_first()
{
	if (Size == 0) 
	{
		return;
	}

	if (Size == 1)
	{
		delete head;
		head = nullptr;
		Size--;
		return;
	}

	Node<T>* delete_elem = head;
	head = head->Next;
	delete delete_elem;
	Size--;
};

template <class T> // удаление последнего элемента
void List<T>::delete_last() 
{
	if (Size == 0) 
	{
		return;
	}

	if (Size == 1)
	{
		delete head;
		head = nullptr;
		Size--;
		return;
	}

	Node<T>* first_element = head; // сохраняем указатель на первый элемент
	while (head->Next)
	{ 
		if (head->Next->Next == nullptr)
		{ // значит нашли предпоследний элемент
			delete head->Next;
			head->Next = nullptr;
			head = first_element;
			break;
		}
		head = head->Next;
	}
	Size--;
}

template <class T> // удаление элемент по индексу, элементы считаются с 0
void List<T>::delete_by_index(int index)
{ 
	if (index > Size - 1) 
	{
		cout << "error" << endl;
		return;
	}

	if (index == 0) 
	{
		delete_first();
		return;
	} 

	int counter = 0; 
	Node<T>* first_element = head; // сохраняем указатель на первый элемент
	while (head->Next)
	{
		if (counter == index - 1)
		{ // элемент после которого нужно удалить
			Node<T>* delete_element = head->Next; // этот элемент нужно удалить
			head->Next = head->Next->Next;
			delete delete_element;
			head = first_element;
			Size--;
			break;
		}
		head = head->Next;
		counter++;
	}
};

template <class T> //удаление всех елементов из списка
void List<T>::delete_all() 
{
	while (Size)
	{
		delete_first();
	}
}