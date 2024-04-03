//Angeline Vu, 2/19/2024, CS302-001, Program 2
//This file implements the template functions
//node and DLL

//Node template
//Default constructor: sets next and previous to null
template <typename TYPE>
node<TYPE>::node() : next(nullptr), prev(nullptr) {}

//Copy constructor: copies another node
template <typename TYPE>
node<TYPE>::node(const node<TYPE> & source) : next(nullptr), prev(nullptr)
{
	data = source.data;	
}

//Constructor with object type: create a node with the data source
template <typename TYPE>
node<TYPE>::node(const TYPE & source) : next(nullptr), prev(nullptr) 
{
	data = source;
}

//Get next ptr
template <typename TYPE>
typename node<TYPE>::node_ptr & node<TYPE>::get_next()
{
	return next;
}

//Get previous ptr
template <typename TYPE>
typename node<TYPE>::node_ptr & node<TYPE>::get_prev()
{
	return prev;
}

//Get data of node
template <typename TYPE>
TYPE & node<TYPE>::get_data()
{
	return data;
}

//Set next ptr
template <typename TYPE>
int node<TYPE>::set_next(const node_ptr new_next)
{
	next = new_next;
	return 1;
}

//Set previous ptr
template <typename TYPE>
int node<TYPE>::set_prev(const node_ptr new_prev)
{
	prev = new_prev;
	return 1;
}

//Compare node value
//Return 0 for greater than
//Return 1 for less than
//Return 2 for equal to
template <typename TYPE>
int node<TYPE>::compare(const TYPE & a_data)
{
	if (data < a_data)
		return 1;
	if (data == a_data)
		return 2;
	return 0;
}

//Display data
template <typename TYPE>
int node<TYPE>::display() const
{
	cout << data;
	return 1;
}

//Destructor
template <typename TYPE>
node<TYPE>::~node()
{
	next = prev = nullptr;
}

//DLL template
//Default constructor: set head and tail to nullptr
template <typename TYPE>
DLL<TYPE>::DLL() : head(nullptr), tail(nullptr) {}

//Copy constructor: uses assignment operating function
template <typename TYPE>
DLL<TYPE>::DLL(const DLL<TYPE> & source)
{
	*this = source;
}

//Operator overload for assingment (public)
template <typename TYPE>
DLL<TYPE> & DLL<TYPE>::operator=(const DLL<TYPE> & source)
{
	if (this == &source)	//Check for self assignment
		return *this;
	
	if (head)		//Exists? Delete
		delete head;	
	head = tail = nullptr;	//Set to null
	
	copy(source);		//Copy list
	return *this;
}

//Copy wrapper function: is private
template <typename TYPE>
int DLL<TYPE>::copy(const DLL<TYPE> & source)
{
	if (!source.head)	//Empty list
		return 0;

	head = new node(*source.head);	//Copy first node
	head->set_prev(nullptr);	
	
	return copy(head->get_next(), head, source.head->get_next());
}

//Copy recursive function
template <typename TYPE>
int DLL<TYPE>::copy(node_ptr & head, node_ptr & previous, node_ptr & source)
{
	if (!source)		//Empty list
	{
		head = nullptr;
		tail = previous;
		return 1;
	}

	head = new node(*source);	//Create new node
	head->set_prev(previous);
	
	return copy(head->get_next(), previous->get_next(), source->get_next());
}

//Get input from user to insert
template <typename TYPE>
int DLL<TYPE>::insert()
{
	TYPE data;
	cin >> data;
	return insert(data);
}

//Insert a new node with given input
template <typename TYPE>
int DLL<TYPE>::insert(const TYPE & new_data)
{
	if (!head)	//Empty
	{
		head = new node(new_data);
		head->set_prev(nullptr);
		head->set_next(nullptr);
		tail = head;
		return 1;
	}

	if (head->compare(new_data) == 1)	//Add new node before
	{
		node_ptr hold = head;
		head = new node(new_data);
		head->set_prev(nullptr);
		head->set_next(hold);
		hold->set_prev(head);
		return 1;
	}

	if (head->compare(new_data) == 2)	//Duplicate alert! == case
		return 0;

	return insert(head->get_next(), head, new_data);
}

//Recursive function
template <typename TYPE>
int DLL<TYPE>::insert(node_ptr & head, node_ptr & prev, const TYPE & new_data)
{
	if (!head)	//Append
	{
		head = new node(new_data);
		head->set_next(nullptr);
		tail = head;
		return 1;
	}

	if (head->compare(new_data) == 1)	//Add before node, returns true if new_data > data
	{
		node_ptr hold = head;
		head = new node(new_data);
		head->set_prev(prev);
		head->set_next(hold);
		return 1;
	}

	if (head->compare(new_data) == 2)	//Duplicate alert! == case
		return 0;

	return insert(head->get_next(), prev->get_next(), new_data);
}

//Display all
template <typename TYPE>
int DLL<TYPE>::display() const
{
	if (!head)
		return 0;
	return display(head);
}

//Display recursive function
template <typename TYPE>
int DLL<TYPE>::display(node_ptr head) const
{
	if (!head)
		return 1;
	head->display();
	return display(head->get_next());	
}

//Retrieve data!
template <typename TYPE>
int DLL<TYPE>::retrieve(const TYPE & match, node_ptr & hold)
{
	if (!head)
		return 0;

	return retrieve(head, match, hold);
}

//Recursive function for retrieve match
template <typename TYPE>
int DLL<TYPE>::retrieve(node_ptr head, const TYPE & match, node_ptr & hold)
{
	if (!head)			//No match
		return 0;

	if (head->compare(match) == 2)	//Match, function return of 2 indicates match
	{
		hold = head;
		return 1;
	}

	return retrieve(head->get_next(), match, hold);
}

//Remove one match
template <typename TYPE>
int DLL<TYPE>::rm_one(const TYPE & match)
{
	if (!head)
		return 0;
	
	if (head->compare(match) == 2)	//Match! First node
	{
		if (head == tail)	//One node
			tail = nullptr;
		node_ptr hold = head->get_next();
		delete head;
		head = hold;
		return 1;
	}
	
	return rm_one(head->get_next(), head, match);
}

//Recursive function for remove one match
template <typename TYPE>
int DLL<TYPE>::rm_one(node_ptr & head, node_ptr & prev, const TYPE & match)
{
	if (!head)	//No match
		return 0;

	if (head->compare(match) == 2)	//Match	
	{
		if (head == tail)	//Last node
			tail = prev;
		node_ptr hold = head->get_next();
		delete head;
		head = hold;
		prev->set_next(head);
		if (head)
			head->set_prev(prev);
		return 1;
	}
	
	return rm_one(head->get_next(), prev->get_next(), match);
}

//Remove all function wrapper
template <typename TYPE>
int DLL<TYPE>::rm_all()
{
	if (!head)
		return 0;
	return rm_all(head);
}

//Remove all function recursive
template <typename TYPE>
int DLL<TYPE>::rm_all(node_ptr & head)
{
	if (!head)
	{
		tail = nullptr;
		return 1;
	}
	
	node_ptr hold = head->get_next();
	delete head;
	head = hold;
	return rm_all(head);
}

//Destructor
template <typename TYPE>
DLL<TYPE>::~DLL()
{
	if (head)
		rm_all(head);
	head = tail = nullptr;
}
