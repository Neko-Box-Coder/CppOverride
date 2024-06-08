//=================================================================
//./Include_MultiHeaders/CppOverride.hpp
//=================================================================
#ifndef CO_CPP_OVERRIDE_HPP
#define CO_CPP_OVERRIDE_HPP


//=================================================================
//./Include_MultiHeaders/CppOverrideInstance.hpp
//=================================================================
#ifndef CO_CPP_OVERRIDE_INSTANCE_HPP
#define CO_CPP_OVERRIDE_INSTANCE_HPP

//=================================================================
//./Include_MultiHeaders/OverrideInfoSetterDeclaration.hpp
//=================================================================
#ifndef CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP
#define CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP

//=================================================================
//./External/MacroPowerToys/MacroPowerToys.h
//=================================================================
//NOTE: Up to 99 arguments

//=================================================================
//./External/MacroPowerToys/Miscellaneous.h
//=================================================================
#ifndef MPT_MISCELLANEOUS_H
#define MPT_MISCELLANEOUS_H

#define MPT_CONCAT( A, B ) A ## B
#define MPT_CONCAT2( A, B ) A ## B
#define MPT_CONCAT3( A, B ) A ## B
#define MPT_CONCAT4( A, B ) A ## B
#define MPT_CONCAT5( A, B ) A ## B
#define MPT_CONCAT6( A, B ) A ## B
#define MPT_CONCAT7( A, B ) A ## B
#define MPT_CONCAT8( A, B ) A ## B
#define MPT_CONCAT9( A, B ) A ## B
#define MPT_CONCAT10( A, B ) A ## B
#define MPT_CONCAT11( A, B ) A ## B
#define MPT_CONCAT12( A, B ) A ## B
#define MPT_CONCAT13( A, B ) A ## B
#define MPT_CONCAT14( A, B ) A ## B
#define MPT_CONCAT15( A, B ) A ## B
#define MPT_CONCAT16( A, B ) A ## B
#define MPT_CONCAT17( A, B ) A ## B
#define MPT_CONCAT18( A, B ) A ## B
#define MPT_CONCAT19( A, B ) A ## B
#define MPT_CONCAT20( A, B ) A ## B

#define MPT_COMPOSE( A, B ) A B
#define MPT_COMPOSE2( A, B ) A B
#define MPT_COMPOSE3( A, B ) A B
#define MPT_COMPOSE4( A, B ) A B
#define MPT_COMPOSE5( A, B ) A B
#define MPT_COMPOSE6( A, B ) A B
#define MPT_COMPOSE7( A, B ) A B
#define MPT_COMPOSE8( A, B ) A B
#define MPT_COMPOSE9( A, B ) A B
#define MPT_COMPOSE10( A, B ) A B
#define MPT_COMPOSE11( A, B ) A B
#define MPT_COMPOSE12( A, B ) A B
#define MPT_COMPOSE13( A, B ) A B
#define MPT_COMPOSE14( A, B ) A B
#define MPT_COMPOSE15( A, B ) A B
#define MPT_COMPOSE16( A, B ) A B
#define MPT_COMPOSE17( A, B ) A B
#define MPT_COMPOSE18( A, B ) A B
#define MPT_COMPOSE19( A, B ) A B
#define MPT_COMPOSE20( A, B ) A B

#define MPT_DELAYED_CONCAT(A, B) MPT_COMPOSE(MPT_CONCAT, (A, B))
#define MPT_DELAYED_CONCAT2(A, B) MPT_COMPOSE2(MPT_CONCAT2, (A, B))
#define MPT_DELAYED_CONCAT3(A, B) MPT_COMPOSE3(MPT_CONCAT3, (A, B))
#define MPT_DELAYED_CONCAT4(A, B) MPT_COMPOSE4(MPT_CONCAT4, (A, B))
#define MPT_DELAYED_CONCAT5(A, B) MPT_COMPOSE5(MPT_CONCAT5, (A, B))
#define MPT_DELAYED_CONCAT6(A, B) MPT_COMPOSE6(MPT_CONCAT6, (A, B))
#define MPT_DELAYED_CONCAT7(A, B) MPT_COMPOSE7(MPT_CONCAT7, (A, B))
#define MPT_DELAYED_CONCAT8(A, B) MPT_COMPOSE8(MPT_CONCAT8, (A, B))
#define MPT_DELAYED_CONCAT9(A, B) MPT_COMPOSE9(MPT_CONCAT9, (A, B))
#define MPT_DELAYED_CONCAT10(A, B) MPT_COMPOSE10(MPT_CONCAT10, (A, B))
#define MPT_DELAYED_CONCAT11(A, B) MPT_COMPOSE11(MPT_CONCAT11, (A, B))
#define MPT_DELAYED_CONCAT12(A, B) MPT_COMPOSE12(MPT_CONCAT12, (A, B))
#define MPT_DELAYED_CONCAT13(A, B) MPT_COMPOSE13(MPT_CONCAT13, (A, B))
#define MPT_DELAYED_CONCAT14(A, B) MPT_COMPOSE14(MPT_CONCAT14, (A, B))
#define MPT_DELAYED_CONCAT15(A, B) MPT_COMPOSE15(MPT_CONCAT15, (A, B))
#define MPT_DELAYED_CONCAT16(A, B) MPT_COMPOSE16(MPT_CONCAT16, (A, B))
#define MPT_DELAYED_CONCAT17(A, B) MPT_COMPOSE17(MPT_CONCAT17, (A, B))
#define MPT_DELAYED_CONCAT18(A, B) MPT_COMPOSE18(MPT_CONCAT18, (A, B))
#define MPT_DELAYED_CONCAT19(A, B) MPT_COMPOSE19(MPT_CONCAT19, (A, B))
#define MPT_DELAYED_CONCAT20(A, B) MPT_COMPOSE20(MPT_CONCAT20, (A, B))

#define INTERNAL_MPT_REMOVE_PARENTHESIS( ... ) __VA_ARGS__
#define MPT_REMOVE_PARENTHESIS( ... ) INTERNAL_MPT_REMOVE_PARENTHESIS __VA_ARGS__

#define INTERNAL_MPT_DELAY( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY2( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY3( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY4( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY5( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY6( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY7( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY8( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY9( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY10( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY11( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY12( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY13( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY14( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY15( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY16( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY17( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY18( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY19( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY20( ... ) __VA_ARGS__
#define INTERNAL_MPT_DELAY_ONE( x ) x

#define MPT_DELAY( ... ) __VA_ARGS__
#define MPT_DELAY2( ... ) __VA_ARGS__
#define MPT_DELAY3( ... ) __VA_ARGS__
#define MPT_DELAY4( ... ) __VA_ARGS__
#define MPT_DELAY5( ... ) __VA_ARGS__
#define MPT_DELAY6( ... ) __VA_ARGS__
#define MPT_DELAY7( ... ) __VA_ARGS__
#define MPT_DELAY8( ... ) __VA_ARGS__
#define MPT_DELAY9( ... ) __VA_ARGS__
#define MPT_DELAY10( ... ) __VA_ARGS__
#define MPT_DELAY11( ... ) __VA_ARGS__
#define MPT_DELAY12( ... ) __VA_ARGS__
#define MPT_DELAY13( ... ) __VA_ARGS__
#define MPT_DELAY14( ... ) __VA_ARGS__
#define MPT_DELAY15( ... ) __VA_ARGS__
#define MPT_DELAY16( ... ) __VA_ARGS__
#define MPT_DELAY17( ... ) __VA_ARGS__
#define MPT_DELAY18( ... ) __VA_ARGS__
#define MPT_DELAY19( ... ) __VA_ARGS__
#define MPT_DELAY20( ... ) __VA_ARGS__
#define MPT_DELAY_ONE( x ) x


#define MPT_DELAYED_COMPOSE(macro, args) MPT_DELAYED_COMPOSE( macro, MPT_DELAY(args) )
#define MPT_DELAYED_COMPOSE2(macro, args) MPT_DELAYED_COMPOSE2( macro, MPT_DELAY2(args) )
#define MPT_DELAYED_COMPOSE3(macro, args) MPT_DELAYED_COMPOSE3( macro, MPT_DELAY3(args) )
#define MPT_DELAYED_COMPOSE4(macro, args) MPT_DELAYED_COMPOSE4( macro, MPT_DELAY4(args) )
#define MPT_DELAYED_COMPOSE5(macro, args) MPT_DELAYED_COMPOSE5( macro, MPT_DELAY5(args) )
#define MPT_DELAYED_COMPOSE6(macro, args) MPT_DELAYED_COMPOSE6( macro, MPT_DELAY6(args) )
#define MPT_DELAYED_COMPOSE7(macro, args) MPT_DELAYED_COMPOSE7( macro, MPT_DELAY7(args) )
#define MPT_DELAYED_COMPOSE8(macro, args) MPT_DELAYED_COMPOSE8( macro, MPT_DELAY8(args) )
#define MPT_DELAYED_COMPOSE9(macro, args) MPT_DELAYED_COMPOSE9( macro, MPT_DELAY9(args) )
#define MPT_DELAYED_COMPOSE10(macro, args) MPT_DELAYED_COMPOSE10( macro, MPT_DELAY10(args) )
#define MPT_DELAYED_COMPOSE11(macro, args) MPT_DELAYED_COMPOSE11( macro, MPT_DELAY11(args) )
#define MPT_DELAYED_COMPOSE12(macro, args) MPT_DELAYED_COMPOSE12( macro, MPT_DELAY12(args) )
#define MPT_DELAYED_COMPOSE13(macro, args) MPT_DELAYED_COMPOSE13( macro, MPT_DELAY13(args) )
#define MPT_DELAYED_COMPOSE14(macro, args) MPT_DELAYED_COMPOSE14( macro, MPT_DELAY14(args) )
#define MPT_DELAYED_COMPOSE15(macro, args) MPT_DELAYED_COMPOSE15( macro, MPT_DELAY15(args) )
#define MPT_DELAYED_COMPOSE16(macro, args) MPT_DELAYED_COMPOSE16( macro, MPT_DELAY16(args) )
#define MPT_DELAYED_COMPOSE17(macro, args) MPT_DELAYED_COMPOSE17( macro, MPT_DELAY17(args) )
#define MPT_DELAYED_COMPOSE18(macro, args) MPT_DELAYED_COMPOSE18( macro, MPT_DELAY18(args) )
#define MPT_DELAYED_COMPOSE19(macro, args) MPT_DELAYED_COMPOSE19( macro, MPT_DELAY19(args) )
#define MPT_DELAYED_COMPOSE20(macro, args) MPT_DELAYED_COMPOSE20( macro, MPT_DELAY20(args) )

#define INTERNAL_MPT_CONCAT( A, B ) A ## B
#define INTERNAL_MPT_CONCAT2( A, B ) A ## B
#define INTERNAL_MPT_CONCAT3( A, B ) A ## B
#define INTERNAL_MPT_CONCAT4( A, B ) A ## B
#define INTERNAL_MPT_CONCAT5( A, B ) A ## B
#define INTERNAL_MPT_CONCAT6( A, B ) A ## B
#define INTERNAL_MPT_CONCAT7( A, B ) A ## B
#define INTERNAL_MPT_CONCAT8( A, B ) A ## B
#define INTERNAL_MPT_CONCAT9( A, B ) A ## B
#define INTERNAL_MPT_CONCAT10( A, B ) A ## B
#define INTERNAL_MPT_CONCAT11( A, B ) A ## B
#define INTERNAL_MPT_CONCAT12( A, B ) A ## B
#define INTERNAL_MPT_CONCAT13( A, B ) A ## B
#define INTERNAL_MPT_CONCAT14( A, B ) A ## B
#define INTERNAL_MPT_CONCAT15( A, B ) A ## B
#define INTERNAL_MPT_CONCAT16( A, B ) A ## B
#define INTERNAL_MPT_CONCAT17( A, B ) A ## B
#define INTERNAL_MPT_CONCAT18( A, B ) A ## B
#define INTERNAL_MPT_CONCAT19( A, B ) A ## B
#define INTERNAL_MPT_CONCAT20( A, B ) A ## B

#define INTERNAL_MPT_SELECT( NAME, NUM ) INTERNAL_MPT_CONCAT( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT2( NAME, NUM ) INTERNAL_MPT_CONCAT2( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT3( NAME, NUM ) INTERNAL_MPT_CONCAT3( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT4( NAME, NUM ) INTERNAL_MPT_CONCAT4( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT5( NAME, NUM ) INTERNAL_MPT_CONCAT5( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT6( NAME, NUM ) INTERNAL_MPT_CONCAT6( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT7( NAME, NUM ) INTERNAL_MPT_CONCAT7( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT8( NAME, NUM ) INTERNAL_MPT_CONCAT8( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT9( NAME, NUM ) INTERNAL_MPT_CONCAT9( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT10( NAME, NUM ) INTERNAL_MPT_CONCAT10( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT11( NAME, NUM ) INTERNAL_MPT_CONCAT11( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT12( NAME, NUM ) INTERNAL_MPT_CONCAT12( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT13( NAME, NUM ) INTERNAL_MPT_CONCAT13( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT14( NAME, NUM ) INTERNAL_MPT_CONCAT14( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT15( NAME, NUM ) INTERNAL_MPT_CONCAT15( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT16( NAME, NUM ) INTERNAL_MPT_CONCAT16( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT17( NAME, NUM ) INTERNAL_MPT_CONCAT17( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT18( NAME, NUM ) INTERNAL_MPT_CONCAT18( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT19( NAME, NUM ) INTERNAL_MPT_CONCAT19( NAME ## _, NUM )
#define INTERNAL_MPT_SELECT20( NAME, NUM ) INTERNAL_MPT_CONCAT20( NAME ## _, NUM )

#define INTERNAL_MPT_DELAYED_SELECT( NAME, NUM ) INTERNAL_MPT_SELECT( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT2( NAME, NUM ) INTERNAL_MPT_SELECT2( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT3( NAME, NUM ) INTERNAL_MPT_SELECT3( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT4( NAME, NUM ) INTERNAL_MPT_SELECT4( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT5( NAME, NUM ) INTERNAL_MPT_SELECT5( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT6( NAME, NUM ) INTERNAL_MPT_SELECT6( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT7( NAME, NUM ) INTERNAL_MPT_SELECT7( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT8( NAME, NUM ) INTERNAL_MPT_SELECT8( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT9( NAME, NUM ) INTERNAL_MPT_SELECT9( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT10( NAME, NUM ) INTERNAL_MPT_SELECT10( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT11( NAME, NUM ) INTERNAL_MPT_SELECT11( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT12( NAME, NUM ) INTERNAL_MPT_SELECT12( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT13( NAME, NUM ) INTERNAL_MPT_SELECT13( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT14( NAME, NUM ) INTERNAL_MPT_SELECT14( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT15( NAME, NUM ) INTERNAL_MPT_SELECT15( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT16( NAME, NUM ) INTERNAL_MPT_SELECT16( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT17( NAME, NUM ) INTERNAL_MPT_SELECT17( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT18( NAME, NUM ) INTERNAL_MPT_SELECT18( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT19( NAME, NUM ) INTERNAL_MPT_SELECT19( NAME, NUM )
#define INTERNAL_MPT_DELAYED_SELECT20( NAME, NUM ) INTERNAL_MPT_SELECT20( NAME, NUM )

#define INTERNAL_MPT_COMPOSE( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE2( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE3( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE4( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE5( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE6( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE7( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE8( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE9( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE10( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE11( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE12( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE13( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE14( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE15( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE16( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE17( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE18( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE19( macro, args ) macro args
#define INTERNAL_MPT_COMPOSE20( macro, args ) macro args


#define INTERNAL_MPT_DELAYED_COMPOSE( macro, args ) INTERNAL_MPT_COMPOSE( macro, INTERNAL_MPT_DELAY(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE2( macro, args ) INTERNAL_MPT_COMPOSE2( macro, INTERNAL_MPT_DELAY2(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE3( macro, args ) INTERNAL_MPT_COMPOSE3( macro, INTERNAL_MPT_DELAY3(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE4( macro, args ) INTERNAL_MPT_COMPOSE4( macro, INTERNAL_MPT_DELAY4(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE5( macro, args ) INTERNAL_MPT_COMPOSE5( macro, INTERNAL_MPT_DELAY5(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE6( macro, args ) INTERNAL_MPT_COMPOSE6( macro, INTERNAL_MPT_DELAY6(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE7( macro, args ) INTERNAL_MPT_COMPOSE7( macro, INTERNAL_MPT_DELAY7(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE8( macro, args ) INTERNAL_MPT_COMPOSE8( macro, INTERNAL_MPT_DELAY8(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE9( macro, args ) INTERNAL_MPT_COMPOSE9( macro, INTERNAL_MPT_DELAY9(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE10( macro, args ) INTERNAL_MPT_COMPOSE10( macro, INTERNAL_MPT_DELAY10(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE11( macro, args ) INTERNAL_MPT_COMPOSE11( macro, INTERNAL_MPT_DELAY11(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE12( macro, args ) INTERNAL_MPT_COMPOSE12( macro, INTERNAL_MPT_DELAY12(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE13( macro, args ) INTERNAL_MPT_COMPOSE13( macro, INTERNAL_MPT_DELAY13(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE14( macro, args ) INTERNAL_MPT_COMPOSE14( macro, INTERNAL_MPT_DELAY14(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE15( macro, args ) INTERNAL_MPT_COMPOSE15( macro, INTERNAL_MPT_DELAY15(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE16( macro, args ) INTERNAL_MPT_COMPOSE16( macro, INTERNAL_MPT_DELAY16(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE17( macro, args ) INTERNAL_MPT_COMPOSE17( macro, INTERNAL_MPT_DELAY17(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE18( macro, args ) INTERNAL_MPT_COMPOSE18( macro, INTERNAL_MPT_DELAY18(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE19( macro, args ) INTERNAL_MPT_COMPOSE19( macro, INTERNAL_MPT_DELAY19(args) )
#define INTERNAL_MPT_DELAYED_COMPOSE20( macro, args ) INTERNAL_MPT_COMPOSE20( macro, INTERNAL_MPT_DELAY20(args) )


#endif

//=================================================================
//./External/MacroPowerToys/AppendListsItems.h
//=================================================================
#ifndef MPT_APPEND_LISTS_ITEMS_H
#define MPT_APPEND_LISTS_ITEMS_H

//=================================================================
//./External/MacroPowerToys/Overload.h
//=================================================================
#ifndef MPT_OVERLOAD_H
#define MPT_OVERLOAD_H

//=================================================================
//./External/MacroPowerToys/ArgsCount.h
//=================================================================
#ifndef MPT_ARGS_COUNT_H
#define MPT_ARGS_COUNT_H



#define INTERNAL_MPT_GET_COUNT( _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, \
                                _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, \
                                _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, \
                                _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, \
                                _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, \
                                _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, \
                                _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, \
                                _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, \
                                _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, \
                                _93, _94, _95, _96, _97, _98, _99, \
                                COUNT, ... ) COUNT

#define INTERNAL_MPT_EXPAND()   ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,, \
                                ,,,,,,,,,

#define MPT_ARGS_COUNT( ... ) \
    INTERNAL_MPT_COMPOSE4 \
    ( \
        INTERNAL_MPT_GET_COUNT, \
        ( \
            INTERNAL_MPT_EXPAND __VA_ARGS__ (), \
            0, 99, 98, 97, 96, 95, 94, 93, 92, 91, \
            90, 89, 88, 87, 86, 85, 84, 83, 82, 81, \
            80, 79, 78, 77, 76, 75, 74, 73, 72, 71, \
            70, 69, 68, 67, 66, 65, 64, 63, 62, 61, \
            60, 59, 58, 57, 56, 55, 54, 53, 52, 51, \
            50, 49, 48, 47, 46, 45, 44, 43, 42, 41, \
            40, 39, 38, 37, 36, 35, 34, 33, 32, 31, \
            30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
            20, 19, 18, 17, 16, 15, 14, 13, 12, 11, \
            10, 9, 8, 7, 6, 5, 4, 3, 2, 1 \
        ) \
    )


