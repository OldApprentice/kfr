/** @addtogroup math
 *  @{
 */
/*
  Copyright (C) 2016 D Levin (https://www.kfrlib.com)
  This file is part of KFR

  KFR is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  KFR is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with KFR.

  If GPL is not suitable for your project, you must purchase a commercial license to use KFR.
  Buying a commercial license is mandatory as soon as you develop commercial activities without
  disclosing the source code of your own applications.
  See https://www.kfrlib.com for details.
 */
#pragma once

#include "../abs.hpp"
#include "../constants.hpp"
#include "../function.hpp"
#include "../log_exp.hpp"
#include "../min_max.hpp"
#include "../operators.hpp"
#include "../select.hpp"

namespace kfr
{

namespace intrinsics
{

template <typename T, size_t N, typename Tout = flt_type<T>>
KFR_SINTRIN vec<Tout, N> sinh(const vec<T, N>& x)
{
    const vec<Tout, N> xx = static_cast<vec<Tout, N>>(x);
    return (exp(xx) - exp(-xx)) * Tout(0.5);
}

template <typename T, size_t N, typename Tout = flt_type<T>>
KFR_SINTRIN vec<Tout, N> cosh(const vec<T, N>& x)
{
    const vec<Tout, N> xx = static_cast<vec<Tout, N>>(x);
    return (exp(xx) + exp(-xx)) * Tout(0.5);
}

template <typename T, size_t N, typename Tout = flt_type<T>>
KFR_SINTRIN vec<Tout, N> tanh(const vec<T, N>& x)
{
    const vec<Tout, N> a = exp(2 * x);
    return (a - 1) / (a + 1);
}

template <typename T, size_t N, typename Tout = flt_type<T>>
KFR_SINTRIN vec<Tout, N> coth(const vec<T, N>& x)
{
    const vec<Tout, N> a = exp(2 * x);
    return (a + 1) / (a - 1);
}

template <typename T, size_t N, typename Tout = flt_type<T>>
KFR_SINTRIN vec<Tout, N> sinhcosh(const vec<T, N>& x)
{
    const vec<Tout, N> a = exp(x);
    const vec<Tout, N> b = exp(-x);
    return subadd(a, b) * Tout(0.5);
}

template <typename T, size_t N, typename Tout = flt_type<T>>
KFR_SINTRIN vec<Tout, N> coshsinh(const vec<T, N>& x)
{
    const vec<Tout, N> a = exp(x);
    const vec<Tout, N> b = exp(-x);
    return addsub(a, b) * Tout(0.5);
}

KFR_I_FLT_CONVERTER(sinh)
KFR_I_FLT_CONVERTER(cosh)
KFR_I_FLT_CONVERTER(tanh)
KFR_I_FLT_CONVERTER(coth)
KFR_I_FLT_CONVERTER(sinhcosh)
KFR_I_FLT_CONVERTER(coshsinh)
} // namespace intrinsics
KFR_I_FN(sinh)
KFR_I_FN(cosh)
KFR_I_FN(tanh)
KFR_I_FN(coth)
KFR_I_FN(sinhcosh)
KFR_I_FN(coshsinh)

} // namespace kfr
