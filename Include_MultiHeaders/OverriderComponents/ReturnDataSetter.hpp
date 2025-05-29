#ifndef CO_OVERRIDER_COMPONENTS_RETURN_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_RETURN_DATA_SETTER_HPP

#include "../OverrideInfoSetterDeclaration.hpp"
#include "../OverrideData.hpp"
#include "../Any.hpp"

#include <iostream>
#include <unordered_map>

namespace CppOverride
{
    struct ReturnDataSetter
    {
        OverrideDatas& CurrentOverrideDatas;
        
        //------------------------------------------------------------------------------
        //Methods for setting return data
        //------------------------------------------------------------------------------
        template<typename ReturnType>
        inline OverrideInfoSetter& 
        ReturnsByAction(OverrideInfoSetter& infoSetter, 
                        std::function<void( void* instance,
                                            const std::vector<void*>& args, 
                                            void* out)> returnAction)
        {
            static_assert(  !std::is_same<ReturnType, Any>(), 
                            "You can't return nothing in return action");

            OverrideData& lastData = 
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();

            lastData.CurrentReturnDataActionInfo.DataAction = returnAction;
            lastData.CurrentReturnDataActionInfo.DataActionSet = true;
            lastData.CurrentReturnDataActionInfo.DataType = typeid(ReturnType).hash_code();
            
            if(std::is_reference<ReturnType>())
                lastData.CurrentReturnDataActionInfo.ReturnReference = true;
            
            return infoSetter;
        }
        
        template
        <
            typename ReturnType,
            typename std::enable_if<!std::is_same<ReturnType, void>::value, bool>::type = true,
            typename std::enable_if<!std::is_reference<ReturnType>::value, bool>::type = true
        >
        inline OverrideInfoSetter& Returns( OverrideInfoSetter& infoSetter, 
                                            ReturnType returnData)
        {
            if(!std::is_same<ReturnType, Any>())
            {
                OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.CurrentReturnDataInfo.Data = 
                    std::shared_ptr<void>(  new ReturnType(returnData), 
                                            [](void* p){ delete static_cast<ReturnType*>(p); });
                lastData.CurrentReturnDataInfo.DataSet = true;
                lastData.CurrentReturnDataInfo.DataType = typeid(ReturnType).hash_code();
            }
            else
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                    .back()
                                    .CurrentReturnDataInfo
                                    .ReturnAny = true;
            }
            
            return infoSetter;
        }
        
        template
        <
            typename ReturnType,
            typename std::enable_if<!std::is_same<ReturnType, void>::value, bool>::type = true,
            typename std::enable_if<std::is_reference<ReturnType>::value, bool>::type = true
        >
        inline OverrideInfoSetter& Returns( OverrideInfoSetter& infoSetter, 
                                            ReturnType returnData)
        {
            if(!std::is_same<ReturnType, Any&>())
            {
                OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.CurrentReturnDataInfo.Data = 
                    std::shared_ptr<void>(&returnData, [](...){});
                lastData.CurrentReturnDataInfo.DataSet = true;
                lastData.CurrentReturnDataInfo.DataType = typeid(ReturnType).hash_code();
                lastData.CurrentReturnDataInfo.ReturnReference = true;
            }
            else
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                    .back()
                                    .CurrentReturnDataInfo
                                    .ReturnAny = true;
            }
            
            return infoSetter;
        }
        
        inline OverrideInfoSetter& ReturnsVoid(OverrideInfoSetter& infoSetter)
        {
            OverrideData& lastData = 
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
            
            lastData.CurrentReturnDataInfo.Data = nullptr;
            lastData.CurrentReturnDataInfo.DataSet = true;
            lastData.CurrentReturnDataInfo.DataType = typeid(void).hash_code();
            
            return infoSetter;
        }
        
        template
        <
            typename ReturnType,
            typename std::enable_if<std::is_same<ReturnType, void>::value, bool>::type = true
        >
        inline OverrideInfoSetter& Returns(OverrideInfoSetter& infoSetter)
        {
            return ReturnsVoid(infoSetter);
        }
        
        inline ReturnDataSetter(OverrideDatas& overrideDatas) : 
            CurrentOverrideDatas(overrideDatas)
        {}
    };
}


#endif
