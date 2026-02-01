#include <gtest/gtest.h>
#include "InheritanceVehicleCar.h"

TEST(Car, ShowSpeedOutput)
{
    Car c;
    c.setSpeed(60);

    testing::internal::CaptureStdout();
    c.showSpeed();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Car speed is: 60\n");
}

TEST(Bike, SpeedAlert)
{
    Bike b;
    b.setSpeed(0);
    EXPECT_EQ(b.AlertFunction(), "NA");

    b.setSpeed(10);
    EXPECT_EQ(b.AlertFunction(),"Normal");

    b.setSpeed(70);
    EXPECT_EQ(b.AlertFunction(),"Orange");

    b.setSpeed(120);
    EXPECT_EQ(b.AlertFunction(),"OverspeedReached");
    
    b.setSpeed(180);
    EXPECT_EQ(b.AlertFunction(),"Red");

    b.setSpeed(185);
    EXPECT_EQ(b.AlertFunction(),"OutOffRange");
} 
