#include "Header.h"
int main (void){
	BST < int > bin;
	int i=0, x=4;

	while (x != 0)
	{
		cout << "Would you like to insert (1)" << '\n';
		cout << "delete (2)" << '\n';
		cout << "print (3)" << '\n';
		cout << "or exit the program (0): ";
		cin >> x;

		if (x==1||x==2) {
			cout << '\n' << "Please select a number: ";
			cin >> i;
			cout << '\n';
		}

		if (x==1)
			bin.insert(i, bin.getRoot());
		if (x==2)
			bin.remove(i, bin.getRoot());
		if (x==3){
			bin.print(bin.getRoot());
			cout << '\n';	
		}
	}
	return 0;
}