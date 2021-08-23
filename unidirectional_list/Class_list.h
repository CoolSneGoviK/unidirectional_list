#pragma once // ��� ����������� ������������� ����� ���� ���

#include <iostream> 
using namespace std;

template <class T> // template - ������
class List
{
public:
	List(); // ����������, ����������� �� ��������� ������ �� ������
	~List() 
	{ // ������� ������ �� ��������� ������ ��� �������� �������
		delete_all();
	};

	void add_element(T data); // ���������� �������� � ����� ������ 
	void add_start(T data); // ���������� � ������ 
	void add_by_index(int index = 1, T data = T()); // ����� - ���������� �������� �� ������� 
	
	T& index_value(int index = 0); // ��������� �������� �������� �� ������� 
	T& operator [] (int index); // ��������� �� ������� � ����������� [] 
	
	void show_list(); // ����� ��������� ���� 

	void swap(int index1 = 0, int index2 = 1); // �������� ������� �������� (�� �������� �� ����) 

	void delete_first(); // �������� ������� �������� 
	void delete_last(); // �������� ���������� 
	void delete_by_index(int index = 0); // �������� �� ������� �����
	void delete_all(); // �������� ���� ��������� ������

private:

	template <class T> // ����� - ����
	class Node 
	{ // ���� - �� ����� ������� ������
	public:
		Node(T data = T(), Node<T>* next = nullptr) // ��������� ������ � ��������� �� ��������� ���� � ������
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
{}; // ����������� - ������, �� ��������� ������ �� ����������

template<class T> // ���������� � ������
void List<T>::add_start(T data)
{
	head = new Node<T>(data, head); // ��� ���������� � ������ ������ ��������
	Size++;
};

template<class T> // ���������� �������� � �����
void List<T>::add_element(T data)
{
	if (this->head == nullptr)
	{
		this->head = new Node<T>(data);
		this->Size++;
	}
	else
	{
		Node<T>* first_element = head; // ��������� ��������� �� ������ �������
		while (head->Next)
		{
			head = head->Next;
		}

		head->Next = new Node<T>(data);
		head = first_element;
		Size++;
	}
}

template <class T> // ���������� �������� �� �������, �������� ��������� � 0
void List<T>::add_by_index(int index, T data)
{
	if (index < 0)
	{ 
		cout << "error" << endl;
		return;
	}

	if (index == Size)
	{ // ������� � ����� ������ ������� 
		add_element();
		return;
	}

	if (index > Size - 1)
	{
		cout << "error" << endl;
		return;
	}

	if (index == 0) // ���� ������ 0, ��������� ����� ������� � ������
	{
		add_start(data);
		return;
	}

	int counter = 0;
	Node<T>* first_element = head; // ��������� ��������� �� ������ �������
	while (head->Next)
	{
		if (counter == index - 1)
		{ // �� ���� ��������� ����� �������� �����
			head->Next = new Node<T>(data, head->Next->Next);
			head = first_element;
			break;
		}
		head = head->Next;
		counter++;
	}
}

template <class T> // ����� ���� ��������� �� �����
void List<T>::show_list() 
{
	if (Size == 0) 
	{
		cout << "the list is empty " << endl;
		return;
	}

	Node<T>* first_element = head; // ��������� ��������� �� ������ �������
	while (head->Next)
	{
		cout << head->data << " ";
		head = head->Next;
	}
	head = first_element;
	cout << endl;
}

template <class T> // ���������� ������ �������� �� �������
T& List<T>::index_value(int index) 
{ 
	if (index < 0)
	{
		cout << "error" << endl; // ������� ������ � ������� � ���������� ������ �� ������ ������� ��������
		return head->data;
	}

	if (index > Size -1) 
	{
		cout << "error" << endl; // ������� ������ � ������� � ���������� ������ �� ������ ������� ��������
		return head->data; 
	} 

	int counter = 0;
	Node<T>* first_element = head; // ��������� ��������� �� ������ �������
	while (head->Next) 
	{
		if (counter == index) 
		{
			Node<T>* current = head;
			head = first_element;
			return current->data; // ������������ �������� ��� ������ �� ���� �������� � ���������� �������
		}
		head = head->Next;
		counter++;
	}
}

template<class T> // ���������� ������ �������� �� �������
T& List<T>::operator[](int index)
{
	if (index < 0)
	{
		cout << "error" << endl; // ������� ������ � ������� � ���������� ������ �� ������ ������� ��������
		return head->data;
	}

	if (index > Size - 1)
	{
		cout << "error" << endl; // ������� ������ � ������� � ���������� ������ �� ������ ������� ��������
		return head->data;
	}

	int counter = 0;
	Node<T>* first_element = head; // ��������� ��������� �� ������ �������
	while (head->Next)
	{
		if (counter == index)
		{
			Node<T>* current = head;
			head = first_element;
			return current->data; // ������������ �������� ��� ������ �� ���� �������� � ���������� �������
		}
		head = head->Next;
		counter++;
	}
}

template <class T> // ������ ������� �������� ���� ���������
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

	int t = index_value(index1); // �������� �������� �������
	index_value(index1) = index_value(index2); // ��������� ������� �������� �������
	index_value(index2) = t; // ������� �������� �������
}

template <class T> // �������� ������� ��������
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

template <class T> // �������� ���������� ��������
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

	Node<T>* first_element = head; // ��������� ��������� �� ������ �������
	while (head->Next)
	{ 
		if (head->Next->Next == nullptr)
		{ // ������ ����� ������������� �������
			delete head->Next;
			head->Next = nullptr;
			head = first_element;
			break;
		}
		head = head->Next;
	}
	Size--;
}

template <class T> // �������� ������� �� �������, �������� ��������� � 0
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
	Node<T>* first_element = head; // ��������� ��������� �� ������ �������
	while (head->Next)
	{
		if (counter == index - 1)
		{ // ������� ����� �������� ����� �������
			Node<T>* delete_element = head->Next; // ���� ������� ����� �������
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

template <class T> //�������� ���� ��������� �� ������
void List<T>::delete_all() 
{
	while (Size)
	{
		delete_first();
	}
}