#define INTERNAL_MPT_ARGS_COUNT( ... ) \
    MPT_ARGS_COUNT( __VA_ARGS__ )

#endif


#define MPT_OVERLOAD_MACRO( NAME, ... ) \
        INTERNAL_MPT_COMPOSE7 \
        ( \
            INTERNAL_MPT_COMPOSE8 \
            ( \
                INTERNAL_MPT_SELECT4, \
                ( NAME, MPT_ARGS_COUNT( __VA_ARGS__ ) ) \
            ), \
            (__VA_ARGS__) \
        )


#endif





#define MPT_APPEND_LISTS_ITEMS( ... ) \
    INTERNAL_MPT_DELAYED_COMPOSE \
    ( \
        INTERNAL_MPT_COMPOSE2 \
        ( \
            INTERNAL_MPT_SELECT, \
            ( INTERNAL_MPT_APPEND_LISTS_ITEMS, INTERNAL_MPT_ARGS_COUNT( __VA_ARGS__ ) ) \
        ), \
        (__VA_ARGS__) \
    )


#define INTERNAL_MPT_APPEND_LISTS_ITEMS_0()

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_2( a1, b1 ) \
a1 b1

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_4( a1, a2, b1, b2 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_2( a1, b1 ), a2 b2

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_6( a1, a2, a3, b1, b2, b3 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_4( a1, a2, b1, b2 ), a3 b3

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_8( a1, a2, a3, a4, b1, b2, b3, b4 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_6( a1, a2, a3, b1, b2, b3 ), a4 b4

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_10( a1, a2, a3, a4, a5, b1, b2, b3, b4, b5 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_8( a1, a2, a3, a4, b1, b2, b3, b4 ), a5 b5

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_12( a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_10( a1, a2, a3, a4, a5, b1, b2, b3, b4, b5 ), a6 b6

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_14( a1, a2, a3, a4, a5, a6, a7, b1, b2, b3, b4, b5, b6, b7 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_12( a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6 ), a7 b7

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_16( a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_14( a1, a2, a3, a4, a5, a6, a7, b1, b2, b3, b4, b5, b6, b7 ), a8 b8

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_18( a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2, b3, b4, b5, b6, b7, b8, b9 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_16( a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8 ), a9 b9

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_20( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_18( a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2, b3, b4, b5, b6, b7, b8, b9 ), a10 b10

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_22( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_20( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10 ), a11 b11

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_24( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_22( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11 ), a12 b12

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_26( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_24( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12 ), a13 b13

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_28( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_26( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13 ), a14 b14

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_30( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_28( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14 ), a15 b15

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_32( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_30( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15 ), a16 b16

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_34( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_32( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16 ), a17 b17

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_36( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_34( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17 ), a18 b18

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_38( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_36( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18 ), a19 b19

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_40( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_38( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19 ), a20 b20

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_42( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_40( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20 ), a21 b21

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_44( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_42( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21 ), a22 b22

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_46( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_44( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22 ), a23 b23

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_48( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_46( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23 ), a24 b24

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_50( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_48( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24 ), a25 b25

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_52( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_50( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25 ), a26 b26

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_54( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_52( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26 ), a27 b27

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_56( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_54( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27 ), a28 b28

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_58( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_56( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28 ), a29 b29

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_60( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_58( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29 ), a30 b30

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_62( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_60( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30 ), a31 b31

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_64( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_62( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31 ), a32 b32

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_66( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_64( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32 ), a33 b33

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_68( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_66( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33 ), a34 b34

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_70( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_68( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34 ), a35 b35

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_72( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_70( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35 ), a36 b36

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_74( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_72( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36 ), a37 b37

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_76( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_74( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37 ), a38 b38

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_78( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_76( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38 ), a39 b39

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_80( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_78( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39 ), a40 b40

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_82( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_80( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40 ), a41 b41

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_84( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_82( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41 ), a42 b42

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_86( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_84( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42 ), a43 b43

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_88( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_86( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43 ), a44 b44

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_90( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_88( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44 ), a45 b45

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_92( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_90( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45 ), a46 b46

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_94( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_92( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46 ), a47 b47

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_96( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_94( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47 ), a48 b48

#define INTERNAL_MPT_APPEND_LISTS_ITEMS_98( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49 ) \
INTERNAL_MPT_APPEND_LISTS_ITEMS_96( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48 ), a49 b49


#endif


//=================================================================
//./External/MacroPowerToys/ConcatListsItems.h
//=================================================================
#ifndef MPT_CONCAT_LISTS_ITEMS_H
#define MPT_CONCAT_LISTS_ITEMS_H






#define MPT_CONCAT_LISTS_ITEMS( ... ) \
    INTERNAL_MPT_COMPOSE5 \
    ( \
        INTERNAL_MPT_SELECT2, \
        ( INTERNAL_MPT_CONCAT_LISTS_ITEMS, MPT_ARGS_COUNT( __VA_ARGS__ ) ) \
    ) (__VA_ARGS__)


#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_0()

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_2( a1, b1 ) \
a1 ## b1

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_4( a1, a2, b1, b2 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_2( a1, b1 ), a2 ## b2

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_6( a1, a2, a3, b1, b2, b3 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_4( a1, a2, b1, b2 ), a3 ## b3

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_8( a1, a2, a3, a4, b1, b2, b3, b4 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_6( a1, a2, a3, b1, b2, b3 ), a4 ## b4

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_10( a1, a2, a3, a4, a5, b1, b2, b3, b4, b5 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_8( a1, a2, a3, a4, b1, b2, b3, b4 ), a5 ## b5

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_12( a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_10( a1, a2, a3, a4, a5, b1, b2, b3, b4, b5 ), a6 ## b6

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_14( a1, a2, a3, a4, a5, a6, a7, b1, b2, b3, b4, b5, b6, b7 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_12( a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6 ), a7 ## b7

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_16( a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_14( a1, a2, a3, a4, a5, a6, a7, b1, b2, b3, b4, b5, b6, b7 ), a8 ## b8

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_18( a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2, b3, b4, b5, b6, b7, b8, b9 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_16( a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8 ), a9 ## b9

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_20( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_18( a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2, b3, b4, b5, b6, b7, b8, b9 ), a10 ## b10

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_22( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_20( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10 ), a11 ## b11

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_24( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_22( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11 ), a12 ## b12

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_26( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_24( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12 ), a13 ## b13

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_28( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_26( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13 ), a14 ## b14

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_30( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_28( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14 ), a15 ## b15

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_32( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_30( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15 ), a16 ## b16

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_34( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_32( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16 ), a17 ## b17

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_36( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_34( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17 ), a18 ## b18

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_38( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_36( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18 ), a19 ## b19

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_40( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_38( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19 ), a20 ## b20

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_42( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_40( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20 ), a21 ## b21

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_44( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_42( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21 ), a22 ## b22

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_46( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_44( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22 ), a23 ## b23

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_48( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_46( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23 ), a24 ## b24

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_50( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_48( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24 ), a25 ## b25

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_52( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_50( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25 ), a26 ## b26

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_54( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_52( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26 ), a27 ## b27

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_56( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_54( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27 ), a28 ## b28

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_58( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_56( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28 ), a29 ## b29

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_60( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_58( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29 ), a30 ## b30

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_62( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_60( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30 ), a31 ## b31

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_64( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_62( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31 ), a32 ## b32

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_66( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_64( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32 ), a33 ## b33

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_68( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_66( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33 ), a34 ## b34

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_70( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_68( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34 ), a35 ## b35

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_72( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_70( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35 ), a36 ## b36

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_74( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_72( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36 ), a37 ## b37

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_76( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_74( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37 ), a38 ## b38

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_78( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_76( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38 ), a39 ## b39

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_80( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_78( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39 ), a40 ## b40

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_82( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_80( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40 ), a41 ## b41

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_84( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_82( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41 ), a42 ## b42

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_86( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_84( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42 ), a43 ## b43

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_88( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_86( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43 ), a44 ## b44

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_90( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_88( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44 ), a45 ## b45

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_92( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_90( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45 ), a46 ## b46

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_94( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_92( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46 ), a47 ## b47

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_96( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_94( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47 ), a48 ## b48

#define INTERNAL_MPT_CONCAT_LISTS_ITEMS_98( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49 ) \
INTERNAL_MPT_CONCAT_LISTS_ITEMS_96( a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48 ), a49 ## b49


#endif

//=================================================================
//./External/MacroPowerToys/CountTo.h
//=================================================================
#ifndef MPT_COUNT_TO_H
#define MPT_COUNT_TO_H



#define MPT_COUNT_TO_0(prefix, suffix)
#define MPT_COUNT_TO_0_(prefix, suffix)

#define MPT_COUNT_TO_1_(prefix, suffix) \
    prefix ## 1 ## suffix

#define MPT_COUNT_TO_1(prefix, suffix) \
    MPT_COUNT_TO_1_(prefix, suffix) \

#define MPT_COUNT_TO_1_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_0_(prefix, suffix)

#define MPT_COUNT_TO_2_(prefix, suffix) \
    MPT_COUNT_TO_1_(prefix, suffix), prefix ## 2 ## suffix

#define MPT_COUNT_TO_2(prefix, suffix) \
    MPT_COUNT_TO_2_(prefix, suffix) 

#define MPT_COUNT_TO_2_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_1_(prefix, suffix)

#define MPT_COUNT_TO_3_(prefix, suffix) \
    MPT_COUNT_TO_2_(prefix, suffix), prefix ## 3 ## suffix

#define MPT_COUNT_TO_3(prefix, suffix) \
    MPT_COUNT_TO_3_(prefix, suffix) 

#define MPT_COUNT_TO_3_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_2_(prefix, suffix)

#define MPT_COUNT_TO_4_(prefix, suffix) \
    MPT_COUNT_TO_3_(prefix, suffix), prefix ## 4 ## suffix

#define MPT_COUNT_TO_4(prefix, suffix) \
    MPT_COUNT_TO_4_(prefix, suffix) 

#define MPT_COUNT_TO_4_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_3_(prefix, suffix)

#define MPT_COUNT_TO_5_(prefix, suffix) \
    MPT_COUNT_TO_4_(prefix, suffix), prefix ## 5 ## suffix

#define MPT_COUNT_TO_5(prefix, suffix) \
    MPT_COUNT_TO_5_(prefix, suffix) 

#define MPT_COUNT_TO_5_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_4_(prefix, suffix)

#define MPT_COUNT_TO_6_(prefix, suffix) \
    MPT_COUNT_TO_5_(prefix, suffix), prefix ## 6 ## suffix

#define MPT_COUNT_TO_6(prefix, suffix) \
    MPT_COUNT_TO_6_(prefix, suffix) 

#define MPT_COUNT_TO_6_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_5_(prefix, suffix)

#define MPT_COUNT_TO_7_(prefix, suffix) \
    MPT_COUNT_TO_6_(prefix, suffix), prefix ## 7 ## suffix

#define MPT_COUNT_TO_7(prefix, suffix) \
    MPT_COUNT_TO_7_(prefix, suffix) 

#define MPT_COUNT_TO_7_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_6_(prefix, suffix)

#define MPT_COUNT_TO_8_(prefix, suffix) \
    MPT_COUNT_TO_7_(prefix, suffix), prefix ## 8 ## suffix

#define MPT_COUNT_TO_8(prefix, suffix) \
    MPT_COUNT_TO_8_(prefix, suffix) 

#define MPT_COUNT_TO_8_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_7_(prefix, suffix)

#define MPT_COUNT_TO_9_(prefix, suffix) \
    MPT_COUNT_TO_8_(prefix, suffix), prefix ## 9 ## suffix

#define MPT_COUNT_TO_9(prefix, suffix) \
    MPT_COUNT_TO_9_(prefix, suffix) 

#define MPT_COUNT_TO_9_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_8_(prefix, suffix)

#define MPT_COUNT_TO_10_(prefix, suffix) \
    MPT_COUNT_TO_9_(prefix, suffix), prefix ## 10 ## suffix

#define MPT_COUNT_TO_10(prefix, suffix) \
    MPT_COUNT_TO_10_(prefix, suffix) 

#define MPT_COUNT_TO_10_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_9_(prefix, suffix)

#define MPT_COUNT_TO_11_(prefix, suffix) \
    MPT_COUNT_TO_10_(prefix, suffix), prefix ## 11 ## suffix

#define MPT_COUNT_TO_11(prefix, suffix) \
    MPT_COUNT_TO_11_(prefix, suffix) 

#define MPT_COUNT_TO_11_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_10_(prefix, suffix)

#define MPT_COUNT_TO_12_(prefix, suffix) \
    MPT_COUNT_TO_11_(prefix, suffix), prefix ## 12 ## suffix

#define MPT_COUNT_TO_12(prefix, suffix) \
    MPT_COUNT_TO_12_(prefix, suffix) 

#define MPT_COUNT_TO_12_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_11_(prefix, suffix)

#define MPT_COUNT_TO_13_(prefix, suffix) \
    MPT_COUNT_TO_12_(prefix, suffix), prefix ## 13 ## suffix

#define MPT_COUNT_TO_13(prefix, suffix) \
    MPT_COUNT_TO_13_(prefix, suffix) 

#define MPT_COUNT_TO_13_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_12_(prefix, suffix)

#define MPT_COUNT_TO_14_(prefix, suffix) \
    MPT_COUNT_TO_13_(prefix, suffix), prefix ## 14 ## suffix

#define MPT_COUNT_TO_14(prefix, suffix) \
    MPT_COUNT_TO_14_(prefix, suffix) 

#define MPT_COUNT_TO_14_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_13_(prefix, suffix)

#define MPT_COUNT_TO_15_(prefix, suffix) \
    MPT_COUNT_TO_14_(prefix, suffix), prefix ## 15 ## suffix

#define MPT_COUNT_TO_15(prefix, suffix) \
    MPT_COUNT_TO_15_(prefix, suffix) 

#define MPT_COUNT_TO_15_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_14_(prefix, suffix)

#define MPT_COUNT_TO_16_(prefix, suffix) \
    MPT_COUNT_TO_15_(prefix, suffix), prefix ## 16 ## suffix

#define MPT_COUNT_TO_16(prefix, suffix) \
    MPT_COUNT_TO_16_(prefix, suffix) 

#define MPT_COUNT_TO_16_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_15_(prefix, suffix)

#define MPT_COUNT_TO_17_(prefix, suffix) \
    MPT_COUNT_TO_16_(prefix, suffix), prefix ## 17 ## suffix

#define MPT_COUNT_TO_17(prefix, suffix) \
    MPT_COUNT_TO_17_(prefix, suffix) 

#define MPT_COUNT_TO_17_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_16_(prefix, suffix)

#define MPT_COUNT_TO_18_(prefix, suffix) \
    MPT_COUNT_TO_17_(prefix, suffix), prefix ## 18 ## suffix

#define MPT_COUNT_TO_18(prefix, suffix) \
    MPT_COUNT_TO_18_(prefix, suffix) 

#define MPT_COUNT_TO_18_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_17_(prefix, suffix)

#define MPT_COUNT_TO_19_(prefix, suffix) \
    MPT_COUNT_TO_18_(prefix, suffix), prefix ## 19 ## suffix

#define MPT_COUNT_TO_19(prefix, suffix) \
    MPT_COUNT_TO_19_(prefix, suffix) 

#define MPT_COUNT_TO_19_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_18_(prefix, suffix)

#define MPT_COUNT_TO_20_(prefix, suffix) \
    MPT_COUNT_TO_19_(prefix, suffix), prefix ## 20 ## suffix

#define MPT_COUNT_TO_20(prefix, suffix) \
    MPT_COUNT_TO_20_(prefix, suffix) 

#define MPT_COUNT_TO_20_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_19_(prefix, suffix)

#define MPT_COUNT_TO_21_(prefix, suffix) \
    MPT_COUNT_TO_20_(prefix, suffix), prefix ## 21 ## suffix

#define MPT_COUNT_TO_21(prefix, suffix) \
    MPT_COUNT_TO_21_(prefix, suffix) 

#define MPT_COUNT_TO_21_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_20_(prefix, suffix)

#define MPT_COUNT_TO_22_(prefix, suffix) \
    MPT_COUNT_TO_21_(prefix, suffix), prefix ## 22 ## suffix

#define MPT_COUNT_TO_22(prefix, suffix) \
    MPT_COUNT_TO_22_(prefix, suffix) 

#define MPT_COUNT_TO_22_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_21_(prefix, suffix)

#define MPT_COUNT_TO_23_(prefix, suffix) \
    MPT_COUNT_TO_22_(prefix, suffix), prefix ## 23 ## suffix

#define MPT_COUNT_TO_23(prefix, suffix) \
    MPT_COUNT_TO_23_(prefix, suffix) 

#define MPT_COUNT_TO_23_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_22_(prefix, suffix)

#define MPT_COUNT_TO_24_(prefix, suffix) \
    MPT_COUNT_TO_23_(prefix, suffix), prefix ## 24 ## suffix

#define MPT_COUNT_TO_24(prefix, suffix) \
    MPT_COUNT_TO_24_(prefix, suffix) 

#define MPT_COUNT_TO_24_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_23_(prefix, suffix)

#define MPT_COUNT_TO_25_(prefix, suffix) \
    MPT_COUNT_TO_24_(prefix, suffix), prefix ## 25 ## suffix

#define MPT_COUNT_TO_25(prefix, suffix) \
    MPT_COUNT_TO_25_(prefix, suffix) 

#define MPT_COUNT_TO_25_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_24_(prefix, suffix)

#define MPT_COUNT_TO_26_(prefix, suffix) \
    MPT_COUNT_TO_25_(prefix, suffix), prefix ## 26 ## suffix

#define MPT_COUNT_TO_26(prefix, suffix) \
    MPT_COUNT_TO_26_(prefix, suffix) 

#define MPT_COUNT_TO_26_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_25_(prefix, suffix)

#define MPT_COUNT_TO_27_(prefix, suffix) \
    MPT_COUNT_TO_26_(prefix, suffix), prefix ## 27 ## suffix

#define MPT_COUNT_TO_27(prefix, suffix) \
    MPT_COUNT_TO_27_(prefix, suffix) 

#define MPT_COUNT_TO_27_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_26_(prefix, suffix)

#define MPT_COUNT_TO_28_(prefix, suffix) \
    MPT_COUNT_TO_27_(prefix, suffix), prefix ## 28 ## suffix

#define MPT_COUNT_TO_28(prefix, suffix) \
    MPT_COUNT_TO_28_(prefix, suffix) 

#define MPT_COUNT_TO_28_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_27_(prefix, suffix)

#define MPT_COUNT_TO_29_(prefix, suffix) \
    MPT_COUNT_TO_28_(prefix, suffix), prefix ## 29 ## suffix

#define MPT_COUNT_TO_29(prefix, suffix) \
    MPT_COUNT_TO_29_(prefix, suffix) 

#define MPT_COUNT_TO_29_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_28_(prefix, suffix)

#define MPT_COUNT_TO_30_(prefix, suffix) \
    MPT_COUNT_TO_29_(prefix, suffix), prefix ## 30 ## suffix

#define MPT_COUNT_TO_30(prefix, suffix) \
    MPT_COUNT_TO_30_(prefix, suffix) 

#define MPT_COUNT_TO_30_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_29_(prefix, suffix)

#define MPT_COUNT_TO_31_(prefix, suffix) \
    MPT_COUNT_TO_30_(prefix, suffix), prefix ## 31 ## suffix

#define MPT_COUNT_TO_31(prefix, suffix) \
    MPT_COUNT_TO_31_(prefix, suffix) 

#define MPT_COUNT_TO_31_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_30_(prefix, suffix)

#define MPT_COUNT_TO_32_(prefix, suffix) \
    MPT_COUNT_TO_31_(prefix, suffix), prefix ## 32 ## suffix

#define MPT_COUNT_TO_32(prefix, suffix) \
    MPT_COUNT_TO_32_(prefix, suffix) 

#define MPT_COUNT_TO_32_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_31_(prefix, suffix)

#define MPT_COUNT_TO_33_(prefix, suffix) \
    MPT_COUNT_TO_32_(prefix, suffix), prefix ## 33 ## suffix

#define MPT_COUNT_TO_33(prefix, suffix) \
    MPT_COUNT_TO_33_(prefix, suffix) 

#define MPT_COUNT_TO_33_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_32_(prefix, suffix)

#define MPT_COUNT_TO_34_(prefix, suffix) \
    MPT_COUNT_TO_33_(prefix, suffix), prefix ## 34 ## suffix

#define MPT_COUNT_TO_34(prefix, suffix) \
    MPT_COUNT_TO_34_(prefix, suffix) 

#define MPT_COUNT_TO_34_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_33_(prefix, suffix)

#define MPT_COUNT_TO_35_(prefix, suffix) \
    MPT_COUNT_TO_34_(prefix, suffix), prefix ## 35 ## suffix

#define MPT_COUNT_TO_35(prefix, suffix) \
    MPT_COUNT_TO_35_(prefix, suffix) 

#define MPT_COUNT_TO_35_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_34_(prefix, suffix)

#define MPT_COUNT_TO_36_(prefix, suffix) \
    MPT_COUNT_TO_35_(prefix, suffix), prefix ## 36 ## suffix

#define MPT_COUNT_TO_36(prefix, suffix) \
    MPT_COUNT_TO_36_(prefix, suffix) 

#define MPT_COUNT_TO_36_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_35_(prefix, suffix)

#define MPT_COUNT_TO_37_(prefix, suffix) \
    MPT_COUNT_TO_36_(prefix, suffix), prefix ## 37 ## suffix

#define MPT_COUNT_TO_37(prefix, suffix) \
    MPT_COUNT_TO_37_(prefix, suffix) 

#define MPT_COUNT_TO_37_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_36_(prefix, suffix)

#define MPT_COUNT_TO_38_(prefix, suffix) \
    MPT_COUNT_TO_37_(prefix, suffix), prefix ## 38 ## suffix

#define MPT_COUNT_TO_38(prefix, suffix) \
    MPT_COUNT_TO_38_(prefix, suffix) 

#define MPT_COUNT_TO_38_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_37_(prefix, suffix)

#define MPT_COUNT_TO_39_(prefix, suffix) \
    MPT_COUNT_TO_38_(prefix, suffix), prefix ## 39 ## suffix

#define MPT_COUNT_TO_39(prefix, suffix) \
    MPT_COUNT_TO_39_(prefix, suffix) 

#define MPT_COUNT_TO_39_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_38_(prefix, suffix)

#define MPT_COUNT_TO_40_(prefix, suffix) \
    MPT_COUNT_TO_39_(prefix, suffix), prefix ## 40 ## suffix

#define MPT_COUNT_TO_40(prefix, suffix) \
    MPT_COUNT_TO_40_(prefix, suffix) 

#define MPT_COUNT_TO_40_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_39_(prefix, suffix)

#define MPT_COUNT_TO_41_(prefix, suffix) \
    MPT_COUNT_TO_40_(prefix, suffix), prefix ## 41 ## suffix

#define MPT_COUNT_TO_41(prefix, suffix) \
    MPT_COUNT_TO_41_(prefix, suffix) 

#define MPT_COUNT_TO_41_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_40_(prefix, suffix)

#define MPT_COUNT_TO_42_(prefix, suffix) \
    MPT_COUNT_TO_41_(prefix, suffix), prefix ## 42 ## suffix

#define MPT_COUNT_TO_42(prefix, suffix) \
    MPT_COUNT_TO_42_(prefix, suffix) 

#define MPT_COUNT_TO_42_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_41_(prefix, suffix)

#define MPT_COUNT_TO_43_(prefix, suffix) \
    MPT_COUNT_TO_42_(prefix, suffix), prefix ## 43 ## suffix

#define MPT_COUNT_TO_43(prefix, suffix) \
    MPT_COUNT_TO_43_(prefix, suffix) 

#define MPT_COUNT_TO_43_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_42_(prefix, suffix)

#define MPT_COUNT_TO_44_(prefix, suffix) \
    MPT_COUNT_TO_43_(prefix, suffix), prefix ## 44 ## suffix

#define MPT_COUNT_TO_44(prefix, suffix) \
    MPT_COUNT_TO_44_(prefix, suffix) 

#define MPT_COUNT_TO_44_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_43_(prefix, suffix)

#define MPT_COUNT_TO_45_(prefix, suffix) \
    MPT_COUNT_TO_44_(prefix, suffix), prefix ## 45 ## suffix

#define MPT_COUNT_TO_45(prefix, suffix) \
    MPT_COUNT_TO_45_(prefix, suffix) 

#define MPT_COUNT_TO_45_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_44_(prefix, suffix)

#define MPT_COUNT_TO_46_(prefix, suffix) \
    MPT_COUNT_TO_45_(prefix, suffix), prefix ## 46 ## suffix

#define MPT_COUNT_TO_46(prefix, suffix) \
    MPT_COUNT_TO_46_(prefix, suffix) 

#define MPT_COUNT_TO_46_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_45_(prefix, suffix)

#define MPT_COUNT_TO_47_(prefix, suffix) \
    MPT_COUNT_TO_46_(prefix, suffix), prefix ## 47 ## suffix

#define MPT_COUNT_TO_47(prefix, suffix) \
    MPT_COUNT_TO_47_(prefix, suffix) 

#define MPT_COUNT_TO_47_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_46_(prefix, suffix)

#define MPT_COUNT_TO_48_(prefix, suffix) \
    MPT_COUNT_TO_47_(prefix, suffix), prefix ## 48 ## suffix

#define MPT_COUNT_TO_48(prefix, suffix) \
    MPT_COUNT_TO_48_(prefix, suffix) 

#define MPT_COUNT_TO_48_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_47_(prefix, suffix)

#define MPT_COUNT_TO_49_(prefix, suffix) \
    MPT_COUNT_TO_48_(prefix, suffix), prefix ## 49 ## suffix

#define MPT_COUNT_TO_49(prefix, suffix) \
    MPT_COUNT_TO_49_(prefix, suffix) 

#define MPT_COUNT_TO_49_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_48_(prefix, suffix)

#define MPT_COUNT_TO_50_(prefix, suffix) \
    MPT_COUNT_TO_49_(prefix, suffix), prefix ## 50 ## suffix

#define MPT_COUNT_TO_50(prefix, suffix) \
    MPT_COUNT_TO_50_(prefix, suffix) 

#define MPT_COUNT_TO_50_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_49_(prefix, suffix)

#define MPT_COUNT_TO_51_(prefix, suffix) \
    MPT_COUNT_TO_50_(prefix, suffix), prefix ## 51 ## suffix

#define MPT_COUNT_TO_51(prefix, suffix) \
    MPT_COUNT_TO_51_(prefix, suffix) 

#define MPT_COUNT_TO_51_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_50_(prefix, suffix)

#define MPT_COUNT_TO_52_(prefix, suffix) \
    MPT_COUNT_TO_51_(prefix, suffix), prefix ## 52 ## suffix

#define MPT_COUNT_TO_52(prefix, suffix) \
    MPT_COUNT_TO_52_(prefix, suffix) 

#define MPT_COUNT_TO_52_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_51_(prefix, suffix)

#define MPT_COUNT_TO_53_(prefix, suffix) \
    MPT_COUNT_TO_52_(prefix, suffix), prefix ## 53 ## suffix

#define MPT_COUNT_TO_53(prefix, suffix) \
    MPT_COUNT_TO_53_(prefix, suffix) 

#define MPT_COUNT_TO_53_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_52_(prefix, suffix)

#define MPT_COUNT_TO_54_(prefix, suffix) \
    MPT_COUNT_TO_53_(prefix, suffix), prefix ## 54 ## suffix

#define MPT_COUNT_TO_54(prefix, suffix) \
    MPT_COUNT_TO_54_(prefix, suffix) 

#define MPT_COUNT_TO_54_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_53_(prefix, suffix)

#define MPT_COUNT_TO_55_(prefix, suffix) \
    MPT_COUNT_TO_54_(prefix, suffix), prefix ## 55 ## suffix

#define MPT_COUNT_TO_55(prefix, suffix) \
    MPT_COUNT_TO_55_(prefix, suffix) 

#define MPT_COUNT_TO_55_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_54_(prefix, suffix)

#define MPT_COUNT_TO_56_(prefix, suffix) \
    MPT_COUNT_TO_55_(prefix, suffix), prefix ## 56 ## suffix

#define MPT_COUNT_TO_56(prefix, suffix) \
    MPT_COUNT_TO_56_(prefix, suffix) 

#define MPT_COUNT_TO_56_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_55_(prefix, suffix)

#define MPT_COUNT_TO_57_(prefix, suffix) \
    MPT_COUNT_TO_56_(prefix, suffix), prefix ## 57 ## suffix

#define MPT_COUNT_TO_57(prefix, suffix) \
    MPT_COUNT_TO_57_(prefix, suffix) 

#define MPT_COUNT_TO_57_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_56_(prefix, suffix)

#define MPT_COUNT_TO_58_(prefix, suffix) \
    MPT_COUNT_TO_57_(prefix, suffix), prefix ## 58 ## suffix

#define MPT_COUNT_TO_58(prefix, suffix) \
    MPT_COUNT_TO_58_(prefix, suffix) 

#define MPT_COUNT_TO_58_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_57_(prefix, suffix)

#define MPT_COUNT_TO_59_(prefix, suffix) \
    MPT_COUNT_TO_58_(prefix, suffix), prefix ## 59 ## suffix

#define MPT_COUNT_TO_59(prefix, suffix) \
    MPT_COUNT_TO_59_(prefix, suffix) 

#define MPT_COUNT_TO_59_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_58_(prefix, suffix)

#define MPT_COUNT_TO_60_(prefix, suffix) \
    MPT_COUNT_TO_59_(prefix, suffix), prefix ## 60 ## suffix

#define MPT_COUNT_TO_60(prefix, suffix) \
    MPT_COUNT_TO_60_(prefix, suffix) 

#define MPT_COUNT_TO_60_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_59_(prefix, suffix)

#define MPT_COUNT_TO_61_(prefix, suffix) \
    MPT_COUNT_TO_60_(prefix, suffix), prefix ## 61 ## suffix

#define MPT_COUNT_TO_61(prefix, suffix) \
    MPT_COUNT_TO_61_(prefix, suffix) 

#define MPT_COUNT_TO_61_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_60_(prefix, suffix)

#define MPT_COUNT_TO_62_(prefix, suffix) \
    MPT_COUNT_TO_61_(prefix, suffix), prefix ## 62 ## suffix

#define MPT_COUNT_TO_62(prefix, suffix) \
    MPT_COUNT_TO_62_(prefix, suffix) 

#define MPT_COUNT_TO_62_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_61_(prefix, suffix)

#define MPT_COUNT_TO_63_(prefix, suffix) \
    MPT_COUNT_TO_62_(prefix, suffix), prefix ## 63 ## suffix

#define MPT_COUNT_TO_63(prefix, suffix) \
    MPT_COUNT_TO_63_(prefix, suffix) 

#define MPT_COUNT_TO_63_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_62_(prefix, suffix)

#define MPT_COUNT_TO_64_(prefix, suffix) \
    MPT_COUNT_TO_63_(prefix, suffix), prefix ## 64 ## suffix

#define MPT_COUNT_TO_64(prefix, suffix) \
    MPT_COUNT_TO_64_(prefix, suffix) 

#define MPT_COUNT_TO_64_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_63_(prefix, suffix)

#define MPT_COUNT_TO_65_(prefix, suffix) \
    MPT_COUNT_TO_64_(prefix, suffix), prefix ## 65 ## suffix

#define MPT_COUNT_TO_65(prefix, suffix) \
    MPT_COUNT_TO_65_(prefix, suffix) 

#define MPT_COUNT_TO_65_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_64_(prefix, suffix)

#define MPT_COUNT_TO_66_(prefix, suffix) \
    MPT_COUNT_TO_65_(prefix, suffix), prefix ## 66 ## suffix

#define MPT_COUNT_TO_66(prefix, suffix) \
    MPT_COUNT_TO_66_(prefix, suffix) 

#define MPT_COUNT_TO_66_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_65_(prefix, suffix)

#define MPT_COUNT_TO_67_(prefix, suffix) \
    MPT_COUNT_TO_66_(prefix, suffix), prefix ## 67 ## suffix

#define MPT_COUNT_TO_67(prefix, suffix) \
    MPT_COUNT_TO_67_(prefix, suffix) 

#define MPT_COUNT_TO_67_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_66_(prefix, suffix)

#define MPT_COUNT_TO_68_(prefix, suffix) \
    MPT_COUNT_TO_67_(prefix, suffix), prefix ## 68 ## suffix

#define MPT_COUNT_TO_68(prefix, suffix) \
    MPT_COUNT_TO_68_(prefix, suffix) 

#define MPT_COUNT_TO_68_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_67_(prefix, suffix)

#define MPT_COUNT_TO_69_(prefix, suffix) \
    MPT_COUNT_TO_68_(prefix, suffix), prefix ## 69 ## suffix

#define MPT_COUNT_TO_69(prefix, suffix) \
    MPT_COUNT_TO_69_(prefix, suffix) 

#define MPT_COUNT_TO_69_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_68_(prefix, suffix)

#define MPT_COUNT_TO_70_(prefix, suffix) \
    MPT_COUNT_TO_69_(prefix, suffix), prefix ## 70 ## suffix

#define MPT_COUNT_TO_70(prefix, suffix) \
    MPT_COUNT_TO_70_(prefix, suffix) 

#define MPT_COUNT_TO_70_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_69_(prefix, suffix)

#define MPT_COUNT_TO_71_(prefix, suffix) \
    MPT_COUNT_TO_70_(prefix, suffix), prefix ## 71 ## suffix

#define MPT_COUNT_TO_71(prefix, suffix) \
    MPT_COUNT_TO_71_(prefix, suffix) 

#define MPT_COUNT_TO_71_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_70_(prefix, suffix)

#define MPT_COUNT_TO_72_(prefix, suffix) \
    MPT_COUNT_TO_71_(prefix, suffix), prefix ## 72 ## suffix

#define MPT_COUNT_TO_72(prefix, suffix) \
    MPT_COUNT_TO_72_(prefix, suffix) 

#define MPT_COUNT_TO_72_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_71_(prefix, suffix)

#define MPT_COUNT_TO_73_(prefix, suffix) \
    MPT_COUNT_TO_72_(prefix, suffix), prefix ## 73 ## suffix

#define MPT_COUNT_TO_73(prefix, suffix) \
    MPT_COUNT_TO_73_(prefix, suffix) 

#define MPT_COUNT_TO_73_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_72_(prefix, suffix)

#define MPT_COUNT_TO_74_(prefix, suffix) \
    MPT_COUNT_TO_73_(prefix, suffix), prefix ## 74 ## suffix

#define MPT_COUNT_TO_74(prefix, suffix) \
    MPT_COUNT_TO_74_(prefix, suffix) 

#define MPT_COUNT_TO_74_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_73_(prefix, suffix)

#define MPT_COUNT_TO_75_(prefix, suffix) \
    MPT_COUNT_TO_74_(prefix, suffix), prefix ## 75 ## suffix

#define MPT_COUNT_TO_75(prefix, suffix) \
    MPT_COUNT_TO_75_(prefix, suffix) 

#define MPT_COUNT_TO_75_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_74_(prefix, suffix)

#define MPT_COUNT_TO_76_(prefix, suffix) \
    MPT_COUNT_TO_75_(prefix, suffix), prefix ## 76 ## suffix

#define MPT_COUNT_TO_76(prefix, suffix) \
    MPT_COUNT_TO_76_(prefix, suffix) 

#define MPT_COUNT_TO_76_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_75_(prefix, suffix)

#define MPT_COUNT_TO_77_(prefix, suffix) \
    MPT_COUNT_TO_76_(prefix, suffix), prefix ## 77 ## suffix

#define MPT_COUNT_TO_77(prefix, suffix) \
    MPT_COUNT_TO_77_(prefix, suffix) 

#define MPT_COUNT_TO_77_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_76_(prefix, suffix)

#define MPT_COUNT_TO_78_(prefix, suffix) \
    MPT_COUNT_TO_77_(prefix, suffix), prefix ## 78 ## suffix

#define MPT_COUNT_TO_78(prefix, suffix) \
    MPT_COUNT_TO_78_(prefix, suffix) 

#define MPT_COUNT_TO_78_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_77_(prefix, suffix)

#define MPT_COUNT_TO_79_(prefix, suffix) \
    MPT_COUNT_TO_78_(prefix, suffix), prefix ## 79 ## suffix

#define MPT_COUNT_TO_79(prefix, suffix) \
    MPT_COUNT_TO_79_(prefix, suffix) 

#define MPT_COUNT_TO_79_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_78_(prefix, suffix)

#define MPT_COUNT_TO_80_(prefix, suffix) \
    MPT_COUNT_TO_79_(prefix, suffix), prefix ## 80 ## suffix

#define MPT_COUNT_TO_80(prefix, suffix) \
    MPT_COUNT_TO_80_(prefix, suffix) 

#define MPT_COUNT_TO_80_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_79_(prefix, suffix)

#define MPT_COUNT_TO_81_(prefix, suffix) \
    MPT_COUNT_TO_80_(prefix, suffix), prefix ## 81 ## suffix

#define MPT_COUNT_TO_81(prefix, suffix) \
    MPT_COUNT_TO_81_(prefix, suffix) 

#define MPT_COUNT_TO_81_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_80_(prefix, suffix)

#define MPT_COUNT_TO_82_(prefix, suffix) \
    MPT_COUNT_TO_81_(prefix, suffix), prefix ## 82 ## suffix

#define MPT_COUNT_TO_82(prefix, suffix) \
    MPT_COUNT_TO_82_(prefix, suffix) 

#define MPT_COUNT_TO_82_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_81_(prefix, suffix)

#define MPT_COUNT_TO_83_(prefix, suffix) \
    MPT_COUNT_TO_82_(prefix, suffix), prefix ## 83 ## suffix

#define MPT_COUNT_TO_83(prefix, suffix) \
    MPT_COUNT_TO_83_(prefix, suffix) 

#define MPT_COUNT_TO_83_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_82_(prefix, suffix)

#define MPT_COUNT_TO_84_(prefix, suffix) \
    MPT_COUNT_TO_83_(prefix, suffix), prefix ## 84 ## suffix

#define MPT_COUNT_TO_84(prefix, suffix) \
    MPT_COUNT_TO_84_(prefix, suffix) 

#define MPT_COUNT_TO_84_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_83_(prefix, suffix)

#define MPT_COUNT_TO_85_(prefix, suffix) \
    MPT_COUNT_TO_84_(prefix, suffix), prefix ## 85 ## suffix

#define MPT_COUNT_TO_85(prefix, suffix) \
    MPT_COUNT_TO_85_(prefix, suffix) 

#define MPT_COUNT_TO_85_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_84_(prefix, suffix)

#define MPT_COUNT_TO_86_(prefix, suffix) \
    MPT_COUNT_TO_85_(prefix, suffix), prefix ## 86 ## suffix

#define MPT_COUNT_TO_86(prefix, suffix) \
    MPT_COUNT_TO_86_(prefix, suffix) 

#define MPT_COUNT_TO_86_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_85_(prefix, suffix)

#define MPT_COUNT_TO_87_(prefix, suffix) \
    MPT_COUNT_TO_86_(prefix, suffix), prefix ## 87 ## suffix

#define MPT_COUNT_TO_87(prefix, suffix) \
    MPT_COUNT_TO_87_(prefix, suffix) 

#define MPT_COUNT_TO_87_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_86_(prefix, suffix)

#define MPT_COUNT_TO_88_(prefix, suffix) \
    MPT_COUNT_TO_87_(prefix, suffix), prefix ## 88 ## suffix

#define MPT_COUNT_TO_88(prefix, suffix) \
    MPT_COUNT_TO_88_(prefix, suffix) 

#define MPT_COUNT_TO_88_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_87_(prefix, suffix)

#define MPT_COUNT_TO_89_(prefix, suffix) \
    MPT_COUNT_TO_88_(prefix, suffix), prefix ## 89 ## suffix

#define MPT_COUNT_TO_89(prefix, suffix) \
    MPT_COUNT_TO_89_(prefix, suffix) 

#define MPT_COUNT_TO_89_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_88_(prefix, suffix)

#define MPT_COUNT_TO_90_(prefix, suffix) \
    MPT_COUNT_TO_89_(prefix, suffix), prefix ## 90 ## suffix

#define MPT_COUNT_TO_90(prefix, suffix) \
    MPT_COUNT_TO_90_(prefix, suffix) 

#define MPT_COUNT_TO_90_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_89_(prefix, suffix)

#define MPT_COUNT_TO_91_(prefix, suffix) \
    MPT_COUNT_TO_90_(prefix, suffix), prefix ## 91 ## suffix

#define MPT_COUNT_TO_91(prefix, suffix) \
    MPT_COUNT_TO_91_(prefix, suffix) 

#define MPT_COUNT_TO_91_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_90_(prefix, suffix)

#define MPT_COUNT_TO_92_(prefix, suffix) \
    MPT_COUNT_TO_91_(prefix, suffix), prefix ## 92 ## suffix

#define MPT_COUNT_TO_92(prefix, suffix) \
    MPT_COUNT_TO_92_(prefix, suffix) 

#define MPT_COUNT_TO_92_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_91_(prefix, suffix)

#define MPT_COUNT_TO_93_(prefix, suffix) \
    MPT_COUNT_TO_92_(prefix, suffix), prefix ## 93 ## suffix

#define MPT_COUNT_TO_93(prefix, suffix) \
    MPT_COUNT_TO_93_(prefix, suffix) 

#define MPT_COUNT_TO_93_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_92_(prefix, suffix)

#define MPT_COUNT_TO_94_(prefix, suffix) \
    MPT_COUNT_TO_93_(prefix, suffix), prefix ## 94 ## suffix

#define MPT_COUNT_TO_94(prefix, suffix) \
    MPT_COUNT_TO_94_(prefix, suffix) 

#define MPT_COUNT_TO_94_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_93_(prefix, suffix)

#define MPT_COUNT_TO_95_(prefix, suffix) \
    MPT_COUNT_TO_94_(prefix, suffix), prefix ## 95 ## suffix

#define MPT_COUNT_TO_95(prefix, suffix) \
    MPT_COUNT_TO_95_(prefix, suffix) 

#define MPT_COUNT_TO_95_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_94_(prefix, suffix)

#define MPT_COUNT_TO_96_(prefix, suffix) \
    MPT_COUNT_TO_95_(prefix, suffix), prefix ## 96 ## suffix

#define MPT_COUNT_TO_96(prefix, suffix) \
    MPT_COUNT_TO_96_(prefix, suffix) 

#define MPT_COUNT_TO_96_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_95_(prefix, suffix)

#define MPT_COUNT_TO_97_(prefix, suffix) \
    MPT_COUNT_TO_96_(prefix, suffix), prefix ## 97 ## suffix

#define MPT_COUNT_TO_97(prefix, suffix) \
    MPT_COUNT_TO_97_(prefix, suffix) 

#define MPT_COUNT_TO_97_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_96_(prefix, suffix)

#define MPT_COUNT_TO_98_(prefix, suffix) \
    MPT_COUNT_TO_97_(prefix, suffix), prefix ## 98 ## suffix

#define MPT_COUNT_TO_98(prefix, suffix) \
    MPT_COUNT_TO_98_(prefix, suffix) 

#define MPT_COUNT_TO_98_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_97_(prefix, suffix)

#define MPT_COUNT_TO_99_(prefix, suffix) \
    MPT_COUNT_TO_98_(prefix, suffix), prefix ## 99 ## suffix

#define MPT_COUNT_TO_99(prefix, suffix) \
    MPT_COUNT_TO_99_(prefix, suffix) 

#define MPT_COUNT_TO_99_MINUS_1(prefix, suffix) \
    MPT_COUNT_TO_98_(prefix, suffix)

#endif

//=================================================================
//./External/MacroPowerToys/GetLastArg.h
//=================================================================
#ifndef MPT_GET_LAST_ARG_H
#define MPT_GET_LAST_ARG_H





#define MPT_GET_LAST_ARG( ... ) \
    INTERNAL_MPT_COMPOSE6 \
    ( \
        INTERNAL_MPT_SELECT3, \
        ( INTERNAL_MPT_GET_LAST_ARG, MPT_ARGS_COUNT( __VA_ARGS__ ) ) \
    ) (__VA_ARGS__)


#define INTERNAL_MPT_GET_LAST_ARG_0()

#define INTERNAL_MPT_GET_LAST_ARG_1( _1 ) _1

#define INTERNAL_MPT_GET_LAST_ARG_2( _1, _2 ) _2
#define INTERNAL_MPT_GET_LAST_ARG_3( _1, _2, _3 ) _3
#define INTERNAL_MPT_GET_LAST_ARG_4( _1, _2, _3, _4 ) _4
#define INTERNAL_MPT_GET_LAST_ARG_5( _1, _2, _3, _4, _5 ) _5
#define INTERNAL_MPT_GET_LAST_ARG_6( _1, _2, _3, _4, _5, _6 ) _6
#define INTERNAL_MPT_GET_LAST_ARG_7( _1, _2, _3, _4, _5, _6, _7 ) _7
#define INTERNAL_MPT_GET_LAST_ARG_8( _1, _2, _3, _4, _5, _6, _7, _8 ) _8
#define INTERNAL_MPT_GET_LAST_ARG_9( _1, _2, _3, _4, _5, _6, _7, _8, _9 ) _9
#define INTERNAL_MPT_GET_LAST_ARG_10( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10 ) _10
#define INTERNAL_MPT_GET_LAST_ARG_11( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11 ) _11
#define INTERNAL_MPT_GET_LAST_ARG_12( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12 ) _12
#define INTERNAL_MPT_GET_LAST_ARG_13( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13 ) _13
#define INTERNAL_MPT_GET_LAST_ARG_14( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14 ) _14
#define INTERNAL_MPT_GET_LAST_ARG_15( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15 ) _15
#define INTERNAL_MPT_GET_LAST_ARG_16( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16 ) _16
#define INTERNAL_MPT_GET_LAST_ARG_17( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17 ) _17
#define INTERNAL_MPT_GET_LAST_ARG_18( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18 ) _18
#define INTERNAL_MPT_GET_LAST_ARG_19( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19 ) _19
#define INTERNAL_MPT_GET_LAST_ARG_20( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20 ) _20
#define INTERNAL_MPT_GET_LAST_ARG_21( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21 ) _21
#define INTERNAL_MPT_GET_LAST_ARG_22( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22 ) _22
#define INTERNAL_MPT_GET_LAST_ARG_23( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23 ) _23
#define INTERNAL_MPT_GET_LAST_ARG_24( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24 ) _24
#define INTERNAL_MPT_GET_LAST_ARG_25( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25 ) _25
#define INTERNAL_MPT_GET_LAST_ARG_26( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26 ) _26
#define INTERNAL_MPT_GET_LAST_ARG_27( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27 ) _27
#define INTERNAL_MPT_GET_LAST_ARG_28( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28 ) _28
#define INTERNAL_MPT_GET_LAST_ARG_29( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29 ) _29
#define INTERNAL_MPT_GET_LAST_ARG_30( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30 ) _30
#define INTERNAL_MPT_GET_LAST_ARG_31( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31 ) _31
#define INTERNAL_MPT_GET_LAST_ARG_32( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32 ) _32
#define INTERNAL_MPT_GET_LAST_ARG_33( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33 ) _33
#define INTERNAL_MPT_GET_LAST_ARG_34( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34 ) _34
#define INTERNAL_MPT_GET_LAST_ARG_35( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35 ) _35
#define INTERNAL_MPT_GET_LAST_ARG_36( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36 ) _36
#define INTERNAL_MPT_GET_LAST_ARG_37( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37 ) _37
#define INTERNAL_MPT_GET_LAST_ARG_38( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38 ) _38
#define INTERNAL_MPT_GET_LAST_ARG_39( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39 ) _39
#define INTERNAL_MPT_GET_LAST_ARG_40( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40 ) _40
#define INTERNAL_MPT_GET_LAST_ARG_41( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41 ) _41
#define INTERNAL_MPT_GET_LAST_ARG_42( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42 ) _42
#define INTERNAL_MPT_GET_LAST_ARG_43( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43 ) _43
#define INTERNAL_MPT_GET_LAST_ARG_44( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44 ) _44
#define INTERNAL_MPT_GET_LAST_ARG_45( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45 ) _45
#define INTERNAL_MPT_GET_LAST_ARG_46( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46 ) _46
#define INTERNAL_MPT_GET_LAST_ARG_47( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47 ) _47
#define INTERNAL_MPT_GET_LAST_ARG_48( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48 ) _48
#define INTERNAL_MPT_GET_LAST_ARG_49( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49 ) _49
#define INTERNAL_MPT_GET_LAST_ARG_50( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50 ) _50
#define INTERNAL_MPT_GET_LAST_ARG_51( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51 ) _51
#define INTERNAL_MPT_GET_LAST_ARG_52( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52 ) _52
#define INTERNAL_MPT_GET_LAST_ARG_53( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53 ) _53
#define INTERNAL_MPT_GET_LAST_ARG_54( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54 ) _54
#define INTERNAL_MPT_GET_LAST_ARG_55( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55 ) _55
#define INTERNAL_MPT_GET_LAST_ARG_56( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56 ) _56
#define INTERNAL_MPT_GET_LAST_ARG_57( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57 ) _57
#define INTERNAL_MPT_GET_LAST_ARG_58( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58 ) _58
#define INTERNAL_MPT_GET_LAST_ARG_59( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59 ) _59
#define INTERNAL_MPT_GET_LAST_ARG_60( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60 ) _60
#define INTERNAL_MPT_GET_LAST_ARG_61( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61 ) _61
#define INTERNAL_MPT_GET_LAST_ARG_62( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62 ) _62
#define INTERNAL_MPT_GET_LAST_ARG_63( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63 ) _63
#define INTERNAL_MPT_GET_LAST_ARG_64( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64 ) _64
#define INTERNAL_MPT_GET_LAST_ARG_65( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65 ) _65
#define INTERNAL_MPT_GET_LAST_ARG_66( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66 ) _66
#define INTERNAL_MPT_GET_LAST_ARG_67( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67 ) _67
#define INTERNAL_MPT_GET_LAST_ARG_68( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68 ) _68
#define INTERNAL_MPT_GET_LAST_ARG_69( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69 ) _69
#define INTERNAL_MPT_GET_LAST_ARG_70( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70 ) _70
#define INTERNAL_MPT_GET_LAST_ARG_71( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71 ) _71
#define INTERNAL_MPT_GET_LAST_ARG_72( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72 ) _72
#define INTERNAL_MPT_GET_LAST_ARG_73( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73 ) _73
#define INTERNAL_MPT_GET_LAST_ARG_74( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74 ) _74
#define INTERNAL_MPT_GET_LAST_ARG_75( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75 ) _75
#define INTERNAL_MPT_GET_LAST_ARG_76( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76 ) _76
#define INTERNAL_MPT_GET_LAST_ARG_77( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77 ) _77
#define INTERNAL_MPT_GET_LAST_ARG_78( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78 ) _78
#define INTERNAL_MPT_GET_LAST_ARG_79( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79 ) _79
#define INTERNAL_MPT_GET_LAST_ARG_80( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80 ) _80
#define INTERNAL_MPT_GET_LAST_ARG_81( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81 ) _81
#define INTERNAL_MPT_GET_LAST_ARG_82( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82 ) _82
#define INTERNAL_MPT_GET_LAST_ARG_83( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83 ) _83
#define INTERNAL_MPT_GET_LAST_ARG_84( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84 ) _84
#define INTERNAL_MPT_GET_LAST_ARG_85( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85 ) _85
#define INTERNAL_MPT_GET_LAST_ARG_86( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86 ) _86
#define INTERNAL_MPT_GET_LAST_ARG_87( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87 ) _87
#define INTERNAL_MPT_GET_LAST_ARG_88( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88 ) _88
#define INTERNAL_MPT_GET_LAST_ARG_89( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89 ) _89
#define INTERNAL_MPT_GET_LAST_ARG_90( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90 ) _90
#define INTERNAL_MPT_GET_LAST_ARG_91( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91 ) _91
#define INTERNAL_MPT_GET_LAST_ARG_92( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92 ) _92
#define INTERNAL_MPT_GET_LAST_ARG_93( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93 ) _93
#define INTERNAL_MPT_GET_LAST_ARG_94( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94 ) _94
#define INTERNAL_MPT_GET_LAST_ARG_95( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95 ) _95
#define INTERNAL_MPT_GET_LAST_ARG_96( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96 ) _96
#define INTERNAL_MPT_GET_LAST_ARG_97( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97 ) _97
#define INTERNAL_MPT_GET_LAST_ARG_98( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98 ) _98
#define INTERNAL_MPT_GET_LAST_ARG_99( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99 ) _99

#endif

//=================================================================
//./External/MacroPowerToys/AreArgsEmpty.h
//=================================================================
#ifndef MPT_IS_EMPTY_ARGS_H
#define MPT_IS_EMPTY_ARGS_H




#define MPT_ARE_ARGS_EMPTY( ... ) \
    INTERNAL_MPT_COMPOSE3 \
    ( \
        INTERNAL_MPT_GET_COUNT, \
        ( \
            INTERNAL_MPT_EXPAND __VA_ARGS__ (), \
            EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
            NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, NOT_EMPTY, \
        ) \
    )

#endif


//=================================================================
//./External/MacroPowerToys/PrefixSuffixArgs.h
//=================================================================
#ifndef MPT_PREFIX_SUFFIX_ARGS_H
#define MPT_PREFIX_SUFFIX_ARGS_H






#ifndef INTERNAL_MPT_PREPEND_COMMA_EMPTY
    #define INTERNAL_MPT_PREPEND_COMMA_EMPTY(...)
#endif

#ifndef INTERNAL_MPT_PREPEND_COMMA_NOT_EMPTY
    #define INTERNAL_MPT_PREPEND_COMMA_NOT_EMPTY(...) ,
#endif

#define MPT_PREFIX_SUFFIX_ARGS( prefix, suffix, ... ) \
    INTERNAL_MPT_DELAYED_COMPOSE9 \
    ( \
        INTERNAL_MPT_COMPOSE10 \
        ( \
            INTERNAL_MPT_COMPOSE11, \
            ( \
                INTERNAL_MPT_DELAYED_SELECT5, \
                ( INTERNAL_MPT_PREFIX_SUFFIX_ARGS, MPT_ARGS_COUNT( __VA_ARGS__ ) ) \
            ) \
        ), \
        ( \
            prefix, \
            suffix \
            INTERNAL_MPT_COMPOSE12 \
            ( \
                MPT_DELAYED_CONCAT6 \
                ( \
                    INTERNAL_MPT_PREPEND_COMMA_, MPT_ARE_ARGS_EMPTY( __VA_ARGS__ ) \
                ), \
                (__VA_ARGS__) \
            ) __VA_ARGS__ \
        ) \
    )


#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_0( pre, suf )

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_1( pre, suf, _1 ) \
pre ## _1 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_2( pre, suf, _1, _2 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_1(pre, suf, _1), pre ## _2 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_3( pre, suf, _1, _2, _3 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_2(pre, suf, _1, _2), pre ## _3 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_4( pre, suf, _1, _2, _3, _4 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_3(pre, suf, _1, _2, _3), pre ## _4 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_5( pre, suf, _1, _2, _3, _4, _5 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_4(pre, suf, _1, _2, _3, _4), pre ## _5 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_6( pre, suf, _1, _2, _3, _4, _5, _6 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_5(pre, suf, _1, _2, _3, _4, _5), pre ## _6 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_7( pre, suf, _1, _2, _3, _4, _5, _6, _7 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_6(pre, suf, _1, _2, _3, _4, _5, _6), pre ## _7 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_8( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_7(pre, suf, _1, _2, _3, _4, _5, _6, _7), pre ## _8 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_9( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_8(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8), pre ## _9 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_10( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_9(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9), pre ## _10 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_11( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_10(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10), pre ## _11 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_12( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_11(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11), pre ## _12 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_13( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_12(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12), pre ## _13 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_14( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_13(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13), pre ## _14 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_15( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_14(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14), pre ## _15 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_16( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_15(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15), pre ## _16 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_17( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_16(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16), pre ## _17 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_18( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_17(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17), pre ## _18 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_19( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_18(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18), pre ## _19 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_20( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_19(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19), pre ## _20 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_21( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_20(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20), pre ## _21 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_22( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_21(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21), pre ## _22 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_23( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_22(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22), pre ## _23 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_24( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_23(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23), pre ## _24 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_25( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_24(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24), pre ## _25 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_26( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_25(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25), pre ## _26 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_27( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_26(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26), pre ## _27 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_28( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_27(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27), pre ## _28 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_29( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_28(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28), pre ## _29 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_30( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_29(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29), pre ## _30 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_31( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_30(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30), pre ## _31 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_32( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_31(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31), pre ## _32 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_33( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_32(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32), pre ## _33 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_34( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_33(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33), pre ## _34 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_35( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_34(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34), pre ## _35 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_36( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_35(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35), pre ## _36 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_37( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_36(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36), pre ## _37 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_38( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_37(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37), pre ## _38 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_39( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_38(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38), pre ## _39 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_40( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_39(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39), pre ## _40 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_41( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_40(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40), pre ## _41 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_42( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_41(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41), pre ## _42 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_43( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_42(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42), pre ## _43 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_44( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_43(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43), pre ## _44 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_45( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_44(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44), pre ## _45 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_46( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_45(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45), pre ## _46 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_47( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_46(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46), pre ## _47 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_48( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_47(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47), pre ## _48 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_49( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_48(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48), pre ## _49 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_50( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_49(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49), pre ## _50 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_51( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_50(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50), pre ## _51 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_52( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_51(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51), pre ## _52 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_53( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_52(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52), pre ## _53 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_54( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_53(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53), pre ## _54 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_55( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_54(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54), pre ## _55 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_56( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_55(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55), pre ## _56 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_57( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_56(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56), pre ## _57 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_58( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_57(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57), pre ## _58 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_59( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_58(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58), pre ## _59 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_60( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_59(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59), pre ## _60 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_61( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_60(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60), pre ## _61 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_62( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_61(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61), pre ## _62 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_63( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_62(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62), pre ## _63 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_64( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_63(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63), pre ## _64 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_65( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_64(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64), pre ## _65 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_66( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_65(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65), pre ## _66 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_67( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_66(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66), pre ## _67 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_68( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_67(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67), pre ## _68 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_69( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_68(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68), pre ## _69 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_70( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_69(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69), pre ## _70 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_71( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_70(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70), pre ## _71 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_72( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_71(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71), pre ## _72 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_73( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_72(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72), pre ## _73 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_74( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_73(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73), pre ## _74 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_75( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_74(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74), pre ## _75 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_76( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_75(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75), pre ## _76 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_77( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_76(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76), pre ## _77 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_78( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_77(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77), pre ## _78 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_79( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_78(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78), pre ## _79 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_80( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_79(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79), pre ## _80 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_81( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_80(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80), pre ## _81 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_82( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_81(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81), pre ## _82 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_83( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_82(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82), pre ## _83 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_84( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_83(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83), pre ## _84 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_85( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_84(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84), pre ## _85 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_86( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_85(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85), pre ## _86 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_87( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_86(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86), pre ## _87 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_88( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_87(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87), pre ## _88 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_89( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_88(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88), pre ## _89 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_90( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_89(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89), pre ## _90 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_91( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_90(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90), pre ## _91 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_92( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_91(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91), pre ## _92 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_93( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_92(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92), pre ## _93 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_94( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_93(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93), pre ## _94 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_95( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_94(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94), pre ## _95 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_96( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_95(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95), pre ## _96 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_97( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_96(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96), pre ## _97 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_98( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_97(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97), pre ## _98 ## suf

#define INTERNAL_MPT_PREFIX_SUFFIX_ARGS_99( pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99 ) \
INTERNAL_MPT_PREFIX_SUFFIX_ARGS_98(pre, suf, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98), pre ## _99 ## suf


#endif

//=================================================================
//./External/MacroPowerToys/PrependAppendArgs.h
//=================================================================
#ifndef MPT_PREPEND_APPEND_ARGS_H
#define MPT_PREPEND_APPEND_ARGS_H






#ifndef INTERNAL_MPT_PREPEND_COMMA_EMPTY
    #define INTERNAL_MPT_PREPEND_COMMA_EMPTY(...)
#endif

#ifndef INTERNAL_MPT_PREPEND_COMMA_NOT_EMPTY
    #define INTERNAL_MPT_PREPEND_COMMA_NOT_EMPTY(...) ,
#endif

#define MPT_PREPEND_APPEND_ARGS( prepend, append, ... ) \
    INTERNAL_MPT_DELAYED_COMPOSE14 \
    ( \
        INTERNAL_MPT_COMPOSE15 \
        ( \
            INTERNAL_MPT_COMPOSE16, \
            ( \
                INTERNAL_MPT_DELAYED_SELECT7, \
                ( INTERNAL_MPT_PREPEND_APPEND_ARGS, MPT_ARGS_COUNT( __VA_ARGS__ ) ) \
            ) \
        ), \
        ( \
            prepend, \
            append \
            INTERNAL_MPT_COMPOSE17 \
            ( \
                MPT_DELAYED_CONCAT8 \
                ( \
                    INTERNAL_MPT_PREPEND_COMMA_, MPT_ARE_ARGS_EMPTY( __VA_ARGS__ ) \
                ), \
                (__VA_ARGS__) \
            ) __VA_ARGS__ \
        ) \
    )

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_0( pre, app )

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_1( pre, app, _1 ) \
pre _1 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_2( pre, app, _1, _2 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_1(pre, app, _1), pre _2 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_3( pre, app, _1, _2, _3 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_2(pre, app, _1, _2), pre _3 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_4( pre, app, _1, _2, _3, _4 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_3(pre, app, _1, _2, _3), pre _4 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_5( pre, app, _1, _2, _3, _4, _5 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_4(pre, app, _1, _2, _3, _4), pre _5 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_6( pre, app, _1, _2, _3, _4, _5, _6 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_5(pre, app, _1, _2, _3, _4, _5), pre _6 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_7( pre, app, _1, _2, _3, _4, _5, _6, _7 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_6(pre, app, _1, _2, _3, _4, _5, _6), pre _7 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_8( pre, app, _1, _2, _3, _4, _5, _6, _7, _8 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_7(pre, app, _1, _2, _3, _4, _5, _6, _7), pre _8 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_9( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_8(pre, app, _1, _2, _3, _4, _5, _6, _7, _8), pre _9 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_10( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_9(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9), pre _10 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_11( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_10(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10), pre _11 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_12( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_11(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11), pre _12 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_13( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_12(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12), pre _13 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_14( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_13(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13), pre _14 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_15( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_14(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14), pre _15 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_16( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_15(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15), pre _16 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_17( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_16(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16), pre _17 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_18( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_17(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17), pre _18 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_19( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_18(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18), pre _19 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_20( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_19(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19), pre _20 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_21( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_20(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20), pre _21 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_22( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_21(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21), pre _22 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_23( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_22(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22), pre _23 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_24( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_23(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23), pre _24 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_25( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_24(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24), pre _25 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_26( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_25(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25), pre _26 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_27( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_26(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26), pre _27 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_28( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_27(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27), pre _28 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_29( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_28(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28), pre _29 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_30( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_29(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29), pre _30 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_31( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_30(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30), pre _31 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_32( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_31(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31), pre _32 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_33( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_32(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32), pre _33 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_34( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_33(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33), pre _34 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_35( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_34(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34), pre _35 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_36( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_35(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35), pre _36 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_37( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_36(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36), pre _37 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_38( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_37(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37), pre _38 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_39( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_38(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38), pre _39 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_40( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_39(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39), pre _40 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_41( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_40(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40), pre _41 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_42( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_41(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41), pre _42 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_43( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_42(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42), pre _43 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_44( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_43(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43), pre _44 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_45( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_44(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44), pre _45 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_46( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_45(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45), pre _46 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_47( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_46(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46), pre _47 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_48( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_47(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47), pre _48 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_49( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_48(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48), pre _49 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_50( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_49(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49), pre _50 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_51( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_50(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50), pre _51 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_52( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_51(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51), pre _52 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_53( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_52(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52), pre _53 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_54( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_53(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53), pre _54 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_55( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_54(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54), pre _55 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_56( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_55(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55), pre _56 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_57( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_56(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56), pre _57 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_58( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_57(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57), pre _58 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_59( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_58(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58), pre _59 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_60( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_59(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59), pre _60 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_61( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_60(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60), pre _61 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_62( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_61(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61), pre _62 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_63( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_62(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62), pre _63 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_64( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_63(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63), pre _64 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_65( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_64(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64), pre _65 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_66( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_65(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65), pre _66 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_67( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_66(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66), pre _67 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_68( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_67(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67), pre _68 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_69( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_68(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68), pre _69 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_70( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_69(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69), pre _70 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_71( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_70(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70), pre _71 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_72( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_71(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71), pre _72 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_73( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_72(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72), pre _73 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_74( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_73(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73), pre _74 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_75( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_74(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74), pre _75 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_76( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_75(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75), pre _76 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_77( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_76(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76), pre _77 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_78( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_77(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77), pre _78 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_79( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_78(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78), pre _79 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_80( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_79(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79), pre _80 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_81( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_80(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80), pre _81 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_82( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_81(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81), pre _82 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_83( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_82(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82), pre _83 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_84( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_83(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83), pre _84 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_85( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_84(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84), pre _85 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_86( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_85(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85), pre _86 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_87( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_86(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86), pre _87 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_88( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_87(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87), pre _88 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_89( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_88(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88), pre _89 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_90( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_89(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89), pre _90 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_91( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_90(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90), pre _91 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_92( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_91(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91), pre _92 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_93( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_92(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92), pre _93 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_94( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_93(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93), pre _94 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_95( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_94(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94), pre _95 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_96( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_95(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95), pre _96 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_97( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_96(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96), pre _97 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_98( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_97(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97), pre _98 app

#define INTERNAL_MPT_PREPEND_APPEND_ARGS_99( pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99 ) \
INTERNAL_MPT_PREPEND_APPEND_ARGS_98(pre, app, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98), pre _99 app


#endif


//=================================================================
//./Include_MultiHeaders/OverrideStatus.hpp
//=================================================================
#ifndef CO_OVERRIDE_STATUS_HPP
#define CO_OVERRIDE_STATUS_HPP

#include <string>

namespace CppOverride
{
    enum class OverrideStatus
    {
        //------------------------------------------
        //Override status
        //------------------------------------------
        //Default status.
        //  Any matching override will modify the status to not be this value.
        //  If the status is not modified (i.e. staying in this value), 
        //  Could be one of these reasons:
        //  - Function name not matching
        //  - Argument types not matching
        //  - Return type not matching
        NO_OVERRIDE,
        
        //The last override was successful. 
        //  Please reset the status to NO_OVERRIDE before every expected override. 
        //  If the status is not reset, it will not be modified if no matching override is found.
        OVERRIDE_SUCCESS,
        
        MATCHING_CONDITION_VALUE_FAILED,
        MATCHING_CONDITION_ACTION_FAILED,
        MATCHING_OVERRIDE_TIMES_FAILED,
        
        //------------------------------------------
        //Internal error
        //------------------------------------------
        INTERNAL_MISSING_CHECK_ERROR,
        
        //------------------------------------------
        //Unsupported operation errors
        //------------------------------------------
        MODIFY_NON_ASSIGNABLE_ARG_ERROR,
        MODIFY_CONST_ARG_ERROR,
        CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR,
        
        COUNT
    };
    
    
    //const OverrideStatus DEFAULT_STATUS = OverrideStatus::NO_OVERRIDE;

    inline std::string OverrideStatusToString(OverrideStatus status)
    {
        static_assert((int)OverrideStatus::COUNT == 9, "");
        
        switch (status)
        {
            case OverrideStatus::NO_OVERRIDE:
                return "NO_OVERRIDE";
            case OverrideStatus::OVERRIDE_SUCCESS:
                return "OVERRIDE_SUCCESS";
            case OverrideStatus::MATCHING_CONDITION_VALUE_FAILED:
                return "MATCHING_CONDITION_VALUE_FAILED";
            case OverrideStatus::MATCHING_CONDITION_ACTION_FAILED:
                return "MATCHING_CONDITION_ACTION_FAILED";
            case OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED:
                return "MATCHING_OVERRIDE_TIMES_FAILED";
            case OverrideStatus::INTERNAL_MISSING_CHECK_ERROR:
                return "INTERNAL_MISSING_CHECK_ERROR";
            case OverrideStatus::MODIFY_NON_ASSIGNABLE_ARG_ERROR:
                return "MODIFY_NON_ASSIGNABLE_ARG_ERROR";
            case OverrideStatus::MODIFY_CONST_ARG_ERROR:
                return "MODIFY_CONST_ARG_ERROR";
            case OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR:
                return "CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR";
            case OverrideStatus::COUNT:
                return "COUNT";
            default:
                return "UNKNOWN";
        }
    }
    
}



#endif

//=================================================================
//./Include_MultiHeaders/TemplateTypeSpecifier.hpp
//=================================================================
#ifndef CO_TEMPLATE_TYPE_SPECIFIER_HPP
#define CO_TEMPLATE_TYPE_SPECIFIER_HPP

//=================================================================
//./Include_MultiHeaders/PureType.hpp
//=================================================================
#ifndef CO_PURE_TYPE_HPP
#define CO_PURE_TYPE_HPP

#include <type_traits>

namespace CppOverride
{
    #define INTERNAL_CO_UNCONST(targetType) typename std::remove_const<targetType>::type
    
    #define INTERNAL_CO_UNREF(targetType) typename std::remove_reference<targetType>::type
    
    #define INTERNAL_CO_UNPOINTER(targetType) typename std::remove_pointer<targetType>::type
    
    #define INTERNAL_CO_PURE_TYPE(targetType)\
        INTERNAL_CO_UNCONST(INTERNAL_CO_UNREF(INTERNAL_CO_UNPOINTER(targetType)))
}

#endif

#include <type_traits>

namespace CppOverride
{
    template<typename T>
    struct TypeSpecifier { using Type = T; };
    
    template<   typename T,
                typename VOID = void>
    struct TypeUnwrapper
    { 
        static_assert(std::is_same<VOID, void>::value, "");
        static_assert(std::is_same<T, void>::value, "");
    };
    
    template<typename T>
    struct TypeUnwrapper
    <
        T, 
        typename std::enable_if
        <
            !std::is_same<INTERNAL_CO_UNCONST(T), void*>::value
        >::type
    >
    { 
        using Type = INTERNAL_CO_PURE_TYPE(T);
    };
    
    template<typename T>
    struct TypeUnwrapper
    <
        T, 
        typename std::enable_if
        <
            std::is_same<INTERNAL_CO_UNCONST(T), void*>::value
        >::type
    >
    { 
        using Type = INTERNAL_CO_UNCONST(T);
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverrideResult.hpp
//=================================================================
#ifndef CO_OVERRIDE_RESULT_HPP
#define CO_OVERRIDE_RESULT_HPP



namespace CppOverride
{
    struct OverrideResult
    {
        OverrideStatus Status = OverrideStatus::NO_OVERRIDE;
    };
}

#endif


#include <functional>
#include <string>
#include <vector>

namespace CppOverride
{
    class Overrider;

    class OverrideInfoSetter
    {
        protected:
            std::string FunctionSignatureName;
            Overrider& CppOverrideObj;
        
        public:
            OverrideInfoSetter( std::string functionSignatureName, 
                                Overrider& SimpleOverrideObj) : 
                FunctionSignatureName(functionSignatureName),
                CppOverrideObj(SimpleOverrideObj)
            {}
            
            inline std::string GetFunctionSignatureName() const
            {
                return FunctionSignatureName;
            }
            
            OverrideInfoSetter& Times(int times);
            
            template<typename... Args>
            OverrideInfoSetter& WhenCalledWith(Args... args);
            
            OverrideInfoSetter& If(std::function<bool(const std::vector<void*>& args)> condition);

            OverrideInfoSetter& 
            Otherwise_Do(std::function<void(const std::vector<void*>& args)> action);

            OverrideInfoSetter& 
            WhenCalledExpectedly_Do(std::function<void(const std::vector<void*>& args)> action);
            
            OverrideInfoSetter& AssignOverrideResult(OverrideResult& result);
            
            
            template<typename ReturnType>
            OverrideInfoSetter& ReturnsByAction(std::function<void( const std::vector<void*>& args, 
                                                                    void* out)> returnAction);
    
            template<typename ReturnType>
            OverrideInfoSetter& Returns(typename TypeSpecifier<ReturnType>::Type returnData);
            
            template<typename ReturnType>
            OverrideInfoSetter& Returns();
            
            OverrideInfoSetter& ReturnsVoid();
            
            #ifndef INTERNAL_CO_SET_ARGS_DECL
                #define INTERNAL_CO_SET_ARGS_DECL(...) \
                    template<MPT_PREFIX_SUFFIX_ARGS(typename Arg, Type, __VA_ARGS__)> \
                    OverrideInfoSetter& SetArgs \
                    ( \
                        MPT_COMPOSE4 \
                        ( \
                            MPT_APPEND_LISTS_ITEMS, \
                            ( \
                                MPT_COMPOSE2 \
                                ( \
                                    MPT_PREFIX_SUFFIX_ARGS, \
                                    ( \
                                        typename TypeUnwrapper<Arg, \
                                        Type>::Type, \
                                        __VA_ARGS__ \
                                    ) \
                                ), \
                                MPT_COMPOSE3 \
                                ( \
                                    MPT_COMPOSE2, \
                                    ( \
                                        MPT_CONCAT, \
                                        ( \
                                            MPT_COUNT_TO_, \
                                            MPT_ARGS_COUNT(__VA_ARGS__) \
                                        ) \
                                    )(_, /* no suffix */) \
                                ) \
                            ) \
                        ) \
                    )
                
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_1(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_2(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_3(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_4(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_5(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_6(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_7(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_8(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_9(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_10(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_11(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_12(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_13(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_14(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_15(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_16(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_17(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_18(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_19(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_20(/* no prefix */, /* no suffix */));
            #endif
            
            #undef INTERNAL_CO_SET_ARGS_DECL
            
            template<typename... Args>
            OverrideInfoSetter& 
            SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction);
    };


}

#endif

//=================================================================
//./Include_MultiHeaders/Any.hpp
//=================================================================
#ifndef CO_ANY_HPP
#define CO_ANY_HPP

#include <ostream>

namespace CppOverride
{
    struct Any
    {
        inline bool operator== (Any& other)
        {
            return true;
        }
        
        inline bool operator!= (Any& other)
        {
            return false;
        }

        friend std::ostream& operator<<(std::ostream& os, const Any& other)
        {
            os << "Any";
            return os;
        }
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ReturnDataSetter.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_SETTER_HPP


//=================================================================
//./Include_MultiHeaders/Internal_OverrideData.hpp
//=================================================================
#ifndef CO_INTERNAL_OVERRIDE_DATA_HPP
#define CO_INTERNAL_OVERRIDE_DATA_HPP

//=================================================================
//./Include_MultiHeaders/Internal_ReturnDataActionInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_RETURN_DATA_ACTION_INFO_HPP
#define CO_INTERNAL_RETURN_DATA_ACTION_INFO_HPP

//=================================================================
//./Include_MultiHeaders/Internal_DataInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_DATA_INFO_HPP
#define CO_INTERNAL_DATA_INFO_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_DataInfo
    {
        std::size_t DataType = 0;
        void* Data = nullptr;
        std::function<void*(void*)> CopyConstructor;
        std::function<void(void*)> Destructor;
        bool DataSet = false;
    };
    
    struct Internal_ReturnDataInfo : public Internal_DataInfo
    {
        bool ReturnReference = false;
        bool ReturnAny = false;
    };
}

#endif


namespace CppOverride
{
    struct Internal_ReturnDataActionInfo
    {
        std::function<void(const std::vector<void*>& args, void* out)> DataAction;
        std::size_t DataType = 0;
        bool DataActionSet = false;
        bool ReturnReference = false;
    };
}


#endif

//=================================================================
//./Include_MultiHeaders/Internal_ConditionInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_CONDITION_INFO_HPP
#define CO_INTERNAL_CONDITION_INFO_HPP

//=================================================================
//./Include_MultiHeaders/ArgsInfo.hpp
//=================================================================
#ifndef CO_ARGS_INFO_HPP
#define CO_ARGS_INFO_HPP

#include <cstddef>
#include <functional>

namespace CppOverride
{
    struct ArgInfo
    {
        void* ArgDataPointer = nullptr;
        std::function<void*(void* data)> CopyConstructor;
        std::function<void(void* data)> Destructor;
        size_t ArgSize = 0;
        size_t ArgTypeHash = 0;
        bool ArgSet = false;
    };
}

#endif


#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ConditionInfo
    {
        std::function<bool(const std::vector<void*>& args)> LambdaCondition;
        std::vector<ArgInfo> ArgsCondition = {};
        int Times = -1;
        int CalledTimes = 0;
        bool DataConditionSet = false;
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/Internal_ResultActionInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_RESULT_ACTION_INFO_HPP
#define CO_INTERNAL_RESULT_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ResultActionInfo
    {
        std::function<void(const std::vector<void*>& args)> OtherwiseAction;
        std::function<void(const std::vector<void*>& args)> CorrectAction;
        bool OtherwiseActionSet = false;
        bool CorrectActionSet = false;
    };
}

#endif


//=================================================================
//./Include_MultiHeaders/Internal_ArgsDataActionInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP
#define CO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ArgsDataActionInfo
    {
        std::function<void(std::vector<void*>& args)> DataAction;
        std::vector<std::size_t> DataTypes;
        std::vector<bool> DataTypesSet;
        bool DataActionSet = false;
    };
}


#endif




namespace CppOverride
{
    struct Internal_OverrideData
    {
        //Condition for override
        Internal_ConditionInfo ConditionInfo;
        
        //Arguments and return data
        std::vector<Internal_DataInfo> ArgumentsDataInfo;
        Internal_ReturnDataInfo ReturnDataInfo;
        
        Internal_ReturnDataActionInfo ReturnDataActionInfo;
        Internal_ArgsDataActionInfo  ArgumentsDataActionInfo;
        
        //Result of the override
        Internal_ResultActionInfo ResultActionInfo;
        OverrideStatus* Status = nullptr;
    };
    
    using Internal_OverrideDataList = std::vector<Internal_OverrideData>;
}

#endif

//=================================================================
//./Include_MultiHeaders/StaticAssertFalse.hpp
//=================================================================
#ifndef CO_STATIC_ASSERT_FALSE
#define CO_STATIC_ASSERT_FALSE

#include <type_traits>

namespace CppOverride
{
    template<typename T>
    struct CO_ASSERT_FALSE : std::false_type { };
}

#endif



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

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ArgsDataSetter.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP







//=================================================================
//./Include_MultiHeaders/AliasTypes.hpp
//=================================================================
#ifndef CO_ALIAS_TYPES_HPP
#define CO_ALIAS_TYPES_HPP



using CO_ANY_TYPE = CppOverride::Any;
const CppOverride::Any CO_ANY;
const CppOverride::Any CO_DONT_SET;
const CppOverride::Any CO_DONT_OVERRIDE_RETURN;

#endif


#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ArgsDataSetter
    {
        friend class OverrideInfoSetter;
        
        #define INTERNAL_CO_UNWRAPPED(arg) typename TypeUnwrapper<arg>::Type
        
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            
            #define INTERNAL_CO_LOG_SetArgs 0
            
            #ifndef PRINT_BYTES
                #define PRINT_BYTES(val) \
                    do \
                    { \
                        for(int byteIdx = 0; byteIdx < sizeof(val); byteIdx++) \
                        { \
                            std::cout<<(int)((uint8_t*)&val)[byteIdx] <<", "; \
                        } \
                        std::cout << std::endl; \
                    } while(0)
            #endif
            
            template<typename T, typename... Args>
            inline typename std::enable_if
            <
                !std::is_copy_assignable<INTERNAL_CO_UNWRAPPED(T)>::value && 
                sizeof...(Args) != 0, 
                OverrideInfoSetter&
            >::type
            SetArgs(OverrideInfoSetter& infoSetter,
                    INTERNAL_CO_UNWRAPPED(T) arg, 
                    INTERNAL_CO_UNWRAPPED(Args)... args)
            {
                static_assert(  CO_ASSERT_FALSE<T>::value, 
                                "Cannot modify a non copy assignable object. "
                                "Please use SetArgsByAction instead.");

                return SetArgs<INTERNAL_CO_UNWRAPPED(Args)...>(infoSetter, args...);
            }
            
            template<typename T>
            inline typename std::enable_if
            <
                std::is_copy_assignable<INTERNAL_CO_UNWRAPPED(T)>::value,
                OverrideInfoSetter&
            >::type
            SetArgs(OverrideInfoSetter& infoSetter, INTERNAL_CO_UNWRAPPED(T) arg)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataInfo.push_back(Internal_DataInfo());
                
                if(!std::is_same<T, Any>())
                {
                    lastData.ArgumentsDataInfo.back().Data = new INTERNAL_CO_UNWRAPPED(T)(arg);
                    lastData.ArgumentsDataInfo.back().CopyConstructor = 
                        [](void* data) 
                        { 
                            return new INTERNAL_CO_UNWRAPPED(T)
                            (
                                *static_cast<INTERNAL_CO_UNWRAPPED(T)*>(data)
                            ); 
                        };
                    
                    lastData.ArgumentsDataInfo.back().Destructor = 
                        [](void* data) { delete static_cast<INTERNAL_CO_UNWRAPPED(T)*>(data); };

                    lastData.ArgumentsDataInfo.back().DataSet = true;
                    lastData.ArgumentsDataInfo.back().DataType = 
                        typeid(T).hash_code();

                    if(INTERNAL_CO_LOG_SetArgs)
                    {
                        std::cout << std::endl << __func__ << " called" << std::endl;
                        
                        std::cout <<    "Set args index: " << 
                                        lastData.ArgumentsDataInfo.size() - 1 << std::endl;
                        
                        std::cout << "arg pointer: " << &arg << std::endl;
                        std::cout << "typeid(T).name(): " << typeid(T).name() << std::endl;
                        std::cout <<    "typeid(T).hash_code(): " << 
                                        typeid(T).hash_code() << 
                                        std::endl;
                        
                        //std::cout <<    "Set args value: "<< 
                        //                (*static_cast<INTERNAL_CO_UNCONST_UNREF_T*>
                        //                (
                        //                    lastData.ArgumentsDataInfo.back().Data
                        //                )) << 
                        //                std::endl << 
                        //                std::endl;
                        
                        //std::cout << "Original Data: "<<std::endl;
                        //PRINT_BYTES(arg);
                        
                        //std::cout << "Copied Data: "<<std::endl;
                        //PRINT_BYTES((*static_cast<INTERNAL_CO_UNWRAPPED(T)*>
                        //(
                        //    lastData.ArgumentsDataInfo.back().Data
                        //)));
                        
                        std::cout << std::endl;
                    }
                }
                
                return infoSetter;
            }
            
            template<typename T, typename... Args>
            inline typename std::enable_if
            <
                std::is_copy_assignable<INTERNAL_CO_UNWRAPPED(T)>::value &&
                sizeof...(Args) != 0, 
                OverrideInfoSetter&
            >::type
            SetArgs(OverrideInfoSetter& infoSetter,
                    INTERNAL_CO_UNWRAPPED(T) arg, 
                    INTERNAL_CO_UNWRAPPED(Args)... args)
            {
                SetArgs<T>(infoSetter, arg);
                return SetArgs<Args...>(infoSetter, args...);
            }
            
        private:
            template<typename T>
            inline void InternalPushActionArgTypes(Internal_OverrideData& lastData)
            {
                lastData.ArgumentsDataActionInfo.DataTypes
                        .push_back(typeid(T).hash_code());
                
                if(INTERNAL_CO_LOG_SetArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout <<    "Data Hash: " << typeid(T).hash_code() << std::endl;
                    std::cout <<    "Data Type: " << typeid(T).name() << std::endl;
                }
                
                if(!std::is_same<T, CO_ANY_TYPE>::value)
                    lastData.ArgumentsDataActionInfo.DataTypesSet.push_back(true);
                else
                    lastData.ArgumentsDataActionInfo.DataTypesSet.push_back(false);
            }
            
            template<typename T, typename... Args>
            inline void PushActionArgTypes(Internal_OverrideData& lastData)
            {
                InternalPushActionArgTypes<T>(lastData);
                PushActionArgTypes<Args...>(lastData);
            }
            
            template<typename... Args>
            inline typename std::enable_if<sizeof...(Args) == 0>::type 
            PushActionArgTypes(Internal_OverrideData& lastData)
            {
            }
        
        protected:
            template<typename... Args>
            inline OverrideInfoSetter& 
            SetArgsByAction(OverrideInfoSetter& infoSetter,
                            std::function<void(std::vector<void*>& args)> setArgsAction)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataActionInfo.DataAction = setArgsAction;
                lastData.ArgumentsDataActionInfo.DataActionSet = true;
                
                PushActionArgTypes<Args...>(lastData);
                
                if(INTERNAL_CO_LOG_SetArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout <<    "Target function: " <<
                                    infoSetter.GetFunctionSignatureName() << std::endl;
                    
                    for(int i = 0; i < lastData.ArgumentsDataActionInfo.DataTypes.size(); i++)
                    {
                        std::cout <<    "Data Type[" << i << "]: " << 
                                        lastData.ArgumentsDataActionInfo.DataTypes[i] << std::endl;
                    }
                }
                
                return infoSetter;
            }
            
        #undef INTERNAL_CO_UNCONST_UNREF_T
        #undef INTERNAL_CO_UNCONST_UNREF
        
        public:
            inline Internal_ArgsDataSetter(OverrideDatas& overrideArgumentsInfos) : 
                CurrentOverrideDatas(overrideArgumentsInfos)
            {}
    };
}


#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_RequirementSetter.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP








#include <cassert>
#include <unordered_map>
#include <iostream>
#include <type_traits>

namespace CppOverride
{
    class Internal_RequirementSetter
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
            friend class OverrideInfoSetter;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
        
            //------------------------------------------------------------------------------
            //Methods for setting requirements
            //------------------------------------------------------------------------------
            inline OverrideInfoSetter& Times(OverrideInfoSetter& infoSetter, int times)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .Times = times;
                
                return infoSetter;
            }
            
            inline OverrideInfoSetter& WhenCalledWith(OverrideInfoSetter& infoSetter)
            {
                return infoSetter;
            }

            template<typename T, typename... Args>
            inline OverrideInfoSetter& WhenCalledWith(  OverrideInfoSetter& infoSetter,
                                                        T arg, 
                                                        Args... args)
            {
                ArgInfo curArg;
                if(!std::is_same<T, Any>())
                {
                    curArg.ArgDataPointer = new T(arg);
                    curArg.CopyConstructor = [](void* data) { return new T(*static_cast<T*>(data)); };
                    curArg.Destructor = [](void* data){ delete static_cast<T*>(data); };
                    curArg.ArgSize = sizeof(T);
                    curArg.ArgTypeHash = typeid(T).hash_code();
                    curArg.ArgSet = true;
                    
                    #if 0
                        std::cout << "typeid(T).name(): "<<typeid(T).name() <<"\n";
                        std::cout << "sizeof(T): " << sizeof(T) << "\n";
                        std::cout << "typeid(T).hash_code(): " << typeid(T).hash_code() << "\n";
                    #endif
                }

                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .ArgsCondition
                                                                            .push_back(curArg);

                return WhenCalledWith(infoSetter, args...);
            }
            
            inline OverrideInfoSetter& 
            If( OverrideInfoSetter& infoSetter, 
                std::function<bool(const std::vector<void*>& args)> condition)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .LambdaCondition = condition;
                        
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .DataConditionSet = true;

                return infoSetter;
            }
            
            inline OverrideInfoSetter& 
            Otherwise_Do(   OverrideInfoSetter& infoSetter, 
                            std::function<void(const std::vector<void*>& args)> action)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .OtherwiseAction = action;
                    
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .OtherwiseActionSet = true;
                
                return infoSetter;
            }
            
            inline OverrideInfoSetter& 
            WhenCalledExpectedly_Do(OverrideInfoSetter& infoSetter, 
                                    std::function<void(const std::vector<void*>& args)> action)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .CorrectAction = action;
                
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .CorrectActionSet = true;

                return infoSetter;
            }
            
            inline OverrideInfoSetter& AssignOverrideResult(OverrideInfoSetter& infoSetter, 
                                                            OverrideResult& result)
            {
                Internal_OverrideData& currentData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                currentData.Status = &result.Status;
                return infoSetter;
            }
            
        
        public:
            Internal_RequirementSetter(OverrideDatas& overrideDataLists) :
                CurrentOverrideDatas(overrideDataLists)
            {}
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ArgsValuesAppender.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_VALUES_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_VALUES_APPENDER_HPP


#include <vector>

namespace CppOverride
{
    class Internal_ArgsValuesAppender
    {
        friend class Internal_ReturnDataValidator;
        friend class Internal_ArgsDataValidator;
        friend class Internal_RequirementValidator;
        
        protected:
            //Appending arguments from function calls
            inline void AppendArgsValues(std::vector<void*>& argumentsList){};

            template<typename T, typename... Args>
            inline void AppendArgsValues(std::vector<void*>& argumentsList, T& arg, Args&... args)
            {
                argumentsList.push_back((INTERNAL_CO_UNCONST(T)*)&arg);
                AppendArgsValues(argumentsList, args...);
            }
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ArgsTypeInfoAppender.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP




#include <iostream>
#include <vector>
namespace CppOverride
{
    class Internal_ArgsTypeInfoAppender
    {
        friend class Internal_ArgsDataValidator;
        
        protected:
            #define INTERNAL_CO_LOG_AppendArgsTypeInfo 0
            
            inline void AppendArgsTypeInfo(std::vector<ArgInfo>& argumentsList) {}
            
            template<   typename T, 
                        typename... Args>
            inline void AppendArgsTypeInfo( std::vector<ArgInfo>& argumentsList, 
                                            T& arg, 
                                            Args&... args)
            {
                ArgInfo curArgInfo;
                if(!std::is_same<T, Any>())
                {
                    curArgInfo.ArgSize = sizeof(T);
                    curArgInfo.ArgTypeHash = typeid(T).hash_code();
                    curArgInfo.ArgSet = true;
                }
                
                if(INTERNAL_CO_LOG_AppendArgsTypeInfo)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Type: " << typeid(T).name() << std::endl;
                    std::cout << "Hash: " << typeid(T).hash_code() << std::endl;
                }

                argumentsList.push_back(curArgInfo);
                AppendArgsTypeInfo(argumentsList, args...);
            }
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ConditionArgsTypesChecker.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_TYPES_CHECKER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_TYPES_CHECKER_HPP




#include <vector>
#include <iostream>

namespace CppOverride
{
    class Internal_ConditionArgsTypesChecker
    {
        friend class Internal_ReturnDataValidator;
        friend class Internal_ArgsDataValidator;
        friend class Internal_RequirementValidator;
        
        protected:
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex) { return true; };

            #define INTERNAL_CO_NON_CONST_T INTERNAL_CO_UNCONST(T)

            #define INTERNAL_CO_LOG_CheckArguments 0

            //Check Value or reference
            template<typename T, typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            T& arg, 
                                            Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    if( sizeof(INTERNAL_CO_NON_CONST_T) != validArgumentsList[argIndex].ArgSize &&
                        sizeof(INTERNAL_CO_NON_CONST_T*) != validArgumentsList[argIndex].ArgSize)
                    {
                        return false;
                    }

                    if( typeid(INTERNAL_CO_NON_CONST_T).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash &&
                        typeid(INTERNAL_CO_NON_CONST_T*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        return false;
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
            }
            
            //Check Pointer or value
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            T*& arg, 
                                            Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    if( sizeof(INTERNAL_CO_NON_CONST_T*) != validArgumentsList[argIndex].ArgSize &&
                        sizeof(INTERNAL_CO_NON_CONST_T) != validArgumentsList[argIndex].ArgSize)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "sizeof(INTERNAL_CO_NON_CONST_T): " <<
                                            sizeof(INTERNAL_CO_NON_CONST_T) <<
                                            "\n";
                            
                            std::cout << "sizeof(T): "<<sizeof(T)<<"\n";
                            std::cout <<    "validArgumentsList[" << 
                                            argIndex << 
                                            "].ArgSize: " << 
                                            validArgumentsList[argIndex].ArgSize <<
                                            "\n";
                        }
                        return false;
                    }

                    if( typeid(INTERNAL_CO_NON_CONST_T*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash &&
                        typeid(INTERNAL_CO_NON_CONST_T).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "typeid(INTERNAL_CO_NON_CONST_T).hash_code(): " <<
                                            typeid(INTERNAL_CO_NON_CONST_T).hash_code() << 
                                            "\n";
                            
                            std::cout <<    "validArgumentsList["
                                            <<argIndex << 
                                            "].ArgTypeHash: " <<
                                            validArgumentsList[argIndex].ArgTypeHash <<
                                            "\n";
                        }
                        return false;
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            const T& arg, 
                                            Args&... args)
            {
                return CheckArgumentsTypes( validArgumentsList, 
                                            argIndex, 
                                            const_cast<INTERNAL_CO_NON_CONST_T&>(arg), 
                                            args...);
            }

        #undef INTERNAL_CO_NON_CONST_T
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ConditionArgsValuesChecker.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_VALUES_CHECKER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_VALUES_CHECKER_HPP




//=================================================================
//./Include_MultiHeaders/TypeCheck.hpp
//=================================================================
#ifndef CO_TYPE_CHECK_HPP
#define CO_TYPE_CHECK_HPP

#include <type_traits>
namespace CppOverride
{
    template<typename T, typename = void>
    struct InequalExists : std::false_type {};
    
    template<typename T>
    struct InequalExists<T, decltype(std::declval<T>() != std::declval<T>(), void())> : std::true_type {};
}

#endif



#include <cassert>
#include <type_traits>
#include <vector>
#include <iostream>


namespace CppOverride
{
    class Internal_ConditionArgsValuesChecker
    {
        friend class Internal_ReturnDataValidator;
        friend class Internal_ArgsDataValidator;
        friend class Internal_RequirementValidator;
        
        protected:
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex,
                                                OverrideStatus& status) { return true; };

            #define INTERNAL_CO_LOG_CheckArgumentsValues 0

            template<   typename T, 
                        typename = typename std::enable_if<!InequalExists<T>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //NOTE: Cannot check data that doesn't have inequal operator
                    status = OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR;
                    return false;
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<InequalExists<T>::value>::type,
                        typename... Args,
                        typename = void()>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout << "CheckArgumentsValues index: " << argIndex << std::endl;
                }

                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    const ArgInfo& curArgInfo = validArgumentsList[argIndex];
                    
                    //Check Reference (Which is converted to pointer when checking)
                    if( sizeof(INTERNAL_CO_UNCONST(T)*) == curArgInfo.ArgSize &&
                        typeid(INTERNAL_CO_UNCONST(T)*).hash_code() == curArgInfo.ArgTypeHash)
                    {
                        if( &arg != *(INTERNAL_CO_UNCONST(T)**)(curArgInfo.ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else if(arg != *static_cast<INTERNAL_CO_UNCONST(T)*>(curArgInfo.ArgDataPointer))
                        return false;
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type,
                        typename = typename std::enable_if<InequalExists<T>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T*& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    const ArgInfo& curArgInfo = validArgumentsList[argIndex];
                    
                    //Check Pointer
                    if( sizeof(INTERNAL_CO_UNCONST(T)*) == curArgInfo.ArgSize &&
                        typeid(INTERNAL_CO_UNCONST(T)*).hash_code() == curArgInfo.ArgTypeHash)
                    {
                        if(arg != *(INTERNAL_CO_UNCONST(T)**)(curArgInfo.ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else
                    {
                        return CheckArgumentsValues(validArgumentsList, 
                                                    argIndex, 
                                                    status, 
                                                    *arg, 
                                                    args...);
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                void*& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
                
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check void Pointer
                    if( sizeof(void*) != validArgumentsList[argIndex].ArgSize ||
                        typeid(void*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash ||
                        arg != *(void**)(validArgumentsList[argIndex].ArgDataPointer))
                    {
                        return false;
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                const T& arg, 
                                                Args&... args)
            {
                return CheckArgumentsValues(validArgumentsList, 
                                            argIndex, 
                                            status,
                                            const_cast<INTERNAL_CO_UNCONST(T)&>(arg), 
                                            args...);
            }
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ArgsModifier.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_MODIFIER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_MODIFIER_HPP







#include <cassert>
#include <cstdint>
#include <vector>
#include <iostream>
#include <type_traits>

namespace CppOverride 
{
    class Internal_ArgsModifier
    {
        protected:
            #define INTERNAL_CO_LOG_ModifyArgs 0
        
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index,
                                    OverrideStatus* status) {}

            template<   typename T, 
                        typename = typename std::enable_if<!std::is_copy_assignable<T>::value>::type,
                        typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T& arg, 
                                    Args&... args)
            {
                if(argsData[index].DataSet)
                {
                    //NOTE: Cannot modify data that are not copy assignable
                    if(status != nullptr)
                        *status = OverrideStatus::MODIFY_NON_ASSIGNABLE_ARG_ERROR;
                    
                    return;
                }
                
                ModifyArgs(argsData, ++index, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<std::is_copy_assignable<T>::value>::type,
                        typename... Args,
                        typename = void()>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T& arg, 
                                    Args&... args)
            {
                if(argsData[index].DataSet)
                {
                    INTERNAL_CO_UNCONST(T)& pureArg = const_cast<INTERNAL_CO_UNCONST(T)&>(arg); 
                    pureArg = *static_cast<INTERNAL_CO_UNCONST(T)*>(argsData[index].Data);
                    if(INTERNAL_CO_LOG_ModifyArgs)
                    {
                        std::cout << std::endl << __func__ << " called" << std::endl;
                        std::cout << "&arg: " << &arg << std::endl;
                        
                        #ifndef PRINT_BYTES
                            #define PRINT_BYTES(val) \
                                do \
                                { \
                                    for(int byteIdx = 0; byteIdx < sizeof(val); byteIdx++) \
                                    { \
                                        std::cout<<(int)((uint8_t*)&val)[byteIdx] <<", "; \
                                    } \
                                    std::cout << std::endl; \
                                } while(0)
                        #endif
                        
                        std::cout << "modified index: "<<index << std::endl;
                        std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                        std::cout <<    "typeid(arg).hash_code(): " << 
                                        typeid(arg).hash_code() <<
                                        std::endl;
                        
                        std::cout <<    "argsData[index].DataType: " << 
                                        argsData[index].DataType <<
                                        std::endl;
                        
                        //std::cout << "arg value: "<< arg << std::endl;
                        //std::cout <<    "modified value: "<< 
                        //                (*static_cast<T*>(argsData[index].Data)) << 
                        //                std::endl << 
                        //                std::endl;

                        std::cout << "modified value bytes:" << std::endl;
                        
                        PRINT_BYTES((*static_cast<T*>(argsData[index].Data)));
                        std::cout << std::endl;
                    }
                }

                ModifyArgs(argsData, ++index, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T*& arg, 
                                    Args&... args)
            {
                ModifyArgs(argsData, index, status, *arg, args...);
            }
            
            template<typename T, typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    const T& arg, 
                                    Args&... args)
            {
                if(INTERNAL_CO_LOG_ModifyArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "modified index: "<<index << std::endl;
                    std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                    std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                    //std::cout << "arg value: "<< arg << std::endl;
                    std::cout << "argsData[index].DataSet: " << argsData[index].DataSet << std::endl;
                    std::cout << std::endl;
                }
                
                if(argsData[index].DataSet)
                {
                    //NOTE: Data cannot be set for const arguments
                    if(status != nullptr)
                        *status = OverrideStatus::MODIFY_CONST_ARG_ERROR;
                    
                    return;
                }

                ModifyArgs(argsData, ++index, status, args...);
            }

            template<typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    const Any& arg, 
                                    Args&... args)
            {
                if(INTERNAL_CO_LOG_ModifyArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std ::cout <<"Skipping ModifyArgs for index "<<index << " for Any\n";
                }
                
                ModifyArgs(argsData, ++index, status, args...);
            }
            
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    Internal_ArgsDataActionInfo& argsDataAction)
            {
                if(argsDataAction.DataActionSet)
                    argsDataAction.DataAction(argumentsList);
            }
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ReturnDataRetriever.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_RETRIEVER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_RETRIEVER_HPP









#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ReturnDataRetriever
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
        
            #define INTERNAL_CO_LOG_GetCorrectReturnDataInfo 0

            template<   typename ReturnType, 
                        typename... Args>
            inline int GetCorrectReturnDataInfo(std::string functionName, 
                                                OverrideStatus& outInternalStatus,
                                                Args&... args)
            {
                if(CurrentOverrideDatas.find(functionName) == CurrentOverrideDatas.end())
                {
                    //NOTE: This should be checked before calling this
                    outInternalStatus = OverrideStatus::INTERNAL_MISSING_CHECK_ERROR;
                    return -1;
                }
                
                if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<Internal_OverrideData>& curOverrideData = 
                    CurrentOverrideDatas[functionName];
                
                int returnIndex = -1;
                for(int i = 0; i < curOverrideData.size(); i++)
                {
                    if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                        std::cout << "Checking return data[" << i << "]" << std::endl;

                    //Check override return data exist
                    if(curOverrideData[i].ReturnDataInfo.DataSet)
                    {
                        //Check return type match
                        if( curOverrideData[i].ReturnDataInfo.DataType != 
                            typeid(ReturnType).hash_code())
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return type" << std::endl;
                            
                            continue;
                        }
                        
                        //If we need to return a reference, 
                        //  we check for pointer type as we can't store references
                        if( std::is_reference<ReturnType>() && 
                            !curOverrideData[i].ReturnDataInfo.ReturnReference)
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return reference" << std::endl;
                            
                            continue;
                        }
                    }
                    else if(curOverrideData[i].ReturnDataActionInfo.DataActionSet)
                    {
                        //Check return type match
                        if( curOverrideData[i].ReturnDataActionInfo.DataType != 
                            typeid(ReturnType).hash_code())
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return type" << std::endl;
                            
                            continue;
                        }
                        
                        //If we need to return a reference, 
                        //  we check for pointer type as we can't store references
                        if( std::is_reference<ReturnType>() && 
                            !curOverrideData[i].ReturnDataActionInfo.ReturnReference)
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return action reference" << std::endl;
                            
                            continue;
                        }
                    }
                    else if(curOverrideData[i].ReturnDataInfo.ReturnAny)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Any return type entry encountered" << std::endl;
                    }
                    else
                        continue;
                    
                    //Check parameter condition types/count match
                    if( !curOverrideData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curOverrideData[i]  .ConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check parameter" << std::endl;
                        
                        continue;
                    }
                    
                    //Check parameter values
                    if( !curOverrideData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curOverrideData[i]  .ConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                outInternalStatus,
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check parameter" << std::endl;
                        
                        if(curOverrideData.at(i).Status != nullptr)
                        {
                            *curOverrideData.at(i).Status = 
                                OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                        }
                        
                        if(curOverrideData[i].ResultActionInfo.OtherwiseActionSet)
                            curOverrideData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    
                    //Check condition lambda
                    if( curOverrideData[i].ConditionInfo.DataConditionSet && 
                        !curOverrideData[i].ConditionInfo.LambdaCondition(argumentsList))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check condition" << std::endl;
                        
                        if(curOverrideData[i].Status != nullptr)
                        {
                            *curOverrideData[i].Status = 
                                OverrideStatus::MATCHING_CONDITION_ACTION_FAILED;
                        }
                        
                        if(curOverrideData[i].ResultActionInfo.OtherwiseActionSet)
                            curOverrideData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curOverrideData[i].ConditionInfo.Times >= 0 && 
                        curOverrideData[i].ConditionInfo.CalledTimes >= 
                        curOverrideData[i].ConditionInfo.Times)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check times" << std::endl;
                        
                        if(curOverrideData[i].Status != nullptr)
                        {
                            *curOverrideData[i].Status = 
                                OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                        }
                        
                        if(curOverrideData[i].ResultActionInfo.OtherwiseActionSet)
                            curOverrideData[i].ResultActionInfo.OtherwiseAction(argumentsList);

                        continue;
                    }
                    
                    if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                        std::cout << "Return data found: " << i << std::endl;
                    
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        public:
            inline Internal_ReturnDataRetriever(OverrideDatas& overrideDataLists,
                                                Internal_ArgsValuesAppender& argsValuesAppender,
                                                Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                                Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                CurrentOverrideDatas(overrideDataLists),
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ArgsDataRetriever.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP









#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsDataRetriever
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypeInfoAppender& ArgsTypeInfoAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
            
            #define INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo 0

            template<typename... Args>
            inline int GetCorrectArgumentsDataInfo( std::string functionName, 
                                                    OverrideStatus& outInternalStatus,
                                                    Args&... args)
            {
                if(CurrentOverrideDatas.find(functionName) == CurrentOverrideDatas.end())
                {
                    //NOTE: This should be checked before calling this
                    outInternalStatus = OverrideStatus::INTERNAL_MISSING_CHECK_ERROR;
                    return -1;
                }
                
                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<ArgInfo> argumentsTypesList;
                ArgsTypeInfoAppender.AppendArgsTypeInfo(argumentsTypesList, args...);
                
                std::vector<Internal_OverrideData>& curData = CurrentOverrideDatas[functionName];
                
                int returnIndex = -1;
                for(int i = 0; i < curData.size(); i++)
                {
                    if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                        std::cout << "Checking arg data[" << i << "]\n";
                    
                    //Check override argument data types match
                    int argumentTypeFailedIndex = -1;
                    
                    if( curData[i].ArgumentsDataActionInfo.DataActionSet && 
                        !argumentsTypesList.empty() &&
                        curData[i].ArgumentsDataActionInfo.DataTypes.size() == 
                            argumentsTypesList.size())
                    {
                        std::vector<std::size_t>& argTypeHashes = 
                            curData[i].ArgumentsDataActionInfo.DataTypes;
                        
                        std::vector<bool>& argsTypesSet = 
                            curData[i].ArgumentsDataActionInfo.DataTypesSet;
                        
                        for(int j = 0; j < argTypeHashes.size(); j++)
                        {
                            if( argsTypesSet[j] &&
                                argTypeHashes[j] != argumentsTypesList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                
                                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                                {
                                    std::cout <<    "argTypeHashes[" << j << "]: " << 
                                                    argTypeHashes[j] << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].ArgTypeHash: " <<
                                                    argumentsTypesList[j].ArgTypeHash << std::endl;
                                }
                                
                                break;
                            }
                        }
                    }
                    //Check set argument data counts match
                    else if(curData[i].ArgumentsDataInfo.size() == argumentsTypesList.size() &&
                            !argumentsTypesList.empty())
                    {
                        for(int j = 0; j < curData[i].ArgumentsDataInfo.size(); j++)
                        {
                            bool overrideArg =  curData[i].ArgumentsDataInfo[j].DataSet;

                            if( overrideArg && 
                                curData[i].ArgumentsDataInfo[j].DataType != 
                                    argumentsTypesList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                
                                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                                {
                                    std::cout << "Failed at checking argument data type" << std::endl;
                                    std::cout <<    "curData[i].ArgumentsDataInfo[" << j << "]: " << 
                                                    curData[i].ArgumentsDataInfo[j].DataType << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].ArgTypeHash: " <<
                                                    argumentsTypesList[j].ArgTypeHash << std::endl;
                                }
                                
                                break;
                            }
                        }
                    }
                    else
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check set argument data exist" << std::endl;
                        
                        continue;
                    }
                    
                    if(argumentTypeFailedIndex >= 0)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                        {
                            std::cout <<    "Failed at Check set argument data types at index " <<
                                            argumentTypeFailedIndex << std::endl;
                        }
                        
                        continue;
                    }
                    
                    //Check parameter condition types/count match
                    if( !curData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curData[i]  .ConditionInfo
                                                                            .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check parameter type" << std::endl;
                        
                        continue;
                    }
                    
                    //Check parameter values
                    if( !curData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curData[i]  .ConditionInfo
                                                                            .ArgsCondition, 
                                                                0, 
                                                                outInternalStatus,
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check parameter value" << std::endl;
                        
                        if(curData[i].Status != nullptr)
                            *curData[i].Status = OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check condition lambda
                    if( curData[i].ConditionInfo.DataConditionSet && 
                        !curData[i].ConditionInfo.LambdaCondition(argumentsList))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check condition" << std::endl;
                        
                        if(curData[i].Status != nullptr)
                            *curData[i].Status = OverrideStatus::MATCHING_CONDITION_ACTION_FAILED;
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curData[i].ConditionInfo.Times >= 0 && 
                        curData[i].ConditionInfo.CalledTimes >= 
                            curData[i].ConditionInfo.Times)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check times" << std::endl;
                        
                        if(curData[i].Status != nullptr)
                        {
                            *curData[i].Status = 
                                OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                        }
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        continue;
                    }
                    
                    if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                        std::cout << "Argument data found: " << i << std::endl;
                    
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        
        public:
            Internal_ArgsDataRetriever( OverrideDatas& overrideArgumentsInfos,
                                        Internal_ArgsValuesAppender& argsValuesAppender,
                                        Internal_ArgsTypeInfoAppender& argsTypeInfoAppender,
                                        Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                        Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                                                CurrentOverrideDatas(overrideArgumentsInfos),
                                                ArgsValuesAppender(argsValuesAppender),
                                                ArgsTypeInfoAppender(argsTypeInfoAppender),
                                                ArgsTypesChecker(argsTypesChecker),
                                                ArgsValuesChecker(argsValuesChecker)
            {}
    };

}

#endif


//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ReturnDataValidator.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_VALIDATOR_HPP









#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ReturnDataValidator
    {
        protected:
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
        
            #define INTERNAL_CO_LOG_IsCorrectReturnDataInfo 0

            template<   typename ReturnType, 
                        typename... Args>
            inline bool IsCorrectReturnDataInfo(Internal_OverrideData& overrideDataToCheck,
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                    std::cout << "Checking return data" << std::endl;

                //Check override return data exist
                if(overrideDataToCheck.ReturnDataInfo.DataSet)
                {
                    //Check return type match
                    if(overrideDataToCheck.ReturnDataInfo.DataType != typeid(ReturnType).hash_code())
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return type" << std::endl;
                        
                        return false;
                    }
                    
                    //If we need to return a reference, 
                    //  we check for pointer type as we can't store references
                    if( std::is_reference<ReturnType>() && 
                        !overrideDataToCheck.ReturnDataInfo.ReturnReference)
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return reference" << std::endl;
                        
                        return false;
                    }
                }
                else if(overrideDataToCheck.ReturnDataActionInfo.DataActionSet)
                {
                    //Check return type match
                    if( overrideDataToCheck.ReturnDataActionInfo.DataType != 
                        typeid(ReturnType).hash_code())
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return type" << std::endl;
                        
                        return false;
                    }
                    
                    //If we need to return a reference, 
                    //  we check for pointer type as we can't store references
                    if( std::is_reference<ReturnType>() && 
                        !overrideDataToCheck.ReturnDataActionInfo.ReturnReference)
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return action reference" << std::endl;
                        
                        return false;
                    }
                }
                else if(overrideDataToCheck.ReturnDataInfo.ReturnAny)
                {
                    if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                        std::cout << "Any return type entry encountered" << std::endl;
                }
                else
                    return false;
                
                if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                    std::cout << "Return data found" << std::endl;
                
                return true;
            }
        public:
            inline Internal_ReturnDataValidator(Internal_ArgsValuesAppender& argsValuesAppender,
                                                Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                                Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_ArgsDataValidator.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_VALIDATOR_HPP









#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsDataValidator
    {
        protected:
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypeInfoAppender& ArgsTypeInfoAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
            
            #define INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo 0

            template<typename... Args>
            inline bool IsCorrectArgumentsDataInfo( Internal_OverrideData& overrideDataToCheck,
                                                    Args&... args)
            {
                
                if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<ArgInfo> argumentsTypesList;
                ArgsTypeInfoAppender.AppendArgsTypeInfo(argumentsTypesList, args...);
                
                if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    std::cout << "Checking arg data\n";
                
                //Check override argument data types match
                int argumentTypeFailedIndex = -1;
                
                if( overrideDataToCheck.ArgumentsDataActionInfo.DataActionSet && 
                    !argumentsTypesList.empty() &&
                    overrideDataToCheck.ArgumentsDataActionInfo.DataTypes.size() == 
                        argumentsTypesList.size())
                {
                    std::vector<std::size_t>& argTypeHashes = 
                        overrideDataToCheck.ArgumentsDataActionInfo.DataTypes;
                    
                    std::vector<bool>& argsTypesSet = 
                        overrideDataToCheck.ArgumentsDataActionInfo.DataTypesSet;
                    
                    for(int i = 0; i < argTypeHashes.size(); i++)
                    {
                        if( argsTypesSet[i] &&
                            argTypeHashes[i] != argumentsTypesList[i].ArgTypeHash)
                        {
                            argumentTypeFailedIndex = i;
                            
                            if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                            {
                                std::cout <<    "argTypeHashes[" << i << "]: " << 
                                                argTypeHashes[i] << std::endl;
                                std::cout <<    "deRefArgumentsList[" << i << "].ArgTypeHash: " <<
                                                argumentsTypesList[i].ArgTypeHash << std::endl;
                            }
                            
                            break;
                        }
                    }
                }
                //Check set argument data counts match
                else if(overrideDataToCheck.ArgumentsDataInfo.size() == argumentsTypesList.size() &&
                        !argumentsTypesList.empty())
                {
                    for(int i = 0; i < overrideDataToCheck.ArgumentsDataInfo.size(); i++)
                    {
                        bool overrideArg =  overrideDataToCheck.ArgumentsDataInfo[i].DataSet;

                        if( overrideArg && 
                            overrideDataToCheck.ArgumentsDataInfo[i].DataType != 
                                argumentsTypesList[i].ArgTypeHash)
                        {
                            argumentTypeFailedIndex = i;
                            
                            if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                            {
                                std::cout << "Failed at checking argument data type" << std::endl;
                                std::cout <<    "overrideDataToCheck.ArgumentsDataInfo[" << i << "]: " << 
                                                overrideDataToCheck.ArgumentsDataInfo[i].DataType << std::endl;
                                std::cout <<    "deRefArgumentsList[" << i << "].ArgTypeHash: " <<
                                                argumentsTypesList[i].ArgTypeHash << std::endl;
                            }
                            
                            break;
                        }
                    }
                }
                else
                {
                    if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                        std::cout << "Failed at Check set argument data exist" << std::endl;
                    
                    return false;
                }
                
                if(argumentTypeFailedIndex >= 0)
                {
                    if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    {
                        std::cout <<    "Failed at Check set argument data types at index " <<
                                        argumentTypeFailedIndex << std::endl;
                    }
                    
                    return false;
                }
                
                
                if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    std::cout << "Argument data found " <<  std::endl;
                
                return true;
            }
        
        public:
            Internal_ArgsDataValidator( Internal_ArgsValuesAppender& argsValuesAppender,
                                        Internal_ArgsTypeInfoAppender& argsTypeInfoAppender,
                                        Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                        Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                                                ArgsValuesAppender(argsValuesAppender),
                                                ArgsTypeInfoAppender(argsTypeInfoAppender),
                                                ArgsTypesChecker(argsTypesChecker),
                                                ArgsValuesChecker(argsValuesChecker)
            {}
    };

}

#endif

//=================================================================
//./Include_MultiHeaders/OverriderComponents/Internal_RequirementValidator.hpp
//=================================================================
#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_VALIDATOR_HPP









#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_RequirementValidator
    {
        protected:
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
        
            #define INTERNAL_CO_LOG_IsCorrectDataInfo 0

            template<   typename ReturnType, 
                        typename... Args>
            inline bool IsMeetingRequirementForDataInfo(Internal_OverrideData& overrideDataToCheck,
                                                        OverrideStatus& outInternalStatus,
                                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << "Checking override data" << std::endl;

                //Check parameter condition types/count match
                if( !overrideDataToCheck.ConditionInfo.ArgsCondition.empty() && 
                    !ArgsTypesChecker.CheckArgumentsTypes(  overrideDataToCheck .ConditionInfo
                                                                                .ArgsCondition, 
                                                            0, 
                                                            args...))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check parameter" << std::endl;
                    
                    return false;
                }
                
                //Check parameter values
                if( !overrideDataToCheck.ConditionInfo.ArgsCondition.empty() && 
                    !ArgsValuesChecker.CheckArgumentsValues(overrideDataToCheck .ConditionInfo
                                                                                .ArgsCondition, 
                                                            0, 
                                                            outInternalStatus,
                                                            args...))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check parameter" << std::endl;
                    
                    if(overrideDataToCheck.Status != nullptr)
                        *overrideDataToCheck.Status = OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                    
                    if(overrideDataToCheck.ResultActionInfo.OtherwiseActionSet)
                        overrideDataToCheck.ResultActionInfo.OtherwiseAction(argumentsList);
                    
                    return false;
                }
                
                
                //Check condition lambda
                if( overrideDataToCheck.ConditionInfo.DataConditionSet && 
                    !overrideDataToCheck.ConditionInfo.LambdaCondition(argumentsList))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check condition" << std::endl;
                    
                    if(overrideDataToCheck.Status != nullptr)
                        *overrideDataToCheck.Status = OverrideStatus::MATCHING_CONDITION_ACTION_FAILED;
                    
                    if(overrideDataToCheck.ResultActionInfo.OtherwiseActionSet)
                        overrideDataToCheck.ResultActionInfo.OtherwiseAction(argumentsList);
                    
                    return false;
                }
                
                //Check times
                if( overrideDataToCheck.ConditionInfo.Times >= 0 && 
                    overrideDataToCheck.ConditionInfo.CalledTimes >= 
                    overrideDataToCheck.ConditionInfo.Times)
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check times" << std::endl;
                    
                    if(overrideDataToCheck.Status != nullptr)
                        *overrideDataToCheck.Status = OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                    
                    if(overrideDataToCheck.ResultActionInfo.OtherwiseActionSet)
                        overrideDataToCheck.ResultActionInfo.OtherwiseAction(argumentsList);

                    return false;
                }
                
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << "Override data found" << std::endl;
                
                return true;
            }
        public:
            inline Internal_RequirementValidator(   Internal_ArgsValuesAppender& argsValuesAppender,
                                                    Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                                    Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif




//=================================================================
//./Include_MultiHeaders/EarlyReturn.hpp
//=================================================================
#ifndef CO_EARLY_RETURN_HPP
#define CO_EARLY_RETURN_HPP

#include <type_traits>

namespace CppOverride
{
    template<   typename T,
                typename = typename std::enable_if<!std::is_reference<T>::value>::type,
                typename = typename std::enable_if<!std::is_reference<T>::value>::type>
    T EarlyReturn()
    {
        return T();
    }
    
    template<   typename T,
                typename = typename std::enable_if<std::is_reference<T>::value>::type>
    T EarlyReturn()
    {
        typename std::remove_reference<T>::type* dummy = nullptr;
        return *dummy;
    }
    
}

#endif


#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Overrider :   public Internal_ReturnDataSetter, 
                        public Internal_ArgsDataSetter,
                        public Internal_RequirementSetter,
                        public Internal_ArgsValuesAppender,
                        public Internal_ArgsTypeInfoAppender,
                        public Internal_ConditionArgsTypesChecker,
                        public Internal_ConditionArgsValuesChecker,
                        public Internal_ArgsModifier,
                        public Internal_ReturnDataValidator,
                        public Internal_ArgsDataValidator,
                        public Internal_RequirementValidator
                        //public Internal_ReturnDataRetriever,
                        //public Internal_ArgsDataRetriever
    {
        private:
            std::unordered_map<std::string, Internal_OverrideDataList> OverrideDatas;


        //==============================================================================
        //Public facing methods for overriding returns or arguments
        //==============================================================================
        public:
            inline Overrider(const Overrider& other) :
                Internal_ReturnDataSetter(OverrideDatas),
                Internal_ArgsDataSetter(OverrideDatas),
                Internal_RequirementSetter(OverrideDatas),
                Internal_ReturnDataValidator(*this, *this, *this),
                Internal_ArgsDataValidator(*this, *this, *this, *this),
                Internal_RequirementValidator(*this, *this, *this)
                //Internal_ReturnDataRetriever(OverrideDatas, *this, *this, *this),
                //Internal_ArgsDataRetriever(OverrideDatas, *this, *this, *this, *this)
            {
                *this = other;
            }
            
            inline Overrider& operator=(const Overrider& other)
            {
                if(this == &other)
                    return *this;
            
                OverrideDatas = other.OverrideDatas;
            
                //For each function
                for(auto it = OverrideDatas.begin(); it != OverrideDatas.end(); it++)
                {
                    //For each override
                    for(int i = 0; i < it->second.size(); i++)
                    {
                        for(int j = 0; j < it->second[i].ConditionInfo.ArgsCondition.size(); j++)
                        {
                            ArgInfo& currentInfo = it->second[i].ConditionInfo.ArgsCondition[j];
                            
                            if(currentInfo.ArgSet)
                            {
                                currentInfo.ArgDataPointer = 
                                    currentInfo.CopyConstructor(currentInfo.ArgDataPointer);
                            }
                        }
                        
                        for(int j = 0; j < it->second[i].ArgumentsDataInfo.size(); j++)
                        {
                            Internal_DataInfo& currentInfo = it->second[i].ArgumentsDataInfo[j];
                            
                            if(currentInfo.DataSet)
                            {
                                currentInfo.Data = 
                                    currentInfo.CopyConstructor(currentInfo.Data);
                            }
                        }
                        
                        {
                            Internal_ReturnDataInfo& currentInfo = it->second[i].ReturnDataInfo;
                            
                            if(currentInfo.DataSet)
                            {
                                currentInfo.Data = 
                                    currentInfo.CopyConstructor(currentInfo.Data);
                            }
                        }
                    }
                }
                
                return *this;
            }
                
            inline Overrider() :    Internal_ReturnDataSetter(OverrideDatas),
                                    Internal_ArgsDataSetter(OverrideDatas),
                                    Internal_RequirementSetter(OverrideDatas),
                                    Internal_ReturnDataValidator(*this, *this, *this),
                                    Internal_ArgsDataValidator(*this, *this, *this, *this),
                                    Internal_RequirementValidator(*this, *this, *this)
                                    //Internal_ReturnDataRetriever(   OverrideDatas, 
                                    //                                *this, 
                                    //                                *this,
                                    //                                *this),
                                    //Internal_ArgsDataRetriever( OverrideDatas, 
                                    //                            *this, 
                                    //                            *this, 
                                    //                            *this,
                                    //                            *this)
            {}
            
            inline ~Overrider()
            {
                for(auto it = OverrideDatas.begin(); it != OverrideDatas.end(); it++)
                {
                    for(int i = 0; i < it->second.size(); i++)
                    {
                        //Free argument condition data
                        for(int j = 0; j < it->second[i].ConditionInfo.ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgInfo = it->second[i].ConditionInfo.ArgsCondition[j];
                            
                            if(curArgInfo.ArgSet)
                                curArgInfo.Destructor(curArgInfo.ArgDataPointer);
                        }
                        
                        //Free arguments data
                        for(int j = 0; j < it->second[i].ArgumentsDataInfo.size(); j++)
                        {
                            Internal_DataInfo& curData = it->second[i].ArgumentsDataInfo[j];
                            
                            if(curData.DataSet)
                                curData.Destructor(curData.Data);
                        }
                        
                        //Free return data
                        {
                            Internal_ReturnDataInfo& curData = it->second[i].ReturnDataInfo;
                            
                            if(curData.DataSet)
                                curData.Destructor(curData.Data);
                        }
                    }
                }
            }

            //------------------------------------------------------------------------------
            //Check overrides available
            //------------------------------------------------------------------------------
            #define INTERNAL_CO_LOG_CheckOverride 0
            
            template<typename ReturnType, typename... Args>
            inline bool Internal_CheckOverride( std::string functionName, 
                                                int& outOverrideIndex,
                                                bool& outOverrideReturn,
                                                bool& outOverrideArgs,
                                                bool& outDontReturn,
                                                Args&... args)
            {
                outOverrideIndex = -1;
                
                if(INTERNAL_CO_LOG_CheckOverride)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: "<< functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
                }
                
                if(OverrideDatas.find(functionName) == OverrideDatas.end())
                {
                    if(INTERNAL_CO_LOG_CheckOverride)
                        std::cout << functionName << " not found\n";
                    
                    return false;
                }
            
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                
                outOverrideArgs = false;
                outOverrideReturn = false;
                outDontReturn = false;
                for(int i = 0; i < currentDataList.size(); ++i)
                {
                    if( !currentDataList[i].ArgumentsDataInfo.empty() ||
                        currentDataList[i].ArgumentsDataActionInfo.DataActionSet)
                    {
                        if(!IsCorrectArgumentsDataInfo( currentDataList[i], 
                                                        args...))
                        {
                            if(INTERNAL_CO_LOG_CheckOverride)
                                std::cout << "Arguments not correct at index: " << i << std::endl;
                            
                            continue;
                        }
                        
                        outOverrideArgs = true;
                    }

                    if( currentDataList[i].ReturnDataInfo.DataSet ||
                        currentDataList[i].ReturnDataInfo.ReturnAny ||
                        currentDataList[i].ReturnDataActionInfo.DataActionSet)
                    {
                        if(!IsCorrectReturnDataInfo<ReturnType>(currentDataList[i], args...))
                        {
                            if(INTERNAL_CO_LOG_CheckOverride)
                                std::cout << "Return not correct at index: " << i << std::endl;
                            
                            continue;
                        }
                        
                        outOverrideReturn = true;
                        
                        if(currentDataList[i].ReturnDataInfo.ReturnAny)
                            outDontReturn = true;
                        else
                            outDontReturn = false;
                    }

                    OverrideStatus internalStatus = OverrideStatus::NO_OVERRIDE;
                    if(!IsMeetingRequirementForDataInfo<ReturnType>(currentDataList[i], 
                                                                    internalStatus, 
                                                                    args...))
                    {
                        //If something is wrong internally, notify everything
                        if(internalStatus != OverrideStatus::NO_OVERRIDE)
                        {
                            for(int i = 0; i < currentDataList.size(); i++)
                            {
                                if(currentDataList[i].Status != nullptr)
                                    *currentDataList[i].Status = internalStatus;
                            }
                        }
                        
                        if(INTERNAL_CO_LOG_CheckOverride)
                            std::cout << "Requirement not correct at index: " << i << std::endl;
                        
                        outOverrideArgs = false;
                        outOverrideReturn = false;
                        outDontReturn = false;
                        continue;
                    }

                    outOverrideIndex = i;
                    break;
                }
                
                
                if(INTERNAL_CO_LOG_CheckOverride)
                    std::cout << "outOverrideIndex: " << outOverrideIndex << std::endl;
                
                return outOverrideIndex != -1;
            }

            template<typename... Args>
            inline void Internal_CallReturnOverrideResultExpectedAction(    std::string functionName,
                                                                            int overrideIndex,
                                                                            Args&... args)
            {
                Internal_OverrideData& correctData = OverrideDatas[functionName][overrideIndex];
                
                if(correctData.ResultActionInfo.CorrectActionSet)
                {
                    std::vector<void*> argumentsList;
                    AppendArgsValues(argumentsList, args...);
                    correctData.ResultActionInfo.CorrectAction(argumentsList); 
                }
                
                correctData.ConditionInfo.CalledTimes++;
                
                if(correctData.Status != nullptr)
                    *correctData.Status = OverrideStatus::OVERRIDE_SUCCESS;
            }

            //------------------------------------------------------------------------------
            //Overriding Returns
            //------------------------------------------------------------------------------

            #define INTERNAL_CO_LOG_CheckOverrideAndReturn 0

            template<   typename ReturnType, 
                        typename = typename std::enable_if<std::is_same<ReturnType, void>::value>::type,
                        typename... Args>
            inline ReturnType Internal_OverrideReturn(  int dataIndex,
                                                        std::string functionName, 
                                                        Args&... args)
            {
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                Internal_CallReturnOverrideResultExpectedAction(functionName, dataIndex, args...);
                
                return ReturnType();
            }

            template<   typename ReturnType, 
                        typename = typename std::enable_if<!std::is_same<ReturnType, void>::value>::type,
                        typename = typename std::enable_if<!std::is_reference<ReturnType>::value>::type,
                        typename... Args>
            inline ReturnType Internal_OverrideReturn(  int dataIndex,
                                                        std::string functionName, 
                                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckOverrideAndReturn)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: " << functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                Internal_CallReturnOverrideResultExpectedAction(functionName, dataIndex, args...);
                
                if(correctData.ReturnDataInfo.DataSet)
                    return *reinterpret_cast<ReturnType*>(correctData.ReturnDataInfo.Data);
                else if(correctData.ReturnDataActionInfo.DataActionSet)
                {
                    ReturnType returnRef;
                    correctData.ReturnDataActionInfo.DataAction(argumentsList, &returnRef);
                    return returnRef;
                }
                
                return ReturnType();
            }
            
            template<   typename ReturnType, 
                        typename = typename std::enable_if<!std::is_same<ReturnType, void>::value>::type,
                        typename = typename std::enable_if<std::is_reference<ReturnType>::value>::type,
                        typename = typename std::enable_if<std::is_reference<ReturnType>::value>::type,
                        typename... Args>
            inline ReturnType Internal_OverrideReturn( int dataIndex,
                                                        std::string functionName, 
                                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckOverrideAndReturn)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: " << functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                Internal_CallReturnOverrideResultExpectedAction(functionName, dataIndex, args...);

                if(correctData.ReturnDataInfo.DataSet)
                {
                    return *reinterpret_cast<INTERNAL_CO_UNREF(ReturnType)*>
                    (
                        correctData.ReturnDataInfo.Data
                    );
                }
                else if(correctData.ReturnDataActionInfo.DataActionSet)
                {
                    INTERNAL_CO_UNREF(ReturnType)* returnRef;
                    correctData.ReturnDataActionInfo.DataAction(argumentsList, &returnRef);
                    return *returnRef;
                }
                
                return EarlyReturn<ReturnType>();
            }

            //------------------------------------------------------------------------------
            //Overriding Arguments
            //------------------------------------------------------------------------------
            #define INTERNAL_CO_LOG_CheckOverrideAndSetArgs 0

            template<typename... Args>
            inline void Internal_OverrideArgs(  int dataIndex,
                                                std::string functionName, 
                                                bool performResultAction,
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckOverrideAndSetArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: "<<functionName << std::endl;
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                OverrideStatus overrideStatus = OverrideStatus::OVERRIDE_SUCCESS;
                
                if(correctData.ArgumentsDataActionInfo.DataActionSet)
                    ModifyArgs(argumentsList, correctData.ArgumentsDataActionInfo);
                else
                {
                    ModifyArgs( correctData.ArgumentsDataInfo, 
                                0, 
                                &overrideStatus, 
                                args...);
                }
                
                if(correctData.Status != nullptr)
                    *correctData.Status = overrideStatus;
                
                if( performResultAction && 
                    overrideStatus == OverrideStatus::OVERRIDE_SUCCESS)
                {
                    Internal_CallReturnOverrideResultExpectedAction(functionName, 
                                                                    dataIndex, 
                                                                    args...);
                }
            }
            
            //------------------------------------------------------------------------------
            //Creating override info
            //------------------------------------------------------------------------------
            
            #define INTERNAL_CO_LOG_OverrideCreation 0

            inline OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName)
            {
                if(INTERNAL_CO_LOG_OverrideCreation)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: " << functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
                }

                OverrideDatas[functionName].push_back(Internal_OverrideData());
                return OverrideInfoSetter(functionName, *this);
            }
            
            inline void Internal_RemoveOverrideInfo(std::string functionName)
            {
                if(OverrideDatas.find(functionName) != OverrideDatas.end())
                    OverrideDatas.erase(functionName);
            }
            
            inline void ClearAllOverrideInfo()
            {
                OverrideDatas.clear();
            }
    };
}

#endif

//=================================================================
//./Include_MultiHeaders/OverrideInfoSetterImplementation.hpp
//=================================================================
#ifndef CO_OVERRIDE_INFO_SETTER_IMPLEMENTATION_HPP
#define CO_OVERRIDE_INFO_SETTER_IMPLEMENTATION_HPP





namespace CppOverride 
{
    //==============================================================================
    //Implementation of OverrideInfoSetter classes for method chaining
    //==============================================================================

    inline OverrideInfoSetter& OverrideInfoSetter::Times(int times)
    {
        return CppOverrideObj.Times(*this, times);
    }

    template<typename... Args>
    inline OverrideInfoSetter& OverrideInfoSetter::WhenCalledWith(Args... args)
    {
        return CppOverrideObj.WhenCalledWith(*this, args...);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::If(std::function<bool(const std::vector<void*>& args)> condition)
    {
        return CppOverrideObj.If(*this, condition);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::Otherwise_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.Otherwise_Do(*this, action);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::WhenCalledExpectedly_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.WhenCalledExpectedly_Do(*this, action);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::AssignOverrideResult(OverrideResult& result)
    {
        return CppOverrideObj.AssignOverrideResult(*this, result);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter& 
    OverrideInfoSetter::ReturnsByAction(std::function<void( const std::vector<void*>& args, 
                                                            void* out)> returnAction)
    {
        return CppOverrideObj.ReturnsByAction<ReturnType>(*this, returnAction);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter&
    OverrideInfoSetter::Returns(typename TypeSpecifier<ReturnType>::Type returnData)
    {
        static_assert(std::is_same<ReturnType, decltype(returnData)>::value, "");
        return CppOverrideObj.Returns<ReturnType>(*this, returnData);
    }
    
    template<>
    inline OverrideInfoSetter&
    OverrideInfoSetter::Returns<void>()
    {
        return CppOverrideObj.ReturnsVoid(*this);
    }
    
    inline OverrideInfoSetter& OverrideInfoSetter::ReturnsVoid()
    {
        return CppOverrideObj.ReturnsVoid(*this);
    }

    #ifndef INTERNAL_CO_SET_ARGS_IMPL
        #define INTERNAL_CO_SET_ARGS_IMPL(...) \
            template<MPT_PREFIX_SUFFIX_ARGS(typename Arg, Type, __VA_ARGS__)> \
            OverrideInfoSetter& OverrideInfoSetter::SetArgs \
            ( \
                MPT_COMPOSE \
                ( \
                    MPT_APPEND_LISTS_ITEMS, \
                    ( \
                        MPT_COMPOSE2 \
                        ( \
                            MPT_PREFIX_SUFFIX_ARGS, \
                            ( \
                                typename TypeUnwrapper<Arg, \
                                Type>::Type, \
                                __VA_ARGS__ \
                            ) \
                        ), \
                        MPT_COMPOSE2 \
                        ( \
                            MPT_COMPOSE3, \
                            ( \
                                MPT_CONCAT, \
                                ( \
                                    MPT_COUNT_TO_, \
                                    MPT_ARGS_COUNT(__VA_ARGS__) \
                                ) \
                            )(_, /* no suffix */) \
                        ) \
                    ) \
                ) \
            ) \
            { \
                return CppOverrideObj.SetArgs<MPT_PREFIX_SUFFIX_ARGS(Arg, Type, __VA_ARGS__)>(*this, MPT_PREFIX_SUFFIX_ARGS(_, \
                                                                            /* no suffix */, \
                                                                            __VA_ARGS__)); \
            }

        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_1(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_2(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_3(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_4(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_5(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_6(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_7(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_8(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_9(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_10(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_11(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_12(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_13(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_14(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_15(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_16(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_17(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_18(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_19(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_20(/* no prefix */, /* no suffix */))
    #endif
    
    #undef INTERNAL_CO_SET_ARGS_IMPL
    
    template<typename... Args>
    inline OverrideInfoSetter&
    OverrideInfoSetter::SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction)
    {
        return CppOverrideObj.SetArgsByAction<Args...>(*this, setArgsAction);
    }
}

#endif

//=================================================================
//./Include_MultiHeaders/Macros.hpp
//=================================================================
#ifndef CO_MACROS_HPP
#define CO_MACROS_HPP



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
        bool found = overrideObjName.Internal_CheckOverride<returnType>(__func__, \
                                                                        foundIndex, \
                                                                        overrideReturn, \
                                                                        overrideArgs, \
                                                                        dontReturn \
                                                                        INTERNAL_CO_ARGS(args)); \
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
                        overrideObjName.Internal_CallReturnOverrideResultExpectedAction(__func__, \
                                                                                        foundIndex \
                                                                                        INTERNAL_CO_ARGS(args)); \
                    } \
                    else \
                    { \
                        return overrideObjName.Internal_OverrideReturn<returnType>( foundIndex, \
                                                                                    __func__ \
                                                                                    INTERNAL_CO_ARGS(args)); \
                    } \
                } \
                if(!overrideArgs && !overrideReturn) \
                { \
                    overrideObjName.Internal_CallReturnOverrideResultExpectedAction(__func__, \
                                                                                    foundIndex \
                                                                                    INTERNAL_CO_ARGS(args)); \
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
        inline returnType functionName (INTERNAL_POPULATE_ARGS_FIELD(argsTypes)) functionAppend \
        { \
            CO_OVERRIDE_IMPL(CurrentOverrideInstance, returnType, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return returnType(); \
        }

    #define INTERNAL_CO_MOCK_METHOD_5(functionPrepend, returnType, functionName, argsTypes, functionAppend) \
        functionPrepend inline returnType functionName (INTERNAL_POPULATE_ARGS_FIELD(argsTypes)) functionAppend \
        { \
            CO_OVERRIDE_IMPL(CurrentOverrideInstance, returnType, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return returnType(); \
        }
    
    #define INTERNAL_CO_MOCK_METHOD_6(functionPrepend, returnType, functionName, argsTypes, argsDefaults, functionAppend) \
        functionPrepend inline returnType functionName \
                                        ( \
                                            MPT_APPEND_LISTS_ITEMS \
                                            ( \
                                                INTERNAL_POPULATE_ARGS_FIELD(argsTypes), \
                                                MPT_REMOVE_PARENTHESIS(argsDefaults) \
                                            ) \
                                        ) functionAppend \
        { \
            CO_OVERRIDE_IMPL(CurrentOverrideInstance, returnType, (INTERNAL_CO_POPULATE_ARGS_NAMES(argsTypes))); \
            return returnType(); \
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



namespace CppOverride
{
    class MockClass
    {
        protected:
            CO_DECLARE_MEMBER_INSTANCE(CurrentOverrideInstance);
        
        public:
            CO_DECLARE_OVERRIDE_METHODS(CurrentOverrideInstance);
    };
}

#endif
