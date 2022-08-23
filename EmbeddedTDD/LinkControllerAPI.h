#pragma once
#ifndef LINK_CONTROLLER_API_H
#define LINK_CONTROLLER_API_H

#include <string>
#include <memory>

class LinkControllerAPI {
public:
	/**
	 * LinkControllerAPI destructor
	 */
	virtual ~LinkControllerAPI() = default;

	/**
	 * LinkControllerAPI constructor
	 */
	LinkControllerAPI() = default;

	/**
	 * LinkControllerAPI copy constructor
	 */
	LinkControllerAPI(LinkControllerAPI const&) = delete;

	/**
	 * LinkControllerAPI move constructor
	 */
	LinkControllerAPI(LinkControllerAPI&&) = delete;

	/**
	 * LinkControllerAPI copy assingment operator
	 */
	LinkControllerAPI& operator=(LinkControllerAPI const&) = delete;

	/**
	 * LinkControllerAPI move assingment operator
	 */
	LinkControllerAPI& operator=(LinkControllerAPI&&) = delete;

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