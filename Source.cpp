#include<iostream>
#include <list>
#include <ctime>
using namespace std;

template <typename T>
class List
{
public:
	List();

	~List();
	void Clear();
	void Add_Last(T data);
	void Add_First(T data);
	void Del_First();
	void Del_Last();
	void delByIndex(int index);
	void insByIndex(T data, int index);
	int GetSize()
	{
		return Size;
	}
	int searchByValue(int value);
	T& operator[](const int index);

private:
	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
void List<T>::Add_Last(T data)
{

	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;

}

template <typename T>
void List<T>::Add_First(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		head = new Node<T>(data);
		head->pNext = current;

	}
	Size++;
}

template <typename T>
void List<T>::Del_Last()
{
	Node<T>* current = head;
	if (head->pNext != nullptr)
	{
		current = head->pNext;

	}
	else
	{
		delete head->pNext;
		current->pNext = nullptr;
	}

	Size--;
}

template <typename T>
void List<T>::Del_First()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;

}

template <typename T>
void List<T>::Clear()
{
	while (Size)
	{
		Del_First();
	}
}

template <typename T>
T& List<T>:: operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}


}

template <typename T>
void List<T>::insByIndex(T data, int index)
{
	if (index == 0)
	{
		Add_First(data);
	}
	else
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->pNext;
		}
		Node <T>* newNode = new Node<T>(data, current->pNext);
		current->pNext = newNode;
	}
	Size++;
}

template <typename T>
void List<T>::delByIndex(int index) 
{
	if (index == 0)
	{
		Del_First();
	}
	else
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->pNext;
		}
		Node<T>* toDelete = current->pNext;
		current->pNext = toDelete->pNext;
		delete toDelete;
	
	}
	Size--;
}

template <typename T>
int List<T>::searchByValue(int value)
{
	Node<T>* current =this->head;
	for (int i = 0; i <Size; i++)
	{
		if (value == current->data)
		{
			return current->data;
			
		}
		else
		{
			current = current->pNext;
		}
	}
	return -1;
}


template <typename T>
List<T>::~List()
{
	Clear();

}

int main()
{
	srand(time(NULL));
	List<int> lst;
	int numbElements;
	cout << "Enter numbers of elements: " << endl;
	cin >> numbElements;
	cout << endl;
	for (int i = 0; i < numbElements; i++)
	{
		lst.Add_Last(rand() % 100);
	}

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << "---Add 1 element in the head ---" << endl;

	lst.Add_First(rand() % 100);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "---Dellete 1 last element  ---" << endl;

	lst.Del_Last();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	int  index_ad;
	cout << "Enter index of element you want to add " << endl;
	cin >> index_ad;
	cout << endl;
	lst.insByIndex(rand() % 100, index_ad);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	int  index_del;
	cout << "Enter index of element you want to delete " << endl;
	cin >> index_del;
	cout << endl;
	lst.delByIndex(index_del);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}


	int search;
	cout << "Enter data you want to search " << endl;
	cin >> search;
	cout << endl;
	cout << lst.searchByValue(search);
	

	return 0;
}
