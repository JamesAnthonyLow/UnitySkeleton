#include "unity.h"
#include "HelloWorld.h"

void test_HelloWorld(void)
{
  TEST_ASSERT_EQUAL_STRING("Hello Worl", greeting);
  TEST_ASSERT_EQUAL_STRING("Hello World!", greeting);
}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_HelloWorld);
  return UNITY_END();
}
