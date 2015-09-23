/*My_vec.h
Your name
Header file for a vector data structure.
*/

#include <ostream>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
template <class T>
class My_vec {
	
	//member variables
	int size, capacity;
	T *ptr;
	
public:	
	//member functions
	My_vec();
	~My_vec();
	My_vec(const My_vec<T>& vec);
	My_vec& operator=(const My_vec<T>& vec);
	int get_size() const;
	int get_capacity() const;
	T& operator[](int i) const;
	T& operator[](int i);
	bool is_empty() const;
	T& elem_at_rank(int r) const;
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r); 
	
};
	template<class T>
	ostream& operator<<(ostream& out, const My_vec<T>& vec);
	template<class T>
	int find_max_index(const My_vec<T>& v,int size);
	template<class T>
	void sort_max(My_vec<T>& vec);
	
/* 	#include "My_vec.h"
using namespace std;
 */
template<class T>
My_vec<T>::My_vec()
{
	size=0; 
	capacity=2; 
	ptr= new T[capacity];
};
template<class T>
My_vec<T>::~My_vec()	{delete [] ptr;};
template<class T>
My_vec<T>::My_vec(const My_vec<T>& vec)
{
	size=vec.size; 
	ptr=new T [size]; 
	capacity = vec.capacity;
	for (int i =0; i<size; i++)
	{
		ptr[i] = vec.ptr[i];
	}
};
template<class T>
My_vec<T>& My_vec<T>::operator=(const My_vec<T>& vec)
{
	if (this != &vec)
	{
		delete [] ptr;
		size=vec.size;
		capacity = vec.capacity;
		ptr= new T[capacity];
		for (int i =0; i<vec.size; i++)
		{
			ptr[i] = vec.ptr[i];
		}
	}
};
template<class T>
int My_vec<T>::get_size() 	const
{
	return size;
};
template<class T>
int My_vec<T>::get_capacity() 	const
{
	return capacity;
};
template<class T>
T& My_vec<T>::operator[](int i) const	{return ptr[i];};

template<class T>
T& My_vec<T>::operator[](int i)	{return ptr[i];};

template<class T>
bool My_vec<T>::is_empty() const	{ return size ==0;};

template<class T>
T& My_vec<T>::elem_at_rank(int r) const {return ptr[r];};

template<class T> 
void My_vec<T>::insert_at_rank(int r, const T& elem)
{
	size++;
	if (r>capacity) 
	{
		//throw invalid_argument("rank greater than size of vector");
		cout<<"Error: The rank chosen is not within capacity limits "<< elem<< " was not inserted \n";	
	}
	else{
		T* B = new T[(capacity)];
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
template<class T>
void My_vec<T>::replace_at_rank(int r, const T& elem)
{
	if (r>size) {cout<<"error, rank is greater than size of vector, "<<elem<<" was not inserted"<<endl;}
	else {ptr[r] = elem;}
};
template<class T>
void My_vec<T>::remove_at_rank(int r)
{
		if (r>size)	{cout<<"error, element was not removed because rank does not exist"<<endl;}
		else
		{
			T* B = new T[(capacity-1)];
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

template<class T>
ostream& operator<<(ostream& out, const My_vec<T>& vec)
{
		//T elements [vec.get_size()];
		for (int i=0; i<vec.get_size(); ++i)
		{
			out<<vec[i];
		}
		return out;
};
template<class T>
int find_max_index(const My_vec<T>& vec, int size)
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
template<class T>
void sort_max(My_vec<T>& vec)
{
	int i, j, first;
	T temp;
    int size = vec.get_size();
    for (i= size - 1; i > 0; i--)
     {
           first = 0;                 // initialize to subscript of first element
           for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
          {
			  T a = vec[j];
			  T b = vec[first];
                 if (a < b) {}
                 
          }
         temp = vec[first];   // Swap smallest found with element in position i.
         vec[first] = vec[i];
         vec[i] = temp;
     }
};