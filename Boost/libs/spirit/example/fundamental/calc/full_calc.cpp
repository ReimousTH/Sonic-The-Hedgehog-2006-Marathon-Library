/*=============================================================================
    Spirit v1.6.1
    Copyright (c) 2001-2003 Dan Nuffer
    Copyright (c) 2001-2003 Joel de Guzman
    http://spirit.sourceforge.net/

    Permission to copy, use, modify, sell and distribute this software is
    granted provided this copyright notice appears in all copies. This
    software is provided "as is" without express or implied warranty, and
    with no claim as to its suitability for any purpose.
=============================================================================*/
////////////////////////////////////////////////////////////////////////////
//
//  Full calculator example using STL functors
//
//  Ported to Spirit v1.5 from v1.2/1.3 example by Dan Nuffer
//  [ JDG 9/18/2002 ]
//
////////////////////////////////////////////////////////////////////////////
#include <boost/spirit/core.hpp>
#include <iostream>
#include <stack>
#include <functional>
#include <string>

////////////////////////////////////////////////////////////////////////////
using namespace std;
using namespace boost::spirit;

////////////////////////////////////////////////////////////////////////////
//
//  Semantic actions
//
////////////////////////////////////////////////////////////////////////////
struct push_int
{
    push_int(stack<long>& eval_)
    : eval(eval_) {}

    void operator()(char const* str, char const* /*end*/) const
    {
        long n = strtol(str, 0, 10);
        eval.push(n);
        cout << "push\t" << long(n) << endl;
    }

    stack<long>& eval;
};

template <typename op>
struct do_op
{
    do_op(op const& the_op, stack<long>& eval_)
    : m_op(the_op), eval(eval_) {}

    void operator()(char const*, char const*) const
    {
        long rhs = eval.top();
        eval.pop();
        long lhs = eval.top();
        eval.pop();

        cout << "popped " << lhs << " and " << rhs << " from the stack. ";
        cout << "pushing " << m_op(lhs, rhs) << " onto the stack.\n";
        eval.push(m_op(lhs, rhs));
    }

    op m_op;
    stack<long>& eval;
};

template <class op>
do_op<op>
make_op(op const& the_op, stack<long>& eval)
{
    return do_op<op>(the_op, eval);
}

struct do_negate
{
    do_negate(stack<long>& eval_)
    : eval(eval_) {}

    void operator()(char const*, char const*) const
    {
        long lhs = eval.top();
        eval.pop();

        cout << "popped " << lhs << " from the stack. ";
        cout << "pushing " << -lhs << " onto the stack.\n";
        eval.push(-lhs);
    }

    stack<long>& eval;
};

////////////////////////////////////////////////////////////////////////////
//
//  Our calculator grammar
//
////////////////////////////////////////////////////////////////////////////
struct calculator : public grammar<calculator>
{
    calculator(stack<long>& eval_)
    : eval(eval_) {}

    template <typename ScannerT>
    struct definition
    {
        definition(calculator const& self)
        {
            integer =
                lexeme_d[ (+digit_p)[push_int(self.eval)] ]
                ;

            factor =
                    integer
                |   '(' >> expression >> ')'
                |   ('-' >> factor)[do_negate(self.eval)]
                |   ('+' >> factor)
                ;

            term =
                factor
                >> *(   ('*' >> factor)[make_op(multiplies<long>(), self.eval)]
                    |   ('/' >> factor)[make_op(divides<long>(), self.eval)]
                    )
                    ;

            expression =
                term
                >> *(  ('+' >> term)[make_op(plus<long>(), self.eval)]
                    |   ('-' >> term)[make_op(minus<long>(), self.eval)]
                    )
                    ;
        }

        rule<ScannerT> expression, term, factor, integer;
        rule<ScannerT> const&
        start() const { return expression; }
    };

    stack<long>& eval;
};

////////////////////////////////////////////////////////////////////////////
//
//  Main program
//
////////////////////////////////////////////////////////////////////////////
int
main()
{
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "\t\tThe simplest working calculator...\n\n";
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "Type an expression...or [q or Q] to quit\n\n";

    stack<long> eval;
    calculator  calc(eval); //  Our parser

    string str;
    while (getline(cin, str))
    {
        if (str[0] == 'q' || str[0] == 'Q')
            break;

        parse_info<> info = parse(str.c_str(), calc, space_p);

        if (info.full)
        {
            cout << "-------------------------\n";
            cout << "Parsing succeeded\n";
            cout << "-------------------------\n";
        }
        else
        {
            cout << "-------------------------\n";
            cout << "Parsing failed\n";
            cout << "stopped at: \": " << info.stop << "\"\n";
            cout << "-------------------------\n";
        }
    }

    cout << "Bye... :-) \n\n";
    return 0;
}


