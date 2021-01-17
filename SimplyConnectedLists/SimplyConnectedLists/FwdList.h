#pragma once
#include <iostream>
#define MY_DEBUG
using namespace std;

template<typename T>
class FwdList
{
public:
	FwdList() = default;
	FwdList(const FwdList& other);
	void pushFront(const T& data);
	void pushTail(const T& data);
	void pushAfter(const T& searchData, const T& insData);
	void eraseByData(const T& searchData);
	void eraseFront();
	void eraseTail();
	bool isEmpty() const;
	void clear();
	void print() const;
	FwdList& operator = (const FwdList& data);
	bool operator == (const FwdList& data);
	size_t searchAndChangeData(const T& searchData, const T& changeData);
	void reverse();
	~FwdList();

private:
	struct Node
	{
		T data;
		Node* next;
		Node(const T& data, Node* next = nullptr)
			:data(data), next(next)
		{}
		void changeData(const T& data)
		{
			this->data = data;
		}
	};
	auto findNode(const T& data);
	Node* head = nullptr;
	Node* tail = nullptr;
};

template<typename T>
inline FwdList<T>::FwdList(const FwdList& other)
{
	if (other.isEmpty())
		return;
	Node* temp = other.head;
	while (temp!=nullptr)
	{
		this->pushTail(temp->data);
		temp = temp->next;
	}
}

template<typename T>
inline void FwdList<T>::pushFront(const T& data)
{
	Node* tmp = new Node(data,head);
	//tmp->data = data;
	//tmp->next=head
	if (isEmpty()) tail = tmp; //first
	head = tmp;
}

template<typename T>
inline void FwdList<T>::pushTail(const T& data)
{
	Node* add = new Node(data, nullptr);
	if (!isEmpty())
		tail->next = add;
	else
		head = add;
	
	tail = add;

}

template<typename T>
inline void FwdList<T>::pushAfter(const T& searchData, const T& insData)
{
	Node* find = findNode(searchData);
	if (find != nullptr)
	{
		Node* ins = new Node(insData, find->next);
		find->next = ins;
		if (find == tail)
			tail = ins;
	}
}

template<typename T>
inline void FwdList<T>::eraseByData(const T& searchData)
{
	Node* find = findNode(searchData);
	if (find != nullptr)
	{
		if (find->next != nullptr) {
			Node* temp = head;
			while (temp->next!=find)
				temp->next = temp;
			temp->next = find->next;
			delete find;
		}
	}
}

template<typename T>
inline void FwdList<T>::print() const
{
	Node* temp = head;
	cout << "----------LIST-PRINT-----------" << endl;
	while (temp != nullptr)
	{
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << "\n--------LIST-PRINT-END--------" << endl;
}

template<typename T>
inline FwdList<T>& FwdList<T>::operator=(const FwdList& other)
{
	Node* temp = other.head;
	while (temp != nullptr)
	{
		this->pushTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

template<typename T>
inline void FwdList<T>::eraseFront()
{
	if (!isEmpty())
	{
		auto temp = head;
		head = head->next;
		if (isEmpty()/*head == nullptr*/)
			tail = nullptr;
#ifdef MY_DEBUG
		cout << "Was deleted " << temp->data << endl;
#endif
		delete temp;
	}
}

template<typename T>
inline void FwdList<T>::eraseTail() //make if 1 elem in all!!!!
{
	if (!isEmpty())
	{
		Node* temp = head;
		if (temp != tail) {
			while (temp->next != tail)
				temp = temp->next;
			delete temp->next;
			tail = temp;
			tail->next = nullptr;
		}
		else
		{
			head = nullptr;
			tail = nullptr;
		}
	}
}

template<typename T>
inline bool FwdList<T>::isEmpty() const
{
	if (head == nullptr)
		return true;
	return false;
}

template<typename T>
inline void FwdList<T>::clear()
{
	while (!isEmpty())
		eraseFront();
}

template<typename T>
inline bool FwdList<T>::operator==(const FwdList& data)
{
	if (isEmpty() || data.isEmpty())
		return false;
	Node* temp = head;
	Node* dataTemp = data.head;
	while (dataTemp != nullptr && temp != nullptr)
	{
		if (temp->data != dataTemp->data)
			return false;
		temp = temp->next;
		dataTemp = dataTemp->next;
	}
	if (temp == nullptr && dataTemp != nullptr || temp != nullptr && dataTemp == nullptr)
		return false;
	return true;
}

template<typename T>
inline size_t FwdList<T>::searchAndChangeData(const T& searchData, const T& changeData)
{
	size_t countChanges = 0;
	Node* temp = head;
	while (temp!=nullptr)
	{
		if (temp->data == searchData) {
			temp->data = changeData;
			++countChanges;
		}
		temp = temp->next;
	}
	return countChanges;
}

template<typename T>
inline void FwdList<T>::reverse()
{
	if (isEmpty())
		return;
	Node* els = tail;
	if (head == tail)
	{
		els = tail;
		tail = head;
		head = els;
		return;
	}
	Node* temp = head;
	while (temp->next != tail)
		temp = temp->next;
	while (temp!=head)
	{
		els->next = temp;
		els = els->next;
		temp = head;
		while (temp->next != els)
			temp = temp->next;
	}
	els = tail;
	tail = head;
	head = els;

}

template<typename T>
inline FwdList<T>::~FwdList()
{
	clear();
}

template<typename T>
inline auto FwdList<T>::findNode(const T& data)
{
	Node* res=head;
	while(res!=nullptr && res->data!=data)
		res = res->next;

	return res;
}

