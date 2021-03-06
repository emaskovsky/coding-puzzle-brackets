/**
    @file

    The standard string processor (implementation).

    @author Emil Maskovsky
*/

// standard library
#include <vector>

// BracketPuzzle
#include "BracketPuzzle/StandardProcessor.hpp"
#include "BracketPuzzle/IValidator.hpp"
#include "BracketPuzzle/IInputReader.hpp"
#include "BracketPuzzle/IResultWriter.hpp"
#include "BracketPuzzle/StandardResult.hpp"


namespace BracketPuzzle
{


bool StandardProcessor::execute(
    const IValidator & validator,
    const IInputReader & reader,
    IResultWriter & writer) const
{
    bool ok = true;
    std::string line;
    std::vector< std::string > lines;
    while (reader.readLine(line))
    {
        lines.push_back(line);
    }
    for (std::vector< std::string >::const_iterator it = lines.begin();
         it != lines.end() && ok;
         ++it)
    {
        ok = writer.writeResult(
            StandardResult(validator.validate(*it)));
    }
    return ok;
}


} // namespace BracketPuzzle


/* EOF */
