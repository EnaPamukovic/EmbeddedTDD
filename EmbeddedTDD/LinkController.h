#pragma once
#ifndef LINK_CONTROLLER_H
#define LINK_CONTROLLER_H

#include "LinkControllerAPI.h"

namespace impl {

class LinkController : public LinkControllerAPI, public std::enable_shared_from_this<LinkController> {
public:
	/**
	 * LinkController constructor
	 */
	LinkController();

	/**
	 * LinkController copy constructor
	 */
	LinkController(LinkController const&) = delete;

	/**
	 * LinkController move constructor
	 */
	LinkController(LinkController&&) = delete;

	/**
     * LinkController destructor
     */
	~LinkController() = default;

	/**
	 * LinkController copy assingment operator
	 */
	LinkController& operator=(LinkController const&) = delete;

	/**
	 * LinkController move assingment operator
	 */
	LinkController& operator=(LinkController&&) = delete;

	/**
	 * Activate link
	 */
	bool activate(std::string link_name);
};
}

#endif