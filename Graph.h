#include <map>
#include <vector>

using namespace::std;

template <class T>
class Graph {
	public:
		map<T, vector<pair<T, int>>> adj; 
};