#include <iostream>

using namespace std;

void get_op(char &ch)
{
	do {
		cout << "Enter Op (/, *, +, -) : ";
		cin >> ch;
	} while (ch != '*' && ch != '/' && ch != '+' && ch != '-');
}

void get_number(int &n)
{
	cout << "Enter a Number : ";
	cin >> n;
}

void do_op(int a, int b, char op)
{
	switch (op) {
	case '/' :
		cout << a << op << b << " : " << a / b << endl;
		break;
	case '*' :
		cout << a << op << b << " : " << a * b << endl;
		break;
	case '-' :
		cout << a << op << b << " : " << a - b << endl;
		break;
	case '+' :
		cout << a << op << b << " : " << a + b << endl;
		break;
	}
}

int main()
{
	char op;
	int a, b;
	get_number(a);
	get_number(b);
	get_op(op);
	do_op(a, b, op); 
	return 0;
}
