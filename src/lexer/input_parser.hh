#ifndef INPUT_PARSER_HH
#define INPUT_PARSER_HH

#include "lexer_core.hh"

#include "input_defs.hh"

#include <map>
#include <vector>
#include <istream>

LEXER_NAMESPACE 
{
    ///\brief Parsers TurLex input files
    ///
    ///This class parses TurLex input files; it prints error messages for input files. 
    ///Otherwise it does the following:
    /// 1) It creates a list of all user options 
    /// 2) It captues all C++ code from the prologue and epilogue
    /// 3) It creates a list of rules and their corresponding regex and user actions
    class input_parser
    {
        ///\brief Constructor from \b std::istream
        ///
        ///Creates an input parser that reads from the specified \b std::istream. 
        ///\param in the \b std::istream connected to the input file
        explicit input_parser(std::istream& in) noexcept;

        input_parser(const input_parser&) = delete;
        input_parser& operator=(const input_parser&) = delete;

        //Goal: generate list of rules (regular expressions + actions when seen)
        void parse_file() noexcept(false);

        ///\brief Returns a \b std::vector of the lexer's rules
        ///
        ///Returns a \b std::vector of the regular expressions the lexer will use and 
        ///the actions to execute when the lexer encounters that regular expression.
        ///
        ///\return a \b std::vector lexer's rules 
        ///\see rule_t
        std::vector<rule_t> get_lexer_rules() const;

        private:
            void handle_warning();
            void handle_error();
        private:
            std::istream& _M_input_stream;
            //Location information 
            size_t _M_curr_line;

            //Error handling 
            ///Warnings indicating a poorly formatted, but valid, input file
            std::vector<std::string> _M_warnings;
            ///Errors indicating an invalid input file
            std::vector<std::string> _M_exceptions;

            //Variables for parsing
            std::string _M_epilogue_code;
            std::map<std::string, bool> _M_definitions;
    };
}

#endif