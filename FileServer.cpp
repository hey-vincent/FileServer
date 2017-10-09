//============================================================================
// Name        : FileServer.cpp
// Author      : wensheng
// Version     :
// Copyright   : This project was created by @wensheng@ since 2017年10月09日12:23:53
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "./Server.h"
#include "IniHelper.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	IniHelper *ini = new IniHelper("./config.ini");
	ini->CheckMap();


	Server svr = Server();
//	cout << svr.Run();
	return 0;
}
