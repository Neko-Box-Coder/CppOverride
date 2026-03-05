#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/TestClasses.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };

    //Return Primitive Type Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc) 
                        .Returns<int>(32)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 32);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Return String Type Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ReturnStringFunc)  
                        .Returns<std::string>("test")
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::ReturnStringFunc(1), "test");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Return Void Early Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AssignArgInternallyFunc)
                        .ReturnsVoid()
                        .Expected();
        std::string testString = "test";
        std::string testString2 = "test2";
        CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        DS_ASSERT_EQ(testString2, "test2");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        
        CO_CLEAR_ALL_INSTRUCTS(OverrideObj);
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AssignArgInternallyFunc)
                        .Returns<void>()
                        .Expected();
        CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        DS_ASSERT_EQ(testString2, "test2");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Return Reference Should Override
    {
        setup();
        int testNum = 1;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ReturnReferenceFunc)
                        .Returns<int&>(testNum)
                        .Expected();
        DS_ASSERT_EQ(&testNum, &CppOverrideTest::NonConst::ReturnReferenceFunc(10));
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        CO_CLEAR_ALL_INSTRUCTS(OverrideObj);
        
        CO_CLEAR_ALL_INSTRUCTS(OverrideObj);
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ReturnReferenceFunc)
                        .ReturnsByAction<int&>
                        (
                            [&](void*, 
                                const std::vector<CppOverride::TypedDataInfo>&, 
                                const CppOverride::TypedInfo& returnInfo) -> CppOverride::TypedDataInfo
                            {
                                if(returnInfo.IsType<int&>())
                                {
                                    return CppOverride  ::TypedDataInfo()
                                                        .CreateReference<int&>(&testNum);
                                }
                                
                                return CppOverride::TypedDataInfo();
                            }
                        )
                        .Expected();
        
        DS_ASSERT_EQ(&testNum, &CppOverrideTest::NonConst::ReturnReferenceFunc(10));
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        CO_CLEAR_ALL_INSTRUCTS(OverrideObj);
    }
    
    //Return Pointer Should Override
    {
        setup();
        int testNum = 1;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ReturnPointerFunc)
                        .Returns<int*>(&testNum)
                        .Expected();
        
        DS_ASSERT_EQ(&testNum, CppOverrideTest::NonConst::ReturnPointerFunc(1));
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Return Nothing Should Not Override Return Value
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .Returns<CO_ANY_TYPE>(CO_DONT_OVERRIDE_RETURN)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), -1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Return Type Not Matching Should Not Override Return Value
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .Returns<float>(2.f)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), -1);
        DS_ASSERT_EQ(CO_GET_FAILED_FUNCTIONS(OverrideObj).size(), 1);
    }
    
    //Return Object Should Override
    {
        setup();
        CppOverrideTest::TestClass assertObject(1, 2.0, "test");
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst::Object, ReturnObjectFunc)
                        .Returns<CppOverrideTest::TestClass>(assertObject)
                        .Expected();
        
        using namespace CppOverrideTest::NonConst::Object;
        DS_ASSERT_TRUE(ReturnObjectFunc(1, 3.0, "test 2") == assertObject);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Return Template Object Should Override
    {
        setup();
        CppOverrideTest::TestClass assertObject(1, 2.f, "test");
        CppOverrideTest::TestClass testObject(2, 3.f, "test 2");
        CO_INSTRUCT_REF 
        (
            OverrideObj, 
            CppOverrideTest::NonConst::Template, 
            TemplateReturnFunc<CppOverrideTest::TestClass>
        )
        .Returns<CppOverrideTest::TestClass>(assertObject)
        .Expected();
        
        using namespace CppOverrideTest::NonConst::Template;
        DS_ASSERT_TRUE(TemplateReturnFunc<CppOverrideTest::TestClass>(testObject) == assertObject);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Return By Action Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .ReturnsByAction<int>
                        (
                            []( void*, 
                                const std::vector<CppOverride::TypedDataInfo>&, 
                                const CppOverride::TypedInfo& returnInfo) -> CppOverride::TypedDataInfo
                            {
                                if(returnInfo.IsType<int>())
                                    return CppOverride::TypedDataInfo().CreateValue<int>(10);
                                return CppOverride::TypedDataInfo();
                            }
                        )
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 10);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
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
