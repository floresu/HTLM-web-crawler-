#include <string> 
#include <iostream>
#include <curl/curl.h>
#include <vector>
#include "URLGraph.h"
#include <queue>
#include "SimpleCurl.h"

using namespace std;

bool not_url_char(char c)
  {
    // characters, in addition to alphanumerics, that can appear in a URL
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // see whether c can appear in a URL and return the negative
    return !(isalnum(c) || 
      find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
  }

  string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
  {
    return find_if(b, e, not_url_char);
  }

  string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
  {
    static const string sep = "://";

    typedef string::const_iterator iter;

    // i marks where the separator was found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e)
    {
      // make sure the separator isn't at the beginning or end of the line
      if (i != b && i + sep.size() != e)
      {
        // beg marks the beginning of the protocol-name
        iter beg = i;
        while (beg != b && isalpha(beg[-1]))
          --beg;

        // is there at least one appropiate character before and after the 
        if (beg != i && !not_url_char(i[sep.size()]))
          return beg;
      }

      // the separator we found wasn't part of a URL advance i past this separater 
      i +=sep.size();
  }
      return e;
  }

  vector<string> find_urls(const string& s)
  {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // look through the entire input
    while (b != e) {
      
      //look for one or more letters followed by ://
      b = url_beg(b, e);

      //if we found it
      if (b != e) {
        // get the reset of the URL
        iter after = url_end(b, e);

        // remember the URL
        ret.push_back(string(b, after));

        // advance b and check for more URLs on this line
        b = after;
      }
    }
    return ret;
	}

URLGraph::URLGraph()
{
	
}

void URLGraph::add(string v, vector<string> neighbors)
{
	graph[v] = neighbors;
}

void URLGraph::BFS(int level, string s, string target)
{
	// Object httpGrabber from SimpleCurl
	// Maps are included for distance, color, and parent
	SimpleCurl httpGrabber;
	map<string, int > distance;
	map<string, string> color;
	map<string, string> parent;
		distance[s] = 0;
		color[s] = "gray";
		parent[s] = "";

	bool check = false;
	queue<string> Q;
	Q.push(s);
	//queue Q = new queue();
	//string u;
	
	while(!Q.empty()) // Checks if Q is not empy
	{
		string works = Q.front(); Q.pop(); // Works is a variable that is eaither pushed
										  // or is popped out.
		cout << works << endl;
		if(httpGrabber.getURL(works) != -1) // Gets the object URL
		{
			cout << works << endl;
				continue;		
		}

		//string doc = 
		vector<string> gettheurlss = find_urls(httpGrabber.getRetrievedDocument());
		add(works, gettheurlss);
		for(int i; i < gettheurlss.size(); i++)
		{
			if(graph.find(gettheurlss[i]) == graph.end())
			{
				Q.push(gettheurlss[i]);
				cout << "We are getting something" << gettheurlss[i] << endl;
			}
			if(gettheurlss[i] == "target")
			{
				check = true;
			}
			if(check) break;
		}
		
	}	
}
