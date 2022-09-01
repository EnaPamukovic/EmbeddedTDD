#pragma once
#ifndef LINK_CONTROLLER_API_H
#define LINK_CONTROLLER_API_H

#include <string>
#include <memory>

#include "IdManagerAPI.h"
#include "LinkConfiguratorAPI.h"

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
	 * Get IdManagerAPI instance
	 */
	virtual std::shared_ptr<IdManagerAPI> getIdManagerInstance() = 0;

	/**
     * Activate link
     */
	virtual bool activate(std::string link_name, std::shared_ptr<IdManagerAPI> id_manager_sp, std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp) = 0;
};

#endif