/** test/unitTestInsert.c
 *
 * This file is a part of:
 * Azadeh Afzar - Arayehsaz (AA-A).
 *
 * Copyright (C) 2020 Mohammad Mahdi Baghbani Pourvahid.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgement in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include "../include/arayeh.h"
#include "unity test framework/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_insert(void)
{
    // This Test is here to ensure that insert works as expected.

    // define error state variable.
    int state;

    // define default arayeh size.
    size_t arayehSize = 10;
    int element       = 5;

    // create new arayeh.
    arayeh *testCase = newArayeh1D(TYPE_INT, arayehSize);

    // insert element.
    state = (testCase->insert)(testCase, 0, &element);

    // assert successful insertion.
    TEST_ASSERT_EQUAL_INT(AA_ARAYEH_SUCCESS, state);

    // assert element is inserted in index 0.
    TEST_ASSERT_EQUAL_INT(element, testCase->_internalProperties.array.pInt[0]);
    TEST_ASSERT_EQUAL_CHAR(IS_FILLED, testCase->_internalProperties.map[0]);
    TEST_ASSERT_EQUAL_INT(1, testCase->_internalProperties.next);

    // insert element.
    state = (testCase->insert)(testCase, 5, &element);

    // assert successful insertion.
    TEST_ASSERT_EQUAL_INT(AA_ARAYEH_SUCCESS, state);

    // assert element is inserted in index 0.
    TEST_ASSERT_EQUAL_INT(element, testCase->_internalProperties.array.pInt[5]);
    TEST_ASSERT_EQUAL_CHAR(IS_FILLED, testCase->_internalProperties.map[5]);
    TEST_ASSERT_EQUAL_INT(1, testCase->_internalProperties.next);

    // free arayeh.
    (testCase->freeArayeh)(&testCase);
}

void test_error_out_of_range_index(void)
{
    // This test ensures that a error code will be returned by insert function
    // when the index is not in range of 0 to (arayeh size - 1), also because
    // the index field of insert function is of type size_t, any negative number
    // in the function call will be converted to unsigned and thus result in
    // an overflow, most of time it will be a very big number that is possibly
    // out of arayeh valid indexes range, but there is a chance that conversion
    // would result in a number inside valid range and corrupt the data inside
    // the arayeh.

    // define error state variable.
    int state;

    // define default arayeh size.
    size_t arayehSize = 10;
    int element       = 5;

    // create new arayeh.
    arayeh *testCase = newArayeh1D(TYPE_INT, arayehSize);

    // insert element in index 10 (maximum possible index is 9).
    state = (testCase->insert)(testCase, 10, &element);

    // assert error code.
    TEST_ASSERT_EQUAL_INT(AA_ARAYEH_WRONG_INDEX, state);

    // ensure arayeh is not affected.
    for (size_t i = 0; i < arayehSize; i++) {
        TEST_ASSERT_EQUAL_CHAR(IS_EMPTY, testCase->_internalProperties.map[i]);
    }

    // test a negative index number.
    state = (testCase->insert)(testCase, -10, &element);

    // assert error code.
    TEST_ASSERT_EQUAL_INT(AA_ARAYEH_WRONG_INDEX, state);

    // ensure arayeh is not affected.
    for (size_t i = 0; i < arayehSize; i++) {
        TEST_ASSERT_EQUAL_CHAR(IS_EMPTY, testCase->_internalProperties.map[i]);
    }

    // free arayeh.
    (testCase->freeArayeh)(&testCase);
}

int main(void)
{
    UnityBegin("unitTestInsert.c");

    RUN_TEST(test_insert);
    RUN_TEST(test_error_out_of_range_index);

    return UnityEnd();
}
