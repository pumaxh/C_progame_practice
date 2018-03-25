LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)

#SET(CMAKE_CXX_FLAGS -lgtest -lpthread)
ADD_EXECUTABLE(sample_test test_main.cpp sample1.cc sample1_unittest.cc)

INCLUDE_DIRECTORIES(${GTEST_DIR}/include)
INCLUDE_DIRECTORIES(${GTEST_DIR}/samples)

TARGET_LINK_LIBRARIES(sample_test libgtest.a)
TARGET_LINK_LIBRARIES(sample_test libpthread.so)
