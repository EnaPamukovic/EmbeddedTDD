#pragma once
#ifndef LINK_CONFIGURATOR_STUB_H
#define LINK_CONFIGURATOR_STUB_H

#include <gtest/gtest.h>

#include "../EmbeddedTDD/LinkConfiguratorAPI.h"

namespace impl {

	class LinkConfiguratorStub : public LinkConfiguratorAPI, public std::enable_shared_from_this<LinkConfiguratorStub> {
	public:
		/**
		 * Activate link
		 */
		bool activate(int link_id);

		/**
		 * Deactivate link
		 */
		bool deactivate(int link_id);
	};
}
#endif