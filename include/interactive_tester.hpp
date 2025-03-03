#ifndef INTERACTIVE_TESTER_HPP
#define INTERACTIVE_TESTER_HPP

#include <boost/process.hpp>
#include <string>

namespace bp = boost::process;

class Interactive_Tester
{
  private:
  bp::ipstream output_stream; // to child
  bp::opstream input_stream; // from child
  public:
  Interactive_Tester();
};

#endif // INTERACTIVE_TESTER_HPP
