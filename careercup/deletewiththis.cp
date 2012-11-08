#include <iostream>
using namespace std;
class test
{
public:
	test();
	~test();

	void d()
	{
		delete this;
		cout<<"deleted";
	}
};

test::test()
{

}
test::~test()
{
	cout<<"deleting";
}

int main(int argc, char const *argv[])
{
	test *t=new test();
	t->d();
	delete t;
	return 0;
}
