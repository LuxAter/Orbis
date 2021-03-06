
// This is a generated file. Do not edit!

#ifndef ORBIS_COMPILER_DETECTION_H
#define ORBIS_COMPILER_DETECTION_H

#ifdef __cplusplus
# define ORBIS_COMPILER_IS_Comeau 0
# define ORBIS_COMPILER_IS_Intel 0
# define ORBIS_COMPILER_IS_PathScale 0
# define ORBIS_COMPILER_IS_Embarcadero 0
# define ORBIS_COMPILER_IS_Borland 0
# define ORBIS_COMPILER_IS_Watcom 0
# define ORBIS_COMPILER_IS_OpenWatcom 0
# define ORBIS_COMPILER_IS_SunPro 0
# define ORBIS_COMPILER_IS_HP 0
# define ORBIS_COMPILER_IS_Compaq 0
# define ORBIS_COMPILER_IS_zOS 0
# define ORBIS_COMPILER_IS_XLClang 0
# define ORBIS_COMPILER_IS_XL 0
# define ORBIS_COMPILER_IS_VisualAge 0
# define ORBIS_COMPILER_IS_PGI 0
# define ORBIS_COMPILER_IS_Cray 0
# define ORBIS_COMPILER_IS_TI 0
# define ORBIS_COMPILER_IS_Fujitsu 0
# define ORBIS_COMPILER_IS_GHS 0
# define ORBIS_COMPILER_IS_SCO 0
# define ORBIS_COMPILER_IS_ARMCC 0
# define ORBIS_COMPILER_IS_AppleClang 0
# define ORBIS_COMPILER_IS_ARMClang 0
# define ORBIS_COMPILER_IS_Clang 0
# define ORBIS_COMPILER_IS_GNU 0
# define ORBIS_COMPILER_IS_MSVC 0
# define ORBIS_COMPILER_IS_ADSP 0
# define ORBIS_COMPILER_IS_IAR 0
# define ORBIS_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef ORBIS_COMPILER_IS_Comeau
# define ORBIS_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef ORBIS_COMPILER_IS_Intel
# define ORBIS_COMPILER_IS_Intel 1

#elif defined(__PATHCC__)
# undef ORBIS_COMPILER_IS_PathScale
# define ORBIS_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef ORBIS_COMPILER_IS_Embarcadero
# define ORBIS_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef ORBIS_COMPILER_IS_Borland
# define ORBIS_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef ORBIS_COMPILER_IS_Watcom
# define ORBIS_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef ORBIS_COMPILER_IS_OpenWatcom
# define ORBIS_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef ORBIS_COMPILER_IS_SunPro
# define ORBIS_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef ORBIS_COMPILER_IS_HP
# define ORBIS_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef ORBIS_COMPILER_IS_Compaq
# define ORBIS_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef ORBIS_COMPILER_IS_zOS
# define ORBIS_COMPILER_IS_zOS 1

#elif defined(__ibmxl__) && defined(__clang__)
# undef ORBIS_COMPILER_IS_XLClang
# define ORBIS_COMPILER_IS_XLClang 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef ORBIS_COMPILER_IS_XL
# define ORBIS_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef ORBIS_COMPILER_IS_VisualAge
# define ORBIS_COMPILER_IS_VisualAge 1

#elif defined(__PGI)
# undef ORBIS_COMPILER_IS_PGI
# define ORBIS_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef ORBIS_COMPILER_IS_Cray
# define ORBIS_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef ORBIS_COMPILER_IS_TI
# define ORBIS_COMPILER_IS_TI 1

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# undef ORBIS_COMPILER_IS_Fujitsu
# define ORBIS_COMPILER_IS_Fujitsu 1

#elif defined(__ghs__)
# undef ORBIS_COMPILER_IS_GHS
# define ORBIS_COMPILER_IS_GHS 1

#elif defined(__SCO_VERSION__)
# undef ORBIS_COMPILER_IS_SCO
# define ORBIS_COMPILER_IS_SCO 1

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# undef ORBIS_COMPILER_IS_ARMCC
# define ORBIS_COMPILER_IS_ARMCC 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef ORBIS_COMPILER_IS_AppleClang
# define ORBIS_COMPILER_IS_AppleClang 1

