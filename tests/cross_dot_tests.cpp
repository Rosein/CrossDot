#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "cross_dot.h"
#include <memory>

using namespace testing;

class MockInput: public Input
{
    public:
    MOCK_METHOD(int, enterInput, (), (override));
};

class DisplayFixture : public Test
{
    protected:
    Display display;
};

TEST_F(DisplayFixture, SetDisplayChar)
{
    display.setXat(1);

    EXPECT_EQ('X',display.getBoard()[0]);
}

TEST_F(DisplayFixture, GivenBoardWhenSetXAtOneAndOAtFiveThenExpectBoardWithTwoPositionsOccupied)
{
    display.setXat(1);
    display.setOat(5);

    EXPECT_EQ("X...O....",display.getBoard());
}

TEST_F(DisplayFixture, IfDrawReturnsStringWithNewLines)
{
  EXPECT_EQ(std::string("...\n...\n...\n"),display.draw());
};


TEST(CrossDotGameTest, GivenStraightColumnOfXAndOWhenRunPlayThenExpectStatusXWin)
{
    std::shared_ptr<MockInput> mock {std::make_shared<MockInput>()};

    std::shared_ptr<Input> input { mock};
    Controller controller(input);

    EXPECT_CALL(*mock, enterInput()).Times(5)
            .WillOnce(Return(1))
            .WillOnce(Return(4))
            .WillOnce(Return(2))
            .WillOnce(Return(5))
            .WillOnce(Return(3));
    
    auto status = controller.play();

    EXPECT_EQ(status, Status::XWon);
}

TEST_F(DisplayFixture, TestIfInputChangesBoardStringToThreeXesAndTwoOs)
{
    std::shared_ptr<MockInput> mock {std::make_shared<MockInput>()};

    std::shared_ptr<Input> input { mock};
    Controller controller(input);
    
    EXPECT_CALL(*mock, enterInput()).Times(5)
            .WillOnce(Return(1))
            .WillOnce(Return(4))
            .WillOnce(Return(2))
            .WillOnce(Return(5))
            .WillOnce(Return(3));
    
    controller.play();
    
    std::string testString{"XXXOO...."};
    EXPECT_EQ(testString, controller.getDisplay().getBoard());
}