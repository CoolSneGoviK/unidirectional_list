#pragma once // ��� ����������� ������������� ����� ���� ���

template <class T> // template - ������
class List
{
public:
	List(); // ����������, ����������� �� ��������� ������ �� ������
	//~List();

private:

	template <class T>
	class Node
	{ // ���� - �� ����� ������� ������
		Node* Next;
		T data;
	};

	Node* head;
	int Size;
};

template <class T>
List<T>::List () 
{} // ����������� - ������, �� ��������� ������ �� ����������
