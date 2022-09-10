#include "IdManagerStub.h"

namespace impl {
	int IdManagerStub::getLinkId(std::string link_name) {
		if (link_name.substr(0, link_name.size() - 1) == "link_") {
			if (isdigit(link_name.back())) {
				return 1000;
			}
			return 100;
		}
		return 0;
	}
}

