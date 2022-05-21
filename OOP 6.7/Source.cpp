#include <iostream>
#include <time.h>
using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator ()(T x) = 0;
};

template<class T>
class for_each : public Predicate<T>
{
public:
	virtual bool operator ()(T x)
	{
		T zero = T();
		if (x == zero)
			return true;
		else
			return false;
	}
};
template<class T>
void generate(T* begin, T* end, Predicate<T>& p)
{
	for (T* current = begin; current < end; current++)
	{
		if (p(*current))
		{
			T A = 1;
			T B = 50;
			*current = A + rand() % (B - A + 1);
		}
	}
}

template<class T>
void print(T* a, size_t t)
{
	for (int j = 0; j < t; j++)
	{
		cout << a[j] << "  ";
	}
	cout << endl;
}

int main()
{
	int a[5] = { 0 };
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
	srand((unsigned)time(NULL));
	Predicate<int>* Foreach = new for_each<int>();

	cout << "b: " << endl;
	generate(&b[0], &b[10], *Foreach);
	print(b, 10);

	cout << "a: " << endl;
	generate(&a[0], &a[5], *Foreach);
	print(a, 5);
	return 0;
}