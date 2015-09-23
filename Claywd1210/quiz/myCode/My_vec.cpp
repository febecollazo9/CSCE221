/*My_vec.h
Clayton Dittman
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

char& My_vec::operator[](int i) const		
{
	if(i<size && i>=0) return ptr[i];
	else cout<< "error, rank is outside range of vector \n";
};


char& My_vec::operator[](int i)	
{
	if(i<size && i>=0) return ptr[i];
	else cout<< "error, rank is outside range of vector \n";
};


bool My_vec::is_empty() const	{ return size ==0;};


char& My_vec::elem_at_rank(int r) const 
{
	if(r<size && r>=0) return ptr[r];
	else cout<< "error, rank is outside range of vector \n";
};


 
void My_vec::insert_at_rank(int r, const char& elem)
{
	
	if (r>capacity || r<0) 
	{
		//throw invalid_argument("rank greater than size of vector");
		cout<<"Error: The rank chosen is not within capacity limits "<< elem<< " was not inserted \n";	
	}
	else{
		if (r>size)
		{
		//throw invalid_argument("rank greater than size of vector");
		cout<<"Error: The rank chosen is not within size of vector limits "<< elem<< " was not inserted \n";	
		}
		else{
			size++;
			if (size == capacity) 
			{
				capacity = capacity*2;
				char* B = new char[(capacity)];
				capacity = capacity*2;
				B[r] = elem;
				int j=0;
				//size++;
				for (int i =0; i<size; i++) 
				{
					if (i != r) 
					{
						B[i] = ptr[j];
						j++;
					}
				}
			if (ptr != NULL) delete [] ptr;
			ptr = B;
			}
			else 
			{
				capacity = capacity+1;
				char* B = new char[(capacity)];
				B[r] = elem;
				int j=0;
				//size++;
				for (int i =0; i<size; i++) 
				{
					if (i != r) 
					{
						B[i] = ptr[j];
						j++;
					}
				}
				if (ptr != NULL) delete [] ptr;
				ptr = B;	
			}
		}
	}
		
};

void My_vec::replace_at_rank(int r, const char& elem)
{
	if (r>=0 && r<size) {ptr[r] = elem;}
	else {cout<<"error, rank is outside range of vector, "<<elem<<" was not inserted"<<endl;}
};

void My_vec::remove_at_rank(int r)
{
		if (r>=0 && r<size)
		{
			for (int i=r; i<size; ++i)
			{
				ptr[i]=ptr[i+1]; 
			}
			size = size-1;
		}
		else	{cout<<"error, rank is outside range of vector"<<endl;}
		
}


ostream& operator<<(ostream& out, const My_vec& vec)
{	
		out.flush();
		//char elements [vec.get_size()];
		for (int i=0; i<vec.get_size(); i++)
		{
			out<<vec[i];
		}
		return out;
};

int find_max_index(const My_vec& vec, int n)
{
	if (vec.is_empty() || n<0 ){  cout<< "error, rank is outside range of vector"<<endl; return NULL;}
	else
	{
		int count;
		if (vec.get_size() > (n-1)) count = (n-1);
		else count = vec.get_size()-1;
		int rank=0;
		for (int i=0; i<count; ++i)
		{
			if (vec.elem_at_rank(i+1) < vec.elem_at_rank(rank)) {rank =rank;}
			else {rank = i+1;}	
			
		}
		return (rank);
	}
};

void sort_max(My_vec& vec)
{
	if (vec.is_empty()){  cout<< "error, vector is empty"<<endl;}
	else
	{
		My_vec temp =vec;
		
		for(int i = vec.get_size(); i>0; i--)
		{
				int rank = find_max_index(vec, i);
				char tempt = vec[rank];
				temp.replace_at_rank(i-1,tempt);
				vec.remove_at_rank(rank);

		}
		vec =temp;
	}
};