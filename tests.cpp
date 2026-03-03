#include <gtest/gtest.h>
#include <windows.h>
#include "threads.h"

// Тест 1: Проверка поиска минимума и максимума
TEST(MinMaxTest, FindMinAndMax) {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = 6;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.min = 0;
    data.max = 0;
    
    min_max(&data);
    
    EXPECT_EQ(data.min, 1);
    EXPECT_EQ(data.max, 9);
}

// Тест 2: Проверка с одним элементом
TEST(MinMaxTest, SingleElement) {
    int arr[] = {42};
    int size = 1;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.min = 0;
    data.max = 0;
    
    min_max(&data);
    
    EXPECT_EQ(data.min, 42);
    EXPECT_EQ(data.max, 42);
}

// Тест 3: Проверка с отрицательными числами
TEST(MinMaxTest, NegativeNumbers) {
    int arr[] = {-5, -2, -8, -1, -9, -3};
    int size = 6;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.min = 0;
    data.max = 0;
    
    min_max(&data);
    
    EXPECT_EQ(data.min, -9);
    EXPECT_EQ(data.max, -1);
}

// Тест 4: Проверка с одинаковыми элементами
TEST(MinMaxTest, AllSameElements) {
    int arr[] = {7, 7, 7, 7, 7};
    int size = 5;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.min = 0;
    data.max = 0;
    
    min_max(&data);
    
    EXPECT_EQ(data.min, 7);
    EXPECT_EQ(data.max, 7);
}

// Тест 5: Проверка среднего арифметического
TEST(AverageTest, CalculateAverage) {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.average = 0;
    
    average(&data);
    
    EXPECT_DOUBLE_EQ(data.average, 3.0);
}

// Тест 6: Проверка среднего с одним элементом
TEST(AverageTest, SingleElementAverage) {
    int arr[] = {42};
    int size = 1;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.average = 0;
    
    average(&data);
    
    EXPECT_DOUBLE_EQ(data.average, 42.0);
}

// Тест 7: Проверка среднего с отрицательными числами
TEST(AverageTest, NegativeNumbersAverage) {
    int arr[] = {-5, -2, -8, -1, -9, -3};
    int size = 6;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.average = 0;
    
    average(&data);
    
    EXPECT_DOUBLE_EQ(data.average, -4.666666666666667);
}

// Тест 8: Проверка среднего с нулями
TEST(AverageTest, ZerosAverage) {
    int arr[] = {0, 0, 0, 0, 0};
    int size = 5;
    
    ThreadData data;
    data.arr = arr;
    data.size = size;
    data.average = 0;
    
    average(&data);
    
    EXPECT_DOUBLE_EQ(data.average, 0.0);
}

// Главная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
