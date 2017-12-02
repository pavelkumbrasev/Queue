#include "Queue.h"

#include <gtest.h>

TEST(TQueue, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<double>(10));

}

TEST(TQueue, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue<double>(-1));
}

TEST(TQueue, can_copy_stack)
{
	TQueue<double> a;
	a.clear();
	a.push(5);

    EXPECT_NO_THROW(TQueue<double> b(a));
}
TEST(TQueue, cant_take_elem_in_empty_stack)
{
	TQueue<double> a;
	a.clear();
	ASSERT_ANY_THROW(a.pop());
}
TEST(TQueue, can_take_elem_in_not_empty_stack)
{
	TQueue<double> a;
	a.clear();
	a.push(1);
	ASSERT_NO_THROW(a.pop());
}
TEST(TQueue, cant_push_elem_in_full_stack)
{
	TQueue<double> a(1);
	a.clear();
	a.push(1);
	ASSERT_ANY_THROW(a.push(1));
}
TEST(TQueue, can_take_elem_in__stack)
{
	TQueue<double> a;
	a.clear();
	a.push(5);
    TQueue<double> b(a);
    EXPECT_EQ(5, b.pop());
}
TEST(TQueue, can_check_stack_is_empty)
{
	TQueue<double> a;
	a.clear();
	a.push(5);

	EXPECT_EQ(false, a.isEmpty());
}
TEST(TQueue, can_check_stack_is_full)
{
	TQueue<double> a(1);
	a.clear();
	a.push(5);

	EXPECT_EQ(true, a.isFull());
}


