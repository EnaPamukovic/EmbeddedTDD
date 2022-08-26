#pragma once
#ifndef LINK_CONTROLLER_H
#define LINK_CONTROLLER_H

#include "LinkControllerAPI.h"

#include "IdManagerAPI.h"
#include "LinkConfiguratorAPI.h"

namespace impl {

class LinkController : public LinkControllerAPI, public std::enable_shared_from_this<LinkController> {
public:
	/**
     * LinkController default constructor
     */
	LinkController();

	/**
	 * LinkController constructor
	 */
	LinkController(std::shared_ptr<IdManagerAPI> id_manager, std::shared_ptr<LinkConfiguratorAPI> link_configurator);

	/**
     * LinkController destructor
     */
	~LinkController() = default;

	/**
	 * Activate link
	 */
	bool activate(std::string link_name);
};
}

#endif