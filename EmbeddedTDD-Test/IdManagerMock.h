#ifndef ID_MANAGER_MOCK_H
#define ID_MANAGER_MOCK_H
#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../EmbeddedTDD/IdManagerAPI.h"

class IdManagerMock : public IdManagerAPI {
public:
	MOCK_METHOD(int, getLinkId, (std::string link_name), (override));
};

#define CreateMockIdManager() \
	MockSingletonAPI<testing::StrictMock<IdManagerMock>>::createMockObject()
#define GetMockIdManager() \
	MockSingletonAPI<testing::StrictMock<IdManagerMock>>::getMockObject()
#define DeleteMockIdManager() \
	MockSingletonAPI<testing::StrictMock<IdManagerMock>>::deleteMockObject()

#endif