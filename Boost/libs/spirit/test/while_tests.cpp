/*=============================================================================
    Phoenix V1.0
    Copyright (c) 2002-2003 Martin Wille

    Permission to copy, use, modify, sell and distribute this software is
    granted provided this copyright notice appears in all copies. This
    software is provided "as is" without express or implied warranty, and
    with no claim as to its suitability for any purpose.
==============================================================================*/
// vi:ts=4:sw=4:et
// Tests for boost::spirit::while_p
// [28-Dec-2002]
////////////////////////////////////////////////////////////////////////////////
#define qDebug 0
#include <iostream>
#include <cstring>
#if qDebug
#define BOOST_SPIRIT_DEBUG
#endif
#include <boost/spirit/core.hpp>
#include <boost/spirit/dynamic/while.hpp>
#include <boost/ref.hpp>
////////////////////////////////////////////////////////////////////////////////

namespace local
{
    template <typename T>
    struct var_wrapper
        : public ::boost::reference_wrapper<T>
    {
        typedef boost::reference_wrapper<T> parent;

        explicit inline var_wrapper(T& t) : parent(t) {}

        inline T& operator()() const { return parent::get(); }
    };

    template <typename T>
    inline var_wrapper<T>
    var(T& t)
    {
        return var_wrapper<T>(t);
    }
}

namespace
{
    template <typename T>
    class add_actor
    {
    public:
        explicit add_actor(T &ref_) : ref(ref_) {}

        template <typename T2>
        void operator()(T2 const &val) const
        { ref += val; }

    private:
        T& ref;
    };

    template <typename T>
    inline add_actor<T> const
    add(T& ref)
    {
        return add_actor<T>(ref);
    }
}

typedef boost::spirit::rule<> rule_t;

unsigned int test_count = 0;
unsigned int error_count = 0;
unsigned int iterations_performed;

unsigned int number_result;
static const unsigned int kError = 999;
static const bool good = true;
static const bool bad = false;

rule_t while_rule;
rule_t do_while_rule;

void
test_while(
    char const *s,
    unsigned int wanted,
    rule_t const &r,
    unsigned int iterations_wanted)
{
    using namespace std;
    ++test_count;

    number_result = 0;
    iterations_performed = 0;

    boost::spirit::parse_info<> m = boost::spirit::parse(s, s+strlen(s), r);

    bool result = wanted == kError?(m.full?bad:good): (number_result==wanted);

    result &= iterations_performed == iterations_wanted;

    if (m.full && (m.length != strlen(s)))
        result = bad;

    if (result==good)
        cout << "PASSED";
    else
    {
        ++error_count;
        cout << "FAILED";
    }

    cout << ": \"" << s << "\" ==> ";
    if (!m.full)
        cout << "<error>";
    else
        cout << number_result;
    cout << "     " << iterations_performed << " of "
         << iterations_wanted << " iterations\n";
}

template<typename T>
struct inc_actor
{
    explicit inc_actor(T &t) : var(t) {}
    template<typename IteratorT>
    void operator()(IteratorT const &, IteratorT const &) const
    {
        ++var;
    }
    template<typename U>
    void operator()(U) const
    {
        ++var;
    }
    T &var;
};

template<typename T>
inc_actor<T>
inc(T &t)
{
    return inc_actor<T>(t);
}

int
main()
{
    using namespace std;
    using ::boost::spirit::uint_p;
    using ::boost::spirit::while_p;
    using ::boost::spirit::do_p;
    using ::boost::spirit::assign;

#if qDebug
    BOOST_SPIRIT_DEBUG_RULE(while_rule);
    BOOST_SPIRIT_DEBUG_RULE(do_while_rule);
#endif

    while_rule
        =   uint_p[assign(number_result)]
        >>  while_p('+')
            [
                uint_p[add(number_result)][inc(iterations_performed)]
            ];

    do_while_rule
        =   do_p
            [
                uint_p[add(number_result)][inc(iterations_performed)]
            ].while_p('+');

    cout << "/////////////////////////////////////////////////////////\n";
    cout << "\n";
    cout << "          while_p test\n";
    cout << "\n";
    cout << "/////////////////////////////////////////////////////////\n";
    cout << "\n";

    cout << "while_p()[]\n";
    test_while("",       kError, while_rule, 0);
    test_while("1",           1, while_rule, 0);
    test_while("1+1",         2, while_rule, 1);
    test_while("1+1+12",     14, while_rule, 2);
    test_while("1+1+x",  kError, while_rule, 1);

    cout << "do_p[].while_p()\n";
    test_while("",       kError, do_while_rule, 0);
    test_while("1",           1, do_while_rule, 1);
    test_while("1+1",         2, do_while_rule, 2);
    test_while("1+1+12",     14, do_while_rule, 3);
    test_while("1+1+x",  kError, do_while_rule, 2);

    std::cout << "\n    ";
    if (error_count==0)
        cout << "All " << test_count << " while_p-tests passed.\n"
             << "Test concluded successfully\n";
    else
        cout << error_count << " of " << test_count << " while_p-tests failed\n"
             << "Test failed\n";

    //////////////////////////////////
    // check wether as_parser<> works:
    while_p('"')['"'];
    do_p['"'].while_p('"');

    return error_count!=0;
}
////////////////////////////////////////////////////////////////////////////////
// End of File
