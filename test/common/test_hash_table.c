//
// Created by kennetsu on 1/8/21.
//
#include "catch.hpp"
#include <string.h>
#include <catch2/catch.hpp>

SCENARIO("Power off tests", "[power_button]")
{
    GIVEN("the power is off")
    {
        power_button_initialize(POWER_OFF);

        WHEN("nothing happens")
        {
            THEN("the power is still off")
            {
                REQUIRE(power_button_getPowerState() == POWER_OFF);
            }
        }

        WHEN("the power button is momentarily pressed")
        {
            power_button_pressMomentary();

            THEN("the power turns on")
            {
                REQUIRE(power_button_getPowerState() == POWER_ON);
            }
        }
    }
}