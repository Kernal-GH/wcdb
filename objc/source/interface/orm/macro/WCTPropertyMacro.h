/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Property
#define __WCDB_PROPERTY_TYPE(className, propertyName) \
    decltype([className new].propertyName)

#define __WCDB_PROPERTY_IMP(propertyName) +(const WCTProperty &) propertyName;

// Synthesize
#define WCDB_ORM_TYPE_SYNTHESIZE synthesize

// __wcdb_className_synthesize_uniqueID
#define __WCDB_SYNTHESIZE_IMP(className, propertyName, columnName)                                                                                                                                    \
    +(const WCTProperty &) propertyName                                                                                                                                                               \
    {                                                                                                                                                                                                 \
        static const WCTProperty *s_property = new WCTProperty(columnName, WCTColumnBinding::generate<__WCDB_PROPERTY_TYPE(className, propertyName)>(className.class, WCDB_STRINGIFY(propertyName))); \
        WCTBinding::assertNoInheritance(className.class, self);                                                                                                                                       \
        return *s_property;                                                                                                                                                                           \
    }                                                                                                                                                                                                 \
    +(const WCTProperty &) WCDB_ORM_UNIQUE(className, WCDB_ORM_TYPE_SYNTHESIZE)                                                                                                                       \
    {                                                                                                                                                                                                 \
        return className.propertyName;                                                                                                                                                                \
    }
