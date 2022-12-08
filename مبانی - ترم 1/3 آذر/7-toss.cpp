#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int toss()
{
    return (rand() % 6 + 1);
}

int main()
{
	srand((unsigned) time(0));
	cout << toss() << '\t' << toss() << endl;
	return 0;
}