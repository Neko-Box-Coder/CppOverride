#ifndef CO_MACROS_HPP
#define CO_MACROS_HPP

#include "../External/MacroPowerToys/MacroPowerToys.h"

#include <set>
#include <string>

namespace CppOverride
{
    //==============================================================================
    //Macro for overriding method implementation
    //==============================================================================
    
    //This macro is to prepend "," if there are any arguments present, otherwise empty
    #define INTERNAL_CO_ARGS(...) \
        MPT_COMPOSE5 \
        ( \
            MPT_DELAYED_CONCAT4, \
            ( \
                INTERNAL_CO_ARGS_, \
                MPT_COMPOSE3 \
                ( \
                    MPT_ARE_ARGS_EMPTY, \
                    __VA_ARGS__ \
                ) \
            ) \
        ) \
        __VA_ARGS__

    #define INTERNAL_CO_ARGS_EMPTY()
    #define INTERNAL_CO_ARGS_NOT_EMPTY(...) , __VA_ARGS__
    
    #if CO_SHOW_OVERRIDE_LOG
        #define INTERNAL_CO_LOG_CO_OVERRIDE_IMPL 1
    #else
        #define INTERNAL_CO_LOG_CO_OVERRIDE_IMPL 0
    #endif
    
    #define INTERNAL_CO_OVERRIDE_IMPL_COMMON_PART_1(overrideObjName, returnType, instance, args) \
    do \
    { \
        int foundIndex = -1; \
        bool overrideArgs = false; \
        bool overrideReturn = false; \
        bool dontReturn = false; \
        bool found = \
            (overrideObjName)   .GetOverrideObject() \
                                .Internal_CheckOverride<MPT_REMOVE_PARENTHESIS(returnType)> \
                                ( \
                                    __func__, \
                                    foundIndex, \
                                    overrideReturn, \
                                    overrideArgs, \
                                    dontReturn, \
                                    (void*)instance \
                                    INTERNAL_CO_ARGS(args) \
                                ); \
        \
        if(found) \
        { \
            if(INTERNAL_CO_LOG_CO_OVERRIDE_IMPL) \
            { \
                std::cout << "foundIndex: " << foundIndex << std::endl; \
                std::cout << "overrideArgs: " << overrideArgs << std::endl; \
                std::cout << "overrideReturn: " << overrideReturn << std::endl; \
                std::cout << "dontReturn: " << dontReturn << std::endl; \
            } \
            \
            if(foundIndex != -1) \
            { \
                if(overrideArgs) \
                { \
                    (overrideObjName)   .GetOverrideObject() \
                                        .Internal_OverrideArgs( foundIndex, \
                                                                __func__, \
                                                                !overrideReturn, \
                                                                (void*)instance \
                                                                INTERNAL_CO_ARGS(args)); \
                    \
                } \
                \
                if(overrideReturn) \
                { \
                    if(INTERNAL_CO_LOG_CO_OVERRIDE_IMPL) \
                        std::cout << "dontReturn: " << dontReturn << std::endl; \
                    /* If we are not returning, we will need to call the result actions */ \
                    if(dontReturn) \
                    { \
                        (overrideObjName)   .GetOverrideObject() \
                                            .Internal_CallReturnOverrideResultExpectedAction \
                                            ( \
                                                __func__, \
                                                foundIndex, \
                                                (void*)instance \
                                                INTERNAL_CO_ARGS(args) \
                                            ); \
                    } \
                    else \
                    {
    
    #define INTERNAL_CO_OVERRIDE_IMPL_NORMAL_PART_2(overrideObjName, returnType, instance, args) \
                        /* If we are returning, the result action is called inside */ \
                        return (overrideObjName).GetOverrideObject() \
                                                .Internal_OverrideReturn<MPT_REMOVE_PARENTHESIS(returnType)> \
                                                ( \
                                                    foundIndex, \
                                                    __func__, \
                                                    (void*)instance \
                                                    INTERNAL_CO_ARGS(args) \
                                                );
    
    #define INTERNAL_CO_OVERRIDE_IMPL_NO_RETURN_TYPE_PART_2(overrideObjName, instance, args) \
                        /* If we are returning, the result action is called inside */ \
                        (overrideObjName)   .GetOverrideObject() \
                                            .Internal_OverrideReturn<MPT_REMOVE_PARENTHESIS(void)> \
                                            ( \
                                                foundIndex, \
                                                __func__, \
                                                (void*)instance \
                                                INTERNAL_CO_ARGS(args) \
                                            ); \
                                            return;

    #define INTERNAL_CO_OVERRIDE_IMPL_COMMON_PART_3(overrideObjName, returnType, instance, args) \
                    } \
                } \
                if(!overrideArgs && !overrideReturn) \
                { \
                    /* If we are not overriding anything, we still need to call result actions */ \
                    (overrideObjName)   .GetOverrideObject() \
                                        .Internal_CallReturnOverrideResultExpectedAction \
                                        ( \
                                            __func__, \
                                            foundIndex, \
                                            (void*)instance \
                                            INTERNAL_CO_ARGS(args) \
                                        ); \
                } \
            } \
        } \
    } while(0)

