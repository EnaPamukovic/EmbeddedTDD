#pragma once
#ifndef LINK_CONTROLLER_API_H
#define LINK_CONTROLLER_API_H

#include <string>
#include <memory>

class LinkControllerAPI {
public:
	/**
	 * LinkControllerAPI constructor
	 */
	LinkControllerAPI() = default;
	
	/**
     * LinkControllerAPI destructor
     */
	virtual ~LinkControllerAPI() = default;

	/**
	 * Global point of access to LinkControllerAPI single instance
	 */
	static std::shared_ptr<LinkControllerAPI> getInstance();

	/**
	 * Delete LinkControllerAPI single instances
	 */
	static void freeInstance();

	/**
     * Activate link
     */
	virtual bool activate(std::string link_name) = 0;
};

#endif