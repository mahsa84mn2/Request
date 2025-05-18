#include <iostream>
#include<string>
#include <vector>
#include <limits.h> 
using namespace std;
class node_BST
{
public:
	node_BST(string name = "", int ID = 0);
	void set(string name, int ID);
	string get_name_Bst();
	int get_ID_Bst();

	string Name_Bst;
	int id_Bst;
	node_BST* L;
	node_BST* R;
	node_BST* P;
};

node_BST::node_BST(string name, int ID)
{
	L = NULL;
	R = NULL;
	P = NULL;
	Name_Bst = name;
	id_Bst = ID;
}

void node_BST::set(string name, int ID)
{
	Name_Bst = name;
	id_Bst = ID;
	
}

string node_BST::get_name_Bst()
{
	return Name_Bst;
}

int node_BST::get_ID_Bst()
{
	return id_Bst;
}

class node_Maxheap
{
public:
	node_Maxheap(int ID = 0, int priority = 0);
	void set(int ID, int priority);
	int get_ID_Max(); 
	int get_priority_Max();

	int id_Max;
	int Priority_Max;

	node_Maxheap* P;
	
};

node_Maxheap::node_Maxheap(int ID, int priority)
{
	id_Max = ID;
	Priority_Max = priority; 
	P = NULL; 
}

void node_Maxheap::set(int ID, int priority)
{
	id_Max = ID;
	Priority_Max = priority;
}

int node_Maxheap::get_ID_Max()
{
	return id_Max;
}

int node_Maxheap::get_priority_Max()
{
	return Priority_Max;
}

class BST
{
public:
	BST();
	void insert(node_BST* TC, node_BST* new_node);
	void Tnsert_BST(string name,int id);
	node_BST* search_Request_BST(int id); 
	bool search(int id);
	int size_BST(); 
    bool isEmpty_BST();
	void print_BST(node_BST* TC);
	void delete_request_BST(int id);


	node_BST* root;

};
BST::BST()
{
	root = NULL;
}

void BST::insert(node_BST* TC, node_BST* new_node) 
{  
	node_BST* save_p = NULL;
	node_BST* x = TC;
	while (x != NULL)
	{
		save_p = x;
		if (new_node->id_Bst < x->id_Bst)
		{
			x = x->L;
		}
		else
			x = x->R; 
	}
	new_node->P = save_p;
	if (save_p == NULL)
		root = new_node;
	else if (new_node->id_Bst < save_p->id_Bst)
		save_p->L = new_node;
	else
		save_p->R = new_node;
}

void BST::Tnsert_BST(string name, int id) 
{
	node_BST* new_node = new node_BST(name, id);
	if (root == NULL)
	{
		root = new_node; 
	}
	else
	{
		insert(root, new_node);
	}
}

node_BST* BST::search_Request_BST(int id)
{
	node_BST* TC = root;
	while (TC != NULL && id != TC->id_Bst)
	{
		if (id < TC->id_Bst)
			TC = TC->L;
		else
			TC = TC->R;
	}

	if (TC == NULL)
		cout << "not found the request with ID=" << id << endl;
	else
		cout << "found the request=" << TC->Name_Bst << "  with ID=" << id << endl;
	return TC;

}

bool BST::search(int id)
{
	node_BST* TC = root;
	while (TC != NULL && id != TC->id_Bst)
	{
		if (id < TC->id_Bst)
			TC = TC->L;
		else
			TC = TC->R;
	}

	if (TC == NULL)
		return 1;
	else
		return 0;
	
}


int BST::size_BST()
{
	if (root == NULL)
		return 0;
	int TC = 0;
	vector<node_BST*> stack; 
	stack.push_back(root); 
	while (!stack.empty())
	{
		node_BST* current= stack.back(); 
		stack.pop_back(); 
		TC++;
		if (current->R != NULL) 
			stack.push_back(current->R); 
		if (current->L != NULL)
			stack.push_back(current->L); 
	}
	return TC;
}

