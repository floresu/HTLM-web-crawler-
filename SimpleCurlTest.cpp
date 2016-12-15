/**
All code here adapted (modified as little as possible) from 
www.luckyspin.org
Adaptation by Gary Lewandowski, 14 October 2007.
Adaptation by Uriel Flores, 05 November 2015

Original header comments follow.
**/

/*
 * This is a very simple example of how to use libcurl from within 
 * a C++  program. The basic idea is that you want to retrieve the 
 * contents of a web page as a string. Obviously, you can replace 
 * the buffer object with anything you want and adjust elsewhere 
 * accordingly.
 * 
 * Hope you find it useful..
 * 
 * Todd Papaioannou 
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "SimpleCurl.h"
#include "URLGraph.h"

using namespace std;
/*
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
  */

int main(int argc, char *argv[])
{
	/** one way to use SimpleCurl: via a constuctor. Give a string and it
	  tries to retrieve the document.
	  **/
	URLGraph graph;
  SimpleCurl httpGrabber(argv[1]);
	//s httpGrabber(argv[1]);
  string doc = httpGrabber.getRetrievedDocument();
	//cout << doc << endl;

	/*
  vector<string> whataretheurls = find_urls(doc);
	{
		for(int i; i < whataretheurls.size(); i++)
			cout << whataretheurls[i] << endl;
	}
  */

    /*
    Here is a second way -- the more likely way you'll use it.
        After creating an httpGrabber, invoke the getURL method.
        It returns -1 on failure.
        */

   if(httpGrabber.getURL("http://www.xavier.edu") !=-1)
        	{
          //cout << httpGrabber.getRetrievedDocument() << endl;
          graph.BFS(2, "http://www.xavier.edu");
          } 
	else
		cout << "Could not retrieve document" << endl;
}
    
