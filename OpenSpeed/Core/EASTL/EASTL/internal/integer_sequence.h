// BSD 3-Clause License, https://github.com/electronicarts/EASTL

#ifndef EASTL_INTEGER_SEQUENCE_H
#define EASTL_INTEGER_SEQUENCE_H

#include <OpenSpeed/Core/EASTL/EABase/config/eacompiler.h>
#include <OpenSpeed/Core/EASTL/EASTL/internal/config.h>
#include <OpenSpeed/Core/EASTL/EASTL/type_traits.h>

namespace eastl {

#if EASTL_VARIADIC_TEMPLATES_ENABLED && !defined(EA_COMPILER_NO_TEMPLATE_ALIASES)

  // integer_sequence
  template <typename T, T... Ints>
  class integer_sequence {
   public:
    typedef T value_type;
    static_assert(is_integral<T>::value, "eastl::integer_sequence can only be instantiated with an integral type");
    static EA_CONSTEXPR size_t size() EA_NOEXCEPT { return sizeof...(Ints); }
  };

  template <size_t N, typename IndexSeq>
  struct make_index_sequence_impl;

  template <size_t N, size_t... Is>
  struct make_index_sequence_impl<N, integer_sequence<size_t, Is...>> {
    typedef typename make_index_sequence_impl<N - 1, integer_sequence<size_t, N - 1, Is...>>::type type;
  };

  template <size_t... Is>
  struct make_index_sequence_impl<0, integer_sequence<size_t, Is...>> {
    typedef integer_sequence<size_t, Is...> type;
  };

  template <size_t... Is>
  using index_sequence = integer_sequence<size_t, Is...>;

  template <size_t N>
  using make_index_sequence = typename make_index_sequence_impl<N, integer_sequence<size_t>>::type;

  template <typename Target, typename Seq>
  struct integer_sequence_convert_impl;

  template <typename Target, size_t... Is>
  struct integer_sequence_convert_impl<Target, integer_sequence<size_t, Is...>> {
    typedef integer_sequence<Target, Is...> type;
  };

  template <typename T, size_t N>
  struct make_integer_sequence_impl {
    typedef typename integer_sequence_convert_impl<T, make_index_sequence<N>>::type type;
  };

  template <typename T, size_t N>
  using make_integer_sequence = typename make_integer_sequence_impl<T, N>::type;

#endif  // EASTL_VARIADIC_TEMPLATES_ENABLED

}  // namespace eastl

#endif  // EASTL_INTEGER_SEQUENCE_H
