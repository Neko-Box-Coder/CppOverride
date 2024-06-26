#ifndef CO_MACROS_HPP
#define CO_MACROS_HPP

#include "../External/MacroPowerToys/MacroPowerToys.h"

#include <set>
#include <string>

namespace CppOverride
{
    #if 0
    inline std::string Internal_RemoveNewlines(std::string functionSig)
    {
        std::set<int> newlinesToRemove;
        for(int i = 0; i < functionSig.size(); i++)
        {
            switch(functionSig[i])
            {
                case '\n':
                case '\r':
                    newlinesToRemove.insert(i);
                    break;
                default:
                    break;
            }
        }

        for(auto it = newlinesToRemove.rbegin(); it != newlinesToRemove.rend(); it++)
            functionSig.erase(functionSig.begin() + *it);

        return functionSig;
    }
    
    inline std::string Internal_RemoveSpaces(std::string functionSig)
    {
        //Remove any consecutive spaces
        std::set<int> spacesToRemove;
        bool isLastSpace = false;
        for(int i = 0; i < functionSig.size(); i++)
        {
            if(isLastSpace)
            {
                if(functionSig[i] == ' ')
                    spacesToRemove.insert(i);
                else
                    isLastSpace = false;
            }
            else if(functionSig[i] == ' ')
                isLastSpace = true;
        }
        
        //Remove spaces around parentheses and commas
        for(int i = 0; i < functionSig.size(); i++)
        {
            switch(functionSig[i])
            {
                case '(':
                case ')':
                case ',':
                case '*':
                case '&':
                case ':':
                case '<':
                case '>':
                    if(i > 0 && functionSig[i - 1] == ' ')
                        spacesToRemove.insert(i - 1);
                    
                    if(i < functionSig.size() - 1 && functionSig[i + 1] == ' ')
                        spacesToRemove.insert(i + 1);
                    break;
                default:
                    break;
            }
        }
        
        for(auto it = spacesToRemove.rbegin(); it != spacesToRemove.rend(); it++)
            functionSig.erase(functionSig.begin() + *it);

        return functionSig;
    }
    
    inline std::string Internal_Trim(std::string functionSig)
    {
        //Trimming
        int firstCharIndex = -1;
        for(int i = 0; i < functionSig.size(); i++)
        {
            if(functionSig[i] != ' ')
            {
                firstCharIndex = i;
                break;
            }
        }
        
        int lastCharIndex = -1;
        for(int i = functionSig.size() - 1; i >= 0; i--)
        {
            if(functionSig[i] != ' ')
            {
                lastCharIndex = i;
                break;
            }
        }
        
        return functionSig.substr(firstCharIndex, lastCharIndex - firstCharIndex + 1);
    }
    
    //==============================================================================
    //Macros and functions for translating function signature to string
    //==============================================================================
    inline std::string Internal_ProcessFunctionSig(std::string functionSig)
    {
        functionSig = Internal_RemoveNewlines(functionSig);
        functionSig = Internal_Trim(functionSig);
        functionSig = Internal_RemoveSpaces(functionSig);
        return functionSig;
    }
    #endif

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
    
    #define INTERNAL_CO_LOG_CO_OVERRIDE_IMPL 0
    