bool BST::isEmpty_BST()
{
	if (root == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void BST::print_BST(node_BST* TC)
{
	if (isEmpty_BST() == 1)
	{
		cout << " *nothing to print* " << endl;
		return;
	}
	if (TC != NULL)
	{
		cout << "name: " << TC->get_name_Bst() << " ID: " << TC->get_ID_Bst() << endl;
		print_BST(TC->L);
		print_BST(TC->R);
	}
}

void BST::delete_request_BST(int id)
{
	if (isEmpty_BST()==1)
	{
		cout << " *is empty* " << endl;
		return; 
	}

	node_BST* TC = root;

	while (TC != NULL && TC->get_ID_Bst() != id)
	{
		if (id < TC->get_ID_Bst())
		{
			TC = TC->L;
		}
		else
		{
			TC = TC->R;
		}
	}

	if (TC == NULL)
		return;

	node_BST* delete_node;
	node_BST* child_node;

	if (TC->L == NULL || TC->R == NULL)
	{
		delete_node = TC;
	}
	else
	{
		delete_node = TC->R;
		while (delete_node->L != NULL)
		{
			delete_node = delete_node->L;
		}
	}

	if (delete_node->L != NULL)
	{
		child_node = delete_node->L;
	}
	else
	{
		child_node = delete_node->R;
	}

	if (child_node != NULL)
	{
		child_node->P = delete_node->P; 
	}

	if (delete_node->P == NULL)
	{
		root = child_node; 
	}
	else if (delete_node == delete_node->P->L)
	{
		delete_node->P->L = child_node;
	}
	else
	{
		delete_node->P->R = child_node;
	}

	if (delete_node != TC)
	{
		TC->get_name_Bst() = delete_node->get_name_Bst();
		TC->id_Bst = delete_node->id_Bst;
	}
	delete delete_node;
}


 


class Maxheap
{
public:
	Maxheap();
	bool isEmpty_Maxheap();
	int size_Maxheap();
	void Increase_priority(int id,int new_priority);
	void Insert_Heap(int id, int priority);
	void Print_Maxheap(int index);
	void Maxheap_ify(int index);
	node_Maxheap* Delete_Maxheap();
	void Delete_node(int id);
	
private:
	BST* BST_tree; 
	vector<node_Maxheap> Heap_array;    


};



Maxheap::Maxheap()
{
}


bool Maxheap::isEmpty_Maxheap()
{
	if (Heap_array.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Maxheap::size_Maxheap()
{
	int size = Heap_array.size();
	return size;
}

void Maxheap::Increase_priority(int id, int new_priority)
{

	for (int i = 0; i < Heap_array.size(); i++)
	{
		if (Heap_array[i].get_ID_Max() == id)
		{
			if (new_priority < Heap_array[i].get_priority_Max()) 
			{
				cout << "the new priority is smaller" << endl;
				return;
			}
			int save_i = i;
			Heap_array[save_i].set(id, new_priority);
			int parent = (save_i - 1) / 2; 
			while (save_i > 0 && Heap_array[parent].get_priority_Max() < Heap_array[save_i].get_priority_Max())
			{
				swap(Heap_array[save_i], Heap_array[parent]);
				save_i = parent;
				parent = (save_i - 1) / 2; 
			}
			return;
		}
	}     

}

void Maxheap::Insert_Heap(int id, int priority)
{
	node_Maxheap new_node(id, -100);
	Heap_array.push_back(new_node);
	Increase_priority(id, priority); 
}

void Maxheap::Print_Maxheap(int index)
{
	for (int i = 0; i < Heap_array.size();i++)
	{
		cout << "ID: " << Heap_array[i].get_ID_Max() << " priorit: " << Heap_array[i].get_priority_Max() << endl;
	}
}

void Maxheap::Maxheap_ify(int index)
{
	int L = (2 * index + 1);
	int R = (2 * index + 2);
	int largest = 0;

	if (L < Heap_array.size() && Heap_array[L].get_priority_Max() > Heap_array[index].get_priority_Max())
	{
		largest = L;
	}
	else
	{
		largest = index;
	}

	if (R < Heap_array.size() && Heap_array[R].get_priority_Max() > Heap_array[largest].get_priority_Max())
	{
		largest = R;
	}

	if (largest != index)
	{
		swap(Heap_array[index], Heap_array[largest]);
		Maxheap_ify(largest);
	}
}

node_Maxheap* Maxheap::Delete_Maxheap()
{
	if (isEmpty_Maxheap() == 1)
	{
		cout << " *the heap is empty* " << endl;
		return nullptr;
	}
	node_Maxheap* max = new node_Maxheap(Heap_array[0].get_ID_Max(), Heap_array[0].get_priority_Max());
 
	Heap_array[0] = Heap_array.back();
	Heap_array.pop_back();

	
	Maxheap_ify(0);
	return max; 
}

void Maxheap::Delete_node(int id)
{
	int index=0;
	while ( index< Heap_array.size() && Heap_array[index].get_ID_Max() != id)
	{
		index = index + 1;
	}

	if (index == Heap_array.size())
	{
		return;
	}

	Heap_array[index] = Heap_array.back();
	Heap_array.pop_back();

	if (index < Heap_array.size())
	{
		Maxheap_ify(index);
	}
}

  
int main()
{


	BST v; 
	node_BST* result; 
	node_Maxheap* result_1; 
	Maxheap k; 
	string Name; 
	int id; 
	int Priority; 
	int choice;

	cout << "enter (1) for insert request" << endl;
	cout << "enter (2) for search request" << endl;
	cout << "enter (3) for delete_type(1) request" << endl;
	cout << "enter (4) for delete_max_node request" << endl;
	cout << "enter (5) for Increase priority of request" << endl;
	cout << "enter (6) for  print list " << endl;
	cout << "enter (1) for exit" << endl;

	while (1)
	{
		cout << "enter number:  ";
		cin >> choice; 
		if (choice == 1)
		{
			
			cout << "request name: ";
			cin >> Name;
			cout << "ID: ";
			cin >> id;
			cout << "priority: ";
			cin >> Priority;
			if (v.search(id) != 1)
			{
				cout << "node is repetitive " << endl;
			}
			else
			{
				v.Tnsert_BST(Name, id);
				k.Insert_Heap(id, Priority);
			}
		}
		else if (choice == 2)
		{
			cout << " enter the request ID you want to search : ";
			cin >> id; 
			result = v.search_Request_BST(id);  
		}
		else if (choice == 3)
		{
			cout << " enter the request ID you want to delete : ";
			cin >> id; 
			v.delete_request_BST(id); 
			k.Delete_node(id);
		}
		else if (choice == 4)
		{
			result_1 = k.Delete_Maxheap();
			v.delete_request_BST(result_1->get_ID_Max());
		}
		else if (choice == 5)
		{
			cout << " enter the request ID you want to increase Priority : ";
			cin >> id;
			cout << " enter the new Priority : ";
			cin >> Priority;
			k.Increase_priority(id, Priority);
		}
		else if (choice == 6)
		{
			v.print_BST(v.root);
			cout << endl;
			k.Print_Maxheap(0);
		}
		else if (choice == 7)
		{
			cout << "*exit of the list*" << endl; 
			break;
		}
	}

	return 0;
}

