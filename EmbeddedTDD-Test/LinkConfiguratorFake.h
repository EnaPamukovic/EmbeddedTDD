#pragma once
#ifndef LINK_CONFIGURATOR_FAKE_H
#define LINK_CONFIGURATOR_FAKE_H

#include "../EmbeddedTDD/LinkConfiguratorAPI.h"

namespace impl {

	class LinkConfiguratorFake : public LinkConfiguratorAPI, public std::enable_shared_from_this<LinkConfiguratorFake> {
	public:
		/**
		 * LinkConfiguratorFake destructor
		 */
		~LinkConfiguratorFake() = default;

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