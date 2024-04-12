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
        
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithoutArgs)
                            .Returns<int>(32);

        CO_SETUP_OVERRIDE   (rect, GetWidth)
                            .Returns<float>(5.f);
        
        ssTEST_OUTPUT_ASSERT("int", FuncWithoutArgs() == 32);
    
        ssTEST_OUTPUT_ASSERT("float", rect.GetWidth() == 5.f);
    };
    
    ssTEST("Return Object Test")
    {
        DummyClass assertObject(1, 2.0, "test");
        
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnObjectFunc)
                            .Returns<DummyClass>(assertObject);
        
        ssTEST_OUTPUT_ASSERT(ReturnObjectFunc(1, 3.0, "test 2") == assertObject);
    };
    
    ssTEST("Return String Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnStringFunc)
                            .Returns<std::string>("test");
        
        ssTEST_OUTPUT_ASSERT(ReturnStringFunc(1) == "test");
    };
    
    ssTEST("Return Template Object Test")
    {
        DummyClass assertObject(1, 2.f, "test");
        DummyClass testObject(2, 3.f, "test 2");
        
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnTemplateObjectFunc)
                            .Returns<DummyClass>(assertObject);
        
        ssTEST_OUTPUT_ASSERT(ReturnTemplateObjectFunc<DummyClass>(testObject) == assertObject);
    };
    
    ssTEST("Return Nothing Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithoutArgs)
                            .Returns<CO_ANY_TYPE>(CO_DONT_OVERRIDE_RETURN);

        ssTEST_OUTPUT_ASSERT(FuncWithoutArgs() == -1);
    };
    
    ssTEST("Return By Action Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithoutArgs)
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
        
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnReferenceFunc)
                            .Returns<int&>(testNum);

        int& testNum2 = ReturnReferenceFunc(1);

        ssTEST_OUTPUT_ASSERT(testNum == testNum2);
    };
    
    ssTEST("Return Pointer Test")
    {
        int testNum = 1;
        
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnPointerFunc)
                            .Returns<int*>(&testNum);

        int* testNum2 = ReturnPointerFunc(1);

        ssTEST_OUTPUT_ASSERT(&testNum == testNum2);
    };
    
    ssTEST_END();
    
    return 0;
}
