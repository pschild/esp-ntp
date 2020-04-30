#include <Arduino.h>
#include <unity.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

#define FOO 42

void my_test_fn(void) {
    TEST_ASSERT_EQUAL(42, FOO);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // IMPORTANT LINE!
    
    RUN_TEST(my_test_fn);
    
    UNITY_END();
}

void loop() {
}