#elif defined(__clang__) && defined(__ARMCOMPILER_VERSION)
# undef ORBIS_COMPILER_IS_ARMClang
# define ORBIS_COMPILER_IS_ARMClang 1

#elif defined(__clang__)
# undef ORBIS_COMPILER_IS_Clang
# define ORBIS_COMPILER_IS_Clang 1

#elif defined(__GNUC__) || defined(__GNUG__)
# undef ORBIS_COMPILER_IS_GNU
# define ORBIS_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef ORBIS_COMPILER_IS_MSVC
# define ORBIS_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef ORBIS_COMPILER_IS_ADSP
# define ORBIS_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# undef ORBIS_COMPILER_IS_IAR
# define ORBIS_COMPILER_IS_IAR 1


#endif

#  if ORBIS_COMPILER_IS_MSVC

#    if !(_MSC_VER >= 1600)
#      error Unsupported compiler version
#    endif

  /* _MSC_VER = VVRR */
# define ORBIS_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
# define ORBIS_COMPILER_VERSION_MINOR (_MSC_VER % 100)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 1400
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define ORBIS_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 100000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define ORBIS_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define ORBIS_COMPILER_VERSION_TWEAK (_MSC_BUILD)
# endif

#    if _MSC_VER >= 1900
#      define ORBIS_COMPILER_CXX_CONSTEXPR 1
#    else
#      define ORBIS_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if _MSC_VER >= 1900
#      define ORBIS_COMPILER_CXX_NOEXCEPT 1
#    else
#      define ORBIS_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if _MSC_VER >= 1600
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if _MSC_VER >= 1900
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  elif ORBIS_COMPILER_IS_GNU

#    if !((__GNUC__ * 100 + __GNUC_MINOR__) >= 404)
#      error Unsupported compiler version
#    endif

# if defined(__GNUC__)
#  define ORBIS_COMPILER_VERSION_MAJOR (__GNUC__)
# else
#  define ORBIS_COMPILER_VERSION_MAJOR (__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define ORBIS_COMPILER_VERSION_MINOR (__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define ORBIS_COMPILER_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define ORBIS_COMPILER_CXX_CONSTEXPR 1
#    else
#      define ORBIS_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define ORBIS_COMPILER_CXX_NOEXCEPT 1
#    else
#      define ORBIS_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  elif ORBIS_COMPILER_IS_Clang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 301)
#      error Unsupported compiler version
#    endif

# define ORBIS_COMPILER_VERSION_MAJOR (__clang_major__)
# define ORBIS_COMPILER_VERSION_MINOR (__clang_minor__)
# define ORBIS_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define ORBIS_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define ORBIS_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_constexpr)
#      define ORBIS_COMPILER_CXX_CONSTEXPR 1
#    else
#      define ORBIS_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_noexcept)
#      define ORBIS_COMPILER_CXX_NOEXCEPT 1
#    else
#      define ORBIS_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_static_assert)
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus > 201103L
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  elif ORBIS_COMPILER_IS_Intel

#    if !(__INTEL_COMPILER >= 1210)
#      error Unsupported compiler version
#    endif

  /* __INTEL_COMPILER = VRP */
# define ORBIS_COMPILER_VERSION_MAJOR (__INTEL_COMPILER/100)
# define ORBIS_COMPILER_VERSION_MINOR (__INTEL_COMPILER/10 % 10)
# if defined(__INTEL_COMPILER_UPDATE)
#  define ORBIS_COMPILER_VERSION_PATCH (__INTEL_COMPILER_UPDATE)
# else
#  define ORBIS_COMPILER_VERSION_PATCH (__INTEL_COMPILER   % 10)
# endif
# if defined(__INTEL_COMPILER_BUILD_DATE)
  /* __INTEL_COMPILER_BUILD_DATE = YYYYMMDD */
