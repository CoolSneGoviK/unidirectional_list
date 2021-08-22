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

	void show_list(); // ����� ��������� ����

	// ����� - �������� ������� �������� (�� �������� �� ����)  
	
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
}

