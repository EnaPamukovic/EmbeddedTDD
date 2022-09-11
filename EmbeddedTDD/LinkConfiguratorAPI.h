#pragma once
#ifndef LINK_CONFIGURATOR_API_H
#define LINK_CONFIGURATOR_API_H

class LinkConfiguratorAPI {
public:
	/**
	 * Activate link
	 */
	virtual bool activate(int link_id) = 0;

	/**
	 * Deactivate link
	 */
	virtual bool deactivate(int link_id) = 0;
};
#endif