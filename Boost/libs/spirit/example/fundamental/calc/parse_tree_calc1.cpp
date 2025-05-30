/*=============================================================================
    Spirit v1.6.1
    Copyright (c) 2001-2003 Daniel Nuffer
    http://spirit.sourceforge.net/

    Permission to copy, use, modify, sell and distribute this software is
    granted provided this copyright notice appears in all copies. This
    software is provided "as is" without express or implied warranty, and
    with no claim as to its suitability for any purpose.
=============================================================================*/
#include "boost/spirit/core.hpp"
#include "boost/spirit/tree/parse_tree.hpp"

#include <iostream>
#include <stack>
#include <functional>
#include <string>

// This example shows how to use a parse tree
////////////////////////////////////////////////////////////////////////////
using namespace std;
using namespace boost::spirit;

// Here's some typedefs to simplify things
typedef char const*         iterator_t;
typedef tree_match<iterator_t> parse_tree_match_t;
typedef parse_tree_match_t::const_tree_iterator iter_t;

typedef pt_match_policy<iterator_t> match_policy_t;
typedef scanner_policies<iteration_policy, match_policy_t, action_policy> scanner_policy_t;
typedef scanner<iterator_t, scanner_policy_t> scanner_t;
typedef rule<scanner_t> rule_t;

//  grammar rules
rule_t expression, term, factor, integer;

////////////////////////////////////////////////////////////////////////////
// Here's the function prototypes that we'll use.  One function for each
// grammar rule.
long evaluate(const tree_parse_info<>& info);
long eval_expression(iter_t const& i);
long eval_term(iter_t const& i);
long eval_factor(iter_t const& i);
long eval_integer(iter_t const& i);

long evaluate(const tree_parse_info<>& info)
{
    return eval_expression(info.trees.begin());
}

// i should be pointing to a node created by the expression rule
long eval_expression(iter_t const& i)
{
    parser_id id = i->value.id();
    assert(id == parser_id(&expression)); // check the id

    // first child points to a term, so call eval_term on it
    iter_t chi = i->children.begin();
    long lhs = eval_term(chi);
    for (++chi; chi != i->children.end(); ++chi)
    {
        // next node points to the operator.  The text of the operator is
        // stored in value (a vector<char>)
        char op = *(chi->value.begin());
        ++chi;
        long rhs = eval_term(chi);
        if (op == '+')
            lhs += rhs;
        else if (op == '-')
            lhs -= rhs;
        else
            assert(0);
    }
    return lhs;
}

long eval_term(iter_t const& i)
{
    parser_id id = i->value.id();
    assert(id == parser_id(&term));

    iter_t chi = i->children.begin();
    long lhs = eval_factor(chi);
    for (++chi; chi != i->children.end(); ++chi)
    {
        char op = *(chi->value.begin());
        ++chi;
        long rhs = eval_factor(chi);
        if (op == '*')
            lhs *= rhs;
        else if (op == '/')
            lhs /= rhs;
        else
            assert(0);
    }
    return lhs;
}

long eval_factor(iter_t const& i)
{
    parser_id id = i->value.id();
    assert(id == parser_id(&factor));

    iter_t chi = i->children.begin();
    id = chi->value.id();
    if (id == parser_id(&integer))
        return eval_integer(chi->children.begin());
    else if (*(chi->value.begin()) == '(')
    {
        ++chi;
        return eval_expression(chi);
    }
    else if (*(chi->value.begin()) == '-')
    {
        ++chi;
        return -eval_factor(chi);
    }
    else
    {
        assert(0);
        return 0;
    }
}

long eval_integer(iter_t const& i)
{
    // extract integer (not always delimited by '\0')
    string integer(i->value.begin(), i->value.end());

    return strtol(integer.c_str(), 0, 10);
}

////////////////////////////////////////////////////////////////////////////
int
main()
{

    //  Start grammar definition
    integer     =   lexeme_d[ token_node_d[ (!ch_p('-') >> +digit_p) ] ];
    factor      =   integer
                |   '(' >> expression >> ')'
                |   ('-' >> factor);
    term        =   factor >>
                    *(  ('*' >> factor)
                      | ('/' >> factor)
                    );
    expression  =   term >>
                    *(  ('+' >> term)
                      | ('-' >> term)
                    );
    //  End grammar definition


    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "\t\tThe simplest working calculator...\n\n";
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "Type an expression...or [q or Q] to quit\n\n";

    string str;
    while (getline(cin, str))
    {
        if (str[0] == 'q' || str[0] == 'Q')
            break;

        const char* first = str.c_str();

        tree_parse_info<> info = pt_parse(first, expression);

        if (info.full)
        {
#if defined(BOOST_SPIRIT_DUMP_PARSETREE_AS_XML)
            // dump parse tree as XML
            std::map<parser_id, std::string> rule_names;
            rule_names[&integer] = "integer";
            rule_names[&factor] = "factor";
            rule_names[&term] = "term";
            rule_names[&expression] = "expression";
            tree_to_xml(cout, info.trees, first, rule_names);
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


