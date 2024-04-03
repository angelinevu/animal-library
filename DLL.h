#include <memory>

//Angeline Vu, 2/19/2024, CS302-001, Program 2
//This file has class interfaces for templates DLL 
//and its node

//Node template: DLL has a pointer to a node
template <typename TYPE>
class node
{
	public:
		typedef node<TYPE> * node_ptr;		//Alias
		node();					//Default constructor
		node(const node<TYPE> & source);	//Copy constructor
		node(const TYPE & source);		//Object constructor
		node_ptr & get_next();			//Get next ptr
		node_ptr & get_prev();			//Get prev ptr
		TYPE & get_data();			//Get data
		int set_next(const node_ptr new_next);	//Set next ptr;
		int set_prev(const node_ptr new_prev);	//Set prev ptr;
		int compare(const TYPE & datum);	//Compares data
		int display() const;			//Displays
		~node();

	private:
		TYPE data;	//TYPE data
		node_ptr next;	//Next ptr
		node_ptr prev;	//Prev ptr
};

//DLL template: DLL has a pointer to a node
template <typename TYPE>
class DLL
{
	public:
		typedef node<TYPE> * node_ptr;		//Alias
		DLL();					//Default constructor
		DLL(const DLL<TYPE> & source);		//Copy constructor
		DLL<TYPE> & operator=(const DLL<TYPE> & source);	//Assignment overloader
		int insert();						//Get input to insert
		int insert(const TYPE & new_data);			//Insert into DLL
		int display() const;					//Display DLL
		int retrieve(const TYPE & match, node_ptr &);		//Retrieve a species match
		int rm_one(const TYPE & match);				//Remove a match
		int rm_all();						//Remove all entries
		
		~DLL();
		
	private:
		node_ptr head;	//DLL head
		node_ptr tail;	//DLL tail
		int copy(const DLL<TYPE> & source);					//Copy function			
		int copy(node_ptr & head, node_ptr & prev, node_ptr & source);		//Copy recursive function
		int insert(node_ptr & head, node_ptr & prev, const TYPE & data);	//Insert recursive function
		int display(node_ptr head) const;					//Display recursive function
		int retrieve(node_ptr head, const TYPE & match, node_ptr &);		//Retrieve match
		int rm_one(node_ptr & head, node_ptr & prev, const TYPE & match);	//Remove a match
		int rm_all(node_ptr & head);						//Remove all recursive function
};

#include "DLL.tpp"
