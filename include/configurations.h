/** include/configurations.h
 *
 * This file is a part of:
 * Azadeh Afzar - Arayehsaz (AA-A).
 *
 * Copyright (C) 2020 Mohammad Mahdi Baghbani Pourvahid
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

#ifndef __AA_A_CONFIGURATIONS_H__
#define __AA_A_CONFIGURATIONS_H__

// return codes.
#define AA_ARAYEH_SUCCESS         1
#define AA_ARAYEH_FAILURE         0
#define AA_ARAYEH_WRONG_NEW_SIZE  2
#define AA_ARAYEH_OVERFLOW        3
#define AA_ARAYEH_REALLOC_DENIED  4
#define AA_ARAYEH_WRONG_INDEX     5
#define AA_ARAYEH_END_BIGGER_SIZE 6
#define AA_ARAYEH_WRONG_STEP      7

// map characters.
#define IS_EMPTY  '0'
#define IS_FILLED '1'

// type codes.
#define TYPE_CHAR   1
#define TYPE_SINT   2
#define TYPE_INT    3
#define TYPE_LINT   4
#define TYPE_FLOAT  5
#define TYPE_DOUBLE 6

#endif    //__AA_A_CONFIGURATIONS_H__