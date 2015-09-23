#include "My_vec.h"
#include <iostream>
#include <cstring>


My_vec::~My_vec(){
	delete ptr;
}
My_vec::My_vec(const My_vec& vec){
	this->size = vec.size;
	this->capacity = vec.capacity;
	ptr = new char[capacity];
	std::memcpy(ptr, vec.ptr, vec.size);
}
My_vec& My_vec:: operator=(const My_vec& vec){
	if(this!=&vec){
		delete ptr;
	}
	this->size = vec.size;
	this->capacity = vec.capacity;
	ptr = new char[capacity];
	memcpy(ptr, vec.ptr, vec.size);
}

int My_vec::get_size() const{
	return size;
}
int My_vec::get_capacity() const{
	return capacity;
}
char& My_vec::operator[](int i) const{
	if(i<size&&i>=0){
		return ptr[i];
	}
	else{	
		cout<< "Error. Out of bounds.";
	}
}
char& My_vec::operator[](int i){
	if(i<size&&i>=0){
		return ptr[i];
	}
	else{	
		cout<< "Error. Out of bounds.";
	}
}
bool My_vec::is_empty() const{		
	if(size == 0){
		return true;
	}
	else{
		return false;
	}
}
char& My_vec::elem_at_rank(int r) const{
	if(r<size&&r>=0){
		return ptr[r];
	}
	else{	
		cout<< "Error. Out of bounds.";
	}
}
void My_vec::insert_at_rank(int r, const char& elem){
	char* temp = new char[capacity+1];
	int numtemp = r;
	if(r>=0){
		if(size==capacity){
		capacity = capacity*2;
			char* temp = new char[capacity];
			memcpy(temp, ptr, size);
			delete ptr;
			ptr = temp;
		}
		for(int i = 0; i<r; i++){
			temp[i] = ptr[i];
			
		}
		temp[r] = elem;
		for(int n = r+1; n<= size; n++){
			temp[n] = ptr[numtemp];
			numtemp++;
			
		}
		size++;
		for(int q = 0; q<= size; q++){
			ptr[q] = temp[q];
			
		}
		
	}
	else if(r==0 && size==0){
		size++;
		ptr[r] = elem;

	}
	else{	
		cout<< "Error. Out of bounds.";
	}

}
void My_vec::replace_at_rank(int r, const char& elem){
	if(r<size&&r>=0){
		ptr[r] = elem;
	}
	else{	
		cout<< "Error. Out of bounds.";
	}
}
void My_vec::remove_at_rank(int r){
	char* temp = new char[size-1];
	int numtemp = r;
	if(r<=size&&r>=0){
		for(int i = 0; i<r; i++){
			temp[i] = ptr[i];
		}
		for(int n = r+1; n<= size; n++){
			temp[numtemp] = ptr[n];
			numtemp++;
		}
		for(int q = 0; q<= size; q++){
			
			ptr[q] = temp[q];
			
		}
		size--;
	}
	else{	
		cout<< "Error. Out of bounds.";
	}
}

int find_max_index(const My_vec& v,int size){
	char top;
	int max;
	top = v[0];
	for(int i=0; i<size; i++){
		if(v[i]>top){
			top = v[i];
			max = i;
		}
	}
	return max;
}

void sort_max(My_vec& vec){
	My_vec temp(vec);
	int cur = 0;
	for(int i=vec.get_size()-1; i>0; i--){
		temp[cur] = vec[find_max_index(vec, vec.get_size())];
		vec.remove_at_rank(find_max_index(vec, vec.get_size()));
		cur++;
	}
	vec = temp;
}
ostream& operator<<(ostream& out, const My_vec& vec){

	for(int i=0; i<vec.get_size(); i++){
		out<< vec[i];

	}
	return out;
	
}