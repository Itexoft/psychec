// Copyright (c) 2021/22/23/24 Leandro T. C. Melo <ltcmelo@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef PSYCHE_C_TYPE_VOID_H__
#define PSYCHE_C_TYPE_VOID_H__

#include "API.h"
#include "Fwds.h"

#include "Type.h"

namespace psy {
namespace C {

/**
 * \brief The VoidType class.
 *
 * \remark 6.2.5-14
 */
class PSY_C_API VoidType final : public Type
{
public:
    //!@{
    /**
     * Cast \c this Type as an VoidType.
     */
    virtual VoidType* asVoidType() override { return this; }
    virtual const VoidType* asVoidType() const override { return this; }
    //!@}

PSY_INTERNAL:
    PSY_GRANT_INTERNAL_ACCESS(Compilation);
    PSY_GRANT_INTERNAL_ACCESS(DeclarationBinder);

    VoidType();
};

PSY_C_API std::ostream& operator<<(std::ostream& os, const VoidType* voidTy);

} // C
} // psy

#endif
