/*
 * all_test.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年1月16日 Author: menmen
 */
#include <complex>
#include <unordered_set>

#include "fold_expression.hpp"
#include "gtest/gtest.h"
#include "print.hpp"
#include "varidic_class.hpp"

TEST(Print, PrintTest) {
  std::string s("world");
  template_2nd::print(7.5, "hello", s);

  EXPECT_EQ(10, template_2nd::foldSum(1, 2, 3, 4));
}

TEST(PrintFinal, PrintFinalTest) {
  std::string s("world");
  template_2nd::print_final(7.5, "hello", s);
  template_2nd::printDoubled(7.5, s, std::complex<float>(4, 2));
}

TEST(FoldExpress, FoldExpressTest) {
  using template_2nd::left;
  using template_2nd::Node;
  using template_2nd::right;
  Node* root = new Node{0};
  root->left = new Node{1};
  root->right = new Node{2};
  root->left->left = new Node{3};
  root->left->right = new Node{4};
  EXPECT_EQ(3, traverse(root, left, left)->value);
  EXPECT_EQ(4, traverse(root, left, right)->value);
}

TEST(Homogeneous, HomogeneousTest) {
  using template_2nd::Indices;
  using template_2nd::isHomogeneous;
  using template_2nd::printByIdx;
  using template_2nd::printElems;
  using template_2nd::printIdx;
  EXPECT_EQ(false, isHomogeneous(43, -1, "hello"));
  EXPECT_EQ(true, isHomogeneous("hello", "", "world", "!"));

  std::vector<std::string> coll = {"good", "times", "say", "bye"};
  printElems(coll, 2, 0, 3);
  printIdx<2, 0, 3>(coll);

  std::array<std::string, 5> arr = {"Hello", "my", "new", "!", "World"};
  printByIdx(arr, Indices<0, 4, 3>());
}

TEST(VaridicClass, VaridicClassTest) {
  using namespace template_2nd;
  // combine hasher and equality for customers in one type:
  using CustomerOP = Overloader<CustomerHash, CustomerEq>;
  std::unordered_set<Customer, CustomerHash, CustomerEq> coll1;
  std::unordered_set<Customer, CustomerOP, CustomerOP> coll2;

  Customer c1("zhangsan");
  Customer c2("lisi");
  Customer c3("zhangsan");
  EXPECT_EQ(true, coll1.insert(c1).second);
  EXPECT_EQ(true, coll1.insert(c2).second);
  EXPECT_EQ(false, coll1.insert(c3).second);

  EXPECT_EQ(true, coll2.insert(c1).second);
  EXPECT_EQ(true, coll2.insert(c2).second);
  EXPECT_EQ(false, coll2.insert(c3).second);
}
