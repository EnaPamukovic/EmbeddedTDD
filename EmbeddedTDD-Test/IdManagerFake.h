#pragma once
#ifndef ID_MANAGER_FAKE_H
#define ID_MANAGER_FAKE_H

#include <gtest/gtest.h>

#include "../EmbeddedTDD/IdManagerAPI.h"

#include <map>

namespace impl {

	class IdManagerFake : public IdManagerAPI, public std::enable_shared_from_this<IdManagerFake> {
	public:
		/**
	     * IdManagerFake destructor
	     */
		~IdManagerFake() = default;

		/**
		 * Get link ID
		 */
		int getLinkId(std::string link_name);

	private:
		std::map<std::string, int> m_link_data = 
		{ {"link_a", 100}, {"link_b", 101}, {"link_c", 103}, {"link_1", 1000}, {"link_2", 1001} };
	};
}
#endif