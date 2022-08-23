#pragma once
#ifndef LINK_CONFIGURATOR_API_H
#define LINK_CONFIGURATOR_API_H

#include <string>
#include <memory>

class LinkConfiguratorAPI {
public:
	/**
	 * LinkConfiguratorAPI destructor
	 */
	virtual ~LinkConfiguratorAPI() = default;

	/**
	 * LinkConfiguratorrAPI constructor
	 */
	LinkConfiguratorAPI() = default;

	/**
	 * Activate link
	 */
	virtual bool activate(int link_id) = 0;

	/**
	 * Deactivate link
	 */
	virtual bool deactivate(int link_id) = 0;

	/**
     * Return true if link is activated
     */
	virtual bool isActivated(int link_id) = 0;
};
#endif