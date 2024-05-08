#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_SETTER_HPP

#include "../OverrideInfoSetterDeclaration.hpp"
#include "../Internal_OverrideData.hpp"
#include "../StaticAssertFalse.hpp"
#include "../Any.hpp"

#include <iostream>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ReturnDataSetter
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
            friend class OverrideInfoSetter;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            
            //------------------------------------------------------------------------------
            //Methods for setting return data
            //------------------------------------------------------------------------------
            template<typename ReturnType>
            inline OverrideInfoSetter& 
            ReturnsByAction(OverrideInfoSetter& infoSetter, 
                            std::function<void( const std::vector<void*>& args, 
                                                void* out)> returnAction)
            {
                static_assert(  !std::is_same<ReturnType, Any>(), 
                                "You can't return nothing in return action");

                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();

                lastData.ReturnDataActionInfo.DataAction = returnAction;
                lastData.ReturnDataActionInfo.DataActionSet = true;
                lastData.ReturnDataActionInfo.DataType = typeid(ReturnType).hash_code();
                
                if(std::is_reference<ReturnType>())
                    lastData.ReturnDataActionInfo.ReturnReference = true;
                
                return infoSetter;
            }
            
            template<   typename ReturnType,
                        typename = typename std::enable_if<!std::is_same<ReturnType, void>::value>::type,
                        typename = typename std::enable_if<!std::is_reference<ReturnType>::value>::type>
            inline OverrideInfoSetter& Returns(OverrideInfoSetter& infoSetter, ReturnType returnData)
            {
                if(!std::is_same<ReturnType, Any>())
                {
                    Internal_OverrideData& lastData = 
                        CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                    
                    lastData.ReturnDataInfo.Data = new ReturnType(returnData);
                    lastData.ReturnDataInfo.CopyConstructor = 
                        [](void* data) { return new ReturnType(*static_cast<ReturnType*>(data)); };
                    
                    lastData.ReturnDataInfo.Destructor = 
                        [](void* data) { delete static_cast<ReturnType*>(data); }; 
                    
                    lastData.ReturnDataInfo.DataSet = true;
                    lastData.ReturnDataInfo.DataType = typeid(ReturnType).hash_code();
                }
                else
                {
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                                .ReturnDataInfo
                                                                                .ReturnAny = true;
                }
                
                return infoSetter;
            }
            
            template<   typename ReturnType,
                        typename = typename std::enable_if<!std::is_same<ReturnType, void>::value>::type,
                        typename = typename std::enable_if<std::is_reference<ReturnType>::value>::type,
                        typename = typename std::enable_if<std::is_reference<ReturnType>::value>::type>
            inline OverrideInfoSetter& Returns(OverrideInfoSetter& infoSetter, ReturnType returnData)
            {
                if(!std::is_same<ReturnType, Any&>())
                {
                    Internal_OverrideData& lastData = 
                        CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                    
                    lastData.ReturnDataInfo.Data = &returnData;
                    lastData.ReturnDataInfo.CopyConstructor = [](void* data) { return data; };
                    lastData.ReturnDataInfo.Destructor = [](void* data) { }; 
                    lastData.ReturnDataInfo.DataSet = true;
                    lastData.ReturnDataInfo.DataType = typeid(ReturnType).hash_code();
                    lastData.ReturnDataInfo.ReturnReference = true;
                }
                else
                {
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                                .ReturnDataInfo
                                                                                .ReturnAny = true;
                }
                
                return infoSetter;
            }
            
            inline OverrideInfoSetter& ReturnsVoid(OverrideInfoSetter& infoSetter)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ReturnDataInfo.Data = nullptr;
                lastData.ReturnDataInfo.CopyConstructor = [](void* data) { return nullptr; };
                lastData.ReturnDataInfo.Destructor = [](void* data) {}; 
                
                lastData.ReturnDataInfo.DataSet = true;
                lastData.ReturnDataInfo.DataType = typeid(void).hash_code();
                
                return infoSetter;
            }
            
            template<   typename ReturnType,
                        typename = typename std::enable_if<std::is_same<ReturnType, void>::value>::type>
            inline OverrideInfoSetter& Returns(OverrideInfoSetter& infoSetter)
            {
                return ReturnsVoid(infoSetter);
            }
            
        public:
            inline Internal_ReturnDataSetter(OverrideDatas& overrideDatas) : 
                CurrentOverrideDatas(overrideDatas)
            {}
    };
}


#endif