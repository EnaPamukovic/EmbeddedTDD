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
	virtual ~IdManagerAPI() = default;

	/**
	 * IdManagerAPI constructor
	 */
	IdManagerAPI() = default;

	/**
     * IdManagerAPI copy constructor
     */
	IdManagerAPI(IdManagerAPI const &) = delete;

	/**
	 * IdManagerAPI move constructor
	 */
	IdManagerAPI(IdManagerAPI &&) = delete;

	/**
	 * IdManagerAPI copy assingment operator
	 */
	IdManagerAPI &operator=(IdManagerAPI const&) = delete;

	/**
     * IdManagerAPI move assingment operator
     */
	IdManagerAPI &operator=(IdManagerAPI &&) = delete;

	/**
	 * Get link ID
	 */
	virtual int getLinkId(std::string link_name) = 0;
};
#endif