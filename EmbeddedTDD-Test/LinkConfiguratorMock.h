#pragma once
#ifndef LINK_CONFIGURATOR_MOCK_H
#define LINK_CONFIGURATOR_MOCK_H
#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../EmbeddedTDD/LinkConfiguratorAPI.h"

class LinkConfiguratorMock : public LinkConfiguratorAPI {
public:
	MOCK_METHOD(bool, activate, (int link_id), (override));

	MOCK_METHOD(bool, deactivate, (int link_id), (override));

	MOCK_METHOD(bool, isActivated, (int link_id), (override));
};

#endif