/**************************************************************************
** Program name: Project 3  - inputVerification.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for input verification. It will use
**               a template class to use for the input validation.
****************************************************************************/
#ifndef INPUTVERIFICATION_HPP
#define INPUTVERIFICATION_HPP

#include <functional>
template <class InputType>

 void SafeInput(InputType & InputVar, std::function <bool(InputType &)> Predicate, std::string s);

#endif