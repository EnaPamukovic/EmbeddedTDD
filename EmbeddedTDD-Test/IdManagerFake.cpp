#include "IdManagerFake.h"

namespace impl {
	int IdManagerFake::getLinkId(std::string link_name) {
		return m_link_data[link_name];
	}
}

