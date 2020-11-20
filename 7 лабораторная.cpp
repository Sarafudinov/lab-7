#include <iostream>

using namespace std;

template<typename Val, typename Key>
struct Data
{
	Key key;
	Val val;

	friend ostream& operator<<(ostream& out, const Data <Val, Key>& obj) {
		return out << obj.key << " " << obj.val;
	};
};


template<typename T1, typename T2>
class MultiMap
{
private:
	size_t size = 0;
	Data<T1, T2>* ceil = nullptr;
	
public:
	MultiMap() {};

	MultiMap(initializer_list<Data<T1,T2>> il) {
		size = il.size();

		ceil = new Data<T1, T2>[size];
		
		copy(il.begin(), il.end(), ceil);
	};



	~MultiMap() {
		delete[]ceil;
	};

	friend ostream& operator<<(ostream& out, const MultiMap <T1, T2>& obj) {
		return out << *(obj.begin());
	};
};


int main()
{
	MultiMap<string, int>a = { { "one", 1 }, {"two", 2} };
}
