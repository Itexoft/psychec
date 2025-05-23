// Copyright (c) 2016/17/18/19/20/21/22 Leandro T. C. Melo <ltcmelo@gmail.com>
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

#include "Unparser.h"

#include "syntax/SyntaxTree.h"

#include "syntax/Lexeme_ALL.h"
#include "syntax/SyntaxNodes.h"

#include <iostream>

using namespace psy;
using namespace C;

void Unparser::unparse(const SyntaxNode* node, std::ostream& os)
{
    os_ = &os;
    visit(node);
}

void Unparser::terminal(const SyntaxToken& tk, const SyntaxNode*)
{
    if (tk.kind() == SyntaxKind::EndOfFile)
        return;

    *os_ << tk.valueText_c_str();

    if (tk.kind() == SyntaxKind::CloseBraceToken
            || tk.kind() == SyntaxKind::OpenBraceToken
            || tk.kind() == SyntaxKind::SemicolonToken)
        *os_ << "\n";
    else
        *os_ << " ";
}
