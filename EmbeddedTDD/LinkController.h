#pragma once
#ifndef LINK_CONTROLLER_H
#define LINK_CONTROLLER_H

#include "LinkControllerAPI.h"

#include "IdManagerAPI.h"
#include "LinkConfiguratorAPI.h"

#include <list>

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
	//LinkController(std::shared_ptr<IdManagerAPI> id_manager, std::shared_ptr<LinkConfiguratorAPI> link_configurator);

	/**
     * LinkController destructor
     */
	~LinkController() = default;

	/**
	 * Get IdManagerAPI instance
	 */
	std::shared_ptr<IdManagerAPI> getIdManagerInstance() override;

	/**
	 * Activate link
	 */
	bool activate(std::string link_name, std::shared_ptr<IdManagerAPI> id_manager_sp, std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp);

	std::shared_ptr<IdManagerAPI> m_id_manager_sp;
	
private:
	std::list<std::string> m_activated_links;
};
}

#endif