    #define CO_OVERRIDE_IMPL(overrideObjName, returnType, args) \
    do \
    { \
        int foundIndex = -1; \
        bool overrideArgs = false; \
        bool overrideReturn = false; \
        bool dontReturn = false; \
        bool found =    overrideObjName.Internal_CheckOverride<MPT_REMOVE_PARENTHESIS(returnType)> \
                        ( \
                            __func__, \
                            foundIndex, \
                            overrideReturn, \
                            overrideArgs, \
                            dontReturn \
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
                    overrideObjName.Internal_OverrideArgs(  foundIndex, \
                                                            __func__, \
                                                            !overrideReturn \
                                                            INTERNAL_CO_ARGS(args)); \
                    \
                } \
                \
                if(overrideReturn) \
                { \
                    if(INTERNAL_CO_LOG_CO_OVERRIDE_IMPL) \
                        std::cout << "dontReturn: " << dontReturn << std::endl; \
                    \
                    if(dontReturn) \
                    { \
                        overrideObjName.Internal_CallReturnOverrideResultExpectedAction \
                        ( \
                            __func__, \
                            foundIndex \
                            INTERNAL_CO_ARGS(args) \
                        ); \
                    } \
                    else \
                    { \
                        return  overrideObjName.Internal_OverrideReturn<MPT_REMOVE_PARENTHESIS(returnType)> \
                                ( \
                                    foundIndex, \
                                    __func__ \
                                    INTERNAL_CO_ARGS(args) \
                                ); \
                    } \
                } \
                if(!overrideArgs && !overrideReturn) \
                { \
                    overrideObjName.Internal_CallReturnOverrideResultExpectedAction \
                    ( \
                        __func__, \
                        foundIndex \
                        INTERNAL_CO_ARGS(args) \
                    ); \
                } \
            } \
        } \
    } while(0)

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
    inline CppOverride::OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName) \
    { \
        return OverrideObjName.Internal_CreateOverrideInfo(functionName); \
    } \
    inline void Internal_RemoveOverrideInfo(std::string functionName) \
    { \
        OverrideObjName.Internal_RemoveOverrideInfo(functionName); \
    } \
    inline void ClearAllOverrideInfo() \
    { \
        OverrideObjName.ClearAllOverrideInfo(); \
    } \
    inline CppOverride::Overrider* GetOverrideObject() \
    { \
        return &OverrideObjName; \
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

    #define CO_MOCK_METHOD(...) \
        MPT_OVERLOAD_MACRO(INTERNAL_CO_MOCK_METHOD, __VA_ARGS__)

    #define INTERNAL_CO_MOCK_METHOD_0(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 0 given currently")
    #define INTERNAL_CO_MOCK_METHOD_1(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 1 given currently")
    #define INTERNAL_CO_MOCK_METHOD_2(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 2 given currently")
    #define INTERNAL_CO_MOCK_METHOD_3(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 3 given currently")

    #define INTERNAL_CO_MOCK_METHOD_4(returnType, functionName, argsTypes, functionAppend) \
        inline MPT_REMOVE_PARENTHESIS(returnType) functionName \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST( INTERNAL_POPULATE_ARGS_FIELD(argsTypes) ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            CO_OVERRIDE_IMPL(CurrentOverrideInstance, returnType, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return MPT_REMOVE_PARENTHESIS(returnType)(); \
        }

    #define INTERNAL_CO_MOCK_METHOD_5(functionPrepend, returnType, functionName, argsTypes, functionAppend) \
        MPT_REMOVE_PARENTHESIS(functionPrepend) inline MPT_REMOVE_PARENTHESIS(returnType) functionName \
        ( \
            MPT_REMOVE_PARENTHESIS_IN_LIST( INTERNAL_POPULATE_ARGS_FIELD(argsTypes) ) \
        ) MPT_REMOVE_PARENTHESIS(functionAppend) \
        { \
            CO_OVERRIDE_IMPL(CurrentOverrideInstance, returnType, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return MPT_REMOVE_PARENTHESIS(returnType)(); \
        }
    
    #define INTERNAL_CO_MOCK_METHOD_6(functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend) \
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
            CO_OVERRIDE_IMPL(CurrentOverrideInstance, returnType, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return MPT_REMOVE_PARENTHESIS(returnType)(); \
        }

    #define INTERNAL_CO_MOCK_METHOD_7(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 7 given currently")
    #define INTERNAL_CO_MOCK_METHOD_8(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 8 given currently")
    #define INTERNAL_CO_MOCK_METHOD_9(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 9 given currently")
    #define INTERNAL_CO_MOCK_METHOD_10(...) static_assert(false, "CO_MOCK_METHOD must have 4, 5 or 6 arguments, 10 given currently")
    
    //#if 1
    #ifdef CO_NO_OVERRIDE
        #undef CO_OVERRIDE_IMPL
        #undef CO_SETUP_OVERRIDE
        #undef CO_REMOVE_OVERRIDE_SETUP
        #undef CO_CLEAR_ALL_OVERRIDE_SETUP
        #undef CO_DECLARE_MEMBER_INSTANCE
        #undef CO_DECLARE_INSTANCE
        #undef CO_DECLARE_OVERRIDE_METHODS
        #undef CO_MOCK_METHOD
    
        #define CO_OVERRIDE_IMPL(...)
        #define CO_SETUP_OVERRIDE(...)
        #define CO_REMOVE_OVERRIDE_SETUP(...)
        #define CO_CLEAR_ALL_OVERRIDE_SETUP(...)
        #define CO_DECLARE_MEMBER_INSTANCE(...)
        #define CO_DECLARE_INSTANCE(...)
        #define CO_DECLARE_OVERRIDE_METHODS(...)
        #define CO_MOCK_METHOD(...)
    #endif
}

#endif
