#pragma once
#ifndef ID_MANAGER_API_H
#define ID_MANAGER_API_H

class IdManagerAPI {
public:
	/**
	 * Get link ID
	 */
	virtual int getLinkId(std::string link_name) = 0;

};
#endif