#ifndef CO_MACROS_HPP
#define CO_MACROS_HPP

#include "../External/MacroPowerToys/MacroPowerToys.h"

#include <set>
#include <string>

namespace CppOverride
{
    //-------------------------------------------------------
    //Declaration Macros
    //-------------------------------------------------------
    #define CO_DECLARE_MEMBER_INSTANCE(OverrideObjName) mutable CppOverride::Overrider OverrideObjName
    #define CO_DECLARE_INSTANCE(OverrideObjName) CppOverride::Overrider OverrideObjName
    
    #define CO_DECLARE_OVERRIDE_METHODS(OverrideObjName) \
    inline CppOverride::OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName) const \
    { \
        return (OverrideObjName).Internal_CreateOverrideInfo(functionName); \
    } \
    inline void Internal_RemoveOverrideInfo(std::string functionName) const \
    { \
        (OverrideObjName).Internal_RemoveOverrideInfo(functionName); \
    } \
    inline CppOverride::OverridePassthroughInfoSetter Internal_CreateOverridePassthroughInfo() const \
    { \
        return (OverrideObjName).Internal_CreateOverridePassthroughInfo(); \
    } \
    inline void Internal_ResetPassthroughOverrideData() const \
    { \
        (OverrideObjName).Internal_ResetPassthroughOverrideData(); \
    } \
    inline void Internal_ClearAllOverrideInfo() const \
    { \
        (OverrideObjName).Internal_ClearAllOverrideInfo(); \
    } \
    inline CppOverride::Overrider& Internal_GetOverrideObject() const \
    { \
        return (OverrideObjName); \
    } \
    inline std::vector<CppOverride::FunctionName> Internal_GetFailedExpects() const \
    { \
        return (OverrideObjName).Internal_GetFailedExpects(); \
    } \
    inline std::vector<CppOverride::ResultPtr> \
    Internal_GetOverrideResults(const std::string& functionName) const \
    { \
        return (OverrideObjName).Internal_GetOverrideResults(functionName); \
    } \
    inline std::string Internal_GetFailedReport() const \
    { \
        return (OverrideObjName).Internal_GetFailedReport(); \
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

    #define INTERNAL_CO_INSERT_METHOD_BASE_NO_DEFAULT(overrideObjName, instance, functionPrepend, returnType, functionName, argsTypes, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline MPT_REMOVE_PARENTHESIS(returnType) functionName \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST( INTERNAL_POPULATE_ARGS_FIELD(argsTypes) ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            INTERNAL_CO_INSERT_IMPL(overrideObjName, returnType, instance, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return CppOverride::EarlyReturn<MPT_REMOVE_PARENTHESIS(returnType)>(); \
        }

    #define INTERNAL_CO_INSERT_METHOD_BASE(overrideObjName, instance, functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend) \
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
            INTERNAL_CO_INSERT_IMPL(overrideObjName, returnType, instance, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return CppOverride::EarlyReturn<MPT_REMOVE_PARENTHESIS(returnType)>(); \
        }

    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, functionPrepend, className, argsTypes, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline className \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST( INTERNAL_POPULATE_ARGS_FIELD(argsTypes) ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            CO_INSERT_MEMBER_IMPL_CTOR_DTOR(overrideObjName, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
        }

    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_BASE(overrideObjName, functionPrepend, className, argsTypes, argsDefaults, functionAppend) \
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
            CO_INSERT_MEMBER_IMPL_CTOR_DTOR(overrideObjName, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
        }

    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_BASE(overrideObjName, functionPrepend, className, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline ~ className () \
            MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            CO_INSERT_MEMBER_IMPL_CTOR_DTOR(overrideObjName, ()); \
        }
    
    //-------------------------------------------------------
    //Macro for inserting overriding implementation
    //-------------------------------------------------------

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
        #define INTERNAL_CO_LOG_CO_IMPL 1
    #else
        #define INTERNAL_CO_LOG_CO_IMPL 0
    #endif
    
    #define INTERNAL_CO_IMPL_COMMON_PART_1(overrideObjName, returnType, instance, args) \
    do \
    { \
        int foundIndex = -1; \
        bool overrideArgs = false; \
        bool overrideReturn = false; \
        bool dontReturn = false; \
        bool found = \
            (overrideObjName)   .Internal_GetOverrideObject() \
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
            if(INTERNAL_CO_LOG_CO_IMPL) \
            { \
                std::cout << "foundIndex: " << foundIndex << std::endl; \
                std::cout << "overrideArgs: " << overrideArgs << std::endl; \
                std::cout << "overrideReturn: " << overrideReturn << std::endl; \
                std::cout << "dontReturn: " << dontReturn << std::endl; \
            } \
            \
            if(foundIndex != -1) \
            { \
                bool previousOverrideSuccessful = true; \
                if(overrideArgs) \
                { \
                    previousOverrideSuccessful = \
                        (overrideObjName)   .Internal_GetOverrideObject() \
                                            .Internal_OverrideArgs( foundIndex, \
                                                                    __func__, \
                                                                    !overrideReturn, \
                                                                    (void*)instance \
                                                                    INTERNAL_CO_ARGS(args)); \
                } \
                \
                if(overrideReturn) \
                { \
                    if(INTERNAL_CO_LOG_CO_IMPL) \
                        std::cout << "dontReturn: " << dontReturn << std::endl; \
                    /* If we are not returning, we will need to call the result actions */ \
                    if(dontReturn) \
                    { \
                        if(previousOverrideSuccessful) \
                        { \
                            (overrideObjName)   .Internal_GetOverrideObject() \
                                                .Internal_CallOverrideExpectedAction \
                                                ( \
                                                    __func__, \
                                                    foundIndex, \
                                                    (void*)instance \
                                                    INTERNAL_CO_ARGS(args) \
                                                ); \
                        } \
                    } \
                    else \
                    {
    
    #define INTERNAL_CO_IMPL_NORMAL_PART_2(overrideObjName, returnType, instance, args) \
                        if(!previousOverrideSuccessful) \
                        { \
                            return CppOverride::EarlyReturn<MPT_REMOVE_PARENTHESIS(returnType)>(); \
                        } \
                        /* If we are returning, the result action is called inside */ \
                        return (overrideObjName).Internal_GetOverrideObject() \
                                                .Internal_OverrideReturn<MPT_REMOVE_PARENTHESIS(returnType)> \
                                                ( \
                                                    foundIndex, \
                                                    __func__, \
                                                    (void*)instance \
                                                    INTERNAL_CO_ARGS(args) \
                                                );
    
    #define INTERNAL_CO_IMPL_NO_RETURN_TYPE_PART_2(overrideObjName, instance, args) \
                        if(!previousOverrideSuccessful) \
                            return; \
                        /* If we are returning, the result action is called inside */ \
                        (overrideObjName)   .Internal_GetOverrideObject() \
                                            .Internal_OverrideReturn<MPT_REMOVE_PARENTHESIS(void)> \
                                            ( \
                                                foundIndex, \
                                                __func__, \
                                                (void*)instance \
                                                INTERNAL_CO_ARGS(args) \
                                            ); \
                                            return;

    #define INTERNAL_CO_IMPL_COMMON_PART_3(overrideObjName, returnType, instance, args) \
                    } \
                } \
                if(!overrideArgs && !overrideReturn) \
                { \
                    /* If we are not overriding anything, we still need to call result actions */ \
                    (overrideObjName)   .Internal_GetOverrideObject() \
                                        .Internal_CallOverrideExpectedAction \
                                        ( \
                                            __func__, \
                                            foundIndex, \
                                            (void*)instance \
                                            INTERNAL_CO_ARGS(args) \
                                        ); \
                } \
            } \
        } \
        else \
        { \
            (overrideObjName)   .Internal_GetOverrideObject() \
                                .Internal_CallOverridePassthroughExpectedAction(__func__); \
        } \
    } while(0)

    #define INTERNAL_CO_INSERT_IMPL(overrideObjName, returnType, instance, args) \
        INTERNAL_CO_IMPL_COMMON_PART_1(overrideObjName, returnType, instance, args) \
        INTERNAL_CO_IMPL_NORMAL_PART_2(overrideObjName, returnType, instance, args) \
        INTERNAL_CO_IMPL_COMMON_PART_3(overrideObjName, returnType, instance, args)

    #define CO_INSERT_IMPL(overrideObjName, returnType, args) \
        INTERNAL_CO_INSERT_IMPL(overrideObjName, returnType, nullptr, args)

    #define CO_INSERT_MEMBER_IMPL_CTOR_DTOR(overrideObjName, args) \
        INTERNAL_CO_IMPL_COMMON_PART_1(overrideObjName, void, this, args) \
        INTERNAL_CO_IMPL_NO_RETURN_TYPE_PART_2(overrideObjName, this, args) \
        INTERNAL_CO_IMPL_COMMON_PART_3(overrideObjName, void, this, args)

    #define CO_INSERT_MEMBER_IMPL(overrideObjName, returnType, args) \
        INTERNAL_CO_INSERT_IMPL(overrideObjName, returnType, this, args)


    //-----------------------------------------------------------------
    //Macro for inserting overriding methods
    //-----------------------------------------------------------------
    
    #define CO_INSERT_METHOD(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_INSERT_METHOD, __VA_ARGS__)

    #define CO_INSERT_MEMBER_METHOD(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_INSERT_MEMBER_METHOD, __VA_ARGS__)

    #define CO_INSERT_MEMBER_METHOD_CTOR(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR, __VA_ARGS__)

    #define CO_INSERT_MEMBER_METHOD_DTOR(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR, __VA_ARGS__)

    #define INTERNAL_CO_INSERT_METHOD_0(...) \
        static_assert(false, "CO_INSERT_METHOD must have 4 to 7 arguments, 0 given currently")
    #define INTERNAL_CO_INSERT_METHOD_1(...) \
        static_assert(false, "CO_INSERT_METHOD must have 4 to 7 arguments, 1 given currently")
    #define INTERNAL_CO_INSERT_METHOD_2(...) \
        static_assert(false, "CO_INSERT_METHOD must have 4 to 7 arguments, 2 given currently")
    #define INTERNAL_CO_INSERT_METHOD_3(...) \
        static_assert(false, "CO_INSERT_METHOD must have 4 to 7 arguments, 3 given currently")
    
    #define INTERNAL_CO_INSERT_METHOD_4(overrideObjName, returnType, functionName, argsTypes) \
        INTERNAL_CO_INSERT_METHOD_BASE_NO_DEFAULT(overrideObjName, nullptr, /*functionPrepend*/, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_INSERT_METHOD_5(overrideObjName, returnType, functionName, argsTypes, functionPrepend) \
        INTERNAL_CO_INSERT_METHOD_BASE_NO_DEFAULT(overrideObjName, nullptr, functionPrepend, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_INSERT_METHOD_6(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend) \
        INTERNAL_CO_INSERT_METHOD_BASE_NO_DEFAULT(overrideObjName, nullptr, functionPrepend, returnType, functionName, argsTypes, functionAppend)
        
    #define INTERNAL_CO_INSERT_METHOD_7(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend, argsDefaults) \
        INTERNAL_CO_INSERT_METHOD_BASE(overrideObjName, nullptr, functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend)
    
    #define INTERNAL_CO_INSERT_METHOD_8(...) \
        static_assert(false, "CO_INSERT_METHOD must have 4 to 7 arguments, 8 given currently")
    #define INTERNAL_CO_INSERT_METHOD_9(...) \
        static_assert(false, "CO_INSERT_METHOD must have 4 to 7 arguments, 9 given currently")
    #define INTERNAL_CO_INSERT_METHOD_10(...) \
        static_assert(false, "CO_INSERT_METHOD must have 4 to 7 arguments, 10 given currently")
    

    #define INTERNAL_CO_INSERT_MEMBER_METHOD_0(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD must have 4 to 7 arguments, 0 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_1(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD must have 4 to 7 arguments, 1 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_2(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD must have 4 to 7 arguments, 2 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_3(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD must have 4 to 7 arguments, 3 given currently")
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_4(overrideObjName, returnType, functionName, argsTypes) \
        INTERNAL_CO_INSERT_METHOD_BASE_NO_DEFAULT(overrideObjName, this, /*functionPrepend*/, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_5(overrideObjName, returnType, functionName, argsTypes, functionPrepend) \
        INTERNAL_CO_INSERT_METHOD_BASE_NO_DEFAULT(overrideObjName, this, functionPrepend, returnType, functionName, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_6(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend) \
        INTERNAL_CO_INSERT_METHOD_BASE_NO_DEFAULT(overrideObjName, this, functionPrepend, returnType, functionName, argsTypes, functionAppend)
        
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_7(overrideObjName, returnType, functionName, argsTypes, functionPrepend, functionAppend, argsDefaults) \
        INTERNAL_CO_INSERT_METHOD_BASE(overrideObjName, this, functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_8(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD must have 4 to 7 arguments, 8 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_9(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD must have 4 to 7 arguments, 9 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_10(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD must have 4 to 7 arguments, 10 given currently")
    
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_0(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 0 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_1(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 1 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_2(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 2 given currently")
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_3(overrideObjName, className, argsTypes) \
        INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, /*functionPrepend*/, className, argsTypes, /*functionAppend*/)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_4(overrideObjName, className, argsTypes, functionPrepend) \
        INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, functionPrepend, className, argsTypes, /*functionAppend*/) \
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_5(overrideObjName, className, argsTypes, functionPrepend, functionAppend) \
        INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_BASE_NO_DEFAULT(overrideObjName, functionPrepend, className, argsTypes, functionAppend)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_6(overrideObjName, className, argsTypes, functionPrepend, functionAppend, argsDefaults) \
        INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_BASE(overrideObjName, functionPrepend, className, argsTypes, argsDefaults, functionAppend)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_7(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 7 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_8(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 8 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_9(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 9 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_CTOR_10(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_CTOR must have 3 to 6 arguments, 10 given currently")


    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_0(...) \
        static_assert(false, "CO_OVERRIDE_MEMBED_METHOD_DTOR must have 2 to 4 arguments, 0 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_1(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 1 given currently")
        
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_2(overrideObjName, className) \
        INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_BASE(overrideObjName, /*functionPrepend*/, className, /*functionAppend*/)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_3(overrideObjName, className, functionPrepend) \
        INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_BASE(overrideObjName, functionPrepend, className, /*functionAppend*/)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_4(overrideObjName, className, functionPrepend, functionAppend) \
        INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_BASE(overrideObjName, functionPrepend, className, functionAppend)
    
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_5(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 5 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_6(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 6 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_7(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 7 given currently")
    #define INTERNAL_CO_INSERT_MEMBER_METHOD_DTOR_8(...) \
        static_assert(false, "CO_INSERT_MEMBER_METHOD_DTOR must have 2 to 4 arguments, 8 given currently")


    //-------------------------------------------------------
    //Instruct overrides
    //-------------------------------------------------------
    #define INTERNAL_CO_REF_FUNCTION(scope, functionName) \
        ;(void) (& scope :: functionName) //NOTE: If you get an error here, common reasons are you are passing an overloaded function, missing template arguments, constructor/destructor or unable to reference function name
    
    #define CO_INSTRUCT_NO_REF(overrideObjName, functionName) \
        ;(overrideObjName).Internal_CreateOverrideInfo(#functionName)

    #define CO_REMOVE_INSTRUCT_NO_REF(overrideObjName, functionName)\
        ;(overrideObjName).Internal_RemoveOverrideInfo(#functionName)

    #define CO_GLOBAL /* Empty */
    #define CO_INSTRUCT_REF(overrideObjName, scope, functionName) \
        INTERNAL_CO_REF_FUNCTION(scope, functionName); \
        ;(overrideObjName).Internal_CreateOverrideInfo(#functionName)

    #define CO_REMOVE_INSTRUCT_REF(overrideObjName, scope, functionName) \
        INTERNAL_CO_REF_FUNCTION(scope, functionName); \
        (overrideObjName).Internal_RemoveOverrideInfo(#functionName)

    #define CO_INSTRUCT_PASSTHROUGH(overrideObjName) \
        ;(overrideObjName).Internal_CreateOverridePassthroughInfo()
    
    #define CO_REMOVE_INSTRUCT_PASSTHROUGH(overrideObjName) \
        ;(overrideObjName).Internal_ResetPassthroughOverrideData()
    
    #define CO_CLEAR_ALL_INSTRUCTS(overrideObjName) \
        ;(overrideObjName).Internal_ClearAllOverrideInfo()
    
    //-------------------------------------------------------
    //Validate overrides results
    //-------------------------------------------------------
    #define CO_GET_FAILED_FUNCTIONS(overrideObjName) \
        static_cast<decltype(overrideObjName)>(overrideObjName).Internal_GetFailedExpects()
    #define CO_GET_OVERRIDE_RESULTS(overrideObjName, functionName) \
        static_cast<decltype(overrideObjName)>(overrideObjName).Internal_GetOverrideResults(functionName)
    #define CO_GET_FAILED_REPORT(overrideObjName) \
        static_cast<decltype(overrideObjName)>(overrideObjName).Internal_GetFailedReport()
    
    //NOTE: CO_INSTRUCT_* needs to be defined as there are chained actions.
    //      For CO_DECLARE_*, they need to be there such that things using them can be compiled
    #ifdef CO_NO_OVERRIDE
        //Undefine marcos first
        
        //#undef CO_DECLARE_MEMBER_INSTANCE
        //#undef CO_DECLARE_INSTANCE
        //#undef CO_DECLARE_OVERRIDE_METHODS
        
        #undef CO_INSERT_IMPL
        #undef CO_INSERT_MEMBER_IMPL_CTOR_DTOR
        #undef CO_INSERT_MEMBER_IMPL
        #undef CO_INSERT_METHOD
        #undef CO_INSERT_MEMBER_METHOD
        #undef CO_INSERT_MEMBER_METHOD_CTOR
        #undef CO_INSERT_MEMBER_METHOD_DTOR
        
        //#undef CO_INSTRUCT_NO_REF
        #undef CO_REMOVE_INSTRUCT_NO_REF
        //#undef CO_GLOBAL
        //#undef CO_INSTRUCT_REF
        #undef CO_REMOVE_INSTRUCT_REF
        //#undef CO_INSTRUCT_PASSTHROUGH
        #undef CO_REMOVE_INSTRUCT_PASSTHROUGH
        #undef CO_CLEAR_ALL_INSTRUCTS
        
        #undef CO_GET_FAILED_FUNCTIONS
        #undef CO_GET_OVERRIDE_RESULTS
        #undef CO_GET_FAILED_REPORT

        //Redefine the macros to noop
        
        //#define CO_DECLARE_MEMBER_INSTANCE(...)
        //#define CO_DECLARE_INSTANCE(...)
        //#define CO_DECLARE_OVERRIDE_METHODS(...)
        
        #define CO_INSERT_IMPL(...)
        #define CO_INSERT_MEMBER_IMPL_CTOR_DTOR(...)
        #define CO_INSERT_MEMBER_IMPL(...)
        #define CO_INSERT_METHOD(...)
        #define CO_INSERT_MEMBER_METHOD(...)
        #define CO_INSERT_MEMBER_METHOD_CTOR(...)
        #define CO_INSERT_MEMBER_METHOD_DTOR(...)
        
        //#define CO_INSTRUCT_NO_REF(...)
        #define CO_REMOVE_INSTRUCT(...)
        //#define CO_GLOBAL
        //#define CO_INSTRUCT_REF(...)
        #define CO_REMOVE_INSTRUCT_REF(...)
        //#define CO_INSTRUCT_PASSTHROUGH(...)
        #define CO_REMOVE_INSTRUCT_PASSTHROUGH(...)
        #define CO_CLEAR_ALL_INSTRUCTS(...)
        
        #define CO_GET_FAILED_FUNCTIONS(...) {}
        #define CO_GET_OVERRIDE_RESULTS(...) {}
        #define CO_GET_FAILED_REPORT(...) {}
    #endif
}

#endif
