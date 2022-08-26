#pragma once
#ifndef ID_MANAGER_API_H
#define ID_MANAGER_API_H

#include <string>
#include<sstream>

class IdManagerAPI {
public:
	/**
     * IdManagerAPI destructor
     */
	virtual ~IdManagerAPI() {}

	/**
	 * Get link ID
	 */
	virtual int getLinkId(std::string link_name) = 0;

	//TODO:dodat neku listu koja sprema parove name,id
};
#endif