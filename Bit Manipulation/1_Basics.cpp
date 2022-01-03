#include <iostream>
using namespace std;

int main() {
	//Bit wise
	int x = 8;
	cout<<(x & 1); //if last bit is 1 then op is 1 else 0 -> if even then 0; if odd then 1
	cout<<endl;
	cout<<(x <<= 1)<<"\n"; //left shift by 1 i.e if 4 - 100 then left shift 1 i.e 1000 = 8 (*2)
	cout<<(x >>= 1)<<"\n"; //right shift >> is divide by 2 i.e if 100 - 4 then 10 - 2
	return 0;
}

// Output
// 0
// 16
// 8