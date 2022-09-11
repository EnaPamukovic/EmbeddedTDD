#include "IdManagerFake.h"

namespace impl {
	int IdManagerFake::getLinkId(std::string link_name) {
		if (m_link_data.find(link_name) != m_link_data.end()) {
			return m_link_data[link_name];
		}
		return 0;
	}
}

