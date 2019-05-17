#include <map>
#include <vector>

using namespace::std;

template <class T>
struct Tree {
	vector<T*> children;
	int	value;
};