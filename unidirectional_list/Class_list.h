#pragma once // для подключения заголовочного файла один раз

template <class T> // template - шаблон
class List
{
public:
	List(); // объявление, конструктор по умолчанию ничего не делает
	//~List();
	void add_element(T data); // добавление элемента

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
};
