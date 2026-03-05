#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //If Condition Should Affect Return
    {
        setup();
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ArgsFunc)
                        .If
                        (
                            [] (void*, 
                                const std::vector<CppOverride::TypedDataInfo>& args) -> bool
                            {
                                if( args.at(0).IsType<int>() && 
                                    *args.at(0).GetTypedDataPtr<int>() == 1 &&
                                    args.at(1).IsType<bool>() && 
                                    *args.at(1).GetTypedDataPtr<bool>() == true &&
                                    args.at(2).IsType<float>() && 
                                    *args.at(2).GetTypedDataPtr<float>() == 2.f)
                                {
                                    return true;
                                }
                                
                                return false;
                            }
                        )
                        .Returns<int>(1)
                        .AssignsResult(result);
    
        DS_ASSERT_EQ(CppOverrideTest::NonConst::ArgsFunc(1, true, 2.f), 1);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        DS_ASSERT_NOT_EQ(CppOverrideTest::NonConst::ArgsFunc(2, false, 3.f), 1);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_ACTION_FAILED);
    }
    
    //If Condition Should Affect Set Args
    {
        setup();
        std::string testString = "";
        float testFloat = 1.f;
        
        CppOverride::ResultPtr result;
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .If
                            (
                                []( void*, 
                                    const std::vector<CppOverride::TypedDataInfo>& args) -> bool
                                {
                                    if( args.at(0).IsType<int>() && 
                                        *args.at(0).GetTypedDataPtr<int>() == 1 &&
                                        args.at(1).IsType<float*>() && 
                                        **args.at(1).GetTypedDataPtr<float*>() == 2.f &&
                                        args.at(2).IsType<std::string&>() && 
                                        *args.at(2).GetTypedDataPtr<std::string&>() == 
                                        "Test String")
                                    {
                                        return true;
                                    }
                                    
                                    return false;
                                }
                            )
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "Test String 2")
                            .AssignsResult(result);
        
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        
        DS_ASSERT_TRUE(testString.empty());
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_ACTION_FAILED);
        
        testString = "Test String";
        testFloat = 2.f;
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        DS_ASSERT_EQ(testString, "Test String 2");
        DS_ASSERT_TRUE(result->LastStatusSucceed());
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
