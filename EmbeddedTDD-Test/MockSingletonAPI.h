#pragma once
#ifndef MOCK_SINGLETON_API_HH
#define MOCK_SINGLETON_API_HH

#include <assert.h>
#include <cstdio>
#include <memory>
#include <string>
#include <typeinfo>

//#include <cassert>
//#include <crtdbg.h>

#define MOCKSINGLETONAPI_ASSERT(__MSG__) __assert(__MSG__, __FILE__, __LINE__)

/* Copy of AIS- PLAB - mockAPI.h */

template <class MockClass>
class MockSingletonAPI {
    static std::shared_ptr<MockClass> mockObject;

public:
    static void createMockObject();
    static void createStrictMockObject();
    static std::shared_ptr<MockClass> getMockObject();
    static void deleteMockObject();

protected:
    static std::string mockClassName();
};

template <class MockClass>
std::shared_ptr<MockClass> MockSingletonAPI<MockClass>::mockObject = nullptr;

template <class MockClass>
void MockSingletonAPI<MockClass>::createMockObject() {
    if (mockObject != nullptr) {
        std::string errStr = "mockObject != nullptr, missing delete of a \"";
        errStr.append(mockClassName()).append("\" object");
        //MOCKSINGLETONAPI_ASSERT(errStr.c_str());
    }
    mockObject = std::make_shared<MockClass>();
}

template <class MockClass>
void MockSingletonAPI<MockClass>::createStrictMockObject() {
    if (mockObject != nullptr) {
        std::string errStr = "mockObject != nullptr, missing delete of a \"";
        errStr.append(mockClassName()).append("\" object");
        //MOCKSINGLETONAPI_ASSERT(errStr.c_str());
    }
    mockObject = std::make_shared<::testing::StrictMock<MockClass>>();
}

template <class MockClass>
std::shared_ptr<MockClass> MockSingletonAPI<MockClass>::getMockObject() {
    if (mockObject == nullptr) {
        std::string errStr = "mockObject == nullptr, missing create of a \"";
        errStr.append(mockClassName()).append("\" object");
        //MOCKSINGLETONAPI_ASSERT(errStr.c_str());
    }
    return mockObject;
}

template <class MockClass>
void MockSingletonAPI<MockClass>::deleteMockObject() {
    if (mockObject == nullptr) {
        std::string errStr = "mockObject == NULL, missing create of a \"";
        errStr.append(mockClassName()).append("\" object");
        //MOCKSINGLETONAPI_ASSERT(errStr.c_str());
    }
    mockObject = nullptr;
}

template <class MockClass>
std::string MockSingletonAPI<MockClass>::mockClassName() {
    std::string s = typeid(MockClass).name();
    return s.substr(s.find_first_not_of("1234567890"));
}

#endif /* MOCK_SINGLETON_API_HH */