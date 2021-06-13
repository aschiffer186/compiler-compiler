#ifndef INPUT_DEFS_HH
#define INPUT_DEFS_HH 1

#include "lexer_core.hh"

#include <string>

LEXER_NAMESPACE
{
    struct definition_t 
    {
        std::string _M_name;
        std::string _M_regex;
    };

    struct rule_t
    {
        std::string _M_regex;
        std::string _M_cpp_code = "";
    };
}

//Specializaitions of standard library functors
namespace std
{
    template<>
    struct less<LEXER_SCOPE::definition_t>
    {
        constexpr bool operator()(const LEXER_SCOPE::definition_t& lhs, const LEXER_SCOPE::definition_t& rhs) {
            return std::less<std::string>{}(lhs._M_name, rhs._M_name);
        }
    };

    template<>
    struct hash<LEXER_SCOPE::definition_t>
    {
        size_t operator()(const LEXER_SCOPE::definition_t& def) const 
        {
            return std::hash<std::string>{}(def._M_name);
        }
    };
}

#endif