#pragma once // ��� ����������� ������������� ����� ���� ���

template <class T> // template - ������
class List
{
public:
	List(); // ����������, ����������� �� ��������� ������ �� ������
	//~List();
	void add_element(T data); // ���������� ��������

private:

	template <class T>
	class Node
	{ // ���� - �� ����� ������� ������
	public:
		Node(T data = T(), Node<T>* next = nullptr) // ��������� ������ � ��������� �� ��������� ���� � ������
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
{}; // ����������� - ������, �� ��������� ������ �� ����������

template<class T>
void List<T>::add_element(T data)
{
	if (this->head == nullptr)
	{
		this->head = new Node<T>(data);
		this->Size++;
	}
};
