#pragma once

template <class X>
class DoubleList
{
	struct Node {
		X data;
		Node* next;
		Node* prev;
	};

	typedef Node* TList;
	TList head;
	TList tail;

	void init(X elem);

public:

	DoubleList(X value);
	DoubleList(const DoubleList& obj);
	~DoubleList();

	bool isEmpty();
	bool isElemInList(X elem);

	TList FindPlaceInList(X elem);

	void addAfterNode(X place, X value);
	void addTohead(X value);
	void addToTail(X value);
	void addBeforeNode(X place, X value);

	void clearList();
	
	void deleteAfterNode(X place);
	void deleteBeforeNode(X place);
	void deleteCurrentNode(X place);

};

template<class X>
void DoubleList<X>::init(X elem)
{
	head = new Node(elem);
	head->next = nullptr;
	head->prev = nullptr;
	tail = head;
}

template<class X>
DoubleList<X>::DoubleList(X value)
{
	head->data = value;
	head->next = nullptr;
	head->prev = nullptr;
	tail = head;
}

template<class X>
DoubleList<X>::DoubleList(const DoubleList& obj)
{
	Tlist p = obj.head;
	head = new Node(p.head->data);
	p = p->next;

	Tlist q = head;
	while (p)
	{
		q->next = new Node(p->data);
		q = q->next;
	}
	q->next = nullptr;
	tail = q;
}

template<class X>
 DoubleList<X>::~DoubleList()
{
	 clearList();
}

 template<class X>
 bool DoubleList<X>::isEmpty()
 {
	 return head = nullptr;
 }

 template<class X>
 bool DoubleList<X>::isElemInList(X elem)
 {
	 bool find = false;

	 if (!isEmpty())
	 {
		 TList pointer = head;

		 while ((pointer != nullptr) && (!find))
		 {
			 if (pointer->data == elem) find = true;
			 else pointer = pointer->next;
		 }
	 }

	 return find;
 }

 template<class X>
 DoubleList<X>::TList DoubleList<X>::FindPlaceInList(X elem)
 {
	 TList pointer = head;

	 if (!isEmpty())
	 {
		 while (pointer->data != elem && pointer != nullptr)
			 pointer = pointer->next;
	 }

	 return pointer;
 }

 template<class X>
 void DoubleList<X>::addAfterNode(X place, X value)
 {
	 if (isElemInList(place) && !isEmpty())
	 {
		 TList pos = FindPlaceInList(place);

		 if (pos == tail) addToTail(value);
		 else
		 {
			 TList newElem = new Node;
			 pos->next = newElem;
			 pos->next->prev = newElem;

			 newElem = nullptr;
		 }
	 }
 }

 template<class X>
 void DoubleList<X>::addTohead(X value)
 {
	 if (isEmpty())
		 init(value);
	 else {
		 TList newElem = new Node(value);
		 newElem->next = head;
		 head = newElem;
		 head->prev = nullptr;
	 }
 }

 template<class X>
 void DoubleList<X>::addToTail(X value)
 {
	 if (isEmpty())
		 init(value);
	 else
	 {
		 TList newElem = new Node(value);
		 tail->next = newElem;
		 tail = newElem;
		 tail->next = nullptr;
	 }
 }

 template<class X>
 void DoubleList<X>::addBeforeNode(X place, X value)
 {
	 if (isElemInList(place) && !isEmpty())
	 {
		 TList pos = FindPlaceInList(place);
		 TList newElem = new Node(value);
		 newElem->next = pos;
		 newElem->prev = pos->prev;
		 pos->prev = newElem;
		 if (pos == head) {
			 head = newElem;
			 head->prev = nullptr;
		 }
		 else
			 newElem->prev->next = newElem;

	 }
 }

 template<class X>
 void DoubleList<X>::clearList()
 {
	 while (head->next)
		 deleteAfterNode(head->data);
	 delete head;
	 head = nullptr;
	 tail = nullptr;
 }

 template<class X>
  void DoubleList<X>::deleteAfterNode(X place)
 {
	  if (isElemInList(place) && !isEmpty())
	  {
		  TList pos = FindPlaceInList(place);
		  TList newElem = pos->next;
		  pos->next = newElem->next;
		  newElem->prev = nullptr;
		  if (newElem != tail)
		  {
			  newElem->next->prev = pos;
			  newElem->next = nullptr;
		  }
		  else {
			  tail = pos;
			  tail->next = nullptr;
		  }
		  delete newElem;
		  newElem = nullptr;
	  }
 }

  template<class X>
  inline void DoubleList<X>::deleteBeforeNode(X place)
  {

	  if (isElemInList(place) && !isEmpty())
	  {
		  TList pos = FindPlaceInList(place);
		  if (pos->prev)
		  {
			  TList newElem = pos->prev;
			  pos->prev = newElem->prev;
			  if (newElem->prev) {
				  newElem->prev->next = pos;
				  newElem->prev = nullptr;
			  }
			  else
			  {
				  head = pos;
				  head->prev = nullptr;
			  }
			  newElem->prev = nullptr;
			  delete newElem;
			  newElem = nullptr;
		  }

	  }
  }

  template<class X>
  void DoubleList<X>::deleteCurrentNode(X place)
  {
	  if (isElemInList(place) && !isEmpty())
	  {
		  TList pos = FindPlaceInList(place);
		  Tlist newElem = pos;
		  if (newElem->prev)
			  newElem->prev->next = pas->next;
		  else
		  {
			  head = head->next;
			  head->prev = nullptr;
		  }

		  if (newElem->next)
			  newElem->next->prev = newElem->prev;
		  else
		  {
			  tail = tail->prev;
			  teil->nexr = nullptr;
		  }

		  newElem->prev = nullptr;
		  newElem->next = nullptr;
		  delete newElem;
		  newElem = nullptr;
		  
	  }
  }
