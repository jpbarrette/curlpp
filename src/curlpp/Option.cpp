#include "curlpp/Option.hpp"
#include "curlpp/OptionSetter.hpp"

template<typename OptionType, CURLoption option>
const CURLoption curlpp::OptionTrait<OptionType, option>::option;

#if defined(CURLPP_TEMPLATE_EXPLICIT_INSTANTIATION)
	#include "Option.ins"
#endif