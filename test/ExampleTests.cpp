#include "../watchdog.h"

#include <gtest/gtest.h>



class ExampleTests : public ::testing::Test {
    
};

TEST_F(ExampleTests, DemonstrateGTestMacros){
    struct mosquitto* watchdog_ = nullptr;
    watchdog watchdog;

    const char* jsonMessage = "{\"idComponent\": \"1\", \"componentName\": \"BackendProcessor\"}";
    struct mosquitto_message message;
    message.payload = static_cast<void*>(new std::string("{\"idComponent\": \"1\", \"componentName\": \"BackendProcessor\"}"));
    message.topic = "watchdog";
    message.payloadlen = strlen(jsonMessage);
    message.qos = 0;
    message.retain = false;

    watchdog.monitorComponent(watchdog_,&watchdog,&message);

    ASSERT_STREQ("1", watchdog.idComponent.c_str());
    ASSERT_STREQ("BackendProcessor", watchdog.componentName.c_str());

}

