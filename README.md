Author: Uriel Flores
Date: 05 November 2015
======================

The purpose of this project is to target a word that develops a path of links that starts with a first page and ends with a second page with the targeted word.

URL code from the AcceleratedCppChapter6-1-2 file was implemented into the SimpleCurlTest.cpp D-level file. The URL code was organized in special order because it has variables that precedent functions require to run. The URL functions were sorted as follows: bool, string::const_iterator url_end, string::const_iterator url_beg, and a vector<string>. In additon, a vector and a for loop were added in the main function in order to extract the source code and URL's from the source code. The URL's from the web's page source code were extracted and printed after testing on terminal. The 

A new class called URLGraph was created along with a header file. The URL code was commented-out in the SimpleCurlTest.cpp file. The same URL code was implemented in the new URLGraph rather than calling it from SimpleCurlTest.cpp file. Maps were implemented to contain distance, color, and parent. Breadth First Search was somewhat translated from the pseudocode. Includes consisted of vector, queue, URLGraph.h, and SimpleCurl.h files. 

I had various errors that came across as I worked through the project. Sometimes I spent an hour trying to figure out a single error and turned out to be a simple syntax error or sometimes header file errors.
