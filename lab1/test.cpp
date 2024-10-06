// #include "gtest/gtest.h"
#include "pch.h"

extern "C" {
#include "Lab1.h" // ���������� ��� ��� � ���������
}

// ���� ������� �������� �������� �����
TEST(LongNumberTest, Create_LongNumbers_def) {
    LongNumber* result = Create_long_number(1);
    EXPECT_STREQ(result->original_result, "0") << "��������� 0";
    EXPECT_EQ(result->original_result[1], '\0') << "��������� \\0";
    EXPECT_STREQ(result->result, "0") << "��������� 0";
    EXPECT_EQ(result->result[1], '\0') << "��������� \\0";
    Free_long_number(result);
}

// ���� ������� ��������� ���� ������� �����
// ������� ������
TEST(LongNumberTest, What_is_bigger_def) {
    char* num1 = "1";
    char* num2 = "0";
    EXPECT_EQ(IsBigger_long_numer(num1, num2), 1)
        << "��������� 1 (������ ����� ������)";
}
// ������ ���������� �����
TEST(LongNumberTest, What_is_bigger_eq) {
    char* num1 = "1";
    char* num2 = "1";
    EXPECT_EQ(IsBigger_long_numer(num1, num2), 1)
        << "��������� 1 (����� �����)";
}
// ������ ������ ����� �������
TEST(LongNumberTest, What_is_bigger_incorrect_null) {
    char* num1 = "1";
    char* num2 = "0000";
    EXPECT_EQ(IsBigger_long_numer(num1, num2), 1)
        << "��������� 1 (������ ����� ������)";
}

// ���� ������� ���������� ������� ��������� �������
TEST(LongNumberTest, Signisicant_digit_def) {
    char* num = "0001";
    int start = 0;
    int maxlength = 4;
    EXPECT_EQ(Find_significant_digit(start, maxlength, num), 3)
        << "��������� 3 (������ ������ �������� ����� ����� 3)";
}

