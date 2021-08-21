#pragma once // для подключения заголовочного файла один раз

template <class T> // template - шаблон
class List
{
public:
	List(); // объявление, конструктор по умолчанию ничего не делает
	//~List();

	void add_element(T data); // добавление элемента в конец списка
	void add_start(T data); // добавление в начало
	// метод - добавление элемента по индексу

	// метод - вывод элементов всех
	 
	// метод - поменять местами элементы (их значения по сути)  
	
	// метод - удаление элемента (первого, последнего, по индексу)
	// метод - удаление всех элементов (вызвать в деструкторе списка)

private:

	template <class T>
	class Node
	{ // узел - из узлов состоит список
	public:
		Node(T data = T(), Node<T>* next = nullptr) // принимает данные и указатель на следующий узел в списке
		{
			this->data = data;
		}

		Node* Next;
		T data;
	};

	Node<T>* head = nullptr;
	int Size = 0;
};

template<class T>
void List<T>::add_start(T data)
{
	head = new Node<T>(data, head); // это добавление в начало списка элемента
	Size++;
};

template <class T>
List<T>::List()
{}; // определение - пустое, по умолчанию ничего не происходит

template<class T>
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


