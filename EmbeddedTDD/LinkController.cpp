#include "LinkController.h"

#include "IdManagerAPI.h"
#include "LinkConfiguratorAPI.h"

#include <iostream>

IdManagerAPI* idManager;
LinkConfiguratorAPI* linkConfigurator;

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

bool LinkController::activate(std::string link_name) {
	//provjeri postoji li taj link_name u idManager
	int id = idManager->getLinkId(link_name);
	if (id == 0) {
		return false;
	}
	//provjeri je li taj link vec aktiviran
	if (linkConfigurator->isActivated(id)) {
		return false;
	}
	//posalji zahtjev za aktivaciju linka
	return linkConfigurator->activate(id);

	//spremi negdi da je link aktiviran 
}
}


