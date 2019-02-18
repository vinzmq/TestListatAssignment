//
// Created by vmartynu on 17.02.19.
//
#include <limits.h>
#include "gtest/gtest.h"
#include "../../inc/FileManager.h"

class FileManagerTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }
    virtual void TearDown() {
     }
    };

TEST_F(FileManagerTest, isXML){
const std::string xml = "<check></check>";
const std::string xml1 = "<check><g></g></check>";
const std::string xml2 = "<check><1></check></1>";
FileManager fileManager;
EXPECT_EQ(true, fileManager.isXML(xml));
EXPECT_EQ(true, fileManager.isXML(xml1));
EXPECT_EQ(false, fileManager.isXML(xml2));

}