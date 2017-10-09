/*
 * IniHelper.cpp
 *
 *  Created on: 2017年10月9日
 *      Author: momo
 */

#include "IniHelper.h"

#define MAX_BUF_SIZE		1024
#define BLANK_CHAR		' '

IniHelper::IniHelper(char* ini_file_name) {
	m_ini_map.clear();

		std::ifstream ini_stream(ini_file_name);
		if(!ini_stream){
			perror("failed to open file");
			exit(1);
		}

		char buf[MAX_BUF_SIZE];
		std::string line;

		while(ini_stream.getline(buf, MAX_BUF_SIZE)){
			line = buf;
			try{
				if('#' == line.at(0) ){
					continue;
				}

				int eq_index = line.find("=");
				if(eq_index <= 0){
					continue;
				}

				std::string left,right,trim_right;
				left = line.substr(0, eq_index);
				right = line.substr(eq_index+1, std::string::npos);
				for(std::string::iterator it = right.begin();it != right.end();it++ ){
					 if( *it != BLANK_CHAR){
						 trim_right += *it;
					 }
				}

				m_ini_map[left] = trim_right;
			}
			catch(...){
				std::cout << "exception occur ad " << __FILE__ << __LINE__ << std::endl;
			}
		}


}

IniHelper::~IniHelper() {
	// TODO Auto-generated destructor stub
}

void IniHelper::CheckMap()
{
	std::map<std::string,std::string>::iterator it = m_ini_map.begin();
	for(;it != m_ini_map.end(); it++){
		std::cout << it->first << "\t=>\t" << (*it).second << std::endl;
	}
}
