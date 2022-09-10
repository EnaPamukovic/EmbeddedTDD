#pragma once
#pragma once
#ifndef ID_MANAGER_STUB_H
#define ID_MANAGER_STUB_H

#include <gtest/gtest.h>

#include "../EmbeddedTDD/IdManagerAPI.h"

#include <map>

namespace impl {

	class IdManagerStub : public IdManagerAPI, public std::enable_shared_from_this<IdManagerStub> {
	public:
		/**
		 * Get link ID
		 */
		int getLinkId(std::string link_name);
	};
}
#endif