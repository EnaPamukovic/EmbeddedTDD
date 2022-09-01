#include "LinkController.h"

#include "IdManagerAPI.h"
#include "LinkConfiguratorAPI.h"

#include <iostream>

static std::shared_ptr<impl::LinkController> link_controller_sp = nullptr;

std::shared_ptr<IdManagerAPI> id_manager_sp = nullptr;
std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp = nullptr;

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
	LinkController::LinkController() {
		//m_id_manager_sp = std::make_shared<IdManagerAPI>();
	}

	/*LinkController::LinkController(std::shared_ptr<IdManagerAPI> id_manager, std::shared_ptr<LinkConfiguratorAPI> link_configurator) : LinkControllerAPI() {
		if (!id_manager || !link_configurator) {
			throw std::exception("null dependency");
		}
		id_manager_sp = id_manager;
		link_configurator_sp = link_configurator;
	}*/

	std::shared_ptr<IdManagerAPI> LinkController::getIdManagerInstance() {
		return m_id_manager_sp;
	}

bool LinkController::activate(std::string link_name, std::shared_ptr<IdManagerAPI> id_manager_sp, std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp) {
	//provjeri postoji li taj link_name u idManager
	int id = id_manager_sp->getLinkId(link_name);
	if (id == 0) {
		printf("Link with that name is not found.");
		return false;
	}

	//provjeri je li taj link vec aktiviran
	auto it = std::find(m_activated_links.begin(), m_activated_links.end(), link_name);
	if (it != m_activated_links.end()) {
		printf("This link is already activated");
		return false;
	}
	
	/*if (link_configurator_sp->isActivated(id)) {
		return false;
	}*/

	//posalji zahtjev za aktivaciju linka
	if (link_configurator_sp->activate(id)) {
		m_activated_links.push_back(link_name);
		printf("Activation succesfull!");
		return true;
	}
	return false;
}
}


