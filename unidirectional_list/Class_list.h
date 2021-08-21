#pragma once // для подключения заголовочного файла один раз

template <class T> // template - шаблон
class List
{
public:
	List(); // объявление, конструктор по умолчанию ничего не делает
	//~List();

private:

	template <class T>
	class Node
	{ // узел - из узлов состоит список
		Node* Next;
		T data;
	};

	Node* head;
	int Size;
};

template <class T>
List<T>::List () 
{} // определение - пустое, по умолчанию ничего не происходит
