#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void get_numbers(int db[], int len)
{
	int temp;
	for (int i = 0; i < len; i++) {
		cout << "Number " << i + 1 << " : ";
		cin >> temp;
		db[i] = temp;
	}
}

void sort_numbers(int numbers[], int len)
{
	int i, temp, j;
    for (i = 1; i < len; i++) {
        temp = numbers[i];
        j = i - 1;
        while (j >= 0 && numbers[j] > temp) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = temp;
    }
}

void print_numbers(int numbers[], int len)
{
	for (int i = 0; i < len; i++) {
		cout << numbers[i] << '\t';
	}
	cout << endl;
}	

int main()
{
	int a;
	cout << "How Many Number Do You Want ? ";
	cin >> a;
	int numbers[a];
	get_numbers(numbers, a);
	sort_numbers(numbers, a);
	print_numbers(numbers, a);
	return 0;
}
