#include <stdio.h>
#include <memory>
#include "LinkController.h"
int main(int arg, char ** argv) {
	std::shared_ptr<LinkControllerAPI> m_link_controller = LinkControllerAPI::getInstance();
	m_link_controller->activate("link_a");
		return 0;
}