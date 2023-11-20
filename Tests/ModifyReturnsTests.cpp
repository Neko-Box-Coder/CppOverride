#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./FileFunctions.hpp"
#include "./ClassFunctions.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };

    ssTEST("Return Primitive types Test")
    {
        Rectangle rect(1.5, 1.5);
        
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithoutArgs())
                            .Returns(32);

        CO_OVERRIDE_RETURNS (rect, GetWidth(float))
                            .Returns(5.f);
        
        ssTEST_OUTPUT_ASSERT("int", FuncWithoutArgs() == 32);
    
        ssTEST_OUTPUT_ASSERT("float", rect.GetWidth() == 5.f);
    };
    
    ssTEST("Return Object Test")
    {
        DummyClass assertObject(1, 2.0, "test");
        
        CO_OVERRIDE_RETURNS (OverrideObj, ReturnObjectFunc(int, double, std::string))
                            .Returns(assertObject);
        
        ssTEST_OUTPUT_ASSERT(ReturnObjectFunc(1, 3.0, "test 2") == assertObject);
    };
    
    ssTEST("Return String Test")
    {
        CO_OVERRIDE_RETURNS (OverrideObj, ReturnStringFunc(int))
                            .Returns(std::string("test"));
        
        ssTEST_OUTPUT_ASSERT(ReturnStringFunc(1) == "test");
    };
    
    ssTEST("Return Template Object Test")
    {
        DummyClass assertObject(1, 2.f, "test");
        DummyClass testObject(2, 3.f, "test 2");
        
        CO_OVERRIDE_RETURNS (OverrideObj, ReturnTemplateObjectFunc(T))
                            .Returns(assertObject);
        
        ssTEST_OUTPUT_ASSERT(ReturnTemplateObjectFunc<DummyClass>(testObject) == assertObject);
    };
    
    ssTEST("Return Nothing Test")
    {
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithoutArgs())
                            .Returns(CO_DONT_OVERRIDE_RETURN);

        ssTEST_OUTPUT_ASSERT(FuncWithoutArgs() == -1);
    };
    
    ssTEST("Return By Action Test")
    {
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithoutArgs())
                            .ReturnsByAction<int>
                            (
                                [](const std::vector<void *>& args, void* out)
                                {
                                    (*(int*)(out)) = 10;
                                }
                            );

        ssTEST_OUTPUT_ASSERT(FuncWithoutArgs() == 10);
    };
    
    ssTEST("Return Reference Test")
    {
        int testNum = 1;
        
        CO_OVERRIDE_RETURNS (OverrideObj, ReturnReferenceFunc(int))
                            .ReturnsReference(testNum);

        int& testNum2 = ReturnReferenceFunc(1);

        ssTEST_OUTPUT_ASSERT(testNum == testNum2);
    };
    
    ssTEST("Return Pointer Test")
    {
        int testNum = 1;
        
        CO_OVERRIDE_RETURNS (OverrideObj, ReturnPointerFunc(int))
                            .Returns(&testNum);

        int* testNum2 = ReturnPointerFunc(1);

        ssTEST_OUTPUT_ASSERT(&testNum == testNum2);
    };
    
    ssTEST_END();
    
    return 0;
}
