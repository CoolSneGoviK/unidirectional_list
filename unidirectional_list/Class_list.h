#pragma once // ��� ����������� ������������� ����� ���� ���

#include <iostream> 
using namespace std;

template <class T> // template - ������
class List
{
public:
	List(); // ����������, ����������� �� ��������� ������ �� ������
	//~List();

	void add_element(T data); // ���������� �������� � ����� ������
	void add_start(T data); // ���������� � ������

	// ����� - ���������� �������� �� �������
	T& index_value(int index = 0); // ��������� �������� �������� �� �������
	void show_list(); // ����� ��������� ����

	void swap(int index1 = 0, int index2 = 1); // �������� ������� �������� (�� �������� �� ����)

	// ����� - �������� �������� (�������, ����������, �� �������)
	// ����� - �������� ���� ��������� (������� � ����������� ������)

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

template<class T> // ���������� � ������
void List<T>::add_start(T data)
{
	head = new Node<T>(data, head); // ��� ���������� � ������ ������ ��������
	Size++;
};

template <class T>
List<T>::List()
{}; // ����������� - ������, �� ��������� ������ �� ����������

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

template <class T> // ����� ���� ��������� �� �����
void List<T>::show_list() 
{
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
	int t = index_value(index1); // �������� �������� �������
	index_value(index1) = index_value(index2); // ��������� ������� �������� �������
	index_value(index2) = t; // ������� �������� �������
}