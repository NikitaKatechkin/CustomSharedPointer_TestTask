#include "pch.h"
#include "../CustomSharedPointer/CustomShairedPointer.h"

TEST(TestCaseName, TestName) 
{
	CustomSharedPointer<int> test_shared_pointer_1(25);
	CustomSharedPointer<int> test_shared_pointer_2(25);
	CustomSharedPointer<int> test_shared_pointer_3(test_shared_pointer_1);

	EXPECT_EQ(test_shared_pointer_1.GetData(), test_shared_pointer_2.GetData());
	EXPECT_EQ(test_shared_pointer_1.GetData(), test_shared_pointer_3.GetData());

	EXPECT_NE(test_shared_pointer_1.GetDataRawPointer(), test_shared_pointer_2.GetDataRawPointer());
	EXPECT_NE(test_shared_pointer_1.GetCounterRawPointer(), test_shared_pointer_2.GetCounterRawPointer());

	EXPECT_EQ(test_shared_pointer_1.GetDataRawPointer(), test_shared_pointer_3.GetDataRawPointer());
	EXPECT_EQ(test_shared_pointer_1.GetCounterRawPointer(), test_shared_pointer_3.GetCounterRawPointer());
}