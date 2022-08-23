#include "pch.h"

#include <memory>

#include "../EmbeddedTDD/LinkController.h"
#include "../EmbeddedTDD-Test/IdManagerMock.h"

using ::testing::_;
using::testing::Return;
using::testing::SaveArg;

class LinkControllerTest : public ::testing::Test {
public:
	LinkControllerTest() {}
	~LinkControllerTest() {}	
	
	void SetUp() override {
		//CreateMockIdManager();

		m_link_controller = LinkControllerAPI::getInstance();
	}

	void TearDown() {
		//DeleteMockIdManager();

		LinkControllerAPI::freeInstance();
	}

protected:
	std::shared_ptr<LinkControllerAPI> m_link_controller;
};

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(LinkControllerTest, ActivateSuccess) {
	//IdManagerMock idManager;

	//EXPECT_CALL(idManager, getLinkId(_)).Times(1);
	m_link_controller->activate("link_a");

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}