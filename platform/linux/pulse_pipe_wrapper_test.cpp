#include "pulse_pipe_wrapper.h"
#include <gtest/gtest.h>

TEST(PulsePipeWrapperTest, InitializePulseAudio) {
    EXPECT_NO_THROW(PulsePipeWrapper::initializePulseAudio());
}

TEST(PulsePipeWrapperTest, InitializePipeWire) {
    EXPECT_NO_THROW(PulsePipeWrapper::initializePipeWire());
}

TEST(PulsePipeWrapperTest, SetOutputDevice) {
    EXPECT_NO_THROW(PulsePipeWrapper::setOutputDevice("headphones"));
}

TEST(PulsePipeWrapperTest, CreateVirtualOutput) {
    EXPECT_NO_THROW(PulsePipeWrapper::createVirtualOutput("virtual_output"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
