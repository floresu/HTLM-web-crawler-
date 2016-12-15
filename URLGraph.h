#include <iostream>
#include <string>
#include <curl/curl.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;

class URLGraph
{
private:
	map<string, vector<string> > graph;
public:
	URLGraph();
	void BFS(int level, string s);
	void add(string v, vector<string> neighbors);
};
