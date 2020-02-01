#include <iostream>
using namespace std;

//using pointers
void Swap1 (int *x, int *y)
{
	int p = *x;
	*x = *y;
	*y = p;
	
	
}

//using references
void Swap2 (int &x, int &y)
{
	int p = x;
	x = y;
	y = p;
	
	
}

int main(int argc, char** argv) {
	/*char ch = 'A';
	int a = 15;
	int B[] = {1, 2, 3};
	int *ptr = &a; // this is a pointer to an int - it can hold the address of int
	
	cout << "Address of ch = " << (void *) &ch << endl;
	cout << "Address of a = " << &a << "address in *prt = " << ptr << endl;
	cout << "Value of a[Before] = " << a << endl;
	*ptr = 12;
	cout << "Value of a[After] = " << a << endl;
	cout << "Address of B = " << &B << endl;
	*/
	
	int a = 19;
	int b = 25;
	
	Swap2 (a, b);
	
	cout << "a = " << a << endl << "b = " << b;
	return 0;
}
