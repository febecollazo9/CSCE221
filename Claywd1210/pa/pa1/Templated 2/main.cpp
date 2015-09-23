
// main.cpp
//Tests all functionality of the My_vec class.
#include "My_vec.h"

int main(){
try{
	
cout<<"----------------------Double Test------------------"<<endl;
	My_vec<double> v;	// define an object v of My_vec type
    v.insert_at_rank(0, .01); // insert 'B' at the rank 0 into the vector v
	cout<<v<<endl;// use the overloaded operator << to display vector elements
    cout<<v.get_size()<<endl;// display the vector v size */

	v.insert_at_rank(0, .02);// insert 'A' at the rank 0 into the vector v
	cout<<v<<endl;// use the overloaded operator << to display vector elements
    cout<<v.get_size()<<endl;// display the vector v size

	v.insert_at_rank(10, .03);// insert 'D' at the rank 10 into the vector v
	cout<<v<<endl;// use the overloaded operator << to display vector elements
    cout<<v.get_size()<<endl;// display the vector v size

	v.remove_at_rank(2);// remove a character at the rank 2 from the vector v
	cout<<v<<endl;// use the overloaded operator << to display vector elements
	cout<<v.get_size()<<endl;// display the vector v size 

	v.replace_at_rank(2, .05);// replace a character at the rank 2 by the character 'E' 
	cout<<v<<endl;// use the overloaded operator << to display vector elements
	cout<<v.get_size()<<endl;// display the vector v size 
	
	My_vec<double> v1 = v;// create a copy v1 of the vector v using a copy constructor
	cout<<v1<<endl;// use the overloaded operator << to display the vector v1
    v1.replace_at_rank(2, .06);// replace a character at the rank 2 of the vector v1 with the character 'Y'
	cout<<v1<<endl;// use the overloaded operator << to display vector v1 elements

	My_vec<double> v2;	// define an object v2 of My_vec type
	v2.insert_at_rank(0,.07);// insert 'K' at the rank 0 into the vector v2
	cout<<v2<<endl;// use the overloaded operator << to display vector elements
	cout<<v2.get_size()<<endl;// display the vector v size 

    v2 = v1;// test the assignment operator and copy the vector v1 to v2 
    cout<<v2<<endl;// use the overloaded operator << to display vector elements
	cout<<v2.get_size()<<endl;// display the vector v2 size 
	
    int rank = find_max_index(v2, v2.get_size()); // test the function find_max_index using v2
	sort_max(v2); cout<<v2<<endl;// test the function sort_max using v2

	// replace in the vector v2 a character at the rank 14 with 'S' */

cout<<"----------------------Char Test------------------"<<endl;
	My_vec<char> v3;	// define an object v of My_vec type
    v3.insert_at_rank(0, 'B'); // insert 'B' at the rank 0 into the vector v
	cout<<v3<<endl;// use the overloaded operator << to display vector elements
    cout<<v3.get_size()<<endl;// display the vector v size */

	v3.insert_at_rank(0, 'A');// insert 'A' at the rank 0 into the vector v
	cout<<v3<<endl;// use the overloaded operator << to display vector elements
    cout<<v3.get_size()<<endl;// display the vector v size

	v3.insert_at_rank(10, 'D');// insert 'D' at the rank 10 into the vector v
	cout<<v3<<endl;// use the overloaded operator << to display vector elements
    cout<<v3.get_size()<<endl;// display the vector v size

	v3.remove_at_rank(2);// remove a character at the rank 2 from the vector v
	cout<<v3<<endl;// use the overloaded operator << to display vector elements
	cout<<v3.get_size()<<endl;// display the vector v size 

	v3.replace_at_rank(2, 'E');// replace a character at the rank 2 by the character 'E' 
	cout<<v3<<endl;// use the overloaded operator << to display vector elements
	cout<<v3.get_size()<<endl;// display the vector v size 
	
	My_vec<char> v4 = v3;// create a copy v1 of the vector v using a copy constructor
	cout<<v4<<endl;// use the overloaded operator << to display the vector v1
    v4.replace_at_rank(2, 'Y');// replace a character at the rank 2 of the vector v1 with the character 'Y'
	cout<<v4<<endl;// use the overloaded operator << to display vector v1 elements

	My_vec<char> v5;	// define an object v2 of My_vec type
	v5.insert_at_rank(0,'K');// insert 'K' at the rank 0 into the vector v2
	cout<<v5<<endl;// use the overloaded operator << to display vector elements
	cout<<v5.get_size()<<endl;// display the vector v size 

    v5 = v4;// test the assignment operator and copy the vector v1 to v2 
    cout<<v5<<endl;// use the overloaded operator << to display vector elements
	cout<<v5.get_size()<<endl;// display the vector v2 size 
	
    int rank1 = find_max_index(v5, v5.get_size()); // test the function find_max_index using v2
	sort_max(v5); cout<<v5<<endl;// test the function sort_max using v2

	// replace in the vector v2 a character at the rank 14 with 'S' */

cout<<"----------------------Int Test------------------"<<endl;
	My_vec<int> v6;	// define an object v of My_vec type
    v6.insert_at_rank(0, 2); // insert 'B' at the rank 0 into the vector v
	cout<<v6<<endl;// use the overloaded operator << to display vector elements
    cout<<v6.get_size()<<endl;// display the vector v size */

	v6.insert_at_rank(0, 1);// insert 'A' at the rank 0 into the vector v
	cout<<v6<<endl;// use the overloaded operator << to display vector elements
    cout<<v6.get_size()<<endl;// display the vector v size

	v6.insert_at_rank(10, 3);// insert 'D' at the rank 10 into the vector v
	cout<<v6<<endl;// use the overloaded operator << to display vector elements
    cout<<v6.get_size()<<endl;// display the vector v size

	v6.remove_at_rank(2);// remove a character at the rank 2 from the vector v
	cout<<v6<<endl;// use the overloaded operator << to display vector elements
	cout<<v6.get_size()<<endl;// display the vector v size 

	v6.replace_at_rank(2, 4);// replace a character at the rank 2 by the character 'E' 
	cout<<v6<<endl;// use the overloaded operator << to display vector elements
	cout<<v6.get_size()<<endl;// display the vector v size 
	
	My_vec<int> v7 = v6;// create a copy v1 of the vector v using a copy constructor
	cout<<v7<<endl;// use the overloaded operator << to display the vector v1
    v7.replace_at_rank(2, 5);// replace a character at the rank 2 of the vector v1 with the character 'Y'
	cout<<v7<<endl;// use the overloaded operator << to display vector v1 elements

	My_vec<int> v8;	// define an object v2 of My_vec type
	v8.insert_at_rank(0,6);// insert 'K' at the rank 0 into the vector v2
	cout<<v8<<endl;// use the overloaded operator << to display vector elements
	cout<<v8.get_size()<<endl;// display the vector v size 

    v8 = v7;// test the assignment operator and copy the vector v1 to v2 
    cout<<v8<<endl;// use the overloaded operator << to display vector elements
	cout<<v8.get_size()<<endl;// display the vector v2 size 
	
    int rank2 = find_max_index(v8, v8.get_size()); // test the function find_max_index using v2
	sort_max(v8); cout<<v8<<endl;// test the function sort_max using v2

	// replace in the vector v2 a character at the rank 14 with 'S' */

}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}
