/*=============================================================================
    Spirit v1.6.1
    Copyright (c) 2001-2003 Daniel Nuffer
    http://spirit.sourceforge.net/

    Permission to copy, use, modify, sell and distribute this software is
    granted provided this copyright notice appears in all copies. This
    software is provided "as is" without express or implied warranty, and
    with no claim as to its suitability for any purpose.
=============================================================================*/
#define BOOST_SPIRIT_DUMP_PARSETREE_AS_XML

#include "boost/spirit/core.hpp"
#include "boost/spirit/tree/ast.hpp"
#include "boost/spirit/tree/tree_to_xml.hpp"
#include "tree_calc_grammar.hpp"

#include <iostream>
#include <stack>
#include <functional>
#include <string>
#include <cassert>

#if defined(BOOST_SPIRIT_DUMP_PARSETREE_AS_XML)
#include <map>
#endif

// This example shows how to use an AST.
////////////////////////////////////////////////////////////////////////////
using namespace std;
using namespace boost::spirit;

typedef char const*         iterator_t;
typedef tree_match<iterator_t> parse_tree_match_t;
typedef parse_tree_match_t::tree_iterator iter_t;

////////////////////////////////////////////////////////////////////////////
long evaluate(parse_tree_match_t hit);
long eval_expression(iter_t const& i);

long evaluate(tree_parse_info<> info)
{
    return eval_expression(info.trees.begin());
}

long eval_expression(iter_t const& i)
{
    cout << "In eval_expression. i->value = " <<
        string(i->value.begin(), i->value.end()) <<
        " i->children.size() = " << i->children.size() << endl;

    if (i->value.id() == calculator::integerID)
    {
        assert(i->children.size() == 0);

        // extract integer (not always delimited by '\0')
        string integer(i->value.begin(), i->value.end());

        return strtol(integer.c_str(), 0, 10);
    }
    else if (i->value.id() == calculator::factorID)
    {
        // factor can only be unary minus
        assert(*i->value.begin() == '-');
        return - eval_expression(i->children.begin());
    }
    else if (i->value.id() == calculator::termID)
    {
        if (*i->value.begin() == '*')
        {
            assert(i->children.size() == 2);
            return eval_expression(i->children.begin()) *
                eval_expression(i->children.begin()+1);
        }
        else if (*i->value.begin() == '/')
        {
            assert(i->children.size() == 2);
            return eval_expression(i->children.begin()) /
                eval_expression(i->children.begin()+1);
        }
        else
            assert(0);
    }
    else if (i->value.id() == calculator::expressionID)
    {
        if (*i->value.begin() == '+')
        {
            assert(i->children.size() == 2);
            return eval_expression(i->children.begin()) +
                eval_expression(i->children.begin()+1);
        }
        else if (*i->value.begin() == '-')
        {
            assert(i->children.size() == 2);
            return eval_expression(i->children.begin()) -
                eval_expression(i->children.begin()+1);
        }
        else
            assert(0);
    }
    else
    {
        assert(0); // error
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////
int
main()
{
    // look in tree_calc_grammar for the definition of calculator
    calculator calc;

    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "\t\tThe simplest working calculator...\n\n";
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "Type an expression...or [q or Q] to quit\n\n";

    string str;
    while (getline(cin, str))
    {
        if (str[0] == 'q' || str[0] == 'Q')
            break;

        tree_parse_info<> info = ast_parse(str.c_str(), calc);

        if (info.full)
        {
#if defined(BOOST_SPIRIT_DUMP_PARSETREE_AS_XML)
            // dump parse tree as XML
            std::map<parser_id, std::string> rule_names;
            rule_names[calculator::integerID] = "integer";
            rule_names[calculator::factorID] = "factor";
            rule_names[calculator::termID] = "term";
            rule_names[calculator::expressionID] = "expression";
            tree_to_xml(cout, info.trees, str.c_str(), rule_names);
#endif

            // print the result
            cout << "parsing succeeded\n";
            cout << "result = " << evaluate(info) << "\n\n";
        }
        else
        {
            cout << "parsing failed\n";
        }
    }

    cout << "Bye... :-) \n\n";
    return 0;
}


