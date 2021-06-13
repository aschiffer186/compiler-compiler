#include "input_parser.hh"

LEXER_NAMESPACE 
{
    input_parser::input_parser(std::istream& in) 
        : _M_input_stream(in), _M_curr_line{0}, _M_warnings(), _M_exceptions(), _M_definitions()
    {
        
    }
}