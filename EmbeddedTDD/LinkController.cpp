#include "LinkController.h"

#include <iostream>

static const int INVALID_ID = 0;

static std::shared_ptr<impl::LinkController> link_controller_sp = nullptr;

std::shared_ptr<LinkControllerAPI> LinkControllerAPI::getInstance() {
	if (link_controller_sp == nullptr) {
		link_controller_sp = std::make_shared<impl::LinkController>();
	}
	return link_controller_sp;
}

void LinkControllerAPI::freeInstance() {
	if (link_controller_sp != nullptr) {
		link_controller_sp.reset();
	}
}
namespace impl {
	LinkController::LinkController() {}

	void LinkController::init(std::shared_ptr<IdManagerAPI> id_manager_sp, std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp) {
		m_id_manager_sp = id_manager_sp;
		m_link_configurator_sp = link_configurator_sp;
	}

bool LinkController::activate(std::string link_name) {
	if (link_name.empty()) {
		std::cout << "Empty link name!\n";
		return false;
	}

	int id = m_id_manager_sp->getLinkId(link_name);
	if (id == INVALID_ID) {
		std::cout << "Invalid link name: '" << link_name << "'\n";
		return false;
	}

	auto it = std::find(m_activated_links.begin(), m_activated_links.end(), link_name);
	if (it != m_activated_links.end()) {
		std::cout << "Link '" << link_name << "' is already activated." << "\n";
		return false;
	}
	
	if (m_link_configurator_sp->activate(id)) {
		m_activated_links.push_back(link_name);
		std::cout << "Activation successful!\n";
		return true;
	}
	std::cout << "Activation unsuccessful!\n";
	return false;
}

bool LinkController::deactivate(std::string link_name) {
	if (link_name.empty()) {
		std::cout << "Empty link name!\n";
		return false;
	}

	int id = m_id_manager_sp->getLinkId(link_name);
	if (id == INVALID_ID) {
		std::cout << "Invalid link name: '" << link_name << "'\n";
		return false;
	}

	auto it = std::find(m_activated_links.begin(), m_activated_links.end(), link_name);
	if (it == m_activated_links.end()) {
		std::cout << "Link '" << link_name << "' is not activated." << "\n";
		return false;
	}

	if (m_link_configurator_sp->deactivate(id)) {
		m_activated_links.remove(link_name);
		std::cout << "Deactivation successful!\n";
		return true;
	}
	std::cout << "Deactivation unsuccessful!\n";
	return false;
}
}


