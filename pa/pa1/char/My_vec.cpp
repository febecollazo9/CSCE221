/*My_vec.h
Your name
Header file for a vector data structure.
*/

/* 	#include "My_vec.h"
using namespace std;
 */
#include "My_vec.h"
using namespace std;
My_vec::My_vec()
{
	size=0; 
	capacity=2; 
	ptr= new char[capacity];
};

My_vec::~My_vec()	{delete [] ptr;};

My_vec::My_vec(const My_vec& vec)
{
	size=vec.size; 
	ptr=new char [size]; 
	capacity = vec.capacity;
	for (int i =0; i<size; i++)
	{
		ptr[i] = vec.ptr[i];
	}
};

My_vec& My_vec::operator=(const My_vec& vec)
{
	if (this != &vec)
	{
		delete [] ptr;
		size=vec.size;
		capacity = vec.capacity;
		ptr= new char[capacity];
		for (int i =0; i<vec.size; i++)
		{
			ptr[i] = vec.ptr[i];
		}
	}
};

int My_vec::get_size() 	const
{
	return size;
};

int My_vec::get_capacity() 	const
{
	return capacity;
};

char& My_vec::operator[](int i) const	{return ptr[i];};


char& My_vec::operator[](int i)	{return ptr[i];};


bool My_vec::is_empty() const	{ return size ==0;};


char& My_vec::elem_at_rank(int r) const {return ptr[r];};

 
void My_vec::insert_at_rank(int r, const char& elem)
{
	size++;
	if (r>capacity) 
	{
		//throw invalid_argument("rank greater than size of vector");
		cout<<"Error: The rank chosen is not within capacity limits "<< elem<< " was not inserted \n";	
	}
	else{
		char* B = new char[(capacity)];
		B[r] = elem;
		int j=0;
		
		for (int i =0; i<size; ++i) 
		{
			if (i != r) 
			{
				B[i] = ptr[j];
				j++;
			}
		}
		if (ptr != NULL) delete [] ptr;
		ptr = B;
		capacity = (capacity * 2);
	
	}
};

void My_vec::replace_at_rank(int r, const char& elem)
{
	if (r>size) {cout<<"error, rank is greater than size of vector, "<<elem<<" was not inserted"<<endl;}
	else {ptr[r] = elem;}
};

void My_vec::remove_at_rank(int r)
{
		if (r>size)	{cout<<"error, element was not removed because rank does not exist"<<endl;}
		else
		{
			char* B = new char[(capacity-1)];
			for (int i =0; i<size; ++i) 
			{
				if (i != r) {B[i] = ptr[i];};
			};
			if (ptr != NULL) delete [] ptr;
			ptr = B;
			capacity = (capacity -1);
			size--;
		}
}


ostream& operator<<(ostream& out, const My_vec& vec)
{
		//char elements [vec.get_size()];
		for (int i=0; i<vec.get_size(); ++i)
		{
			out<<vec[i];
		}
		return out;
};

int find_max_index(const My_vec& vec, int size)
{
	int rank=0;
	for (int i=0; i<(size); ++i)
	{
		if (size = i+1) rank = i; 
		else 
		{
			if (vec.elem_at_rank(i) > vec.elem_at_rank(i-1)) {rank = i;}
			else {rank = i-1;}
		}
		
		
	}
	return rank;
};

void sort_max(My_vec& vec)
{
	int i, j, first;
	char temp;
    int size = vec.get_size();
    for (i= size - 1; i > 0; i--)
     {
           first = 0;                 // initialize to subscript of first element
           for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
          {
			  char a = vec[j];
			  char b = vec[first];
                 if (a < b) {}
                 
          }
         temp = vec[first];   // Swap smallest found with element in position i.
         vec[first] = vec[i];
         vec[i] = temp;
     }
};