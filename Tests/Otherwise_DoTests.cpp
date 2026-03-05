#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/TestClasses.hpp"
#include "./Components/Shapes.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //WhenCalledWith Condition Not Met Should Trigger Otherwise_Do For Return
    {
        setup();
        CppOverrideTest::Rectangle rect(1.5, 1.5);
        bool otherwiseDoCalled = false;
        CO_INSTRUCT_NO_REF  (rect, GetWidth)
                            .WhenCalledWith(2.f)
                            .Returns<float>(6.f)
                            .Otherwise_Do
                            (
                                [&otherwiseDoCalled](...)
                                {
                                    otherwiseDoCalled = true;
                                }
                            );
        rect.GetWidth(2.f);
        DS_ASSERT_FALSE(otherwiseDoCalled);
        
        rect.GetWidth(3.f);
        DS_ASSERT_TRUE(otherwiseDoCalled);
    }
    
    //If Condition Not Met Should Trigger Otherwise_Do For Return
    {
        setup();
        CppOverrideTest::Rectangle rect(1.5, 1.5);
        bool otherwiseDoCalled = false;
        CO_INSTRUCT_NO_REF  (rect, GetWidth)
                            .If
                            (
                                [](void*, const std::vector<CppOverride::TypedDataInfo>& args)
                                {
                                    return  args[0].IsType<float>() && 
                                            (*args[0].GetTypedDataPtr<float>() == 2.f);
                                }
                            )
                            .Returns<float>(6.f)
                            .Otherwise_Do
                            (
                                [&otherwiseDoCalled](...)
                                {
                                    otherwiseDoCalled = true;
                                }
                            );
        rect.GetWidth(2.f);
        DS_ASSERT_FALSE(otherwiseDoCalled);
        
        rect.GetWidth(3.f);
        DS_ASSERT_TRUE(otherwiseDoCalled);
    }
    
    //WhenCalledWith Condition Not Met Should Trigger Otherwise_Do For SetArgs
    {
        setup();
        bool otherwiseDoCalled = false;
        std::string testString;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, ConstArgsAndArgsToSetFunc)
                        .WhenCalledWith(1, 2.f, CO_ANY)
                        .SetArgs<   CO_ANY_TYPE, 
                                    CO_ANY_TYPE, 
                                    std::string&>(  CO_DONT_SET, 
                                                    CO_DONT_SET, 
                                                    "test")
                        .Otherwise_Do
                        (
                            [&otherwiseDoCalled](...)
                            {
                                otherwiseDoCalled = true;
                            }
                        );
        CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(1, 2.f, testString);
        DS_ASSERT_FALSE(otherwiseDoCalled);
        
        CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(2, 3.f, testString);
        DS_ASSERT_TRUE(otherwiseDoCalled);
    }
    
    //If Condition Not Met Should Trigger Otherwise_Do For SetArgs
    {
        setup();
        bool otherwiseDoCalled = false;
        std::string testString;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, ConstArgsAndArgsToSetFunc)
                        .If
                        (
                            [](void*, const std::vector<CppOverride::TypedDataInfo>& args)
                            {
                                return  args.at(0).IsType<int>() && 
                                        (*args.at(0).GetTypedDataPtr<int>() == 1) && 
                                        args.at(1).IsType<float>() && 
                                        (*args.at(1).GetTypedDataPtr<float>() == 2.f);
                            }
                        )
                        .SetArgs<   CO_ANY_TYPE, 
                                    CO_ANY_TYPE, 
                                    std::string&>(  CO_DONT_SET, 
                                                    CO_DONT_SET, 
                                                    "test")
                        .Otherwise_Do
                        (
                            [&otherwiseDoCalled](...)
                            {
                                otherwiseDoCalled = true;
                            }
                        );
        CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(1, 2.f, testString);
        DS_ASSERT_FALSE(otherwiseDoCalled);
        
        CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(2, 3.f, testString);
        DS_ASSERT_TRUE(otherwiseDoCalled);
    }

    return {};
}

int main(int, char**)
{
    try
    {
        TestMain().DS_TRY_ACT(std::cout << DS_TMP_ERROR.ToString() << std::endl; return 1);
        return 0;
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    return 1;
}
