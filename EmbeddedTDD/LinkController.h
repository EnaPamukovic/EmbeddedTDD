#pragma once
#ifndef LINK_CONTROLLER_H
#define LINK_CONTROLLER_H

#include "LinkControllerAPI.h"

#include <list>

namespace impl {

class LinkController : public LinkControllerAPI, public std::enable_shared_from_this<LinkController> {
public:
	/**
     * LinkController default constructor
     */
	LinkController();

	/**
     * LinkController destructor
     */
	~LinkController() = default;

	/**
	 * Activate link
	 */
	bool activate(std::string link_name, std::shared_ptr<IdManagerAPI> id_manager_sp, std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp);

	/**
	 * Deactivate link
	 */
	bool deactivate(std::string link_name, std::shared_ptr<IdManagerAPI> id_manager_sp, std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp);
	
private:
	std::list<std::string> m_activated_links;
};
}

#endif