    #define INTERNAL_CO_OVERRIDE_IMPL_BASE(overrideObjName, returnType, instance, args) \
        INTERNAL_CO_OVERRIDE_IMPL_COMMON_PART_1(overrideObjName, returnType, instance, args) \
        INTERNAL_CO_OVERRIDE_IMPL_NORMAL_PART_2(overrideObjName, returnType, instance, args) \
        INTERNAL_CO_OVERRIDE_IMPL_COMMON_PART_3(overrideObjName, returnType, instance, args)

    #define CO_OVERRIDE_IMPL(overrideObjName, returnType, args) \
        INTERNAL_CO_OVERRIDE_IMPL_BASE(overrideObjName, returnType, nullptr, args)

    #define CO_OVERRIDE_MEMBER_IMPL_CTOR_DTOR(overrideObjName, args) \
        INTERNAL_CO_OVERRIDE_IMPL_COMMON_PART_1(overrideObjName, void, this, args) \
        INTERNAL_CO_OVERRIDE_IMPL_NO_RETURN_TYPE_PART_2(overrideObjName, this, args) \
        INTERNAL_CO_OVERRIDE_IMPL_COMMON_PART_3(overrideObjName, void, this, args)

    #define CO_OVERRIDE_MEMBER_IMPL(overrideObjName, returnType, args) \
        INTERNAL_CO_OVERRIDE_IMPL_BASE(overrideObjName, returnType, this, args)


    //-------------------------------------------------------
    //Setup overrides
    //-------------------------------------------------------

    #define CO_SETUP_OVERRIDE(overrideObjName, functionName) \
        overrideObjName.Internal_CreateOverrideInfo(#functionName)

    #define CO_REMOVE_OVERRIDE_SETUP(overrideObjName, functionName)\
        overrideObjName.Internal_RemoveOverrideInfo(functionName)

    #define CO_CLEAR_ALL_OVERRIDE_SETUP(overrideObjName) \
        overrideObjName.ClearAllOverrideInfo()

    //-------------------------------------------------------
    //Declaration Macros
    //-------------------------------------------------------
    #define CO_DECLARE_MEMBER_INSTANCE(OverrideObjName) mutable CppOverride::Overrider OverrideObjName
    #define CO_DECLARE_INSTANCE(OverrideObjName) CppOverride::Overrider OverrideObjName
    
    #define CO_DECLARE_OVERRIDE_METHODS(OverrideObjName) \
    inline CppOverride::OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName) const \
    { \
        return OverrideObjName.Internal_CreateOverrideInfo(functionName); \
    } \
    inline void Internal_RemoveOverrideInfo(std::string functionName) const \
    { \
        OverrideObjName.Internal_RemoveOverrideInfo(functionName); \
    } \
    inline void ClearAllOverrideInfo() const \
    { \
        OverrideObjName.ClearAllOverrideInfo(); \
    } \
    inline CppOverride::Overrider& GetOverrideObject() const \
    { \
        return OverrideObjName; \
    }
    
    #define INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes) \
        MPT_COMPOSE \
        ( \
            MPT_DELAYED_CONCAT \
            ( \
                MPT_COUNT_TO_, \
                MPT_ARGS_COUNT \
                ( \
                    MPT_REMOVE_PARENTHESIS(argsTypes) \
                ) \
            ), \
            (arg_, /* no suffix */) \
        )

