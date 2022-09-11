#include "pch.h"

#include "../EmbeddedTDD/LinkController.h"

#include "IdManagerMock.h"
#include "LinkConfiguratorMock.h"
#include "IdManagerStub.h"
#include "LinkConfiguratorStub.h"
#include "IdManagerFake.h"

using ::testing::_;
using::testing::Return;

static const std::string EMPTY_LINK_NAME = "";
static const std::string INVALID_LINK_NAME = "link_xy";
static const std::string LINK_NAME_ACTIVATE_FAILURE = "link_a";
static const std::string LINK_NAME = "link_1";
static const int INVALID_LINK_ID = 0;
static const int LINK_ID_ACTIVATE_FAILURE = 100;
static const int LINK_ID = 1000;

class LinkControllerTestWithMocks : public ::testing::Test {
public:
	LinkControllerTestWithMocks() {}
	~LinkControllerTestWithMocks() {}

	void SetUp() override {
		m_id_manager = std::make_shared<IdManagerMock>();
		m_link_configurator = std::make_shared<LinkConfiguratorMock>();

		m_link_controller = LinkControllerAPI::getInstance();
	}

	void TearDown() {
		m_id_manager.reset();
		m_link_configurator.reset();

		LinkControllerAPI::freeInstance();
	}

protected:
	std::shared_ptr<LinkControllerAPI> m_link_controller;
	std::shared_ptr<IdManagerMock> m_id_manager;
	std::shared_ptr<LinkConfiguratorMock> m_link_configurator;
};

TEST_F(LinkControllerTestWithMocks, ActivateFailureEmptyName) {
	EXPECT_FALSE(m_link_controller->activate(EMPTY_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateFailureInvalidName) {
	EXPECT_CALL(*m_id_manager, getLinkId(INVALID_LINK_NAME)).WillOnce(Return(INVALID_LINK_ID));
	EXPECT_FALSE(m_link_controller->activate(INVALID_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateFailure) {
	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(false));
	EXPECT_FALSE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateSuccess) {
	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateTwice) {
	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_FALSE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, DeactivateFailureEmptyName) {
	EXPECT_FALSE(m_link_controller->deactivate(EMPTY_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, DeactivateFailureInvalidName) {
	EXPECT_CALL(*m_id_manager, getLinkId(INVALID_LINK_NAME)).WillOnce(Return(INVALID_LINK_ID));
	EXPECT_FALSE(m_link_controller->deactivate(INVALID_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, DeactivateNotActivatedLink) {
	EXPECT_FALSE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateDeactivateFailure) {
	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, deactivate(LINK_ID)).WillOnce(Return(false));
	EXPECT_FALSE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateDeactivate) {
	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, deactivate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateDeactivateTwice) {
	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, deactivate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_FALSE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithMocks, ActivateDeactivateActivate) {
	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, deactivate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_CALL(*m_id_manager, getLinkId(LINK_NAME)).WillOnce(Return(LINK_ID));
	EXPECT_CALL(*m_link_configurator, activate(LINK_ID)).WillOnce(Return(true));
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

class LinkControllerTestWithStubs : public ::testing::Test {
public:
	LinkControllerTestWithStubs() {}
	~LinkControllerTestWithStubs() {}

	void SetUp() override {
		m_id_manager = std::make_shared<impl::IdManagerStub>();
		m_link_configurator = std::make_shared<impl::LinkConfiguratorStub>();

		m_link_controller = LinkControllerAPI::getInstance();
	}

	void TearDown() {
		m_id_manager.reset();
		m_link_configurator.reset();

		LinkControllerAPI::freeInstance();
	}

protected:
	std::shared_ptr<LinkControllerAPI> m_link_controller;
	std::shared_ptr<impl::IdManagerStub> m_id_manager;
	std::shared_ptr<impl::LinkConfiguratorStub> m_link_configurator;
};

TEST_F(LinkControllerTestWithStubs, ActivateFailureEmptyName) {
	EXPECT_FALSE(m_link_controller->activate(EMPTY_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, ActivateFailureInvalidName) {
	EXPECT_FALSE(m_link_controller->activate(INVALID_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, ActivateFailure) {
	EXPECT_FALSE(m_link_controller->activate(LINK_NAME_ACTIVATE_FAILURE, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, ActivateSuccess) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, ActivateTwice) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_FALSE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, DeactivateFailureEmptyName) {
	EXPECT_FALSE(m_link_controller->deactivate(EMPTY_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, DeactivateFailureInvalidName) {
	EXPECT_FALSE(m_link_controller->deactivate(INVALID_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, DeactivateNotActivatedLink) {
	EXPECT_FALSE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, ActivateDeactivate) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, ActivateDeactivateTwice) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_FALSE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithStubs, ActivateDeactivateActivate) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

class LinkControllerTestWithFake : public ::testing::Test {
public:
	LinkControllerTestWithFake() {}
	~LinkControllerTestWithFake() {}

	void SetUp() override {
		m_id_manager = std::make_shared<impl::IdManagerFake>();
		m_link_configurator = std::make_shared<impl::LinkConfiguratorStub>();

		m_link_controller = LinkControllerAPI::getInstance();
	}

	void TearDown() {
		m_id_manager.reset();
		m_link_configurator.reset();

		LinkControllerAPI::freeInstance();
	}

protected:
	std::shared_ptr<LinkControllerAPI> m_link_controller;
	std::shared_ptr<impl::IdManagerFake> m_id_manager;
	std::shared_ptr<impl::LinkConfiguratorStub> m_link_configurator;
};

TEST_F(LinkControllerTestWithFake, ActivateFailureEmptyName) {
	EXPECT_FALSE(m_link_controller->activate(EMPTY_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, ActivateFailureInvalidName) {
	EXPECT_FALSE(m_link_controller->activate(INVALID_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, ActivateFailure) {
	EXPECT_FALSE(m_link_controller->activate(LINK_NAME_ACTIVATE_FAILURE, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, ActivateSuccess) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, ActivateTwice) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_FALSE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, DeactivateFailureEmptyName) {
	EXPECT_FALSE(m_link_controller->deactivate(EMPTY_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, DeactivateFailureInvalidName) {
	EXPECT_FALSE(m_link_controller->deactivate(INVALID_LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, DeactivateNotActivatedLink) {
	EXPECT_FALSE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, ActivateDeactivate) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, ActivateDeactivateTwice) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_FALSE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));
}

TEST_F(LinkControllerTestWithFake, ActivateDeactivateActivate) {
	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->deactivate(LINK_NAME, m_id_manager, m_link_configurator));

	EXPECT_TRUE(m_link_controller->activate(LINK_NAME, m_id_manager, m_link_configurator));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