#  define ORBIS_COMPILER_VERSION_TWEAK (__INTEL_COMPILER_BUILD_DATE)
# endif
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define ORBIS_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define ORBIS_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif
# if defined(__GNUC__)
#  define ORBIS_SIMULATE_VERSION_MAJOR (__GNUC__)
# elif defined(__GNUG__)
#  define ORBIS_SIMULATE_VERSION_MAJOR (__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define ORBIS_SIMULATE_VERSION_MINOR (__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define ORBIS_SIMULATE_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if __cpp_constexpr >= 200704 || __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define ORBIS_COMPILER_CXX_CONSTEXPR 1
#    else
#      define ORBIS_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define ORBIS_COMPILER_CXX_NOEXCEPT 1
#    else
#      define ORBIS_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__cpp_static_assert >= 200410 || __INTEL_COMPILER >= 1210) && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  elif ORBIS_COMPILER_IS_AppleClang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 400)
#      error Unsupported compiler version
#    endif

# define ORBIS_COMPILER_VERSION_MAJOR (__clang_major__)
# define ORBIS_COMPILER_VERSION_MINOR (__clang_minor__)
# define ORBIS_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define ORBIS_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define ORBIS_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif
# define ORBIS_COMPILER_VERSION_TWEAK (__apple_build_version__)

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_constexpr)
#      define ORBIS_COMPILER_CXX_CONSTEXPR 1
#    else
#      define ORBIS_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_noexcept)
#      define ORBIS_COMPILER_CXX_NOEXCEPT 1
#    else
#      define ORBIS_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_static_assert)
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define ORBIS_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 501 && __cplusplus > 201103L
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#  else
#    error Unsupported compiler
#  endif

#  if defined(ORBIS_COMPILER_CXX_CONSTEXPR) && ORBIS_COMPILER_CXX_CONSTEXPR
#    define ORBIS_CONSTEXPR constexpr
#  else
#    define ORBIS_CONSTEXPR 
#  endif


#  if defined(ORBIS_COMPILER_CXX_NOEXCEPT) && ORBIS_COMPILER_CXX_NOEXCEPT
#    define ORBIS_NOEXCEPT noexcept
#    define ORBIS_NOEXCEPT_EXPR(X) noexcept(X)
#  else
#    define ORBIS_NOEXCEPT
#    define ORBIS_NOEXCEPT_EXPR(X)
#  endif

#  if defined(ORBIS_COMPILER_CXX_STATIC_ASSERT) && ORBIS_COMPILER_CXX_STATIC_ASSERT
#    define ORBIS_STATIC_ASSERT(X) static_assert(X, #X)
#    define ORBIS_STATIC_ASSERT_MSG(X, MSG) static_assert(X, MSG)
#  else
#    define ORBIS_STATIC_ASSERT_JOIN(X, Y) ORBIS_STATIC_ASSERT_JOIN_IMPL(X, Y)
#    define ORBIS_STATIC_ASSERT_JOIN_IMPL(X, Y) X##Y
template<bool> struct ORBISStaticAssert;
template<> struct ORBISStaticAssert<true>{};
#    define ORBIS_STATIC_ASSERT(X) enum { ORBIS_STATIC_ASSERT_JOIN(ORBISStaticAssertEnum, __LINE__) = sizeof(ORBISStaticAssert<X>) }
#    define ORBIS_STATIC_ASSERT_MSG(X, MSG) enum { ORBIS_STATIC_ASSERT_JOIN(ORBISStaticAssertEnum, __LINE__) = sizeof(ORBISStaticAssert<X>) }
#  endif


#  ifndef ORBIS_DEPRECATED
#    if defined(ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED) && ORBIS_COMPILER_CXX_ATTRIBUTE_DEPRECATED
#      define ORBIS_DEPRECATED [[deprecated]]
#      define ORBIS_DEPRECATED_MSG(MSG) [[deprecated(MSG)]]
#    elif ORBIS_COMPILER_IS_GNU || ORBIS_COMPILER_IS_Clang
#      define ORBIS_DEPRECATED __attribute__((__deprecated__))
#      define ORBIS_DEPRECATED_MSG(MSG) __attribute__((__deprecated__(MSG)))
#    elif ORBIS_COMPILER_IS_MSVC
#      define ORBIS_DEPRECATED __declspec(deprecated)
#      define ORBIS_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#    else
#      define ORBIS_DEPRECATED
#      define ORBIS_DEPRECATED_MSG(MSG)
#    endif
#  endif

#endif

#endif
