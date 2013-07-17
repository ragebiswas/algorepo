/*
 * main.cc
 * 	The main launcher
 *
 *  Created on: Mar 27, 2011
 *      Author: biswasra
 */

#include <iostream>

extern void graph_test_run();

int main()
{
	std::cout<<"Launching...\n";

	graph_test_run();

	std::cout<<"\nProgram complete.";
}
