#include "pch.h"

#include <memory>

#include "../EmbeddedTDD/LinkController.h"
#include "IdManagerMock.h"
#include "LinkConfiguratorMock.h"

using ::testing::_;
using::testing::Return;
using::testing::SaveArg;

class LinkControllerTest : public ::testing::Test {
public:
	LinkControllerTest() {}
	~LinkControllerTest() {}	
	
	void SetUp() override {
		//CreateMockIdManager();
		m_id_manager = std::make_shared<IdManagerMock>();
		m_link_configurator = std::make_shared<LinkConfiguratorMock>();


		m_link_controller = LinkControllerAPI::getInstance();
	}

	void TearDown() {
		//DeleteMockIdManager();
		m_id_manager.reset();
		m_link_configurator.reset();

		LinkControllerAPI::freeInstance();
	}

protected:
	std::shared_ptr<LinkControllerAPI> m_link_controller;
	std::shared_ptr<IdManagerMock> m_id_manager;
	std::shared_ptr<LinkConfiguratorMock> m_link_configurator;
};

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(LinkControllerTest, ActivateSuccess) {

	EXPECT_CALL(*m_id_manager, getLinkId("link_a")).WillOnce(Return(100));
	//sEXPECT_CALL(*m_link_configurator, isActivated(100)).WillOnce(Return(false));
	EXPECT_CALL(*m_link_configurator, activate(100)).WillOnce(Return(true));

	EXPECT_TRUE(m_link_controller->activate("link_a", m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTest, ActivateFailureWrongName) {

	EXPECT_CALL(*m_id_manager, getLinkId("link_z")).WillOnce(Return(0));
	
	EXPECT_FALSE(m_link_controller->activate("link_z", m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTest, ActivateTwice) {

	EXPECT_CALL(*m_id_manager, getLinkId("link_a")).WillOnce(Return(100));
	//EXPECT_CALL(*m_link_configurator, isActivated(100)).WillOnce(Return(false));
	EXPECT_CALL(*m_link_configurator, activate(100)).WillOnce(Return(true));

	EXPECT_TRUE(m_link_controller->activate("link_a", m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId("link_a")).WillOnce(Return(100));
	//EXPECT_CALL(*m_link_configurator, isActivated(100)).WillOnce(Return(true));

	EXPECT_FALSE(m_link_controller->activate("link_a", m_id_manager, m_link_configurator));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
