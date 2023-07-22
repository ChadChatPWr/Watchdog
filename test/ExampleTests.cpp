#include "../watchdog.h"

#include <gtest/gtest.h>

class ExampleTests : public ::testing::Test {
};

TEST_F(ExampleTests, DemonstrateGTestMacros){
    watchdog watchdog;

    ASSERT_TRUE(!watchdog_);
    EXPECT_CALL(watchdog::connect());
    EXPECT_CALL(watchdog::loop());

    std::string jsonMessage = "{\"idComponent\": \"1\", \"componentName\": \"BackendProcessor\"}";
    struct mosquitto_message message;
    message.payload = jsonMessage;
    message.topic = "watchdog";
    // For simplicity, we are setting the other fields of the message to nullptr or 0
    message.payloadlen = strlen(jsonMessage);
    message.qos = 0;
    message.retain = false;

    watchdog::monitorComponent(watchdog_,&watchdog.&message);

    ASSERT_STREQ("1", watchdog_.idComponent.c_str());
    ASSERT_STREQ("BackendProcessor", watchdog_.componentName.c_str());

}

