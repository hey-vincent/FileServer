/*
 * IniHelper.h
 *
 *  Created on: 2017年10月9日
 *      Author: momo
 */

#ifndef INIHELPER_H_
#define INIHELPER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class IniHelper {
public:
	IniHelper(char* ini_file_name);
	virtual ~IniHelper();
	void CheckMap();

protected:
	std::map<std::string,std::string> m_ini_map;
};

#endif /* INIHELPER_H_ */
