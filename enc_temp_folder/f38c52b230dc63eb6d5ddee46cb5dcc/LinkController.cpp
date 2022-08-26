#include "LinkController.h"

#include "IdManagerAPI.h"
#include "LinkConfiguratorAPI.h"

#include <iostream>

static std::shared_ptr<impl::LinkController> link_controller_sp = nullptr;

std::shared_ptr<IdManagerAPI> id_manager_sp = nullptr;
std::shared_ptr<LinkConfiguratorAPI> link_configurator_sp = nullptr;

std::shared_ptr<LinkControllerAPI> LinkControllerAPI::getInstance() {
	if (link_controller_sp == nullptr) {
		link_controller_sp = std::make_shared<impl::LinkController>(id_manager_sp, link_configurator_sp);
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

	LinkController::LinkController(std::shared_ptr<IdManagerAPI> id_manager, std::shared_ptr<LinkConfiguratorAPI> link_configurator) : LinkControllerAPI() {
		if (!id_manager || !link_configurator) {
			throw std::exception("null dependency");
		}
		id_manager_sp = id_manager;
		link_configurator_sp = link_configurator;
	}

bool LinkController::activate(std::string link_name) {
	//provjeri postoji li taj link_name u idManager
	int id = id_manager_sp->getLinkId(link_name);
	if (id == 0) {
		return false;
	}
	//provjeri je li taj link vec aktiviran
	if (link_configurator_sp->isActivated(id)) {
		return false;
	}
	//posalji zahtjev za aktivaciju linka
	return link_configurator_sp->activate(id);

	//spremi negdi da je link aktiviran 
}
}


