#include "pch.h"
#include "CppUnitTest.h"
#include "../../lab5.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест 1: базовий приклад
        TEST_METHOD(TestBasicCountWays)
        {
            maxDepth = 0; // обнуляємо перед тестом
            int result = countWays(5, 1, 2, 3);
            Assert::AreEqual(5, result, L"Кількість способів для 5 з номіналами 1,2,3 неправильна");
            Assert::IsTrue(maxDepth > 0, L"Глибина рекурсії повинна бути > 0");
        }

        // Тест 2: m = 0
        TEST_METHOD(TestZeroSum)
        {
            maxDepth = 0;
            int result = countWays(0, 1, 2, 3);
            Assert::AreEqual(1, result, L"Для m=0 має бути 1 спосіб");
            Assert::AreEqual(1, maxDepth, L"Глибина рекурсії для m=0 повинна бути 1");
        }

        // Тест 3: m менше мінімального номіналу
        TEST_METHOD(TestLessThanMin)
        {
            maxDepth = 0;
            int result = countWays(1, 2, 3, 4);
            Assert::AreEqual(0, result, L"Для m < мінімального номіналу повинно бути 0 способів");
            Assert::IsTrue(maxDepth > 0, L"Рекурсія все одно спрацювала");
        }

        // Тест 4: перевірка глибини рекурсії для більшого m
        TEST_METHOD(TestMaxDepth)
        {
            maxDepth = 0;
            int result = countWays(4, 1, 2, 3);
            Assert::AreEqual(7, result, L"Кількість способів для m=4 неправильна");
            Assert::IsTrue(maxDepth >= 2, L"Максимальна глибина рекурсії повинна бути >= 2");
        }
    };
}
