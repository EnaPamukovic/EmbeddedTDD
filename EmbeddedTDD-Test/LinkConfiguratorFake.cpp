#include "LinkConfiguratorFake.h"

namespace impl {
	bool LinkConfiguratorFake::activate(int link_id) {
		return true;
	}

	bool LinkConfiguratorFake::deactivate(int link_id) {
		return true;
	}
}

