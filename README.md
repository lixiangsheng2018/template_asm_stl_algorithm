ProjectTemplate
===============

A [gn](https://gn.googlesource.com/gn),
[ninja](https://github.com/ninja-build/ninja), and
[googletest](https://github.com/google/googletest)-based C++ project template.

Prerequisites
-------------

要求版本clang-10版本以上

```
sudo apt-get install clang-10 ninja
```




Obtaining the source
--------------------

First, clone the repo. Then, initialise and fetch git submodules:

    # Initialise local configuration file.
    git submodule init
    
    # Fetch data from the buildroot submodule.
    git submodule update


### Unit tests

To build and run the unit tests, run:

    ninja -C out/debug src:foo_tests
    ./out/debug/foo_tests



测试用例参考

```C++
//src/foo_test.cc
#include "foo.h"

#include "gtest/gtest.h"

TEST(Foo, IncrementsZero) {
  EXPECT_EQ(1, Foo(0));
}

TEST(Foo, IncrementsPositive) {
  EXPECT_EQ(2, Foo(1));
}

TEST(Foo, IncrementsNegative) {
  EXPECT_EQ(-1, Foo(-2));
}

```

如何添加测试用例

```python
#1.在src下添加源文件hello_test.cc,可以参考src/foo_test.cc
#2.修改src/BUILD.gn文件
executable("foo_tests") {
  testonly = true

  sources = [
    "bar_test.cc",
    "foo_test.cc",
    "hello_test.cc"，
  ]
  deps = [
    ":foo_srcs",
    "//third_party/googletest:gtest",
    "//third_party/googletest:gtest_main",
  ]
}
#3.执行下面指令编译
ninja -C out/debug src:foo_tests
#生成产物在out/debug下面，foo_tests的可执行程序
```