// ���� �������� ������� �����
// ������� ������
TEST(LongNumberTest, AddLongNumbers_def) {
    LongNumber* result = Add_long_numbers("1", "1");
    EXPECT_STREQ(result->result, "2") << "��������� |1 + 1| = 2";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� � ��� ����� �������������
TEST(LongNumberTest, AddLongNumbers_incorrect_positive_null) {
    LongNumber* result = Add_long_numbers("000", "000");
    EXPECT_STREQ(result->result, "0") << "��������� |0 + 0| = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� � ���� �� ����� �������������
TEST(LongNumberTest, AddLongNumbers_incorrect_negative_null) {
    LongNumber* result = Add_long_numbers("-000", "000");
    EXPECT_STREQ(result->result, "0") << "��������� |-0 + 0| = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� � ��� ����� �������������
TEST(LongNumberTest, AddLongNumbers_incorrect_negative_null_two) {
    LongNumber* result = Add_long_numbers("-000", "-000");
    EXPECT_STREQ(result->result, "0") << "��������� |-0 + -0| = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ���� ����� ������������� ������ �������������, �� ������ ����� �����
TEST(LongNumberTest, AddLongNumbers_negative_plus_positive_eq_null) {
    LongNumber* result = Add_long_numbers("-1", "1");
    EXPECT_STREQ(result->result, "0") << "��������� |-1 + 1| = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ���� ����� ������������� ������ �������������, �� ������ �������������
// ����� ������
TEST(LongNumberTest, AddLongNumbers_negative_plus_positive_eq_possitive) {
    LongNumber* result = Add_long_numbers("-1", "2");
    EXPECT_STREQ(result->result, "1") << "��������� |-1 + 2| = 1";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ���� ����� ������������� ������ �������������, �� ������ �������������
// ����� ������
TEST(LongNumberTest, AddLongNumbers_negative_plus_positive_eq_negative) {
    LongNumber* result = Add_long_numbers("-2", "1");
    EXPECT_STREQ(result->result, "1") << "��������� |-2 + 1| = 1";
    EXPECT_EQ(result->IsNegative, 1) << "��������� 1 (�������������)";
    Free_long_number(result);
}
// ������ ��� ����� �������������
TEST(LongNumberTest, AddLongNumbers_negative_plus_negative) {
    LongNumber* result = Add_long_numbers("-1", "-1");
    EXPECT_STREQ(result->result, "2") << "��������� |-1 + -1| = 2";
    EXPECT_EQ(result->IsNegative, 1) << "��������� 1 (�������������)";
    Free_long_number(result);
}
// ������ ���������� �������
TEST(LongNumberTest, AddLongNumbers_add_rank) {
    LongNumber* result = Add_long_numbers("1", "9");
    EXPECT_STREQ(result->result, "10") << "��������� |1 + 9| = 10";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}

// ���� ��������� ������� �����
// ������� ������
TEST(LongNumberTest, MultiplyLongNumbers_def) {
    LongNumber* result = Multiply_long_numbers("1", "2");
    EXPECT_STREQ(result->result, "2") << "��������� |1 * 2| = 2";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� ��� ����� �������������
TEST(LongNumberTest, MultiplyLongNumbers_incorrect_null_positive) {
    LongNumber* result = Multiply_long_numbers("0000", "1");
    EXPECT_STREQ(result->result, "0") << "��������� |0 * 1| = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� ���� �� ����� �������������
TEST(LongNumberTest, MultiplyLongNumbers_incorrect_null_negative) {
    LongNumber* result = Multiply_long_numbers("-0000", "1");
    EXPECT_STREQ(result->result, "0") << "��������� |0 * 1| = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� ��� ����� �������������
TEST(LongNumberTest, MultiplyLongNumbers_incorrect_null_negative_two) {
    LongNumber* result = Multiply_long_numbers("-0000", "-1");
    EXPECT_STREQ(result->result, "0") << "��������� |0 * -1| = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ���� ����� �������������, ������ �������������
TEST(LongNumberTest, MultiplyLongNumbers_negative_mul_positive) {
    LongNumber* result = Multiply_long_numbers("-1", "1");
    EXPECT_STREQ(result->result, "1") << "��������� |-1 * 1| = 1";
    EXPECT_EQ(result->IsNegative, 1) << "��������� 1 (�������������)";
    Free_long_number(result);
}
// ������ ��� ����� �������������
TEST(LongNumberTest, MultiplyLongNumbers_negative_mul_negative) {
    LongNumber* result = Multiply_long_numbers("-1", "-1");
    EXPECT_STREQ(result->result, "1") << "��������� |-1 * -1| = 1";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}

// ���� ���������� � �������
// ������� ������
TEST(LongNumberTest, PowerLongNumbers_def) {
    LongNumber* result = Power_long_numbers("2", 2);
    EXPECT_STREQ(result->result, "4") << "��������� 2^2 = 4";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� � ���� �����
TEST(LongNumberTest, PowerLongNumbers_incorrect_null_in_base) {
    LongNumber* result = Power_long_numbers("0000", 2);
    EXPECT_STREQ(result->result, "0") << "��������� 0^2 = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� � ������� �����
TEST(LongNumberTest, PowerLongNumbers_incorrect_null_in_exp) {
    LongNumber* result = Power_long_numbers("1", 0000);
    EXPECT_STREQ(result->result, "1") << "��������� 1^0 = 1";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������ ����� ������� � ���� �������������� �����
TEST(LongNumberTest, PowerLongNumbers_incorrect_null_negative_in_base) {
    LongNumber* result = Power_long_numbers("-0000", 2);
    EXPECT_STREQ(result->result, "0") << "��������� 0^2 = 0";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}

// ������ ������������� ���� � ������ �������
TEST(LongNumberTest, PowerLongNumbers_negative_in_base_even_base) {
    LongNumber* result = Power_long_numbers("-1", 2);
    EXPECT_STREQ(result->result, "1") << "��������� -1^2 = 1";
    EXPECT_EQ(result->IsNegative, 0) << "��������� 0 (�������������)";
    Free_long_number(result);
}
// ������ ������������� ���� � �������� �������
TEST(LongNumberTest, PowerLongNumbers_negative_in_base_odd_base) {
    LongNumber* result = Power_long_numbers("-1", 3);
    EXPECT_STREQ(result->result, "1") << "��������� -1^3 = -1";
    EXPECT_EQ(result->IsNegative, 1) << "��������� 1 (�������������)";
    Free_long_number(result);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // ������ ���� ������
}