    #define INTERNAL_POPULATE_ARGS_FIELD(argsTypes) \
        MPT_APPEND_LISTS_ITEMS \
        ( \
            MPT_REMOVE_PARENTHESIS(argsTypes), \
            INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes) \
        )

    #define INTERNAL_CO_OVERRIDE_METHOD_BASE_NO_DEFAULT(overrideObjName, instance, functionPrepend, returnType, functionName, argsTypes, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline MPT_REMOVE_PARENTHESIS(returnType) functionName \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST( INTERNAL_POPULATE_ARGS_FIELD(argsTypes) ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            INTERNAL_CO_OVERRIDE_IMPL_BASE(overrideObjName, returnType, instance, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return CppOverride::EarlyReturn<MPT_REMOVE_PARENTHESIS(returnType)>(); \
        }

    #define INTERNAL_CO_OVERRIDE_METHOD_BASE(overrideObjName, instance, functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline MPT_REMOVE_PARENTHESIS(returnType) functionName \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST \
            ( \
                MPT_APPEND_LISTS_ITEMS \
                ( \
                    INTERNAL_POPULATE_ARGS_FIELD(argsTypes), \
                    MPT_REMOVE_PARENTHESIS(argsDefaults) \
                ) \
            ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            INTERNAL_CO_OVERRIDE_IMPL_BASE(overrideObjName, returnType, instance, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return CppOverride::EarlyReturn<MPT_REMOVE_PARENTHESIS(returnType)>(); \
        }

    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, functionPrepend, className, argsTypes, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline className \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST( INTERNAL_POPULATE_ARGS_FIELD(argsTypes) ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            CO_OVERRIDE_MEMBER_IMPL_CTOR_DTOR(overrideObjName, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
        }

    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_BASE(overrideObjName, functionPrepend, className, argsTypes, argsDefaults, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline className \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST \
            ( \
                MPT_APPEND_LISTS_ITEMS \
                ( \
                    INTERNAL_POPULATE_ARGS_FIELD(argsTypes), \
                    MPT_REMOVE_PARENTHESIS(argsDefaults) \
                ) \
            ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            CO_OVERRIDE_MEMBER_IMPL_CTOR_DTOR(overrideObjName, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
        }

    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_BASE(overrideObjName, functionPrepend, className, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline ~ className () \
            MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            CO_OVERRIDE_MEMBER_IMPL_CTOR_DTOR(overrideObjName, ()); \
        }

    //-----------------------------------------------------------------
    //CO_OVERRIDE_METHOD
    //-----------------------------------------------------------------
    
    #define CO_OVERRIDE_METHOD(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_OVERRIDE_METHOD, __VA_ARGS__)

    #define CO_OVERRIDE_MEMBER_METHOD(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_OVERRIDE_MEMBER_METHOD, __VA_ARGS__)

    #define CO_OVERRIDE_MEMBER_METHOD_CTOR(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR, __VA_ARGS__)

    #define CO_OVERRIDE_MEMBER_METHOD_DTOR(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR, __VA_ARGS__)

    //-----------------------------------------------------------------
    //INTERNAL_CO_OVERRIDE_METHOD
    //-----------------------------------------------------------------
    
    #define INTERNAL_CO_OVERRIDE_METHOD_0(...) \
        static_assert(false, "CO_OVERRIDE_METHOD must have 4 to 7 arguments, 0 given currently")
    #define INTERNAL_CO_OVERRIDE_METHOD_1(...) \
        static_assert(false, "CO_OVERRIDE_METHOD must have 4 to 7 arguments, 1 given currently")
    #define INTERNAL_CO_OVERRIDE_METHOD_2(...) \
        static_assert(false, "CO_OVERRIDE_METHOD must have 4 to 7 arguments, 2 given currently")
    #define INTERNAL_CO_OVERRIDE_METHOD_3(...) \
        static_assert(false, "CO_OVERRIDE_METHOD must have 4 to 7 arguments, 3 given currently")
    
    #define INTERNAL_CO_OVERRIDE_METHOD_4(overrideObjName, returnType, functionName, argsTypes) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE_NO_DEFAULT(overrideObjName, nullptr, /*functionPrepend*/, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_OVERRIDE_METHOD_5(overrideObjName, returnType, functionName, argsTypes, functionPrepend) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE_NO_DEFAULT(overrideObjName, nullptr, functionPrepend, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_OVERRIDE_METHOD_6(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE_NO_DEFAULT(overrideObjName, nullptr, functionPrepend, returnType, functionName, argsTypes, functionAppend)
        
    #define INTERNAL_CO_OVERRIDE_METHOD_7(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend, argsDefaults) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE(overrideObjName, nullptr, functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend)
    
    #define INTERNAL_CO_OVERRIDE_METHOD_8(...) \
        static_assert(false, "CO_OVERRIDE_METHOD must have 4 to 7 arguments, 8 given currently")
    #define INTERNAL_CO_OVERRIDE_METHOD_9(...) \
        static_assert(false, "CO_OVERRIDE_METHOD must have 4 to 7 arguments, 9 given currently")
    #define INTERNAL_CO_OVERRIDE_METHOD_10(...) \
        static_assert(false, "CO_OVERRIDE_METHOD must have 4 to 7 arguments, 10 given currently")
    

    //-----------------------------------------------------------------
    //INTERNAL_CO_OVERRIDE_MEMBER_METHOD
    //-----------------------------------------------------------------

    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_0(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD must have 4 to 7 arguments, 0 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_1(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD must have 4 to 7 arguments, 1 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_2(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD must have 4 to 7 arguments, 2 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_3(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD must have 4 to 7 arguments, 3 given currently")
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_4(overrideObjName, returnType, functionName, argsTypes) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE_NO_DEFAULT(overrideObjName, this, /*functionPrepend*/, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_5(overrideObjName, returnType, functionName, argsTypes, functionPrepend) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE_NO_DEFAULT(overrideObjName, this, functionPrepend, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_6(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE_NO_DEFAULT(overrideObjName, this, functionPrepend, returnType, functionName, argsTypes, functionAppend)
        
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_7(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend, argsDefaults) \
        INTERNAL_CO_OVERRIDE_METHOD_BASE(overrideObjName, this, functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_8(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD must have 4 to 7 arguments, 8 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_9(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD must have 4 to 7 arguments, 9 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_10(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD must have 4 to 7 arguments, 10 given currently")
    
    
    //-----------------------------------------------------------------
    //INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR
    //-----------------------------------------------------------------
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_0(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 0 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_1(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 1 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_2(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 2 given currently")
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_3(overrideObjName, className, argsTypes) \
        INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, /*functionPrepend*/, className, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_4(overrideObjName, className, argsTypes, functionPrepend) \
        INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, functionPrepend, className, argsTypes, /*functionAppend*/) \
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_5(overrideObjName, className, argsTypes, functionPrepend, functionAppend) \
        INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, functionPrepend, className, argsTypes, functionAppend)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_6(overrideObjName, className, argsTypes, functionPrepend, functionAppend, argsDefaults) \
        INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_BASE(overrideObjName, functionPrepend, className, argsTypes, argsDefaults, functionAppend)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_7(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 7 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_8(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 8 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_9(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 9 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_CTOR_10(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 10 given currently")
    //-----------------------------------------------------------------
    //INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR
    //-----------------------------------------------------------------
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_0(...) \
        static_assert(false, "CO_OVERRIDE_MEMBED_METHOD_DTOR must have 2 to 4 arguments, 0 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_1(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 1 given currently")
        
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_2(overrideObjName, className) \
        INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_BASE(overrideObjName, /*functionPrepend*/, className, /*functionAppend*/)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_3(overrideObjName, className, functionPrepend) \
        INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_BASE(overrideObjName, functionPrepend, className, /*functionAppend*/)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_4(overrideObjName, className, functionPrepend, functionAppend) \
        INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_BASE(overrideObjName, functionPrepend, className, functionAppend)
    
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_5(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 5 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_6(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 6 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_7(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 7 given currently")
    #define INTERNAL_CO_OVERRIDE_MEMBER_METHOD_DTOR_8(...) \
        static_assert(false, "CO_OVERRIDE_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 8 given currently")
    
    //NOTE: CO_SETUP_OVERRIDE needs to be defined as there are chained actions.
    //      For CO_DECLARE_*, they need to be there such that things using them can be compiled
    #ifdef CO_NO_OVERRIDE
        #undef CO_OVERRIDE_IMPL
        #undef CO_OVERRIDE_MEMBER_IMPL_CTOR_DTOR
        #undef CO_OVERRIDE_MEMBER_IMPL
        //#undef CO_SETUP_OVERRIDE
        #undef CO_REMOVE_OVERRIDE_SETUP
        #undef CO_CLEAR_ALL_OVERRIDE_SETUP
        //#undef CO_DECLARE_MEMBER_INSTANCE
        //#undef CO_DECLARE_INSTANCE
        //#undef CO_DECLARE_OVERRIDE_METHODS
        #undef CO_OVERRIDE_METHOD
        #undef CO_OVERRIDE_MEMBER_METHOD
        #undef CO_OVERRIDE_MEMBER_METHOD_CTOR
        #undef CO_OVERRIDE_MEMBER_METHOD_DTOR
    
        #define CO_OVERRIDE_IMPL(...)
        #define CO_OVERRIDE_MEMBER_IMPL_CTOR_DTOR(...)
        #define CO_OVERRIDE_MEMBER_IMPL(...)
        //#define CO_SETUP_OVERRIDE(...)
        #define CO_REMOVE_OVERRIDE_SETUP(...)
        #define CO_CLEAR_ALL_OVERRIDE_SETUP(...)
        //#define CO_DECLARE_MEMBER_INSTANCE(...)
        //#define CO_DECLARE_INSTANCE(...)
        //#define CO_DECLARE_OVERRIDE_METHODS(...)
        #define CO_OVERRIDE_METHOD(...)
        #define CO_OVERRIDE_MEMBER_METHOD(...)
        #define CO_OVERRIDE_MEMBER_METHOD_CTOR(...)
        #define CO_OVERRIDE_MEMBER_METHOD_DTOR(...)
    #endif
}

#endif
