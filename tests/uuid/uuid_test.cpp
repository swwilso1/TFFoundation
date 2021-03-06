/******************************************************************************

Tectiform Open Source License (TOS)

Copyright (c) 2019 Tectiform Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
SOFTWARE.


******************************************************************************/

#include "TFFoundation.hpp"
#include "gtest/gtest.h"

using namespace TF::Foundation;

TEST(UUIDTest, BasicConstructorTest)
{
    UUID theID;
    String idAsString = theID.toString();
    EXPECT_EQ(idAsString.length(), UUID::uuidStringLength);
}

TEST(UUIDTest, CopyConstructorTest)
{
    UUID theID;
    UUID theNextID(theID);
    EXPECT_EQ(theID, theNextID);
}

UUID testHelper()
{
    return UUID();
}

TEST(UUIDTest, RValueConstructorTest)
{
    UUID theID(testHelper());
    String idAsString = theID.toString();
    EXPECT_EQ(idAsString.length(), UUID::uuidStringLength);
}

TEST(UUIDTest, AssignmentOperatorTest)
{
    UUID theUUID;
    UUID theOtherUUID;
    theOtherUUID = theUUID;
    EXPECT_EQ(theUUID, theOtherUUID);
}

TEST(UUIDTest, RValueAssignementOperatorTest)
{
    UUID theUUID = testHelper();
    EXPECT_EQ(theUUID.toString().length(), UUID::uuidStringLength);
}

TEST(UUIDTest, OperatorEqualTest)
{
    UUID theUUID;
    UUID theOtherUUID;
    theUUID.fromString("7EB28421-0C05-4E4B-8086-3AC98133F016");
    theOtherUUID.fromString("7EB28421-0C05-4E4B-8086-3AC98133F016");
    EXPECT_TRUE(theUUID == theOtherUUID);
}

TEST(UUIDTest, StringOperatorEqualTest)
{
    UUID theUUID;
    theUUID.fromString("4AF5744D-A5F3-4F10-8DDC-1563F6A58796");
    EXPECT_TRUE(theUUID == "4AF5744D-A5F3-4F10-8DDC-1563F6A58796");
    EXPECT_FALSE(theUUID == "12345");
}

TEST(UUIDTest, OperatorNotEqualTest)
{
    UUID theUUID;
    UUID theOtherUUID;
    EXPECT_TRUE(theUUID != theOtherUUID);
    EXPECT_FALSE(theUUID != theUUID);
}

TEST(UUIDTest, StringOperatorNotEqualTest)
{
    UUID theUUID;
    theUUID.fromString("87CA2887-48BD-4310-99B2-46618BE65FFF");
    EXPECT_TRUE(theUUID != "87CA2887-48BD-4310-99B2-46618BE65FFE");
    EXPECT_FALSE(theUUID != "87CA2887-48BD-4310-99B2-46618BE65FFF");
}

TEST(UUIDTest, ToStringTest)
{
    UUID theUUID;
    theUUID.fromString("BB6F37AD-77A3-45ED-A321-115F59CF7856");
    EXPECT_EQ(theUUID.toString(), "BB6F37AD-77A3-45ED-A321-115F59CF7856");
}

TEST(UUIDTest, FromStringTest)
{
    UUID theUUID;
    auto result = theUUID.fromString("foo");
    EXPECT_FALSE(result);
    result = theUUID.fromString("943CD73D-6A1D-4752-8901-0E34A38C824A");
    EXPECT_TRUE(result);
    EXPECT_EQ(theUUID, "943CD73D-6A1D-4752-8901-0E34A38C824A");
}
