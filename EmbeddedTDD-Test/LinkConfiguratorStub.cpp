#include "LinkConfiguratorStub.h"

namespace impl {
	bool LinkConfiguratorStub::activate(int link_id) {
		if (link_id >= 1000) {
			return true;
		}
		return false;
	}

	bool LinkConfiguratorStub::deactivate(int link_id) {
		if (link_id >= 1000) {
			return true;
		}
		return false;
	}
}

