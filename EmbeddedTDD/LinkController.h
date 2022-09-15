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
     * Initialize the LinkControllerAPI.
     */
	void init(std::shared_ptr<IdManagerAPI> id_manager_sp, std::shared_ptr<LinkConfiguratorAPI>);

	/**
	 * Activate link
	 */
	bool activate(std::string link_name);

	/**
	 * Deactivate link
	 */
	bool deactivate(std::string link_name);
	
private:
	std::shared_ptr<IdManagerAPI> m_id_manager_sp;
	std::shared_ptr<LinkConfiguratorAPI> m_link_configurator_sp;

	std::list<std::string> m_activated_links;
};
}

#endif